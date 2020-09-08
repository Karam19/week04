#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  int n;
  pid_t fork_pid = fork();
  pid_t pid = getpid();
  if (fork_pid == 0) {
    printf("Hello from child [%d - %d]\n", pid, n);
  } else {
    printf("Hello from parent [%d - %d]\n", pid, n);
  }
  return 0;
}


/*
The explanation:
Since PID values are different the output will be different too
The OS are responsiple of scheduling the processes so the order of exection will be different
*/