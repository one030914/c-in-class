#include <stdio.h>
#define SIZE 1024

typedef struct{
    char date[10];
    int balance;
    char note[SIZE];
} Person;

int main(){
    char cmd, msg[SIZE];
    int balance = 0;
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

        printf("================================\n");
        switch(cmd){
            case 'A':
                printf("Please enter a record: ");
                scanf("%s %d %s", p.date, &p.balance, p.note);
                fprintf(fp, "%s %d %s\n", p.date, p.balance, p.note);
                printf("Received.\n");
                break;
            case 'S':
                while(1){
                    if(feof(fp)) break;
                    fscanf(fp, "%s %d %s\n", p.date, &p.balance, p.note);
                    printf("%s %d %s\n", p.date, p.balance, p.note);
                }
                break;
            case 'C':
                while(1){
                    if(feof(fp)) break;
                    fscanf(fp, "%s %d %s\n", p.date, &p.balance, p.note);
                    balance += p.balance;
                }
                printf("Balance = %d\n", balance);
                break;
            case 'E':
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
        printf("================================\n");
        fclose(fp);
    }

    return 0;
}
