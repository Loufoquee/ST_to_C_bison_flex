%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);
extern int yyparse(void);
extern FILE *yyin;

char* final_code = NULL;
int used_concat = 0;
int used_mid = 0;
int tabs = 1;

int is_string(const char* s) {
    if (!s) return 0;
    size_t len = strlen(s);
    return len >= 2 && s[0] == '"' && s[len - 1] == '"';
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}

char* concat(const char* a, const char* b) {
    size_t len = strlen(a) + strlen(b) + 1;
    char* res = malloc(len);
    if (!res) { fprintf(stderr, "Out of memory\n"); exit(1); }
    strcpy(res, a);
    strcat(res, b);
    return res;
}

char* make_binop(const char* left, const char* op, const char* right) {
    size_t len = strlen(left) + strlen(op) + strlen(right) + 4;
    char* res = malloc(len);
    if (!res) { fprintf(stderr, "Out of memory\n"); exit(1); }
    snprintf(res, len, "%s %s %s", left, op, right);
    return res;
}
char* make_tabs(int n) {
    char* tabs = malloc(n + 1); // +1 для '\0'
    for (int i = 0; i < n; i++) {
        tabs[i] = '\t';
    }
    tabs[n] = '\0';
    return tabs;
}

char* make_strcmp_eq(const char* a, const char* b) {
    size_t len = strlen(a) + strlen(b) + 30;
    char* res = malloc(len);
    sprintf(res, "strcmp(%s, %s) == 0", a, b);
    return res;
}


char* escape_string(const char* s) {
    size_t len = strlen(s);
    const char* start = s;
    size_t real_len = len;
    if (len >= 2 && ((s[0] == '"' && s[len-1] == '"') || (s[0] == '\'' && s[len-1] == '\''))) {
        start = s + 1;
        real_len = len - 2;
    }
    
    size_t max_len = real_len * 2 + 3;
    char* escaped = malloc(max_len);
    if (!escaped) { fprintf(stderr, "Out of memory\n"); exit(1); }
    char* dst = escaped;
    *dst++ = '"';
    for (size_t i = 0; i < real_len; i++) {
        if ((start[i] == '"')) {
            if (i > 0 && start[i-1] != '\\'){
                *dst++ = '\\';
            }else if (i == 0 && start[i] != '\\'){
                *dst++ = '\\';
            }
            *dst++ = start[i];
        } else {
            *dst++ = start[i];
        }
    }
    *dst++ = '"';
    *dst = '\0';
    return escaped;
}
%}

%union {
    int ival;
    char* str;
}

%debug

%token VAR END_VAR WHILE DO END_WHILE IF THEN ELSIF ELSE END_IF NOT
%token AND OR ASSIGN
%token SEMICOLON COLON LPAREN RPAREN COMMA
%token LE GE EQ NE LT GT SR
%token STRING_TYPE CHAR_TYPE INT_TYPE
%token PLUS MINUS TIMES DIVIDE



%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left TIMES DIVIDE
%left SR
%right NOT
%right UMINUS

%token <ival> INT_LITERAL
%token <str> STRING_LITERAL ID FUNC_ID
%token <str> CHAR_LITERAL

%type <str> block program var_block decl_list decl expr_list expr function_call statement statement_list if_tail

%%

program:
    var_block statement_list {
        char *extra_funcs = strdup("");
        if (used_concat) {
            extra_funcs = concat(extra_funcs,
                "char* concat(const char* a, const char* b) {\n"
                "    size_t len = strlen(a) + strlen(b) + 1;\n"
                "    char* res = malloc(len);\n"
                "    strcpy(res, a);\n"
                "    strcat(res, b);\n"
                "    return res;\n"
                "}\n\n");
        }
        if (used_mid) {
            extra_funcs = concat(extra_funcs,
                "char* mid(const char* s, int start, int length) {\n"
                "    char* res = malloc(length + 1);\n"
                "    strncpy(res, s + start - 1, length);\n"
                "    res[length] = '\\0';\n"
                "    return res;\n"
                "}\n\n");
        }
        size_t len = strlen($1 ? $1 : "") + strlen($2 ? $2 : "") + 500;
        len += strlen(extra_funcs);

        final_code = malloc(len);
        snprintf(final_code, len,
            "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n%sint main() {\n%s%s\treturn 0;\n}\n",
            extra_funcs,
            $1 ? $1 : "", $2 ? $2 : "");

        $$ = final_code;
    }
;

var_block:
    VAR decl_list END_VAR {
        $$ = $2;
    }
