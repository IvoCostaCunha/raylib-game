#include "utils.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void initStrArray(struct s_StrArray *strArray, size_t initialSize) {
  strArray->array = malloc(initialSize * sizeof(char *));
  strArray->size = initialSize;
  for (unsigned int i = 0; i < initialSize; i++) {
    strArray->array[i] = "";
  }
  strArray->usedSize = 0;
  strArray->b_size = initialSize * sizeof(char *);
}

void addToStrArray(struct s_StrArray *strArray, char *str) {
  strArray->usedSize++;
  if (strArray->usedSize >= strArray->size) {
    strArray->size++;
    strArray->b_size = strArray->size * sizeof(char *);
    strArray->array = realloc(strArray->array, strArray->size * sizeof(char *));
  }
  strArray->array[strArray->usedSize - 1] = str;
  printf("* size %ld usedsize %ld b_size %ld\n", strArray->size,
         strArray->usedSize, strArray->b_size);
}

void deleteFromStrArray(struct s_StrArray *strArray, int index) {
  strArray->array[index] = "[empty]";
  for (long unsigned int i = index; i < strArray->usedSize - 1; i++) {
    strArray->array[i] = strArray->array[i + 1];
  }
  strArray->usedSize--;
  strArray->size--;
  strArray->b_size = strArray->size * sizeof(char *);
  strArray->array = realloc(strArray->array, strArray->size * sizeof(char *));
  printf("* size %ld usedsize %ld b_size %ld\n", strArray->size,
         strArray->usedSize, strArray->b_size);
}

void initStrArrayTest() {
  struct s_StrArray strArray;
  initStrArray(&strArray, 10);
  
  assert(strArray.size == 10);
  assert(strArray.usedSize == 0);
  assert(strArray.b_size == 10 * sizeof(char *));
}

void addToStrArrayTest() {
  struct s_StrArray strArray;
  initStrArray(&strArray, 1);
  addToStrArray(&strArray, "test");
  addToStrArray(&strArray, "test2");

  assert(strArray.b_size == 24);
  assert(strArray.size == 3);
  assert(strArray.usedSize == 2);
  assert(strcmp(strArray.array[0], "test") == 0);
  assert(strcmp(strArray.array[1], "test2") == 0);

  struct s_StrArray strArray2;
  initStrArray(&strArray2, 1);
  addToStrArray(&strArray2, "test");

  assert(strArray2.b_size == 16);
  assert(strArray2.size == 2);
  assert(strArray2.usedSize == 1);
  assert(strcmp(strArray2.array[0], "test") == 0);
}

void deleteFromStrArrayTest() {

}