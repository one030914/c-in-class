#include <stdio.h>

void swap(int *aPtr, int *bPtr);

int main(void){
    int a, b;

    scanf("%d%d", &a, &b);

    printf("Before %d, %d\n", a, b);

    swap(&a, &b);

    printf("After %d, %d\n", a, b);
}

void swap(int *aPtr, int *bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}