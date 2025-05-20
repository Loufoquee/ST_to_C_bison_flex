Интерпретатор с языка ST(Structured Text) на язык C(Си)
входной файл: input.st
выходной файл: output.st

Запуск (bash):

clean make\n
make\n
./parser < input.st > output.c\n

или 

flex lexer.l\n
bison -d parser.y\n
gcc parser.tab.c lex.yy.c -o pars\n
./pars < input.st > output.c\n
