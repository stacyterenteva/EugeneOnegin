#include "sorting.h"
//NOTE как принять массив типа void* если там лежат адреса указателей
void bubble_sort(char** data, int size, int (*compare_func)(char** a, char** b)) {
    assert(data);
    assert(compare_func);

    for (int n = 0; n < size; n++) {
        for (int i = 0; i < size - 1; i++) {
            if ((*compare_func)(&data[i], &data[i + 1]) != -1) {
                swap_value(&data[i], &data[i + 1]);
            }
        }
    }
}

void swap_value(char** value1, char** value2)
{
    assert(value1);
    assert(value2);

    char* temp = 0;
    temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int compare_less(const void* a, const void* b)
{
    assert(a);
    assert(b);

    int value_a = *(const int*) a;
    int value_b = *(const int*) b;
    if (value_a < value_b) {
        return 1;
    }
    else if (value_a > value_b) {
        return -1;
    }
    else {
        return 0;
    }
}

int compare_greater(const void* a, const void* b)
{
    assert(a);
    assert(b);

    int value_a = *(const int*) a;
    int value_b = *(const int*) b;
    if (value_a > value_b) {
        return 1;
    }
    else if (value_a < value_b) {
        return -1;
    }
    else {
        return 0;
    }
}

int alfabet_compare(char** str1_pointer, char** str2_pointer)
{
    assert(str1_pointer);
    assert(str2_pointer);

    char* str1 = *(char**) str1_pointer;
    char* str2 = *(char**) str2_pointer;

    int compare_flag = 0;

    for (int i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++, j++) {
        while (!isalpha(str1[i])) {
            i++;
        }

        while (!isalpha(str2[j])) {
            j++;
        }

        if (tolower(str1[i]) > tolower(str2[j])) {
            compare_flag = 1;
            break;
        }
        else {
            compare_flag = -1;
            break;
        }
    }
    return compare_flag;
}

int rifm_compare(char** str1_pointer, char** str2_pointer)
{
    assert(str1_pointer);
    assert(str2_pointer);

    char* str1 = *(char**) str1_pointer;
    char* str2 = *(char**) str2_pointer;

    int i = 0;
    int j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    int compare_flag = 0;

    while (str2[j] != '\0') {
        j++;
    }

    for (; i > 0, j > 0; i--, j--) {
        while (!isalpha(str1[i])) {
            i--;
        }

        while (!isalpha(str2[j])) {
            j--;
        }

        if (tolower(str1[i]) > tolower(str2[j])) {
            compare_flag = 1;
            break;
        }
        else {
            compare_flag = -1;
            break;
        }
    }
    return compare_flag;

    }


