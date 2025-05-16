#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TEXT 1024
#define SIZE 1200000

typedef struct{
    char date[11];
    int balance;
    char note[TEXT];
} Record;

int acsDate(const void *a, const void *b){
    Record *ra = (Record *)a;
    Record *rb = (Record *)b;
    return strcmp(ra->date, rb->date);
}

int acsBal(const void *a, const void *b){
    Record *ra = (Record *)a;
    Record *rb = (Record *)b;
    return ra->balance - rb->balance;
}

int acsNote(const void *a, const void *b){
    Record *ra = (Record *)a;
    Record *rb = (Record *)b;
    return strcmp(ra->note, rb->note);
}

Record *byDate(Record data[], unsigned int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(strcmp(data[j].date, data[j + 1].date) > 0){
                Record tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    return data;
}

Record *byBal(Record data[], unsigned int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(data[j].balance > data[j + 1].balance){
                Record tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = data[j];
            }
        }
    }
    return data;
}

Record *byNote(Record data[], unsigned int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(strcmp(data[j].note, data[j + 1].note) > 0){
                Record tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    return data;
}

int main(){
    clock_t start, end;
    double timer;
    int size = 0, bufB = 0;
    char bufD[11], bufN[TEXT];
    Record *qdate = (Record *)calloc(SIZE, sizeof(Record));
    Record *qbal = (Record *)calloc(SIZE, sizeof(Record));
    Record *qnote = (Record *)calloc(SIZE, sizeof(Record));
    Record *bdate = (Record *)calloc(SIZE, sizeof(Record));
    Record *bbal = (Record *)calloc(SIZE, sizeof(Record));
    Record *bnote = (Record *)calloc(SIZE, sizeof(Record));

    start = clock();
    FILE *read = fopen("expense_1M.txt", "r");
    while(!feof(read)){
        fscanf(read, "%s %d %s\n", bufD, &bufB, bufN);
        strcpy(qdate[size].date, bufD);
        qdate[size].balance = bufB;
        strcpy(qdate[size].note, bufN);
        size++;
    }
    memcpy(qbal, qdate, SIZE * sizeof(Record));
    memcpy(qnote, qdate, SIZE * sizeof(Record));
    memcpy(bdate, qdate, SIZE * sizeof(Record));
    memcpy(bbal, qdate, SIZE * sizeof(Record));
    memcpy(bnote, qdate, SIZE * sizeof(Record));
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Read time used: %.6f seconds.\n", timer);

    FILE *Qdate = fopen("expense_1M_Qdate.txt", "w");
    FILE *Qbal = fopen("expense_1M_Qbal.txt", "w");
    FILE *Qnote = fopen("expense_1M_Qnote.txt", "w");
    FILE *Bdate = fopen("expense_1M_Bdate.txt", "w");
    FILE *Bbal = fopen("expense_1M_Bbal.txt", "w");
    FILE *Bnote = fopen("expense_1M_Bnote.txt", "w");

    start = clock();
    qsort(qdate, size, sizeof(Record), acsDate);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Qsort Date time used: %.6f seconds.\n", timer);

    start = clock();
    qsort(qbal, size, sizeof(Record), acsBal);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Qsort Balance time used: %.6f seconds.\n", timer);
    
    start = clock();
    qsort(qnote, size, sizeof(Record), acsNote);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Qsort Note time used: %.6f seconds.\n", timer);

    start = clock();
    bdate = byDate(bdate, size);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Date time used: %.6f seconds.\n", timer);
    
    start = clock();
    bbal = byBal(bbal, size);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Balance time used: %.6f seconds.\n", timer);

    start = clock();
    bnote = byNote(bnote, size);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Note time used: %.6f seconds.\n", timer);

    start = clock();
    int index = 0;
    while(index < size){
        fprintf(Qdate, "%s %d %s\n", qdate[index].date, qdate[index].balance, qdate[index].note);
        fprintf(Qbal, "%s %d %s\n", qbal[index].date, qbal[index].balance, qbal[index].note);
        fprintf(Qnote, "%s %d %s\n", qnote[index].date, qnote[index].balance, qnote[index].note);
        fprintf(Bdate, "%s %d %s\n", bdate[index].date, bdate[index].balance, bdate[index].note);
        fprintf(Bbal, "%s %d %s\n", bbal[index].date, bbal[index].balance, bbal[index].note);
        fprintf(Bnote, "%s %d %s\n", bnote[index].date, bnote[index].balance, bnote[index].note);
        index++;
    }
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Write time used: %.6f seconds.\n", timer);

    return 0;
}