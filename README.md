# MacroMagic - Cool C Macros

This is a collection of interesting and useful macros for the C pre-processor. Currently, the following macros are available:

# MultiType

```.c
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
  
  add (a,b,c)   += 3; // Add 3 to a, b and c
  add (a,b,c,d) -= 9; // Subtract 9 from a, b, c and d
  mul (a,b,c)   *= 2; // Multiply a, b and c with d
  mul (a,b)     /= 8; // Divide a and b with 8
  map (a,b,c)    = square; // Map a, b and c to a^2, b^2 and c^2 respectively
                           // Any double(*map_f)(double) function is allowed

  map (a,b,c) to square; // This syntax is also valid

  return 0;
}
```

# Hashmap

```.c
#include "hmap.h"

int main(const int argc, const char *argv[]) {

  hmap_t *hmap = new_hmap(100); // Local hashmap
  init_global_hmap(100);        // Global hashmap

  char *val = "hello";
  char *key = "world";

  put(hmap, key) = val; // Put it in the local hashmap
  val = get(hmap, key); // Retrieve it from the local hashmap

  put(key) = val;       // Put it in the global hashmap
  val = get(key);       // Retrieve it from the global hashmap

  return 0;
}
```

# License

MIT
