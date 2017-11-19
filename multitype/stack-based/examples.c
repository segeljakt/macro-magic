/******************************************************************************
*     File Name           :     tuple.c                                       *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-16 09:43]                            *
*     Last Modified       :     [2017-11-18 17:03]                            *
*     Description         :                                                   *
******************************************************************************/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "multitype.h"

/* An example struct */
typedef struct x_s {
  int a;
  int b;
} x_t;

/* Define all multitypes which should be used */
multitypedefs(
  multitypedef (int,float,double,int*),
  multitypedef (int,float),
  multitypedef (int,x_t)
);

/* Return an int and a float variable */
multitype (int,float) func0() {
  int   a = 3;
  float b = 9.5;
  return (a,b);
}

/* Return them as literals instead */
multitype (int,float) func1() {
  return ((int)3,(float)9.5);
}

/* Let's try something more advanced */
multitype (int,float,double,int*) func2() {
  int    a = 25;
  float  b = -1.3;
  double c = 3.75;
  int   *d = malloc(sizeof(int));
  *d = -32;
  return (a,b,c,d);
}

/* Structs work too */
multitype(int,x_t) func3() {
  x_t x = {3,5};
  return ((int)7,x);
}

/* If we are lazy, we can specify it to return multitype_t and  *
 * it will be able to return any of the user defined multitypes */
multitype_t func4() {
  x_t x = {3,5};
  return ((int)7,x);
}

/* Regular functions work as well */
int func5() {
  return 5;
}

/* This one too */
int func6() {
  return (int)3.5;
}

int main(const int argc, const char *argv[]) {

  int    i;
  float  f;
  double d;
  int   *p = malloc(sizeof(int));
  float *q = malloc(sizeof(float));
  x_t    x;

  let (i,f) = func0();
  printf("func0:  i: %d,  f: %g\n", i, f);
  // Prints "i: 3, f: 9.5"

  let (*p,*q) = func0();
  printf("func0: *p: %d, *q: %g\n", *p, *q);
  // Prints "*p: 3, *q: 9.5"

  let (i,f) = func1();
  printf("func1:  i: %d,  f: %g\n", i, f);
  // Prints "i: 3, f: 9.5"

  let (i,f,d,p) = func2();
  printf("func2:  i: %d, f: %g,  d: %g, *p: %d\n", i, f, d, *p);
  // Prints "i: 25, f: -1.3 d: 3.75 *p: -32"

  let (i,x) = func3();
  printf("func3:  i: %d,  x: {%d,%d}\n", i, x.a, x.b);
  // Prints "i: 7, x.a: 3 x.b: 5"

  let (i,x) = func4();
  printf("func4:  i: %d,  x: {%d,%d}\n", i, x.a, x.b);
  // Prints "i: 7, x.a: 3 x.b: 5"

  i = func5();
  printf("func5:  i: %d\n", i);
  // Prints "i: 5"

  i = func6();
  printf("func6:  i: %d\n", i);
  // Prints "i: 3"

  return 0;
}
