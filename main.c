#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bogosort.h"
#include "basic_funcs.h"
#include "hash_sort.h"

int main(){
	srand(time(NULL));
	int len = 10;
	int* list = get_random_list(len);
    printf("randomly generated list of len %d\n", len);
	show_list(list, len);
    printf("\n");

    int* final_list = hash_sort(list, len);
    printf("list sorted using an hash table\n");
	show_list(final_list, len);
    free(final_list);
    printf("\n");

    printf("list sorted by bogosort (the best) needed only %d tries\n", bogosort(list, len));
	show_list(list, len);
    free(list);
    printf("\n");
	return 0;
}