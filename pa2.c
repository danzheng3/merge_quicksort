#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

void testCaseGen(long* arr, int size);

int main() {
    int size=20;
    long* arr = (long*) malloc(50 * sizeof(long));

    testCaseGen(arr, size);
    printf("Original array: \n");
    printArr(arr, size);
    mergeSort(arr, size);
    printf("\nSorted array: \n");
    printArr(arr,size);

    free(arr);





    return 0;
}

void testCaseGen(long* arr, int size) {
    for (int i =0; i<size; i++) {
        arr[i] = rand() % 201 - 100;
    }
    return;
}

