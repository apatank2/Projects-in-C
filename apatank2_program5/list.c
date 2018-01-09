#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "list.h"
#include "data.h"

void insertList(struct List *list, int index, Data data)
{
    Node *n = malloc(sizeof(Node));
    n->next = n->prev = NULL;
    n->data = data;
    Node *temp = list->head;
    if(temp == NULL)
    {
        list->head = list->tail = n;
        return;
    }
    int i;
    for (i = 0; i < index; i++) {
        if(temp->next == NULL)
            break;
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        n->prev = temp;
        temp->next=n;
        list->tail = n;
    }
    else
    {
        printf("%i \n", index);
        n->prev = temp;
        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
        //list->tail = n;
    }


    /*Node *n = malloc(sizeof(Node));
    n->next = n->prev = NULL;
    n->val = data;
    if(list->head == NULL)
        list->head = list->tail = n;
    else
    {
        int counter = 1;
        int i;
        Node *node = list->head;
        while(1)
        {
            if(counter == index)
            {
                if(node->next == NULL)
            }
            if(node->next != NULL)
            {
                node = node -> next;
            }
            list->head->next
        }
        n->prev = list->tail;
        list->tail->next = n;
    }*/
}

Data* readList(struct List *list, int index)
{
    Node *temp = list->head;
    if(index == 0)
        return &(list->head->data);
    int i;
    for (i = 0; i < index; i++) {
        if(temp->next == NULL)
            break;
        temp = temp->next;
    }
    if(i==index)
        return &(temp->data);
    else
        return NULL;
}

void removeList(struct List *list, int index)
{
    Node *temp = list->head;
    if(index ==0)
    {
        if(temp->next == NULL)
        {
            list->head=list->tail = NULL;
        }
        else
        {
            list->head = temp->next;
            list->head->prev = NULL;
        }
        free(temp);
        return;
    }
    int i;
    for (i = 0; i < index; i++) {
        if(temp->next == NULL)
            break;
        temp = temp->next;
    }
    if(index == i)
    {
        if(temp->next == NULL)
        {
            temp->prev->next = NULL;
            list->tail = temp->prev;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void deleteList(List *list)
{ 
    free(list);
}

List * newList()
{
    List *list = malloc(sizeof(List));
    list->head = list->tail = NULL;
    list->insert = insertList;
    list->read= readList;
    list->remove= removeList;
    list->delete=deleteList;
    return list;
}
