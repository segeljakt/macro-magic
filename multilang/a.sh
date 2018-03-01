#define C_CODE_START \
: '

#include <stdio.h>
int main() {
  printf("Hello world!\n");
}

#define C_CODE_END \
'

#ifdef BASH_CODE_START

gcc "$(basename "$0")" -x c && ./a.out

#endif // BASH_CODE_END
