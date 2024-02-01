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

/**
 * Initialise an s_StrArray
 * @param strArray Pointer to the concerned s_StrArray structure
 * @param initialSize Size at which the s_StrArray will be initialised (defaulted to 1 if 0 is provided) 
*/
void initStrArray(struct s_StrArray *strArray, size_t initialSize);
void addToStrArray(struct s_StrArray *strArray, char *str);
void deleteFromStrArray(struct s_StrArray *strArray, int index);

void initStrArrayTest();
void addToStrArrayTest();
void deleteFromStrArrayTest();

// StrLinkedList
struct s_StrLinkedListElement {
  char *element;
  size_t charSize;
  struct s_StrLinkedListElement *next;
};

struct s_StrLinkedList {
  struct s_StrLinkedListElement *root;
  struct s_StrLinkedListElement *lastElement;
};

void addToStrLinkedList(struct s_StrLinkedList *StrLinkedList, char* newElement, size_t newElementSize);
void deleteFromStrLinkedList(struct s_StrLinkedList *StrLinkedList, int index);
