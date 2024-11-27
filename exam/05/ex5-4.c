#include <stdio.h>

unsigned int fibonacii(unsigned int n);

int main(void){
    unsigned int number;

    printf("%s", "Enter n: ");
    scanf("%u", &number);

    printf("Fibonacii(%u) = %u\n", number, fibonacii(number));
}

unsigned int fibonacii(unsigned int n){
    if(n == 0){
        return 0;
    }else if(n <= 2){
        return 1;
    }else{
        return (fibonacii(n - 1) + fibonacii(n - 2));
    }
}
