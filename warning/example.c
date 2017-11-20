/******************************************************************************
*     File Name           :     example.c                                     *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-20 09:22]                            *
*     Last Modified       :     [????-??-?? ??:??]                            *
*     Description         :                                                   *
******************************************************************************/
#include "warning.h"
/*****************************************************************************/
int main(const int argc, const char *argv[]) {
  _Pragma ("GCC dependency \"parse.y\"")
  return 0;
}
