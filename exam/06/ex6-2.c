#include <stdio.h>
#define SIZE 100

int search(const char *str, const char *key);

int main(){
    char str[SIZE], key[SIZE];

    scanf("%s%s", str, key);

    printf("%d\n", search(str, key));
}


int search(const char *str, const char *key){
    int count = 0;
    const char *key_temp = key;

    while(*str != '\0'){
        const char *str_temp = str;
        while(*key == *str_temp && *key != '\0'){
            str_temp++;
            key++;
        }
        if(*key == '\0'){
            count++;
        }
        key = key_temp;
        str++;
    }

    return count;
}