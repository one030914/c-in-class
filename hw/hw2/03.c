#include <stdio.h>
#define SIZE 200

int main() {
    char str[SIZE] = "";
    int char_count[26] = {0};
    while(scanf("%s", &str) != EOF){
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] - 'A' + 'a';
            }
            if(str[i] >= 'a' && str[i] <= 'z'){
                char_count[str[i] - 'a']++;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        printf("%c : %d\n", 'a' + i, char_count[i]);
    }
    return 0;
}