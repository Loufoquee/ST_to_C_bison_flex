all: parser

parser: lexer.o parser.tab.o main.o
	$(CC) -o parser lexer.o parser.tab.o main.o

lexer.o: lexer.l parser.tab.h
	flex -o lexer.c lexer.l
	$(CC) -c lexer.c

parser.tab.o parser.tab.h: parser.y
	bison -d parser.y
	$(CC) -c parser.tab.c

main.o: main.c
	$(CC) -c main.c

clean:
	rm -f *.o parser lexer.c parser.tab.c parser.tab.h
