#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 500

typedef struct{
    char name[MAXSIZE];
    char phone[MAXSIZE];
} contact;

contact *lookup(contact *dict[], const char key[]);
contact *byName(contact *dict[], unsigned int len);
contact *byPhone(contact *dict[], unsigned int len);

int main(){
    contact contacts[MAXSIZE];
    contact *conPtrs[MAXSIZE];

    for(int i = 0; i < MAXSIZE; i++){
        contacts[i].name[0] = '\0';
        contacts[i].phone[0] = '\0';
        conPtrs[i] = &contacts[i];
    }

    char bufn[MAXSIZE];
    char bufp[MAXSIZE];
    unsigned int index = 0;

    while(scanf("%s%s", bufn, bufp) != EOF){
        if(strcmp(bufn, "0\0") == 0 && strcmp(bufp, "0\0") == 0){
            break;
        }else{
            strcpy(conPtrs[index]->name, bufn);
            strcpy(conPtrs[index++]->phone, bufp);
        }
    }

    char cmd, key[MAXSIZE];
    contact *person;

    while(1){
        printf("--\n(s) show\n(l) lookup\n(n) sort by name\n(p) sort by phone\n(q) quit\nChoose your action: ");
        scanf("%s", &cmd);
        switch (cmd){
            case 's':
                //show
                printf("--\n");
                for(int i = 0; i < index; i++){
                    printf("%s, %s\n", conPtrs[i]->name, conPtrs[i]->phone);
                }
                break;
            case 'l':
                //lookup
                scanf("%s", key);
                person = lookup(conPtrs, key);
                printf("--\n%s\n", person->phone);
                break;
            case 'n':
                //sort by name
                byName(conPtrs, index);
                printf("--\n");
                for(int i = 0; i < index; i++){
                    printf("%s, %s\n", conPtrs[i]->name, conPtrs[i]->phone);
                }
                continue;
            case 'p':
                //sort by phone
                byPhone(conPtrs, index);
                printf("--\n");
                for(int i = 0; i < index; i++){
                    printf("%s, %s\n", conPtrs[i]->name, conPtrs[i]->phone);
                }
                break;
            case 'q':
                //quit
                exit(0);
            default:
                printf("Invalid command\n");
                break;
        }
    }
    return 0;
}

contact *lookup(contact *dict[], const char key[]){
    for(int i = 0; i < MAXSIZE; i++){
        if(strcmp(key, dict[i]->name) == 0){
            return dict[i];
        }
    }
    return NULL;
}

contact *byName(contact *dict[], unsigned int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(strcmp(dict[j]->name, dict[j + 1]->name) > 0){
                contact *tmp = dict[j];
                dict[j] = dict[j + 1];
                dict[j + 1] = tmp;
            }
        }
    }
    return *dict;
}

contact *byPhone(contact *dict[], unsigned int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(strcmp(dict[j]->phone, dict[j + 1]->phone) > 0){
                contact *tmp = dict[j];
                dict[j] = dict[j + 1];
                dict[j + 1] = tmp;
            }
        }
    }
    return *dict;
}