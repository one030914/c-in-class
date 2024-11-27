#include <stdio.h>

int main(void){
    unsigned int n = 0, c = 1;
    printf("Enter n: ");
    scanf("%d", &n);

    while(c <= n){
        if(n % c == 0){
            printf("%d ", c);
        }
        c += 1;
    }
}
