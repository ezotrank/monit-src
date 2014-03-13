#include <config.h>
/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 26 "src/p.y"


/*
 * DESCRIPTION
 *   Simple context-free grammar for parsing the control file.
 *
 */

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif

#ifdef HAVE_PWD_H
#include <pwd.h>
#endif

#ifdef HAVE_GRP_H
#include <grp.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_TIME_H
#include <time.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_ASM_PARAM_H
#include <asm/param.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#endif

#ifndef HAVE_SOL_IP
#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#endif

#ifdef HAVE_NETINET_IP_ICMP_H
#include <netinet/ip_icmp.h>
#endif

#ifdef HAVE_REGEX_H
#include <regex.h>
#endif

#include "net.h"
#include "monit.h"
#include "protocol.h"
#include "engine.h"
#include "alert.h"
#include "process.h"
#include "ssl.h"
#include "device.h"

// libmonit
#include "io/File.h"


/* ------------------------------------------------------------- Definitions */

  struct IHavePrecedence {
    int daemon;
    int logfile;
    int pidfile;
  };

  struct myrate {
    unsigned count;
    unsigned cycles;
  };

  /* yacc interface */
  void  yyerror(const char *,...);
  void  yyerror2(const char *,...);
  void  yywarning(const char *,...);
  void  yywarning2(const char *,...);

  /* lexer interface */
  int yylex(void);
  extern FILE *yyin;
  extern int lineno;
  extern int arglineno;
  extern char *yytext;
  extern char *argyytext;
  extern char *currentfile;
  extern char *argcurrentfile;
  extern int buffer_stack_ptr;

  /* Local variables */
  static int cfg_errflag = FALSE;
  static Service_T tail = NULL;
  static Service_T current = NULL;
  static Request_T urlrequest = NULL;
  static command_t command = NULL;
  static command_t command1 = NULL;
  static command_t command2 = NULL;
  static Service_T depend_list = NULL;
  static struct mygid gidset;
  static struct myuid uidset;
  static struct mystatus statusset;
  static struct myperm permset;
  static struct mysize sizeset;
  static struct myuptime uptimeset;
  static struct mymatch matchset;
  static struct myicmp icmpset;
  static struct mymail mailset;
  static struct myport portset;
  static struct mymailserver mailserverset;
  static struct myfilesystem filesystemset;
  static struct myresource resourceset;
  static struct mychecksum checksumset;
  static struct mytimestamp timestampset;
  static struct myactionrate actionrateset;
  static struct IHavePrecedence ihp = {FALSE, FALSE, FALSE};
  static struct myrate rate1 = {1, 1};
  static struct myrate rate2 = {1, 1};
  static char * htpasswd_file = NULL;
  static int    digesttype = DIGEST_CLEARTEXT;

#define BITMAP_MAX (sizeof(long long) * 8)


/* -------------------------------------------------------------- Prototypes */

  static void  preparse();
  static void  postparse();
  static void  addmail(char *, Mail_T, Mail_T *);
  static Service_T createservice(int, char *, char *, int (*)(Service_T));
  static void  addservice(Service_T);
  static void  adddependant(char *);
  static void  addservicegroup(char *);
  static void  addport(Port_T);
  static void  addresource(Resource_T);
  static void  addtimestamp(Timestamp_T, int);
  static void  addactionrate(ActionRate_T);
  static void  addsize(Size_T);
  static void  adduptime(Uptime_T);
  static void  addfilesystem(Filesystem_T);
  static void  addicmp(Icmp_T);
  static void  addgeneric(Port_T, char*, char*);
  static void  addcommand(int, unsigned);
  static void  addargument(char *);
  static void  addmmonit(URL_T, int, int, char *);
  static void  addmailserver(MailServer_T);
  static int   addcredentials(char *, char *, int, int);
#ifdef HAVE_LIBPAM
  static void  addpamauth(char *, int);
#endif
  static void  addhtpasswdentry(char *, char *, int);
  static uid_t get_uid(char *, uid_t);
  static gid_t get_gid(char *, gid_t);
  static void  addchecksum(Checksum_T);
  static void  addperm(Perm_T);
  static void  addmatch(Match_T, int, int);
  static void  addmatchpath(Match_T, int);
  static void  addstatus(Status_T);
  static void  adduid(Uid_T);
  static void  addgid(Gid_T);
  static void  addeuid(uid_t);
  static void  addegid(gid_t);
  static void  addeventaction(EventAction_T *, int, int);
  static void  seteventaction(EventAction_T *, int, int);
  static void  prepare_urlrequest(URL_T U);
  static void  seturlrequest(int, char *);
  static void  setlogfile(char *);
  static void  setpidfile(char *);
  static void  reset_mailset();
  static void  reset_mailserverset();
  static void  reset_portset();
  static void  reset_resourceset();
  static void  reset_timestampset();
  static void  reset_actionrateset();
  static void  reset_sizeset();
  static void  reset_uptimeset();
  static void  reset_checksumset();
  static void  reset_permset();
  static void  reset_uidset();
  static void  reset_statusset();
  static void  reset_gidset();
  static void  reset_filesystemset();
  static void  reset_icmpset();
  static void  reset_rateset();
  static void  check_name(char *);
  static int   check_perm(int);
  static void  check_hostname (char *);
  static void  check_exec(char *);
  static int   cleanup_hash_string(char *);
  static void  check_depend();
  static void  setsyslog(char *);
  static command_t copycommand(command_t);
  static int verifyMaxForward(int);



/* Line 268 of yacc.c  */
#line 305 "src/y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     THEN = 260,
     OR = 261,
     FAILED = 262,
     SET = 263,
     LOGFILE = 264,
     FACILITY = 265,
     DAEMON = 266,
     SYSLOG = 267,
     MAILSERVER = 268,
     HTTPD = 269,
     ALLOW = 270,
     ADDRESS = 271,
     INIT = 272,
     READONLY = 273,
     CLEARTEXT = 274,
     MD5HASH = 275,
     SHA1HASH = 276,
     CRYPT = 277,
     DELAY = 278,
     PEMFILE = 279,
     ENABLE = 280,
     DISABLE = 281,
     HTTPDSSL = 282,
     CLIENTPEMFILE = 283,
     ALLOWSELFCERTIFICATION = 284,
     IDFILE = 285,
     STATEFILE = 286,
     SEND = 287,
     EXPECT = 288,
     EXPECTBUFFER = 289,
     CYCLE = 290,
     COUNT = 291,
     REMINDER = 292,
     PIDFILE = 293,
     START = 294,
     STOP = 295,
     PATHTOK = 296,
     HOST = 297,
     HOSTNAME = 298,
     PORT = 299,
     TYPE = 300,
     UDP = 301,
     TCP = 302,
     TCPSSL = 303,
     PROTOCOL = 304,
     CONNECTION = 305,
     ALERT = 306,
     NOALERT = 307,
     MAILFORMAT = 308,
     UNIXSOCKET = 309,
     SIGNATURE = 310,
     TIMEOUT = 311,
     RETRY = 312,
     RESTART = 313,
     CHECKSUM = 314,
     EVERY = 315,
     NOTEVERY = 316,
     DEFAULT = 317,
     HTTP = 318,
     APACHESTATUS = 319,
     FTP = 320,
     SMTP = 321,
     POP = 322,
     IMAP = 323,
     CLAMAV = 324,
     NNTP = 325,
     NTP3 = 326,
     MYSQL = 327,
     DNS = 328,
     SSH = 329,
     DWP = 330,
     LDAP2 = 331,
     LDAP3 = 332,
     RDATE = 333,
     RSYNC = 334,
     TNS = 335,
     PGSQL = 336,
     POSTFIXPOLICY = 337,
     SIP = 338,
     LMTP = 339,
     GPS = 340,
     RADIUS = 341,
     MEMCACHE = 342,
     STRING = 343,
     PATH = 344,
     MAILADDR = 345,
     MAILFROM = 346,
     MAILREPLYTO = 347,
     MAILSUBJECT = 348,
     MAILBODY = 349,
     SERVICENAME = 350,
     STRINGNAME = 351,
     NUMBER = 352,
     PERCENT = 353,
     LOGLIMIT = 354,
     CLOSELIMIT = 355,
     DNSLIMIT = 356,
     KEEPALIVELIMIT = 357,
     REPLYLIMIT = 358,
     REQUESTLIMIT = 359,
     STARTLIMIT = 360,
     WAITLIMIT = 361,
     GRACEFULLIMIT = 362,
     CLEANUPLIMIT = 363,
     REAL = 364,
     CHECKPROC = 365,
     CHECKFILESYS = 366,
     CHECKFILE = 367,
     CHECKDIR = 368,
     CHECKHOST = 369,
     CHECKSYSTEM = 370,
     CHECKFIFO = 371,
     CHECKPROGRAM = 372,
     CHILDREN = 373,
     SYSTEM = 374,
     STATUS = 375,
     RESOURCE = 376,
     MEMORY = 377,
     TOTALMEMORY = 378,
     LOADAVG1 = 379,
     LOADAVG5 = 380,
     LOADAVG15 = 381,
     SWAP = 382,
     MODE = 383,
     ACTIVE = 384,
     PASSIVE = 385,
     MANUAL = 386,
     CPU = 387,
     TOTALCPU = 388,
     CPUUSER = 389,
     CPUSYSTEM = 390,
     CPUWAIT = 391,
     GROUP = 392,
     REQUEST = 393,
     DEPENDS = 394,
     BASEDIR = 395,
     SLOT = 396,
     EVENTQUEUE = 397,
     SECRET = 398,
     HOSTHEADER = 399,
     UID = 400,
     GID = 401,
     MMONIT = 402,
     INSTANCE = 403,
     USERNAME = 404,
     PASSWORD = 405,
     TIMESTAMP = 406,
     CHANGED = 407,
     SECOND = 408,
     MINUTE = 409,
     HOUR = 410,
     DAY = 411,
     SSLAUTO = 412,
     SSLV2 = 413,
     SSLV3 = 414,
     TLSV1 = 415,
     CERTMD5 = 416,
     BYTE = 417,
     KILOBYTE = 418,
     MEGABYTE = 419,
     GIGABYTE = 420,
     INODE = 421,
     SPACE = 422,
     PERMISSION = 423,
     SIZE = 424,
     MATCH = 425,
     NOT = 426,
     IGNORE = 427,
     ACTION = 428,
     UPTIME = 429,
     EXEC = 430,
     UNMONITOR = 431,
     ICMP = 432,
     ICMPECHO = 433,
     NONEXIST = 434,
     EXIST = 435,
     INVALID = 436,
     DATA = 437,
     RECOVERED = 438,
     PASSED = 439,
     SUCCEEDED = 440,
     URL = 441,
     CONTENT = 442,
     PID = 443,
     PPID = 444,
     FSFLAG = 445,
     REGISTER = 446,
     CREDENTIALS = 447,
     URLOBJECT = 448,
     TARGET = 449,
     TIMESPEC = 450,
     MAXFORWARD = 451,
     FIPS = 452,
     NOTEQUAL = 453,
     EQUAL = 454,
     LESS = 455,
     GREATER = 456
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define THEN 260
#define OR 261
#define FAILED 262
#define SET 263
#define LOGFILE 264
#define FACILITY 265
#define DAEMON 266
#define SYSLOG 267
#define MAILSERVER 268
#define HTTPD 269
#define ALLOW 270
#define ADDRESS 271
#define INIT 272
#define READONLY 273
#define CLEARTEXT 274
#define MD5HASH 275
#define SHA1HASH 276
#define CRYPT 277
#define DELAY 278
#define PEMFILE 279
#define ENABLE 280
#define DISABLE 281
#define HTTPDSSL 282
#define CLIENTPEMFILE 283
#define ALLOWSELFCERTIFICATION 284
#define IDFILE 285
#define STATEFILE 286
#define SEND 287
#define EXPECT 288
#define EXPECTBUFFER 289
#define CYCLE 290
#define COUNT 291
#define REMINDER 292
#define PIDFILE 293
#define START 294
#define STOP 295
#define PATHTOK 296
#define HOST 297
#define HOSTNAME 298
#define PORT 299
#define TYPE 300
#define UDP 301
#define TCP 302
#define TCPSSL 303
#define PROTOCOL 304
#define CONNECTION 305
#define ALERT 306
#define NOALERT 307
#define MAILFORMAT 308
#define UNIXSOCKET 309
#define SIGNATURE 310
#define TIMEOUT 311
#define RETRY 312
#define RESTART 313
#define CHECKSUM 314
#define EVERY 315
#define NOTEVERY 316
#define DEFAULT 317
#define HTTP 318
#define APACHESTATUS 319
#define FTP 320
#define SMTP 321
#define POP 322
#define IMAP 323
#define CLAMAV 324
#define NNTP 325
#define NTP3 326
#define MYSQL 327
#define DNS 328
#define SSH 329
#define DWP 330
#define LDAP2 331
#define LDAP3 332
#define RDATE 333
#define RSYNC 334
#define TNS 335
#define PGSQL 336
#define POSTFIXPOLICY 337
#define SIP 338
#define LMTP 339
#define GPS 340
#define RADIUS 341
#define MEMCACHE 342
#define STRING 343
#define PATH 344
#define MAILADDR 345
#define MAILFROM 346
#define MAILREPLYTO 347
#define MAILSUBJECT 348
#define MAILBODY 349
#define SERVICENAME 350
#define STRINGNAME 351
#define NUMBER 352
#define PERCENT 353
#define LOGLIMIT 354
#define CLOSELIMIT 355
#define DNSLIMIT 356
#define KEEPALIVELIMIT 357
#define REPLYLIMIT 358
#define REQUESTLIMIT 359
#define STARTLIMIT 360
#define WAITLIMIT 361
#define GRACEFULLIMIT 362
#define CLEANUPLIMIT 363
#define REAL 364
#define CHECKPROC 365
#define CHECKFILESYS 366
#define CHECKFILE 367
#define CHECKDIR 368
#define CHECKHOST 369
#define CHECKSYSTEM 370
#define CHECKFIFO 371
#define CHECKPROGRAM 372
#define CHILDREN 373
#define SYSTEM 374
#define STATUS 375
#define RESOURCE 376
#define MEMORY 377
#define TOTALMEMORY 378
#define LOADAVG1 379
#define LOADAVG5 380
#define LOADAVG15 381
#define SWAP 382
#define MODE 383
#define ACTIVE 384
#define PASSIVE 385
#define MANUAL 386
#define CPU 387
#define TOTALCPU 388
#define CPUUSER 389
#define CPUSYSTEM 390
#define CPUWAIT 391
#define GROUP 392
#define REQUEST 393
#define DEPENDS 394
#define BASEDIR 395
#define SLOT 396
#define EVENTQUEUE 397
#define SECRET 398
#define HOSTHEADER 399
#define UID 400
#define GID 401
#define MMONIT 402
#define INSTANCE 403
#define USERNAME 404
#define PASSWORD 405
#define TIMESTAMP 406
#define CHANGED 407
#define SECOND 408
#define MINUTE 409
#define HOUR 410
#define DAY 411
#define SSLAUTO 412
#define SSLV2 413
#define SSLV3 414
#define TLSV1 415
#define CERTMD5 416
#define BYTE 417
#define KILOBYTE 418
#define MEGABYTE 419
#define GIGABYTE 420
#define INODE 421
#define SPACE 422
#define PERMISSION 423
#define SIZE 424
#define MATCH 425
#define NOT 426
#define IGNORE 427
#define ACTION 428
#define UPTIME 429
#define EXEC 430
#define UNMONITOR 431
#define ICMP 432
#define ICMPECHO 433
#define NONEXIST 434
#define EXIST 435
#define INVALID 436
#define DATA 437
#define RECOVERED 438
#define PASSED 439
#define SUCCEEDED 440
#define URL 441
#define CONTENT 442
#define PID 443
#define PPID 444
#define FSFLAG 445
#define REGISTER 446
#define CREDENTIALS 447
#define URLOBJECT 448
#define TARGET 449
#define TIMESPEC 450
#define MAXFORWARD 451
#define FIPS 452
#define NOTEQUAL 453
#define EQUAL 454
#define LESS 455
#define GREATER 456




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 259 "src/p.y"

  URL_T url;
  float real;
  int   number;
  char *string;



