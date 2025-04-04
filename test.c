#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *prev, *next;
};

struct Node *nil;

void init() {
    nil = (struct Node *)malloc(sizeof(struct Node));
    nil->next = nil;
    nil->prev = nil;
}

void insert(int key) {
    struct Node *x = (struct Node *)malloc(sizeof(struct Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

struct Node *listSearch(int key) {
    struct Node *cur = nil->next;
    while (cur != nil && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

void deleteNode(struct Node *t) {
    if (t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}
void deleteKey(int key) {
    deleteNode(listSearch(key));
}

void printList() {
    struct Node *cur;
    cur = nil->next;
    int isf = 0;

    while (1) {
        if (cur == nil) break;
        if (isf++ > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}


int main(void) {
    int key, n, i;
    int size = 0;
    char com[20];
    int np = 0, nd = 0;
    scanf("%d", &n);
    init();
    for (i = 0; i < n; i++) {
        scanf("%s%d", com, &key);
        if (com[0] == 'i') {
            insert(key);
            np++;
            size++;
        } else if (com[0] == 'd') {
            if (strlen(com) > 6) {
                if (com[6] == 'F') {
                    deleteFirst();
                } else if (com[6] == 'L') {
                    deleteLast();
                }
            } else {
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }
    printList();
    return 0;

}