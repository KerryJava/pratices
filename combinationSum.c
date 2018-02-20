/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    int *candidates;
    int size;
    int capacity;
}Item;

typedef struct result {
    int **combination;
    int *columnSizes;
    int size;
    int capacity;
    Item item;
}Result;

void initResult(Result *res, int size) {
    res->size = 0;
    res->capacity = size;
    res->columnSizes = malloc(sizeof(int)*size);
    res->combination = malloc(sizeof(int*)*size);

    res->item.candidates = malloc(sizeof(int) *size);
    res->item.size = 0;
    res->item.capacity = size;

    for (int i = 0 ; i < size; i++) {
        res->combination[i] = malloc(sizeof(int) *  size);
        //res->columnSizes[i] = malloc(sizeof(int));
        res->columnSizes[i] = 0;
    }
}

void insertResult(Result *res, int value) {
    
    Item *item = &(res->item);
    if (item->size >= item->capacity) {
        item->candidates = realloc(item->candidates, sizeof(int) * item->capacity *2);
        item->capacity = item->capacity * 2;
    }
    
    item->candidates[item->size] = value;
    item->size ++;
}

void removeResult(Result *res) {
    Item *item = &(res->item);
    item->size --;
    if (item->size < 0) {
        printf(" error remove\n");
    }
}

void printItemHelper(int *item, int size) {
    printf("%s\n", "printItem");
    for (int i = 0; i < size; i++) {
        printf("%d, ", item[i]);
    }

    printf("\n");   
}

void printItem(Result *res) {

    printItemHelper(res->item.candidates, res->item.size);
}

void storeResult(Result *res) {
    if (res->size >= res->capacity) {
        res->combination = realloc(res->combination, sizeof(int *) * res->capacity * 2);
        res->columnSizes = realloc(res->columnSizes, sizeof(int) * res->capacity * 2);
        res->capacity = res->capacity * 2;
    }
    
    res->combination[res->size] = malloc(sizeof(int)* res->item.size);
    memcpy(res->combination[res->size], res->item.candidates, sizeof(int)*res->item.size);
    //res->combination[res->size] = res->item.candidates;
    //res->columnSizes[res->size] = malloc(sizeof(int));
    //*(res->columnSizes[res->size]) = res->item.size;

    res->columnSizes[res->size] = res->item.size;
    res->size++;
}

void sort(int *candidates, int candidatesSize)
{
    for(int i = 0; i < candidatesSize - 1; i++) {

        int j = i ;
        int temp = candidates[j+1];

        for (; j >= 0 && temp < candidates[j]; j--) {
            candidates[j+1] = candidates[j];
        }

        candidates[j+1] = temp;
    }

    for (int k = 0; k < candidatesSize; k++) {
        printf("%d ,", candidates[k]);
    }
    printf("%s\n", "\n");
}

void combinationSumHelper(int* candidates, int candidatesSize, int target, int index, Result *result) {
    
    if (target <= 0) {
        //printItem(result);
        storeResult(result);
        //printf("----%s %d---\n", "recurse ", target);
        return;
    }
    
    for(int i = index; i >= 0; i--)
    {

        if (candidates[i] <=  target) {
            int value = target - candidates[i];
            insertResult(result, candidates[i]);
            combinationSumHelper(candidates, candidatesSize, value, i, result);
            removeResult(result); 
        }
 
    }
    
    return;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    // 1. sort input
    // 2. find biggest Val(i) <= target
    // 3. for (int idx = 0; idx <= i; ++)
    // 4.     find biggest value 

    sort(candidates, candidatesSize);
    Result *result = malloc(sizeof(Result));
    initResult(result, candidatesSize);
    
    combinationSumHelper(candidates, candidatesSize, target, candidatesSize-1, result);
    
    *returnSize = result->size;
    *columnSizes = result->columnSizes;

    return result->combination;
}

int main() {
    printf("hello world\n");
    int candidates[] = {2, 6, 3, 7};
    //int candidates[] = {1, 2};

    int *columnSizes;
    int returnSize = 0;
    int target = 7;
    int ** result = combinationSum(candidates, sizeof(candidates)/sizeof(int), target, &columnSizes, &returnSize);
    int *size = columnSizes;

    for (int i = 0; i < returnSize; i++) {

       int *array = *(result+i);

       printf("%s\n", "[");
       for (int j = 0 ; j < size[i]; j++) {
            printf("%d,", array[j]);
       }
       printf("%s\n", "]");
    }
}