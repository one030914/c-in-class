#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100000

int main(){
    int *arr, size = 0;
    arr = (int *)calloc(SIZE, sizeof(int));
    FILE *read = fopen("secondhalf\\hands-on\05\\int_1M.txt", "r");
    while(!feof(read)){
        fscanf(read, "%d\n", &arr[size++]);
    }

    
    fclose(read);
    free(arr);
    return 0;
}