#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bogosort.h"
#include "basic_funcs.h"

int main(){
	srand(time(NULL));
	int len = 10;
	int* list = get_random_list(len);
	show_list(list, len);
	printf("number of try: %d\n",bogosort(list, len));
	show_list(list, len);
	return 0;
}