/******************************************************************************
*     File Name           :     example.c                                     *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-20 13:52]                            *
*     Last Modified       :     [????-??-?? ??:??]                            *
*     Description         :                                                   *
******************************************************************************/
#include "./hmap.h"
#include <stdio.h>
/*****************************************************************************/
int main(const int argc, const char *argv[]) {


  /* Local version */
  hmap_t *hmap = new_hmap(100);

  int x = 35;                           // Define a variable
  put(hmap, "hello") = &x;              // Put it in a hashmap
  int *y = get(hmap, "hello");          // Retrieve it from the hashmap
  printf("get(\"hello\") => %d\n", *y); // Print it



  /* Global version */
  init_global_hmap(100);

  int a = 27;                           // Define a variable
  put("hello") = &a;                    // Put it in a global hashmap
  int *b = get("hello");                // Retrieve it from the global hashmap
  printf("get(\"hello\") => %d\n", *b); // Print it


  return 0;
}