/* Line 293 of yacc.c  */
#line 752 "src/y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 764 "src/y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   992

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  206
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  164
/* YYNRULES -- Number of rules.  */
#define YYNRULES  505
/* YYNRULES -- Number of states.  */
#define YYNSTATES  889

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   456

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   204,     2,
       2,     2,     2,     2,   205,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   202,     2,   203,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    42,    45,    48,    51,    54,    57,    60,    63,    64,
      67,    69,    71,    73,    75,    77,    79,    81,    83,    85,
      87,    89,    91,    93,    95,    97,    99,   100,   103,   105,
     107,   109,   111,   113,   115,   117,   119,   121,   123,   125,
     127,   129,   131,   133,   135,   137,   138,   141,   143,   145,
     147,   149,   151,   153,   155,   157,   159,   161,   163,   165,
     167,   169,   171,   173,   174,   177,   179,   181,   183,   185,
     187,   189,   191,   193,   195,   197,   199,   201,   203,   205,
     207,   210,   212,   214,   216,   218,   220,   222,   224,   226,
     228,   230,   232,   234,   235,   238,   240,   242,   244,   246,
     248,   250,   252,   254,   256,   257,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     288,   289,   292,   294,   296,   298,   300,   302,   304,   306,
     308,   310,   312,   317,   325,   334,   339,   340,   344,   349,
     352,   355,   359,   363,   369,   374,   381,   386,   390,   394,
     398,   402,   405,   409,   414,   415,   418,   424,   430,   436,
     438,   441,   447,   455,   456,   459,   461,   463,   465,   467,
     470,   473,   474,   477,   479,   481,   483,   486,   489,   492,
     495,   497,   499,   502,   505,   508,   511,   514,   517,   520,
     522,   528,   533,   536,   540,   544,   548,   549,   554,   555,
     561,   562,   568,   569,   575,   578,   580,   583,   585,   586,
     588,   593,   598,   603,   608,   613,   618,   623,   628,   631,
     636,   642,   646,   651,   655,   660,   664,   669,   671,   674,
     676,   679,   681,   683,   686,   689,   692,   695,   696,   699,
     702,   703,   706,   707,   710,   723,   735,   747,   758,   759,
     762,   765,   768,   769,   772,   777,   780,   781,   784,   785,
     787,   789,   791,   793,   794,   798,   801,   804,   807,   810,
     814,   817,   820,   823,   826,   829,   834,   837,   840,   843,
     846,   849,   852,   855,   858,   861,   864,   867,   870,   874,
     877,   879,   881,   884,   887,   890,   891,   894,   897,   898,
     901,   902,   906,   912,   913,   916,   919,   921,   925,   930,
     935,   940,   945,   950,   955,   960,   965,   970,   975,   983,
     990,   997,  1007,  1008,  1011,  1012,  1016,  1017,  1021,  1022,
    1026,  1027,  1030,  1038,  1046,  1047,  1051,  1053,  1055,  1059,
    1066,  1074,  1076,  1079,  1082,  1084,  1087,  1089,  1091,  1093,
    1095,  1097,  1099,  1101,  1103,  1105,  1107,  1109,  1111,  1113,
    1115,  1117,  1119,  1121,  1123,  1125,  1127,  1129,  1131,  1132,
    1137,  1139,  1142,  1144,  1146,  1148,  1150,  1154,  1157,  1160,
    1163,  1166,  1169,  1172,  1175,  1177,  1180,  1182,  1191,  1198,
    1200,  1203,  1205,  1207,  1209,  1211,  1218,  1220,  1223,  1225,
    1227,  1229,  1231,  1236,  1241,  1246,  1248,  1250,  1252,  1257,
    1262,  1267,  1272,  1277,  1282,  1286,  1290,  1292,  1294,  1296,
    1298,  1300,  1310,  1317,  1318,  1320,  1322,  1324,  1326,  1328,
    1329,  1331,  1333,  1335,  1337,  1339,  1342,  1346,  1348,  1350,
    1352,  1354,  1356,  1358,  1359,  1362,  1366,  1367,  1370,  1374,
    1375,  1382,  1389,  1396,  1405,  1416,  1424,  1425,  1427,  1429,
    1438,  1448,  1458,  1468,  1475,  1476,  1478,  1480,  1482,  1484,
    1493,  1501,  1509,  1514,  1519,  1520,  1522,  1532,  1539,  1548,
    1557,  1566,  1575,  1578,  1579,  1582
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     207,     0,    -1,    -1,   208,    -1,   209,    -1,   208,   209,
      -1,   226,    -1,   227,    -1,   232,    -1,   233,    -1,   237,
      -1,   241,    -1,   242,    -1,   243,    -1,   236,    -1,   234,
      -1,   235,    -1,   229,    -1,   230,    -1,   231,    -1,   268,
     210,    -1,   269,   212,    -1,   270,   214,    -1,   271,   216,
      -1,   272,   218,    -1,   273,   220,    -1,   274,   222,    -1,
     275,   224,    -1,    -1,   210,   211,    -1,   276,    -1,   277,
      -1,   278,    -1,   305,    -1,   306,    -1,   307,    -1,   308,
      -1,   286,    -1,   287,    -1,   314,    -1,   317,    -1,   325,
      -1,   326,    -1,   327,    -1,   328,    -1,   332,    -1,    -1,
     212,   213,    -1,   276,    -1,   277,    -1,   278,    -1,   305,
      -1,   347,    -1,   314,    -1,   325,    -1,   317,    -1,   362,
      -1,   366,    -1,   367,    -1,   356,    -1,   365,    -1,   363,
      -1,   326,    -1,   327,    -1,   328,    -1,    -1,   214,   215,
      -1,   276,    -1,   277,    -1,   278,    -1,   305,    -1,   314,
      -1,   325,    -1,   317,    -1,   362,    -1,   366,    -1,   367,
      -1,   326,    -1,   327,    -1,   328,    -1,   358,    -1,   359,
      -1,   360,    -1,    -1,   216,   217,    -1,   276,    -1,   277,
      -1,   278,    -1,   305,    -1,   347,    -1,   314,    -1,   325,
      -1,   317,    -1,   362,    -1,   366,    -1,   367,    -1,   326,
      -1,   327,    -1,   328,    -1,   219,    -1,   218,   219,    -1,
     276,    -1,   277,    -1,   278,    -1,   305,    -1,   286,    -1,
     288,    -1,   314,    -1,   317,    -1,   325,    -1,   326,    -1,
     327,    -1,   328,    -1,    -1,   220,   221,    -1,   276,    -1,
     277,    -1,   278,    -1,   314,    -1,   317,    -1,   325,    -1,
     327,    -1,   328,    -1,   335,    -1,    -1,   222,   223,    -1,
     276,    -1,   277,    -1,   278,    -1,   305,    -1,   347,    -1,
     314,    -1,   325,    -1,   317,    -1,   362,    -1,   366,    -1,
     367,    -1,   326,    -1,   327,    -1,   328,    -1,    -1,   224,
     225,    -1,   276,    -1,   277,    -1,   278,    -1,   314,    -1,
     305,    -1,   317,    -1,   325,    -1,   327,    -1,   328,    -1,
     331,    -1,     8,   318,   322,   369,    -1,     8,   318,   202,
     320,   203,   322,   369,    -1,     8,   318,   171,   202,   320,
     203,   322,   369,    -1,     8,    11,    97,   228,    -1,    -1,
      39,    23,    97,    -1,     8,    34,    97,   361,    -1,     8,
      17,    -1,     8,   197,    -1,     8,     9,    89,    -1,     8,
       9,    12,    -1,     8,     9,    12,    10,    88,    -1,     8,
     142,   140,    89,    -1,     8,   142,   140,    89,   141,    97,
      -1,     8,   142,   141,    97,    -1,     8,    30,    89,    -1,
       8,    31,    89,    -1,     8,    38,    89,    -1,     8,   147,
     238,    -1,   239,   240,    -1,   238,   239,   240,    -1,   193,
     312,   294,   293,    -1,    -1,   191,   192,    -1,     8,    13,
     244,   312,   285,    -1,     8,    53,   202,   323,   203,    -1,
       8,    14,    44,    97,   246,    -1,   245,    -1,   244,   245,
      -1,    88,   283,   284,   294,   293,    -1,    88,    44,    97,
     283,   284,   294,   293,    -1,    -1,   246,   247,    -1,   248,
      -1,   253,    -1,   256,    -1,   260,    -1,   252,   249,    -1,
     251,   249,    -1,    -1,   249,   250,    -1,   257,    -1,   258,
      -1,   259,    -1,    27,    25,    -1,    25,    27,    -1,    27,
      26,    -1,    26,    27,    -1,   254,    -1,   255,    -1,    55,
      25,    -1,    25,    55,    -1,    55,    26,    -1,    26,    55,
      -1,    16,    88,    -1,    24,    89,    -1,    28,    89,    -1,
      29,    -1,    15,    88,   204,    88,   267,    -1,    15,   205,
      88,   267,    -1,    15,    89,    -1,    15,    19,    89,    -1,
      15,    20,    89,    -1,    15,    22,    89,    -1,    -1,    15,
      89,   261,   265,    -1,    -1,    15,    19,    89,   262,   265,
      -1,    -1,    15,    20,    89,   263,   265,    -1,    -1,    15,
      22,    89,   264,   265,    -1,    15,    88,    -1,   266,    -1,
     265,   266,    -1,    88,    -1,    -1,    18,    -1,   110,    95,
      38,    89,    -1,   110,    95,    41,    89,    -1,   110,    95,
     170,    88,    -1,   110,    95,   170,    89,    -1,   112,    95,
      41,    89,    -1,   111,    95,    41,    89,    -1,   113,    95,
      41,    89,    -1,   114,    95,    16,    88,    -1,   115,    95,
      -1,   116,    95,    41,    89,    -1,   117,    95,    41,   279,
     311,    -1,    39,   279,   310,    -1,    39,   279,   280,   310,
      -1,    40,   279,   310,    -1,    40,   279,   280,   310,    -1,
      58,   279,   310,    -1,    58,   279,   280,   310,    -1,   281,
      -1,   279,   281,    -1,   282,    -1,   280,   282,    -1,    88,
      -1,    89,    -1,   145,    88,    -1,   146,    88,    -1,   145,
      97,    -1,   146,    97,    -1,    -1,   149,    90,    -1,   149,
      88,    -1,    -1,   150,    88,    -1,    -1,    43,    88,    -1,
       3,     7,   289,   290,   292,   295,   312,   313,   353,     5,
     351,   355,    -1,     3,     7,   186,   193,   315,   312,   313,
     353,     5,   351,   355,    -1,     3,     7,   291,   292,   295,
     312,   313,   353,     5,   351,   355,    -1,     3,     7,   177,
     368,   309,   312,   353,     5,   351,   355,    -1,    -1,    42,
      88,    -1,    44,    97,    -1,    54,    89,    -1,    -1,    45,
      47,    -1,    45,    48,   294,   293,    -1,    45,    46,    -1,
      -1,   161,    88,    -1,    -1,   158,    -1,   159,    -1,   160,
      -1,   157,    -1,    -1,    49,    64,   303,    -1,    49,    62,
      -1,    49,    73,    -1,    49,    75,    -1,    49,    65,    -1,
      49,    63,   300,    -1,    49,    68,    -1,    49,    69,    -1,
      49,    76,    -1,    49,    77,    -1,    49,    72,    -1,    49,
      83,   298,   299,    -1,    49,    70,    -1,    49,    71,    -1,
      49,    82,    -1,    49,    67,    -1,    49,    66,    -1,    49,
      74,    -1,    49,    78,    -1,    49,    79,    -1,    49,    80,
      -1,    49,    81,    -1,    49,    84,    -1,    49,    85,    -1,
      49,    86,   302,    -1,    49,    87,    -1,   296,    -1,   297,
      -1,   296,   297,    -1,    32,    88,    -1,    33,    88,    -1,
      -1,   194,    90,    -1,   194,    88,    -1,    -1,   196,    97,
      -1,    -1,   138,    89,   301,    -1,   138,    89,    59,    88,
     301,    -1,    -1,   144,    88,    -1,   143,    88,    -1,   304,
      -1,   303,     6,   304,    -1,    99,   348,    97,    98,    -1,
     100,   348,    97,    98,    -1,   101,   348,    97,    98,    -1,
     102,   348,    97,    98,    -1,   103,   348,    97,    98,    -1,
     104,   348,    97,    98,    -1,   105,   348,    97,    98,    -1,
     106,   348,    97,    98,    -1,   107,   348,    97,    98,    -1,
     108,   348,    97,    98,    -1,     3,   171,   180,   353,     5,
     351,   355,    -1,     3,   152,   188,   353,     5,   351,    -1,
       3,   152,   189,   353,     5,   351,    -1,     3,   174,   348,
      97,   349,   353,     5,   351,   355,    -1,    -1,    36,    97,
      -1,    -1,    56,    97,   153,    -1,    -1,    56,    97,   153,
      -1,    -1,    56,    97,   153,    -1,    -1,    57,    97,    -1,
       3,    97,    58,    97,    35,     5,   351,    -1,     3,    97,
      58,    97,    35,     5,    56,    -1,    -1,   187,   316,    88,
      -1,   199,    -1,   198,    -1,   318,   322,   369,    -1,   318,
     202,   320,   203,   322,   369,    -1,   318,   171,   202,   320,
     203,   322,   369,    -1,   319,    -1,    51,    90,    -1,    52,
      90,    -1,   321,    -1,   320,   321,    -1,   173,    -1,    59,
      -1,    50,    -1,   187,    -1,   182,    -1,   175,    -1,   190,
      -1,   146,    -1,   177,    -1,   148,    -1,   181,    -1,   179,
      -1,   168,    -1,   188,    -1,   189,    -1,   121,    -1,   169,
      -1,   120,    -1,    56,    -1,   151,    -1,   145,    -1,   174,
      -1,    -1,    53,   202,   323,   203,    -1,   324,    -1,   323,
     324,    -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,
      60,    97,    35,    -1,    60,   195,    -1,    61,   195,    -1,
     128,   129,    -1,   128,   130,    -1,   128,   131,    -1,   137,
      96,    -1,   139,   329,    -1,   330,    -1,   329,   330,    -1,
      95,    -1,     3,   120,   348,    97,   353,     5,   351,   355,
      -1,     3,   333,   353,     5,   351,   355,    -1,   334,    -1,
     333,   334,    -1,   338,    -1,   341,    -1,   343,    -1,   344,
      -1,     3,   336,   353,     5,   351,   355,    -1,   337,    -1,
     336,   337,    -1,   344,    -1,   341,    -1,   342,    -1,   339,
      -1,   132,   348,    97,    98,    -1,   133,   348,    97,    98,
      -1,   340,   348,    97,    98,    -1,   134,    -1,   135,    -1,
     136,    -1,   122,   348,   346,   361,    -1,   122,   348,    97,
      98,    -1,   123,   348,   346,   361,    -1,   123,   348,    97,
      98,    -1,   127,   348,   346,   361,    -1,   127,   348,    97,
      98,    -1,   118,   348,    97,    -1,   345,   348,   346,    -1,
     124,    -1,   125,    -1,   126,    -1,   109,    -1,    97,    -1,
       3,   151,   348,    97,   349,   353,     5,   351,   355,    -1,
       3,   152,   151,   353,     5,   351,    -1,    -1,   201,    -1,
     200,    -1,   199,    -1,   198,    -1,   152,    -1,    -1,   153,
      -1,   154,    -1,   155,    -1,   156,    -1,    51,    -1,   175,
     279,    -1,   175,   279,   280,    -1,    58,    -1,    39,    -1,
      40,    -1,   176,    -1,   350,    -1,   350,    -1,    -1,    97,
      35,    -1,    97,    97,    35,    -1,    -1,    97,    35,    -1,
      97,    97,    35,    -1,    -1,     4,     3,   183,   354,     5,
     352,    -1,     4,     3,   184,   354,     5,   352,    -1,     4,
       3,   185,   354,     5,   352,    -1,     3,     7,   357,    59,
     353,     5,   351,   355,    -1,     3,     7,   357,    59,    33,
      88,   353,     5,   351,   355,    -1,     3,   152,   357,    59,
     353,     5,   351,    -1,    -1,    20,    -1,    21,    -1,     3,
     166,   348,    97,   353,     5,   351,   355,    -1,     3,   166,
     348,    97,    98,   353,     5,   351,   355,    -1,     3,   167,
     348,   346,   361,   353,     5,   351,   355,    -1,     3,   167,
     348,    97,    98,   353,     5,   351,   355,    -1,     3,   152,
     190,   353,     5,   351,    -1,    -1,   162,    -1,   163,    -1,
     164,    -1,   165,    -1,     3,     7,   168,    97,   353,     5,
     351,   355,    -1,     3,   364,   170,    89,   353,     5,   351,
      -1,     3,   364,   170,    88,   353,     5,   351,    -1,   172,
     364,   170,    89,    -1,   172,   364,   170,    88,    -1,    -1,
     171,    -1,     3,   169,   348,    97,   361,   353,     5,   351,
     355,    -1,     3,   152,   169,   353,     5,   351,    -1,     3,
       7,   145,    88,   353,     5,   351,   355,    -1,     3,     7,
     145,    97,   353,     5,   351,   355,    -1,     3,     7,   146,
      88,   353,     5,   351,   355,    -1,     3,     7,   146,    97,
     353,     5,   351,   355,    -1,    45,   178,    -1,    -1,    37,
      97,    -1,    37,    97,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   305,   305,   306,   309,   310,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   337,   338,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   359,   360,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   382,   383,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   404,   405,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   424,
     425,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   442,   443,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   457,   458,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     477,   478,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   493,   497,   500,   506,   516,   517,   520,   525,
     530,   537,   545,   548,   553,   556,   560,   566,   571,   576,
     584,   587,   588,   591,   597,   598,   603,   610,   619,   625,
     626,   629,   648,   667,   668,   671,   672,   673,   674,   677,
     680,   691,   692,   695,   696,   697,   700,   701,   704,   705,
     708,   709,   712,   713,   716,   717,   720,   723,   728,   736,
     741,   744,   752,   756,   760,   764,   768,   768,   775,   775,
     782,   782,   789,   789,   796,   804,   805,   808,   812,   813,
     816,   819,   822,   829,   838,   843,   848,   853,   859,   871,
     876,   884,   887,   892,   895,   901,   904,   909,   910,   913,
     914,   917,   918,   921,   922,   923,   924,   927,   928,   929,
     932,   933,   936,   937,   940,   947,   957,   966,   976,   982,
     985,   988,   993,   996,   999,  1007,  1012,  1013,  1016,  1017,
    1018,  1019,  1020,  1023,  1026,  1029,  1032,  1035,  1038,  1041,
    1044,  1047,  1050,  1053,  1056,  1059,  1062,  1065,  1069,  1072,
    1075,  1078,  1081,  1084,  1087,  1090,  1093,  1096,  1099,  1102,
    1105,  1110,  1111,  1114,  1115,  1118,  1119,  1122,  1127,  1128,
    1133,  1134,  1138,  1145,  1146,  1151,  1156,  1157,  1160,  1164,
    1168,  1172,  1176,  1180,  1184,  1188,  1192,  1196,  1202,  1208,
    1213,  1218,  1225,  1228,  1233,  1236,  1241,  1244,  1249,  1252,
    1257,  1260,  1265,  1271,  1279,  1280,  1286,  1287,  1290,  1294,
    1297,  1301,  1306,  1309,  1312,  1313,  1316,  1317,  1318,  1319,
    1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,  1340,  1341,
    1344,  1345,  1348,  1349,  1350,  1351,  1354,  1358,  1362,  1368,
    1371,  1374,  1380,  1384,  1387,  1388,  1391,  1394,  1402,  1408,
    1409,  1412,  1413,  1414,  1415,  1418,  1424,  1425,  1428,  1429,
    1430,  1431,  1434,  1439,  1446,  1453,  1454,  1455,  1458,  1463,
    1468,  1473,  1480,  1485,  1492,  1499,  1506,  1507,  1508,  1511,
    1512,  1515,  1521,  1528,  1529,  1530,  1531,  1532,  1533,  1536,
    1537,  1538,  1539,  1540,  1543,  1544,  1545,  1546,  1547,  1548,
    1549,  1552,  1561,  1570,  1571,  1577,  1587,  1588,  1594,  1604,
    1607,  1610,  1613,  1618,  1622,  1629,  1635,  1636,  1637,  1640,
    1647,  1656,  1665,  1674,  1679,  1680,  1681,  1682,  1683,  1686,
    1693,  1700,  1706,  1713,  1721,  1724,  1730,  1736,  1743,  1749,
    1756,  1762,  1769,  1772,  1773,  1774
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "THEN", "OR", "FAILED",
  "SET", "LOGFILE", "FACILITY", "DAEMON", "SYSLOG", "MAILSERVER", "HTTPD",
  "ALLOW", "ADDRESS", "INIT", "READONLY", "CLEARTEXT", "MD5HASH",
  "SHA1HASH", "CRYPT", "DELAY", "PEMFILE", "ENABLE", "DISABLE", "HTTPDSSL",
  "CLIENTPEMFILE", "ALLOWSELFCERTIFICATION", "IDFILE", "STATEFILE", "SEND",
  "EXPECT", "EXPECTBUFFER", "CYCLE", "COUNT", "REMINDER", "PIDFILE",
  "START", "STOP", "PATHTOK", "HOST", "HOSTNAME", "PORT", "TYPE", "UDP",
  "TCP", "TCPSSL", "PROTOCOL", "CONNECTION", "ALERT", "NOALERT",
  "MAILFORMAT", "UNIXSOCKET", "SIGNATURE", "TIMEOUT", "RETRY", "RESTART",
  "CHECKSUM", "EVERY", "NOTEVERY", "DEFAULT", "HTTP", "APACHESTATUS",
  "FTP", "SMTP", "POP", "IMAP", "CLAMAV", "NNTP", "NTP3", "MYSQL", "DNS",
  "SSH", "DWP", "LDAP2", "LDAP3", "RDATE", "RSYNC", "TNS", "PGSQL",
  "POSTFIXPOLICY", "SIP", "LMTP", "GPS", "RADIUS", "MEMCACHE", "STRING",
  "PATH", "MAILADDR", "MAILFROM", "MAILREPLYTO", "MAILSUBJECT", "MAILBODY",
  "SERVICENAME", "STRINGNAME", "NUMBER", "PERCENT", "LOGLIMIT",
  "CLOSELIMIT", "DNSLIMIT", "KEEPALIVELIMIT", "REPLYLIMIT", "REQUESTLIMIT",
  "STARTLIMIT", "WAITLIMIT", "GRACEFULLIMIT", "CLEANUPLIMIT", "REAL",
  "CHECKPROC", "CHECKFILESYS", "CHECKFILE", "CHECKDIR", "CHECKHOST",
  "CHECKSYSTEM", "CHECKFIFO", "CHECKPROGRAM", "CHILDREN", "SYSTEM",
  "STATUS", "RESOURCE", "MEMORY", "TOTALMEMORY", "LOADAVG1", "LOADAVG5",
  "LOADAVG15", "SWAP", "MODE", "ACTIVE", "PASSIVE", "MANUAL", "CPU",
  "TOTALCPU", "CPUUSER", "CPUSYSTEM", "CPUWAIT", "GROUP", "REQUEST",
  "DEPENDS", "BASEDIR", "SLOT", "EVENTQUEUE", "SECRET", "HOSTHEADER",
  "UID", "GID", "MMONIT", "INSTANCE", "USERNAME", "PASSWORD", "TIMESTAMP",
  "CHANGED", "SECOND", "MINUTE", "HOUR", "DAY", "SSLAUTO", "SSLV2",
  "SSLV3", "TLSV1", "CERTMD5", "BYTE", "KILOBYTE", "MEGABYTE", "GIGABYTE",
  "INODE", "SPACE", "PERMISSION", "SIZE", "MATCH", "NOT", "IGNORE",
  "ACTION", "UPTIME", "EXEC", "UNMONITOR", "ICMP", "ICMPECHO", "NONEXIST",
  "EXIST", "INVALID", "DATA", "RECOVERED", "PASSED", "SUCCEEDED", "URL",
  "CONTENT", "PID", "PPID", "FSFLAG", "REGISTER", "CREDENTIALS",
  "URLOBJECT", "TARGET", "TIMESPEC", "MAXFORWARD", "FIPS", "NOTEQUAL",
  "EQUAL", "LESS", "GREATER", "'{'", "'}'", "':'", "'@'", "$accept",
  "cfgfile", "statement_list", "statement", "optproclist", "optproc",
  "optfilelist", "optfile", "optfilesyslist", "optfilesys", "optdirlist",
  "optdir", "opthostlist", "opthost", "optsystemlist", "optsystem",
  "optfifolist", "optfifo", "optstatuslist", "optstatus", "setalert",
  "setdaemon", "startdelay", "setexpectbuffer", "setinit", "setfips",
  "setlog", "seteventqueue", "setidfile", "setstatefile", "setpid",
  "setmmonits", "mmonitlist", "mmonit", "credentials", "setmailservers",
  "setmailformat", "sethttpd", "mailserverlist", "mailserver", "httpdlist",
  "httpdoption", "ssl", "optssllist", "optssl", "sslenable", "ssldisable",
  "signature", "sigenable", "sigdisable", "bindaddress", "pemfile",
  "clientpemfile", "allowselfcert", "allow", "$@1", "$@2", "$@3", "$@4",
  "allowuserlist", "allowuser", "readonly", "checkproc", "checkfile",
  "checkfilesys", "checkdir", "checkhost", "checksystem", "checkfifo",
  "checkprogram", "start", "stop", "restart", "argumentlist",
  "useroptionlist", "argument", "useroption", "username", "password",
  "hostname", "connection", "connectionunix", "icmp", "host", "port",
  "unixsocket", "type", "certmd5", "sslversion", "protocol",
  "sendexpectlist", "sendexpect", "target", "maxforward", "request",
  "hostheader", "secret", "apache_stat_list", "apache_stat", "exist",
  "pid", "ppid", "uptime", "icmpcount", "exectimeout", "programtimeout",
  "nettimeout", "retry", "actionrate", "urloption", "urloperator", "alert",
  "alertmail", "noalertmail", "eventoptionlist", "eventoption",
  "formatlist", "formatoptionlist", "formatoption", "every", "mode",
  "group", "depend", "dependlist", "dependant", "statusvalue",
  "resourceprocess", "resourceprocesslist", "resourceprocessopt",
  "resourcesystem", "resourcesystemlist", "resourcesystemopt",
  "resourcecpuproc", "resourcecpu", "resourcecpuid", "resourcemem",
  "resourceswap", "resourcechild", "resourceload", "resourceloadavg",
  "value", "timestamp", "operator", "time", "action", "action1", "action2",
  "rate1", "rate2", "recovery", "checksum", "hashtype", "inode", "space",
  "fsflag", "unit", "permission", "match", "matchflagnot", "size", "uid",
  "gid", "icmptype", "reminder", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   123,   125,    58,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   206,   207,   207,   208,   208,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   210,   210,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   212,   212,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   214,   214,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   216,   216,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   218,
     218,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   220,   220,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   222,   222,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     224,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   226,   226,   226,   227,   228,   228,   229,   230,
     231,   232,   232,   232,   233,   233,   233,   234,   235,   236,
     237,   238,   238,   239,   240,   240,   241,   242,   243,   244,
     244,   245,   245,   246,   246,   247,   247,   247,   247,   248,
     248,   249,   249,   250,   250,   250,   251,   251,   252,   252,
     253,   253,   254,   254,   255,   255,   256,   257,   258,   259,
     260,   260,   260,   260,   260,   260,   261,   260,   262,   260,
     263,   260,   264,   260,   260,   265,   265,   266,   267,   267,
     268,   268,   268,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   276,   277,   277,   278,   278,   279,   279,   280,
     280,   281,   281,   282,   282,   282,   282,   283,   283,   283,
     284,   284,   285,   285,   286,   286,   287,   288,   289,   289,
     290,   291,   292,   292,   292,   292,   293,   293,   294,   294,
     294,   294,   294,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   296,   296,   297,   297,   298,   298,   298,   299,   299,
     300,   300,   300,   301,   301,   302,   303,   303,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   306,
     307,   308,   309,   309,   310,   310,   311,   311,   312,   312,
     313,   313,   314,   314,   315,   315,   316,   316,   317,   317,
     317,   317,   318,   319,   320,   320,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   322,   322,
     323,   323,   324,   324,   324,   324,   325,   325,   325,   326,
     326,   326,   327,   328,   329,   329,   330,   331,   332,   333,
     333,   334,   334,   334,   334,   335,   336,   336,   337,   337,
     337,   337,   338,   338,   339,   340,   340,   340,   341,   341,
     341,   341,   342,   342,   343,   344,   345,   345,   345,   346,
     346,   347,   347,   348,   348,   348,   348,   348,   348,   349,
     349,   349,   349,   349,   350,   350,   350,   350,   350,   350,
     350,   351,   352,   353,   353,   353,   354,   354,   354,   355,
     355,   355,   355,   356,   356,   356,   357,   357,   357,   358,
     358,   359,   359,   360,   361,   361,   361,   361,   361,   362,
     363,   363,   363,   363,   364,   364,   365,   365,   366,   366,
     367,   367,   368,   369,   369,   369
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     7,     8,     4,     0,     3,     4,     2,
       2,     3,     3,     5,     4,     6,     4,     3,     3,     3,
       3,     2,     3,     4,     0,     2,     5,     5,     5,     1,
       2,     5,     7,     0,     2,     1,     1,     1,     1,     2,
       2,     0,     2,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       5,     4,     2,     3,     3,     3,     0,     4,     0,     5,
       0,     5,     0,     5,     2,     1,     2,     1,     0,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     4,
       5,     3,     4,     3,     4,     3,     4,     1,     2,     1,
       2,     1,     1,     2,     2,     2,     2,     0,     2,     2,
       0,     2,     0,     2,    12,    11,    11,    10,     0,     2,
       2,     2,     0,     2,     4,     2,     0,     2,     0,     1,
       1,     1,     1,     0,     3,     2,     2,     2,     2,     3,
       2,     2,     2,     2,     2,     4,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     2,
       1,     1,     2,     2,     2,     0,     2,     2,     0,     2,
       0,     3,     5,     0,     2,     2,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     7,     6,
       6,     9,     0,     2,     0,     3,     0,     3,     0,     3,
       0,     2,     7,     7,     0,     3,     1,     1,     3,     6,
       7,     1,     2,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     2,     1,     1,     1,     1,     3,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     1,     8,     6,     1,
       2,     1,     1,     1,     1,     6,     1,     2,     1,     1,
       1,     1,     4,     4,     4,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     3,     3,     1,     1,     1,     1,
       1,     9,     6,     0,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     0,     2,     3,     0,     2,     3,     0,
       6,     6,     6,     8,    10,     7,     0,     1,     1,     8,
       9,     9,     9,     6,     0,     1,     1,     1,     1,     8,
       7,     7,     4,     4,     0,     1,     9,     6,     8,     8,
       8,     8,     2,     0,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     6,     7,    17,    18,    19,     8,     9,
      15,    16,    14,    10,    11,    12,    13,    28,    46,    65,
      83,     0,   113,   124,   140,     0,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   388,
       0,     0,     0,     0,     0,   238,     0,     0,     1,     5,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    99,   101,   102,   103,   105,
     106,   104,   107,   108,   388,   361,   109,   110,   111,   112,
      25,    26,    27,   162,   161,   156,   257,   348,   179,     0,
     167,   168,   484,   169,   362,     0,     0,     0,   348,   170,
     174,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    37,
      38,    33,    34,    35,    36,    39,    40,    41,    42,    43,
      44,    45,   494,   494,    47,    48,    49,    50,    51,    53,
      55,    54,    62,    63,    64,    52,    59,    56,    61,    60,
      57,    58,     0,    66,    67,    68,    69,    70,    71,    73,
      72,    77,    78,    79,    80,    81,    82,    74,    75,    76,
       0,    84,    85,    86,    87,    88,    90,    92,    91,    96,
      97,    98,    89,    93,    94,    95,   268,     0,     0,   251,
     252,   344,   247,   344,   363,   344,     0,   397,   398,   399,
     400,   401,   402,   406,   403,   404,   100,     0,     0,   503,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   125,   126,   127,   128,   129,   131,   133,   132,   137,
     138,   139,   130,   134,   135,   136,     0,   141,   142,   143,
     144,   146,   145,   147,   148,   149,   150,   151,     0,     0,
     155,     0,     0,   260,     0,   180,   262,   183,   485,   486,
     487,   488,   158,   392,   393,   394,   395,     0,   390,   164,
     166,   278,   174,     0,   171,     0,     0,   368,   384,   367,
     383,   381,   386,   373,   375,   385,   378,   382,   366,   387,
     371,   374,   377,   376,   370,   369,   379,   380,   372,     0,
     364,     0,   152,   230,   231,   232,   233,   235,   234,   236,
     237,   239,   346,   268,   443,   443,   443,   436,   437,   438,
     443,   443,     0,   443,   463,   409,   411,   412,   413,   414,
     443,   476,   443,   476,   443,   495,     0,   495,     0,     0,
       0,   443,   443,     0,     0,     0,     0,     0,     0,   463,
       0,     0,     0,   344,   248,   249,   241,   344,   243,   344,
     245,   396,   405,     0,     0,   358,   443,   425,   426,   427,
     463,   416,   421,   443,   419,   420,   418,   443,   163,     0,
     257,   259,   258,     0,   278,     0,     0,   176,   178,   177,
     391,     0,   282,   279,   280,   281,   276,   172,   175,     0,
       0,   388,   365,   504,     0,   240,     0,   272,   448,   447,
     446,   445,   444,     0,     0,     0,     0,     0,   463,   463,
       0,     0,   410,     0,     0,   477,   478,     0,     0,     0,
       0,     0,   463,   463,     0,     0,     0,     0,   463,     0,
       0,   269,     0,   342,   354,     0,   272,     0,     0,     0,
     253,   255,   254,   256,   250,   242,   244,   246,     0,   388,
       0,   417,     0,     0,     0,   157,   260,   261,   276,   349,
     263,     0,     0,     0,     0,     0,     0,   184,   185,   191,
     191,   186,   200,   201,   187,   188,   165,     0,   173,   389,
     388,   503,   505,     0,   271,     0,   283,   434,   440,   439,
     484,   440,   484,     0,     0,     0,     0,   449,   464,     0,
       0,   440,   435,   463,   463,   463,   463,   463,   463,   449,
       0,     0,   463,   484,   463,   463,   493,   492,     0,   463,
     440,   484,   502,     0,   348,     0,   348,   270,   283,     0,
       0,   345,   388,   503,   440,   484,     0,     0,   463,   278,
     181,     0,     0,     0,   224,   212,     0,   206,   197,   203,
     199,   205,   196,   198,   202,   204,   190,   189,   277,   503,
     153,   347,   275,   273,   278,     0,     0,     0,   348,   310,
     311,   429,   428,   431,   430,   422,   423,     0,     0,   450,
     451,   452,   453,   463,   465,   458,   459,   454,   457,     0,
     460,   461,   469,     0,     0,     0,     0,     0,     0,     0,
     463,     0,     0,     0,   463,     0,     0,     0,   463,     0,
     463,   463,   343,   463,   357,   356,     0,   350,   348,     0,
     469,   503,   359,   433,   432,   469,   424,     0,   276,   213,
     214,   215,     0,     0,   228,     0,     0,   209,   192,   193,
     194,   195,   154,   276,   313,   314,   285,   320,     0,   288,
     300,   299,   290,   291,   296,   297,   294,   286,   301,   287,
     292,   293,   302,   303,   304,   305,   298,   315,   306,   307,
       0,   309,   350,   312,   339,   340,     0,   455,     0,   408,
       0,     0,     0,     0,     0,   463,     0,     0,   442,   497,
       0,     0,     0,     0,   483,     0,     0,     0,     0,     0,
     355,     0,   463,   350,   353,   352,   338,   360,   415,     0,
     182,     0,     0,     0,   228,   227,   217,   225,   229,   211,
     207,   208,   274,     0,   289,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   284,   326,     0,   318,     0,
     308,   463,     0,   456,     0,   469,   469,   469,   469,   469,
       0,   469,     0,   475,     0,   491,   490,     0,   469,     0,
       0,     0,   351,     0,   463,   469,   219,   221,   223,   210,
     226,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,   316,     0,   295,   325,     0,   469,
     466,   466,   466,   498,   499,   500,   501,   489,     0,   473,
     469,   469,   469,   479,   469,   469,   469,     0,     0,   407,
       0,     0,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   327,   319,     0,   341,     0,     0,     0,
       0,   469,   441,   496,   480,   482,   481,   267,   469,     0,
     323,   324,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   469,   467,     0,     0,     0,     0,   474,   265,
     469,   322,   266,   468,   462,   470,   471,   472,   264
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    60,   125,    61,   144,    62,   163,
      63,   181,    74,    75,    90,   221,    91,   231,    92,   247,
      13,    14,   260,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   109,   110,   284,    24,    25,    26,    97,    98,
     398,   487,   488,   576,   658,   489,   490,   491,   492,   493,
     494,   659,   660,   661,   495,   653,   731,   732,   733,   736,
     737,   739,    27,    28,    29,    30,    31,    32,    33,    34,
      76,    77,    78,   201,   363,   202,   365,   263,   394,   397,
      79,   130,    80,   357,   456,   417,   506,   498,   406,   588,
     589,   590,   758,   806,   744,   832,   760,   755,   756,    81,
     132,   133,   134,   544,   366,   415,   266,   722,    82,   546,
     636,    83,    84,    85,   309,   310,   114,   277,   278,    86,
      87,    88,    89,   214,   215,   257,   141,   334,   335,   230,
     380,   381,   336,   382,   383,   337,   385,   338,   339,   340,
     510,   155,   423,   603,   611,   612,   885,   433,   848,   699,
     156,   440,   174,   175,   176,   272,   157,   158,   346,   159,
     160,   161,   453,   312
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -651
static const yytype_int16 yypact[] =
{
     479,    53,   -44,   -39,   -14,   -10,    -3,    38,    43,    49,
     100,   479,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,   501,  -651,  -651,  -651,    42,     8,   111,   166,  -651,
     156,   159,   158,   204,   188,    94,    25,   107,  -651,   -35,
      31,   269,   307,   310,   360,  -651,   351,   353,  -651,  -651,
     505,    74,   624,   670,    23,   174,   174,   316,   174,   -45,
     202,   229,   304,   341,   501,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,   -34,  -651,  -651,  -651,  -651,  -651,
     347,   670,   684,   403,  -651,   399,    -8,   -12,  -651,   356,
    -651,  -651,   160,  -651,  -651,   368,   361,   383,   416,   107,
     298,   292,   293,   526,   455,   408,   417,   266,   434,   436,
     439,   449,   453,   174,   135,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,    56,   334,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,   136,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
      52,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,    19,   488,   358,  -651,
    -651,   264,  -651,   264,  -651,   264,   512,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,   341,  -651,  -651,   349,   526,   455,
     632,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,    -9,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,   466,   532,
    -651,   461,    81,   410,   467,  -651,   528,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,    36,  -651,   432,
    -651,   352,   298,   380,  -651,   368,   526,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,   193,
    -651,   481,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,     9,     6,    37,    37,    37,  -651,  -651,  -651,
      37,    37,   176,    37,   615,  -651,  -651,  -651,  -651,  -651,
      37,     2,    37,    29,    37,   358,   409,  -651,   411,   -56,
     393,    37,    37,   433,   498,   542,   395,   555,   508,   510,
     517,   154,   186,   -24,  -651,  -651,  -651,   -24,  -651,   -24,
    -651,  -651,  -651,   526,   345,  -651,    37,  -651,  -651,  -651,
     649,  -651,  -651,    37,  -651,  -651,  -651,    37,  -651,   518,
     460,  -651,  -651,   533,   352,   477,   551,  -651,   597,  -651,
    -651,   523,  -651,  -651,  -651,  -651,   482,  -651,  -651,    67,
     429,   588,  -651,   610,   553,  -651,   562,   611,  -651,  -651,
    -651,  -651,  -651,   561,    -1,    54,   563,   581,   510,   510,
     582,    10,  -651,   675,    55,  -651,  -651,   189,   220,   584,
     627,   595,   510,   510,   634,   599,   290,   296,   510,   600,
     120,  -651,   520,   666,   519,   607,   611,   676,   712,   572,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,   480,   588,
     147,  -651,   721,   630,   635,  -651,   410,  -651,   482,  -651,
    -651,    21,   646,    48,    68,   377,   400,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,   655,  -651,  -651,
     588,   455,  -651,   596,  -651,   375,   123,  -651,   652,  -651,
     160,   653,   160,   662,   664,   759,   760,   414,  -651,   718,
     279,  -651,  -651,   510,   510,   510,   510,   510,     5,   414,
     764,   765,   510,   160,   510,   510,  -651,  -651,   772,   335,
     680,   160,  -651,   682,   416,   258,   416,  -651,   123,   775,
     279,  -651,   588,   455,   683,   160,   279,   692,   510,   352,
    -651,   693,   702,   703,   589,   720,   727,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,   318,   318,  -651,   455,
    -651,  -651,  -651,  -651,   352,   731,   732,   814,   416,   431,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,   279,   279,  -651,
    -651,  -651,  -651,   510,  -651,  -651,  -651,  -651,  -651,   174,
    -651,  -651,   810,   817,   822,   823,   827,   852,   770,   854,
     510,   279,   279,   855,   510,   856,   857,   279,   510,   858,
     510,   510,  -651,   510,  -651,  -651,   777,   807,   416,   276,
     810,   455,  -651,  -651,  -651,   810,  -651,   864,   482,   782,
     784,   815,   816,   818,   853,   813,   819,  -651,  -651,  -651,
    -651,  -651,  -651,   482,  -651,  -651,  -651,   767,   748,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,   713,  -651,  -651,
     766,  -651,   807,  -651,  -651,  -651,   905,   127,   908,  -651,
     279,   279,   279,   279,   279,   510,   279,   907,  -651,  -651,
     279,   909,   279,   279,  -651,   910,   279,   911,   912,   913,
    -651,   824,   510,   807,  -651,  -651,  -651,  -651,  -651,   279,
    -651,   818,   818,   818,   853,  -651,   818,  -651,  -651,  -651,
    -651,  -651,  -651,   830,  -651,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,   914,  -651,   241,   717,   834,
    -651,   510,   279,   322,   245,   810,   810,   810,   810,   810,
     918,   810,   279,  -651,   279,  -651,  -651,   279,   810,   279,
     279,   279,  -651,   919,   510,   810,   818,   818,   818,  -651,
    -651,   -25,   828,   829,   831,   832,   833,   835,   836,   837,
     838,   839,   748,  -651,  -651,   840,  -651,  -651,   922,   810,
     841,   841,   841,  -651,  -651,  -651,  -651,  -651,   279,  -651,
     810,   810,   810,  -651,   810,   810,   810,   279,   926,  -651,
     851,   859,  -651,   842,   843,   844,   845,   846,   847,   848,
     850,   860,   861,  -651,  -651,   279,  -651,    20,   944,   945,
     946,   810,  -651,  -651,  -651,  -651,  -651,  -651,   810,   279,
     808,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,   810,  -651,   920,   279,   279,   279,  -651,  -651,
     810,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -651,  -651,  -651,   942,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,   880,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,   862,   674,  -651,  -651,  -651,  -651,   863,
    -651,  -651,  -651,   471,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -230,
    -522,   223,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
     628,   726,   734,   -66,  -199,  -198,  -352,   573,   486,  -651,
     904,  -651,  -651,  -651,  -651,  -651,   509,  -466,  -378,   418,
    -651,   378,  -651,  -651,  -651,   108,  -651,  -651,   167,   574,
    -651,  -651,  -651,  -651,  -176,  -651,  -107,  -650,   739,  -651,
    -651,   743,   969,  -651,  -185,  -256,   -76,   687,  -263,   750,
     328,   776,   783,  -651,   761,  -651,  -651,  -651,   639,  -651,
    -651,   594,  -651,  -651,  -651,  -207,  -651,  -651,  -196,  -651,
    -149,    -5,  -305,   447,  -360,  -482,  -399,  -349,  -329,  -351,
    -651,   636,  -651,  -651,  -651,  -184,   178,  -651,   849,  -651,
     242,   249,  -651,  -210
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -223
static const yytype_int16 yytable[] =
{
     203,   281,   205,   364,   367,   364,   369,   364,   219,   375,
     458,   464,   560,   384,   400,   464,   478,   464,   111,   111,
     424,   425,   435,   436,   386,   426,   427,   368,   430,   370,
     196,   472,   360,   374,   830,   434,   261,   441,   618,   445,
     561,   562,   761,   563,   264,   518,   449,   450,   354,   435,
     436,    50,   206,   412,    93,   873,    51,   322,   192,   349,
     416,   354,    35,   341,    36,   414,    37,    38,   640,   115,
      39,   470,   116,   784,   645,   568,    96,   142,   473,   515,
     516,    52,   474,    40,    41,    53,   242,    42,   197,   437,
     438,    43,    54,   530,   531,   570,   508,   199,   200,   538,
      58,   410,   431,   569,    44,    95,    45,   519,   509,   564,
     565,   387,   439,    65,    66,   694,   695,   874,   412,   831,
     197,   361,   362,   571,   364,    44,    67,   273,   274,   275,
     276,    94,    68,    55,    69,    70,   112,   217,    56,   708,
     709,   262,   323,   349,    57,   714,   400,   437,   438,   197,
     207,   511,   521,   197,   412,   585,   586,   725,   273,   274,
     275,   276,   198,   509,   509,   106,   107,   113,   218,   391,
     439,   392,   587,   384,   613,   614,   615,   616,   617,   619,
     442,   648,   730,   623,   386,   625,   626,   465,   468,   418,
     629,   466,   356,   467,   198,    46,   355,   742,   443,    96,
      47,   117,    71,   342,   353,   356,   663,   342,   343,   647,
      99,    72,   412,    73,   790,   199,   200,   540,   765,   766,
     767,   768,   769,   198,   771,   344,   566,   345,   773,   509,
     775,   776,   197,   197,   778,   419,   420,   421,   422,   399,
     177,   193,   460,   287,   554,   100,   143,   785,   101,   288,
      48,   461,   289,   324,   696,   102,   509,   325,   326,   327,
     328,   329,   199,   200,   790,   790,   790,   330,   331,   243,
     499,   707,   361,   362,   462,   711,   512,   523,   104,   715,
     809,   717,   718,   463,   719,   522,   524,   332,   350,   726,
     820,   580,   821,   103,   728,   822,   105,   824,   825,   826,
     108,   541,   351,   352,   178,   194,   198,   198,   525,   333,
     118,   179,   195,   290,   291,   605,   606,   526,   605,   606,
     360,   555,   268,   269,   270,   271,   592,   607,   594,   803,
     607,   804,   724,   244,   608,   501,   851,   608,   292,   293,
     245,   294,   655,   642,   295,   858,   656,   657,   119,   624,
     220,   120,   199,   200,   315,   316,   770,   631,   209,   210,
     211,   296,   297,   872,   428,   429,   298,   299,   300,   662,
     301,   644,   302,   783,   303,   304,   121,   880,   534,   535,
     305,   306,   307,   308,   536,   537,    65,    66,   138,   152,
     171,   189,   122,   553,   123,   287,   411,   208,    44,    67,
     212,   288,   572,   573,   289,    68,   204,    69,    70,   361,
     362,   464,   808,   258,   813,   814,   815,   816,   817,   239,
     819,   582,   583,   584,   579,   574,   575,   823,   810,   811,
     812,   727,   431,   628,   829,   828,   213,   633,   259,   637,
     792,   793,   794,   795,   796,   797,   798,   799,   800,   801,
     279,   609,   610,   267,   609,   610,   634,   635,   846,   273,
     274,   275,   276,   585,   586,   290,   291,   361,   362,   852,
     853,   854,   264,   855,   856,   857,   641,   886,   887,   287,
     280,   692,   849,   850,    72,   288,    73,     1,   289,   283,
     292,   293,   311,   294,   285,   286,   295,   313,   763,   364,
     878,   786,   787,   788,    64,   347,   314,   879,   124,   402,
     403,   404,   405,   296,   297,   884,   884,   884,   298,   299,
     300,   882,   301,   317,   302,   318,   303,   304,   319,   888,
     287,   723,   305,   306,   307,   308,   288,   320,   359,   289,
      65,    66,   321,   697,    65,    66,   358,   371,   469,   290,
     291,   373,    44,    67,   388,   389,    44,    67,   390,    68,
     393,    69,    70,    68,   395,    69,    70,   599,   600,   601,
     602,   396,   408,   401,   292,   293,   287,   294,   413,   446,
     295,   447,   288,   448,   442,   289,   451,   452,   454,     2,
       3,     4,     5,     6,     7,     8,     9,   296,   297,   455,
     290,   291,   298,   299,   300,   457,   301,   431,   302,   262,
     303,   304,   481,   482,   459,   475,   305,   306,   307,   308,
     496,   477,   483,   484,   485,   292,   293,   162,   294,    71,
     479,   295,   500,    71,   131,   148,   167,   185,    72,   480,
      73,   111,    72,   497,    73,   502,   290,   291,   296,   297,
     503,   504,   486,   298,   299,   300,   505,   301,   507,   302,
     513,   303,   304,    65,    66,   235,   251,   305,   306,   307,
     308,   292,   293,   180,   294,    44,    67,   295,   514,   517,
     520,   527,    68,   552,    69,    70,   528,   246,   126,   145,
     164,   182,   529,   532,   296,   297,   533,   539,   542,   298,
     299,   300,   543,   301,   547,   302,   545,   303,   304,    65,
      66,   549,   431,   305,   306,   307,   308,   550,   222,   232,
     248,    44,    67,    65,    66,   551,   556,   557,    68,   197,
      69,    70,   558,   324,   567,    44,    67,   325,   326,   327,
     328,   329,    68,   578,    69,    70,   431,   330,   331,   581,
     591,   593,    71,   604,   325,   326,   327,   328,   329,   376,
     595,    72,   596,    73,   597,   598,   377,   378,   379,   621,
     622,   325,   326,   327,   328,   329,   376,   627,   630,   632,
     639,   643,   649,   377,   378,   379,   127,   146,   165,   183,
     646,   650,   651,   652,   128,   147,   166,   184,    71,   135,
     149,   168,   186,   136,   150,   169,   187,    72,  -216,    73,
     137,   151,   170,   188,   698,   654,   223,   233,   249,   664,
     665,    72,   700,    73,   224,   234,   250,   701,   702,   225,
     236,   252,   703,   226,   237,   253,   139,   153,   172,   190,
     227,   238,   254,   140,   154,   173,   191,   745,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   704,   705,   706,
     710,   712,   713,   716,   721,   720,   228,   240,   255,   729,
    -218,   738,  -220,   229,   241,   256,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,   740,  -222,   734,   743,   735,   757,   741,   759,
     762,   764,   772,   805,   774,   777,   779,   780,   781,   791,
     802,   782,   807,   818,   827,   833,   834,   845,   835,   836,
     837,   859,   838,   839,   840,   841,   842,   844,   847,   860,
     862,   863,   864,   865,   866,   867,   868,   861,   869,   875,
     876,   877,   831,    59,   216,   883,   407,   789,   870,   871,
     265,   577,   559,   476,   129,   548,   638,   693,   881,   843,
      49,   282,   409,   432,   471,   372,   620,     0,     0,   444,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   348
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-651))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      66,   108,    68,   201,   203,   203,   205,   205,    84,   219,
     359,   363,   478,   220,   277,   367,   394,   369,    53,    53,
     325,   326,    20,    21,   220,   330,   331,   203,   333,   205,
       7,   380,    56,   218,    59,   340,    44,   342,    33,   344,
      19,    20,   692,    22,    56,    35,   351,   352,    42,    20,
      21,    95,    97,   309,    12,    35,    95,   123,    63,     7,
      54,    42,     9,     7,    11,    56,    13,    14,   550,    38,
      17,   376,    41,   723,   556,    27,    88,     3,   383,   428,
     429,    95,   387,    30,    31,    95,    91,    34,    97,   145,
     146,    38,    95,   442,   443,    27,    97,    88,    89,   448,
       0,   286,    97,    55,    51,    97,    53,    97,   109,    88,
      89,   120,   168,    39,    40,   597,   598,    97,   374,   144,
      97,   145,   146,    55,   322,    51,    52,    91,    92,    93,
      94,    89,    58,    95,    60,    61,   171,   171,    95,   621,
     622,   149,     7,     7,    95,   627,   409,   145,   146,    97,
     195,    97,    97,    97,   410,    32,    33,   639,    91,    92,
      93,    94,   171,   109,   109,   140,   141,   202,   202,    88,
     168,    90,    49,   380,   523,   524,   525,   526,   527,   528,
     151,   559,   648,   532,   380,   534,   535,   363,   373,   152,
     539,   367,   186,   369,   171,   142,   177,   663,   169,    88,
     147,   170,   128,   151,   152,   186,   584,   151,   152,   558,
      44,   137,   468,   139,   736,    88,    89,    97,   700,   701,
     702,   703,   704,   171,   706,   169,   205,   171,   710,   109,
     712,   713,    97,    97,   716,   198,   199,   200,   201,   203,
      62,    63,    88,    50,    97,    89,   172,   729,    89,    56,
     197,    97,    59,   118,   603,    97,   109,   122,   123,   124,
     125,   126,    88,    89,   786,   787,   788,   132,   133,    91,
     203,   620,   145,   146,    88,   624,   425,    88,    90,   628,
     762,   630,   631,    97,   633,   434,    97,   152,   152,   640,
     772,   501,   774,    89,   645,   777,   202,   779,   780,   781,
     193,   450,   166,   167,    62,    63,   171,   171,    88,   174,
      41,    62,    63,   120,   121,    39,    40,    97,    39,    40,
      56,   470,   162,   163,   164,   165,   510,    51,   512,    88,
      51,    90,    56,    91,    58,   411,   818,    58,   145,   146,
      91,   148,    24,   553,   151,   827,    28,    29,    41,   533,
       3,    41,    88,    89,    88,    89,   705,   541,   129,   130,
     131,   168,   169,   845,   188,   189,   173,   174,   175,   579,
     177,   555,   179,   722,   181,   182,    16,   859,    88,    89,
     187,   188,   189,   190,    88,    89,    39,    40,    60,    61,
      62,    63,    41,   469,    41,    50,   203,   195,    51,    52,
      96,    56,    25,    26,    59,    58,    90,    60,    61,   145,
     146,   763,   761,    10,   765,   766,   767,   768,   769,    91,
     771,    46,    47,    48,   500,    25,    26,   778,   183,   184,
     185,   641,    97,    98,   785,   784,    95,   544,    39,   546,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
      89,   175,   176,    97,   175,   176,   198,   199,   809,    91,
      92,    93,    94,    32,    33,   120,   121,   145,   146,   820,
     821,   822,    56,   824,   825,   826,   552,   876,   877,    50,
      97,   588,   811,   812,   137,    56,   139,     8,    59,   191,
     145,   146,    37,   148,   202,   202,   151,    89,   697,   697,
     851,   731,   732,   733,     3,   171,    89,   858,     3,   157,
     158,   159,   160,   168,   169,   875,   876,   877,   173,   174,
     175,   872,   177,    89,   179,    89,   181,   182,    89,   880,
      50,   638,   187,   188,   189,   190,    56,    88,   180,    59,
      39,    40,    89,   609,    39,    40,    58,    35,   203,   120,
     121,   202,    51,    52,    88,    23,    51,    52,    97,    58,
     150,    60,    61,    58,    97,    60,    61,   153,   154,   155,
     156,    43,   192,   141,   145,   146,    50,   148,    97,   170,
     151,   170,    56,   190,   151,    59,    88,    45,   193,   110,
     111,   112,   113,   114,   115,   116,   117,   168,   169,    44,
     120,   121,   173,   174,   175,    97,   177,    97,   179,   149,
     181,   182,    15,    16,    97,    97,   187,   188,   189,   190,
      97,    88,    25,    26,    27,   145,   146,     3,   148,   128,
     153,   151,   203,   128,    60,    61,    62,    63,   137,    88,
     139,    53,   137,   161,   139,    35,   120,   121,   168,   169,
      97,    89,    55,   173,   174,   175,    45,   177,    97,   179,
      97,   181,   182,    39,    40,    91,    92,   187,   188,   189,
     190,   145,   146,     3,   148,    51,    52,   151,    97,    97,
       5,    97,    58,   203,    60,    61,    59,     3,    60,    61,
      62,    63,    97,    59,   168,   169,    97,    97,   178,   173,
     174,   175,    36,   177,    97,   179,   187,   181,   182,    39,
      40,    35,    97,   187,   188,   189,   190,     5,    90,    91,
      92,    51,    52,    39,    40,   153,     5,    97,    58,    97,
      60,    61,    97,   118,    88,    51,    52,   122,   123,   124,
     125,   126,    58,    88,    60,    61,    97,   132,   133,   153,
      98,    98,   128,    35,   122,   123,   124,   125,   126,   127,
      98,   137,    98,   139,     5,     5,   134,   135,   136,     5,
       5,   122,   123,   124,   125,   126,   127,     5,    98,    97,
       5,    98,    89,   134,   135,   136,    60,    61,    62,    63,
      98,    89,    89,   204,    60,    61,    62,    63,   128,    60,
      61,    62,    63,    60,    61,    62,    63,   137,    88,   139,
      60,    61,    62,    63,     4,    88,    90,    91,    92,    88,
      88,   137,     5,   139,    90,    91,    92,     5,     5,    90,
      91,    92,     5,    90,    91,    92,    60,    61,    62,    63,
      90,    91,    92,    60,    61,    62,    63,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     5,    88,     5,
       5,     5,     5,     5,    57,    88,    90,    91,    92,     5,
      88,    18,    88,    90,    91,    92,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    89,    88,    88,   138,    88,   194,    89,   143,
       5,     3,     5,   196,     5,     5,     5,     5,     5,    89,
       6,    97,    88,     5,     5,    97,    97,     5,    97,    97,
      97,     5,    97,    97,    97,    97,    97,    97,    97,    88,
      98,    98,    98,    98,    98,    98,    98,    88,    98,     5,
       5,     5,   144,    11,    74,    35,   282,   734,    98,    98,
      97,   490,   476,   390,    60,   456,   548,   589,   860,   802,
       1,   109,   285,   334,   380,   214,   529,    -1,    -1,   343,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     8,   110,   111,   112,   113,   114,   115,   116,   117,
     207,   208,   209,   226,   227,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   241,   242,   243,   268,   269,   270,
     271,   272,   273,   274,   275,     9,    11,    13,    14,    17,
      30,    31,    34,    38,    51,    53,   142,   147,   197,   318,
      95,    95,    95,    95,    95,    95,    95,    95,     0,   209,
     210,   212,   214,   216,     3,    39,    40,    52,    58,    60,
      61,   128,   137,   139,   218,   219,   276,   277,   278,   286,
     288,   305,   314,   317,   318,   319,   325,   326,   327,   328,
     220,   222,   224,    12,    89,    97,    88,   244,   245,    44,
      89,    89,    97,    89,    90,   202,   140,   141,   193,   238,
     239,    53,   171,   202,   322,    38,    41,   170,    41,    41,
      41,    16,    41,    41,     3,   211,   276,   277,   278,   286,
     287,   305,   306,   307,   308,   314,   317,   325,   326,   327,
     328,   332,     3,   172,   213,   276,   277,   278,   305,   314,
     317,   325,   326,   327,   328,   347,   356,   362,   363,   365,
     366,   367,     3,   215,   276,   277,   278,   305,   314,   317,
     325,   326,   327,   328,   358,   359,   360,   362,   366,   367,
       3,   217,   276,   277,   278,   305,   314,   317,   325,   326,
     327,   328,   347,   362,   366,   367,     7,    97,   171,    88,
      89,   279,   281,   279,    90,   279,    97,   195,   195,   129,
     130,   131,    96,    95,   329,   330,   219,   171,   202,   322,
       3,   221,   276,   277,   278,   314,   317,   325,   327,   328,
     335,   223,   276,   277,   278,   305,   314,   317,   325,   326,
     327,   328,   347,   362,   366,   367,     3,   225,   276,   277,
     278,   305,   314,   317,   325,   327,   328,   331,    10,    39,
     228,    44,   149,   283,    56,   245,   312,    97,   162,   163,
     164,   165,   361,    91,    92,    93,    94,   323,   324,    89,
      97,   312,   239,   191,   240,   202,   202,    50,    56,    59,
     120,   121,   145,   146,   148,   151,   168,   169,   173,   174,
     175,   177,   179,   181,   182,   187,   188,   189,   190,   320,
     321,    37,   369,    89,    89,    88,    89,    89,    89,    89,
      88,    89,   279,     7,   118,   122,   123,   124,   125,   126,
     132,   133,   152,   174,   333,   334,   338,   341,   343,   344,
     345,     7,   151,   152,   169,   171,   364,   171,   364,     7,
     152,   166,   167,   152,    42,   177,   186,   289,    58,   180,
      56,   145,   146,   280,   281,   282,   310,   280,   310,   280,
     310,    35,   330,   202,   320,   369,   127,   134,   135,   136,
     336,   337,   339,   340,   341,   342,   344,   120,    88,    23,
      97,    88,    90,   150,   284,    97,    43,   285,   246,   203,
     324,   141,   157,   158,   159,   160,   294,   240,   192,   323,
     320,   203,   321,    97,    56,   311,    54,   291,   152,   198,
     199,   200,   201,   348,   348,   348,   348,   348,   188,   189,
     348,    97,   334,   353,   348,    20,    21,   145,   146,   168,
     357,   348,   151,   169,   357,   348,   170,   170,   190,   348,
     348,    88,    45,   368,   193,    44,   290,    97,   353,    97,
      88,    97,    88,    97,   282,   310,   310,   310,   320,   203,
     348,   337,   353,   348,   348,    97,   283,    88,   294,   153,
      88,    15,    16,    25,    26,    27,    55,   247,   248,   251,
     252,   253,   254,   255,   256,   260,    97,   161,   293,   203,
     203,   322,    35,    97,    89,    45,   292,    97,    97,   109,
     346,    97,   346,    97,    97,   353,   353,    97,    35,    97,
       5,    97,   346,    88,    97,    88,    97,    97,    59,    97,
     353,   353,    59,    97,    88,    89,    88,    89,   353,    97,
      97,   346,   178,    36,   309,   187,   315,    97,   292,    35,
       5,   153,   203,   322,    97,   346,     5,    97,    97,   284,
     293,    19,    20,    22,    88,    89,   205,    88,    27,    55,
      27,    55,    25,    26,    25,    26,   249,   249,    88,   322,
     369,   153,    46,    47,    48,    32,    33,    49,   295,   296,
     297,    98,   361,    98,   361,    98,    98,     5,     5,   153,
     154,   155,   156,   349,    35,    39,    40,    51,    58,   175,
     176,   350,   351,   353,   353,   353,   353,   353,    33,   353,
     349,     5,     5,   353,   361,   353,   353,     5,    98,   353,
      98,   361,    97,   312,   198,   199,   316,   312,   295,     5,
     351,   322,   369,    98,   361,   351,    98,   353,   294,    89,
      89,    89,   204,   261,    88,    24,    28,    29,   250,   257,
     258,   259,   369,   294,    88,    88,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   312,   297,   351,   351,   353,   279,     4,   355,
       5,     5,     5,     5,     5,    88,     5,   353,   351,   351,
       5,   353,     5,     5,   351,   353,     5,   353,   353,   353,
      88,    57,   313,   312,    56,   351,   355,   369,   355,     5,
     293,   262,   263,   264,    88,    88,   265,   266,    18,   267,
      89,    89,   293,   138,   300,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   303,   304,   194,   298,   143,
     302,   313,     5,   280,     3,   351,   351,   351,   351,   351,
     353,   351,     5,   351,     5,   351,   351,     5,   351,     5,
       5,     5,    97,   353,   313,   351,   265,   265,   265,   267,
     266,    89,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,     6,    88,    90,   196,   299,    88,   353,   351,
     183,   184,   185,   355,   355,   355,   355,   355,     5,   355,
     351,   351,   351,   355,   351,   351,   351,     5,   353,   355,
      59,   144,   301,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,   304,    97,     5,   355,    97,   354,   354,
     354,   351,   355,   355,   355,   355,   355,   355,   351,     5,
      88,    88,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,   351,    35,    97,     5,     5,     5,   355,   355,
     351,   301,   355,    35,   350,   352,   352,   352,   355
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 152:

