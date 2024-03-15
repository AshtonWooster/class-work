#include <stdio.h>
#include <stdlib.h>
#include "prelab8.h"


int main() {
    int ec = 0;
    List * myList = initList(&ec);
    myList = insertAtHead(1, myList, &ec);
    myList = insertAtHead(2, myList, &ec);
    myList = insertAtHead(3, myList, &ec);
    myList = insertAtPosition(2, 6, myList, &ec);
    outputInfo(myList);

    // printf("POS 2: %d\n", getAtPosition(2, myList, &ec));
    // printf("POS 1: %d\n", getAtPosition(1, myList, &ec)); 
    // printf("POS 4: %d\n", getAtPosition(4, myList, &ec));  
    // printf("ILLEGAL HIGH POS: %d\n", getAtPosition(getListLength(myList)+1, myList, &ec));
    // printf("ILLEGAL LOW POS: %d\n", getAtPosition(0, myList, &ec));

    myList = removeAtPosition(2, myList, &ec);
    outputInfo(myList);

    myList = insertAtHead(3, myList, &ec);
    myList = insertAtHead(5, myList, &ec);
    myList = insertAtHead(3, myList, &ec);
    myList = insertAtHead(3, myList, &ec);
    myList = insertAtPosition(getListLength(myList)+1, 3, myList, &ec);
    outputInfo(myList);
    myList = removeObject(3, myList, &ec);
    outputInfo(myList);

    printf("ERROR CODE: %d\n", ec);

    freeList(myList);
    return 0;
}
