# Multitypes

`multitype.h` is a collection of macros which make it possible to return multiple values from a function. The returned values can be assigned to multiple variables in one line of code. The macros rely on tricks, but it has been successfully tested with:

Compilers: `gcc` and `clang`
Standards: `-std=c11` and `-std=c99`
Optimizations: `-O0`, `-O1`, `-O2`, `-O3`, `-Ofast`

# How to use

Include `multitype.h` at the top of your source file.

```.c
#include "multitype.h"
```

Define some multitypes which you would like to return from your functions:

```.c
multitypedefs(
  multitypedef(int,float,double),
  multitypedef(int,int)
);
```

Create some functions which return some values:

```.c
multitype(int,float,double) func1() {
  int    a = 5;
  float  b = -1.3;
  double c = 3.75;
  return (a,b,c);
}

multitype(int,int) func2() {
  return ((int)1,(int)2);
}

// multitype macros do not interfere with regular functions

int func3() {
  return (int)3;
}

int func4() {
  return 9;
}
```

Call it from somewhere:

```.c
int main(const int argc, const char *argv[]) {

  int    i;
  int    j;
  float  f;
  double d;


  let(i,f,d) = func1();
  printf("(i, f, d) ==> (%d, %f, %g)", i, f, d);


  let(i,j) = func2();
  printf("(i, j) ==> (%d, %d)", i, j);


  i = func3();
  printf("i ==> %d", i);


  i = func4();
  printf("i ==> %d", i);


  return 0;

}
```

Output:

```
(i, f, d) ==> (5,-1.3,3.75)
(i, j) ==> (1,2)
i ==> 3
i ==> 9
```

That's it! :D

You can also return and assign structs and pointers as parameters. For more examples, see `example.c`.
