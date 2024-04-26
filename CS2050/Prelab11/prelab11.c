#include "prelab11.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSortBySSN(Employee** arr, int low, int high) {
    if (high-low <= 0) {
        return;
    }

    srand(time(NULL));
    Employee * partition = arr[(rand() % (high-low)) + low];
    Employee * dummy = arr[0];
    int l = low;
    int h = high;

    // Partition the array
    while (l < h) {
        // Find first element greater than pivot
        while (arr[l]->SSN <= partition->SSN && l <= high - 1) {
            l++;
        }

        // Find first element less than pivot from the back
        while (arr[h]->SSN > partition->SSN && h >= low + 1) {
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

    quickSortBySSN(arr, low, h-1);
    quickSortBySSN(arr, h+1, high);
}

EmpDatabase* createSearchableEmployeeDB(Employee ** arr, int length) {
    // Allocate memory
    EmpDatabase * db = (EmpDatabase*)malloc(sizeof(EmpDatabase));
    if (!db) {
        return NULL;
    }

    Employee ** sortedBySSN = (Employee**)malloc(sizeof(Employee*));
    if (!sortedBySSN) {
        free(db);
        return NULL;
    }

    Employee ** sortedByID = (Employee**)malloc(sizeof(Employee*));
    if (!sortedByID) {
        free(sortedBySSN);
        free(db);
        return NULL;
    }

    // Initialize 
    db->length = length;
    db->errorCode = 0;
    db->listByID = sortedByID;
    db->listBySSN = sortedBySSN;

    printf("?\n\n");
    for (int i = 0; i < length; i++) {
        sortedBySSN[i] = arr[i];
    }
    printf("More?\n\n");
    quickSortBySSN(db->listBySSN, 0, length-1);

    return db;
}

Employee * findEmpBySSN(int SSN, EmpDatabase * db) {
    int first = 0;
    int last = db->length-1;
    int mid = 0;
    while (first <= last) {
        mid = (last-first)/2;
        if (db->listBySSN[mid]->SSN < SSN) {
            first = mid+1;
        }
        else if (db->listBySSN[mid]->SSN > SSN) {
            last = mid-1;
        }
        else {
            db->errorCode = 0;
            return db->listBySSN[mid];
        }
    }
    // Not found
    db->errorCode = 1;
    return NULL;
}

Employee * findEmpByID(int ID, EmpDatabase * db) {
    int first = 0;
    int last = db->length-1;
    int mid = 0;
    while (first <= last) {
        mid = (last-first)/2;
        if (db->listByID[mid]->ID < ID) {
            first = mid+1;
        }
        else if (db->listByID[mid]->ID > ID) {
            last = mid-1;
        }
        else {
            db->errorCode = 0;
            return db->listByID[mid];
        }
    }
    // Not found
    db->errorCode = 1;
    return NULL;    
}

void freeEmpDatabase(EmpDatabase * db) {
    free(db->listByID);
    free(db->listBySSN);
    free(db);
}

int getErrorCode(EmpDatabase * db) {
    return db->errorCode;
}
