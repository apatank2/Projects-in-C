#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "vector.h"
#include "data.h"

void insertVector(Vector * v, int index, Data value){
    int current_siz = 0;
	if(index>=v->max_size)
    {
    v->max_size = ((index * 2)+1);
    int *new_array = malloc(v->max_size*sizeof(int));
    memcpy(new_array,v->data,v->current_size*sizeof(int));
    free(v->data);
    v->data = new_array;
    }

    if(index >= v->current_size)
    {
         current_siz = v->current_size + 1;
        for (;current_siz < index;current_siz++)
        {
            v->data[current_siz].value = -1;
        }
    v->current_size = index + 1;
    v->data[index] = value;
    }
};

Data * readVector(Vector * v, int index){
	if(index >= v->current_size)
    {
        return NULL;
    }
	else
    {
        return &v->data[index];
    }

};

void removeVector(Vector * v, int index)
{
    if(index < v->max_size)
    {
       v->data[index].value = NULL;
       v->current_size = v->current_size - 1;
    }
};

void deleteVector(Vector * v){
	free(v->data);
	free(v);
};

Vector * newVector(){
        Vector * v = malloc(sizeof(Vector));
        v->max_size = 0;
        v->current_size = 0;
        v->data = NULL;
        v->insert = insertVector;
        v->read = readVector;
        v->remove=removeVector;
        //v->copy = copyVector;
        v->delete = deleteVector;
        return v;
};