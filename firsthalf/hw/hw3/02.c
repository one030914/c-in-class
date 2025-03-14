#include <stdio.h>
#define SIZE 300

int main() {
    int arr[SIZE][SIZE] = {0}, row = 0, col = 0;
    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][col] += arr[i][j]; //加總完column的值，往下一列
            arr[row][j] += arr[i][j]; //目標row會跟著行數移動加總
            arr[row][col] += arr[i][j];
        }
    }
    for(int i = 0; i <= row; i++) {
        for(int j = 0; j <= col; j++) {
            if(j > 0){
                printf(" ");
            }
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}