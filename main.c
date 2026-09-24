#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "sorting.h"
#include "string_funcs.h"

struct Text
{
    char* text;
    size_t size;
};


void save_text_to_file(char** index, FILE* file, const int n_lines);
bool process_of_argc(int argc); //NOTE: в каких случаях возвращаемое значение лучше делать bool а в каких int, main возвращает только 0 или 1 но его воозвращаеме значение это int
Text get_content_from_file(const char* file_name);
char** create_index(char* text, size_t size);
void end_program(FILE* file, char** index, char* text);

int main(int argc, char* argv[])
{
    bool is_file_name_input_correct = process_of_argc(argc);
    if (!is_file_name_input_correct) {
        return 0;
    }

    const char* file_name = argv[1];
    Text content = get_content_from_file(file_name);
    if (content.size == 0) {
        return 0;
    }

    char* text = content.text;
    size_t real_size = content.size;

    int n_lines = count_ch(text, '\n') - 1;

    char** index = create_index(text, real_size);

    FILE* sorted_text = fopen("sorted_onegin.txt", "w");

    bubble_sort(index, n_lines, sizeof(index[0]), alfabet_compare);
    save_text_to_file(index, sorted_text, n_lines);

    qsort(index, n_lines, sizeof(index[0]), rifm_compare);
    save_text_to_file(index, sorted_text, n_lines);

    bubble_sort(index, n_lines, sizeof(index[0]), compare_greater);
    save_text_to_file(index, sorted_text, n_lines);

    end_program(sorted_text, index, text);
}

void save_text_to_file(char** index, FILE* file, const int n_lines)
{
    assert(index);
    assert(file);

    for (int i = 0; i < n_lines; i++) {
        const char* ch = index[i];
            fputs(ch, file);
            fputs("\n", file);
    }

    fputs("\n", file);
}

bool process_of_argc(int argc)
{
    if (argc == 1) {
        printf("Too few arguments\n");
        return 0;
    }
    else if (argc == 2) {
        return 1;
    }
    else {
        printf("Too many arguments\n");
        return 0;
    }
}
Text get_content_from_file(const char* file_name) {
    int onegin = open(file_name, O_RDONLY);
    Text content = {"", 0};

    if (onegin == -1) { //NOTE как закрыть доступ к файлу и ещё как-нибудь попортить файлы для теста
        perror("error");
        return content;
    }

    struct stat file_inf = {};
    stat(file_name, &file_inf);

    char* text = (char*) calloc(file_inf.st_size + 1, sizeof(char));
    size_t real_size = read(onegin, text, file_inf.st_size);
    content = {.text = text, .size = real_size};
    return content;
}

char** create_index(char* text, size_t size)
{
    char** index = (char**) calloc(size, sizeof(char*));
    int line_num = 0;
    index[line_num] = text;
    line_num++;

    for (size_t i = 0; i < size; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            index[line_num] = text + i + 1;
            line_num++;
        }
    }
    return index;
}

void end_program(FILE* file, char** index, char* text)
{
    fclose(file);
    free(index);
    free(text);
}
