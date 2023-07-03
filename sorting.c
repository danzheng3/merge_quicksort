#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

void printArr(long* arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}

int partition(long* arr, int lb, int ub)
{
    if (ub<lb)
        return -1;
    //lomuto partition
    long temp;
    long partition_el = arr[ub];
    int i = lb - 1;

    for (int j = lb; j <= ub - 1; j++) {
        if (arr[j] <= partition_el) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // elements to correct position
    temp = arr[i + 1];
    arr[i + 1] = arr[ub];
    arr[ub] = temp;

    return i + 1;
}

void quickSort(long* arr, int size)
{
    if (size <= 1)
        return;

    int pivot = size - 1;
    int partition_idx = partition(arr, 0, pivot);

    quickSort(arr, partition_idx);
    quickSort(arr + partition_idx + 1, size - partition_idx - 1);
}

void merge(long* src, long* dest, int lb, int mid, int ub) {
    if (ub <= lb || mid < lb || mid + 1 > ub)
        return;

    int leftSize = mid - lb + 1;
    int rightSize = ub - mid;

    long* leftArray = malloc(leftSize * sizeof(long));
    long* rightArray = malloc(rightSize * sizeof(long));

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = src[lb + i];

    for (int j = 0; j < rightSize; j++)
        rightArray[j] = src[mid + 1 + j];

    int leftIndex = 0;
    int rightIndex = 0;
    int destIndex = lb;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            dest[destIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            dest[destIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        destIndex++;
    }

    while (leftIndex < leftSize) {
        dest[destIndex] = leftArray[leftIndex];
        leftIndex++;
        destIndex++;
    }

    while (rightIndex < rightSize) {
        dest[destIndex] = rightArray[rightIndex];
        rightIndex++;
        destIndex++;
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(long* arr, int size) {
    if (size <= 1)
        return;

    int middle = size / 2;

    mergeSort(arr, middle);
    mergeSort(arr + middle, size - middle);

    long* sol = malloc(size * sizeof(long));
    merge(arr, sol, 0, middle - 1, size - 1);

    for (int i = 0; i < size; i++) {
        arr[i] = sol[i];
    }

    free(sol);
}

