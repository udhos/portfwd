
/*  A Bison parser, made from conf.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TK_NAME	257
#define	TK_TCP	258
#define	TK_UDP	259
#define	TK_COLON	260
#define	TK_SCOLON	261
#define	TK_COMMA	262
#define	TK_SLASH	263
#define	TK_RANGE	264
#define	TK_LBRACE	265
#define	TK_RBRACE	266
#define	TK_ARROW	267
#define	TK_ACTV	268
#define	TK_PASV	269
#define	TK_USER	270
#define	TK_GROUP	271
#define	TK_BIND	272
#define	TK_ILLEGAL	273

#line 7 "conf.y"


#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

#include "util.h"
#include "solve.h"
#include "port_pair.h"
#include "proto_map.hpp"
#include "entry.hpp"
#include "portfwd.h"

extern int yylex();
extern char yytext[];
extern void show_last_token();
extern int conf_line_number;
extern char conf_ident[];

const char *const ANY_ADDR = "0.0.0.0";
const int MIN_MASK_LEN = 0;
const int MAX_MASK_LEN = 32;

int conf_syntax_errors = 0;

void yyerror(const char *msg)
{
  ++conf_syntax_errors;
  syslog(LOG_ERR, "Syntax error: %s\n", msg);
  show_last_token();
}

/* Variaveis Auxiliares */

proto_t curr_proto;
vector<from_addr*> *from_vector;
vector<host_map*>  *host_vector;
vector<int>        *port_vector;
vector<proto_map*> *map_vector;
vector<entry*>     *entry_vector = new vector<entry*>();

int            conf_user  = -1;
int            conf_group = -1;
struct ip_addr conf_bind  = solve_hostname(ANY_ADDR);

/* Funcoes Auxiliares */

int mask_len_value(const char *len)
{
  return atoi(len);
}

void set_protoname(proto_t proto)
{
  curr_proto = proto;
  ONVERBOSE(syslog(LOG_DEBUG, "Protocol: %s\n", get_protoname(curr_proto)))
}

int use_port(char *portname)
{
  int port = solve_port(portname, get_protoname(curr_proto));
  free(portname);
  return port;
}

struct ip_addr use_hostname(char *hostname)
{
  struct ip_addr ip = solve_hostname(hostname);
  free(hostname);
  return ip;
}

net_portion *use_hostprefix(char *hostname, int prefix_len)
{
  return new net_portion(use_hostname(hostname), prefix_len);  
}

to_addr *use_toaddr(char *hostname, int port)
{
  return new to_addr(on_the_fly_dns ? safe_strdup(hostname) : 0, 
		     use_hostname(hostname), 
		     port);
}


#line 114 "conf.y"
typedef union {
	int	           int_type;
        char               *str_type;
        port_pair          *port_type;
        net_portion        *net_type;
	from_addr   	   *from_type;
	vector<from_addr*> *from_list_type;
	host_map           *host_map_type;
	vector<host_map*>  *host_list_type;
	vector<int>        *port_list_type;
	proto_map          *map_type;
	vector<proto_map*> *map_list_type;
	entry		   *entry_type;
} YYSTYPE;
#line 143 "conf.y"

  /* Simbolo nao-terminal inicial */
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		79
#define	YYFLAG		-32768
#define	YYNTBASE	20

#define YYTRANSLATE(x) ((unsigned)(x) <= 273 ? yytranslate[x] : 39)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     3,     5,     8,    10,    12,    15,    18,    21,
    25,    29,    30,    31,    35,    37,    41,    46,    53,    60,
    69,    78,    80,    82,    86,    88,    92,    98,   100,   104,
   105,   107,   110,   114,   117,   118,   121,   123,   126,   129
};

