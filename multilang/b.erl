-module(helloworld).
-export([start/0]).
%: define C_CODE_START \

-ifdef(comment).

#include <stdio.h>
int main(int argc, char *argv[]) {
  printf("Hello world!\n");
}

%: define C_CODE_END \

-endif().

%: if ERLANG_CODE_START


start() ->
    io:fwrite("Hello world!\n").

%: endif // ERLANG_CODE_END
