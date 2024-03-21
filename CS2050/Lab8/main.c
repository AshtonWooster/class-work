#include <stdio.h>
#include "lab8.h"

int main() {
    VendingMachine * myMachine = newMachine();
    StockItem item1 = {1,1,1,1};
    StockItem item2 = {2,2,2,2};
    StockItem item3 = {3,3,3,3};
    StockItem result = {0,0,0,0};

    printIDS(myMachine);
    printf("Adding: %d\n", addStockItem(myMachine, item1, 1));
    printf("Adding: %d\n", addStockItem(myMachine, item2, 0));
    printf("Adding: %d\n", addStockItem(myMachine, item3, 0));
    printIDS(myMachine);
    purchaseItem(myMachine, 2);
    printf("Removing: %d\n", removeStockItem(myMachine, 1, &result));
    printIDS(myMachine);
    printf("Removing: %d\n", removeStockItem(myMachine, 3, &result));
    printIDS(myMachine);
    printf("Removing: %d\n", removeStockItem(myMachine, 2, &result));
    printf("Removing: %d\n", removeStockItem(myMachine, 2, &result));
    printf("RESULT: %d %d %d %.2f\n", result.ID, result.stock, result.maxStock, result.price);
    printIDS(myMachine);

    freeVendingMachine(myMachine);
    return 0;
}