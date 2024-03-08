#include "lab7.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct StockNode_t {
    // Stores the item in the node
    StockItem item;
    // Stores the address of the next node
    struct StockNode_t * nextItem;
} StockNode;

struct VendingMachine_t {
    // The current number of used slots
    int length;
    // The stock item linked list
    StockNode * items;
};

/*
    This function will get the StockNode at the given index of the linked list for a machien

    It takes a [ VendingMachine * ], the machine to grab the StockNode from, and an [ int ], the index
    It returns a [ StockNode * ], the StockNode at the index in the linked list
*/
StockNode * getNodeFromIndex(VendingMachine* vm, int index) {
    StockNode * currentNode = vm->items;

    for (int i = 0; i < index; i++) {
         currentNode = currentNode->nextItem;
    }
    
    return currentNode;
}

/*
    This function creates a new, empty, vending machine with a dynamic number of item slots.
    
    It will return a [ VendingMachine * ], a pointer to the new vending machine, or NULL on failure
*/
VendingMachine * newMachine() {
    VendingMachine * machine = (VendingMachine*)malloc(sizeof(VendingMachine));
    if (!machine) {
        return NULL;
    }

    machine->length = 0;
    machine->items = NULL;

    return machine;
}

/*
    This function takes a VendingMachine, and a StockItem. It appends the item onto the linked list.
    It returns 1 if it was successful, or 0 on failure.

    It takes a [ VendingMachine* ], the machine to insert the item into, and an [ StockItem ], the item to add
    It returns an [ int ], which is 1 on success, or 0 on failure
*/
int addStockItem(VendingMachine *vm, StockItem item) {
    StockNode * newNode = (StockNode*)malloc(sizeof(StockNode));
    if (!newNode) {
        return 0;
    }
    newNode->item = item;
    int length = vm->length;

    // Add the Node to the end
    if (length == 0) {
        newNode->nextItem = NULL;
        vm->items = newNode;
    }
    else {
        StockNode * lastNode = getNodeFromIndex(vm, length-1);
        lastNode->nextItem = newNode;
    }
    vm->length = length + 1; 
    
    return 1;  
}

/*
    This function takes a VendingMachine, and returns the number of item slots currently in the
    machine.

    It takes a [ VendingMachine * ], the machine to get the amount of items from
    It returns an [ int ], the number of items in the machine
*/
int countItems(VendingMachine *vm) {
    return vm->length;
}

/*
    This function takes a VendingMachine, and returns the number of items with a stock equal to 0

    It takes a [ VendingMachine * ], the machine to count empty items
    It returns an [ int ], the number of items with stock == 0
*/
int countEmpty(VendingMachine *vm) {
    StockNode * currentNode = vm->items;
    int count = 0;

    for (int i = 0; i < vm->length; i++) {
        if (currentNode->item.stock == 0) {
            count++;
        }
        if (i < vm->length - 1) {
            currentNode = currentNode->nextItem;
        }
    }

    return count;
}

/*
    This function takes a VendingMachine, and the ID of a StockItem. If a stock item with the given
    ID exists in the vending machine, it will update the result pointer with the stock item, and return 1.
    If the ID is not associated with a stock item in the vending machine, it will return 0;

    It takes a [ VendingMachine * ], the machine to search, an [ int ], the ID to search for,
        and a [ StockItem * ], the pointer to update with the item associated with the ID
    It returns an [ int ], which is 1 if the item was found, and 0 if it was not
*/
int getStockItem(VendingMachine *vm, int ID, StockItem *result) {
    StockNode * currentNode = vm->items;
    
    for (int i = 0; i < vm->length; i++) {
        if (currentNode->item.ID == ID) {
            *result = currentNode->item;
            return 1;
        }
        if (i < vm->length - 1) {
            currentNode = currentNode->nextItem;
        }
    }

    return 0;
}

/*
    This function frees the memory allocated for a vending machine

    It takes a [ VendingMachine * ], the machine to free
*/
void freeVendingMachine(VendingMachine *vm) {
    // Free the StockItems
    StockNode * currentNode = vm->items;
    StockNode * nextNode = NULL;
    for (int i = 0; i < vm->length; i++) {
        if (i < vm->length - 1) {
            nextNode = currentNode->nextItem;
        }
        free(currentNode);
        currentNode = nextNode;
    }
    // Free the machine
    free(vm);
    vm = NULL;
}

/*
    This function will print info for the vending machine

    It takes a [ VendingMachine * ], the machine to get info for
*/
void outputInfo(VendingMachine *vm) {
    printf("MACHINE INFO:\n");
    printf("----------------\n");
    StockNode * currentNode = vm->items;
    for (int i = 0; i < vm->length; i++) {
        printf("%d: ID: %d Stock: %d\n", i, currentNode->item.ID, currentNode->item.stock);

        if (i < vm->length - 1) {
            currentNode = currentNode->nextItem;
        }
    }
    printf("----------------\n\n");
}
