#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 500

typedef struct{
    char name[MAXSIZE];
    char phone[MAXSIZE];
} contant;

int main(){
    contant contants[MAXSIZE];
    contant *conPtrs[MAXSIZE];

    for(int i = 0; i < MAXSIZE; i++){
        contants[i].name[0] = '\0';
        contants[i].phone[0] = '\0';
        conPtrs[i] = &contants[i];
    }

    char bufn[MAXSIZE];
    char bufp[MAXSIZE];

    while(scanf("%s", bufn) != EOF && strcmp(bufn, "0\n\0") != 0){
        printf("yes");
    }
}

contant *lookup(contant dict[], const char key[]){
    for(int i = 0; i < MAXSIZE; i++){
        if(strcmp(key, dict[i].name) == 0){
            return &dict[i];
        }
    }
    return NULL;
}