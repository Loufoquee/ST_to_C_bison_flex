#include <stdio.h>
#include <stdlib.h>

extern int yyparse(void);
extern int yydebug;
extern FILE *yyin;
extern char* final_code;

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            perror("File open error");
            return 1;
        }
        yyin = f;
    }
    yydebug = 1;
    if (yyparse() == 0) {
        printf("%s\n", final_code);
    } else {
        fprintf(stderr, "Parsing failed.\n");
    }
    free(final_code);
    return 0;
}
