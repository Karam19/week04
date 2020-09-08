#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 5; ++i) {
    fork();
  }
  sleep(5);
  return 0;
}

/*

Each instance of 'ex2' forks itself and continues the execution so a new instance will become the 
child of the old one.
In the second fork execution each of the 2 'ex2' will forks and each of them will give us a new 'ex2'
At the end after we execute fork() 3 times and we will have 2^3=8 processes and the pstree output will looks like:
The `pstree` output:
├─zsh───ex2─┬─ex2─┬─ex2───ex2
│           │     └─ex2
│           ├─ex2───ex2
│           └─ex2

In the second task we are executing fork() 5 times so we are doing 2^5=32 processes and the output will be:
─zsh─┬─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     │     └─ex2
     │     │     │     ├─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2───ex2
     │     │     └─ex2
     │     ├─ex2───ex2
     │     └─ex2
*/