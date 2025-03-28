#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};
typedef struct Node Node;
typedef struct Node *NodeP;

typedef struct {
    NodeP head, tail;
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

int len(const DLLP *listP) {
    int count = 0;
    NodeP current = (*listP)->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void append(DLLP *listP, int data) {
    NodeP node = new(data);

    if ((*listP)->head == NULL && (*listP)->tail == NULL) {
        (*listP)->head = node;
        (*listP)->tail = node;
    } else if ((*listP)->head == NULL || (*listP)->tail == NULL) {
        printf("head or tail is NULL, it shouldn't happen.\n");
    } else {
        node->prev = (*listP)->tail;
        (*listP)->tail->next = node;
        (*listP)->tail = node;
    }
}

int pop(DLLP *listP) {
    if ((*listP)->head == NULL && (*listP)->tail == NULL) {
        return -1;
    } else if ((*listP)->head == NULL || (*listP)->tail == NULL) {
        printf("head or tail is NULL, it shouldn't happen.\n");
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
        return data;
    }
}

void insert(DLLP *listP, int index, int data) {
    int length = len(listP);

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
    } else if ((*listP)->head == NULL || (*listP)->tail == NULL) {
        printf("head or tail is NULL, it shouldn't happen.\n");
    } else {
        NodeP node = new(data);
        NodeP current = (*listP)->head;
        for (int i = 0; i < index; i++) {
            if (current->next != NULL) {
                current = current->next;
            } else {
                break;
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
    }
}

void delete(DLLP *listP, int index) {
    int length = len(listP);

    if (index < 0) {
        index = length + index;
    }

    if (index < 0) {
        printf("index out of range.\n");
        return;
    }

    if ((*listP)->head == NULL && (*listP)->tail == NULL) {
        printf("list is empty, can't be removed.\n");
        return;
    } else if ((*listP)->head == NULL || (*listP)->tail == NULL) {
        printf("head or tail is NULL, it shouldn't happen.\n");
    } else {
        NodeP current = (*listP)->head;

        for (int i = 0; i < index; i++) {
            if (current->next != NULL) {
                current = current->next;
            } else {
                break;
            }
        }
        printf("%d\n", current->data);
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
    }
}

void show(const DLLP *listP) {
    printf("\n-------------------------\n");
    printf("Route:\n");

    int i = 0;
    NodeP current = (*listP)->head;

    while (current != NULL) {
        if (i++ > 0) printf("<->");
        printf("%d", current->data);
        current = current->next;
    }

    printf("\n-------------------------\n");
}

int main() {
    int data = 0, i = 100;
    DLLP route = NULL;

    // scanf("%d%d", &data, &i);
    route = init();
    insert(&route, 100, 999); // 超過長度，應該報錯
    show(&route);

    return 0;
}