/* Line 1806 of yacc.c  */
#line 493 "src/p.y"
    {
                   mailset.events = Event_All;
                    addmail((yyvsp[(2) - (4)].string), &mailset, &Run.maillist);
                  }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 497 "src/p.y"
    {
                    addmail((yyvsp[(2) - (7)].string), &mailset, &Run.maillist);
                  }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 500 "src/p.y"
    {
                   mailset.events = ~mailset.events;
                   addmail((yyvsp[(2) - (8)].string), &mailset, &Run.maillist);
                  }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 506 "src/p.y"
    {
                    if (!Run.isdaemon || ihp.daemon) {
                      ihp.daemon     = TRUE;
                      Run.isdaemon   = TRUE;
                      Run.polltime   = (yyvsp[(3) - (4)].number);
                      Run.startdelay = (yyvsp[(4) - (4)].number);
                    }
                  }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 516 "src/p.y"
    { (yyval.number) = START_DELAY; }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 517 "src/p.y"
    { (yyval.number) = (yyvsp[(3) - (3)].number); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 520 "src/p.y"
    {
                    Run.expectbuffer = (yyvsp[(3) - (4)].number) * (yyvsp[(4) - (4)].number);
                  }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 525 "src/p.y"
    {
                    Run.init = TRUE;
                  }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 530 "src/p.y"
    {
                  #ifdef OPENSSL_FIPS
                    Run.fipsEnabled = TRUE;
                  #endif
                  }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 537 "src/p.y"
    {
                   if (!Run.logfile || ihp.logfile) {
                     ihp.logfile = TRUE;
                     setlogfile((yyvsp[(3) - (3)].string));
                     Run.use_syslog = FALSE;
                     Run.dolog =TRUE;
                   }
                  }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 545 "src/p.y"
    {
                    setsyslog(NULL);
                  }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 548 "src/p.y"
    {
                    setsyslog((yyvsp[(5) - (5)].string)); FREE((yyvsp[(5) - (5)].string));
                  }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 553 "src/p.y"
    {
                    Run.eventlist_dir = (yyvsp[(4) - (4)].string);
                  }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 556 "src/p.y"
    {
                    Run.eventlist_dir = (yyvsp[(4) - (6)].string);
                    Run.eventlist_slots = (yyvsp[(6) - (6)].number);
                  }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 560 "src/p.y"
    {
                    Run.eventlist_dir = Str_dup(MYEVENTLISTBASE);
                    Run.eventlist_slots = (yyvsp[(4) - (4)].number);
                  }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 566 "src/p.y"
    {
                    Run.idfile = (yyvsp[(3) - (3)].string);
                  }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 571 "src/p.y"
    {
                    Run.statefile = (yyvsp[(3) - (3)].string);
                  }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 576 "src/p.y"
    {
                   if (!Run.pidfile || ihp.pidfile) {
                     ihp.pidfile = TRUE;
                     setpidfile((yyvsp[(3) - (3)].string));
                   }
                 }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 591 "src/p.y"
    {
                    check_hostname(((yyvsp[(1) - (4)].url))->hostname);
                    addmmonit((yyvsp[(1) - (4)].url), (yyvsp[(2) - (4)].number), (yyvsp[(3) - (4)].number), (yyvsp[(4) - (4)].string));
                  }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 598 "src/p.y"
    {
                    Run.dommonitcredentials = FALSE;
                  }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 603 "src/p.y"
    {
                   if (((yyvsp[(4) - (5)].number)) > SMTP_TIMEOUT)
                     Run.mailserver_timeout = (yyvsp[(4) - (5)].number);
                   Run.mail_hostname = (yyvsp[(5) - (5)].string);
                  }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 610 "src/p.y"
    {
                   Run.MailFormat.from    = mailset.from    ?  mailset.from    : Str_dup(ALERT_FROM);
                   Run.MailFormat.replyto = mailset.replyto ?  mailset.replyto : NULL;
                   Run.MailFormat.subject = mailset.subject ?  mailset.subject : Str_dup(ALERT_SUBJECT);
                   Run.MailFormat.message = mailset.message ?  mailset.message : Str_dup(ALERT_MESSAGE);
                   reset_mailset();
                 }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 619 "src/p.y"
    {
                   Run.dohttpd = TRUE;
                   Run.httpdport = (yyvsp[(4) - (5)].number);
                 }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 629 "src/p.y"
    {
                    /* Restore the current text overriden by lookahead */
                    FREE(argyytext);
                    argyytext = Str_dup((yyvsp[(1) - (5)].string));

                    check_hostname((yyvsp[(1) - (5)].string));
                    mailserverset.host = (yyvsp[(1) - (5)].string);
                    mailserverset.username = (yyvsp[(2) - (5)].string);
                    mailserverset.password = (yyvsp[(3) - (5)].string);
                    mailserverset.ssl.version = (yyvsp[(4) - (5)].number);
                    if (mailserverset.ssl.version != SSL_VERSION_NONE) {
                      mailserverset.ssl.use_ssl = TRUE;
                      if (mailserverset.ssl.version == SSL_VERSION_SSLV2 ||
                         mailserverset.ssl.version == SSL_VERSION_SSLV3)
                         mailserverset.port = PORT_SMTPS;
                      mailserverset.ssl.certmd5 = (yyvsp[(5) - (5)].string);
                    }
                    addmailserver(&mailserverset);
                  }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 648 "src/p.y"
    {
                    /* Restore the current text overriden by lookahead */
                    FREE(argyytext);
                    argyytext = Str_dup((yyvsp[(1) - (7)].string));

                    check_hostname((yyvsp[(1) - (7)].string));
                    mailserverset.host = (yyvsp[(1) - (7)].string);
                    mailserverset.port = (yyvsp[(3) - (7)].number);
                    mailserverset.username = (yyvsp[(4) - (7)].string);
                    mailserverset.password = (yyvsp[(5) - (7)].string);
                    mailserverset.ssl.version = (yyvsp[(6) - (7)].number);
                    if (mailserverset.ssl.version != SSL_VERSION_NONE) {
                      mailserverset.ssl.use_ssl = TRUE;
                      mailserverset.ssl.certmd5 = (yyvsp[(7) - (7)].string);
                    }
                    addmailserver(&mailserverset);
                  }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 677 "src/p.y"
    {
                    Run.httpdssl = FALSE;
                  }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 680 "src/p.y"
    {
                    Run.httpdssl = TRUE;
                    if (! have_ssl())
                      yyerror("SSL is not supported");
                    else if (! Run.httpsslpem)
                      yyerror("SSL server PEM file is required (pemfile option)");
                    else if (! file_checkStat(Run.httpsslpem, "SSL server PEM file", S_IRWXU))
                      yyerror("SSL server PEM file permissions check failed");
                  }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 708 "src/p.y"
    { Run.httpdsig = TRUE; }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 709 "src/p.y"
    { Run.httpdsig = FALSE; }
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 720 "src/p.y"
    { Run.bind_addr = (yyvsp[(2) - (2)].string); }
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 723 "src/p.y"
    {
                    Run.httpsslpem = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 728 "src/p.y"
    {
                    Run.httpsslclientpem = (yyvsp[(2) - (2)].string);
                    Run.clientssl = TRUE;
                    if (!file_checkStat(Run.httpsslclientpem, "SSL client PEM file", S_IRWXU | S_IRGRP | S_IROTH))
                      yyerror2("SSL client PEM file has too loose permissions");
                  }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 736 "src/p.y"
    {
                    Run.allowselfcert = TRUE;
                  }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 741 "src/p.y"
    {
                    addcredentials((yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].string), DIGEST_CLEARTEXT, (yyvsp[(5) - (5)].number));
                  }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 744 "src/p.y"
    {
#ifdef HAVE_LIBPAM
                    addpamauth((yyvsp[(3) - (4)].string), (yyvsp[(4) - (4)].number));
#else
                    yyerror("PAM is not supported");
                    FREE((yyvsp[(3) - (4)].string));
#endif
                  }
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 752 "src/p.y"
    {
                    addhtpasswdentry((yyvsp[(2) - (2)].string), NULL, DIGEST_CLEARTEXT);
                    FREE((yyvsp[(2) - (2)].string));
                  }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 756 "src/p.y"
    {
                    addhtpasswdentry((yyvsp[(3) - (3)].string), NULL, DIGEST_CLEARTEXT);
                    FREE((yyvsp[(3) - (3)].string));
                  }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 760 "src/p.y"
    {
                    addhtpasswdentry((yyvsp[(3) - (3)].string), NULL, DIGEST_MD5);
                    FREE((yyvsp[(3) - (3)].string));
                  }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 764 "src/p.y"
    {
                    addhtpasswdentry((yyvsp[(3) - (3)].string), NULL, DIGEST_CRYPT);
                    FREE((yyvsp[(3) - (3)].string));
                  }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 768 "src/p.y"
    {
                    htpasswd_file = (yyvsp[(2) - (2)].string);
                    digesttype = CLEARTEXT;
                  }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 772 "src/p.y"
    {
                    FREE(htpasswd_file);
                  }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 775 "src/p.y"
    {
                    htpasswd_file = (yyvsp[(3) - (3)].string);
                    digesttype = DIGEST_CLEARTEXT;
                  }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 779 "src/p.y"
    {
                    FREE(htpasswd_file);
                  }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 782 "src/p.y"
    {
                    htpasswd_file = (yyvsp[(3) - (3)].string);
                    digesttype = DIGEST_MD5;
                  }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 786 "src/p.y"
    {
                    FREE(htpasswd_file);
                  }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 789 "src/p.y"
    {
                    htpasswd_file = (yyvsp[(3) - (3)].string);
                    digesttype = DIGEST_CRYPT;
                  }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 793 "src/p.y"
    {
                    FREE(htpasswd_file);
                  }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 796 "src/p.y"
    {
                    if (! (add_net_allow((yyvsp[(2) - (2)].string)) || add_host_allow((yyvsp[(2) - (2)].string)))) {
                      yyerror2("erroneous network or host identifier %s", (yyvsp[(2) - (2)].string));
                    }
                    FREE((yyvsp[(2) - (2)].string));
                  }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 808 "src/p.y"
    { addhtpasswdentry(htpasswd_file, (yyvsp[(1) - (1)].string), digesttype);
                           FREE((yyvsp[(1) - (1)].string)); }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 812 "src/p.y"
    { (yyval.number) = FALSE; }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 813 "src/p.y"
    { (yyval.number) = TRUE; }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 816 "src/p.y"
    {
                    createservice(TYPE_PROCESS, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_process);
                  }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 819 "src/p.y"
    {
                    createservice(TYPE_PROCESS, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_process);
                  }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 822 "src/p.y"
    {
                    createservice(TYPE_PROCESS, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_process);
                    matchset.ignore = FALSE;
                    matchset.match_path = NULL;
                    matchset.match_string = Str_dup((yyvsp[(4) - (4)].string));
                    addmatch(&matchset, ACTION_IGNORE, 0);
                  }
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 829 "src/p.y"
    {
                    createservice(TYPE_PROCESS, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_process);
                    matchset.ignore = FALSE;
                    matchset.match_path = NULL;
                    matchset.match_string = Str_dup((yyvsp[(4) - (4)].string));
                    addmatch(&matchset, ACTION_IGNORE, 0);
                  }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 838 "src/p.y"
    {
                    createservice(TYPE_FILE, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_file);
                  }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 843 "src/p.y"
    {
                    createservice(TYPE_FILESYSTEM, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_filesystem);
                  }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 848 "src/p.y"
    {
                    createservice(TYPE_DIRECTORY, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_directory);
                  }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 853 "src/p.y"
    {
                    check_hostname((yyvsp[(4) - (4)].string));
                    createservice(TYPE_HOST, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_remote_host);
                  }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 859 "src/p.y"
    {
                    char hostname[STRLEN];
                    if (Util_getfqdnhostname(hostname, sizeof(hostname))) {
                      LogError("Cannot get system hostname\n");
                      cfg_errflag++;
                    }
                    char *servicename = (yyvsp[(2) - (2)].string);
                    Util_replaceString(&servicename, "$HOST", hostname);
                    Run.system = createservice(TYPE_SYSTEM, servicename, Str_dup(""), check_system); // The name given in the 'check system' statement overrides system hostname
                  }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 871 "src/p.y"
    {
                    createservice(TYPE_FIFO, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_fifo);
                  }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 876 "src/p.y"
    {
                        command_t c = command; // Current command
                        check_exec(c->arg[0]);
                        createservice(TYPE_PROGRAM, (yyvsp[(2) - (5)].string), Str_dup(c->arg[0]), check_program);
                        current->program->timeout = (yyvsp[(5) - (5)].number);
                  }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 884 "src/p.y"
    {
                    addcommand(START, (yyvsp[(3) - (3)].number));
                  }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 887 "src/p.y"
    {
                    addcommand(START, (yyvsp[(4) - (4)].number));
                  }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 892 "src/p.y"
    {
                    addcommand(STOP, (yyvsp[(3) - (3)].number));
                  }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 895 "src/p.y"
    {
                    addcommand(STOP, (yyvsp[(4) - (4)].number));
                  }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 901 "src/p.y"
    {
                    addcommand(RESTART, (yyvsp[(3) - (3)].number));
                  }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 904 "src/p.y"
    {
                    addcommand(RESTART, (yyvsp[(4) - (4)].number));
                  }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 917 "src/p.y"
    { addargument((yyvsp[(1) - (1)].string)); }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 918 "src/p.y"
    { addargument((yyvsp[(1) - (1)].string)); }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 921 "src/p.y"
    { addeuid( get_uid((yyvsp[(2) - (2)].string), 0) ); FREE((yyvsp[(2) - (2)].string)); }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 922 "src/p.y"
    { addegid( get_gid((yyvsp[(2) - (2)].string), 0) ); FREE((yyvsp[(2) - (2)].string)); }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 923 "src/p.y"
    { addeuid( get_uid(NULL, (yyvsp[(2) - (2)].number)) ); }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 924 "src/p.y"
    { addegid( get_gid(NULL, (yyvsp[(2) - (2)].number)) ); }
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 927 "src/p.y"
    { (yyval.string) = NULL; }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 928 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 929 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 932 "src/p.y"
    { (yyval.string) = NULL; }
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 933 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 936 "src/p.y"
    { (yyval.string) = NULL; }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 937 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 941 "src/p.y"
    {
                    portset.timeout = (yyvsp[(7) - (12)].number);
                    portset.retry = (yyvsp[(8) - (12)].number);
                    addeventaction(&(portset).action, (yyvsp[(11) - (12)].number), (yyvsp[(12) - (12)].number));
                    addport(&portset);
                  }
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 948 "src/p.y"
    {
                    prepare_urlrequest((yyvsp[(4) - (11)].url));
                    portset.timeout = (yyvsp[(6) - (11)].number);
                    portset.retry = (yyvsp[(7) - (11)].number);
                    addeventaction(&(portset).action, (yyvsp[(10) - (11)].number), (yyvsp[(11) - (11)].number));
                    addport(&portset);
                  }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 958 "src/p.y"
    {
                   portset.timeout = (yyvsp[(6) - (11)].number);
                   portset.retry = (yyvsp[(7) - (11)].number);
                   addeventaction(&(portset).action, (yyvsp[(10) - (11)].number), (yyvsp[(11) - (11)].number));
                   addport(&portset);
                  }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 967 "src/p.y"
    {
                   icmpset.type = (yyvsp[(4) - (10)].number);
                   icmpset.count = (yyvsp[(5) - (10)].number);
                   icmpset.timeout = (yyvsp[(6) - (10)].number);
                   addeventaction(&(icmpset).action, (yyvsp[(9) - (10)].number), (yyvsp[(10) - (10)].number));
                   addicmp(&icmpset);
                  }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 976 "src/p.y"
    {
                    if (current->type == TYPE_HOST)
                      portset.hostname = Str_dup(current->path);
                    else
                      portset.hostname = Str_dup(LOCALHOST);
                  }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 982 "src/p.y"
    { check_hostname((yyvsp[(2) - (2)].string)); portset.hostname = (yyvsp[(2) - (2)].string); }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 985 "src/p.y"
    { portset.port = (yyvsp[(2) - (2)].number); portset.family = AF_INET; }
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 988 "src/p.y"
    {
                    portset.pathname = (yyvsp[(2) - (2)].string); portset.family = AF_UNIX;
                  }
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 993 "src/p.y"
    {
                    portset.type = SOCK_STREAM;
                  }
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 996 "src/p.y"
    {
                    portset.type = SOCK_STREAM;
                  }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 999 "src/p.y"
    {
                    portset.type = SOCK_STREAM;
                    portset.SSL.use_ssl = TRUE;
                    portset.SSL.version = (yyvsp[(3) - (4)].number);
                    if (portset.SSL.version == SSL_VERSION_NONE)
                      portset.SSL.version = SSL_VERSION_AUTO;
                    portset.SSL.certmd5 = (yyvsp[(4) - (4)].string);
                  }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1007 "src/p.y"
    {
                    portset.type = SOCK_DGRAM;
                  }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1012 "src/p.y"
    { (yyval.string) = NULL; }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1013 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1016 "src/p.y"
    { (yyval.number) = SSL_VERSION_NONE; }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1017 "src/p.y"
    { (yyval.number) = SSL_VERSION_SSLV2; }
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1018 "src/p.y"
    { (yyval.number) = SSL_VERSION_SSLV3; }
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1019 "src/p.y"
    { (yyval.number) = SSL_VERSION_TLS; }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1020 "src/p.y"
    { (yyval.number) = SSL_VERSION_AUTO; }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1023 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_DEFAULT);
                  }
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1026 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_APACHESTATUS);
                  }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1029 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_DEFAULT);
                  }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1032 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_DNS);
                  }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 1035 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_DWP);
                  }
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 1038 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_FTP);
                  }
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 1041 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_HTTP);
                  }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1044 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_IMAP);
                  }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1047 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_CLAMAV);
                  }
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1050 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_LDAP2);
                  }
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 1053 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_LDAP3);
                  }
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 1056 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_MYSQL);
                  }
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 1059 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_SIP);
                  }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 1062 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_NNTP);
                  }
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 1065 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_NTP3);
                    portset.type = SOCK_DGRAM;
                  }
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 1069 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_POSTFIXPOLICY);
                  }
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1072 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_POP);
                  }
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1075 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_SMTP);
                  }
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1078 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_SSH);
                  }
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1081 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_RDATE);
                  }
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 1084 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_RSYNC);
                  }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 1087 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_TNS);
                  }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 1090 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_PGSQL);
                  }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1093 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_LMTP);
                  }
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1096 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_GPS);
                  }
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1099 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_RADIUS);
                  }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1102 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_MEMCACHE);
                  }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1105 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_GENERIC);
                  }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1114 "src/p.y"
    { addgeneric(&portset, (yyvsp[(2) - (2)].string), NULL); FREE((yyvsp[(2) - (2)].string));}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1115 "src/p.y"
    { addgeneric(&portset, NULL, (yyvsp[(2) - (2)].string)); FREE((yyvsp[(2) - (2)].string));}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1119 "src/p.y"
    {
                    portset.request = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1122 "src/p.y"
    {
                    portset.request = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1128 "src/p.y"
    {
                     portset.maxforward = verifyMaxForward((yyvsp[(2) - (2)].number));
                   }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1134 "src/p.y"
    {
                    portset.request = Util_urlEncode((yyvsp[(2) - (3)].string));
                    FREE((yyvsp[(2) - (3)].string));
                  }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1138 "src/p.y"
    {
                    portset.request = Util_urlEncode((yyvsp[(2) - (5)].string));
                    FREE((yyvsp[(2) - (5)].string));
                    portset.request_checksum = (yyvsp[(4) - (5)].string);
                  }
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1146 "src/p.y"
    {
                    portset.request_hostheader = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1151 "src/p.y"
    {
                    portset.request = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 1160 "src/p.y"
    {
                    portset.ApacheStatus.loglimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.loglimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1164 "src/p.y"
    {
                    portset.ApacheStatus.closelimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.closelimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1168 "src/p.y"
    {
                    portset.ApacheStatus.dnslimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.dnslimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1172 "src/p.y"
    {
                    portset.ApacheStatus.keepalivelimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.keepalivelimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1176 "src/p.y"
    {
                    portset.ApacheStatus.replylimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.replylimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1180 "src/p.y"
    {
                    portset.ApacheStatus.requestlimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.requestlimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1184 "src/p.y"
    {
                    portset.ApacheStatus.startlimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.startlimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1188 "src/p.y"
    {
                    portset.ApacheStatus.waitlimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.waitlimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 1192 "src/p.y"
    {
                    portset.ApacheStatus.gracefullimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.gracefullimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 1196 "src/p.y"
    {
                    portset.ApacheStatus.cleanuplimitOP = (yyvsp[(2) - (4)].number);
                    portset.ApacheStatus.cleanuplimit = (yyvsp[(3) - (4)].number);
                  }
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 1202 "src/p.y"
    {
                    seteventaction(&(current)->action_NONEXIST, (yyvsp[(6) - (7)].number), (yyvsp[(7) - (7)].number));
                  }
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 1208 "src/p.y"
    {
                    seteventaction(&(current)->action_PID, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                  }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 1213 "src/p.y"
    {
                    seteventaction(&(current)->action_PPID, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                  }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 1218 "src/p.y"
    {
                    uptimeset.operator = (yyvsp[(3) - (9)].number);
                    uptimeset.uptime = ((unsigned long long)(yyvsp[(4) - (9)].number) * (yyvsp[(5) - (9)].number));
                    addeventaction(&(uptimeset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    adduptime(&uptimeset);
                  }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 1225 "src/p.y"
    {
                   (yyval.number) = ICMP_ATTEMPT_COUNT;
                  }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 1228 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (2)].number);
                  }
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 1233 "src/p.y"
    {
                   (yyval.number) = EXEC_TIMEOUT;
                  }
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 1236 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (3)].number);
                  }
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 1241 "src/p.y"
    {
                   (yyval.number) = PROGRAM_TIMEOUT; // Default program status check timeout is 5 min
                  }
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 1244 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (3)].number);
                  }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 1249 "src/p.y"
    {
                   (yyval.number) = NET_TIMEOUT;
                  }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 1252 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (3)].number);
                  }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 1257 "src/p.y"
    {
                   (yyval.number) = 1;
                  }
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 1260 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (2)].number);
                  }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 1265 "src/p.y"
    {
                   actionrateset.count = (yyvsp[(2) - (7)].number);
                   actionrateset.cycle = (yyvsp[(4) - (7)].number);
                   addeventaction(&(actionrateset).action, (yyvsp[(7) - (7)].number), ACTION_ALERT);
                   addactionrate(&actionrateset);
                 }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 1271 "src/p.y"
    {
                   actionrateset.count = (yyvsp[(2) - (7)].number);
                   actionrateset.cycle = (yyvsp[(4) - (7)].number);
                   addeventaction(&(actionrateset).action, ACTION_UNMONITOR, ACTION_ALERT);
                   addactionrate(&actionrateset);
                 }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 1280 "src/p.y"
    {
                    seturlrequest((yyvsp[(2) - (3)].number), (yyvsp[(3) - (3)].string));
                    FREE((yyvsp[(3) - (3)].string));
                  }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 1286 "src/p.y"
    { (yyval.number) = Operator_Equal; }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 1287 "src/p.y"
    { (yyval.number) = Operator_NotEqual; }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 1290 "src/p.y"
    {
                   mailset.events = Event_All;
                   addmail((yyvsp[(1) - (3)].string), &mailset, &current->maillist);
                  }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 1294 "src/p.y"
    {
                   addmail((yyvsp[(1) - (6)].string), &mailset, &current->maillist);
                  }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 1297 "src/p.y"
    {
                   mailset.events = ~mailset.events;
                   addmail((yyvsp[(1) - (7)].string), &mailset, &current->maillist);
                  }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 1301 "src/p.y"
    {
                   addmail((yyvsp[(1) - (1)].string), &mailset, &current->maillist);
                  }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 1306 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 1309 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 1316 "src/p.y"
    { mailset.events |= Event_Action; }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 1317 "src/p.y"
    { mailset.events |= Event_Checksum; }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 1318 "src/p.y"
    { mailset.events |= Event_Connection; }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 1319 "src/p.y"
    { mailset.events |= Event_Content; }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 1320 "src/p.y"
    { mailset.events |= Event_Data; }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 1321 "src/p.y"
    { mailset.events |= Event_Exec; }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 1322 "src/p.y"
    { mailset.events |= Event_Fsflag; }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 1323 "src/p.y"
    { mailset.events |= Event_Gid; }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 1324 "src/p.y"
    { mailset.events |= Event_Icmp; }
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 1325 "src/p.y"
    { mailset.events |= Event_Instance; }
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 1326 "src/p.y"
    { mailset.events |= Event_Invalid; }
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 1327 "src/p.y"
    { mailset.events |= Event_Nonexist; }
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 1328 "src/p.y"
    { mailset.events |= Event_Permission; }
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 1329 "src/p.y"
    { mailset.events |= Event_Pid; }
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 1330 "src/p.y"
    { mailset.events |= Event_PPid; }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 1331 "src/p.y"
    { mailset.events |= Event_Resource; }
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 1332 "src/p.y"
    { mailset.events |= Event_Size; }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 1333 "src/p.y"
    { mailset.events |= Event_Status; }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 1334 "src/p.y"
    { mailset.events |= Event_Timeout; }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 1335 "src/p.y"
    { mailset.events |= Event_Timestamp; }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 1336 "src/p.y"
    { mailset.events |= Event_Uid; }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 1337 "src/p.y"
    { mailset.events |= Event_Uptime; }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 1348 "src/p.y"
    { mailset.from = (yyvsp[(1) - (1)].string); }
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 1349 "src/p.y"
    { mailset.replyto = (yyvsp[(1) - (1)].string); }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 1350 "src/p.y"
    { mailset.subject = (yyvsp[(1) - (1)].string); }
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 1351 "src/p.y"
    { mailset.message = (yyvsp[(1) - (1)].string); }
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 1354 "src/p.y"
    {
                   current->every.type = EVERY_SKIPCYCLES;
                   current->every.spec.cycle.number = (yyvsp[(2) - (3)].number);
                 }
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 1358 "src/p.y"
    {
                   current->every.type = EVERY_CRON;
                   current->every.spec.cron = (yyvsp[(2) - (2)].string);
                 }
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 1362 "src/p.y"
    {
                   current->every.type = EVERY_NOTINCRON;
                   current->every.spec.cron = (yyvsp[(2) - (2)].string);
                 }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 1368 "src/p.y"
    {
                    current->mode = MODE_ACTIVE;
                  }
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 1371 "src/p.y"
    {
                    current->mode = MODE_PASSIVE;
                  }
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 1374 "src/p.y"
    {
                    current->mode = MODE_MANUAL;
                    current->monitor = MONITOR_NOT;
                  }
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 1380 "src/p.y"
    { addservicegroup((yyvsp[(2) - (2)].string)); FREE((yyvsp[(2) - (2)].string));}
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 1391 "src/p.y"
    { adddependant((yyvsp[(1) - (1)].string)); }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 1394 "src/p.y"
    {
                        statusset.operator = (yyvsp[(3) - (8)].number);
                        statusset.return_value = (yyvsp[(4) - (8)].number);
                        addeventaction(&(statusset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                        addstatus(&statusset);
                   }
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 1402 "src/p.y"
    {
                     addeventaction(&(resourceset).action, (yyvsp[(5) - (6)].number), (yyvsp[(6) - (6)].number));
                     addresource(&resourceset);
                   }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 1418 "src/p.y"
    {
                     addeventaction(&(resourceset).action, (yyvsp[(5) - (6)].number), (yyvsp[(6) - (6)].number));
                     addresource(&resourceset);
                   }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 1434 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_CPU_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10);
                  }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 1439 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_TOTAL_CPU_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10);
                  }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 1446 "src/p.y"
    {
                    resourceset.resource_id = (yyvsp[(1) - (4)].number);
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10);
                  }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 1453 "src/p.y"
    { (yyval.number) = RESOURCE_ID_CPUUSER; }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 1454 "src/p.y"
    { (yyval.number) = RESOURCE_ID_CPUSYSTEM; }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 1455 "src/p.y"
    { (yyval.number) = RESOURCE_ID_CPUWAIT; }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 1458 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_MEM_KBYTE;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = (int) ((yyvsp[(3) - (4)].real) * ((yyvsp[(4) - (4)].number) / 1024.0));
                  }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 1463 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_MEM_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10);
                  }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 1468 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_TOTAL_MEM_KBYTE;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = (int) ((yyvsp[(3) - (4)].real) * ((yyvsp[(4) - (4)].number) / 1024.0));
                  }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 1473 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_TOTAL_MEM_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10);
                  }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 1480 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_SWAP_KBYTE;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = (int) ((yyvsp[(3) - (4)].real) * ((yyvsp[(4) - (4)].number) / 1024.0));
                  }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 1485 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_SWAP_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10);
                  }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 1492 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_CHILDREN;
                    resourceset.operator = (yyvsp[(2) - (3)].number);
                    resourceset.limit = (int) (yyvsp[(3) - (3)].number);
                  }
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 1499 "src/p.y"
    {
                    resourceset.resource_id = (yyvsp[(1) - (3)].number);
                    resourceset.operator = (yyvsp[(2) - (3)].number);
                    resourceset.limit = (int) ((yyvsp[(3) - (3)].real) * 10.0);
                  }
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 1506 "src/p.y"
    { (yyval.number) = RESOURCE_ID_LOAD1; }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 1507 "src/p.y"
    { (yyval.number) = RESOURCE_ID_LOAD5; }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 1508 "src/p.y"
    { (yyval.number) = RESOURCE_ID_LOAD15; }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 1511 "src/p.y"
    { (yyval.real) = (yyvsp[(1) - (1)].real); }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 1512 "src/p.y"
    { (yyval.real) = (float) (yyvsp[(1) - (1)].number); }
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 1515 "src/p.y"
    {
                    timestampset.operator = (yyvsp[(3) - (9)].number);
                    timestampset.time = ((yyvsp[(4) - (9)].number) * (yyvsp[(5) - (9)].number));
                    addeventaction(&(timestampset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addtimestamp(&timestampset, FALSE);
                  }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 1521 "src/p.y"
    {
                    timestampset.test_changes = TRUE;
                    addeventaction(&(timestampset).action, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                    addtimestamp(&timestampset, TRUE);
                  }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 1528 "src/p.y"
    { (yyval.number) = Operator_Equal; }
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 1529 "src/p.y"
    { (yyval.number) = Operator_Greater; }
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 1530 "src/p.y"
    { (yyval.number) = Operator_Less; }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 1531 "src/p.y"
    { (yyval.number) = Operator_Equal; }
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 1532 "src/p.y"
    { (yyval.number) = Operator_NotEqual; }
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 1533 "src/p.y"
    { (yyval.number) = Operator_NotEqual; }
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 1536 "src/p.y"
    { (yyval.number) = TIME_SECOND; }
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 1537 "src/p.y"
    { (yyval.number) = TIME_SECOND; }
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 1538 "src/p.y"
    { (yyval.number) = TIME_MINUTE; }
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 1539 "src/p.y"
    { (yyval.number) = TIME_HOUR; }
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 1540 "src/p.y"
    { (yyval.number) = TIME_DAY; }
    break;

  case 454:

/* Line 1806 of yacc.c  */
#line 1543 "src/p.y"
    { (yyval.number) = ACTION_ALERT; }
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 1544 "src/p.y"
    { (yyval.number) = ACTION_EXEC; }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 1545 "src/p.y"
    { (yyval.number) = ACTION_EXEC; }
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 1546 "src/p.y"
    { (yyval.number) = ACTION_RESTART; }
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 1547 "src/p.y"
    { (yyval.number) = ACTION_START; }
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 1548 "src/p.y"
    { (yyval.number) = ACTION_STOP; }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 1549 "src/p.y"
    { (yyval.number) = ACTION_UNMONITOR; }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 1552 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(1) - (1)].number);
                    if ((yyvsp[(1) - (1)].number) == ACTION_EXEC && command) {
                      command1 = command;
                      command = NULL;
                    }
                  }
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 1561 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(1) - (1)].number);
                    if ((yyvsp[(1) - (1)].number) == ACTION_EXEC && command) {
                      command2 = command;
                      command = NULL;
                    }
                  }
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 1571 "src/p.y"
    {
                    rate1.count  = (yyvsp[(1) - (2)].number);
                    rate1.cycles = (yyvsp[(1) - (2)].number);
                    if (rate1.cycles < 1 || rate1.cycles > BITMAP_MAX)
                      yyerror2("the number of cycles must be between 1 and %d", BITMAP_MAX);
                  }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 1577 "src/p.y"
    {
                    rate1.count  = (yyvsp[(1) - (3)].number);
                    rate1.cycles = (yyvsp[(2) - (3)].number);
                    if (rate1.cycles < 1 || rate1.cycles > BITMAP_MAX)
                      yyerror2("the number of cycles must be between 1 and %d", BITMAP_MAX);
                    if (rate1.count < 1 || rate1.count > rate1.cycles)
                      yyerror2("the number of events must be bigger then 0 and less than poll cycles");
                  }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 1588 "src/p.y"
    {
                    rate2.count  = (yyvsp[(1) - (2)].number);
                    rate2.cycles = (yyvsp[(1) - (2)].number);
                    if (rate2.cycles < 1 || rate2.cycles > BITMAP_MAX)
                      yyerror2("the number of cycles must be between 1 and %d", BITMAP_MAX);
                  }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 1594 "src/p.y"
    {
                    rate2.count  = (yyvsp[(1) - (3)].number);
                    rate2.cycles = (yyvsp[(2) - (3)].number);
                    if (rate2.cycles < 1 || rate2.cycles > BITMAP_MAX)
                      yyerror2("the number of cycles must be between 1 and %d", BITMAP_MAX);
                    if (rate2.count < 1 || rate2.count > rate2.cycles)
                      yyerror2("the number of events must be bigger then 0 and less than poll cycles");
                  }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 1604 "src/p.y"
    {
                    (yyval.number) = ACTION_ALERT;
                  }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 1607 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(6) - (6)].number);
                  }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 1610 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(6) - (6)].number);
                  }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 1613 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(6) - (6)].number);
                  }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 1618 "src/p.y"
    {
                    addeventaction(&(checksumset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addchecksum(&checksumset);
                  }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 1623 "src/p.y"
    {
                    snprintf(checksumset.hash, sizeof(checksumset.hash), "%s", (yyvsp[(6) - (10)].string));
                    FREE((yyvsp[(6) - (10)].string));
                    addeventaction(&(checksumset).action, (yyvsp[(9) - (10)].number), (yyvsp[(10) - (10)].number));
                    addchecksum(&checksumset);
                  }
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 1629 "src/p.y"
    {
                    checksumset.test_changes = TRUE;
                    addeventaction(&(checksumset).action, (yyvsp[(7) - (7)].number), ACTION_IGNORE);
                    addchecksum(&checksumset);
                  }
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 1635 "src/p.y"
    { checksumset.type = HASH_UNKNOWN; }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 1636 "src/p.y"
    { checksumset.type = HASH_MD5; }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 1637 "src/p.y"
    { checksumset.type = HASH_SHA1; }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 1640 "src/p.y"
    {
                    filesystemset.resource = RESOURCE_ID_INODE;
                    filesystemset.operator = (yyvsp[(3) - (8)].number);
                    filesystemset.limit_absolute = (yyvsp[(4) - (8)].number);
                    addeventaction(&(filesystemset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addfilesystem(&filesystemset);
                  }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 1647 "src/p.y"
    {
                    filesystemset.resource = RESOURCE_ID_INODE;
                    filesystemset.operator = (yyvsp[(3) - (9)].number);
                    filesystemset.limit_percent = (int)((yyvsp[(4) - (9)].number) * 10);
                    addeventaction(&(filesystemset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addfilesystem(&filesystemset);
                  }
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 1656 "src/p.y"
    {
                    if (!filesystem_usage(current->inf, current->path))
                      yyerror2("cannot read usage of filesystem %s", current->path);
                    filesystemset.resource = RESOURCE_ID_SPACE;
                    filesystemset.operator = (yyvsp[(3) - (9)].number);
                    filesystemset.limit_absolute = (int)((float)(yyvsp[(4) - (9)].real) / (float)current->inf->priv.filesystem.f_bsize * (float)(yyvsp[(5) - (9)].number));
                    addeventaction(&(filesystemset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addfilesystem(&filesystemset);
                  }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 1665 "src/p.y"
    {
                    filesystemset.resource = RESOURCE_ID_SPACE;
                    filesystemset.operator = (yyvsp[(3) - (9)].number);
                    filesystemset.limit_percent = (int)((yyvsp[(4) - (9)].number) * 10);
                    addeventaction(&(filesystemset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addfilesystem(&filesystemset);
                  }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 1674 "src/p.y"
    {
                    seteventaction(&(current)->action_FSFLAG, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                  }
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 1679 "src/p.y"
    { (yyval.number) = UNIT_BYTE; }
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 1680 "src/p.y"
    { (yyval.number) = UNIT_BYTE; }
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 1681 "src/p.y"
    { (yyval.number) = UNIT_KILOBYTE; }
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 1682 "src/p.y"
    { (yyval.number) = UNIT_MEGABYTE; }
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 1683 "src/p.y"
    { (yyval.number) = UNIT_GIGABYTE; }
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 1686 "src/p.y"
    {
                    permset.perm = check_perm((yyvsp[(4) - (8)].number));
                    addeventaction(&(permset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addperm(&permset);
                  }
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 1693 "src/p.y"
    {
                    matchset.ignore = FALSE;
                    matchset.match_path = (yyvsp[(4) - (7)].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, (yyvsp[(7) - (7)].number));
                    FREE((yyvsp[(4) - (7)].string));
                  }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 1700 "src/p.y"
    {
                    matchset.ignore = FALSE;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[(4) - (7)].string);
                    addmatch(&matchset, (yyvsp[(7) - (7)].number), 0);
                  }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 1706 "src/p.y"
    {
                    matchset.ignore = TRUE;
                    matchset.match_path = (yyvsp[(4) - (4)].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, ACTION_IGNORE);
                    FREE((yyvsp[(4) - (4)].string));
                  }
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 1713 "src/p.y"
    {
                    matchset.ignore = TRUE;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[(4) - (4)].string);
                    addmatch(&matchset, ACTION_IGNORE, 0);
                  }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 1721 "src/p.y"
    {
                    matchset.not = FALSE;
                  }
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 1724 "src/p.y"
    {
                    matchset.not = TRUE;
                  }
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 1730 "src/p.y"
    {
                    sizeset.operator = (yyvsp[(3) - (9)].number);
                    sizeset.size = ((unsigned long long)(yyvsp[(4) - (9)].number) * (yyvsp[(5) - (9)].number));
                    addeventaction(&(sizeset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addsize(&sizeset);
                  }
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 1736 "src/p.y"
    {
                    sizeset.test_changes = TRUE;
                    addeventaction(&(sizeset).action, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                    addsize(&sizeset);
                  }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 1743 "src/p.y"
    {
                    uidset.uid = get_uid((yyvsp[(4) - (8)].string), 0);
                    addeventaction(&(uidset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    adduid(&uidset);
                    FREE((yyvsp[(4) - (8)].string));
                  }
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 1749 "src/p.y"
    {
                    uidset.uid = get_uid(NULL, (yyvsp[(4) - (8)].number));
                    addeventaction(&(uidset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    adduid(&uidset);
                  }
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 1756 "src/p.y"
    {
                    gidset.gid = get_gid((yyvsp[(4) - (8)].string), 0);
                    addeventaction(&(gidset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addgid(&gidset);
                    FREE((yyvsp[(4) - (8)].string));
                  }
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 1762 "src/p.y"
    {
                    gidset.gid = get_gid(NULL, (yyvsp[(4) - (8)].number));
                    addeventaction(&(gidset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addgid(&gidset);
                  }
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 1769 "src/p.y"
    { (yyval.number) = ICMP_ECHO; }
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 1772 "src/p.y"
    { mailset.reminder = 0; }
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 1773 "src/p.y"
    { mailset.reminder = (yyvsp[(2) - (2)].number); }
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 1774 "src/p.y"
    { mailset.reminder = (yyvsp[(2) - (3)].number); }
    break;



/* Line 1806 of yacc.c  */
#line 5607 "src/y.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1777 "src/p.y"



/* -------------------------------------------------------- Parser interface */


/**
 * Syntactic error routine
 *
 * This routine is automatically called by the lexer!
 */
void yyerror(const char *s, ...) {
  va_list ap;
  char *msg = NULL;

  ASSERT(s);

  va_start(ap,s);
  msg = Str_vcat(s, ap);
  va_end(ap);

  LogError("%s:%i: Error: %s '%s'\n", currentfile, lineno, msg, yytext);
  cfg_errflag++;

  FREE(msg);

}

/**
 * Syntactical warning routine
 */
void yywarning(const char *s, ...) {
  va_list ap;
  char *msg = NULL;

  ASSERT(s);

  va_start(ap,s);
  msg = Str_vcat(s, ap);
  va_end(ap);

  LogWarning("%s:%i: Warning: %s '%s'\n", currentfile, lineno, msg, yytext);

  FREE(msg);

}

/**
 * Argument error routine
 */
void yyerror2(const char *s, ...) {
  va_list ap;
  char *msg = NULL;

  ASSERT(s);

  va_start(ap,s);
  msg = Str_vcat(s, ap);
  va_end(ap);

  LogError("%s:%i: Error: %s '%s'\n", argcurrentfile, arglineno, msg, argyytext);
  cfg_errflag++;

  FREE(msg);

}

/**
 * Argument warning routine
 */
void yywarning2(const char *s, ...) {
  va_list ap;
  char *msg = NULL;

  ASSERT(s);

  va_start(ap,s);
  msg = Str_vcat(s, ap);
  va_end(ap);

  LogWarning("%s:%i: Warning: %s '%s'\n", argcurrentfile, arglineno, msg, argyytext);

  FREE(msg);

}

/*
 * The Parser hook - start parsing the control file
 * Returns TRUE if parsing succeeded, otherwise FALSE
 */
int parse(char *controlfile) {

  ASSERT(controlfile);

  servicelist = tail = current = NULL;

  if ((yyin = fopen(controlfile,"r")) == (FILE *)NULL) {
    LogError("%s: Error: cannot open the control file '%s' -- %s\n", prog, controlfile, STRERROR);
    return FALSE;
  }

  currentfile = Str_dup(controlfile);

  /*
   * Creation of the global service list is synchronized
   */
  LOCK(Run.mutex)
    preparse();
    yyparse();
    fclose(yyin);
    postparse();
  END_LOCK;

  FREE(currentfile);

  if (argyytext != NULL)
    FREE(argyytext);

  /*
   * Secure check the monitrc file. The run control file must have the
   * same uid as the REAL uid of this process, it must have permissions
   * no greater than 700 and it must not be a symbolic link.
   */
  if (! file_checkStat(controlfile, "control file", S_IRUSR|S_IWUSR|S_IXUSR))
    return FALSE;

  return(cfg_errflag == 0);
}


/* ----------------------------------------------------------------- Private */


/**
 * Initialize objects used by the parser.
 */
static void preparse() {
  int i;

  /* Set instance incarnation ID */
  time(&Run.incarnation);
  /* Reset lexer */
  buffer_stack_ptr        = 0;
  lineno                  = 1;
  arglineno               = 1;
  argcurrentfile          = NULL;
  argyytext               = NULL;
  /* Reset parser */
  Run.stopped             = FALSE;
  Run.dolog               = FALSE;
  Run.dohttpd             = FALSE;
  Run.doaction            = FALSE;
  Run.httpdsig            = TRUE;
  Run.dommonitcredentials = TRUE;
  Run.mmonitcredentials   = NULL;
  Run.credentials         = NULL;
  Run.httpdssl            = FALSE;
  Run.httpsslpem          = NULL;
  Run.httpsslclientpem    = NULL;
  Run.clientssl           = FALSE;
  Run.allowselfcert       = FALSE;
  Run.mailserver_timeout  = SMTP_TIMEOUT;
  Run.bind_addr           = NULL;
  Run.eventlist           = NULL;
  Run.eventlist_dir       = NULL;
  Run.eventlist_slots     = -1;
  Run.system              = NULL;
  Run.expectbuffer        = STRLEN;
  Run.mmonits             = NULL;
  Run.maillist            = NULL;
  Run.mailservers         = NULL;
  Run.MailFormat.from     = NULL;
  Run.MailFormat.replyto  = NULL;
  Run.MailFormat.subject  = NULL;
  Run.MailFormat.message  = NULL;
  depend_list             = NULL;
  Run.handler_init        = TRUE;
#ifdef OPENSSL_FIPS
  Run.fipsEnabled         = FALSE;
#endif
  for (i = 0; i <= HANDLER_MAX; i++)
    Run.handler_queue[i] = 0;
  /*
   * Initialize objects
   */
  reset_uidset();
  reset_statusset();
  reset_gidset();
  reset_sizeset();
  reset_mailset();
  reset_mailserverset();
  reset_portset();
  reset_permset();
  reset_icmpset();
  reset_rateset();
  reset_filesystemset();
  reset_resourceset();
  reset_checksumset();
  reset_timestampset();
  reset_actionrateset();
}


/*
 * Check that values are reasonable after parsing
 */
static void postparse() {
        if (cfg_errflag)
                return;

        /* If defined - add the last service to the service list */
        if (current)
                addservice(current);

        /* Check that we do not start monit in daemon mode without having a poll time */
        if (!Run.polltime && (Run.isdaemon || Run.init)) {
                LogError("%s: Error: Poll time not defined. Please define poll time in the\n control file or use the -d option when starting monit\n", prog);
                cfg_errflag++;
        }

        if (Run.logfile)
                Run.dolog = TRUE;

        for (Service_T s = servicelist; s; s = s->next) {
                if (s->type == TYPE_HOST) {
                        /* Verify that a remote service has a port or an icmp list */
                        if (!s->portlist && !s->icmplist) {
                                LogError("%s: Error: 'check host' statement is incomplete: Please specify a port number to test\n or an icmp test at the remote host: '%s'\n", prog, s->name);
                                cfg_errflag++;
                        }
                } else if (s->type == TYPE_PROGRAM) {
                        /* Verify that a program test has a status test */
                        if (! s->statuslist) {
                                LogError("%s: Error: 'check program %s' is incomplete: Please add an 'if status != n' test\n", prog, s->name);
                                cfg_errflag++;
                        }
                        /* Create the Command object */
                        s->program->C = Command_new(s->path, NULL);
                        // Append any arguments
                        for (int i = 1; i < s->program->args->length; i++) {
                                Command_appendArgument(s->program->C, s->program->args->arg[i]);
                        }
                }
        }

        /* Add the default general system service if not specified explicitly: service name default to hostname */
        if (! Run.system) {
                char hostname[STRLEN];
                if (Util_getfqdnhostname(hostname, sizeof(hostname))) {
                        LogError("Cannot get system hostname -- please add 'check system <name>'\n");
                        cfg_errflag++;
                }
                if (Util_existService(hostname)) {
                        LogError("'check system' not defined in control file, failed to add automatic configuration (service name %s is used already) -- please add 'check system <name>' manually\n", hostname);
                        cfg_errflag++;
                } else {
                        Run.system = createservice(TYPE_SYSTEM, Str_dup(hostname), Str_dup(""), check_system);
                        addservice(Run.system);
                }
        }

        if (Run.mmonits) {
                if (Run.dohttpd) {
                        if (Run.dommonitcredentials) {
                                Auth_T c;
                                for (c = Run.credentials; c; c = c->next) {
                                        if (c->digesttype == DIGEST_CLEARTEXT && ! c->is_readonly) {
                                                Run.mmonitcredentials = c;
                                                break;
                                        }
                                }
                                if (! Run.mmonitcredentials)
                                LogWarning("%s: Warning: M/Monit registration with credentials enabled, but no suitable credentials found in monit configuration file -- please add 'allow user:password' option to 'set httpd' statement\n", prog);
                        }
                } else
                LogWarning("%s: Warning: M/Monit enabled but no httpd allowed -- please add 'set httpd' statement\n", prog);
        }

        /* Check the sanity of any dependency graph */
        check_depend();
}


/*
 * Create a new service object and add any current objects to the
 * service list.
 */
static Service_T createservice(int type, char *name, char *value, int (*check)(Service_T s)) {
  ASSERT(name);
  ASSERT(value);

  check_name(name);

  if (current)
        addservice(current);

  NEW(current);

  current->type = type;

  NEW(current->inf);
  Util_resetInfo(current);

  if (type == TYPE_PROGRAM) {
    NEW(current->program);
    current->program->args = command;
    command = NULL;
    current->program->timeout = PROGRAM_TIMEOUT;
  }

  /* Set default values */
  current->monitor = MONITOR_INIT;
  current->mode    = MODE_ACTIVE;
  current->name    = name;
  current->check   = check;
  current->path    = value;

  /* Initialize general event handlers */
  addeventaction(&(current)->action_DATA,     ACTION_ALERT,     ACTION_ALERT);
  addeventaction(&(current)->action_EXEC,     ACTION_ALERT,     ACTION_ALERT);
  addeventaction(&(current)->action_INVALID,  ACTION_RESTART,   ACTION_ALERT);
  addeventaction(&(current)->action_NONEXIST, ACTION_RESTART,   ACTION_ALERT);
  addeventaction(&(current)->action_PID,      ACTION_ALERT,     ACTION_IGNORE);
  addeventaction(&(current)->action_PPID,     ACTION_ALERT,     ACTION_IGNORE);
  addeventaction(&(current)->action_FSFLAG,   ACTION_ALERT,     ACTION_IGNORE);

  /* Initialize internal event handlers */
  addeventaction(&(current)->action_MONIT_START,  ACTION_START, ACTION_IGNORE);
  addeventaction(&(current)->action_MONIT_STOP,   ACTION_STOP,  ACTION_IGNORE);
  addeventaction(&(current)->action_MONIT_RELOAD, ACTION_START, ACTION_IGNORE);
  addeventaction(&(current)->action_ACTION,       ACTION_ALERT, ACTION_IGNORE);

  gettimeofday(&current->collected, NULL);

  return current;
}


/*
 * Add a service object to the servicelist
 */
static void addservice(Service_T s) {
  ASSERT(s);

  /* Add the service to the end of the service list */
  if (tail != NULL) {
    tail->next = s;
    tail->next_conf = s;
  } else {
    servicelist = s;
    servicelist_conf = s;
  }
  tail = s;
}


/*
 * Add entry to service group list
 */
static void addservicegroup(char *name) {
  ServiceGroup_T g;
  ServiceGroupMember_T m;

  ASSERT(name);

  /* Check if service group with the same name is defined already */
  for (g = servicegrouplist; g; g = g->next)
    if (! strcasecmp(g->name, name))
      break;

  if (! g) {
    NEW(g);
    g->name = Str_dup(name);
    g->next = servicegrouplist;
    servicegrouplist = g;
  }

  NEW(m);
  m->name = Str_dup(current->name);
  m->next = g->members;
  g->members = m;
}


/*
 * Add a dependant entry to the current service dependant list
 *
 */
static void adddependant(char *dependant) {
  Dependant_T d;

  ASSERT(dependant);

  NEW(d);

  if (current->dependantlist != NULL)
    d->next = current->dependantlist;

  d->dependant = dependant;
  current->dependantlist = d;

}


/*
 * Add the given mailaddress with the appropriate alert notification
 * values and mail attributes to the given mailinglist.
 */
static void addmail(char *mailto, Mail_T f, Mail_T *l) {
  Mail_T m;

  ASSERT(mailto);

  NEW(m);
  m->to       = mailto;
  m->from     = f->from;
  m->subject  = f->subject;
  m->message  = f->message;
  m->events   = f->events;
  m->reminder = f->reminder;

  m->next = *l;
  *l = m;

  reset_mailset();
}


/*
 * Add the given portset to the current service's portlist
 */
static void addport(Port_T port) {
  Port_T p;

  ASSERT(port);

  NEW(p);
  p->port               = port->port;
  p->type               = port->type;
  p->socket             = port->socket;
  p->family             = port->family;
  p->action             = port->action;
  p->timeout            = port->timeout;
  p->retry              = port->retry;
  p->request            = port->request;
  p->generic            = port->generic;
  p->protocol           = port->protocol;
  p->pathname           = port->pathname;
  p->hostname           = port->hostname;
  p->url_request        = port->url_request;
  p->request_checksum   = port->request_checksum;
  p->request_hostheader = port->request_hostheader;
  memcpy(&p->ApacheStatus, &port->ApacheStatus, sizeof(struct apache_status));

  if (p->request_checksum) {
    cleanup_hash_string(p->request_checksum);
    if (strlen(p->request_checksum) == 32)
      p->request_hashtype = HASH_MD5;
    else if (strlen(p->request_checksum) == 40)
      p->request_hashtype = HASH_SHA1;
    else
      yyerror2("invalid checksum [%s]", p->request_checksum);
  } else
    p->request_hashtype = 0;

  if (port->SSL.use_ssl == TRUE) {
    if (!have_ssl()) {
      yyerror("ssl check cannot be activated. SSL is not supported");
    } else {
      if (port->SSL.certmd5 != NULL) {
        p->SSL.certmd5 = port->SSL.certmd5;
        cleanup_hash_string(p->SSL.certmd5);
      }
      p->SSL.use_ssl = TRUE;
      p->SSL.version = port->SSL.version;
    }
  }
  p->maxforward = port->maxforward;
  p->next = current->portlist;
  current->portlist = p;

  reset_portset();

}


/*
 * Add a new resource object to the current service resource list
 */
static void addresource(Resource_T rr) {
  Resource_T r;

  ASSERT(rr);

  NEW(r);
  if (! Run.doprocess)
    yyerror("Cannot activate service check. The process status engine was disabled. On certain systems you must run monit as root to utilize this feature)\n");
  r->resource_id = rr->resource_id;
  r->limit       = rr->limit;
  r->action      = rr->action;
  r->operator    = rr->operator;
  r->next        = current->resourcelist;

  current->resourcelist = r;
  reset_resourceset();
}


/*
 * Add a new file object to the current service timestamp list
 */
static void addtimestamp(Timestamp_T ts, int notime) {
  Timestamp_T t;

  ASSERT(ts);

  NEW(t);
  t->operator     = ts->operator;
  t->time         = ts->time;
  t->action       = ts->action;
  t->test_changes = ts->test_changes;

  if (t->test_changes || notime) {
    if (! file_exist(current->path)) {
      DEBUG("%s: Debug: the path '%s' used in the TIMESTAMP statement refer to a non-existing object\n", prog, current->path);
    } else if (!(t->timestamp = file_getTimestamp(current->path, S_IFDIR|S_IFREG))) {
      yyerror2("cannot get the timestamp for '%s'", current->path);
    }
  }

  t->next = current->timestamplist;
  current->timestamplist = t;

  reset_timestampset();
}


/*
 * Add a new object to the current service actionrate list
 */
static void addactionrate(ActionRate_T ar) {
  ActionRate_T a;

  ASSERT(ar);

  if (ar->count > ar->cycle)
    yyerror2("the number of restarts must be less than poll cycles");
  if (ar->count <= 0 || ar->cycle <= 0)
    yyerror2("zero or negative values not allowed in a action rate statement");

  NEW(a);
  a->count  = ar->count;
  a->cycle  = ar->cycle;
  a->action = ar->action;

  a->next = current->actionratelist;
  current->actionratelist = a;

  reset_actionrateset();
}



/*
 * Add a new Size object to the current service size list
 */
static void addsize(Size_T ss) {
  Size_T s;
  struct stat buf;

  ASSERT(ss);

  NEW(s);
  s->operator     = ss->operator;
  s->size         = ss->size;
  s->action       = ss->action;
  s->test_changes = ss->test_changes;
  /* Get the initial size for future comparision, if the file exists */
  if (s->test_changes) {
    s->initialized = ! stat(current->path, &buf);
    if (s->initialized)
      s->size = (unsigned long long)buf.st_size;
  }

  s->next = current->sizelist;
  current->sizelist = s;

  reset_sizeset();
}


/*
 * Add a new Uptime object to the current service uptime list
 */
static void adduptime(Uptime_T uu) {
  Uptime_T u;

  ASSERT(uu);

  NEW(u);
  u->operator = uu->operator;
  u->uptime = uu->uptime;
  u->action = uu->action;

  u->next = current->uptimelist;
  current->uptimelist = u;

  reset_uptimeset();
}


/*
 * Set Checksum object in the current service
 */
static void addchecksum(Checksum_T cs) {

  int len;
  Checksum_T c;

  ASSERT(cs);

  cs->initialized = TRUE;

  if (! *cs->hash) {
    if (cs->type == HASH_UNKNOWN)
      cs->type = DEFAULT_HASH;
    if ( !(Util_getChecksum(current->path, cs->type, cs->hash, sizeof(cs->hash)))) {
      /* If the file doesn't exist, set dummy value */
      snprintf(cs->hash, sizeof(cs->hash), "00000000000000000000000000000000");
      cs->initialized = FALSE;
      yywarning2("cannot compute a checksum for file %s", current->path);
    }
  }

  len = cleanup_hash_string(cs->hash);

  if (cs->type == HASH_UNKNOWN) {
    if (len == 32) {
      cs->type = HASH_MD5;
    } else if (len == 40) {
      cs->type = HASH_SHA1;
    } else {
      yyerror2("unknown checksum type [%s] for file %s", cs->hash, current->path);
      reset_checksumset();
      return;
    }
  } else if (( cs->type == HASH_MD5 && len!=32 ) || ( cs->type == HASH_SHA1 && len != 40 )) {
    yyerror2("invalid checksum [%s] for file %s", cs->hash, current->path);
    reset_checksumset();
    return;
  }

  NEW(c);

  c->type         = cs->type;
  c->test_changes = cs->test_changes;
  c->initialized  = cs->initialized;
  c->action       = cs->action;
  snprintf(c->hash, sizeof(c->hash), "%s", cs->hash);

  current->checksum = c;

  reset_checksumset();

}


/*
 * Set Perm object in the current service
 */
static void addperm(Perm_T ps) {
  Perm_T p;

  ASSERT(ps);

  NEW(p);
  p->perm       = ps->perm;
  p->action     = ps->action;
  current->perm = p;
  reset_permset();

}


static void appendmatch(Match_T *list, Match_T item) {
  if (*list) {
    /* Find the end of the list (keep the same patterns order as in the config file) */
    Match_T last;
    for (last = *list; last->next; last = last->next)
      ;
    last->next = item;
  } else {
    *list = item;
  }
}


/*
 * Set Match object in the current service
 */
static void addmatch(Match_T ms, int actionnumber, int linenumber) {
  Match_T m;
  int     reg_return;

  ASSERT(ms);

  NEW(m);
#ifdef HAVE_REGEX_H
  NEW(m->regex_comp);
#endif

  m->match_string = ms->match_string;
  m->match_path   = ms->match_path ? Str_dup(ms->match_path) : NULL;
  m->action       = ms->action;
  m->not          = ms->not;
  m->ignore       = ms->ignore;
  m->next         = NULL;

  addeventaction(&(m->action), actionnumber, ACTION_IGNORE);

#ifdef HAVE_REGEX_H
  reg_return = regcomp(m->regex_comp, ms->match_string, REG_NOSUB|REG_EXTENDED);

  if (reg_return != 0) {
    char errbuf[STRLEN];
    regerror(reg_return, ms->regex_comp, errbuf, STRLEN);
    if (m->match_path != NULL)
      yyerror2("regex parsing error:%s on line %i of", errbuf, linenumber);
    else
      yyerror2("regex parsing error:%s", errbuf);
  }
#endif
  appendmatch(m->ignore ? &current->matchignorelist : &current->matchlist, m);
}


static void addmatchpath(Match_T ms, int actionnumber) {

  FILE *handle;
  command_t savecommand = NULL;
  char buf[2048];
  int linenumber = 0;

  ASSERT(ms->match_path);

  handle = fopen(ms->match_path, "r");
  if (handle == NULL) {
    yyerror2("cannot read regex match file (%s)", ms->match_path);
    return;
  }

  while (!feof(handle)) {
    size_t len;

    linenumber++;

    if (! fgets(buf, 2048, handle))
      continue;

    len = strlen(buf);

    if (len == 0 || buf[0] == '\n')
      continue;

    if (buf[len-1] == '\n')
      buf[len-1] = 0;

    ms->match_string = Str_dup(buf);

    /* The addeventaction() called from addmatch() will reset the
     * command1 to NULL, but we need to duplicate the command for
     * each line, thus need to save it here */
    if (actionnumber == ACTION_EXEC) {
      if (command1 == NULL) {
        ASSERT(savecommand);
        command1 = savecommand;
      }
      savecommand = copycommand(command1);
    }

    addmatch(ms, actionnumber, linenumber);
  }

  if (actionnumber == ACTION_EXEC && savecommand)
    gccmd(&savecommand);

  fclose(handle);
}


/*
 * Set exit status test object in the current service
 */
static void addstatus(Status_T status) {
        Status_T s;
        ASSERT(status);
        NEW(s);
        s->return_value = status->return_value;
        s->operator = status->operator;
        s->action = status->action;
        s->next = current->statuslist;
        current->statuslist = s;

        reset_statusset();
}


/*
 * Set Uid object in the current service
 */
static void adduid(Uid_T us) {
  Uid_T u;

  ASSERT(us);

  NEW(u);
  u->uid       = us->uid;
  u->action    = us->action;
  current->uid = u;
  reset_uidset();
}


/*
 * Set Gid object in the current service
 */
static void addgid(Gid_T gs) {
  Gid_T g;

  ASSERT(gs);

  NEW(g);
  g->gid       = gs->gid;
  g->action    = gs->action;
  current->gid = g;
  reset_gidset();
}


/*
 * Add a new filesystem to the current service's filesystem list
 */
static void addfilesystem(Filesystem_T ds) {
  Filesystem_T dev;

  ASSERT(ds);

  NEW(dev);
  dev->resource           = ds->resource;
  dev->operator           = ds->operator;
  dev->limit_absolute     = ds->limit_absolute;
  dev->limit_percent      = ds->limit_percent;
  dev->action             = ds->action;

  dev->next               = current->filesystemlist;
  current->filesystemlist = dev;

  reset_filesystemset();

}


/*
 * Add a new icmp object to the current service's icmp list
 */
static void addicmp(Icmp_T is) {
  Icmp_T icmp;

  ASSERT(is);

  NEW(icmp);
  icmp->type         = is->type;
  icmp->count        = is->count;
  icmp->timeout      = is->timeout;
  icmp->action       = is->action;
  icmp->is_available = FALSE;
  icmp->response     = -1;

  icmp->next         = current->icmplist;
  current->icmplist  = icmp;

  reset_icmpset();
}


/*
 * Set EventAction object
 */
static void addeventaction(EventAction_T *_ea, int failed, int succeeded) {
  EventAction_T ea;

  ASSERT(_ea);

  NEW(ea);
  NEW(ea->failed);
  NEW(ea->succeeded);

  ea->failed->id     = failed;
  ea->failed->count  = rate1.count;
  ea->failed->cycles = rate1.cycles;
  if (failed == ACTION_EXEC) {
    ASSERT(command1);
    ea->failed->exec = command1;
    command1 = NULL;
  }

  ea->succeeded->id     = succeeded;
  ea->succeeded->count  = rate2.count;
  ea->succeeded->cycles = rate2.cycles;
  if (succeeded == ACTION_EXEC) {
    ASSERT(command2);
    ea->succeeded->exec = command2;
    command2 = NULL;
  }
  *_ea = ea;
  reset_rateset();
}


/*
 * Redefine EventAction object (used for default action overloading)
 */
static void seteventaction(EventAction_T *_ea, int failed, int succeeded) {
  EventAction_T ea = *_ea;

  ASSERT(ea);
  ASSERT(ea->failed);
  ASSERT(ea->succeeded);

  ea->failed->id     = failed;
  ea->failed->count  = rate1.count;
  ea->failed->cycles = rate1.cycles;
  if (failed == ACTION_EXEC) {
    ASSERT(command1);
    ea->failed->exec = command1;
    command1 = NULL;
  }

  ea->succeeded->id     = succeeded;
  ea->succeeded->count  = rate2.count;
  ea->succeeded->cycles = rate2.cycles;
  if (succeeded == ACTION_EXEC) {
    ASSERT(command2);
    ea->succeeded->exec = command2;
    command2 = NULL;
  }
}


/*
 * Add a generic protocol handler to
 */
static void addgeneric(Port_T port, char *send, char *expect) {
  Generic_T g = port->generic;

  if (g == NULL) {
    NEW(g);
    port->generic = g;
  } else {
    while (g->next != NULL)
      g = g->next;
    NEW(g->next);
    g = g->next;
  }

  if (send != NULL) {
    g->send = Str_dup(send);
    g->expect = NULL;
  } else if (expect != NULL) {
#ifdef HAVE_REGEX_H

    int   reg_return;
    NEW(g->expect);
    reg_return = regcomp(g->expect, expect, REG_NOSUB|REG_EXTENDED);
    if (reg_return != 0) {
      char errbuf[STRLEN];
      regerror(reg_return, g->expect, errbuf, STRLEN);
      yyerror2("regex parsing error:%s", errbuf);
    }
#else
    g->expect = Str_dup(expect);
#endif
    g->send = NULL;
  }
}


/*
 * Add the current command object to the current service object's
 * start or stop program.
 */
static void addcommand(int what, unsigned timeout) {

  switch(what) {
          case START:   current->start = command; break;
          case STOP:    current->stop = command; break;
          case RESTART: current->restart = command; break;
  }

  command->timeout = timeout;

  command = NULL;

}


/*
 * Add a new argument to the argument list
 */
static void addargument(char *argument) {

  ASSERT(argument);

  if (! command) {

    NEW(command);
    check_exec(argument);

  }

  command->arg[command->length++] = argument;
  command->arg[command->length] = NULL;

  if (command->length >= ARGMAX)
    yyerror("exceeded maximum number of program arguments");

}


/*
 * Setup a url request for the current port object
 */
static void prepare_urlrequest(URL_T U) {

  ASSERT(U);

  portset.protocol = Protocol_get(Protocol_HTTP);

  if (urlrequest == NULL)
    NEW(urlrequest);
  urlrequest->url = U;
  portset.hostname = Str_dup(U->hostname);
  check_hostname(portset.hostname);
  portset.port = U->port;
  portset.url_request = urlrequest;
  portset.type = SOCK_STREAM;
  portset.request = Str_cat("%s%s%s", U->path, U->query ? "?" : "", U->query ? U->query : "");
  /* Only the HTTP protocol is supported for URLs.
     See also the lexer if this is to be changed in
     the future */
  portset.protocol = Protocol_get(Protocol_HTTP);
  if (IS(U->protocol, "https"))
    portset.SSL.use_ssl = TRUE;

}


/*
 * Set the url request for a port
 */
static void  seturlrequest(int operator, char *regex) {

  ASSERT(regex);

  if (! urlrequest)
    NEW(urlrequest);
  urlrequest->operator = operator;
#ifdef HAVE_REGEX_H
  {
    int reg_return;
    NEW(urlrequest->regex);
    reg_return = regcomp(urlrequest->regex, regex, REG_NOSUB|REG_EXTENDED);
    if (reg_return != 0) {
      char errbuf[STRLEN];
      regerror(reg_return, urlrequest->regex, errbuf, STRLEN);
      yyerror2("regex parsing error: %s", errbuf);
    }
  }
#else
  urlrequest->regex = Str_dup(regex);
#endif

}


/*
 * Add a new data recipient server to the mmonit server list
 */
static void addmmonit(URL_T url, int timeout, int sslversion, char *certmd5) {
  Mmonit_T c;

  ASSERT(url);

  NEW(c);
  c->url = url;
  if (!strcmp(c->url->protocol, "https")) {
    if (!have_ssl()) {
      yyerror("ssl check cannot be activated. SSL is not supported");
    } else {
      c->ssl.use_ssl = TRUE;
      c->ssl.version = (sslversion == SSL_VERSION_NONE) ? SSL_VERSION_AUTO : sslversion;
      if (certmd5) {
        c->ssl.certmd5 = certmd5;
        cleanup_hash_string(c->ssl.certmd5);
      }
    }
  }
  c->timeout = timeout;
  c->next = NULL;

  if (Run.mmonits) {
    Mmonit_T C;
    for (C = Run.mmonits; C->next; C = C->next)
      /* Empty */ ;
    C->next = c;
  } else {
    Run.mmonits = c;
  }
}


/*
 * Add a new smtp server to the mail server list
 */
static void addmailserver(MailServer_T mailserver) {

  MailServer_T s;

  ASSERT(mailserver->host);

  NEW(s);
  s->host        = mailserver->host;
  s->port        = mailserver->port;
  s->username    = mailserver->username;
  s->password    = mailserver->password;
  s->ssl.use_ssl = mailserver->ssl.use_ssl;
  s->ssl.version = mailserver->ssl.version;
  s->ssl.certmd5 = mailserver->ssl.certmd5;

  s->next = NULL;

  if (Run.mailservers) {
    MailServer_T l;
    for (l = Run.mailservers; l->next; l = l->next) /* empty */;
    l->next = s;
  } else {
    Run.mailservers = s;
  }

  reset_mailserverset();
}


/*
 * Return uid if found on the system. If the parameter user is NULL
 * the uid parameter is used for looking up the user id on the system,
 * otherwise the user parameter is used.
 */
static uid_t get_uid(char *user, uid_t uid) {
  struct passwd *pwd;

  if (user) {
    pwd = getpwnam(user);

    if (pwd == NULL) {
      yyerror2("requested user not found on the system");
      return(0);
    }

  } else {

    if ( (pwd = getpwuid(uid)) == NULL ) {
      yyerror2("requested uid not found on the system");
      return(0);
    }
  }

  return(pwd->pw_uid);

}


/*
 * Return gid if found on the system. If the parameter group is NULL
 * the gid parameter is used for looking up the group id on the system,
 * otherwise the group parameter is used.
 */
static gid_t get_gid(char *group, gid_t gid) {
  struct group *grd;

  if (group) {
    grd = getgrnam(group);

    if (grd == NULL) {
      yyerror2("requested group not found on the system");
      return(0);
    }

  } else {

    if ( (grd = getgrgid(gid)) == NULL ) {
      yyerror2("requested gid not found on the system");
      return(0);
    }

  }

  return(grd->gr_gid);

}


/*
 * Add a new user id to the current command object.
 */
static void addeuid(uid_t uid) {
  if (!getuid()) {
    command->has_uid = TRUE;
    command->uid = uid;
  } else
    yyerror("uid statement requires root privileges");
}


/*
 * Add a new group id to the current command object.
 */
static void addegid(gid_t gid) {
  if (!getuid()) {
    command->has_gid = TRUE;
    command->gid = gid;
  } else
    yyerror("gid statement requires root privileges");
}


/*
 * Reset the logfile if changed
 */
static void setlogfile(char *logfile) {
  if (Run.logfile) {
    if (IS(Run.logfile, logfile)) {
      FREE(logfile);
      return;
    } else
      FREE(Run.logfile);
  }
  Run.logfile = logfile;
}


/*
 * Reset the pidfile if changed
 */
static void setpidfile(char *pidfile) {
  if (Run.pidfile) {
    if (IS(Run.pidfile, pidfile)) {
      FREE(pidfile);
      return;
    } else
      FREE(Run.pidfile);
  }
  Run.pidfile = pidfile;
}


/*
 * Read a apache htpasswd file and add credentials found for username
 */
static void addhtpasswdentry(char *filename, char *username, int dtype) {
  char *ht_username = NULL;
  char *ht_passwd = NULL;
  char buf[STRLEN];
  FILE *handle = NULL;
  int credentials_added = 0;

  ASSERT(filename);

  handle = fopen(filename, "r");

  if ( handle == NULL ) {
    if (username != NULL)
      yyerror2("cannot read htpasswd (%s)", filename);
    else
      yyerror2("cannot read htpasswd", filename);
    return;
  }

  while (!feof(handle)) {
    char *colonindex = NULL;
    int i;

    if (! fgets(buf, STRLEN, handle))
      continue;

    /* strip trailing non visible characters */
    for (i = (int)strlen(buf)-1; i >= 0; i--) {
      if ( buf[i] == ' '  || buf[i] == '\r' || buf[i] == '\n' || buf[i] == '\t' )
        buf[i] ='\0';
      else
        break;
    }

    if ( NULL == (colonindex = strchr(buf, ':')))
      continue;

    ht_passwd = Str_dup(colonindex+1);
    *colonindex = '\0';

    /* In case we have a file in /etc/passwd or /etc/shadow style we
     *  want to remove ":.*$" and Crypt and MD5 hashed dont have a colon
     */

    if ( (NULL != (colonindex = strchr(ht_passwd, ':'))) && ( dtype != DIGEST_CLEARTEXT) )
      *colonindex = '\0';

    ht_username = Str_dup(buf);

    if (username == NULL) {
      if (addcredentials(ht_username, ht_passwd, dtype, FALSE))
        credentials_added++;
    } else if (strcmp(username, ht_username) == 0)  {
      if (addcredentials(ht_username, ht_passwd, dtype, FALSE))
        credentials_added++;
    } else {
      FREE(ht_passwd);
      FREE(ht_username);
    }
  }

  if (credentials_added == 0) {
    if ( username == NULL )
      yywarning2("htpasswd file (%s) has no usable credentials", filename);
    else
      yywarning2("htpasswd file (%s) has no usable credentials for user %s", filename, username);
  }
  fclose(handle);
}


#ifdef HAVE_LIBPAM
static void addpamauth(char* groupname, int readonly) {
  Auth_T c = NULL;
  Auth_T prev = NULL;

  ASSERT(groupname);

  if (Run.credentials == NULL)
    NEW(Run.credentials);

  c = Run.credentials;
  do {
    if (c->groupname != NULL && IS(c->groupname, groupname)) {
      yywarning2("PAM group %s was added already, entry ignored", groupname);
      FREE(groupname);
      return;
    }
    prev = c;
    c = c->next;
  } while (c != NULL);

  NEW(prev->next);
  c = prev->next;

  c->next        = NULL;
  c->uname       = NULL;
  c->passwd      = NULL;
  c->groupname   = groupname;
  c->digesttype  = DIGEST_PAM;
  c->is_readonly = readonly;

  DEBUG("%s: Adding PAM group '%s'.\n", prog, groupname);

  return;
}
#endif


/*
 * Add Basic Authentication credentials
 */
static int addcredentials(char *uname, char *passwd, int dtype, int readonly) {
  Auth_T c;

  ASSERT(uname);
  ASSERT(passwd);

  if (Run.credentials == NULL) {
    NEW(Run.credentials);
    c = Run.credentials;
  } else {

    if (Util_getUserCredentials(uname) != NULL) {
      yywarning2("credentials for user %s were already added, entry ignored", uname);
      FREE(uname);
      FREE(passwd);
      return FALSE;
    }

    c = Run.credentials;

    while ( c->next != NULL )
      c = c->next;

    NEW(c->next);
    c = c->next;

  }

  c->next        = NULL;
  c->uname       = uname;
  c->passwd      = passwd;
  c->groupname   = NULL;
  c->digesttype  = dtype;
  c->is_readonly = readonly;

  DEBUG("%s: Debug: Adding credentials for user '%s'.\n", prog, uname);

  return TRUE;

}


/*
 * Set the syslog and the facilities to be used
 */
static void setsyslog(char *facility) {

  if (!Run.logfile || ihp.logfile) {
    ihp.logfile = TRUE;
    setlogfile(Str_dup("syslog"));
    Run.use_syslog = TRUE;
    Run.dolog = TRUE;
  }

  if (facility) {
    if (IS(facility,"log_local0"))
      Run.facility = LOG_LOCAL0;
    else if (IS(facility, "log_local1"))
      Run.facility = LOG_LOCAL1;
    else if (IS(facility, "log_local2"))
      Run.facility = LOG_LOCAL2;
    else if (IS(facility, "log_local3"))
      Run.facility = LOG_LOCAL3;
    else if (IS(facility, "log_local4"))
      Run.facility = LOG_LOCAL4;
    else if (IS(facility, "log_local5"))
      Run.facility = LOG_LOCAL5;
    else if (IS(facility, "log_local6"))
      Run.facility = LOG_LOCAL6;
    else if (IS(facility, "log_local7"))
      Run.facility = LOG_LOCAL7;
    else if (IS(facility, "log_daemon"))
      Run.facility = LOG_DAEMON;
    else
      yyerror2("invalid syslog facility");
  } else {
    Run.facility = LOG_USER;
  }

}


/*
 * Reset the current mailset for reuse
 */
static void reset_mailset() {
  memset(&mailset, 0, sizeof(struct mymail));
}


/*
 * Reset the mailserver set to default values
 */
static void reset_mailserverset() {
  memset(&mailserverset, 0, sizeof(struct mymailserver));
  mailserverset.port = PORT_SMTP;
  mailserverset.ssl.use_ssl = FALSE;
  mailserverset.ssl.version = SSL_VERSION_AUTO;
}


/*
 * Reset the Port set to default values
 */
static void reset_portset() {
  memset(&portset, 0, sizeof(struct myport));
  portset.socket = -1;
  portset.type = SOCK_STREAM;
  portset.family = AF_INET;
  portset.SSL.version = SSL_VERSION_AUTO;
  portset.timeout = NET_TIMEOUT;
  portset.retry = 1;
  portset.maxforward = 70;
  urlrequest = NULL;
}


/*
 * Reset the Proc set to default values
 */
static void reset_resourceset() {
  resourceset.resource_id = 0;
  resourceset.limit = 0;
  resourceset.action = NULL;
  resourceset.operator = Operator_Equal;
}


/*
 * Reset the Timestamp set to default values
 */
static void reset_timestampset() {
  timestampset.operator = Operator_Equal;
  timestampset.time = 0;
  timestampset.test_changes = FALSE;
  timestampset.action = NULL;
}


/*
 * Reset the ActionRate set to default values
 */
static void reset_actionrateset() {
  actionrateset.count = 0;
  actionrateset.cycle = 0;
  actionrateset.action = NULL;
}


/*
 * Reset the Size set to default values
 */
static void reset_sizeset() {
  sizeset.operator = Operator_Equal;
  sizeset.size = 0;
  sizeset.test_changes = FALSE;
  sizeset.action = NULL;
}


/*
 * Reset the Uptime set to default values
 */
static void reset_uptimeset() {
  uptimeset.operator = Operator_Equal;
  uptimeset.uptime = 0;
  uptimeset.action = NULL;
}


/*
 * Reset the Checksum set to default values
 */
static void reset_checksumset() {
  checksumset.type         = HASH_UNKNOWN;
  checksumset.test_changes = FALSE;
  checksumset.action       = NULL;
  *checksumset.hash        = 0;
}


/*
 * Reset the Perm set to default values
 */
static void reset_permset() {
  permset.perm = 0;
  permset.action = NULL;
}


/*
 * Reset the Status set to default values
 */
static void reset_statusset() {
        statusset.return_value = 0;
        statusset.operator = Operator_Equal;
        statusset.action = NULL;
}


/*
 * Reset the Uid set to default values
 */
static void reset_uidset() {
  uidset.uid = 0;
  uidset.action = NULL;
}


/*
 * Reset the Gid set to default values
 */
static void reset_gidset() {
  gidset.gid = 0;
  gidset.action = NULL;
}


/*
 * Reset the Filesystem set to default values
 */
static void reset_filesystemset() {
  filesystemset.resource = 0;
  filesystemset.operator = Operator_Equal;
  filesystemset.limit_absolute = -1;
  filesystemset.limit_percent = -1;
  filesystemset.action = NULL;
}


/*
 * Reset the ICMP set to default values
 */
static void reset_icmpset() {
  icmpset.type = ICMP_ECHO;
  icmpset.count = ICMP_ATTEMPT_COUNT;
  icmpset.timeout = NET_TIMEOUT;
  icmpset.action = NULL;
}


/*
 * Reset the Rate set to default values
 */
static void reset_rateset() {
  rate1.count  = 1;
  rate1.cycles = 1;

  rate2.count  = 1;
  rate2.cycles = 1;
}


/* ---------------------------------------------------------------- Checkers */


/*
 * Check for unique service name
 */
static void check_name(char *name) {
  ASSERT(name);

  if (Util_existService(name) || (current && IS(name, current->name)))
    yyerror2("service name conflict, %s already defined", name);
  if (name && *name == '/')
          yyerror2("service name '%s' must not start with '/' -- ", name);
}


/*
 * Permission statement semantic check
 */
static int check_perm(int perm) {
  int result;
  char *status;
  char buf[STRLEN];

  snprintf(buf, STRLEN, "%d", perm);

  result = (int)strtol(buf, &status, 8);

  if ( *status != '\0' || result < 0 || result > 07777 )
    yyerror2("permission statements must have an octal value between 0 and 7777");

  return result;
}


/*
 * Check hostname
 */
static void check_hostname(char *hostname) {

  ASSERT(hostname);

  if (!check_host(hostname))
    yywarning2("hostname did not resolve");
}

/*
 * Check the dependency graph for errors
 * by doing a topological sort, thereby finding any cycles.
 * Assures that graph is a Directed Acyclic Graph (DAG).
 */
static void check_depend() {
  Service_T s;
  Service_T depends_on = NULL;
  Service_T* dlt = &depend_list; /* the current tail of it                                 */
  int done;                      /* no unvisited nodes left?                               */
  int found_some;                /* last iteration found anything new ?                    */
  depend_list = NULL;            /* depend_list will be the topological sorted servicelist */

  do {
    done = TRUE;
    found_some = FALSE;
    for (s = servicelist; s; s = s->next) {
        Dependant_T d;
      if (s->visited)
          continue;
      done = FALSE; // still unvisited nodes
      depends_on = NULL;
      for (d = s->dependantlist; d; d = d->next) {
        Service_T dp = Util_getService(d->dependant);
        if (!dp) {
          LogError("%s: Error: Depend service '%s' is not defined in the control file\n", prog, d->dependant);
          exit(1);
        }
        if (!dp->visited) {
          depends_on = dp;
        }
      }

      if (!depends_on) {
        s->visited = TRUE;
        found_some = TRUE;
        *dlt = s;
        dlt = &s->next_depend;
      }
    }
  } while (found_some && !done);

  if (!done) {
        ASSERT(depends_on);
        LogError("%s: Error: Found a depend loop in the control file involving the service '%s'\n", prog, depends_on->name);
        exit(1);
   }

  ASSERT(depend_list);
  servicelist = depend_list;

  for (s = depend_list; s; s = s->next_depend)
    s->next = s->next_depend;

  reset_depend();
}


/*
 * Check if the executable exist
 */
static void check_exec(char *exec) {
        if (! File_exist(exec))
                yywarning2("Program does not exist:");
        else if (! File_isExecutable(exec))
                yywarning2("Program is not executable:");
}


/* Return a valid max forward value for SIP header */
static int verifyMaxForward(int mf) {
  int max = 70;

  if (mf >= 0 && mf <= 255)
    max = mf;
  else
    yywarning2("SIP max forward is outside the range [0..255]. Setting max forward to 70");

  return max;
}


/* -------------------------------------------------------------------- Misc */


/*
 * Cleans up an md5 string, tolower and remove byte separators
 */
static int cleanup_hash_string(char *hashstring) {
  int i = 0, j = 0;

  ASSERT(hashstring);

  while (hashstring[i] != '\0') {
    if (isxdigit((int) hashstring[i])) {
      hashstring[j] = tolower((int)hashstring[i]);
      j++;
    }
    i++;
  }
  hashstring[j] = '\0';
  return j;
}


/* Return deep copy of the command */
static command_t copycommand(command_t source) {
  int i;
  command_t copy = NULL;

  NEW(copy);
  copy->length = source->length;
  copy->has_uid = source->has_uid;
  copy->uid = source->uid;
  copy->has_gid = source->has_gid;
  copy->gid = source->gid;
  copy->timeout = source->timeout;
  for (i = 0; i < copy->length; i++)
     copy->arg[i] = Str_dup(source->arg[i]);
  copy->arg[copy->length] = NULL;

  return copy;
}


