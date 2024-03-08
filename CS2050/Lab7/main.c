#include "lab7.h"
#include <stdio.h>

int main() {

    VendingMachine * myMachine = newMachine();
    StockItem newItem = {1, 2};
    StockItem otherItem = {2, 2};
    StockItem thirdItem = {3, 5};
    StockItem placeholder = {0,0,0,0};
    StockItem result = {0};

    outputInfo(myMachine);
    printf("Added 1: %d\n", addStockItem(myMachine, newItem));
    printf("Added 2: %d\n", addStockItem(myMachine, otherItem));
    printf("Added 3: %d\n", addStockItem(myMachine, thirdItem));
    printf("ITEMS: %d\n", countItems(myMachine));
    printf("EMPTY: %d\n", countEmpty(myMachine));
    printf("Added 0: %d\n", addStockItem(myMachine, placeholder));
    printf("ITEMS: %d\n", countItems(myMachine));
    printf("EMPTY: %d\n", countEmpty(myMachine));
    printf("\n\n");
    printf("FINDING 1: %d\n", getStockItem(myMachine, 1, &result));
    printf("Result: %d\n", result.ID);
    printf("FINDING 8: %d\n", getStockItem(myMachine, 8, &result));
    printf("Result: %d\n", result.ID);
    outputInfo(myMachine);

    freeVendingMachine(myMachine);

    return 0;
}
