#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 1000000

void MS(int arr[], int begin, int end){
    int len = end - begin + 1;
    if(len <= 1) return;

    int mid = (begin + end) / 2;
    MS(arr, begin, mid);
    MS(arr, mid + 1, end);

    int l = begin, r = mid + 1, m = 0, *tmp;
    tmp = (int *)calloc(len, sizeof(int));
    while(l <= mid && r <= end){
        if(arr[l] <= arr[r]){
            tmp[m] = arr[l++];
        }else if(arr[l] > arr[r]){
            tmp[m] = arr[r++];
        }
        m++;
    }
    while(l <= mid){
        tmp[m++] = arr[l++];
    }
    while(r <= end){
        tmp[m++] = arr[r++];
    }
    for(int i = 0; i < len; i++){
        arr[i + begin] = tmp[i];
    }
    free(tmp);
}

int main(){
    clock_t start, end;
    double timer;
    int *arr, size = 0;
    arr = (int *)calloc(SIZE, sizeof(int));

    start = clock();
    FILE *read = fopen("int_1M.txt", "r");
    while(!feof(read) && size < SIZE){
        fscanf(read, "%d\n", &arr[size++]);
    }
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Read time used: %.6f seconds.\n", timer);

    start = clock();
    MS(arr, 0, size - 1);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge sort time used: %.6f seconds.\n", timer);
    
    start = clock();
    FILE *write = fopen("int_1M_sorted.txt", "w");
    int index = 0;
    while(index < size){
        fprintf(write, "%d\n", arr[index++]);
    }
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Write time used: %.6f seconds.\n", timer);

    fclose(read);
    fclose(write);
    free(arr);
    return 0;
}