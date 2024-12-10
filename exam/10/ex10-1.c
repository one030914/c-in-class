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
    unsigned int index = 0;

    while(scanf("%s", bufn) != EOF && strcmp(bufn, "0\0") != 0 || scanf("%s", bufp) != EOF && strcmp(bufp, "0\0") != 0){a
        strcpy(conPtrs[index]->name, bufn);
        strcpy(conPtrs[index++]->phone, bufp);
    }

    //output
    // for(int i = 0; i < index; i++){
    //     printf("%s %s\n", conPtrs[i]->name, conPtrs[i]->phone);
    // }
}

contant *lookup(contant dict[], const char key[]){
    for(int i = 0; i < MAXSIZE; i++){
        if(strcmp(key, dict[i].name) == 0){
            return &dict[i];
        }
    }
    return NULL;
}