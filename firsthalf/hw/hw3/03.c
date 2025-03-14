#include <stdio.h>
#define SIZE 300

int main(){
    int matrix[SIZE][SIZE] = {0}, vector[SIZE] = {0}, sum[SIZE] = {0}, col = 0, row = 0;
    scanf("%d %d", &row, &col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < col; i++){
        scanf("%d", &vector[i]);
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            sum[i] += matrix[i][j] * vector[j];
        }
        printf("%d\n", sum[i]);
    }
    return 0;
}