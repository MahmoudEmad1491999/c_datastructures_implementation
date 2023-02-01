#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "vector.h"
enum TypesTesting
{
    TYPE1, 
    TYPE2,
    TYPE3, 
    TYPE4,
    TYPE5
};

typedef struct {
    int x;
} Type1;

typedef struct {
    double x;
} Type2;

typedef struct {
    char x;
} Type3;

typedef struct {
    _Bool x;
} Type4;

void printAllElements(DynVector* dynVector)
{
    for(int index = 0; index < dynVector->size; index++)
    {
        if(dynVector->types[index] == TYPE1)
        {
            printf("type1: %d\n",( (Type1*)(dynVector->dynVector[index]))->x);
        }
        else if(dynVector->types[index] == TYPE2)
        {
            printf("type2: %g\n",( (Type2*)(dynVector->dynVector[index]))->x);
        }
        else if(dynVector->types[index] == TYPE3)
        {
            printf("type3: %c\n",( (Type3*)(dynVector->dynVector[index]))->x);
        }
        else if(dynVector->types[index] == TYPE4)
        {
            printf("type4: %d\n",( (Type4*)(dynVector->dynVector[index]))->x);
        }
    }
}




int main(int argc, char** argv)
{
    Vector* x = makeVector(40);
    int* ptr;
    for(int index = 0;index < 50;index++)
    {
        ptr = (int*) malloc(sizeof(int));
        *ptr = index + 100;
        addEleVector(x, ptr);
    } 

    for(int index = 0; index < 50 ; index++)
    {
        printf("%d\n", *((int*)(x->vector[index])) );
    }

    printf("%d, %d\n", x->cap, x->size);
    freeVector(x);

   DynVector* y = makeDynVector(40);
//
   Type1* t1 = (Type1*) malloc(sizeof(Type1));
   Type2* t2 = (Type2*) malloc(sizeof(Type2));
   Type3* t3 = (Type3*) malloc(sizeof(Type3));
   Type4* t4 = (Type4*) malloc(sizeof(Type4));
    t1->x = 200;
    t2->x = 2.3;
    t3->x = 'c';
    t4->x = 1;
   addEleDynVector(y, t1, TYPE1);
   addEleDynVector(y, t2, TYPE2);
   addEleDynVector(y, t3, TYPE3);
   addEleDynVector(y, t4, TYPE4);

   printAllElements(y);

   freeDynVector(y);
    return 0;
}


