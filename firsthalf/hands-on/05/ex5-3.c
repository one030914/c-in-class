#include <stdio.h>

unsigned int factorial(unsigned int number);

int main(void){
    unsigned int i;

    printf("Enter n: ");
    scanf("%u", &i);
    factorial(i);
}

unsigned int factorial(unsigned int number){
    static int n = 0;
    if(number == 1){
        printf("%d! = %d\n", ++n, number);
        return 1;
    }else{
        number *= factorial(number - 1);
        printf("%d! = %d\n", ++n, number);
        return number;
    }
}