static const short yyrhs[] = {    -1,
    21,     0,    22,     0,    21,    22,     0,    24,     0,    23,
     0,    16,     3,     0,    17,     3,     0,    18,     3,     0,
     4,    25,    27,     0,     5,    26,    27,     0,     0,     0,
    11,    28,    12,     0,    29,     0,    28,     7,    29,     0,
    31,    11,    32,    12,     0,    31,    14,    30,    11,    32,
    12,     0,    31,    15,    30,    11,    32,    12,     0,    31,
    14,    30,    15,    30,    11,    32,    12,     0,    31,    15,
    30,    14,    30,    11,    32,    12,     0,     3,     0,    30,
     0,    31,     8,    30,     0,    33,     0,    32,     7,    33,
     0,    34,    13,    30,     6,    30,     0,    35,     0,    34,
     8,    35,     0,     0,    36,     0,     6,    38,     0,    36,
     6,    38,     0,    30,    37,     0,     0,     9,     3,     0,
    30,     0,    30,    10,     0,    10,    30,     0,    30,    10,
    30,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   151,   151,   154,   154,   157,   157,   160,   160,   161,   164,
   164,   167,   168,   170,   172,   176,   182,   184,   188,   192,
   197,   204,   206,   210,   216,   220,   226,   232,   236,   242,
   244,   247,   250,   255,   260,   260,   263,   266,   270,   274
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","TK_NAME",
"TK_TCP","TK_UDP","TK_COLON","TK_SCOLON","TK_COMMA","TK_SLASH","TK_RANGE","TK_LBRACE",
"TK_RBRACE","TK_ARROW","TK_ACTV","TK_PASV","TK_USER","TK_GROUP","TK_BIND","TK_ILLEGAL",
"conf","stmt_list","stmt","global_option","entry","set_proto_tcp","set_proto_udp",
"section","map_list","map","name","port_list","host_list","host_map","from_list",
"from","host_prefix","prefix_length","port_range", NULL
};
#endif

static const short yyr1[] = {     0,
    20,    20,    21,    21,    22,    22,    23,    23,    23,    24,
    24,    25,    26,    27,    28,    28,    29,    29,    29,    29,
    29,    30,    31,    31,    32,    32,    33,    34,    34,    35,
    35,    35,    35,    36,    37,    37,    38,    38,    38,    38
};

static const short yyr2[] = {     0,
     0,     1,     1,     2,     1,     1,     2,     2,     2,     3,
     3,     0,     0,     3,     1,     3,     4,     6,     6,     8,
     8,     1,     1,     3,     1,     3,     5,     1,     3,     0,
     1,     2,     3,     2,     0,     2,     1,     2,     2,     3
};

static const short yydefact[] = {     1,
    12,    13,     0,     0,     0,     2,     3,     6,     5,     0,
     0,     7,     8,     9,     4,     0,    10,    11,    22,     0,
    15,    23,     0,     0,    14,     0,    30,     0,     0,    16,
    24,     0,    35,     0,    25,     0,    28,    31,     0,     0,
     0,    37,    32,     0,    34,    30,    17,    30,     0,     0,
    30,     0,    30,     0,    39,    38,    36,    26,    29,     0,
    33,     0,     0,     0,     0,    40,     0,    18,    30,    19,
    30,    27,     0,     0,    20,    21,     0,     0,     0
};

static const short yydefgoto[] = {    77,
     6,     7,     8,     9,    10,    11,    17,    20,    21,    33,
    23,    34,    35,    36,    37,    38,    45,    43
};

static const short yypact[] = {    10,
-32768,-32768,     2,    26,    28,    10,-32768,-32768,-32768,    39,
    39,-32768,-32768,-32768,-32768,    42,-32768,-32768,-32768,    23,
-32768,-32768,     9,    42,-32768,    42,     1,    42,    42,-32768,
-32768,    -1,    44,    25,-32768,    -2,-32768,    48,     7,    38,
    42,    45,-32768,    53,-32768,     1,-32768,     1,    42,    -1,
     1,    42,     1,    42,-32768,    42,-32768,-32768,-32768,    51,
-32768,    32,    47,    34,    49,-32768,    42,-32768,     1,-32768,
     1,-32768,    35,    36,-32768,-32768,    59,    61,-32768
};

static const short yypgoto[] = {-32768,
-32768,    56,-32768,-32768,-32768,-32768,    52,-32768,    40,   -16,
-32768,   -50,    19,-32768,    18,-32768,-32768,    17
};


