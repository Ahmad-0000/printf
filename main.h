#ifndef THISFILE
#define THISFILE
#include <stdarg.h>
int _printf(const char *theFormat, ...);
int s_Handling(va_list ptr);
int c_Handling(va_list ptr);
int NormalText(const char *theFormat, int j, int *thePchar);
#endif
