#include <stdio.h>
#define SIZE 1024

typedef struct{
    char date[10];
    int balance;
    char note[SIZE];
} Record;

int main(){
    char cmd;
    Record r;

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
                scanf("%s %d %s", r.date, &r.balance, r.note);
                fprintf(fp, "%s %d %s\n", r.date, r.balance, r.note);
                printf("Received.\n");
                break;
            case 'S':
                while(!feof(fp)){
                    fscanf(fp, "%s %d %s\n", r.date, &r.balance, r.note);
                    printf("%s %d %s\n", r.date, r.balance, r.note);
                }
                break;
            case 'C':
                int balance = 0;
                while(!feof(fp)){
                    fscanf(fp, "%s %d %s\n", r.date, &r.balance, r.note);
                    balance += r.balance;
                }
                printf("Balance = %d\n", balance);
                break;
            case 'E':
                printf("Bye.\n");
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
