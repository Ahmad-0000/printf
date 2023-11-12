#ifndef THISFILE
#define THISFILE
#include <stdarg.h>
int _printf(const char *theFormat, ...);
int s_Handling(va_list ptr, int theArgNum);
int c_Handling(va_list ptr, int theArgNum);
int NormalText(const char *theFormat, int j, int *thePchar);
int argCounting(const char *theFormat);
int opDeterminer(const char *theFormat, int *theArgNum, int i, va_list myPtr);
int id_handling(va_list myPtr, int theArgNum);
#endif
