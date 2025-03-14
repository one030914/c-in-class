#include <stdio.h>

int main() {
  int n = 0, prime = 0;
  
  while(scanf("%d", &n)!=EOF) { // keep receiving integers until EOF is reached
    if(n < 2){
        printf("not prime\n");
        continue;
    }
    for(int i = 1;i <= n;i++){
        if(n % i == 0){
            prime++;
        }
    }
    if(prime > 2){
        printf("not prime\n");   
    }else{
        printf("prime\n");
    }
    prime = 0;
  }
  
  return 0;
}