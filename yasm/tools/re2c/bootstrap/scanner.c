/* Generated by re2c 0.9.1-C on Sun Oct  9 22:15:58 2005
 */
#line 1 "scanner.re"
#include <stdlib.h>
#include <string.h>
#include "tools/re2c/scanner.h"
#include "tools/re2c/parse.h"
#include "tools/re2c/globals.h"
#include "re2c-parser.h"

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#define	BSIZE	8192

#define	YYCTYPE		unsigned char
#define	YYCURSOR	cursor
#define	YYLIMIT		s->lim
#define	YYMARKER	s->ptr
#define	YYFILL(n)	{cursor = fill(s, cursor);}

#define	RETURN(i)	{s->cur = cursor; return i;}

static unsigned char *fill(Scanner*, unsigned char*);

void
Scanner_init(Scanner *s, FILE *i)
{
    s->in = i;
    s->bot = s->tok = s->ptr = s->cur = s->pos = s->lim = s->top =
	     s->eof = NULL;
    s->tchar = s->tline = 0;
    s->cline = 1;
}

static unsigned char *
fill(Scanner *s, unsigned char *cursor)
{
    if(!s->eof){
	unsigned int cnt = s->tok - s->bot;
	if(cnt){
	    memcpy(s->bot, s->tok, s->lim - s->tok);
	    s->tok = s->bot;
	    s->ptr -= cnt;
	    cursor -= cnt;
	    s->pos -= cnt;
	    s->lim -= cnt;
	}
	if((s->top - s->lim) < BSIZE){
	    unsigned char *buf = malloc(((s->lim - s->bot) + BSIZE));
	    memcpy(buf, s->tok, s->lim - s->tok);
	    s->tok = buf;
	    s->ptr = &buf[s->ptr - s->bot];
	    cursor = &buf[cursor - s->bot];
	    s->pos = &buf[s->pos - s->bot];
	    s->lim = &buf[s->lim - s->bot];
	    s->top = &s->lim[BSIZE];
	    if (s->bot)
		free(s->bot);
	    s->bot = buf;
	}
	if((cnt = fread(s->lim, 1, BSIZE, s->in)) != BSIZE){
	    s->eof = &s->lim[cnt]; *s->eof++ = '\0';
	}
	s->lim += cnt;
    }
    return cursor;
}

#line 79 "scanner.re"


int
Scanner_echo(Scanner *s, FILE *out)
{
    unsigned char *cursor = s->cur;
    int ignore_eoc = 0;

    /* Catch EOF */
    if (s->eof && cursor == s->eof)
	return 0;

    s->tok = cursor;
echo:

#line 87 "scanner.c"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy0;
	++YYCURSOR;
yy0:
	if((YYLIMIT - YYCURSOR) < 11) YYFILL(11);
	yych = *YYCURSOR;
	if(yych <= ')'){
		if(yych <= '\000')	goto yy7;
		if(yych == '\n')	goto yy5;
		goto yy9;
	} else {
		if(yych <= '*')	goto yy4;
		if(yych != '/')	goto yy9;
		goto yy2;
	}
yy2:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == '*')	goto yy12;
	goto yy3;
yy3:
#line 117 "scanner.re"
{ goto echo; }
#line 112 "scanner.c"
yy4:	yych = *++YYCURSOR;
	if(yych == '/')	goto yy10;
	goto yy3;
yy5:	yych = *++YYCURSOR;
	goto yy6;
yy6:
#line 112 "scanner.re"
{ fwrite(s->tok, 1, cursor - s->tok, out);
				  s->tok = s->pos = cursor; s->cline++; oline++;
				  goto echo; }
#line 123 "scanner.c"
yy7:	yych = *++YYCURSOR;
	goto yy8;
yy8:
#line 115 "scanner.re"
{ fwrite(s->tok, 1, cursor - s->tok - 1, out); /* -1 so we don't write out the \0 */
				  if(cursor == s->eof) { RETURN(0); } }
#line 130 "scanner.c"
yy9:	yych = *++YYCURSOR;
	goto yy3;
