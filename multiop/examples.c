/******************************************************************************
*     File Name           :     example.c                                     *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-20 11:39]                            *
*     Last Modified       :     [????-??-?? ??:??]                            *
*     Description         :                                                   *
******************************************************************************/
#include "multiop.h"
#include <stdio.h>
/*****************************************************************************/

int main(const int argc, const char *argv[]) {
  int x    = 0;
  float y  = 1;
  double z = 2;
  long   l = 100;

  /* Add 3 to x, y and z */
  printf("   (%d, %f, %g) += 3\n", x,y,z);
  add (x,y,z) += 3;
  printf("=> (%d, %f, %g)\n\n", x,y,z);

  /* Multiply 3 to x, y and z*/
  printf("   (%d, %f, %g, %ld) *= 4\n", x,y,z,l);
  mul (x,y,z,l) *= 3;
  printf("=> (%d, %f, %g, %ld)\n", x,y,z,l);

  return 0;
}
