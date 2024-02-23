#include "prelab5.h"
#include <stdio.h>
#include <string.h>

int main() {
    int errorCode = 0;
    GroceryList myList = GroceryListInit(10, &errorCode);

    outputList(myList);
    myList = GroceryListAppend(myList, "Apple", &errorCode);
    myList = GroceryListAppend(myList, "Orange", &errorCode);
    printf("\n");
    outputList(myList);
    printf("Orange? %s\n", GroceryListGetItem(myList, 1, &errorCode));

    GroceryListDelete(myList);
    return 0;
}