yy10:	yych = *++YYCURSOR;
	goto yy11;
yy11:
#line 103 "scanner.re"
{
		if (ignore_eoc) {
		    ignore_eoc = 0;
		} else {
		    fwrite(s->tok, 1, cursor - s->tok, out);
		}
		s->tok = s->pos = cursor;
		goto echo;
	}
#line 146 "scanner.c"
yy12:	yych = *++YYCURSOR;
	if(yych == '!')	goto yy14;
	goto yy13;
yy13:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy3;
	}
yy14:	yych = *++YYCURSOR;
	if(yych == 'm')	goto yy15;
	if(yych == 'r')	goto yy16;
	goto yy13;
yy15:	yych = *++YYCURSOR;
	if(yych == 'a')	goto yy21;
	goto yy13;
yy16:	yych = *++YYCURSOR;
	if(yych != 'e')	goto yy13;
	goto yy17;
yy17:	yych = *++YYCURSOR;
	if(yych != '2')	goto yy13;
	goto yy18;
yy18:	yych = *++YYCURSOR;
	if(yych != 'c')	goto yy13;
	goto yy19;
yy19:	yych = *++YYCURSOR;
	goto yy20;
yy20:
#line 94 "scanner.re"
{ fwrite(s->tok, 1, &cursor[-7] - s->tok, out);
				  s->tok = cursor;
				  RETURN(1); }
#line 177 "scanner.c"
yy21:	yych = *++YYCURSOR;
	if(yych != 'x')	goto yy13;
	goto yy22;
yy22:	yych = *++YYCURSOR;
	if(yych != ':')	goto yy13;
	goto yy23;
yy23:	yych = *++YYCURSOR;
	if(yych != 'r')	goto yy13;
	goto yy24;
yy24:	yych = *++YYCURSOR;
	if(yych != 'e')	goto yy13;
	goto yy25;
yy25:	yych = *++YYCURSOR;
	if(yych != '2')	goto yy13;
	goto yy26;
yy26:	yych = *++YYCURSOR;
	if(yych != 'c')	goto yy13;
	goto yy27;
yy27:	yych = *++YYCURSOR;
	goto yy28;
yy28:
#line 97 "scanner.re"
{
		fprintf(out, "#define YYMAXFILL %u\n", maxFill);
		s->tok = s->pos = cursor;
		ignore_eoc = 1;
		goto echo;
	}
#line 206 "scanner.c"
}
#line 118 "scanner.re"

}


int
Scanner_scan(Scanner *s)
{
    unsigned char *cursor = s->cur;
    unsigned int depth;

scan:
    s->tchar = cursor - s->pos;
    s->tline = s->cline;
    s->tok = cursor;

#line 224 "scanner.c"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy29;
	++YYCURSOR;
yy29:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '/'){
		if(yych <= '"'){
			if(yych <= '\n'){
				if(yych <= '\b')	goto yy53;
				if(yych <= '\t')	goto yy47;
				goto yy49;
			} else {
				if(yych == ' ')	goto yy47;
				if(yych <= '!')	goto yy53;
				goto yy37;
			}
		} else {
			if(yych <= '*'){
				if(yych <= '&')	goto yy53;
				if(yych <= '\'')	goto yy39;
				if(yych <= ')')	goto yy43;
				goto yy35;
			} else {
				if(yych <= '+')	goto yy44;
				if(yych <= '-')	goto yy53;
				if(yych <= '.')	goto yy51;
				goto yy33;
			}
		}
	} else {
		if(yych <= '@'){
			if(yych <= '<'){
				if(yych == ';')	goto yy43;
				goto yy53;
			} else {
				if(yych <= '=')	goto yy43;
				if(yych == '?')	goto yy44;
				goto yy53;
			}
		} else {
			if(yych <= '`'){
				if(yych <= 'Z')	goto yy45;
				if(yych <= '[')	goto yy41;
				if(yych <= '\\')	goto yy43;
				goto yy53;
			} else {
				if(yych <= 'z')	goto yy45;
				if(yych <= '{')	goto yy31;
				if(yych <= '|')	goto yy43;
				goto yy53;
			}
		}
	}
