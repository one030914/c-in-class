#include <stdio.h>

int min(int x, int y, int z);


int main(void){
    int n1, n2, n3;

    scanf("%d%d%d", &n1, &n2, &n3);

    printf("min=%d\n", min(n1, n2, n3));
}

int min(int x, int y, int z){
    int min;

    if(x < y && x < z){
        min = x;
    }else if(y < x && y < z){
        min = y;
    }else if(z < x && z < y){
        min = z;
    }

    return min;
}
