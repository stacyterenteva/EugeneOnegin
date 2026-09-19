#include "sorting.h"

//NOTE как принять массив типа void* если там лежат адреса указателей
void bubble_sort(void* data, int size, int size_of_element, int (*compare_func)(const void* a, const void* b)) {

    assert(data);
    assert(compare_func);
    char *data_m = (char*)data;

    for (int n = 0; n < size; n++) {
        for (int i = 0; i < size - 1; i++) {
            if (compare_func(data_m + i * size_of_element, data_m + (i + 1) * size_of_element) != -1) {
                swap_value(data_m + i * size_of_element, data_m + (i + 1) * size_of_element, sizeof(*(data_m + (i + 1) * size_of_element)));
            }
        }
    }
}

// FIXME: universal swap


void swap_value(void* value1, void* value2, int size)
{
    assert(value1);
    assert(value2);

    char* value11 = (char*) value1;
    char* value21 = (char*) value2;

    char temp = 0;
    for (int i = 0; i < size; i++) {
        temp = value11[i];
        value11[i] = value21[i];
        value21[i] = temp;
    }
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

int alfabet_compare(const void* str1_pointer, const void* str2_pointer)
{
    assert(str1_pointer);
    assert(str2_pointer);

    const char* str1 = *(const char**) str1_pointer;
    const char* str2 = *(const char**) str2_pointer;
    assert(str1);
    assert(str2);

//    fputs(str1, stderr);
//    fprintf(stderr, "str1 = %s, str2 = %s\n", str1, str2);

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

// Компараторы - частные случаи, swap и sort - универсальные
int rifm_compare(const void* str1_pointer, const void* str2_pointer)
{
    assert(str1_pointer);
    assert(str2_pointer);

    const char* str1 = *(const char**) str1_pointer;
    const char* str2 = *(const char**) str2_pointer;

    int i = 0;
    int j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    int compare_flag = 0;

    while (str2[j] != '\0') {
        j++;
    }

    // TODO: разобраться, что имелось в виду
    for (; i > 0 && j > 0; i--, j--) {
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


