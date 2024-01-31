#include "UnitsTests.h"

#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>

void initStrArrayTest() {
  CU_ASSERT(2 == 2);
}

void initStrArrayTest2() {
  CU_ASSERT(2 == 2);
}

void StrArrayTests() {
  CU_pSuite StrArrayTestsSuite = CU_add_suite("StrArrayTests", NULL, NULL);
  CU_add_test(StrArrayTestsSuite, "initStrArrayTest", initStrArrayTest);
  CU_add_test(StrArrayTestsSuite, "initStrArrayTest2", initStrArrayTest2);
}