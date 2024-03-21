#include <stdio.h>
#include <stdlib.h>
#include "lab8.h"

typedef struct StockNode_t {
    // Stores the item in the node
    StockItem item;
    // Stores the address of the next node
    struct StockNode_t * nextItem;
} StockNode;

struct VendingMachine_t {
    // The list of items
    StockNode * items;
};

/*
    This function creates a new vending machine with a dynamic number of item slots.
    
    It will return a [ VendingMachine * ], a pointer to the new vending machine, or NULL on failure
*/
VendingMachine * newMachine() {
    // Allocate a new machine, return null on failure
    VendingMachine * machine = (VendingMachine*)malloc(sizeof(VendingMachine));
    if (!machine) {
        return NULL;
    }

    // Allocate a new dummy node for the StockItem list, return null on failure
    StockNode * dummyNode = (StockNode*)malloc(sizeof(StockNode));
    if (!dummyNode) {
        free(machine);
        return NULL;
    }

    // Initialize the machine
    StockItem dummyItem = {0,0,0,0};
    dummyNode->nextItem = NULL;
    dummyNode->item = dummyItem;
    machine->items = dummyNode;

    return machine;
}

/*
    This function takes a VendingMachine, a StockItem, and an afterID. It inserts the item into
    the vending machine. If the afterID given is > 0, it inserts the new item just after the stock item with
    the specified ID. If the afterID given is <= 0, it inserts the new item at the head of the list. If a stock
    item with the given afterID is not found on the list, the new item is inserted at the end of the list.

    It takes a [ VendingMachine* ], the machine to insert into, a [ StockItem ], the item to insert,
        and an [ int ], the ID of the item to return after
    It returns an [ int ], which is 1 on success and 0 on failure
*/
int addStockItem(VendingMachine *vm, StockItem item, int afterID) {
    // Allocate a new node, return 0 on failure
    StockNode * newNode = (StockNode*)malloc(sizeof(StockNode));
    if (!newNode) {
        return 0;
    }

    // Grab the node to insert after
    StockNode * currentNode = vm->items;
    if (afterID > 0) {
        while(currentNode->item.ID != afterID && currentNode->nextItem && (currentNode = currentNode->nextItem));
    }

    // Insert the item
    newNode->nextItem = currentNode->nextItem;
    newNode->item = item;
    currentNode->nextItem = newNode;

    return 1;
}

/*
    This function takes a VendingMachine, and prints the ID for each item it contains, all on one single line, separated by commas.

    It takes a [ VendingMachine* ], the machine to print the IDs from
*/
void printIDS(VendingMachine *vm) {
    printf("VendingMachine : ");

    StockNode * currentNode = vm->items->nextItem;
    if (currentNode) {
        // Print the IDS
        printf("%d", currentNode->item.ID);
        while ((currentNode = currentNode->nextItem)) {
            printf(", %d", currentNode->item.ID);
        }
    }

    printf("\n");
}

/*
    This function takes a VendingMachine and an Item ID. It locates the item, and if it has any
    stock, decrements the stock by 1

    It takes a [ VendingMachine* ], the machine to purchase from, and an [ int ], the ID of the item to purchase
    It returns an [ int ], which is a 1 if the item was purchased, or 0 if the item was not found or out of stock
*/
int purchaseItem(VendingMachine *vm, int ID) {
    StockNode * currentNode = vm->items;

    while ((currentNode = currentNode->nextItem)) {
        if (currentNode->item.ID == ID && currentNode->item.stock > 0) {
            currentNode->item.stock = currentNode->item.stock - 1;
            return 1;
        }
    }

    return 0;
}

/*
    This function takes a VendingMachine, and the ID of a StockItem. If a stock item with the given
    ID exists in the vending machine, it will update the result pointer with the stock item and remove the item from the list

    It takes a [ VendingMachine* ], the machine to remove from, an [ int ], the ID of the item to remove,
        and a [ StockItem* ], the removed item
    It returns an [ int ], which is 1 on success and 0 if the item does not exist in the machine
*/
int removeStockItem(VendingMachine *vm, int ID, StockItem *result) {
    StockNode * currentNode = vm->items;
    
    do {
        StockNode * toRemove = currentNode->nextItem;
        if (!toRemove || toRemove->item.ID != ID) {
            continue;
        }
        
        // Remove the item
        currentNode->nextItem = toRemove->nextItem;
        *result = toRemove->item;
        free(toRemove);
        return 1;
    } while((currentNode = currentNode->nextItem));

    return 0;
}

/*
    This function takes a VendingMachine, and frees all memory allocated to it.

    It takes a [ VendingMachine* ], the machine to free
*/
void freeVendingMachine(VendingMachine *vm) {
    StockNode * nextNode = vm->items;
    StockNode * currentNode = nextNode;

    do {
        nextNode = nextNode->nextItem;
        free(currentNode);
    } while((currentNode = nextNode));

    free(vm);
}
