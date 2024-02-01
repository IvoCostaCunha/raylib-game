#include "utils.h"

void addToStrLinkedList(struct s_StrLinkedList *StrLinkedList, char *newElement, size_t newElementSize) {
  struct s_StrLinkedListElement *s = malloc(sizeof(struct s_StrLinkedList));
  StrLinkedList->lastElement->next = s;
  StrLinkedList->lastElement->charSize = newElementSize;
  StrLinkedList->lastElement->element = newElement;
}

void deleteFromStrLinkedList(struct s_StrLinkedList *StrLinkedList, int index) {
  struct s_StrLinkedListElement *currentElement = StrLinkedList->root;
  struct s_StrLinkedListElement *beforeElement = NULL;
  for (int i = 0; i < index; i++) {
    if (i == index - 1) {
      beforeElement = currentElement;
    }
    currentElement = currentElement->next;
  }

  if (currentElement != StrLinkedList->lastElement) {
    beforeElement->next = currentElement->next;
  }
  free(currentElement);
}

struct s_StrLinkedListElement *getFromStrLinkedList(struct s_StrLinkedList *StrLinkedList, int index) {
  struct s_StrLinkedListElement *currentElement = StrLinkedList->root;
  for (int i = 0; i < index; i++) {
    currentElement = currentElement->next;
  }
  return currentElement;
}