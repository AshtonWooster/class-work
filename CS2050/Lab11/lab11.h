#include <stdio.h>
#include <stdlib.h>

typedef struct Car_t Car;

struct Car_t {
    int SKU;
    double price;
    unsigned long long OEM_PN;
};

typedef struct Database_t Database;


// O(n^2)

Database * makeDatabase(Car *cars, int size);

// O(n)

void printSKU_Sorted(Database *db);

// O(n)

void printPriceSorted(Database *db);

// O(log(n))

unsigned long long getPN_FromSKU(Database *db, int SKU);

// O(log(n))

int getSKU_FromPrice(Database *db, double price);

// O(1)

void destroy(Database *db);

