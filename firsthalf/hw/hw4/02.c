#include <stdio.h>
#include <string.h>
#define SIZE 2000

void reverse(char str[], int start, int end);
void print(char str[], int start, int end);
void replace(char str[], int start, int end, char tar[]);

int main(){
    char str[SIZE] = {'\0'};
    int n = 0;
    scanf("%s", str);
    scanf("%d", &n);
    while(n--){
        char cmd[SIZE] = {'\0'}, tar[SIZE] = {'\0'};
        int start = 0, end = 0;
        scanf("%s %d %d", cmd, &start, &end);
        if(strcmp(cmd, "replace") == 0){
            scanf("%s", tar);
            replace(str, start, end, tar);
        }else if(strcmp(cmd, "reverse") == 0){
            reverse(str, start, end);
        }else if(strcmp(cmd, "print") == 0){
            print(str, start, end);
        }
    }
    return 0;
}

void reverse(char str[], int start, int end){
    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void print(char str[], int start, int end){
    while(end < start && str[end] != '\n'){
        printf("%c", str[start--]);
    }
    while(start <= end && str[start] != '\n'){
        printf("%c", str[start++]);
    }
    printf("\n");
}

void replace(char str[], int start, int end, char tar[]){
    char result[SIZE] = {'\0'};

    strncpy(result, str, start);
    strncat(result, tar, end - start + 1);
    strcat(result, str + end + 1);
    strncpy(str, result, SIZE);
}