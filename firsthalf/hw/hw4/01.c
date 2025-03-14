#include <stdio.h>
#define SIZE 101

void reverse(char str[], int start, int end);
unsigned int len(const char *str);
int main(){
    int n = 0;
    scanf("%d ",&n);
    while(n--){
        printf("%d\n", n);
        char n1[SIZE] = {'\0'}, n2[SIZE] = {'\0'}, sum[SIZE] = {'\0'};
        fgets(n1, SIZE, stdin);
        fgets(n2, SIZE, stdin);

        int len1 = len(n1), len2 = len(n2);
        int max = len1 > len2 ? len1 : len2;
        reverse(n1, 0, len1);
        reverse(n2, 0, len2);
        
        int carry = 0, i = 0;
        for(i = 0; i < max; i++){
            int num1 = (n1[i] - '0') > 0 ? n1[i] - '0' : 0;
            int num2 = (n2[i] - '0') > 0 ? n2[i] - '0' : 0;
            int sumNum = num1 + num2 + carry;
            carry = sumNum / 10;
            sum[i] = sumNum % 10 + '0';
        }
        if(carry){
            sum[i++] = carry + '0';
        }
        sum[i] = '\n';
        if(len(sum) > 80) {
            printf("overflow\n");
            continue;
        }
        reverse(sum, 0, i);
        printf("%s", sum);
    }
}
unsigned int len(const char *str){
    int i = 0;
    while(str[++i] != '\n');
    return i;
}

void reverse(char str[], int start, int end){
    end--;
    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}