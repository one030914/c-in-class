#include <stdio.h>
#include <math.h>
#define SIZE 2000

double sigma(int c, int s[]);
double sum_(int c, int s[]);

int main() {
    double sig = 0.0;
    int s[SIZE] = {0}, n = 0;
    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &s[i]);
        }
        sig = sigma(n, s);
        printf("%.3f\n", sig);
        n = 0;
    }
    return 0;
}

double sigma(int c, int s[]){
    double mu = 0.0, sum = 0.0, sum_ = 0.0;
    for(int i = 0; i < c; i++){
        sum += s[i];
    }
    mu = sum / c;
    for(int i = 0; i < c; i++){
        sum_ += pow(s[i] - mu, 2);
    }
    return sqrt(sum_ / c);
}
