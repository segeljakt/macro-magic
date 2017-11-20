# MacroMagic - Magical C Macros

This is a collection of interesting and useful macros for the C pre-processor. Currently, the following macros are available:

# MultiType

```
#include "multitype.h"

multitype (int,float,double) fun() {
  int    a = 2;
  float  b = 3.7;
  double c = 22.53;
  return (a,b,c); // Return multiple values
}

int main(int argc, char *argv[]) {
  int    x;
  float  y;
  double z;
  
  let (x,y,z) = fun(); // Assign multiple values

  return 0;
}
```

# MultiOperations

```.c
#include "multiop.h"

double square(double x) {
  return x*x;
}

int main(int argc, char *argv[]) {
  int    a = 3;
  float  b = 1;
  double c = 9;
  long   d = 2;
  
  add (a,b,c)   += 3; // Add 3 to x, y and z
  add (a,b,c,d) -= 9; // Subtract 9 from x, y, z and u
  mul (a,b,c)   *= 2; // Multiply x, y and z with 2
  mul (a,b)     /= 8; // Divide x and y with 8
  map (a,b,c)    = square; // Map x, y and z to x^2, y^2 and z^2 respectively
                           // Any double(*map_f)(double) function is allowed

  map (a,b,c) to square; // This syntax is also valid

  return 0;
}
```

# Hashmap

```
#include "hmap.h"

int main(const int argc, const char *argv[]) {


  /* Local version */
  hmap_t *hmap = new_hmap(100);

  int x = 35;                           // Define a variable

  put(hmap, "hello") = &x;              // Put it in a hashmap
  int *y = get(hmap, "hello");          // Retrieve it from the hashmap


  /* Global version */
  init_global_hmap(100);

  put("hello") = &x;                    // Put it in a global hashmap
  int *y = get("hello");                // Retrieve it from the global hashmap


  return 0;
}
```
