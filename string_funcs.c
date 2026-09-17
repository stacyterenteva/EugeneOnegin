#include <stdio.h> //NOTE нужна ли для чтения из стд ввода
#include "string_funcs.h"

int my_fgets(char* buffer, int n, FILE* file)
{
    int c = fgetc(file);
    int i = 0;
    while (i < n && c != EOF && c != '\n') {
        buffer[i] = (char) c;
        i++;
        c = fgetc(file);
    }
    i++;
    buffer[i] = '\0';
    return i;
}

int my_strlen(const char* string)
{
    assert(string);

    int i = 0;
    for (i = 0; string[i] != '\0'; i++) {
        ;
    }
    return i;
}

void my_puts(const char* string)
{
    assert(string);

    int i = 0;
    for (i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
    }
}

void my_strcpy(const char* old_string, char* new_string)
{
    assert(old_string);
    assert(new_string);

    for (int i = 0; old_string[i] != '\0'; i++) {
        new_string[i] = old_string[i];
    }
}

void my_strcat(char* first_string, const char* second_string)
{
    assert(first_string);
    assert(second_string);

    int i = my_strlen(first_string);

    my_strcpy(second_string, first_string + i);
}

bool my_strcmp(const char* first_string, const char* second_string)
{
    assert(first_string);
    assert(second_string);

    bool equal_flag = true;
    int i = 0;
    for (i = 0; first_string[i] != '\0'; i++) {
        if (first_string[i] != second_string[i]) {
            equal_flag = 0;
            break;
        }
    }
    if (first_string[i] != second_string[i]) {
        equal_flag = 0;
    }
    return equal_flag;
}

void my_strncat(char* first_string, const char* second_string, int count)
{
    assert(first_string);
    assert(second_string);

    int i = 0;
    for (i = 0; first_string[i] != '\0'; i++) {
        ;
    }
    int j = 0;
    for (j = 0; j < count && second_string[j] != '\0'; j++) {
        first_string[i] = second_string[j];
        i++;
    }
}

int my_strchr(const char* string, char ch)
{
    assert(string);
    int i = 0;
    for (i = 0; string[i] != '\0' && string[i] != ch; i++) {
        ;
    }
    if (string[i] == ch) {
        return i;
    }
    else {
        return -1;
    }
}

// TODO: strtok
const char* my_strstr(const char* string, const char* substring)
{
    assert(string);
    assert(substring);

    int i = 0;
    for (i = 0; string[i] != '\0'; i++) {
        int j = 0;
        int temp_i = i;
        for (j = 0; substring[j] != '\0'; j++) {
            if (string[temp_i] != substring[j]) {
                break;
            }
            temp_i++;
        }
            if (substring[j] == '\0') {
                return string + temp_i;
            }
        }
        return NULL;
    }

const char* my_strrchr(const char* string, char ch)
{
    assert(string);

    int i = 0;
    int last_idx;
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == ch) {
            last_idx = i;
        }
    }
    return string + last_idx;
}

int my_strspn(const char* str1, const char* str2)
{
    assert(str1);
    assert(str2);

    int i = 0;
    for (i = 0; my_strchr(str2, str1[i]) != -1; i++) {
        ;
    }

    return i;
}
