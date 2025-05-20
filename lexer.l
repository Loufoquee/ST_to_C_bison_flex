%{
#include "parser.tab.h"
#include <string.h>
#include <stdlib.h>

void yyerror(const char *s);
%}

%%

"VAR"          return VAR;
"END_VAR"      return END_VAR;
"WHILE"        return WHILE;
"DO"           return DO;
"END_WHILE"    return END_WHILE;
"IF"           return IF;
"THEN"         return THEN;
"ELSIF"        return ELSIF;
"ELSE"         return ELSE;
"END_IF"       return END_IF;
"NOT"          return NOT;

"CHAR" {
    int c = input();
    if (c == '(') {
        unput(c);
        yylval.str = strdup("CHAR");
        return FUNC_ID;
    } else {
        unput(c);
        return CHAR_TYPE;
    }
}

"STRING" {
    int c = input();
    if (c == '(') {
        unput(c);
        yylval.str = strdup("STRING");
        return FUNC_ID;
    } else {
        unput(c);
        return STRING_TYPE;
    }
}

"INT" {
    int c = input();
    if (c == '(') {
        unput(c);
        yylval.str = strdup("INT");
        return FUNC_ID;
    } else {
        unput(c);
        return INT_TYPE;
    }
}

"=="           return SR;
"<="           return LE;
">="           return GE;
"="            return EQ;
"<>"           return NE;
"<"            return LT;
">"            return GT;

"+"     return PLUS;
"-"     return MINUS;
"*"     return TIMES;
"/"     return DIVIDE;

"AND"          return AND;
"OR"           return OR;

":="           return ASSIGN;
";"            return SEMICOLON;
":"            return COLON;
","            return COMMA;
"("            return LPAREN;
")"            return RPAREN;

'([^']+)'     { yylval.str = strdup(yytext); return CHAR_LITERAL; }

\'([^\\\']|\\.)*\' {
    yylval.str = strdup(yytext);
    return STRING_LITERAL;
}

[0-9]+ {
    yylval.ival = atoi(yytext);
    return INT_LITERAL;
}

[A-Za-z_][A-Za-z0-9_]* {
    char next_char;
    yylval.str = strdup(yytext);
    if (strcmp(yytext, "TRACE") == 0) {
        return FUNC_ID;
    }
    // Сохраняем позицию в лексере
    int c;
    do {
        c = input();
    } while (c == ' ' || c == '\t' || c == '\n' || c == '\r');

    if (c != EOF) {
        next_char = c;
        unput(c);
    } else {
        next_char = 0;
    }

    if (next_char == '(')
        return FUNC_ID;
    else
        return ID;
}

[ \t\r\n]+    ; // пропускаем пробелы и переносы

.             ; // игнорируем остальные символы

%%

int yywrap(void) { return 1; }
