#include "../Unity/src/unity.h"
#include "../read.h"

void setUp() {}
void tearDown() {}

void test_string(void) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  TEST_ASSERT_EQUAL_STRING(str1, str2);
}

void test_resd_test(void) {
  int value = test();
  TEST_ASSERT_EQUAL_INT(6, value);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_string);
  RUN_TEST(test_resd_test);

  return UNITY_END();
}
