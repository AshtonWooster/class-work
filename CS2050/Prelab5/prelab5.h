#ifndef PRELAB5_H_
#define PRELAB5_H_
#include <stdio.h>

typedef struct GroceryList {
    int length;
    int maxLength;
    char** list;

} GroceryList;

GroceryList GroceryListInit(int maxLength, int *errorCode);
GroceryList GroceryListAppend(GroceryList glist, char * itemName, int * errorCode);
void outputList(GroceryList glist);
char * GroceryListGetItem(GroceryList glist, int k, int *errorCode);
void GroceryListDelete(GroceryList glist);

#endif