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
    int* final_list = malloc(sizeof(int)*len);
    int index = 0;
    int max = 0;
    for (int i=0;i<len;i++){
        if (list[i]>max)max=list[i];
    }
    HashNode* hash_table = malloc(sizeof(HashNode)*(max+1));
    for (int i=0;i<len;i++){
        hash_table[list[i]].number++;
    }
    for (int i=0;i<max+1;i++){
        for (int j=0;j<hash_table[i].number;j++){
            final_list[index] = i;
            index++;
        }
    }
    free(hash_table);
    return final_list;
}