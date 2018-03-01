/******************************************************************************
*     File Name           :     a.c                                           *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-20 23:00]                            *
*     Last Modified       :     [2017-11-21 07:11]                            *
*     Description         :                                                   *
******************************************************************************/
#define C_CODE_START \
: <<'BASH_COMMENT'


#include <stdio.h>
int main() {
  printf("Hello world!\n");
}


#define C_CODE_END \
BASH_COMMENT
#if 0 //


gcc "$(basename "$0")" -x c && ./a.out


#endif // BASH_CODE_END
