#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};
typedef struct Node Node;
typedef struct Node *NodeP;

typedef struct{
    NodeP head, tail;
} DLL;
typedef DLL *DLLP;

DLLP init(){
    DLLP list = (DLLP) malloc(sizeof(DLL));
    if(list == NULL){
        printf("failed to malloc.\n");
        exit(1);
    }

    list->head = NULL;
    list->tail = NULL;

    return list;
}

NodeP new(int data){
    NodeP node = (NodeP) malloc(sizeof(Node));
    if(node == NULL){
        printf("failed to malloc.\n");
        exit(1);
    }

    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void append(DLLP *listP, int data){
    NodeP node = new(data);

    if((*listP)->head == NULL && (*listP)->tail == NULL){
        (*listP)->head = node;
        (*listP)->tail = node;
    }else if((*listP)->head == NULL || (*listP)->tail == NULL){
        printf("head or tail is NULL, it shouldn't happen.\n");
    }else{
        node->prev = (*listP)->tail;
        (*listP)->tail->next = node;
        (*listP)->tail = node;
    }
}

int pop(DLLP *listP){
    if((*listP)->head == NULL && (*listP)->tail == NULL){
        return -1;
    }else if((*listP)->head == NULL || (*listP)->tail == NULL){
        printf("head or tail is NULL, it shouldn't happen.\n");
    }else{
        int data = (*listP)->tail->data;
        NodeP prev = (*listP)->tail->prev;
        prev->next = NULL;
        free((*listP)->tail);
        return data;
    }
}

void insert(DLLP *listP, int index, int data){
    NodeP node = new(data);

    if((*listP)->head == NULL && (*listP)->tail == NULL){
        append(listP, data);
    }else if((*listP)->head == NULL || (*listP)->tail == NULL || index == -1){
        printf("head or tail is NULL, it shouldn't happen.\n");
    }else{
        NodeP current = (*listP)->head;
        for(int i = 1; i < index; i++){
            if(current->next != NULL){
                current = current->next;
            }else{
                break;
            }
        }
        if(current->prev == NULL){ // at first
            printf("first.\n");
        }else if(current->next == NULL){ // at last
            printf("last.\n");
        }else{
            printf("middle.\n");
        }
    }
}

// int remove();

void show(const DLLP *listP){
    printf("\n-------------------------\n");
    printf("Route:\n");

    int i = 0;
    NodeP current = (*listP)->head;
    
    while(current != NULL){
        if(i++ > 0) printf("<->");
        printf("%d", current->data);
        current = current->next;
    }

    printf("\n-------------------------\n");
}

int main(){
    int data = 0, i = 0;
    DLLP route = NULL;

    // scanf("%d%d", &data, &i);
    route = init();
    append(&route, 10);
    append(&route, 20);
    show(&route);
    data = pop(&route);
    insert(&route, 0, 30);
    show(&route);

    return 0;
}