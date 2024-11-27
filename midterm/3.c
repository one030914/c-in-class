#include <stdio.h>
#include <math.h>

int main(void){
    int c = 0, x = 0, y = 0, p1 = 0, p2 = 0, x_ = 0, y_ = 0;
    double distance = 0.0, p = 0.0;
    scanf("%d", &c);
    for(int i = 0; i < c; i++){
        scanf("%d", &x);
        scanf("%d", &y);
        p1 += abs(x);
        p2 += abs(y);
        p += sqrt(x * x + y * y);
        x_ += x;
        y_ += y;
    }
    distance = sqrt(p1 * p1 + p2 * p2);
    printf("%d %d %.2f\n", x_, y_, distance);

    printf("%d %d %.2f\n", x_, y_, p);
}
