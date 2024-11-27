#include <stdio.h>
#define SIZE 100

int main(void){
    int n = 0, sum = 0, c = 0;
    double a = 0.0;
    while(scanf("%d", &n) && n!=-1){
        sum += n;
        c++;
        a = (double) sum / c;
    }
    printf("%.2f\n", a);
}
