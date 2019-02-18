#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void parent(pid_t pid_c) {
  printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid_c);
  exit(EXIT_SUCCESS);
}

static void child() {
  printf("I'm child! my pid is %d.\n", getpid());
  exit(EXIT_SUCCESS);
}

int main(void) {
  pid_t res; // pid_t: Process ID type
  res = fork();
  if (res == -1) {
    err(EXIT_FAILURE, "fork() failed");
  }
  if (res == 0) {
    // child process came here because fork() returns 0 for child process
    child();
  } else {
    // parent process came here because fork() returns the pid of newly created child process (> 1)
    parent(res);
  }
  err(EXIT_FAILURE, "Should not reach here");
}
