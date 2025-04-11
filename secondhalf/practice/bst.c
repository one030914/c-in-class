#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
typedef struct Node Node;
typedef struct Node *NodeP;

NodeP new(int data){
    NodeP nodeP = (NodeP) malloc(sizeof(Node));
    if(nodeP != NULL){
        nodeP->data = data;
        nodeP->left = NULL;
        nodeP->right = NULL;
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
            if (cur->data <= data){
                if(cur->right == NULL){
                    cur->right = n;
                    break;
                }
                cur = cur->right;
            }else if(cur->data > data){
                if(cur->left == NULL){
                    cur->left = n;
                    break;
                }
                cur = cur->left;
            }
        }
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
        }
    }

    return 0;
}