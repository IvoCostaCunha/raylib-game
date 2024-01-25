#include "utils.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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