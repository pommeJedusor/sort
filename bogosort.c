#include "basic_funcs.h"

int bogosort(int* list, int len){
	int counter = 0;
	while (!check_sort(list, len)){
		shuffle(list, len);
		counter++;
	}
	return counter;
}