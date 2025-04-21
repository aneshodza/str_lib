#include <stdlib.h>
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

int str_count_char(const char *str, char c) {
  int counter = 0;

  while (*str) {
    if (*str == c) {
      counter++;
    }
    str++;
  }

  return counter;
}

char *str_concat(const char *str1, const char *str2) {
  int size1 = str_len(str1);
  int size2 = str_len(str2);

  char *str_result = malloc((size1 + size2) * sizeof(char));

  for (int i = 0; i < size1; i++) {
    str_result[i] = str1[i];
  }

  for (int i = 0; i < size2; i++) {
    str_result[size1 + i] = str2[i];
  }

  return str_result;
}
