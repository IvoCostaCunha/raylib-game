#pragma once
#include <CUnit/CUnit.h>
#include <stdbool.h> 

int initializeUnitTests();
void freeUnitTests();
void addUnitTestSuites(void(f_tests)(void), ...);
void runAllUnitTestsBasic();
void runAllUnitTestsAutomatic();
bool hasFailedAnUnitTest();

void StrArrayTests();
