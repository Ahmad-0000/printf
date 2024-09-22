#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *fmt, ...);
int _strlen(char *c);
int s_Handling(va_list ptr, int argnum, int *fpos, char *mb, int *bpos);
int c_Handling(va_list ptr, int argnum, int *fpos, char *mb, int *bpos);
int per_Handling(int *fpos, char *mb, int *bpos);
void NormalText(const char *F, int *fpos, int *pc, char *mb, int *bpos);
int countargs(const char *fmt);
int opDeterminer(const char *F, int *A, int *fpos, va_list P, char *bm, int *bpos);
int id_handling(va_list ap, int argnum, int *fpos, char *mb, int *bpos);
int u_Handling(va_list ap, int argnum, int *fpos, char *mb, int *bpos);
int o_Handling(va_list ap, int argnum, int *fpos, char *mb, int *bpos);
int binaryHandling(va_list ap, int argnum, int *fpos, char *mb, int *bpos);
int xX_Handling(va_list ap, int A, char C, int *fpos, char *mb, int *bpos);
void printing(char *buff, int *bpos);
int S_Handling(va_list ap, int A, int *fpos, char *mb, int *bpos);
char theCaseFun(char x, unsigned long int xx);
int pointers(va_list ap, int A, int *fpos, char *mb, int *bpos);
int finally(char c, int *fpos, char *mb, int *bpos);
#endif
