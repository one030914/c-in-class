#include <stdio.h>
#define SIZE 100

typedef struct{
    char arr[SIZE];
    int top;
} stack;

void init(stack *s){
    s->top = -1;
}

int push(stack *s, char n){
    if(s->top == SIZE - 1){
        printf("stack is full.");
        return -1;
    }
    s->arr[++s->top] = n;
    return s->top;
}

int pop(stack *s){
    if(s->top == -1){
        return -2;
    }
    return --s->top;
}

int main(){
    stack s;
    init(&s);
    char str[SIZE] = {0};
    char *strP = str;
    int n = 0;

    printf("input: ");
    scanf("%s", &str);
    printf("output: ");
    
    for(; *strP != 0; strP++){
        if(*strP == '('){
            n = push(&s, *strP);
        }else if(*strP == ')'){
            n = pop(&s);
        }
    }
    if(n == -1){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}