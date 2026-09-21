#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "sorting.h"
#include "string_funcs.h"

const int n_lines = 6821;

void save_text_to_file(char** index, FILE* file, int n_lines);

int main()
{
    struct stat file_inf;
    stat("onegin.txt", &file_inf);

    int onegin = open("onegin.txt", O_RDONLY);

    char* text = (char*) calloc(file_inf.st_size + 1, sizeof(char));
    size_t real_size = read(onegin, text, file_inf.st_size);

    char** index = (char**) calloc(file_inf.st_size, sizeof(char*));
    int line_num = 0;
    index[line_num] = text;
    line_num++;

    for (size_t i = 0; i < real_size; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            index[line_num] = text + i + 1;
            line_num++;
        }
    }

    FILE* sorted_text = fopen("sorted_onegin.txt", "w");

    bubble_sort(index, n_lines, sizeof(index[0]), alfabet_compare);
    save_text_to_file(index, sorted_text, n_lines);

    qsort(index, n_lines, sizeof(index[0]), rifm_compare);
    save_text_to_file(index, sorted_text, n_lines);

    bubble_sort(index, n_lines, sizeof(index[0]), compare_greater);
    save_text_to_file(index, sorted_text, n_lines);

    fclose(sorted_text);

}

void save_text_to_file(char** index, FILE* file, int n_lines)
{
    for (int i = 0; i < n_lines; i++) {
        const char* ch = index[i];
        fputs(ch, file);
        fputs("\n", file);
    }

    fputs("\n", file);
}
