#include <stdio.h>
#include <math.h>
#define SIZE 100

int main(void){
    int n[SIZE] = {0}, num = 0, m[SIZE] = {0};
    while(scanf("%d", &n[num]) && n[num] != -1){
        num++;
    }
    for(int i = 0; i < SIZE; i++){
        int tmp = 0;
        for(int j = 0; j < i; j++){
            if(n[j] <= n[j + 1]){
                tmp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        printf("%d\n", n[i]);
    }
}
