#include <stdio.h>
#include <stdlib.h>
#include <timer.h>

int main(){
    clock_t start, end;
    double timer;
    int n = 1000, m = 100, index = 1;
    char *fname = (char *)calloc(30, sizeof(char));
    int k = n / m;
    int **buf = (int **)calloc(k + 1, sizeof(int));
    for(int i = 0; i < k; i++){
        buf[i] = (int *)calloc(m / (k + 1), sizeof(int *));
    }

    for()
    
    start = clock();
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time used: %.6f seconds", timer);

    FILE *output = fopen("file_sorted.txt", "w");
    
    fclose(output);
    for(int i = 0; i < k; i++){
        free(buf[i]);
    }
    free(buf);
    return 0;
}