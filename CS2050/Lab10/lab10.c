#include "lab10.h"
#include <stdio.h>
#include <stdlib.h>

// Node Struct
typedef struct Node_t {
    struct Node_t * next;
    void * object;
} Node;

// Queue Struct
struct Queue_t {
    Node * head;
    Node * tail;
    int size;
};

/*
    This function creates and returns a new Queue.

    It returns a [ Queue* ], a pointer to the new Queue or NULL on failure.
*/
Queue * newQueue(void) {
    // Create and initialize a new Queue
    Queue * newQueue = (Queue*)malloc(sizeof(Queue));
    if (!newQueue) {
        return NULL;
    }
    newQueue->size = 0;

    // Add a dummy node
    Node * dummyNode = (Node*)malloc(sizeof(Node));
    if (!dummyNode) {
        free(newQueue);
        return NULL;
    }
    dummyNode->next = NULL;
    dummyNode->object = NULL;
    newQueue->head = dummyNode;
    newQueue->tail = dummyNode;

    return newQueue;
}

/*
    This function returns the size of the provided Queue

    It takes a [ Queue* ], the Queue to get the size of
    It returns an [ int ], the size of the Queue
*/
int getSize(Queue *q) {
    return q->size;
}

/*
    This function will enqueue a new data object to the given queue

    It takes a [ Queue* ], the queue to append to and a [ void* ], the object to queue
    It returns an [ int ], which is 1 on success and 0 on failure
*/
int enQueue(Queue *q, void *data) {
    // Allocate and initialize a new Node
    Node * newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) {
        return 0;
    }

    newNode->next = NULL;
    newNode->object = data;

    q->tail->next = newNode;
    q->tail = newNode;
    q->size++;

    return 1;
}

/*
    This function takes a Queue, and returns the item at the front of the queue without removing it. 

    It takes a [ Queue* ], the queue to peek at
    It returns a [ void* ], a pointer to the item at the front of the queue
*/
void * peek(Queue *q) {
    if (q->size < 1) {
        return NULL;
    }

    return q->head->next->object;
}

/*
    This function takes a Queue, and removes and returns the item at the front of the queue.

    It takes a [ Queue* ], the queue to pull the first item from
    It returns a [ void* ], the removed object at the front of the queue
*/
void * deQueue(Queue *q) {
    if (q->size == 0) {
        return NULL;
    }

    // Remove and deallocate the first node, shifting the others down
    Node * toRemove = q->head->next;
    void * removedObject = toRemove->object;
    // Update tail pointer if needed
    if (q->size == 1) {
        q->tail = q->head;
    }
    q->head->next = toRemove->next;

    q->size--;
    free(toRemove);
    return removedObject;
}

/*
    This function takes a Queue pointer and frees all of the memory allocated to it

    It takes a [ Queue* ], the Queue to free memory from
*/
void destroy(Queue *q) {
    // Loop through the Queue and free all of the Nodes
    Node * cursor;
    while((cursor = q->head)) {
        q->head = cursor->next;
        free(cursor);
    }
    free(q);
    q = NULL;
}
