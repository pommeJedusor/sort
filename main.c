#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bogosort.h"
#include "basic_funcs.h"
#include "hash_sort.h"
#include "bubble.h"
#include "merge.h"

int* copy_list(int* list, int len){
    int* new_list = malloc(sizeof(int)*len);
    for (int i=0;i<len;i++){
        new_list[i]=list[i];
    }
    return new_list;
}

char** copy_str_list(char** list, int len){
    char** new_list = malloc(sizeof(char*)*len);
    for (int i=0;i<len;i++){
        new_list[i]=list[i];
    }
    return new_list;
}

int main(){
	srand(time(NULL));
	int len = 10000;
	int* list = get_random_list(len, 10000, -10000);
    printf("randomly generated list of len %d\n", len);
	//show_list(list, len);
    printf("\n");

    clock_t begin = clock();
    int* final_list = hash_sort(list, len);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("list sorted using an hash table\n");
    printf("time taken: %f\n",time_spent);
	//show_list(final_list, len);
    free(final_list);
    printf("\n");

    begin = clock();
    final_list = bubble_sort(copy_list(list, len), len);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("list sorted using bubble sort\n");
    printf("time taken: %f\n",time_spent);
	//show_list(final_list, len);
    free(final_list);
    printf("\n");

    begin = clock();
    final_list = merge_sort(copy_list(list, len), len);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("list sorted using merge sort\n");
    printf("time taken: %f\n",time_spent);
	//show_list(final_list, len);
    free(final_list);
    printf("\n");

    free(list);
	return 0;
}