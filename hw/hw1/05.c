#include <stdio.h>

int main(){
    int n = 0, k = 0, min = 0, max = 0, sum = 0, temp = 0;

    scanf("%d",&n);
    scanf("%d",&k);
    max = k;
    min = k;
    sum = k;
    for(int i = 0; i < n - 1; i++){
        scanf("%d",&k);
        temp = k;
        if(temp > max){
            max = temp;
        }
        if(temp < min){
            min = temp;
        }
        sum += temp;
    }
    printf("%d %d %d", min, max, sum);
    return 0;
}