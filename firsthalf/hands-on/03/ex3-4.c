#include <stdio.h>

int main(void){
    float capital = 0, rate = 0, s = 1;
    unsigned int y, c = 0;

    printf("Enter capital: ");
    scanf("%f", &capital);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    rate += 1;
    printf("Enter #years: ");
    scanf("%d", &y);

    while(c < y){
        s *= rate;
        c += 1;
    }
    s *= capital;

    printf("The final amout is $%.2f", s);
}
