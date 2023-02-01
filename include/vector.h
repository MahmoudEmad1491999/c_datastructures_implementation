#include <stdlib.h>

/**
 * this structure represent a dynamic array of single type,a.k.a vector, that can grow
 * dynamically on runtime .
 * @vector  this parameter represent an array of pointer to the actual 
 *          elements to be stored on the list.
 * @cap     this member represent the actual current capacity of the vector.
 * @size    this memeber represent the actual size currently occupied by elements.
 *          size is always < cap         
 * Note:    this type is allocated on the heap and every element given must also be 
 *          allocated on the heap
 */

typedef struct {
    void** vector;
    int32_t cap, size;

} Vector;

/**
 * this structure represent a dynamic array of multiple element types,a.k.a vector or list,
 * that can grow dynamically on runtime .
 * @vector  this parameter represent an array of pointer to the actual 
 *          elements to be stored on the list.
 * @cap     this member represent the actual current capacity of the vector.
 * @size    this memeber represent the actual size currently occupied by elements.
 *          size is always < cap         
 * @types   this memeber represent the types of each individual element on the vector
 *          the actual values is determined by the client of the dynamic vector.
 *
 * Note:    this type is allocated on the heap and every element given must also be 
 *          allocated on the heap
 */

typedef struct {
    void** dynVector;
    int32_t cap, size;
    int32_t* types;
} DynVector;


/**
 * this function create a new vector structure on the heap with the given capacity
 *      on the heap
 * @intialCap this parameter represent the wanted initial capacity of the Vector
 * @return pointer to a dynamically allocated vector of the given capacity
 */
Vector* makeVector(int32_t intialCap);


/**
 * this function free the memeory of the space allocated for the elements and the 
 *      vector itself
 * @vector pointer to the vector to be freed
 */

void freeVector(Vector* vector);

/**
 * this function create a new dynamic vector structure on the heap with the given capacity
 *      on the heap
 * @intialCap this parameter represent the wanted initial capacity of the DynVector
 * @return pointer to a dynamically allocated vector of the given capacity
 */
DynVector* makeDynVector(int32_t intialCap);

/**
 * this function free the memeory of the space allocated for the elements and the 
 *      vector itself
 * @vector pointer to the vector to be freed
 */
void freeDynVector(DynVector* dynVector);

