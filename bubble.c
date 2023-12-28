int* bubble_sort(int* list, int len){
    char is_sorted=1;
    int temp;
    while (is_sorted){
        is_sorted = 0;
        for (int i=1;i<len;i++){
            if (list[i-1]>list[i]){
                temp = list[i];
                list[i] = list[i-1];
                list[i-1] = temp;
                is_sorted = 1;
            }
        }
    }
    return list;
}