#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_t Queue;

// O(1)

Queue * newQueue(void);

// O(1)

int getSize(Queue *q);

// O(1)

int enQueue(Queue *q, void *data);

// O(1)

void * peek(Queue *q);

// O(1)

void * deQueue(Queue *q);

// O(n)

void destroy(Queue *q);

