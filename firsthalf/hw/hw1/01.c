#include <stdio.h>

int main() {
  unsigned int a = 0, b = 0, sum = 0, len = 0;
  
  while(scanf("%u%u", &a, &b)!=EOF) { // receive two integers at a time until EOF is reached
    sum = a + b;
    
    if (sum == 0) {
      len = 1;
    }else{
      while(sum){
        len++;
        sum /= 10;
      }
    }
    printf("%u\n", len);
    len = 0;
  }
  return 0;
}