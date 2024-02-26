#include "lab5.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    VendingMachine* myMachine = newMachine(10);
    StockItem newItem = {1, 2};
    StockItem otherItem = {2, 2};
    StockItem thirdItem = {3, 2};
    StockItem fourthItem = {4, 2};
    StockItem placeholder = {0,0,0,0};

    outputInfo(myMachine);

    addStockItem(myMachine, newItem);
    outputInfo(myMachine);
    printf("IN STOCK: %d\n", countInStock(myMachine));
    printf("Added 2: %d\n", addStockItem(myMachine, otherItem));
    outputInfo(myMachine);
    printf("REMOVED 1: %d\n", removeStockItem(myMachine, 1, &placeholder));
    printf("IN STOCK: %d\n", countInStock(myMachine));
    outputInfo(myMachine);
    printf("Added 3, 4: %d %d\n", addStockItem(myMachine, thirdItem), addStockItem(myMachine, fourthItem));
    outputInfo(myMachine);
    printf("\n Adding 10 times.\n");
    for (int i = 0; i < 10; i++) {
        printf("%d", addStockItem(myMachine, newItem));
    }
    outputInfo(myMachine);
    printf("IN STOCK: %d\n", countInStock(myMachine));
    removeStockItem(myMachine, 2, &placeholder);
    printf("%d\n", placeholder.ID);
    outputInfo(myMachine);
    printf("ATTEMPTING 2 AGAIN: %d\n", removeStockItem(myMachine, 2, &placeholder));
    outputInfo(myMachine);
    printf("IN STOCK: %d\n", countInStock(myMachine));

    freeVendingMachine(myMachine);

    return 0;
}
