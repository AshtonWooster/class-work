#include "lab11.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int size = 10;
    Car * myCars = (Car*)malloc(sizeof(Car)*size);
    for (int i = 0; i < size; i++) {
        myCars[i].OEM_PN = i;
        myCars[i].price = i*2;
        myCars[i].SKU = i*3;
    }

    Database * myDB = makeDatabase(myCars, size);

    printSKU_Sorted(myDB);
    printPriceSorted(myDB);
    printf("Searching for 2: %d\n", (int)getPN_FromSKU(myDB, myCars[2].SKU));
    printf("Searching for 6: %d\n", (int)getPN_FromSKU(myDB, myCars[6].SKU));
    printf("Searching for -1: %d\n", (int)getPN_FromSKU(myDB, -1));
    printf("Searching for %d: %d\n", myCars[3].SKU, getSKU_FromPrice(myDB, myCars[3].price));
    printf("Searching for %d: %d\n", myCars[0].SKU, getSKU_FromPrice(myDB, myCars[0].price));
    printf("Searching for %d: %d\n", myCars[size-1].SKU, getSKU_FromPrice(myDB, myCars[size-1].price));
    printf("Searching for -1: %d\n", getSKU_FromPrice(myDB, -1));

    free(myCars);
    destroy(myDB);
    return 0;
}
