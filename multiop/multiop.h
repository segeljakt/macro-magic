/******************************************************************************
*     File Name           :     multiop.h                                     *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-20 11:29]                            *
*     Last Modified       :     [????-??-?? ??:??]                            *
*     Description         :                                                   *
******************************************************************************/

/* ============================= HELPER MACROS ============================= */

/* Add to multiple variables */

#define MOA3(_0,_1,_2,_3) _0 += diff; _1 += diff; _2 += diff; _3 += diff;
#define MOA2(_0,_1,_2)    _0 += diff; _1 += diff; _2 += diff;
#define MOA1(_0,_1)       _0 += diff; _1 += diff;
#define MOA0(_0)          _0 += diff;

#define MOA_(_0,_1,_2,_3,MOA_MACRO,...) MOA_MACRO

#define MOA(...) MOA_(__VA_ARGS__,MOA3,MOA2,MOA1,MOA0)(__VA_ARGS__)

/* Multiply to multiple variables */

#define MOM3(_0,_1,_2,_3) _0 *= diff; _1 *= diff; _2 *= diff; _3 *= diff;
#define MOM2(_0,_1,_2)    _0 *= diff; _1 *= diff; _2 *= diff;
#define MOM1(_0,_1)       _0 *= diff; _1 *= diff;
#define MOM0(_0)          _0 *= diff;

#define MOM_(_0,_1,_2,_3,MOM_MACRO,...) MOM_MACRO

#define MOM(...) MOM_(__VA_ARGS__,MOM3,MOM2,MOM1,MOM0)(__VA_ARGS__)

/* Map multiple variables */

#define MOF3(_0,_1,_2,_3) _0 = mf(_0); _1 = mf(_1); _2 = mf(_2); _3 = mf(_3);
#define MOF2(_0,_1,_2)    _0 = mf(_0); _1 = mf(_1); _2 = mf(_2);
#define MOF1(_0,_1)       _0 = mf(_0); _1 = mf(_1);
#define MOF0(_0)          _0 = mf(_0);

#define MOF_(_0,_1,_2,_3,MOF_MACRO,...) MOF_MACRO

#define MOF(...) MOF_(__VA_ARGS__,MOF3,MOF2,MOF1,MOF0)(__VA_ARGS__)

/* ============================== API MACROS =============================== */


typedef double(*map_f)(double);

#define with =

/* Add to multiple variables at once */

#define add(...)                                                              \
  for(int mi = 0; !mi;)                                                       \
    for(double diff = 0; mi < 2; mi++)                                        \
      if(mi) {                                                                \
        MOA(__VA_ARGS__)                                                      \
      } else                                                                  \
        diff

/* Multiply to multiple variables at once */

#define mul(...)                                                              \
  for(int mi = 0; !mi;)                                                       \
    for(double diff = 1; mi < 2; mi++)                                        \
      if(mi) {                                                                \
        MOM(__VA_ARGS__)                                                      \
      } else                                                                  \
        diff

#define map(...)                                                              \
  for(int mi = 0; !mi;)                                                       \
    for(map_f mf; mi < 2; mi++)                                               \
      if(mi) {                                                                \
        MOF(__VA_ARGS__)                                                      \
      } else                                                                  \
        mf
