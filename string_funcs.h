#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <assert.h>
#include <string.h>

const int MAX_NUM_OF_CHARS = 1000;
const int TEST_SIZE = 10;

int my_strlen(const char* string);
void my_puts(const char* string);
void my_strcpy(const char* old_string, char* new_string);
bool my_strcmp(const char* first_string, const char* second_string);
void my_strcat(char* first_string, const char* second_string);
void my_strncat(char* first_string, const char* second_string, int count);
int  my_strchr(const char* string, char ch);
const char* my_strstr(const char* string, const char* substring);
const char* my_strrchr(const char* string, char ch);
int my_strspn(const char* str1, const char* str2);
int my_fgets(char* buffer, int n, FILE* file);
#endif /* STRING_H */
