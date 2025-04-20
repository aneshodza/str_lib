#include "../include/str_lib.h"
#include <stdio.h>

int main() {
  char str[] = "hello";
  int len = str_len(str);
  printf("Length: %d\n", len);

  return 0;
}
