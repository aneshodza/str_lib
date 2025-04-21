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

int main() {
  // Sets up everything
  CU_initialize_registry();

  // Adding the test suite
  CU_pSuite suite = CU_add_suite("String Library Tests", NULL, NULL);

  // Register the tests
  CU_add_test(suite, "str_len tests", test_str_len);
  CU_add_test(suite, "str_count_char tests", test_str_count_char);

  // Run the registered tests
  CU_basic_run_tests();

  // Note down the amount of failed tests
  unsigned short failed = CU_get_number_of_failures();

  // Clean up
  CU_cleanup_registry();

  // Return non-zero if there are failed tests
  return (failed > 0) ? 1 : 0;
}
