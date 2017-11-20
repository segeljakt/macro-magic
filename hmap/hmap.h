/******************************************************************************
*     File Name           :     hmap/hmap.h                                   *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-06-30 21:58]                            *
*     Last Modified       :     [2017-11-20 14:12]                            *
*     Description         :     Hashmap declaration.                          *
******************************************************************************/
#ifndef HMAP_H
#define HMAP_H
/*****************************************************************************/
#include <stdlib.h>
/*****************************************************************************/
#define GET1(_0,_1)                                                           \
  hmap_get(_0,_1);
#define GET0(_0)                                                              \
  hmap_get(global_hmap,_0)
#define GET_(_0,_1,GET_MACRO,...) GET_MACRO
/*---------------------------------------------------------------------------*/
#define PUT1(HMAP,STR)                                                        \
  for(int hmap_i = 0; !hmap_i; )                                              \
    for(void *val; hmap_i < 2; hmap_i++)                                      \
      if(hmap_i) {                                                            \
        hmap_put(HMAP, STR, val);                                             \
      } else                                                                  \
        val
#define PUT0(STR)                                                             \
  for(int hmap_i = 0; !hmap_i; )                                              \
    for(void *val = NULL; hmap_i < 2; hmap_i++)                               \
      if(hmap_i) {                                                            \
        hmap_put(global_hmap, STR, val);                                      \
      } else                                                                  \
        val
#define PUT_(_0,_1,PUT_MACRO,...) PUT_MACRO
/*****************************************************************************/
#define get(...)                                                              \
  GET_(__VA_ARGS__,GET1,GET0)(__VA_ARGS__)
#define put(...)                                                              \
  PUT_(__VA_ARGS__,PUT1,PUT0)(__VA_ARGS__)
/*****************************************************************************/
typedef struct hmap_s hmap_t;
typedef void (*free_val_f)(void *val);
/*****************************************************************************/
hmap_t *new_hmap(size_t nmemb);
void    free_hmap(hmap_t *hmap, free_val_f free_val);
void   *hmap_put(hmap_t *hmap, char *key, void *val);
void   *hmap_get(hmap_t *hmap, char *key);
void   *hmap_getp(hmap_t *hmap, char *key);
void   *hmap_pop(hmap_t *hmap, char *key);
void    init_global_hmap(size_t nmemb);
/*****************************************************************************/
extern hmap_t *global_hmap;
/*****************************************************************************/
#endif // HMAP_H
