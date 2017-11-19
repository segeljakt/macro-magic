# Multitypes

`multitype.h` is a collection of macros which make it possible to return multiple values from a function. The returned values can be assigned to multiple variables in one line of code. The macros rely on tricks, but it has been successfully tested with:

Compilers: `gcc` and `clang`
Standards: `-std=c11` and `-std=c99`
Optimizations: `-O0`, `-O1`, `-O2`, `-O3`, `-Ofast`

There are two versions, `heap-based/multitype.h` and `stack-based/multitype.h`. The former returns arguments by allocating them on the heap while the latter puts them on the stack. The stack-based version is less user friendly since it requires all multitypes to be pre-defined at the top of the file.

# How to use

Include either the heap-based or stack-based `multitype.h` at the top of your source file.

```.c
#include "multitype.h"
```

If using the stack based version, define the multitypes which you would like to return from your functions. Skip this step when using the heap-based version.

```.c
multitypedefs(
  multitypedef (int,float,double),
  multitypedef (int,int)
);
```

Create some functions which return some values:

```.c
multitype (int,float,double) func1() {
  int    a = 5;
  float  b = -1.3;
  double c = 3.75;
  return (a,b,c);
}
```

There is no need to specify the types, e.g `(int,float,double)`, but it can be used to make things more clear. Thereby, it is also valid to type:

```.c
multitype (int,float,double) func1() {
  int    a = 5;
  float  b = -1.3;
  double c = 3.75;
  return (a,b,c);
}
```

To return literals, cast them to the appropriate type. Otherwise, the compiler might get confused.

```
multitype (int,int) func2() {
  return ((int)1,(int)2);
}
```

Multitype macros do not interfere with regular functions.

```
int func3() {
  return 9;
}

int func4() {
  return (int)3;
}
```

Finally, multiple variables can be assigned from functions on the same line by using the `let` macro.

```.c
int main(const int argc, const char *argv[]) {

  int    i;
  int    j;
  float  f;
  double d;


  let (i,f,d) = func1();
  printf("(i, f, d) ==> (%d, %f, %g)", i, f, d);


  let (i,j) = func2();
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
i ==> 9
i ==> 3
```

That's is all!

You can also return and assign structs and pointers as parameters. For more examples, see `heap-based/examples.c` and `stack-based/examples.c`.



# LICENSE

MIT
