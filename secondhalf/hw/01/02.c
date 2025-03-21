#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct{
    char arr[SIZE];
    int head, tail;
} queue;

void init(queue *s){
    s->head = -1;
    s->tail = -1;
}

void eq(queue *s, char n){
    if(s->tail == SIZE - 1){
        printf("stack is full.");
        return;
    }
    s->arr[++s->tail] = n;
}

int dq(queue *s){
    if(s->tail == -1){
        return -1;
    }else if(s->head > s->tail){
        return -1;
    }
    return s->arr[++s->head];
}

int main(){
    queue q;
    init(&q);
    char str[SIZE] = {0};
    char *strP = str;
    int input = 0, output = 0;
    
    while(1){
        printf("input: ");
        scanf("%s", &str);
        if(strcmp(str, "eq") == 0){
            scanf("%d", &input);
            eq(&q, input);
            printf("output: \n");
        }else if(strcmp(str, "dq") == 0){
            output = dq(&q);
            printf("output: ");
            if(output <= 0){
                printf("empty\n");
                break;
            }else{
                printf("%d\n", output);
            }
        }
    }

    return 0;
}