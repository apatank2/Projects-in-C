#ifndef VECTOR_H
#define VECTOR_H
#include "data.h"

typedef struct Vector{
        int max_size;
		int current_size;
		Data *data;
		void (*insert)(struct Vector *,int,Data);
		void (*remove)(struct Vector *, int);
        Data * (*read)(struct Vector *, int);
        void (*delete) (struct Vector *);
        } Vector;

Vector * newVector();
void insertVector(Vector * v, int index, Data value);
Data * readVector(Vector * v, int index);
void removeVector(Vector * v, int index);
void deleteVector(Vector * v);
#endif 