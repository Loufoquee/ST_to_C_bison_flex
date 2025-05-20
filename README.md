Транслятор с языка ST(Structured Text) на язык C(Си)
входной файл: input.st
выходной файл: output.st

Запуск (bash):

clean make
make
./parser < input.st > output.c

или 

flex lexer.l
bison -d parser.y
gcc parser.tab.c lex.yy.c -o pars
./pars < input.st > output.c