;

decl_list:
      /* empty */ { $$ = strdup(""); }
    | decl_list decl {
        size_t len = strlen($1) + strlen($2) + 4;
        char* res = malloc(len);
        snprintf(res, len, "%s\t%s\n", $1, $2);
        $$ = res;
    }
;

decl:
      ID COLON STRING_TYPE ASSIGN expr_list SEMICOLON {
        size_t len = strlen($1) + strlen($5) + 20;
        char* res = malloc(len);
        snprintf(res, len, "char* %s = %s;", $1, escape_string($5));
        $$ = res;
    }
    | ID COLON CHAR_TYPE ASSIGN expr_list SEMICOLON {
        size_t len = strlen($1) + strlen($5) + 20;
        char* res = malloc(len);
        snprintf(res, len, "char %s = %s;", $1, $5);
        $$ = res;
    }
    | ID COLON INT_TYPE ASSIGN expr_list SEMICOLON {
        size_t len = strlen($1) + strlen($5) + 20;
        char* res = malloc(len);
        snprintf(res, len, "int %s = %s;", $1, $5);
        $$ = res;
    }
    | ID COLON STRING_TYPE SEMICOLON {
        size_t len = strlen($1) + 20;
        char* res = malloc(len);
        snprintf(res, len, "char* %s;", $1);
        $$ = res;
    }
    | ID COLON CHAR_TYPE SEMICOLON {
        size_t len = strlen($1) + 20;
        char* res = malloc(len);
        snprintf(res, len, "char %s;", $1);
        $$ = res;
    }
    | ID COLON INT_TYPE SEMICOLON {
        size_t len = strlen($1) + 20;
        char* res = malloc(len);
        snprintf(res, len, "int %s;", $1);
        $$ = res;
    }
;

expr_list
    : expr {
        $$ = strdup($1);  // копия строки, чтобы не зависеть от $1
    }
    | expr_list COMMA expr {
        size_t len = strlen($1) + strlen($3) + 2;
        char* res = malloc(len);
        snprintf(res, len, "%s,%s", $1, $3);
        $$ = res;
    }


expr:
      INT_LITERAL {
          char buf[32];
          snprintf(buf, sizeof(buf), "%d", $1);
          $$ = strdup(buf);
      }
    | STRING_LITERAL {
        if (strlen($1) >= 1){
            $$ = strdup(escape_string($1));
        }else{
            $$ = strdup($1);
        }
    }
    | NOT expr %prec NOT {
        size_t len = strlen($2) + 4;
        char* res = malloc(len);
        snprintf(res, len, "!(%s)", $2);
        $$ = res;
    }
    | LPAREN expr RPAREN { $$ = $2; }
    | ID {
        $$ = strdup($1);
    }
    | function_call {
        $$ = strdup($1);
    }
    | CHAR_LITERAL {
        if (strlen($1) >= 1){
            $$ = strdup(escape_string($1));
        }else{
            $$ = strdup($1);
        }
    }
    | expr AND expr {
        char* res = make_binop($1, "&&", $3);
        $$ = res;
    }
    | expr OR expr {
        char* res = make_binop($1, "||", $3);
        $$ = res;
    }
    | expr PLUS expr {
        if (is_string($1) || is_string($3)) {
            size_t len = strlen($1) + strlen($3) + 1;
            char* res = malloc(len + 8);
            char* a = "strcat(";
            strcpy(res, a);
            strcat(res, $1);
            strcat(res, $3);
            strcat(res, ")");
            $$ = res;
        } else {
            char* res = make_binop($1, "+", $3);
            $$ = res;
        }
    }
    | expr MINUS expr {
        char* res = make_binop($1, "-", $3);
        $$ = res;
    }
    | expr TIMES expr {
        char* res = make_binop($1, "*", $3);
        $$ = res;
    }
    | expr DIVIDE expr {
        char* res = make_binop($1, "/", $3);
        $$ = res;
    }
    | expr LE expr {
        char* res;
        if (is_string($1) || is_string($3)) {
            asprintf(&res, "%s[0] <= %s[0]", $1, $3);
            $$ = res;
        }else{
            res = make_binop($1, "<=", $3);
        }
        $$ = res;
    }
    | expr GE expr {
        char* res;
        if (is_string($1) || is_string($3)) {
            asprintf(&res, "%s[0] >= %s[0]", $1, $3);
            $$ = res;
        }else{
            res = make_binop($1, ">=", $3);
        }
        $$ = res;
    }
    | expr LT expr {
        char* res = make_binop($1, "<", $3);
        $$ = res;
    }
    | expr GT expr {
        char* res = make_binop($1, ">", $3);
        $$ = res;
    }
    | expr EQ expr {
        char* res;
        asprintf(&res, "strcmp(%s, %s) == 0", $1, $3);
        $$ = res;
    }
    | expr NE expr {
        char* res = make_binop($1, "!=", $3);
        $$ = res;
    }
    | MINUS expr %prec UMINUS {
        size_t len = strlen($2) + 4;
        char* res = malloc(len);
        snprintf(res, len, "-(%s)", $2);
        $$ = res;
    }
    | expr SR expr {
        char* res;
        asprintf(&res, "strcmp(%s, %s) == 0", $1, $3);
        $$ = res;
    }