yy31:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych <= '/')	goto yy32;
	if(yych <= '9')	goto yy84;
	goto yy32;
yy32:
#line 133 "scanner.re"
{ depth = 1;
				  goto code;
				}
#line 291 "scanner.c"
yy33:	yych = *++YYCURSOR;
	if(yych == '*')	goto yy82;
	goto yy34;
yy34:
#line 163 "scanner.re"
{ RETURN(*s->tok); }
#line 298 "scanner.c"
yy35:	yych = *++YYCURSOR;
	if(yych == '/')	goto yy80;
	goto yy36;
yy36:
#line 165 "scanner.re"
{ yylval.op = *s->tok;
				  RETURN(CLOSE); }
#line 306 "scanner.c"
yy37:	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych != '\n')	goto yy76;
	goto yy38;
yy38:
#line 150 "scanner.re"
{ Scanner_fatal(s, "unterminated string constant (missing \")"); }
#line 314 "scanner.c"
yy39:	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych != '\n')	goto yy71;
	goto yy40;
yy40:
#line 151 "scanner.re"
{ Scanner_fatal(s, "unterminated string constant (missing ')"); }
#line 322 "scanner.c"
yy41:	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == '\n')	goto yy42;
	if(yych == '^')	goto yy62;
	goto yy60;
yy42:
#line 161 "scanner.re"
{ Scanner_fatal(s, "unterminated range (missing ])"); }
#line 331 "scanner.c"
yy43:	yych = *++YYCURSOR;
	goto yy34;
yy44:	yych = *++YYCURSOR;
	goto yy36;
yy45:	yych = *++YYCURSOR;
	goto yy58;
yy46:
#line 180 "scanner.re"
{ SubStr substr;
				  s->cur = cursor;
				  substr = Scanner_token(s);
				  yylval.symbol = Symbol_find(&substr);
				  return ID; }
#line 345 "scanner.c"
yy47:	yych = *++YYCURSOR;
	goto yy56;
yy48:
#line 186 "scanner.re"
{ goto scan; }
#line 351 "scanner.c"
yy49:	yych = *++YYCURSOR;
	goto yy50;
yy50:
#line 188 "scanner.re"
{ if(cursor == s->eof) RETURN(0);
				  s->pos = cursor; s->cline++;
				  goto scan;
	    			}
#line 360 "scanner.c"
yy51:	yych = *++YYCURSOR;
	goto yy52;
yy52:
#line 193 "scanner.re"
{ s->cur = cursor;
				  yylval.regexp = mkDot();
				  return RANGE;
				}
#line 369 "scanner.c"
yy53:	yych = *++YYCURSOR;
	goto yy54;
yy54:
#line 198 "scanner.re"
{ fprintf(stderr, "unexpected character: '%c'\n", *s->tok);
				  goto scan;
				}
#line 377 "scanner.c"
yy55:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy56;
yy56:	if(yych == '\t')	goto yy55;
	if(yych == ' ')	goto yy55;
	goto yy48;
yy57:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy58;
yy58:	if(yych <= '@'){
		if(yych <= '/')	goto yy46;
		if(yych <= '9')	goto yy57;
		goto yy46;
	} else {
		if(yych <= 'Z')	goto yy57;
		if(yych <= '`')	goto yy46;
		if(yych <= 'z')	goto yy57;
		goto yy46;
	}
yy59:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy60;
yy60:	if(yych <= '['){
		if(yych != '\n')	goto yy59;
		goto yy61;
	} else {
		if(yych <= '\\')	goto yy64;
		if(yych <= ']')	goto yy65;
		goto yy59;
	}
yy61:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy32;
	case 1:	goto yy38;
	case 2:	goto yy40;
	case 3:	goto yy42;
	}
yy62:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy63;
yy63:	if(yych <= '['){
		if(yych == '\n')	goto yy61;
		goto yy62;
	} else {
		if(yych <= '\\')	goto yy67;
		if(yych <= ']')	goto yy68;
		goto yy62;
	}
