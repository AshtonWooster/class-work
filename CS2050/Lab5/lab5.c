#include "lab5.h"
#include <stdio.h>
#include <stdlib.h>

// The vending machine struct
struct VendingMachine_t {
    // Current amount of slots in use
    int slots;
    // Maximum amount of slots available
    int maxSlots;
    // Array of items, with id=0 when that slot is empty
    StockItem* items;
};

// empty item for copying
StockItem EMPTY_ITEM = {0,0,0,0};

/*
    This function will output all of the items in the vending machine as well as the slots used and max slots

    It takes a [ VendingMachine* ], the machine to print the info for
*/
void outputInfo(VendingMachine* vm) {
    printf("\nVENDING MACHINE\n");
    printf("ITEMS: %d\n", vm->slots);
    printf("MAX ITEMS: %d\n", vm->maxSlots);
    printf("STOCK: \n");
    printf("------------------\n");
    for (int i = 0; i < vm->slots; i++) {
        printf("ID: %d\n", vm->items[i].ID);
    }
    printf("------------------\n");
}

/* 
    This function will move one item into another given slot

    It takes a [ StockItem* ], the slot to move the item to, and a [ StockItem ], the item to move
*/
void moveItem(StockItem * slot, StockItem item) {
    slot->ID = item.ID;
    slot->maxStock = item.maxStock;
    slot->stock = item.stock;
    slot->price = item.price;
}

/*
    This function will find the index of an item inside a machine given the ID

    It takes a [ VendingMachine* ], the machine to search, and an [ int ], the ID of the item to search for
    It returns an [ int ], which is the index of the item on success, or -1 on failure
*/
int findItem(VendingMachine* vm, int ID) {
    for (int i = 0; i < vm->slots; i++) {
        if (vm->items[i].ID == ID) {
            return i;
        }
    }

    return -1;
}

/*
    This function creates a new, empty, vending machine with a number of item slots equal to
    numslots.

    It takes an [ int ], the maximum amount of slots for the machine
    It returns a [ VendingMachine* ], the empty machine 
*/
VendingMachine * newMachine(int numSlots) {
    // create a new machine and return NULL if malloc fails.
    VendingMachine * machine = (VendingMachine*)malloc(sizeof(VendingMachine));
    if (!machine) {
        return NULL;
    }

    machine->slots = 0;
    machine->maxSlots=numSlots;

    // malloc a new items array and return NULL if malloc fails.
    machine->items = (StockItem*)malloc(sizeof(StockItem) * numSlots);
    if (!machine->items) {
        return NULL;
    }
    // initialize the items array.
    for (int i = 0; i < numSlots; i++) {
        moveItem(machine->items + i, EMPTY_ITEM);
    }

    return machine;
}

/*
    This function takes a VendingMachine, and a StockItem. It inserts the item into the first empty
    slot in the vending machine. It returns 1 if insertion was successful, or 0 if the vending machine is
    has no empty slots left (or if insertion failed for any other reason).

    It takes a [ VendingMachine* ], the machine to insert the item into, and an [ StockItem ], the item to add
    It returns an [ int ], which is 1 on success, or 0 on failure
*/
int addStockItem(VendingMachine *vm, StockItem item) {
    // If there are no spots left, return 0
    if (vm->slots == vm->maxSlots) {
        return 0;
    }
    // Copy the item into the slot and increment slots count
    moveItem(vm->items + vm->slots, item);
    vm->slots++;
    return 1;
}

/*
    This function takes a VendingMachine, and returns the number of items with a stock > 0

    It takes a [ VendingMachine* ], the machine to count in-stock items
    It returns an [ int ], the number of items with remaining stock
*/
int countInStock(VendingMachine *vm) {
    int count = 0;
    for (int i = 0; i < vm->slots; i++) {
        if (vm->items[i].stock > 0) {
            count++;
        }
    }
    
    return count;
}

/*
    This function takes a VendingMachine, and the ID of a StockItem. If a stock item with the
    given ID exists in the vending machine, it will update the result pointer with the stock item to be
    removed, set the item slot to be empty.

    It takes a [ VendingMachine* ], the machine to remove the item from, an [ int ], the ID of the item to remove,
        and a [ StockItem* ], the item pointer to store the removed item
    It returns an [ int ], which is a 1 on success and a 0 on failure
*/
int removeStockItem(VendingMachine *vm, int ID, StockItem *result) {
    // Find the index, if it doesnt exist return 0
    int index = findItem(vm, ID);
    if (index < 0) {
        return 0;
    }

    // Copy the item into the result and clear the slot
    moveItem(result, vm->items[index]);
    moveItem(vm->items + index, EMPTY_ITEM);

    // Shift all other items down
    for (int i = index + 1; i < vm->slots; i++) {
        moveItem(vm->items + (i-1), vm->items[i]);
    }
    vm->slots--;
    
    return 1;
}

/*
    This function frees the memory allocated for a vending machine

    It takes a [ VendingMachine* ], the machine to free
*/
void freeVendingMachine(VendingMachine *vm) {
    free(vm->items);
    free(vm);
    vm = NULL;
}
