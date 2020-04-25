#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define ERROR \
printf("In File %s \t ", __FILE__); \
printf("In Function %s() \t", __FUNCTION__); \
printf("At Line %d\t",__LINE__); \
printf("At %s \t\n",__TIME__); \
printf("Enter any character to exit\n"); \
char bff[8]; \
fgets(bff, 6, stdin); \
exit(0);

#endif