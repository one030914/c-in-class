#include <stdio.h>
#define SIZE 1024

typedef struct{
    char date[10];
    int balance;
    char name[30];
} Person;

int main(){
    char cmd, msg[SIZE];
    Person p;

    while(1){
        FILE *fp = fopen("expense.txt", "a+");
        if(fp == NULL){
            printf("failed to open.\n");
            return 1;
        }

        printf("[Menu]\n");
        printf("(A)dd record\n");
        printf("(S)how records\n");
        printf("(C)alculate balance\n");
        printf("(E)xit\n\n");
        printf("Action: ");
        
        if(scanf(" %c", &cmd) == EOF) break;
        if(cmd >= 'a' && cmd <= 'z') cmd -= 32;
    
        switch(cmd){
            case 'A':
                printf("Please enter a record: ");
                scanf("%s %d %s", p.date, &p.balance, p.name);
                printf("%s %d %s\n", p.date, p.balance, p.name);
                fprintf(fp, "%s %d %s\n", p.date, p.balance, p.name);
                break;
            case 'S':
                break;
            case 'C':
                break;
            case 'E':
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
        fclose(fp);
    }

    return 0;
}
