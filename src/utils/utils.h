#pragma once

#include <stddef.h>
#include <stdlib.h>

// StrArray
struct s_StrArray {
  char **array;
  size_t size;
  size_t usedSize;
  size_t b_size;
};

void initStrArray(struct s_StrArray *strArray, size_t initialSize);
void addToStrArray(struct s_StrArray *strArray, char *str);
void deleteFromStrArray(struct s_StrArray *strArray, int index);