#include <stdio.h>
#define SIZE 110

int main(){
    int n = 1, arr[SIZE] = {0}, c = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                c++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if (i > 0){
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n%d\n", c);
    return 0;
}