yy64:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == '\n')	goto yy61;
	goto yy59;
yy65:	yych = *++YYCURSOR;
	goto yy66;
yy66:
#line 157 "scanner.re"
{ s->cur = cursor;
				  yylval.regexp = ranToRE(Scanner_token(s));
				  return RANGE; }
#line 442 "scanner.c"
yy67:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == '\n')	goto yy61;
	goto yy62;
yy68:	yych = *++YYCURSOR;
	goto yy69;
yy69:
#line 153 "scanner.re"
{ s->cur = cursor;
				  yylval.regexp = invToRE(Scanner_token(s));
				  return RANGE; }
#line 455 "scanner.c"
yy70:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy71;
yy71:	if(yych <= '&'){
		if(yych == '\n')	goto yy61;
		goto yy70;
	} else {
		if(yych <= '\'')	goto yy73;
		if(yych != '\\')	goto yy70;
		goto yy72;
	}
yy72:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == '\n')	goto yy61;
	goto yy70;
yy73:	yych = *++YYCURSOR;
	goto yy74;
yy74:
#line 146 "scanner.re"
{ s->cur = cursor;
				  yylval.regexp = strToCaseInsensitiveRE(Scanner_token(s));
				  return STRING; }
#line 480 "scanner.c"
yy75:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy76;
yy76:	if(yych <= '!'){
		if(yych == '\n')	goto yy61;
		goto yy75;
	} else {
		if(yych <= '"')	goto yy78;
		if(yych != '\\')	goto yy75;
		goto yy77;
	}
yy77:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == '\n')	goto yy61;
	goto yy75;
yy78:	yych = *++YYCURSOR;
	goto yy79;
yy79:
#line 142 "scanner.re"
{ s->cur = cursor;
				  yylval.regexp = strToRE(Scanner_token(s));
				  return STRING; }
#line 505 "scanner.c"
yy80:	yych = *++YYCURSOR;
	goto yy81;
yy81:
#line 139 "scanner.re"
{ s->tok = cursor;
				  RETURN(0); }
#line 512 "scanner.c"
yy82:	yych = *++YYCURSOR;
	goto yy83;
yy83:
#line 136 "scanner.re"
{ depth = 1;
				  goto comment; }
#line 519 "scanner.c"
yy84:	++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	goto yy85;
yy85:	if(yych <= '/'){
		if(yych == ',')	goto yy88;
		goto yy61;
	} else {
		if(yych <= '9')	goto yy84;
		if(yych != '}')	goto yy61;
		goto yy86;
	}
yy86:	yych = *++YYCURSOR;
	goto yy87;
yy87:
#line 168 "scanner.re"
{ yylval.extop.minsize = atoi((char *)s->tok+1);
				  yylval.extop.maxsize = atoi((char *)s->tok+1);
				  RETURN(CLOSESIZE); }
#line 539 "scanner.c"
yy88:	yych = *++YYCURSOR;
	if(yych != '}')	goto yy92;
	goto yy89;
yy89:	yych = *++YYCURSOR;
	goto yy90;
yy90:
#line 176 "scanner.re"
{ yylval.extop.minsize = atoi((char *)s->tok+1);
				  yylval.extop.maxsize = -1;
				  RETURN(CLOSESIZE); }
#line 550 "scanner.c"
yy91:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy92;
yy92:	if(yych <= '/')	goto yy61;
	if(yych <= '9')	goto yy91;
	if(yych != '}')	goto yy61;
	goto yy93;
yy93:	yych = *++YYCURSOR;
	goto yy94;
yy94:
#line 172 "scanner.re"
{ yylval.extop.minsize = atoi((char *)s->tok+1);
				  yylval.extop.maxsize = MAX(yylval.extop.minsize,atoi(strchr((char *)s->tok, ',')+1));
				  RETURN(CLOSESIZE); }
#line 566 "scanner.c"
}
#line 201 "scanner.re"


code:

