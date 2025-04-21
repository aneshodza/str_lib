#include <CUnit/Basic.h>
#include "../include/str_lib.h"

void test_str_len(void) {
  CU_ASSERT_EQUAL(str_len("hello"), 5);
  CU_ASSERT_EQUAL(str_len(""), 0);
  CU_ASSERT_EQUAL(str_len(" "), 1);
  CU_ASSERT_EQUAL(str_len("1234567890"), 10);
}

void test_str_count_char(void) {
  CU_ASSERT_EQUAL(str_count_char("hello", 'l'), 2);
  CU_ASSERT_EQUAL(str_count_char("hello", 'a'), 0);
  CU_ASSERT_EQUAL(str_count_char(" ", ' '), 1);
  CU_ASSERT_EQUAL(str_count_char("", ' '), 0);
}

void test_str_concat(void) {
  CU_ASSERT_STRING_EQUAL(str_concat("hello,", " world!"), "hello, world!");
  CU_ASSERT_STRING_EQUAL(str_concat("", ""), "");
  CU_ASSERT_STRING_EQUAL(str_concat(" ", "_"), " _");
}

void test_str_trim(void) {
  char str1[] = " test ";
  str_trim(str1);
  CU_ASSERT_STRING_EQUAL(str1, "test");

  char str2[] = "    hello, world!";
  str_trim(str2);
  CU_ASSERT_STRING_EQUAL(str2, "hello, world!");
}

int main() {
  // Sets up everything
  CU_initialize_registry();

  // Adding the test suite
  CU_pSuite suite = CU_add_suite("String Library Tests", NULL, NULL);

  // Register the tests
  CU_add_test(suite, "str_len tests", test_str_len);
  CU_add_test(suite, "str_count_char tests", test_str_count_char);
  CU_add_test(suite, "str_concat tests", test_str_concat);

  // Run the registered tests
  CU_basic_run_tests();

  // Note down the amount of failed tests
  unsigned short failed = CU_get_number_of_failures();

  // Clean up
  CU_cleanup_registry();

  // Return non-zero if there are failed tests
  return (failed > 0) ? 1 : 0;
}
