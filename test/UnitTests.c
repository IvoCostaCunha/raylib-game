#include "UnitsTests.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUError.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>

int initializeUnitTests() {
  printf("\n* [T] Running unit tests\n");
  int success = CU_initialize_registry();
  if (success == CUE_SUCCESS) {
    printf("* [T] CUnit successfully initiated\n");
    return EXIT_SUCCESS;
  } else {
    printf("* [T] CUnit could not be initiated\n");
    return EXIT_FAILURE;
  }
}

void freeUnitTests() {
  CU_cleanup_registry();
}

void runAllUnitTests() { 
  CU_basic_set_mode(CU_BRM_SILENT);
  CU_basic_run_tests();
  if(CU_get_number_of_failures() > 0) {
    printf("\n* [T] Unit tests have failed !\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n");
  }
  else {
    printf("\n* [T] All unit test were successfull !");
  }
}

void runAllUnitTestsAutomatic() {
  time_t t = time(NULL);
  struct tm *lt = localtime(&t);
  char filenamePrefix[21];
  strftime(filenamePrefix, sizeof(filenamePrefix), "logs/%Y%m%d-%H%M%S", lt);
  CU_set_output_filename(filenamePrefix);
  CU_automated_run_tests();
  char filename[34];
  sprintf(filename,"%s-Results.xml", filenamePrefix);
  printf("\n* [T] Unit test log saved as %s\n\n", filename);
}

bool hasFailedAnUnitTest() {
  return CU_get_number_of_failures() > 0;
}