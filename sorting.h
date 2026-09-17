#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

void bubble_sort(char** data, int size, int (*compare_func)(char** a, char** b));
void swap_value(char** value1, char** value2);
int compare_less(const void* a, const void* b);
int compare_greater(const void* a, const void* b);
int alfabet_compare(char** str1_pointer, char** str2_pointer);
int rifm_compare(char** str1_pointer, char** str2_pointer);

#endif /* SORTING_H */
