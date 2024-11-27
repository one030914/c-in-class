#include <stdio.h>

int main(void){
    int x = 0, y = 0, c = 0, s = 1;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    while (c < y){
        s *= x;
        c += 1;
    }
    printf("%d\n", s);
}
