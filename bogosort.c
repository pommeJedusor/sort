#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char check_sort(int* list, int len){
	int last_value = list[0];
	for (int i=1;i<len;i++){
		if (last_value>list[i])return 0;
		last_value = list[i];
	}
	return 1;
}

void shuffle(int* list, int len){
	int temp = 0, rand_index = 0;
	for (int i=0;i<len;i++){
		rand_index = rand()%len;
		temp = list[i];
		list[i] = list[rand_index];
		list[rand_index] = temp;
	}	
}

void show_list(int* list, int len){
	printf("%d",list[0]);
	for (int i=1;i<len;i++){
		printf(", %d",list[i]);
	}
	printf("\n");
}

int* get_random_list(int len){

	int* list = malloc(sizeof(int)*len);
	if (list==NULL)return list;

	for (int i=0;i<len;i++){
		list[i] = rand()%100;
	}

	return  list;
}

int bogosort(int* list, int len){
	int counter = 0;
	while (!check_sort(list, len)){
		shuffle(list, len);
		counter++;
	}
	return counter;
}

int main(){
	srand(time(NULL));
	int len = 10;
	int* list = get_random_list(len);
	show_list(list, len);
	printf("number of try: %d\n",bogosort(list, len));
	show_list(list, len);
	return 0;
}
