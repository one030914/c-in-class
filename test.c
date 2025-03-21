#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};
typedef struct Node node;
typedef struct Node *nodeP;

nodeP init(int data){
    nodeP list = (nodeP) malloc(sizeof(node));
    if(list != NULL){
        list->data = data;
        list->prev = NULL;
        list->next = NULL;
    }

    return list;
}

void append(nodeP *listP, nodeP list){
    if(*listP == NULL){
        *listP = list;
    }else{ // not empty
        nodeP tail = *listP;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = list;
        list->prev = tail;
        list->next = NULL;
    }
}

int pop(nodeP *listP){
    if(*listP == NULL){
        return -1;
    }else{
        nodeP tail = *listP;
        while(tail->next != NULL){
            tail = tail->next;
        }
        nodeP prev = tail->prev;
        free(tail);
        prev->next = NULL;
        return prev->data;
    }
}

void insert(int index, nodeP *listP, nodeP list){
    if(*listP == NULL || index == -1){
        append(listP, list);
    }else if(index == 0){
        list->next = *listP;
        *listP = list;
    }else{
        nodeP current = *listP;
        for(int i = 0; i < index; i++){ // iter to index
            if(current->next != NULL){
                current = current->next;
            }else{
                break;
            }
        }

        nodeP prev = current->prev;
        nodeP next = current->next;
        prev = list;
        next = list;
        list->prev = prev;
        list->next = next;
    }
}

// int remove();

void show(nodeP list){
    int i = 0;
    printf("--------------------\n");
    printf("Route:\n");
    
    while(list != NULL){
        if(i++ > 0){
            printf("->");
        }
        printf("%d", list->data);
        
        list = list->next;
    }
    printf("\n--------------------\n");
}

int main(){
    int data = 0, i = 0;
    nodeP route = NULL;

    scanf("%d%d", &data, &i);
    route = init(data);
    append(&route, init(10));
    data = pop(&route);
    append(&route, init(10));
    insert(1, &route, init(12));
    show(route);

    return 0;
}