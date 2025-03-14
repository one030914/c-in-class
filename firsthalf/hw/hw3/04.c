#include <stdio.h>
#define SIZE 200000

int main(){
    int low = 0, mid = 0, high = 0, S[SIZE] = {0}, T[SIZE] = {0}, S_n = 0, T_n = 0, c = 0;
    scanf("%d", &S_n);
    for(int i = 0; i < S_n; i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &T_n);
    for(int i = 0; i < T_n; i++){
        scanf("%d", &T[i]);
    }

    for(int i = 0; i < T_n; i++){
        high = S_n - 1;
        low = 0;
        while(low <= high){
            mid = (low + high) / 2;
            if(T[i] == S[mid]){
                c++;
                break;
            }else if(T[i] < S[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
    }
    printf("%d\n", c);
    return 0;
}