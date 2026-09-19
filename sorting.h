#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

void bubble_sort(void* data, int size, int size_of_element, int (*compare_func)(const void* a, const void* b));
void swap_value(void* value1, void* value2, int size);
int compare_less(const void* a, const void* b);
int compare_greater(const void* a, const void* b);
int alfabet_compare(const void* str1_pointer, const void* str2_pointer);
int rifm_compare(const void* str1_pointer, const void* str2_pointer);

#endif /* SORTING_H */
