#include <stdlib.h>
#include <stdio.h>

int* merge_sort(int* list, int len){
    if (len==1){
        return list;
    }
    int middle = len/2;
    merge_sort(list, middle);
    merge_sort(list+middle, len-middle);
    int* temp_list = malloc(sizeof(int)*len);
    int j1=0;
    int j2=middle;
    for (int i=0;i<len;i++){
        if (j1==middle){
            temp_list[i]=list[j2];
            j2++;
        }else if (j2==len){
            temp_list[i]=list[j1];
            j1++;
        }else if (list[j1]<list[j2]){
            temp_list[i]=list[j1];
            j1++;
        }else {
            temp_list[i]=list[j2];
            j2++;
        }
    }
    for (int i=0;i<len;i++){
        list[i] = temp_list[i];
    }
    free(temp_list);
    return list;
}