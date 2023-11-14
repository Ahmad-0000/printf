#ifndef THISFILE
#define THISFILE
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *theFormat, ...);
int _strlen(char *c);
int s_Handling(va_list ptr, int theArgNum, int *fp, char *mb, int *bp);
int c_Handling(va_list ptr, int theArgNum, int *fp, char *mb, int *bp);
int per_Handling(int *fp, char *mb, int *bp);
void NormalText(const char *F, int *fp, int *pc, char *mb, int *bp);
int argCounting(const char *theFormat);
int opDeterminer(const char *F, int *A, int *fp, va_list P, char *bm, int *bp);
int id_handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp);
int u_Handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp);
int o_Handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp);
int binaryHandling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp);
int xX_Handling(va_list myPtr, int A, char C, int *fp, char *mb, int *bp);
void printing(char *theBuffer, int *bp);
int finally(char c, int *fp, char *mb, int *bp);
#endif
