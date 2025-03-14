#include <stdio.h>
#define SIZE 100

void replace(char *str, const char *pattern, const char *target);
int len(const char *str);

int main(){
    char str[SIZE], pattern[SIZE], target[SIZE];

    scanf("%s%s%s", str, pattern, target);

    replace(str, pattern, target);

    printf("%s\n", str);
}

int len(const char *str){
    int len = 0;
    while(*str != '\0'){
        len++;
        str++;
    }
    return len;
}

void replace(char *str, const char *pattern, const char *target){
    char result[SIZE] = {0}, *resPtr = result, *str_start = str;
    int tar_len = len(target);

    while(*str != '\0'){
        char *str_temp = str;
        const char *pat_temp = pattern;
        while(*pat_temp == *str_temp && *pat_temp != '\0'){
            str_temp++;
            pat_temp++;
        }
        if(*pat_temp == '\0'){
            while(*target != '\0'){
                *resPtr = *target;
                resPtr++;
                target++;
            }
            target -= tar_len;
            str = str_temp;
        }else{
            *resPtr = *str;
            resPtr++;
            str++;
        }
    }
    *resPtr = '\0';

    resPtr = result;
    str = str_start;

    while (*resPtr != '\0') {
        *str = *resPtr;
        str++;
        resPtr++;
    }
    *str = '\0';
}