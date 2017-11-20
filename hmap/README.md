# Hmap (Hash map)

This is a hash map implementation which make use of macros to make the API syntax more convenient. Two macros are provided: `put` and `get`. They can be used as in the example below:

```.c
#include "./hmap.h"
#include <stdio.h>
/*****************************************************************************/
int main(const int argc, const char *argv[]) {


  /* --- Local version --- */

  hmap_t *hmap = new_hmap(100);

  int x = 35;                           // Define a variable
  put(hmap, "hello") = &x;              // Put it in a hashmap
  int *y = get(hmap, "hello");          // Retrieve it from the hashmap
  printf("get(\"hello\") => %d\n", *y); // Print it



  /* --- Global version --- */

  init_global_hmap(100);

  int a = 27;                           // Define a variable
  put("hello") = &a;                    // Put it in a global hashmap
  int *b = get("hello");                // Retrieve it from the global hashmap
  printf("get(\"hello\") => %d\n", *b); // Print it


  return 0;
}
```

# Implementation

Hash maps are created with `new_hmap`. A global hash map can also be instantiated with `init_global_hmap`. The global hash map could be used for things such as storing the program configuration or global state. Keys must be strings, i.e. `char*`, and values can be any type of pointer.
