#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main() {
    clock_t start, end;
    double timer;
    int n = 1000, m = 100;
    int k = n / m;
    char *fname = (char *)calloc(30, sizeof(char));
    FILE **input = (FILE **)calloc(k, sizeof(FILE *));
    int **bufs = (int **)calloc(k + 1, sizeof(int *));
    int buf_size = m / (k + 1);
    for (int i = 0; i < k + 1; i++) {
        bufs[i] = (int *)calloc(buf_size, sizeof(int));
    }
    int *in_pos = (int *)calloc(k, sizeof(int));
    int *in_count = (int *)calloc(k, sizeof(int));
    int *eof = (int *)calloc(k, sizeof(int));
    int out_pos = 0;

    start = clock();
    for (int i = 0; i < k; i++) {
        sprintf(fname, "file_%d.txt", i + 1);
        input[i] = fopen(fname, "r");

        for (int j = 0; j < buf_size; j++) {
            if (fscanf(input[i], "%d\n", &bufs[i][j]) == 1) {
                in_count[i]++;
            }else{
                eof[i] = 1; // Mark this buffer as EOF
                break; // No more data to read from this buffer
            }
        }
    }
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Loading all bufs time used: %.6f seconds.\n", timer);


    start = clock();
    FILE *output = fopen("file_sorted.txt", "w");

    while (1) {
        int min = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < k; i++) {
            if (in_pos[i] < in_count[i]) {
                if (bufs[i][in_pos[i]] < min) {
                    min = bufs[i][in_pos[i]];
                    min_index = i;
                }
            }
        }

        // All buffers are empty
        if (min_index == -1) {
            break;
        }

        bufs[k][out_pos++] = min; // Store the minimum value in the output buffer
        in_pos[min_index]++; // Move the position forward in the buffer that had the minimum value

        // If the output buffer is full, write it to the output file
        if (out_pos == buf_size) {
            for (int i = 0; i < buf_size; i++) {
                fprintf(output, "%d\n", bufs[k][i]);
            }
            out_pos = 0; // Reset output position
        }

        // If the buffer from which we took the minimum value is exhausted, refill it
        if (in_pos[min_index] == in_count[min_index] && !eof[min_index]){
            in_count[min_index] = 0; // Reset count for this buffer
            in_pos[min_index] = 0; // Reset position for this buffer
            for (int j = 0; j < buf_size; j++){
                if (fscanf(input[min_index], "%d\n", &bufs[min_index][j]) == 1) {
                    in_count[min_index]++;
                } else {
                    eof[min_index] = 1; // Mark this buffer as EOF
                    break; // No more data to read from this buffer
                }
            }
        }
    }

    // Write any remaining data in the output buffer to the file
    for (int i = 0; i < out_pos; i++) {
        fprintf(output, "%d\n", bufs[k][i]);
    }

    for (int i = 0; i < k; i++) {
        fclose(input[i]);
    }
    fclose(output);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge files time used: %.6f seconds", timer);

    free(fname);
    free(input);
    for (int i = 0; i < k; i++) {
        free(bufs[i]);
    }
    free(bufs);
    free(in_pos);
    free(in_count);
    free(eof);
    return 0;
}