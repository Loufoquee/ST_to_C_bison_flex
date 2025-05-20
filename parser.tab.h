/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VAR = 258,                     /* VAR  */
    END_VAR = 259,                 /* END_VAR  */
    WHILE = 260,                   /* WHILE  */
    DO = 261,                      /* DO  */
    END_WHILE = 262,               /* END_WHILE  */
    IF = 263,                      /* IF  */
    THEN = 264,                    /* THEN  */
    ELSIF = 265,                   /* ELSIF  */
    ELSE = 266,                    /* ELSE  */
    END_IF = 267,                  /* END_IF  */
    NOT = 268,                     /* NOT  */
    AND = 269,                     /* AND  */
    OR = 270,                      /* OR  */
    ASSIGN = 271,                  /* ASSIGN  */
    SEMICOLON = 272,               /* SEMICOLON  */
    COLON = 273,                   /* COLON  */
    LPAREN = 274,                  /* LPAREN  */
    RPAREN = 275,                  /* RPAREN  */
    COMMA = 276,                   /* COMMA  */
    LE = 277,                      /* LE  */
    GE = 278,                      /* GE  */
    EQ = 279,                      /* EQ  */
    NE = 280,                      /* NE  */
    LT = 281,                      /* LT  */
    GT = 282,                      /* GT  */
    SR = 283,                      /* SR  */
    STRING_TYPE = 284,             /* STRING_TYPE  */
    CHAR_TYPE = 285,               /* CHAR_TYPE  */
    INT_TYPE = 286,                /* INT_TYPE  */
    PLUS = 287,                    /* PLUS  */
    MINUS = 288,                   /* MINUS  */
    TIMES = 289,                   /* TIMES  */
    DIVIDE = 290,                  /* DIVIDE  */
    UMINUS = 291,                  /* UMINUS  */
    INT_LITERAL = 292,             /* INT_LITERAL  */
    STRING_LITERAL = 293,          /* STRING_LITERAL  */
    ID = 294,                      /* ID  */
    FUNC_ID = 295,                 /* FUNC_ID  */
    CHAR_LITERAL = 296             /* CHAR_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 91 "parser.y"

    int ival;
    char* str;

#line 110 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
