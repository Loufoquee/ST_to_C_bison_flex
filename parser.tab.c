/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 161 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_END_VAR = 4,                    /* END_VAR  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_DO = 6,                         /* DO  */
  YYSYMBOL_END_WHILE = 7,                  /* END_WHILE  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_THEN = 9,                       /* THEN  */
  YYSYMBOL_ELSIF = 10,                     /* ELSIF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_END_IF = 12,                    /* END_IF  */
  YYSYMBOL_NOT = 13,                       /* NOT  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NE = 25,                        /* NE  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_SR = 28,                        /* SR  */
  YYSYMBOL_STRING_TYPE = 29,               /* STRING_TYPE  */
  YYSYMBOL_CHAR_TYPE = 30,                 /* CHAR_TYPE  */
  YYSYMBOL_INT_TYPE = 31,                  /* INT_TYPE  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_TIMES = 34,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 35,                    /* DIVIDE  */
  YYSYMBOL_UMINUS = 36,                    /* UMINUS  */
  YYSYMBOL_INT_LITERAL = 37,               /* INT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 38,            /* STRING_LITERAL  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_FUNC_ID = 40,                   /* FUNC_ID  */
  YYSYMBOL_CHAR_LITERAL = 41,              /* CHAR_LITERAL  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_var_block = 44,                 /* var_block  */
  YYSYMBOL_decl_list = 45,                 /* decl_list  */
  YYSYMBOL_decl = 46,                      /* decl  */
  YYSYMBOL_expr_list = 47,                 /* expr_list  */
  YYSYMBOL_expr = 48,                      /* expr  */
  YYSYMBOL_function_call = 49,             /* function_call  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_if_tail = 51,                   /* if_tail  */
  YYSYMBOL_statement_list = 52,            /* statement_list  */
  YYSYMBOL_block = 53                      /* block  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   161,   167,   168,   177,   183,   189,   195,
     201,   207,   216,   219,   228,   233,   240,   246,   247,   250,
     253,   260,   264,   268,   283,   287,   291,   295,   305,   315,
     319,   323,   328,   332,   338,   347,   353,   382,   388,   394,
     397,   407,   408,   414,   423,   424,   432
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "END_VAR",
  "WHILE", "DO", "END_WHILE", "IF", "THEN", "ELSIF", "ELSE", "END_IF",
  "NOT", "AND", "OR", "ASSIGN", "SEMICOLON", "COLON", "LPAREN", "RPAREN",
  "COMMA", "LE", "GE", "EQ", "NE", "LT", "GT", "SR", "STRING_TYPE",
  "CHAR_TYPE", "INT_TYPE", "PLUS", "MINUS", "TIMES", "DIVIDE", "UMINUS",
  "INT_LITERAL", "STRING_LITERAL", "ID", "FUNC_ID", "CHAR_LITERAL",
  "$accept", "program", "var_block", "decl_list", "decl", "expr_list",
  "expr", "function_call", "statement", "if_tail", "statement_list",
  "block", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -47,    23,   -47,     2,   -47,     5,   -47,     7,   -47,
      80,    80,    33,    64,    35,   -47,    65,    80,    80,    80,
     -47,   -47,   -47,   -47,    54,   -47,    39,    80,    71,   -47,
      -1,    40,    81,   -47,   129,   -47,   -47,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
     -47,   151,   -47,    82,   166,    80,   -47,    80,   -47,    80,
     -47,   -47,     5,    52,   195,   181,   -14,   -14,   209,   209,
     -14,   -14,   -47,   -23,   -23,    57,    57,    90,   -47,   -47,
      80,    25,    26,    34,    75,    80,   -47,    93,   166,   -47,
     -47,   -47,   -47,   113,   -47,    89,   -47,   -47,    90,   -47
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,    44,     0,     1,     2,     3,     0,     5,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
      14,    15,    18,    20,     0,    19,     0,     0,     0,    39,
       0,     0,     0,    16,     0,    33,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,    35,     0,    12,     0,     9,     0,    10,     0,
      11,    17,    46,     0,    21,    22,    27,    28,    31,    32,
      29,    30,    34,    23,    24,    25,    26,    41,    37,    36,
       0,     0,     0,     0,     0,     0,    44,     0,    13,     6,
       7,     8,    38,     0,    43,     0,    44,    40,    41,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,   -47,   -47,   -33,   -10,    -4,   -47,     9,
     111,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     9,    53,    54,    25,    15,    87,
      62,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    26,    14,     1,    77,    45,     7,    33,    34,    35,
      10,    48,    49,    11,    45,    55,    56,    51,    46,    47,
      48,    49,    81,     5,    82,    16,    83,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      94,     8,    89,    90,    12,    13,    80,    80,    50,    27,
      98,    91,    29,    37,    38,    80,    57,    58,    14,    84,
      36,    39,    40,    41,    42,    43,    44,    45,    37,    38,
      88,    46,    47,    48,    49,    93,    39,    40,    41,    42,
      43,    44,    45,    28,    17,    45,    46,    47,    48,    49,
      18,    52,    92,    17,    30,    31,    32,    59,    60,    18,
      85,    86,    79,    80,    19,    95,    97,    99,    20,    21,
      22,    13,    23,    19,     6,     0,     0,    20,    21,    22,
      13,    23,    96,     0,     0,     0,     0,    37,    38,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,    45,     0,    37,    38,    46,    47,    48,    49,    61,
       0,    39,    40,    41,    42,    43,    44,    45,     0,     0,
       0,    46,    47,    48,    49,    37,    38,     0,    78,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,    45,
      37,    38,     0,    46,    47,    48,    49,     0,    39,    40,
      41,    42,    43,    44,    45,    37,     0,     0,    46,    47,
      48,    49,     0,    39,    40,    41,    42,    43,    44,    45,
       0,     0,     0,    46,    47,    48,    49,    39,    40,    41,
      42,    43,    44,    45,     0,     0,     0,    46,    47,    48,
      49,    39,    40,     0,     0,    43,    44,    45,     0,     0,
       0,    46,    47,    48,    49
};

static const yytype_int8 yycheck[] =
{
      10,    11,     6,     3,    50,    28,     4,    17,    18,    19,
       5,    34,    35,     8,    28,    16,    17,    27,    32,    33,
      34,    35,    55,     0,    57,    18,    59,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      86,    39,    17,    17,    39,    40,    21,    21,     9,    16,
      96,    17,    17,    14,    15,    21,    16,    17,    62,     7,
       6,    22,    23,    24,    25,    26,    27,    28,    14,    15,
      80,    32,    33,    34,    35,    85,    22,    23,    24,    25,
      26,    27,    28,    19,    13,    28,    32,    33,    34,    35,
      19,    20,    17,    13,    29,    30,    31,    16,    17,    19,
      10,    11,    20,    21,    33,    12,    17,    98,    37,    38,
      39,    40,    41,    33,     3,    -1,    -1,    37,    38,    39,
      40,    41,     9,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    14,    15,    32,    33,    34,    35,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    33,    34,    35,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      14,    15,    -1,    32,    33,    34,    35,    -1,    22,    23,
      24,    25,    26,    27,    28,    14,    -1,    -1,    32,    33,
      34,    35,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    32,    33,    34,
      35,    22,    23,    -1,    -1,    26,    27,    28,    -1,    -1,
      -1,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,    44,    45,     0,    52,     4,    39,    46,
       5,     8,    39,    40,    49,    50,    18,    13,    19,    33,
      37,    38,    39,    41,    48,    49,    48,    16,    19,    17,
      29,    30,    31,    48,    48,    48,     6,    14,    15,    22,
      23,    24,    25,    26,    27,    28,    32,    33,    34,    35,
       9,    48,    20,    47,    48,    16,    17,    16,    17,    16,
      17,    20,    52,    53,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    53,    17,    20,
      21,    47,    47,    47,     7,    10,    11,    51,    48,    17,
      17,    17,    17,    48,    53,    12,     9,    17,    53,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    46,    46,
      46,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    50,    50,    50,
      50,    51,    51,    51,    52,    52,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     0,     2,     6,     6,     6,     4,
       4,     4,     1,     3,     1,     1,     2,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     4,     4,     6,     2,
       7,     0,     5,     2,     0,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: var_block statement_list  */
