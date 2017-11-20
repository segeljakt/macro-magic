# MultiOp

This is a set of macro operators which can act on multiple variables at once. For example:

```.c
int main(const int argc, const char *argv[]) {

  int    x = 0;
  float  y = 1;
  double z = 2;
  long   l = 100;

  /* Add 3 to x, y and z */
  add (x,y,z) += 3;

  /* Multiply 3 to x, y, z, and l */
  mul (x,y,z,l) *= 3;

  return 0;
}
```

The `add` macro can be used to apply either a `+=` or `-=` to a number of variables:

```.c
add (x,y,z) += 3;
add (x,y,z) -= 3;
```

The `mul` macro can be used to apply either a `*=` or `/=` to a number of variables:

```.c
mul (x,y,z) *= 3;
mul (x,y,z) /= 3;
```

Variables can be of any scalar type. If needed, the macro could possibly be modified to support custom types.
