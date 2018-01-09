#ifndef LIST_H
#define LIST_H
#include "data.h"

typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    Data data;
}Node;

typedef struct List
{
    Node *head;
    Node *tail;

    void (*insert)(struct List *, int, Data);
    Data* (*read)(struct List *, int);
    void (*remove)(struct List *, int);
    void (*delete)(struct List *);
}List;

List * newList();
void deleteList(List *list);
void removeList(struct List *list, int index);
Data* readList(struct List *list, int index);
void insertList(struct List *list, int index, Data data);

#endif 