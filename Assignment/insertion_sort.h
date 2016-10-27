#ifndef INSERTION_SORT_H_GLUPKJ69
#define INSERTION_SORT_H_GLUPKJ69

#include "linked_list.h"

int insertionSort(LinkedList *list, int (*compare)(void *elem1, void *elem2));

int compareInt(void *elem1, void *elem2);

#endif /* end of include guard: INSERTION_SORT_H_GLUPKJ69 */
