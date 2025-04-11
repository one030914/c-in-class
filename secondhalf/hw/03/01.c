#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right, *parent;
};
typedef struct Node Node;
typedef struct Node *NodeP;

NodeP new(int data){
    NodeP nodeP = (NodeP) malloc(sizeof(Node));
    if(nodeP != NULL){
        nodeP->data = data;
        nodeP->left = NULL;
        nodeP->right = NULL;
        nodeP->parent = NULL;
    }
    return nodeP;
}

void preO(const NodeP nodeP){
    if (nodeP == NULL) return;

    printf(" %d", nodeP->data);
    preO(nodeP->left);
    preO(nodeP->right);
}

void inO(const NodeP nodeP){
    if (nodeP == NULL) return;

    inO(nodeP->left);
    printf(" %d", nodeP->data);
    inO(nodeP->right);
}

void postO(const NodeP nodeP){
    if (nodeP == NULL) return;

    postO(nodeP->left);
    postO(nodeP->right);
    printf(" %d", nodeP->data);
}

NodeP find(NodeP nodeP, const int data){
    while (nodeP != NULL){
        if (nodeP->data < data){
            nodeP = nodeP->right;
        } else if (nodeP->data > data){
            nodeP = nodeP->left;
        }else{
            return nodeP;
        }
    }
    return NULL;
}

void insert(NodeP *nodeP, int data){
    NodeP n = new(data);
    if(*nodeP == NULL){
        *nodeP = n;
    }else{
        NodeP cur = *nodeP;
        while(cur != NULL){
            if (cur->data <= data){ // greater, insert right
                if(cur->right == NULL){
                    cur->right = n;
                    n->parent = cur;
                    break;
                }
                cur = cur->right;
            }else if(cur->data > data){ // less, insert left
                if(cur->left == NULL){
                    cur->left = n;
                    n->parent = cur;
                    break;
                }
                cur = cur->left;
            }
        }
    }
}

void no_child(NodeP *nodeP, NodeP n){
    if(n->parent == NULL){
        *nodeP = NULL;
    }else if(n->parent->data < n->data){
        n->parent->right = NULL;
    }else{
        n->parent->left = NULL;
    }
    free(n);
}

void one_child(NodeP *nodeP, NodeP n){
    NodeP child = (n->left != NULL) ? n->left : n->right;
    if(n->parent == NULL){
        *nodeP = child;
        child->parent = NULL;
    }else{
        if(n->parent->left == n){
            n->parent->left = child;
        }else{
            n->parent->right = child;
        }
        child->parent = n->parent;
    }
    free(n);
}

void two_children(NodeP n){
    NodeP s = n->right;
    while(s->left != NULL){
        s = s->left;
    }
    n->data = s->data;

    if(s->parent == n){ // n's child is s
        if(s->right != NULL){ // has child
            n->right = s->right;
            s->right->parent = s->parent;
        }else{
            n->right = NULL;
        }
        free(s);
    }else{ // n's child isn't s
        if(s->parent->left == s){
            s->parent->left = s->right;
        }else{
            s->parent->right = s->right;
        }
        if(s->right != NULL){
            s->right->parent = s->parent;
        }
        free(s);
    }
}

void delete(NodeP *node, int data){
    NodeP n = find(*node, data);
    if(n != NULL){
        if(n->left == NULL && n->right == NULL){
            no_child(node, n);
        }else if(n->left == NULL || n->right == NULL){
            one_child(node, n);
        }else{
            two_children(n);
        }
    }else{
        return;
    }
}

int main(){
    int n = 0, data = 0;
    char cmd[10] = {0};
    NodeP root = NULL;

    scanf("%d", &n);
    while(n--){
        scanf("%s", &cmd);
        switch (cmd[0]){
            case 'i':
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 'f':
                scanf("%d", &data);
                NodeP cur = find(root, data);
                if(cur == NULL){
                    printf("no\n");
                }else{
                    printf("yes\n");
                }
                break;
            case 'p':
                inO(root);
                printf("\n");
                preO(root);
                printf("\n");
                break;
            case 'd':
                scanf("%d", &data);
                delete(&root, data);
                break;
        }
    }

    return 0;
}