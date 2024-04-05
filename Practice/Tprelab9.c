#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;

struct Node {
    void* val;
    Node *next;
};

typedef struct ListInfo {
    Node *head, *tail;
    int size;
} ListInfo;

typedef struct List {
    ListInfo* li;
} List;

Node * makeNode(Node *next, void* data) {
    Node *n = malloc(sizeof(Node));

    if(n) {
        //*n = (Node){&next, data};
        n->next = next;
        n->val = data;
    }

    return n;
}

/* This function returns an empty list. Parameter is a reference to an error code. */
List initEmptyList(int* err) {
    List list;
    list.li = malloc(sizeof(ListInfo));
    if (!list.li) {
        *err = 0;
        list.li = NULL;
        return list;
    }
    *err = 1;
    list.li->head = list.li->tail = NULL;
    list.li->size = 0;
    return list;
}


/* This function inserts the pointer to a user’s object at the head of the list.
Returns error code. */
int insertHead(void* ptr, List list) {
    Node* new = makeNode(list.li->head, ptr);
    if (!new) {
        return 0;
    }

    list.li->head = new;

    if (!list.li->tail) {
        list.li->tail = list.li->head;
    }

    list.li->size++;
    return 1;
}

/* This function returns the object at the head of the list. NULL is returned if
the list is empty. */
void * getHeadObject(List list) {
    return list.li->head->val;
}

/* This function removes the object at the head of the list. Returns error code. */
int removeHead(List list) {
    if (list.li->head->next == NULL) {
        return 1;
    }
    Node* temp = list.li->head->next;
    free(list.li->head);
    list.li->head = temp;
    list.li->size--;
    return 1;
}
/* This function inserts the pointer to a user’s object at the tail of the list.
Returns error code. */
int insertTail(void *ptr, List list) {
    Node* new = makeNode(NULL, ptr);
    if (!new) {
        return 0; 
    }
    list.li->tail->next = new;
    list.li->tail = new;
    list.li->size++;
    return 1;
}

/* This function returns the object at the tail of the list. NULL is returned if
the list is empty. */
void * getTailObject(List list) {
    return list.li->tail->val;
}

/* This function returns the number of objects in the list. */
int getLength(List list) {
    return list.li->size;
}

/* This function deletes list, and returns an error code.
No operations can be performed on deleted list */
int deleteList(List list) {
    Node* cursor;
    
    while ((cursor = list.li->head)) {
        list.li->head = cursor->next;
        free(cursor);
    }

    free(list.li);
    return 1;
}

/*Node *cursor = vm->head;

    // Another possible way to iterate over a linked list
    // Highly recommended
    while(cursor) {
        if(cursor->data.ID == ID) {
            *result = cursor->data;
            return 1;
        }
        cursor = cursor->next;
    }

    return 0;*/

int main() {
    int x = 5;
    int y = 6;
    int* error = &x;
    void *value = &y;
    List list = initEmptyList(error);

    printf("%d\n", *error);
    printf("%d\n", insertHead(value, list));
    printf("%p\n", getHeadObject(list));
    printf("%d\n", removeHead(list));
    printf("%d\n", insertTail(value, list));
    printf("%p\n", getTailObject(list));
    printf("%d\n", getLength(list));
    printf("%d\n", deleteList(list));

    return 0;
}