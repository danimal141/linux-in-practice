#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p = NULL;
  puts("Before invalid access");
  *p = 0;
  puts("After invalid access");
  exit(EXIT_SUCCESS);
}
