#include "basic_funcs.h"

int bogosort(int* list, int len){
	int counter = 0;
	while (!check_sort(list, len)){
		shuffle(list, len);
		counter++;
	}
	return counter;
}

int str_bogosort(char** list, int len){
	int counter = 0;
	while (!check_str_sort(list, len)){
		str_shuffle(list, len);
		counter++;
	}
	return counter;
}