#include "lab10.h"
#include <stdio.h>

int main() {
    Queue * q = newQueue();
    int * a;
    int * b;
    int x = 1;
    int y = 2;
    a = &x;
    b = &y;

    printf("Size: %d\n", getSize(q));
    int * c = (int*)deQueue(q);
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    c = (int*)deQueue(q);
    printf("C: %d\n", *c);
    peek(q);
    printf("Size: %d\n", getSize(q));
    printf("ENQUEUE b: %d\n", enQueue(q, (void*)b));
    printf("%d\n", *(int*)peek(q));
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    c = (int*)deQueue(q);
    printf("C: %d\n", *c);
    printf("Size: %d\n", getSize(q));
    printf("%d\n", *(int*)peek(q));
    c = (int*)deQueue(q);
    c = (int*)deQueue(q);
    c = (int*)deQueue(q);
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    printf("ENQUEUE a: %d\n", enQueue(q, (void*)a));
    peek(q);
    peek(q);
    peek(q);
    peek(q);
    peek(q);

    destroy(q);
    
    return 0;
}