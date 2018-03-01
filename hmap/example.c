/******************************************************************************
*     File Name           :     example.c                                     *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-20 13:52]                            *
*     Last Modified       :     [2017-11-22 00:34]                            *
*     Description         :                                                   *
******************************************************************************/
#include "./hmap.h"
#include <stdio.h>
/*****************************************************************************/
int main(const int argc, const char *argv[]) {

  init_global_hmap(100); /* Global version */

  char *val = NULL;
  // Put
  hash("key") = "val";
  // Get
  val = hash("key");
  // Pop
  val = hash("key") = NULL;
  // Copy
  hash("key") = "val";
  hash("newkey") = hash("key");
  // Move
  hash("newkey") = hash("key") = NULL;


  hmap_t *hmap = new_hmap(100); /* Local version */
  hash(hmap, "xxx") = val;


  return 0;
}
