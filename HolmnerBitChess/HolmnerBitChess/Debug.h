#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "Print.h"
#include "Global.h"

#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed ",#n); \
printf("On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
printf("Enter any character to exit\n"); \
char bff[8]; \
fgets(bff, 6, stdin); \
exit(0);}

int isBoardEqual(const BOARD *board1, const BOARD *board2);

#endif