#define	YYLAST		67


static const short yytable[] = {    22,
    62,    19,    64,    19,    12,    48,    32,    22,    41,    31,
    49,    39,    40,     1,     2,    42,    26,    51,    73,    27,
    74,    52,    28,    29,    55,     3,     4,     5,    13,    24,
    14,    46,    60,    42,    25,    63,    47,    65,    46,    66,
    46,    46,    46,    68,    19,    70,    75,    76,    53,    16,
    72,    54,    44,    50,    56,    57,    67,    69,    78,    71,
    79,    15,    18,    30,    58,    59,    61
};

static const short yycheck[] = {    16,
    51,     3,    53,     3,     3,     8,     6,    24,    10,    26,
    13,    28,    29,     4,     5,    32,     8,    11,    69,    11,
    71,    15,    14,    15,    41,    16,    17,    18,     3,     7,
     3,     7,    49,    50,    12,    52,    12,    54,     7,    56,
     7,     7,     7,    12,     3,    12,    12,    12,    11,    11,
    67,    14,     9,     6,    10,     3,     6,    11,     0,    11,
     0,     6,    11,    24,    46,    48,    50
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/misc/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/share/misc/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 5:
#line 157 "conf.y"
{ entry_vector-> push(yyvsp[0].entry_type); ;
    break;}
case 7:
#line 160 "conf.y"
{ conf_user = solve_user(conf_ident); ;
    break;}
case 8:
#line 161 "conf.y"
{ conf_group = solve_group(conf_ident); ;
    break;}
case 9:
#line 162 "conf.y"
{ conf_bind = solve_hostname(conf_ident); ;
    break;}
case 10:
#line 164 "conf.y"
{ yyval.entry_type = new entry(P_TCP, yyvsp[0].map_list_type); ;
    break;}
case 11:
#line 165 "conf.y"
{ yyval.entry_type = new entry(P_UDP, yyvsp[0].map_list_type); ;
    break;}
case 12:
#line 167 "conf.y"
{ set_protoname(P_TCP); ;
    break;}
case 13:
#line 168 "conf.y"
{ set_protoname(P_UDP); ;
    break;}
case 14:
#line 170 "conf.y"
{ yyval.map_list_type = yyvsp[-1].map_list_type; ;
    break;}
case 15:
#line 172 "conf.y"
{
			map_vector = new vector<proto_map*>();
			map_vector->push(yyvsp[0].map_type);
			yyval.map_list_type = map_vector;
		;
    break;}
case 16:
#line 177 "conf.y"
{
			map_vector->push(yyvsp[0].map_type);
			yyval.map_list_type = map_vector;
		;
    break;}
case 17:
#line 182 "conf.y"
{
			yyval.map_type = new proto_map(yyvsp[-3].port_list_type, yyvsp[-1].host_list_type, 0, 0, conf_user, conf_group, conf_bind);
		;
    break;}
case 18:
#line 185 "conf.y"
{
		        struct ip_addr ip = use_hostname(yyvsp[-3].str_type);
			yyval.map_type = new proto_map(yyvsp[-5].port_list_type, yyvsp[-1].host_list_type, &ip, 0, conf_user, conf_group, conf_bind);
		;
    break;}
case 19:
#line 189 "conf.y"
{
		        struct ip_addr ip = use_hostname(yyvsp[-3].str_type);
			yyval.map_type = new proto_map(yyvsp[-5].port_list_type, yyvsp[-1].host_list_type, 0, &ip, conf_user, conf_group, conf_bind);
		;
    break;}
case 20:
#line 193 "conf.y"
{
		        struct ip_addr ip1 = use_hostname(yyvsp[-5].str_type);
		        struct ip_addr ip2 = use_hostname(yyvsp[-3].str_type);
			yyval.map_type = new proto_map(yyvsp[-7].port_list_type, yyvsp[-1].host_list_type, &ip1, &ip2, conf_user, conf_group, conf_bind);
		;
    break;}
case 21:
#line 198 "conf.y"
{
		        struct ip_addr ip1 = use_hostname(yyvsp[-5].str_type);
		        struct ip_addr ip2 = use_hostname(yyvsp[-3].str_type);
			yyval.map_type = new proto_map(yyvsp[-7].port_list_type, yyvsp[-1].host_list_type, &ip2, &ip1, conf_user, conf_group, conf_bind);
		;
    break;}
case 22:
#line 204 "conf.y"
{ yyval.str_type = safe_strdup(conf_ident); ;
    break;}
case 23:
#line 206 "conf.y"
{
			port_vector = new vector<int>();
			port_vector->push(use_port(yyvsp[0].str_type));
			yyval.port_list_type = port_vector; 
		;
    break;}
case 24:
#line 211 "conf.y"
{
			port_vector->push(use_port(yyvsp[0].str_type));
			yyval.port_list_type = port_vector; 
		;
    break;}
case 25:
#line 216 "conf.y"
{
              		host_vector = new vector<host_map*>();
			host_vector->push(yyvsp[0].host_map_type);
			yyval.host_list_type = host_vector;
		;
    break;}
case 26:
#line 221 "conf.y"
{
			host_vector->push(yyvsp[0].host_map_type);
			yyval.host_list_type = host_vector;
		;
    break;}
case 27:
#line 226 "conf.y"
{
			int port = use_port(yyvsp[0].str_type);
			to_addr *to = use_toaddr(yyvsp[-2].str_type, port); /* new to_addr() */
			yyval.host_map_type = new host_map(yyvsp[-4].from_list_type, to);
		;
    break;}
case 28:
#line 232 "conf.y"
{
			from_vector = new vector<from_addr*>();
			from_vector->push(yyvsp[0].from_type);
			yyval.from_list_type = from_vector;
		;
    break;}
case 29:
#line 237 "conf.y"
{
			from_vector->push(yyvsp[0].from_type);
			yyval.from_list_type = from_vector;
		;
    break;}
case 30:
#line 242 "conf.y"
{ 
			yyval.from_type = new from_addr(new net_portion(solve_hostname(ANY_ADDR), MIN_MASK_LEN), new port_pair(FIRST_PORT, LAST_PORT)); 
		;
    break;}
case 31:
#line 245 "conf.y"
{ 
			yyval.from_type = new from_addr(yyvsp[0].net_type, new port_pair(FIRST_PORT, LAST_PORT)); 
		;
    break;}
case 32:
#line 248 "conf.y"
{ 
			yyval.from_type = new from_addr(new net_portion(solve_hostname(ANY_ADDR), MIN_MASK_LEN), yyvsp[0].port_type); 
		;
    break;}
case 33:
#line 251 "conf.y"
{ 
			yyval.from_type = new from_addr(yyvsp[-2].net_type, yyvsp[0].port_type); 
		;
    break;}
case 34:
#line 255 "conf.y"
{ 
			/* use_hostprefix(): new net_portion() */
  			yyval.net_type = use_hostprefix(yyvsp[-1].str_type, yyvsp[0].int_type); 
		;
    break;}
case 35:
#line 260 "conf.y"
{ yyval.int_type = MAX_MASK_LEN; ;
    break;}
case 36:
#line 261 "conf.y"
{ yyval.int_type = mask_len_value(conf_ident); ;
    break;}
case 37:
#line 263 "conf.y"
{
			int port = use_port(yyvsp[0].str_type);
			yyval.port_type = new port_pair(port, port);
		;
    break;}
case 38:
#line 267 "conf.y"
{ 
			yyval.port_type = new port_pair(use_port(yyvsp[-1].str_type), 
					   LAST_PORT); 
		;
    break;}
case 39:
#line 271 "conf.y"
{ 
			yyval.port_type = new port_pair(FIRST_PORT, 
				           use_port(yyvsp[0].str_type)); 
		;
    break;}
case 40:
#line 275 "conf.y"
{ 
			yyval.port_type = new port_pair(use_port(yyvsp[-2].str_type),
				           use_port(yyvsp[0].str_type));
		;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/share/misc/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 281 "conf.y"


/* C code */

/* eof: conf.y */

