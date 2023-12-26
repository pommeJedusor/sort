#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bogosort.h"
#include "basic_funcs.h"
#include "hash_sort.h"

int main(){
	srand(time(NULL));
	int len = 10;
	int* list = get_random_list(len, 100, -100);
    printf("randomly generated list of len %d\n", len);
	show_list(list, len);
    printf("\n");

    clock_t begin = clock();
    int* final_list = hash_sort(list, len);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("list sorted using an hash table\n");
    printf("time taken: %f\n",time_spent);
	show_list(final_list, len);
    free(final_list);
    printf("\n");

    begin = clock();
    int bogo = bogosort(list, len);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("list sorted by bogosort (the best) needed only %d tries\n", bogo);
    printf("time taken: %f\n",time_spent);
	show_list(list, len);
    free(list);
    printf("\n");

    printf("generate a list with randomness\n");
    len = 10;
    char letters[26];
    for (int i=0; i<26;i++){
        letters[i] = i+'a';
    }
    char** str_list = get_random_str_list(letters, 26, 3, 10, 5);
    for (int i=0;i<5;i++){
        printf("%s\n", str_list[i]);
    }
    free_str_list(str_list, 3);
	return 0;
}