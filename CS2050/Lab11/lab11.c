#include "lab11.h"
#include <stdio.h>
#include <stdlib.h>


// I couldn't get my quicksort to work, but I believe the searches would still work if my array was correctly sorted.


struct Database_t {
    Car ** carsBySKU;
    Car ** carsByPrice;
    int length;
};

/*
    This function will recursively sort an array of cars in place by their SKU. It uses the quicksort algorithm.

    It takes a [ Car** ], the array to sort, and two [ int ], which are the lower and upper bound of the array to sort
*/
void quickSortBySKU(Car ** arr, int low, int high) {
    if (high-low <= 0) {
        return;
    }

    Car * partition = arr[low];
    Car * dummy = arr[0];
    int l = low;
    int h = high;

    // Partition the array
    while (l < h) {
        // Find first element greater than pivot
        while (arr[l]->SKU <= partition->SKU && l <= high - 1) {
            l++;
        }

        // Find first element less than pivot from the back
        while (arr[h]->SKU > partition->SKU && h >= low + 1) {
            h--;
        }

        if (l < h) {
            dummy = arr[l];
            arr[l] = arr[h];
            arr[h] = dummy;
        }
    }

    dummy = arr[low];
    arr[low] = arr[h];
    arr[h] = dummy;

    quickSortBySKU(arr, low, h-1);
    quickSortBySKU(arr, h+1, high);
}

/*
    This function will recursively sort an array of cars in place by their price. It uses the quicksort algorithm.

    It takes a [ Car** ], the array to sort, and two [ int ], which are the lower and upper bound of the array to sort
*/
void quickSortByPrice(Car ** arr, int low, int high) {
    if (high-low <= 0) {
        return;
    }

    Car * partition = arr[low];
    Car * dummy = arr[0];
    int l = low;
    int h = high;

    // Partition the array
    while (l < h) {
        // Find first element greater than pivot
        while (arr[l]->price <= partition->price && l <= high - 1) {
            l++;
        }

        // Find first element less than pivot from the back
        while (arr[h]->price >= partition->price && h >= low + 1) {
            h--;
        }

        if (l < h) {
            dummy = arr[l];
            arr[l] = arr[h];
            arr[h] = dummy;
        }
    }
    dummy = arr[low];
    arr[low] = arr[h];
    arr[h] = dummy;

    quickSortByPrice(arr, low, h-1);
    quickSortByPrice(arr, h+1, high);
}

/*
    This function will create a new database of cars for efficient sorting by price and SKU.

    It takes a [ Car* ], the list of cars to use for the database, and an [ int ], the size of the list
    It returns a [ Database* ], the efficient database for searching, or NULL on failure.
*/
Database * makeDatabase(Car *cars, int size) {
    // Allocate memory and initialize
    Database * newDB = (Database*)malloc(sizeof(Database));
    if (!newDB) {
        return NULL;
    }
    newDB->carsBySKU = (Car**)malloc(sizeof(Car*) * size);
    if (!newDB->carsBySKU) {
        free(newDB);
        return NULL;
    }
    newDB->carsByPrice = (Car**)malloc(sizeof(Car*) * size);
    if (!newDB->carsByPrice) {
        free(newDB->carsBySKU);
        free(newDB);
        return NULL;
    }
    newDB->length = size;
    for (int i = 0; i < size; i++) {
        newDB->carsByPrice[i] = &cars[i]; 
        newDB->carsBySKU[i] = &cars[i];
    }

    quickSortByPrice(newDB->carsByPrice, 0, size-1);
    quickSortBySKU(newDB->carsBySKU, 0, size-1);

    return newDB;
}

/* 
    This function takes a database and prints all of the SKUs of the cars in ascending order.

    It takes a [ Database* ], the database to print from.
*/
void printSKU_Sorted(Database *db) {
    printf("SKUs: ");
    for (int i = 0; i < db->length-1; i++) {
        printf("%d, ", db->carsBySKU[i]->SKU);
    }
    printf("%d\n", db->carsBySKU[db->length-1]->SKU);
}

/* 
    This function takes a database and prints all of the Prices of the cars in ascending order.

    It takes a [ Database* ], the database to print from.
*/
void printPriceSorted(Database *db) {
    printf("Prices: ");
    for (int i = 0; i < db->length-1; i++) {
        printf("$%.2f, ", db->carsByPrice[i]->price);
    }
    printf("$%.2f\n", db->carsBySKU[db->length-1]->price);
}

/*
    This function will search a database and return the PN associated with the given SKU. Uses a binary search algorithm.

    It takes a [ Database* ], the database to search and an [ int ], the SKU to get the PN of
    It returns an [ unsigned long long ], which is the PN of the car, or -1 on failure
*/
unsigned long long getPN_FromSKU(Database *db, int SKU) {
    int first = 0;
    int last = db->length-1;
    int mid = 0;
    while (first <= last) {
        mid = (last+first)/2;
        // Car is in upper partition of the array
        if (db->carsBySKU[mid]->SKU < SKU) {
            first = mid+1;
        }
        // Car is in lower partition of the array
        else if (db->carsBySKU[mid]->SKU > SKU) {
            last = mid-1;
        }
        // Car is found
        else {
            return db->carsBySKU[mid]->OEM_PN;
        }
    }
    // Not found
    return -1;
}

/*
    This function will search a database and return the SKU associated with the given price. Uses a binary search algorithm.

    It takes a [ Database* ], the database to search and a [ double ], the price to get the SKU of the associated car
    It returns an [ int ], which is the SKU of the car, or -1 on failure
*/
int getSKU_FromPrice(Database *db, double price) {
    int first = 0;
    int last = db->length-1;
    int mid = 0;
    while (first <= last) {
        mid = (last+first)/2;
        // Car is in upper partition of the array
        if (db->carsByPrice[mid]->price < price) {
            first = mid+1;
        }
        // Car is in the lower partition of the array
        else if (db->carsByPrice[mid]->price > price) {
            last = mid-1;
        }
        // Car is found
        else {
            return db->carsByPrice[mid]->SKU;
        }
    }
    // Not found
    return -1;
}


/*
    This function takes a database and frees all the memory allocated to it

    It takes a [ Database* ], the database to destroy
*/
void destroy(Database *db) {
    free(db->carsByPrice);
    free(db->carsBySKU);
    free(db);
}
