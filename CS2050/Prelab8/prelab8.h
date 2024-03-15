#ifndef _PRELAB8
#define _PRELAB8
#include <stdio.h>
#include <stdlib.h>

typedef struct List_t List;

List * initList(int*);
List * insertAtHead(int, List*, int*);
int getListLength(List*);
List * freeList(List*);

List * insertAtPosition(int pos, int key, List*, int*);
int getAtPosition(int pos, List*, int*);
List * removeAtPosition(int pos, List*, int*);
List * removeObject(int obj, List*, int*);

void outputInfo(List * list);

#endif
