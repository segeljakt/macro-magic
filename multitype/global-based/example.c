/******************************************************************************
*     File Name           :     example.c                                     *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-21 08:58]                            *
*     Last Modified       :     [????-??-?? ??:??]                            *
*     Description         :                                                   *
******************************************************************************/
#include <stdio.h>

#include <stdlib.h>

long cast_from_long(void *var, char to) {
  switch(to) {
    case 'c': return (long)*(char*)  var;
    case 'i': return (long)*(int*)   var;
    case 'l': return (long)*(long*)  var;
    case 'f': return (long)*(float*) var;
    case 'd': return (long)*(double*)var;
    default: abort();
  }
}

double cast_from_double(void *var, char to) {
  switch(to) {
    case 'c': return (double)*(char*)  var;
    case 'i': return (double)*(int*)   var;
    case 'l': return (double)*(long*)  var;
    case 'f': return (double)*(float*) var;
    case 'd': return (double)*(double*)var;
    default: abort();
  }
}


#define CAST_TO_TYPE(VAR, TO)           \
  _Generic((VAR),                       \
    char:    cast_from_long(&VAR,TO),   \
    int:     cast_from_long(&VAR,TO),   \
    long:    cast_from_long(&VAR,TO),   \
    float:   cast_from_double(&VAR,TO), \
    double:  cast_from_double(&VAR,TO), \
    default: 's'                        \
  )

/*#define TYPE(VAR) \*/
  /*_Generic((VAR),             \*/
    /*char:    'c',             \*/
    /*int:     'i',             \*/
    /*long:    'l',             \*/
    /*float:   'f',             \*/
    /*double:  'd',             \*/
    /*default: 's'              \*/
  /*)*/

/*double cast_to_double*/






int main(const int argc, const char *argv[]) {
  int    i = 0;
  double d = 0;
  char c = (char) i;
  typedef struct x_s {
    int asd;
  } x_t;

  x_t x;

  char a = TYPE(x);
  printf("%c\n", a);
  /*void *a = (int*)&x;*/
  /*void *p = CAST_TO_TYPE(x, 'i');*/
  /*char type = _Generic((x), int: 'd', default: 'c');*/
  /*printf("%c\n", type);*/
  /*char a = CAST_TO_TYPE(i);*/
  return 0;
}
