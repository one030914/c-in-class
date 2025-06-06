#include <stdio.h>
#include <string.h>
#define SIZE 1024

typedef struct {
    char date[10];
    int balance;
    char note[SIZE];
} Record;

int main(int argc, char *argv[]) {
    char cmd, file[SIZE];
    Record r;
    if (argv[1] == NULL) {
        strcpy(file, "expense.txt");
    } else {
        strcpy(file, argv[1]);
    }

    while (1) {
        FILE *fp = fopen(file, "a+");
        if (fp == NULL) {
            printf("failed to open.\n");
            return 1;
        }

        printf("[Menu]\n");
        printf("(A)dd record\n");
        printf("(S)how records\n");
        printf("(C)alculate balance\n");
        printf("(E)xit\n\n");
        printf("Action: ");

        if (scanf(" %c", &cmd) == EOF) break;
        if (cmd >= 'a' && cmd <= 'z') cmd -= 32;

        printf("================================\n");
        switch (cmd) {
        case 'A':
            printf("Ex. 2023-10-01 1000 Lunch\n");
            printf("Please enter a record: ");
            scanf("%s %d %s", r.date, &r.balance, r.note);
            fprintf(fp, "%s %d %s\n", r.date, r.balance, r.note);
            printf("Received.\n");
            break;
        case 'S':
            while (1) {
                fscanf(fp, "%s %d %s\n", r.date, &r.balance, r.note);
                if (feof(fp)) break;
                printf("%s %d %s\n", r.date, r.balance, r.note);
            }
            break;
        case 'C':
            int balance = 0;
            while (1) {
                fscanf(fp, "%s %d %s\n", r.date, &r.balance, r.note);
                if (feof(fp)) break;
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
