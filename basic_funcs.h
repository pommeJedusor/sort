#ifndef BASIC_FUNC
#define BASIC_FUNC
char check_sort(int* list, int len);
char check_str_sort(char** list, int len);
void shuffle(int* list, int len);
void str_shuffle(char** list, int len);
void show_list(int* list, int len);
void show_str_list(char** list, int len);
int* get_random_list(int len, int max, int min);
char** get_random_str_list(char* letters, int nb_letters, int len_min, int len_max, int nb_str);
void free_str_list(char** list, int len);
#endif