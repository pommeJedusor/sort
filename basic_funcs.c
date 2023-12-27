#include <stdio.h>
#include <stdlib.h>

char check_sort(int* list, int len){
	int last_value = list[0];
	for (int i=1;i<len;i++){
		if (last_value>list[i])return 0;
		last_value = list[i];
	}
	return 1;
}

char check_str_sort(char** list, int len){
	int j;
	for (int i=1;i<len;i++){
		j=0;
		while (list[i-1][j]==list[i][j] && list[i][j]!='\0'){
			j++;
		}
		if (list[i-1][j]>list[i][j])return 0;
	}
	return 1;
}

void str_shuffle(char** list, int len){
	char* temp, rand_index = 0;
	for (int i=0;i<len;i++){
		rand_index = rand()%len;
		temp = list[i];
		list[i] = list[rand_index];
		list[rand_index] = temp;
	}	
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

void show_str_list(char** list, int len){
	printf("%s",list[0]);
	for (int i=1;i<len;i++){
		printf(", %s",list[i]);
	}
	printf("\n");
}

int* get_random_list(int len, int max, int min){

	int* list = malloc(sizeof(int)*len);
	if (list==NULL)return list;

	for (int i=0;i<len;i++){
		list[i] = rand()%(max-min)+min;
	}

	return  list;
}

char** get_random_str_list(char* letters, int nb_letters, int len_min, int len_max, int nb_str){
	char** list = malloc(sizeof(char*)*nb_str);
	int len_str;
	for (int i=0;i<nb_str;i++){
		len_str = rand()%(len_max-len_min)+len_min;
		list[i] = malloc(sizeof(char)*(len_str+1));
		for (int j=0;j<len_str;j++){
			list[i][j] = letters[rand()%nb_letters];
		}
		list[i][len_str] = '\0';
	}
	return list;
}

void free_str_list(char** list, int len){
	for (int i=0;i<len;i++){
		free(list[i]);
	}
	free(list);
}