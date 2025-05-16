#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 1000000

int asc(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int *bubble(int data[], const int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(data[j] > data[j + 1]){
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    return data;
}

int main(){
    clock_t start, end;
    double timer;
    int *q_arr, *b_arr, *sorted, i = 0;
    q_arr = (int *)calloc(SIZE, sizeof(int));
    b_arr = (int *)calloc(SIZE, sizeof(int));
    sorted = (int *)calloc(SIZE, sizeof(int));

    start = clock();
    FILE *read = fopen("int_1M.txt", "r");
    while(!feof(read)){
        fscanf(read, "%d\n", &q_arr[i++]);
    }
    memcpy(b_arr, q_arr, SIZE * sizeof(int));
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Read time used: %.6f seconds.\n", timer);
    FILE *qfp = fopen("int_1M_Qsorted.txt", "w");
    FILE *bfp = fopen("int_1M_Bsorted.txt", "w");

    start = clock();
    qsort(q_arr, i, sizeof(int), asc);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("QSort time used: %.6f seconds.\n", timer);

    start = clock();
    sorted = bubble(b_arr, i);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort time used: %.6f seconds.\n", timer);

    start = clock();
    int index = 0;
    while(index < i){
        fprintf(qfp, "%d\n", q_arr[index]);
        fprintf(bfp, "%d\n", sorted[index++]);
    }
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Write time used: %.6f seconds.\n", timer);

    fclose(read);
    fclose(qfp);
    fclose(bfp);
    free(q_arr);
    free(b_arr);
    free(sorted);
    return 0;
}