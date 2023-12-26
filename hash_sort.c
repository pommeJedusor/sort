#include "hash_sort.h"
#include <stdlib.h>
#include <stdio.h>
#include "basic_funcs.h"

void show_hash_table(HashNode* table, int len){
    printf("%d", table[0].number);
    for (int i=1;i<len;i++){
        printf(", %d", table[i].number);
    }
    printf("\n");
}

int* hash_sort(int* list, int len){
    //get the number of negative number and the least closer number to 0
    int max = 0;
    int min = 0;
    int negative_number = 0;
    for (int i=0;i<len;i++){
        if (list[i]>max)max=list[i];
        if (list[i]<min)min=list[i];
        if (list[i]<0)negative_number++;
    }
    if (-min>max)max=-min;
    //make an hash table
    HashNode* hash_table = malloc(sizeof(HashNode)*(max+1));
    for (int i=0;i<len;i++){
        if (list[i]>=0)hash_table[list[i]].number++;
        else hash_table[-list[i]].negative++;
    }
    //create the list ordred
    int* final_list = malloc(sizeof(int)*len);
    int index = 0;
    int negative_index = negative_number-1;
    for (int i=0;i<max+1;i++){
        for (int j=0;j<hash_table[i].number;j++){
            final_list[negative_number+index] = i;
            index++;
        }
        for (int j=0;j<hash_table[i].negative;j++){
            final_list[negative_index] = -i;
            negative_index--;
        }
    }

    free(hash_table);
    return final_list;
}