#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int asc(const void *a, const void *b){
//     return (*(int *)a - *(int *)b);
// }

void MS(int arr[], int begin, int end) {
    int len = end - begin + 1;
    if (len <= 1) return;

    int mid = (begin + end) / 2;
    MS(arr, begin, mid);
    MS(arr, mid + 1, end);

    int l = begin, r = mid + 1, m = 0, *tmp;
    tmp = (int *)calloc(len, sizeof(int));
    while (l <= mid && r <= end) {
        if (arr[l] <= arr[r]) {
            tmp[m] = arr[l++];
        } else if (arr[l] > arr[r]) {
            tmp[m] = arr[r++];
        }
        m++;
    }
    while (l <= mid) {
        tmp[m++] = arr[l++];
    }
    while (r <= end) {
        tmp[m++] = arr[r++];
    }
    for (int i = 0; i < len; i++) {
        arr[i + begin] = tmp[i];
    }
    free(tmp);
}

int main() {
    clock_t start, end;
    double timer;
    int n = 1000, m = 100, index = 1;
    char *fname = (char *)calloc(30, sizeof(char));

    FILE *input = fopen("int_1k.txt", "r");
    while (!feof(input)) {
        printf("%d.\n", index);
        start = clock();
        int *buf = (int *)calloc(m, sizeof(int));
        for (int i = 0; i < m; i++) {
            fscanf(input, "%d\n", &buf[i]);
        }
        end = clock();
        timer = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Read 100 integers time used: %.6f seconds.\n", timer);

        // start = clock();
        // qsort(buf, m, sizeof(int), asc);
        // end = clock();
        // timer = (double)(end - start) / CLOCKS_PER_SEC;
        // printf("QSort time used: %.6f seconds.\n", timer);

        start = clock();
        MS(buf, 0, m - 1);int *in_pos = (int *)calloc(k, sizeof(int));
    int *in_count = (int *)calloc(k, sizeof(int));
    int *eof = (int *)calloc(k, sizeof(int));
        for (int i = 0; i < m; i++) {
            printf("%d ", buf[i]);
        }
        end = clock();
        timer = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Merge Sort time used: %.6f seconds.\n", timer);

        start = clock();
        sprintf(fname, "file_%d.txt", index++);
        FILE *output = fopen(fname, "w");
        for (int i = 0; i < m; i++) {
            fprintf(output, "%d\n", buf[i]);
        }
        fclose(output);
        end = clock();
        timer = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Write 100 integers time used: %.6f seconds.\n\n", timer);
        free(buf);
    }

    fclose(input);
    free(fname);
    return 0;
}