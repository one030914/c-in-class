#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000

void asc(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

void MS(int *arr, int begin, int end){
    if (begin >= end) return;
    int mid = (begin + end) / 2;
    MS(arr, begin, mid);
    MS(arr, mid + 1, end);

    int *tmp = (int *)calloc((end - begin + 1), sizeof(int));
    int left = begin, right = mid + 1, index = 0;

    while(left <= mid && right <= end){
        tmp[index++] = (arr[left] < arr[right]) ? arr[left++] : arr[right++];
    }
    while(left <= mid) {
        tmp[index++] = arr[left++];
    }
    while(right <= end) {
        tmp[index++] = arr[right++];
    }
    for (int i = 0; i < index; i++) {
        arr[begin + i] = tmp[i];
    }
    free(tmp);
}

int main() {

    // MS(arr, 0, size - 1);
    // qsort(arr, size, sizeof(int), asc);

    return 0;
}