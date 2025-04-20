#include "../include/str_lib.h"

int str_len(const char *str) {
  int len = 0;

  // Every string in C ends with \0
  // Here we check if the value behind the
  // pointer str (dereferencing with *str)
  // is \0, meaning the string is over.
  while (*str != '\0') {
    len++;
    str++;
  } 
  return len;
}