#line 573 "scanner.c"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy95;
	++YYCURSOR;
yy95:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '&'){
		if(yych <= '\n'){
			if(yych <= '\t')	goto yy103;
			goto yy101;
		} else {
			if(yych == '"')	goto yy105;
			goto yy103;
		}
	} else {
		if(yych <= '{'){
			if(yych <= '\'')	goto yy106;
			if(yych <= 'z')	goto yy103;
			goto yy99;
		} else {
			if(yych != '}')	goto yy103;
			goto yy97;
		}
	}
yy97:	yych = *++YYCURSOR;
	goto yy98;
yy98:
#line 205 "scanner.re"
{ if(--depth == 0){
					s->cur = cursor;
					yylval.token = Token_new(Scanner_token(s), s->tline);
					return CODE;
				  }
				  goto code; }
#line 610 "scanner.c"
yy99:	yych = *++YYCURSOR;
	goto yy100;
yy100:
#line 211 "scanner.re"
{ ++depth;
				  goto code; }
#line 617 "scanner.c"
yy101:	yych = *++YYCURSOR;
	goto yy102;
yy102:
#line 213 "scanner.re"
{ if(cursor == s->eof) Scanner_fatal(s, "missing '}'");
				  s->pos = cursor; s->cline++;
				  goto code;
				}
#line 626 "scanner.c"
yy103:	yych = *++YYCURSOR;
	goto yy104;
yy104:
#line 217 "scanner.re"
{ goto code; }
#line 632 "scanner.c"
yy105:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == '\n')	goto yy104;
	goto yy112;
yy106:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == '\n')	goto yy104;
	goto yy108;
yy107:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy108;
yy108:	if(yych <= '&'){
		if(yych != '\n')	goto yy107;
		goto yy109;
	} else {
		if(yych <= '\'')	goto yy103;
		if(yych == '\\')	goto yy110;
		goto yy107;
	}
yy109:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy104;
	}
yy110:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == '\n')	goto yy109;
	goto yy107;
yy111:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy112;
yy112:	if(yych <= '!'){
		if(yych == '\n')	goto yy109;
		goto yy111;
	} else {
		if(yych <= '"')	goto yy103;
		if(yych != '\\')	goto yy111;
		goto yy113;
	}
yy113:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == '\n')	goto yy109;
	goto yy111;
}
#line 218 "scanner.re"


comment:

#line 685 "scanner.c"
{
	YYCTYPE yych;
	goto yy114;
	++YYCURSOR;
yy114:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= ')'){
		if(yych == '\n')	goto yy119;
		goto yy121;
	} else {
		if(yych <= '*')	goto yy116;
		if(yych == '/')	goto yy118;
		goto yy121;
	}
yy116:	yych = *++YYCURSOR;
	if(yych == '/')	goto yy124;
	goto yy117;
yy117:
#line 232 "scanner.re"
{ goto comment; }
#line 707 "scanner.c"
yy118:	yych = *++YYCURSOR;
	if(yych == '*')	goto yy122;
	goto yy117;
yy119:	yych = *++YYCURSOR;
	goto yy120;
yy120:
#line 228 "scanner.re"
{ if(cursor == s->eof) RETURN(0);
				  s->tok = s->pos = cursor; s->cline++;
				  goto comment;
				}
#line 719 "scanner.c"
yy121:	yych = *++YYCURSOR;
	goto yy117;
yy122:	yych = *++YYCURSOR;
	goto yy123;
yy123:
#line 226 "scanner.re"
{ ++depth;
				  goto comment; }
#line 728 "scanner.c"
yy124:	yych = *++YYCURSOR;
	goto yy125;
yy125:
#line 222 "scanner.re"
{ if(--depth == 0)
					goto scan;
				    else
					goto comment; }
#line 737 "scanner.c"
}
#line 233 "scanner.re"

}

void
Scanner_fatal(Scanner *s, const char *msg)
{
    fprintf(stderr, "line %d, column %d: %s\n", s->tline, s->tchar + 1, msg);
    exit(1);
}
