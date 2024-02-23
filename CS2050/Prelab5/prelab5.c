#include "prelab5.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

GroceryList GroceryListInit(int maxLength, int *errorCode) {
    GroceryList list = {0, 0, NULL};
    list.list = (char**)malloc(sizeof(char*) * maxLength);
    
    if (!list.list) {
        *errorCode = 1;
        return list;
    }

    list.maxLength = maxLength;
    for (int i  = 0; i < maxLength; i++) {
        list.list[i] = NULL;
    }

    *errorCode = 0;
    return list;
}

GroceryList GroceryListAppend(GroceryList glist, char * itemName, int * errorCode) {
    if (glist.length == glist.maxLength) {
        *errorCode = 2;
        return glist;
    }

    int i = glist.length;
    int nameLength = strlen(itemName);
    glist.list[i] = (char*)malloc(sizeof(char) * nameLength + sizeof(char));

    if (!glist.list[i]) {
        *errorCode = 1;
        return glist;
    }

    glist.list[i][nameLength] = '\0';
    strncpy(glist.list[i], itemName, nameLength);

    glist.length++;
    *errorCode = 0;
    return glist;
}

char * GroceryListGetItem(GroceryList glist, int k, int *errorCode) {
    if (k > glist.length) {
        *errorCode = 1;
        return NULL;
    }

    *errorCode = 0;
    return glist.list[k];
}

void outputList(GroceryList glist) {
    printf("GROCERY LIST\n");
    printf("-----------------------\n");
    for (int i = 0; i < glist.length; i++) {
        printf("%s\n", glist.list[i]);
    }
    printf("-----------------------\n");
}

void GroceryListDelete(GroceryList glist) {
    for (int i = 0; i < glist.length; i++) {
        free(glist.list[i]);
        glist.list[i] = NULL;
    }

    free(glist.list);
    glist.list = NULL;
    glist.length = 0;
    glist.maxLength = 0;
}
