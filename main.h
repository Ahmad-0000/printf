#ifndef MAIN_H
#define MAIN_H
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024
#include <stdarg.h>
#include <unistd.h>

typedef struct conspc
{
	int cs;
	int fg1; /* 0 and - */
	int fg2; /* + and ' ' */
	int fg3; /* # */
	int width;
	int precision;
	char lmod;
	int len;
} conspc_t;

typedef struct csfun {
	char cs;
	int (*fun)(conspc_t *conspc, char *buff, int *bpos, va_list ap);
} csfun_t;

int _printf(const char *fmt, ...);
int _strlen(char *c);
conspc_t *getcs(const char **fmt);
int handd(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handc(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int hands(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handr(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handb(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handu(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int hando(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handS(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handR(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handxX(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handp(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handper(conspc_t *conspc, char *buff, int *bpos, va_list ap);
int handwidth(conspc_t *conspc, char *buff, int *bpos, char *num, int arpos);
char *handpre(conspc_t *conspc, char *val);
void handnormal(const char **fmt, int *wrtnchar, char *buff, int *bpos);
char xorX(char x, unsigned int remainder);
int countargs(const char *fmt);
int (*getcsfun(char c))(conspc_t *conspc, char *buff, int *bpos, va_list ap);
void _fflush(char *buff, int *n);
#endif
