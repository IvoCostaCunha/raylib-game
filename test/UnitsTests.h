#pragma once
#include <CUnit/TestRun.h>
#include <stdbool.h> 

int initializeUnitTests();
void freeUnitTests();
void runAllUnitTests();
void runAllUnitTestsAutomatic();
bool hasFailedAnUnitTest();

void StrArrayTests();