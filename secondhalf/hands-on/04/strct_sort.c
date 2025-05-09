#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 1200000

typedef struct{
    char date[10];
    int balance;
    char note[SIZE];
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

Record *byDate(Record *data[], unsigned int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(strcmp(data[j]->date, data[j + 1]->date) > 0){
                Record *tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    return *data;
}

Record *byBal(Record *data[], unsigned int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(data[j]->balance > data[j + 1]->balance){
                Record *tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = data[j];
            }
        }
    }
    return *data;
}

Record *byNote(Record *data[], unsigned int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(strcmp(data[j]->note, data[j + 1]->note) > 0){
                Record *tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    return *data;
}

int main(){
    clock_t start, end;
    double timer;
    int size = 0;
    Record *q_arr = (Record *)calloc(SIZE, sizeof(Record));
    Record *b_arr = (Record *)calloc(SIZE, sizeof(Record));
    
    start = clock();
    FILE *read = fopen("expense_1M.txt", "r");
    while(!feof(read)){
        fscanf(read, "%s %d %s\n", q_arr->date, &q_arr->balance, q_arr->note);
        size++;
    }
    memcpy(b_arr, q_arr, SIZE * sizeof(Record *));
    printf("%s %s", b_arr[0].date, q_arr[0].date);
    end = clock();
    timer = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Read time used: %.6f seconds.\n", timer);

    FILE *qdate = fopen("expense_1M_Qdate.txt", "w");
    FILE *qbal = fopen("expense_1M_Qbal.txt", "w");
    FILE *qnote = fopen("expense_1M_Qnote.txt", "w");
    FILE *bdate = fopen("expense_1M_Bdate.txt", "w");
    FILE *bbal = fopen("expense_1M_Bbal.txt", "w");
    FILE *bnote = fopen("expense_1M_Bnote.txt", "w");

    return 0;
}