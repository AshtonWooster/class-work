#include <stdio.h>
#include <stdlib.h>
#include "lab9.h"

typedef struct Node_t {
    char object;
    struct Node_t * next;
} Node;

struct StringBuilder_t {
    int size;
    Node * head;
    Node * tail;
};

/*
    This function creates and returns a new StringBuilder.

    It returns a [ StringBuilder* ], a pointer to the new StringBuilder or NULL on failure.
*/
StringBuilder * newBuilder(void) {
    // Create and initialize a new StringBuilder
    StringBuilder * builder = (StringBuilder*)malloc(sizeof(StringBuilder));
    if (!builder) {
        return NULL;
    }
    builder->size = 0;

    // Add a dummy node
    Node * dummyNode = (Node*)malloc(sizeof(Node));
    if (!dummyNode) {
        free(builder);
        return NULL;
    }
    dummyNode->next = NULL;
    dummyNode->object = ' ';
    builder->head = dummyNode;
    builder->tail = dummyNode;

    return builder;
}

/*
    This function returns the size of the provided StringBuilder

    It takes a [ StringBuilder* ], the StringBuilder to get the size of
    It returns an [ int ], the size of the StringBuilder
*/
int getSize(StringBuilder *b) {
    return b->size;
}

/*
    This function will append a char to the end of the given StringBuilder

    It takes a [ StringBuilder* ], the StringBuilder to append to, and a [ char ], the char to append
    It returns an [ int ], which is 1 on success or 0 on failure
*/
int appendChar(StringBuilder *b, char c) {
    // Allocate and initialize a newChar Node
    Node * newChar = (Node*)malloc(sizeof(Node));
    if(!newChar) {
        return 0;
    }
    newChar->next = NULL;
    newChar->object = c;

    b->tail->next = newChar;
    b->tail = newChar;
    b->size++;

    return 1;
}

/*
    This function will return the last char in the given StringBuilder

    It takes a [ StringBuilder* ], the StringBuilder to get the last character of
    It returns a [ char ], the last character of the StringBuilder or the null terminator if it is empty
*/
char lastChar(StringBuilder *b) {
    if(b->size == 0) {
        return '\0';
    }
    return b->tail->object;
}

/*
    This function will append a cstring to the end of a StringBuilder, if appending fails at any point,
        it will not undo any previous additions to the StringBuilder

    It takes a [ StringBuilder* ], the StringBuilder to append to, and a [ char* ], the cstring to append
    It returns an [ int ], which is 1 on success and 0 on failure 
*/
int appendStr(StringBuilder *b, char *s) {
    // Loop through the string until the null terminator
    char * toAdd = (s-1);
    while(*(toAdd = toAdd+1)) {
        int errorCode = appendChar(b, *toAdd);
        if (!errorCode) {
            return 0;
        }
    }

    return 1;
}

/*
    This function takes a StringBuilder and dynamically allocates and returns its representation as a cstring
        the returned cstring must be freed by the user.

    It takes a [ StringBuilder* ], the StringBuilder to convert to a string
    It returns a [ char* ], the converted string on success or NULL on failure
*/
char * toStr(StringBuilder *b) {
    // Allocate a new string
    char * converted = (char*)malloc(sizeof(char) * (b->size + 1));
    if (!converted) {
        return NULL;
    }

    // Loop through the StringBuilder and set each char from it into the string with a null terminator
    Node * cursor = b->head;
    int count = 0;
    while((cursor = cursor->next)) {
        converted[count] = cursor->object;
        count++;
    }
    converted[count] = '\0';

    return converted;
}

/*
    This function returns the last index of the given char inside the given StringBuilder

    It takes a [ StringBuilder* ], the StringBuilder to search, and a [ char ], the char to search for
    It returns an [ int ], the last index of the given char or -1 if it was not found
*/
int lastIndex(StringBuilder *b, char c) {
    // Loop through the StringBuilder, updating lastIndex when the char appears
    Node * cursor = b->head;
    int count = 0;
    int lastIndex = -1;
    while ((cursor = cursor->next)) {
        if (cursor->object == c) {
            lastIndex = count;
        }
        count++;
    }

    return lastIndex;
}

/*
    This function takes a StringBuilder pointer and frees all of the memory allocated to it

    It takes a [ StringBuilder* ], the Stringbuilder to free memory from
*/
void destroy(StringBuilder *b) {
    // Loop through the String Builder and free all of the Nodes
    Node * cursor;
    while((cursor = b->head)) {
        b->head = cursor->next;
        free(cursor);
    }
    free(b);
    b = NULL;
}