;

function_call
    : FUNC_ID LPAREN RPAREN {
        size_t len = strlen($1) + 3;
        char* res = malloc(len);
        snprintf(res, len, "%s()", $1);
        $$ = res;
    }
    | FUNC_ID LPAREN expr_list RPAREN {
        char* res;
        if (strcmp($1, "CONCAT") == 0) {
            used_concat = 1;
            size_t len = strlen("concat(") + strlen($3) + 2;
            res = malloc(len);
            snprintf(res, len, "concat(%s)", $3);
        } else if (strcmp($1, "MID") == 0) {
            used_mid = 1;
            size_t len = strlen("mid(") + strlen($3) + 2;
            res = malloc(len);
            snprintf(res, len, "mid(%s)", $3);
        } else if (strcmp($1, "LEN") == 0) {
            size_t len = strlen("strlen(") + strlen($3) + 2;
            res = malloc(len);
            snprintf(res, len, "strlen(%s)", $3);
        } else if (strcmp($1, "TRACE") == 0) {
            size_t len = strlen("printf(\"%%s\\n\", ") + strlen($3) + 10;
            res = malloc(len);
            snprintf(res, len, "printf(\"%%s\\n\", %s);", $3, $3);
        } else {
            size_t len = strlen($1) + strlen($3) + 4;
            res = malloc(len);
            snprintf(res, len, "%s(%s)", $1, $3);
        }
        $$ = res;
    }

statement:
      ID ASSIGN expr SEMICOLON {
        size_t len = strlen($1) + strlen($3) + 15;
        char* res = malloc(len);
        snprintf(res, len, "%s = %s;", $1, $3);
        $$ = res;
    }
    | WHILE expr DO block END_WHILE SEMICOLON {
        size_t len = strlen($2) + strlen($4) + 300;
        char* res = malloc(len);
        snprintf(res, len, "while (%s) {\n%s\t}", $2, $4);
        $$ = res;
    }
    | function_call SEMICOLON {
        $$ = strdup($1);
    }
    | IF expr THEN block if_tail END_IF SEMICOLON{
        size_t len = strlen($2) + strlen($4) + strlen($5) + 40;
        char* res = malloc(len);
        snprintf(res, len, "if (%s) {\n%s\t}%s", $2, $4, $5);
        $$ = res;
    }

;

if_tail:
      /* empty */ { $$ = strdup(""); }
    | ELSIF expr THEN block if_tail {
        size_t len = strlen($2) + strlen($4) + strlen($5) + 25;
        char* res = malloc(len);
        snprintf(res, len, " else if (%s) {\n%s\t}%s", $2, $4, $5);
        $$ = res;
    }
    | ELSE block{
        size_t len = strlen($2) + 20;
        char* res = malloc(len);
        snprintf(res, len, " else {\n%s\t}", $2);
        $$ = res;
    }
;

statement_list:
      /* empty */ { $$ = strdup(""); }
    | statement_list statement {
        size_t len = strlen($1) + strlen($2) + 10;
        char* res = malloc(len);
        snprintf(res, len, "%s\t%s\n", $1, $2);
        $$ = res;
    }
;
block:
    statement_list {
        const char* input = $1;
        size_t total_len = strlen(input) + 1024;  // запас
        char* res = malloc(total_len);
        res[0] = '\0';

        char* temp = strdup(input);  // strtok мутирует строку, нужно копировать
        char* line = strtok(temp, "\n");

        char* tab_str = make_tabs(tabs);

        while (line) {
            strcat(res, tab_str);
            strcat(res, line);
            strcat(res, "\n");
            line = strtok(NULL, "\n");
        }

        free(temp);
        free(tab_str);
        $$ = res;
    }
;

%%