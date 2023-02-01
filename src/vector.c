#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

extern int32_t VECTOR_INCREMENT_VALUE;

Vector* makeVector(int32_t initialCap){
    // validate the inital capacity given > 0
    if(initialCap <= 0)
    {
        fprintf(stderr, "cannot initalize a vector initial capacity cannot be zero or less %d", initialCap);
        exit(-1);
    }

    Vector* value_to_return = (Vector*) malloc(sizeof(Vector));
    void** vector = (void**) malloc(initialCap * sizeof(void*));
    
    // validate that that memory allocation happened.
    if(NULL == value_to_return || NULL == vector)
    {
        fprintf(stderr, "memory allocation failed\n");
        exit(-1);
    }
    // set the members of the returned vector to their correct values.
    value_to_return->cap = initialCap;
    value_to_return->size = 0;
    value_to_return->vector = vector;

    return value_to_return;
}


void addEleVector(Vector *vector, void *ele)
{
    // check if there is enough space on the vector
    if(vector->size < vector->cap)
    {
        vector->vector[vector->size] = ele;
        vector->size++;
    }
    else
    {
        // there is not enouph space on the record try reallocating more space.
        vector->vector = (void**) realloc(vector->vector,(vector->cap + VECTOR_INCREMENT_VALUE)* sizeof(void*));
        // check if reallocation happened.
        if(NULL == vector->vector)
        {
            fprintf(stderr, "vector expansion failed!");
            exit(-1);
        }
        // assign the new capacity to the vector structure.
        vector->cap = vector->cap + VECTOR_INCREMENT_VALUE;        
        // add the new element to the structrue.
        vector->vector[vector->size] = ele;
        // increment the size. 
        vector->size++;
    }
}


void freeVector(Vector* vector)
{
    // check that the given vector is not null
    if(NULL != vector)
    {
        // free each element pointed out by the addresses given in the vector array.
        for(int index = 0 ; index < vector->size; index++)
        {
            free(vector->vector[index]);
        }
        // free the space allocated for the pointer to elements.
        free(vector->vector);
        // free the space allocated for the structure itself.
        free(vector);
    }
}


DynVector* makeDynVector(int32_t initialCap)
{
    // validate the inital capacity given > 0
    if(initialCap <= 0)
    {
        fprintf(stderr, "cannot initalize a vector initial capacity cannot be zero or less %d", initialCap);
        exit(-1);
    }

    // allocate the space for the DynVector structure itself, the pointer
    // to elements list and the elements types list.
    DynVector* value_to_return = (DynVector*) malloc(sizeof(DynVector));
    void** dynVector = (void**) malloc(initialCap * sizeof(void*));
    int32_t* types = (int32_t*) malloc(initialCap* sizeof(int32_t));

    // validate that that memory allocation happened.
    if(NULL == value_to_return || NULL == dynVector || NULL == types)
    {
        fprintf(stderr, "memory allocation failed\n");
        exit(-1);
    }
    
    // set the members of the returned vector to their correct values.
    value_to_return->cap = initialCap;
    value_to_return->size = 0;
    value_to_return->dynVector = dynVector;

    return value_to_return;
}

void freeDynVector(DynVector* dynVector)
{
    // check that the given vector is not null
    if(NULL != dynVector)
    {
        // free each element pointed out by the addresses given in the vector array.
        for(int index = 0 ; index < dynVector->size; index++)
        {
            free(dynVector->dynVector[index]);
        }
        // free the space allocated for the pointer to elements.
        free(dynVector->dynVector);
        // free the space occupied by the types list.
        free(dynVector->types);
        // free the space allocated for the structure itself.
        free(dynVector);
    }
}

void addEleDynVector(DynVector *dynVector, void *ele, int32_t type)
{
    // check if there is enough space on the vector
    if(dynVector->size < dynVector->cap)
    {
        dynVector->dynVector[dynVector->size] = ele;
        dynVector->types[dynVector->size] = type;
        dynVector->size++;
    }
    else
    {
        // there is not enouph space on the record try reallocating more space.
        dynVector->dynVector = (void**) realloc(dynVector->dynVector,(dynVector->cap + VECTOR_INCREMENT_VALUE)* sizeof(void*));
        dynVector->types = (int32_t*) realloc(dynVector->types, (dynVector->cap + VECTOR_INCREMENT_VALUE)* sizeof(int32_t));
        // check if reallocation happened.
        if(NULL == dynVector->dynVector || NULL == dynVector->types)
        {
            fprintf(stderr, "vector expansion failed!");
            exit(-1);
        }
        // assign the new capacity to the vector structure.
        dynVector->cap = dynVector->cap + VECTOR_INCREMENT_VALUE;        
        // add the new element to the structrue.
        dynVector->dynVector[dynVector->size] = ele;
        // add the new type to the list of the corresponding types.
        dynVector->types[dynVector->size] = type;
        // increment the size. 
        dynVector->size++;
    }
}