#line 126 "parser.y"
                             {
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
        size_t len = strlen((yyvsp[-1].str) ? (yyvsp[-1].str) : "") + strlen((yyvsp[0].str) ? (yyvsp[0].str) : "") + 500;
        len += strlen(extra_funcs);

        final_code = malloc(len);
        snprintf(final_code, len,
            "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n%sint main() {\n%s%s\treturn 0;\n}\n",
            extra_funcs,
            (yyvsp[-1].str) ? (yyvsp[-1].str) : "", (yyvsp[0].str) ? (yyvsp[0].str) : "");

        (yyval.str) = final_code;
    }
#line 1318 "parser.tab.c"
    break;

  case 3: /* var_block: VAR decl_list END_VAR  */
#line 161 "parser.y"
                          {
        (yyval.str) = (yyvsp[-1].str);
    }
#line 1326 "parser.tab.c"
    break;

  case 4: /* decl_list: %empty  */
#line 167 "parser.y"
                  { (yyval.str) = strdup(""); }
#line 1332 "parser.tab.c"
    break;

  case 5: /* decl_list: decl_list decl  */
#line 168 "parser.y"
                     {
        size_t len = strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 4;
        char* res = malloc(len);
        snprintf(res, len, "%s\t%s\n", (yyvsp[-1].str), (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1343 "parser.tab.c"
    break;

  case 6: /* decl: ID COLON STRING_TYPE ASSIGN expr_list SEMICOLON  */
#line 177 "parser.y"
                                                      {
        size_t len = strlen((yyvsp[-5].str)) + strlen((yyvsp[-1].str)) + 20;
        char* res = malloc(len);
        snprintf(res, len, "char* %s = %s;", (yyvsp[-5].str), escape_string((yyvsp[-1].str)));
        (yyval.str) = res;
    }
#line 1354 "parser.tab.c"
    break;

  case 7: /* decl: ID COLON CHAR_TYPE ASSIGN expr_list SEMICOLON  */
#line 183 "parser.y"
                                                    {
        size_t len = strlen((yyvsp[-5].str)) + strlen((yyvsp[-1].str)) + 20;
        char* res = malloc(len);
        snprintf(res, len, "char %s = %s;", (yyvsp[-5].str), (yyvsp[-1].str));
        (yyval.str) = res;
    }
#line 1365 "parser.tab.c"
    break;

  case 8: /* decl: ID COLON INT_TYPE ASSIGN expr_list SEMICOLON  */
#line 189 "parser.y"
                                                   {
        size_t len = strlen((yyvsp[-5].str)) + strlen((yyvsp[-1].str)) + 20;
        char* res = malloc(len);
        snprintf(res, len, "int %s = %s;", (yyvsp[-5].str), (yyvsp[-1].str));
        (yyval.str) = res;
    }
#line 1376 "parser.tab.c"
    break;

  case 9: /* decl: ID COLON STRING_TYPE SEMICOLON  */
#line 195 "parser.y"
                                     {
        size_t len = strlen((yyvsp[-3].str)) + 20;
        char* res = malloc(len);
        snprintf(res, len, "char* %s;", (yyvsp[-3].str));
        (yyval.str) = res;
    }
#line 1387 "parser.tab.c"
    break;

  case 10: /* decl: ID COLON CHAR_TYPE SEMICOLON  */
#line 201 "parser.y"
                                   {
        size_t len = strlen((yyvsp[-3].str)) + 20;
        char* res = malloc(len);
        snprintf(res, len, "char %s;", (yyvsp[-3].str));
        (yyval.str) = res;
    }
#line 1398 "parser.tab.c"
    break;

  case 11: /* decl: ID COLON INT_TYPE SEMICOLON  */
#line 207 "parser.y"
                                  {
        size_t len = strlen((yyvsp[-3].str)) + 20;
        char* res = malloc(len);
        snprintf(res, len, "int %s;", (yyvsp[-3].str));
        (yyval.str) = res;
    }
#line 1409 "parser.tab.c"
    break;

  case 12: /* expr_list: expr  */
#line 216 "parser.y"
           {
        (yyval.str) = strdup((yyvsp[0].str));  // копия строки, чтобы не зависеть от $1
    }
#line 1417 "parser.tab.c"
    break;

  case 13: /* expr_list: expr_list COMMA expr  */
#line 219 "parser.y"
                           {
        size_t len = strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2;
        char* res = malloc(len);
        snprintf(res, len, "%s,%s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1428 "parser.tab.c"
    break;

  case 14: /* expr: INT_LITERAL  */
#line 228 "parser.y"
                  {
          char buf[32];
          snprintf(buf, sizeof(buf), "%d", (yyvsp[0].ival));
          (yyval.str) = strdup(buf);
      }
#line 1438 "parser.tab.c"
    break;

  case 15: /* expr: STRING_LITERAL  */
#line 233 "parser.y"
                     {
        if (strlen((yyvsp[0].str)) >= 1){
            (yyval.str) = strdup(escape_string((yyvsp[0].str)));
        }else{
            (yyval.str) = strdup((yyvsp[0].str));
        }
    }
#line 1450 "parser.tab.c"
    break;

  case 16: /* expr: NOT expr  */
#line 240 "parser.y"
                         {
        size_t len = strlen((yyvsp[0].str)) + 4;
        char* res = malloc(len);
        snprintf(res, len, "!(%s)", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1461 "parser.tab.c"
    break;

  case 17: /* expr: LPAREN expr RPAREN  */
#line 246 "parser.y"
                         { (yyval.str) = (yyvsp[-1].str); }
#line 1467 "parser.tab.c"
    break;

  case 18: /* expr: ID  */
#line 247 "parser.y"
         {
        (yyval.str) = strdup((yyvsp[0].str));
    }
#line 1475 "parser.tab.c"
    break;

  case 19: /* expr: function_call  */
#line 250 "parser.y"
                    {
        (yyval.str) = strdup((yyvsp[0].str));
    }
#line 1483 "parser.tab.c"
    break;

  case 20: /* expr: CHAR_LITERAL  */
#line 253 "parser.y"
                   {
        if (strlen((yyvsp[0].str)) >= 1){
            (yyval.str) = strdup(escape_string((yyvsp[0].str)));
        }else{
            (yyval.str) = strdup((yyvsp[0].str));
        }
    }
#line 1495 "parser.tab.c"
    break;

  case 21: /* expr: expr AND expr  */
#line 260 "parser.y"
                    {
        char* res = make_binop((yyvsp[-2].str), "&&", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1504 "parser.tab.c"
    break;

  case 22: /* expr: expr OR expr  */
#line 264 "parser.y"
                   {
        char* res = make_binop((yyvsp[-2].str), "||", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1513 "parser.tab.c"
    break;

  case 23: /* expr: expr PLUS expr  */
#line 268 "parser.y"
                     {
        if (is_string((yyvsp[-2].str)) || is_string((yyvsp[0].str))) {
            size_t len = strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 1;
            char* res = malloc(len + 8);
            char* a = "strcat(";
            strcpy(res, a);
            strcat(res, (yyvsp[-2].str));
            strcat(res, (yyvsp[0].str));
            strcat(res, ")");
            (yyval.str) = res;
        } else {
            char* res = make_binop((yyvsp[-2].str), "+", (yyvsp[0].str));
            (yyval.str) = res;
        }
    }
#line 1533 "parser.tab.c"
    break;

  case 24: /* expr: expr MINUS expr  */
#line 283 "parser.y"
                      {
        char* res = make_binop((yyvsp[-2].str), "-", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1542 "parser.tab.c"
    break;

  case 25: /* expr: expr TIMES expr  */
#line 287 "parser.y"
                      {
        char* res = make_binop((yyvsp[-2].str), "*", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1551 "parser.tab.c"
    break;

  case 26: /* expr: expr DIVIDE expr  */
#line 291 "parser.y"
                       {
        char* res = make_binop((yyvsp[-2].str), "/", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1560 "parser.tab.c"
    break;

  case 27: /* expr: expr LE expr  */
#line 295 "parser.y"
                   {
        char* res;
        if (is_string((yyvsp[-2].str)) || is_string((yyvsp[0].str))) {
            asprintf(&res, "%s[0] <= %s[0]", (yyvsp[-2].str), (yyvsp[0].str));
            (yyval.str) = res;
        }else{
            res = make_binop((yyvsp[-2].str), "<=", (yyvsp[0].str));
        }
        (yyval.str) = res;
    }
#line 1575 "parser.tab.c"
    break;

  case 28: /* expr: expr GE expr  */
#line 305 "parser.y"
                   {
        char* res;
        if (is_string((yyvsp[-2].str)) || is_string((yyvsp[0].str))) {
            asprintf(&res, "%s[0] >= %s[0]", (yyvsp[-2].str), (yyvsp[0].str));
            (yyval.str) = res;
        }else{
            res = make_binop((yyvsp[-2].str), ">=", (yyvsp[0].str));
        }
        (yyval.str) = res;
    }
#line 1590 "parser.tab.c"
    break;

  case 29: /* expr: expr LT expr  */
#line 315 "parser.y"
                   {
        char* res = make_binop((yyvsp[-2].str), "<", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1599 "parser.tab.c"
    break;

  case 30: /* expr: expr GT expr  */
#line 319 "parser.y"
                   {
        char* res = make_binop((yyvsp[-2].str), ">", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1608 "parser.tab.c"
    break;

  case 31: /* expr: expr EQ expr  */
#line 323 "parser.y"
                   {
        char* res;
        asprintf(&res, "strcmp(%s, %s) == 0", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1618 "parser.tab.c"
    break;

  case 32: /* expr: expr NE expr  */
#line 328 "parser.y"
                   {
        char* res = make_binop((yyvsp[-2].str), "!=", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1627 "parser.tab.c"
    break;

  case 33: /* expr: MINUS expr  */
#line 332 "parser.y"
                              {
        size_t len = strlen((yyvsp[0].str)) + 4;
        char* res = malloc(len);
        snprintf(res, len, "-(%s)", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1638 "parser.tab.c"
    break;

  case 34: /* expr: expr SR expr  */
#line 338 "parser.y"
                   {
        char* res;
        asprintf(&res, "strcmp(%s, %s) == 0", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1648 "parser.tab.c"
    break;

  case 35: /* function_call: FUNC_ID LPAREN RPAREN  */
#line 347 "parser.y"
                            {
        size_t len = strlen((yyvsp[-2].str)) + 3;
        char* res = malloc(len);
        snprintf(res, len, "%s()", (yyvsp[-2].str));
        (yyval.str) = res;
    }
#line 1659 "parser.tab.c"
    break;

  case 36: /* function_call: FUNC_ID LPAREN expr_list RPAREN  */
#line 353 "parser.y"
                                      {
        char* res;
        if (strcmp((yyvsp[-3].str), "CONCAT") == 0) {
            used_concat = 1;
            size_t len = strlen("concat(") + strlen((yyvsp[-1].str)) + 2;
            res = malloc(len);
            snprintf(res, len, "concat(%s)", (yyvsp[-1].str));
        } else if (strcmp((yyvsp[-3].str), "MID") == 0) {
            used_mid = 1;
            size_t len = strlen("mid(") + strlen((yyvsp[-1].str)) + 2;
            res = malloc(len);
            snprintf(res, len, "mid(%s)", (yyvsp[-1].str));
        } else if (strcmp((yyvsp[-3].str), "LEN") == 0) {
            size_t len = strlen("strlen(") + strlen((yyvsp[-1].str)) + 2;
            res = malloc(len);
            snprintf(res, len, "strlen(%s)", (yyvsp[-1].str));
        } else if (strcmp((yyvsp[-3].str), "TRACE") == 0) {
            size_t len = strlen("printf(\"%%s\\n\", ") + strlen((yyvsp[-1].str)) + 10;
            res = malloc(len);
            snprintf(res, len, "printf(\"%%s\\n\", %s);", (yyvsp[-1].str), (yyvsp[-1].str));
        } else {
            size_t len = strlen((yyvsp[-3].str)) + strlen((yyvsp[-1].str)) + 4;
            res = malloc(len);
            snprintf(res, len, "%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));
        }
        (yyval.str) = res;
    }
#line 1691 "parser.tab.c"
    break;

  case 37: /* statement: ID ASSIGN expr SEMICOLON  */
#line 382 "parser.y"
                               {
        size_t len = strlen((yyvsp[-3].str)) + strlen((yyvsp[-1].str)) + 15;
        char* res = malloc(len);
        snprintf(res, len, "%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str));
        (yyval.str) = res;
    }
#line 1702 "parser.tab.c"
    break;

  case 38: /* statement: WHILE expr DO block END_WHILE SEMICOLON  */
#line 388 "parser.y"
                                              {
        size_t len = strlen((yyvsp[-4].str)) + strlen((yyvsp[-2].str)) + 300;
        char* res = malloc(len);
        snprintf(res, len, "while (%s) {\n%s\t}", (yyvsp[-4].str), (yyvsp[-2].str));
        (yyval.str) = res;
    }
#line 1713 "parser.tab.c"
    break;

  case 39: /* statement: function_call SEMICOLON  */
#line 394 "parser.y"
                              {
        (yyval.str) = strdup((yyvsp[-1].str));
    }
#line 1721 "parser.tab.c"
    break;

  case 40: /* statement: IF expr THEN block if_tail END_IF SEMICOLON  */
#line 397 "parser.y"
                                                 {
        size_t len = strlen((yyvsp[-5].str)) + strlen((yyvsp[-3].str)) + strlen((yyvsp[-2].str)) + 40;
        char* res = malloc(len);
        snprintf(res, len, "if (%s) {\n%s\t}%s", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-2].str));
        (yyval.str) = res;
    }
#line 1732 "parser.tab.c"
    break;

  case 41: /* if_tail: %empty  */
#line 407 "parser.y"
                  { (yyval.str) = strdup(""); }
#line 1738 "parser.tab.c"
    break;

  case 42: /* if_tail: ELSIF expr THEN block if_tail  */
#line 408 "parser.y"
                                    {
        size_t len = strlen((yyvsp[-3].str)) + strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 25;
        char* res = malloc(len);
        snprintf(res, len, " else if (%s) {\n%s\t}%s", (yyvsp[-3].str), (yyvsp[-1].str), (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1749 "parser.tab.c"
    break;

  case 43: /* if_tail: ELSE block  */
#line 414 "parser.y"
                {
        size_t len = strlen((yyvsp[0].str)) + 20;
        char* res = malloc(len);
        snprintf(res, len, " else {\n%s\t}", (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1760 "parser.tab.c"
    break;

  case 44: /* statement_list: %empty  */
#line 423 "parser.y"
                  { (yyval.str) = strdup(""); }
#line 1766 "parser.tab.c"
    break;

  case 45: /* statement_list: statement_list statement  */
#line 424 "parser.y"
                               {
        size_t len = strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 10;
        char* res = malloc(len);
        snprintf(res, len, "%s\t%s\n", (yyvsp[-1].str), (yyvsp[0].str));
        (yyval.str) = res;
    }
#line 1777 "parser.tab.c"
    break;

  case 46: /* block: statement_list  */
#line 432 "parser.y"
                   {
        const char* input = (yyvsp[0].str);
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
        (yyval.str) = res;
    }
#line 1804 "parser.tab.c"
    break;


#line 1808 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 456 "parser.y"
