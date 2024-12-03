#include <stdio.h>
#define SIZE 2000

int main() {
    int n = 0, arr[SIZE] = {0};
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            printf("%d", arr[i]);
            if (i > 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
