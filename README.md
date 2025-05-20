Интерпретатор с языка ST(Structured Text) на язык C(Си)
входной файл: input.st
выходной файл: output.st

Запуск (bash):

  1)clean make
  2)make
  3)./parser < input.st > output.c

или 

  1)flex lexer.l
  2)bison -d parser.y
  3)gcc parser.tab.c lex.yy.c -o pars
  4)./pars < input.st > output.c\n
