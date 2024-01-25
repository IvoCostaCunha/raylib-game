#include "UnitsTests.h"

#include <stdio.h>

#include "CUnit/CUError.h"
#include "CUnit/CUnit.h"
#include "CUnit/TestDB.h"

void initializeUnitTests() {
  if (CU_initialize_registry() == CUE_SUCCESS) {
    printf("* [T] CUnit successfully initiated\n");
  }
}

void freeUnitTests() {
  CU_cleanup_registry();
}