/******************************************************************************
*     File Name           :     hmap/hmap.h                                   *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-06-30 21:58]                            *
*     Last Modified       :     [2018-03-01 21:42]                            *
*     Description         :     Hashmap declaration.                          *
******************************************************************************/
#ifndef HMAP_H
#define HMAP_H
/*****************************************************************************/
#include <stdlib.h>
/*****************************************************************************/
#define HASH1(HMAP,KEY)                                                       \
  hmap_get(HMAP, KEY);                                                        \
  for(int hmap_i=0; !hmap_i; )                                                \
  for(void *hmap_val, *hmap_tmp = hmap_get; hmap_i < 2; hmap_i++)           \
  if(hmap_i) {                                                            \
    if(hmap_val == NULL) {                                                \
      hmap_pop(HMAP,KEY);                                                 \
    } else if(hmap_val != (void*)hmap_get) {                              \
      hmap_put(HMAP,KEY,hmap_val);                                        \
    }                                                                     \
  } else                                                                  \
  hmap_val = hmap_tmp
/*---------------------------------------------------------------------------*/
#define HASH0(KEY)                                                            \
  hmap_get(global_hmap, KEY);                                                 \
  for(int hmap_i = 0; !hmap_i; )                                              \
  for(void *hmap_val, *hmap_tmp = hmap_get; hmap_i < 2; hmap_i++)           \
  if(hmap_i) {                                                            \
    if(hmap_val == NULL) {                                                \
      hmap_pop(global_hmap,KEY);                                          \
    } else if(hmap_val != (void*)hmap_get) {                              \
      hmap_put(global_hmap,KEY,hmap_val);                                 \
    }                                                                     \
  } else                                                                  \
  hmap_val = hmap_tmp
/*---------------------------------------------------------------------------*/
#define GET1(HMAP,KEY)                                                        \
  hmap_get(HMAP,KEY);
#define GET0(KEY)                                                             \
  hmap_get(global_hmap,KEY)
/*---------------------------------------------------------------------------*/
#define PUT1(HMAP,KEY)                                                        \
  for(int hmap_i = 0; !hmap_i; )                                              \
  for(void *val; hmap_i < 2; hmap_i++)                                      \
  if(hmap_i) {                                                            \
    hmap_put(HMAP,KEY,val);                                               \
  } else                                                                  \
  val
#define PUT0(KEY)                                                             \
  for(int hmap_i = 0; !hmap_i; )                                              \
  for(void *val = NULL; hmap_i < 2; hmap_i++)                               \
  if(hmap_i) {                                                            \
    hmap_put(global_hmap,KEY,val);                                        \
  } else                                                                  \
  val
/*---------------------------------------------------------------------------*/
#define HMAP_SELECT(_0,_1,HMAP_SELECTED,...) HMAP_SELECTED
/*****************************************************************************/
#define hash(...)                                                             \
  HMAP_SELECT(__VA_ARGS__,HASH1,HASH0)(__VA_ARGS__)
#define get(...)                                                              \
  HMAP_SELECT(__VA_ARGS__,GET1,GET0)(__VA_ARGS__)
#define put(...)                                                              \
  HMAP_SELECT(__VA_ARGS__,PUT1,PUT0)(__VA_ARGS__)
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
