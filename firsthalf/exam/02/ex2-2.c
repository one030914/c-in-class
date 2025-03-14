#include <stdio.h>

int main(void){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    if (n1 % n2 == 0){
        printf("It is divisible.\n");
    }else{
        printf("It is indivisible.\n");
    }
}
