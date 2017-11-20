/******************************************************************************
*     File Name           :     example.c                                     *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-20 13:52]                            *
*     Last Modified       :     [2017-11-20 18:57]                            *
*     Description         :                                                   *
******************************************************************************/
#include "./hmap.h"
#include <stdio.h>
/*****************************************************************************/
int main(const int argc, const char *argv[]) {

  hmap_t *hmap = new_hmap(100); /* Local version */
  init_global_hmap(100); /* Global version */

  char *key = "hello";
  char *val = "there";

  put(hmap, key) = val; // Put it in a hashmap
  val = get(hmap, key); // Retrieve it from the hashmap

  printf("%s\n", key);



  put(key) = val; // Put it in a global hashmap
  val = get(key); // Retrieve it from the global hashmap

  printf("%s\n", val); // Print it

  return 0;
}

