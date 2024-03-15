#include <stdio.h>
#include <stdlib.h>
#include "prelab8.h"

struct List_t {
    int object;
    List * next;
};

List * initList(int* ec) {
    List * list = (List*)malloc(sizeof(List));
    
    if (!list) {
        *ec = 1;
        return NULL;
    }

    list->object = 0;
    list->next = NULL;

    *ec = 0;
    return list;
}

List * insertAtHead(int obj, List* list, int* ec) {
    List * node = (List*)malloc(sizeof(List));

    if (!list) {
        *ec = 1;
        return list;
    }

    node->object = obj;
    node->next = list->next;
    list->next = node;

    *ec = 0;
    return list;
}

int getAtPosition(int i, List* list, int* ec) {
    List * currentNode = list;
    int count = 0;
    do {
        count++;
    } while((currentNode = currentNode->next) && count < i);

    if (currentNode && count == i) {
        *ec = 0;
        return currentNode->object;
    }

    *ec = 1;
    return 0;
}

int getListLength(List* list) {
    List * currentNode = list;
    int count = 0;
    while ((currentNode = currentNode->next)) {
        count++;
    }

    return count;
}

List * freeList(List* list) {
    List * nextNode = list;
    List * currentNode = list;

    do {
        nextNode = nextNode->next;
        free(currentNode);
    } while((currentNode = nextNode));

    return NULL;
}

List * insertAtPosition(int pos, int key, List* list, int* ec) {
    int count = 0;
    List * currentNode = list;
    do {
        count++;
    } while ((currentNode = currentNode->next) && count < (pos-1));

    if (count != (pos-1)) {
        *ec = 1;
        return list;
    }

    List * newNode = (List*)malloc(sizeof(List));
    
    if (!newNode) {
        *ec = 2;
        return list;
    }

    newNode->object = key;
    newNode->next = currentNode->next;
    currentNode->next = newNode;

    return list;
}

void outputInfo(List * list) {
    List * currentNode = list;
    int count = 0;

    printf("\nLIST INFO:\n");
    printf("------------------\n");
    while ((currentNode = currentNode->next)) {
        count++;
        printf("NODE %d: %d\n", count, currentNode->object);
    }
    printf("------------------\n\n");
}

List * removeAtPosition(int pos, List* list, int* ec) {
    int count = 1;
    List * currentNode = list;
    while (count < pos && (currentNode = currentNode->next)) {
        count++;
    }

    if (count != pos) {
        *ec = 1;
        return list;
    }

    List * toRemove = currentNode->next;

    if (!toRemove) {
        *ec = 1;
        return list;
    }

    currentNode->next = toRemove->next;
    free(toRemove);

    *ec = 0;
    return list;
}

List * removeObject(int obj, List* list, int* ec) {
    List * currentNode = list;
    int hasRemoved = 0;
    do {
        hasRemoved = 0;
        if (!currentNode->next || currentNode->next->object != obj) continue;

        List * toRemove = currentNode->next;

        currentNode->next = toRemove->next;
        free(toRemove);
        
        hasRemoved = 1;
    } while(currentNode->next && (hasRemoved || (currentNode = currentNode->next)));

    return list;
}
