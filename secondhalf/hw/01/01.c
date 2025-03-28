#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *prev, *next;
};
typedef struct Node Node;
typedef struct Node *NodeP;

NodeP route;

void init() {
    route = (NodeP)malloc(sizeof(Node));
    if (route == NULL) exit(1);

    route->next = route;
    route->prev = route;
}

void insert(int data) {
    NodeP node = (NodeP)malloc(sizeof(Node));
    if (node == NULL) exit(1);
    NodeP head = route->next;

    node->data = data;
    node->next = head; // insert a node at the front.
    head->prev = node; // the head point to the node.
    head = node; // move the head to the node.
    node->prev = route; // 
}

void deleteV(DLLP *listP, int data) {
    NodeP current = (*listP)->head;

    while (current != NULL) {
        if (current->data == data) {
            if (current->prev) {
                current->prev->next = current->next;
            } else { // at first
                (*listP)->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else { // at last
                (*listP)->tail = current->prev;
            }

            free(current);
            return;
        }
        current = current->next;
    }
}

void deleteF(DLLP *listP) {
    if ((*listP)->head == NULL) return;

    NodeP node = (*listP)->head;
    (*listP)->head = node->next;

    if ((*listP)->head) {
        (*listP)->head->prev = NULL;
    } else { // at first
        (*listP)->tail = NULL;
    }
    free(node);
}

void deleteL(DLLP *listP) {
    if ((*listP)->tail == NULL) return;

    NodeP node = (*listP)->tail;
    (*listP)->tail = node->prev;

    if ((*listP)->tail) {
        (*listP)->tail->next = NULL;
    } else { // at last
        (*listP)->head = NULL;
    }
    free(node);
}

void show(const DLLP *listP) {
    int flag = 0;
    NodeP current = (*listP)->head;

    while (current != NULL) {
        if (flag) printf(" ");
        printf("%d", current->data);
        flag = 1;
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n = 0, data = 0;
    char cmd[16] = { 0 };
    DLLP route = NULL;
    route = init();

    scanf("%d", &n);
    while (n--) {
        scanf("%s", &cmd);
        if (strcmp(cmd, "insert") == 0) {
            scanf("%d", &data);
            insert(&route, data);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%d", &data);
            deleteV(&route, data);
        } else if (strcmp(cmd, "deleteFirst") == 0) {
            deleteF(&route);
        } else if (strcmp(cmd, "deleteLast") == 0) {
            deleteL(&route);
        }
    }
    show(&route);

    return 0;
}