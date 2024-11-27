#include <stdio.h>

int main(void){
    unsigned int n = 0, sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    sum = (1 + n) * n / 2;
    printf("The sum is %d", sum);
}
