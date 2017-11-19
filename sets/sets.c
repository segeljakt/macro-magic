/******************************************************************************
*     File Name           :     sets.c                                        *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-18 23:19]                            *
*     Last Modified       :     [????-??-?? ??:??]                            *
*     Description         :                                                   *
******************************************************************************/

#if 0
typedef struct set_s {
  int nmemb;
  int A[3];
} set_t;
typedef union var_u {
  set_t set;
} var;

#define PP_ARG_N( \
          _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, \
         _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
         _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
         _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
         _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
         _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
         _61, _62, _63, N, ...) N

/* Note 63 is removed */
#define PP_RSEQ_N()                                        \
         62, 61, 60,                                       \
         59, 58, 57, 56, 55, 54, 53, 52, 51, 50,           \
         49, 48, 47, 46, 45, 44, 43, 42, 41, 40,           \
         39, 38, 37, 36, 35, 34, 33, 32, 31, 30,           \
         29, 28, 27, 26, 25, 24, 23, 22, 21, 20,           \
         19, 18, 17, 16, 15, 14, 13, 12, 11, 10,           \
          9,  8,  7,  6,  5,  4,  3,  2,  1,  0

#define PP_NARG_(...)    PP_ARG_N(__VA_ARGS__)

/* Note dummy first argument _ and ##__VA_ARGS__ instead of __VA_ARGS__ */
#define PP_NARG(...)     PP_NARG_(_, ##__VA_ARGS__, PP_RSEQ_N())

#define my_func(...)     func(PP_NARG(__VA_ARGS__), __VA_ARGS__)

/*#define set(...) \*/
  /*(var){(set_t) {.nmemb = PP_NARG(__VA_ARGS__), .A = {__VA_ARGS__}}};*/

/*#define unify(...) :1*/
/*#define xxx(...) ?=*/

































#define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define UNIQUE static void TOKENPASTE2(Unique_, __LINE__)(void) {}

#define set(...) TOKENPASTE2(Unique_,__LINE__)

  var v = (var){(set_t) {.nmemb = PP_NARG(__VA_ARGS__), .A = {__VA_ARGS__}}} \
  {                                                                          \
      unify_method() {                                                       \
                                                                             \
      }                                                                      \
  }

#endif


#include <stdio.h>
#include <stdlib.h>

typedef struct a_s {
  int size;
  void (*method)();
} a_t;

void func(a_t *a) {
  printf("MMethod: Pointer: %p\n", a);
}

a_t *new_a(int size) {
  a_t *a = malloc(sizeof(a_t));

  {
    void fake() {
      printf("FMethod: Pointer: %p\n", a);
      func(a);
    }
    a->size = 5;
    a->method = &fake;
  }
  printf(" Method: Pointer: %p\n", a);
  a->method();

  return a;
}

int main(const int argc, const char *argv[]) {
  a_t *a = new_a(5);
  printf(" Method: Pointer: %p\n", a);
  /*a->method();*/
  /*a_t *b = new_a(3);*/
  /*b->method();*/
  return 0;
}
