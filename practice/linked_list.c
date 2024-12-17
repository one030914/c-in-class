#include <stdio.h>
#include <stdlib.h>

struct node{
    int lng; //longitude
    int lat; //latitude
    struct node *next;
};
typedef struct node location;
typedef struct node *locPtr;

locPtr cLoc(int lng, int lat);
void append(locPtr *listPtr, locPtr loc);
void insert(locPtr *listPtr, int index, locPtr loc);
void show(locPtr listPtr);
//add a deletion function and a free function.

int main(){
    int x, y, i;
    locPtr route = NULL;

    printf("Enter location(i, x, y): ");

    while(scanf("%d%d%d", &i, &x, &y) != EOF){
        insert(&route, i, cLoc(x, y));
        show(route);

        printf("Enter location(i, x, y): ");
    }

    return 0;
}

locPtr cLoc(int lng, int lat){
    locPtr loc = (locPtr) malloc(sizeof(location));

    if(loc != NULL){
        loc->lng = lng;
        loc->lat = lat;
        loc->next = NULL;
    }

    return loc;
}

void append(locPtr *listPtr, locPtr loc){
    if(*listPtr == NULL){
        // if the list is empty,
        // let 'loc' become the head of list.
        *listPtr = loc;
    }else{
        // if the list is NOT empty,
        // follow the link to find the tail.
        locPtr tail = *listPtr;
        while(tail->next != NULL){
            tail = tail->next;
        }

        // let 'loc' become new tail.
        tail->next = loc;
    }
}

void insert(locPtr *listPtr, int index, locPtr loc){
    if(*listPtr == NULL || index == -1){
        append(listPtr, loc);
    }else if(index == 0){
        loc->next = *listPtr;
        *listPtr = loc;
    }else{
        // if the list is NOT empty,
        // follow the link to the (index-1)-th node
        locPtr currentPtr = *listPtr;
        for(int i = 1; i < index; i++){
            if(currentPtr->next != NULL){
                currentPtr = currentPtr->next;
            }else{
                break;
            }
        }

        // insert 'loc' after current
        locPtr nextPtr = currentPtr->next;
        currentPtr->next = loc;
        loc->next = nextPtr;
    }
}

void show(locPtr listPtr){
    int i = 0;
    printf("----\nRoute:\n");

    while(listPtr != NULL){
        // print the current location and its memory address
        printf("%2d.", i);
        printf(" (%3d, %3d)", listPtr->lng, listPtr->lat);
        printf(" %p", listPtr);
        printf(" => %p\n", listPtr->next);

        // move the pointer to the next location
        listPtr = listPtr->next;

        i++;
    }

    printf("------------\n");
}