#include <stdio.h>
#define SIZE 15000

int main() {
    int n1 = 0, set1[SIZE] = {-1}, n2 = 0, set2[SIZE] = {-1}, c = 0;
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++){
        scanf("%d", &set1[i]);
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++){
        scanf("%d", &set2[i]);
    }
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(set1[i] == set2[j]){
                c++;
                set2[j] = -1;
                break;
            }
        }
    }
    printf("%d", c);
}