#include "str_lib.h"

int str_len(const char *str) {
  int len = 0;
  while (*str++) len++;
  return len;
}
