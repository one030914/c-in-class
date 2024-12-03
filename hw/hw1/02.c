#include <stdio.h>

int main() {
    int count = 0, a = 0, b = 0, c = 0, max = 0, x = 0, y = 0;
    scanf("%d", &count);
    while (count > 0) {
        scanf("%d%d%d", &a, &b, &c);

        if(a >= b && a >= c) {
            max = a;
            x = b;
            y = c;
        } else if(b >= a && b >= c) {
            max = b;
            x = a;
            y = c;
        } else if(c >= a && c >= b) {
            max = c;
            x = a;
            y = b;
        }
        
        if(max * max == x * x + y * y){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        count--;
    }
    return 0;
}