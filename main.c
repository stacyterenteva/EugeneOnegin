#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

#include "sorting.h"
#include "string_funcs.h"

void save_text_to_file(char** index1, char** index2, char** index3);
const int NUM_OF_LINES = 14;

int main() {


    int a = 9;
    int b = 5;

    swap_value(&a, &b, sizeof(int));

    printf("a = %d, b = %d\n", a, b);

    FILE* onegin = fopen("onegin.txt", "r");
    char* text = (char*) calloc(1000, sizeof(char));

    char* true_index[14] = {};
    char* alfabet_index[14] = {};
    char* rifm_index[14] = {};

    //TODO: make it func
    int n_lines = 0;
    while (n_lines != NUM_OF_LINES) {
        true_index[n_lines] = text;
        int num_of_letters = my_fgets(text, 1000, onegin); //TODO: macros with sizeof
        text += num_of_letters;
        n_lines++;
    }

    memcpy(alfabet_index, true_index, sizeof(true_index));
    memcpy(rifm_index, true_index, sizeof(true_index));

    bubble_sort(alfabet_index, 14, sizeof(alfabet_index[0]), alfabet_compare);

    bubble_sort(rifm_index, 14, sizeof(rifm_index[0]), rifm_compare);

    save_text_to_file(alfabet_index, rifm_index, true_index);
}

//TODO: maybe ui.c
void save_text_to_file(char** index1, char** index2, char** index3)
{
    FILE* sorted_text = fopen("sorted_onegin.txt", "w");
    for (int i = 0; i < 14; i++) {
        const char* ch = index1[i];
        fputs(ch, sorted_text);
        fputs("\n", sorted_text);
    }
    fputs("\n", sorted_text);

    for (int i = 0; i < 14; i++) {
        const char* ch = index2[i];
        fputs(ch, sorted_text);
        fputs("\n", sorted_text);
    }
    fputs("\n", sorted_text);

    for (int i = 0; i < 14; i++) {
        const char* ch = index3[i];
        fputs(ch, sorted_text);
        fputs("\n", sorted_text);
    }
    fputs("\n", sorted_text);

    fclose(sorted_text);
}
