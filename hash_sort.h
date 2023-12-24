#ifndef HASH_SORT
#define HASH_SORT
typedef struct HashNode {
    int number;
}HashNode;
int* hash_sort(int* list, int len);
void show_hash_table(HashNode* table, int len);
#endif