#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void){
    unsigned int n = 0, d = 0, c = 0;
    double pi = 0.0;

    srand(time(NULL));

    printf("Enter sample size: ");
    scanf("%d", &n);

    for(int i = 0; i <= n; i++){
        d = pow(((float) rand() / RAND_MAX), 2) + pow(((float) rand() / RAND_MAX), 2);
        if(d < 1){
            c++;
        }
    }
    pi = 4 * ((float) c / n);
    printf("%.8f", pi);
}
