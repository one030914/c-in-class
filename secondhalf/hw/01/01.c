#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *prev, *next;
};
typedef struct Node Node;
typedef struct Node *NodeP;

typedef struct {
    NodeP head, tail;
    int len;
} DLL;
typedef DLL *DLLP;

DLLP init() {
    DLLP list = (DLLP)malloc(sizeof(DLL));
    if (list == NULL) {
        printf("failed to malloc.\n");
        exit(1);
    }

    list->head = NULL;
    list->tail = NULL;
    list->len = 0;

    return list;
}

NodeP new(int data){
    NodeP node = (NodeP)malloc(sizeof(Node));
    if (node == NULL) {
        printf("failed to malloc.\n");
        exit(1);
    }

    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void append(DLLP *listP, int data) {
    NodeP node = new(data);

    if ((*listP)->head == NULL && (*listP)->tail == NULL) {
        (*listP)->head = node;
        (*listP)->tail = node;
    } else {
        node->prev = (*listP)->tail;
        (*listP)->tail->next = node;
        (*listP)->tail = node;
    }
    (*listP)->len++;
}

int pop(DLLP *listP) {
    if ((*listP)->head == NULL && (*listP)->tail == NULL) {
        return -1;
    } else {
        int data = (*listP)->tail->data;
        NodeP prev = (*listP)->tail->prev;

        if (prev == NULL) {  // one node
            free((*listP)->tail);
            (*listP)->head = NULL;
            (*listP)->tail = NULL;
        } else {
            prev->next = NULL;
            free((*listP)->tail);
            (*listP)->tail = prev;
        }
        (*listP)->len--;
        return data;
    }
}

void insert(DLLP *listP, int index, int data) {
    int length = (*listP)->len;

    if (index < 0) {
        index = length + index;
    }

    if (length == 0 && (index == 0 || index == -1)) {
        append(listP, data);
        return;
    }

    if (index < 0) {
        printf("index out of range.\n");
        return;
    }

    if ((*listP)->head == NULL && (*listP)->tail == NULL) {
        append(listP, data);
    } else {
        NodeP node = new(data);
        NodeP current = (*listP)->head;

        if (index <= length / 2) {
            current = (*listP)->head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
        } else {
            current = (*listP)->tail;
            for (int i = length - 1; i > index; i--) {
                current = current->prev;
            }
        }

        if (index == 0) { // at first
            node->next = current;
            current->prev = node;
            (*listP)->head = node;
        } else if (index >= length) { // at last
            node->prev = current;
            current->next = node;
            (*listP)->tail = node;
        } else { // in middle
            node->prev = current->prev;
            node->next = current;
            current->prev->next = node; // current previous node's next pointer is node.
            current->prev = node; // current node's previous pointer is node.
        }
        (*listP)->len++;
    }
}

void deleteV(DLLP *listP, int data) {
    int length = (*listP)->len;

    if (length == 0) return;

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
            (*listP)->len--;
            return;
        }
        current = current->next;
    }
}

void deleteI(DLLP *listP, int index) {
    int length = (*listP)->len;

    if (index < 0) {
        index = length + index;
    }

    if (index < 0) {
        printf("index out of range.\n");
        return;
    }

    NodeP current = (*listP)->head;

    if (index <= length / 2) {
        current = (*listP)->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        current = (*listP)->tail;
        for (int i = length - 1; i > index; i--) {
            current = current->prev;
        }
    }

    if (index == 0) { // at first
        (*listP)->head = current->next;
        if ((*listP)->head != NULL) {
            current->next->prev = NULL;
        } else { // one node
            (*listP)->tail = NULL;
        }
        free(current);
    } else if (current->next == NULL) { // at last
        (*listP)->tail = current->prev;
        if ((*listP)->tail != NULL) {
            (*listP)->tail->next = NULL;
        } else { // one node
            (*listP)->head = NULL;
        }
        free(current);
    } else { // in middle
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    (*listP)->len--;
}

void show(const DLLP *listP) {
    int i = 0;
    NodeP current = (*listP)->head;

    while (current != NULL) {
        if (i++ > 0) printf(" ");
        printf("%d", current->data);
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
            insert(&route, 0, data);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%d", &data);
            deleteV(&route, data);
        } else if (strcmp(cmd, "deleteFirst") == 0) {
            deleteI(&route, 0);
        } else if (strcmp(cmd, "deleteLast") == 0) {
            deleteI(&route, -1);
        }
    }
    show(&route);

    return 0;
}