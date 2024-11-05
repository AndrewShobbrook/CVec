#include <stdlib.h>

/* Creates a cvec with element count *count* with element size based on *type_size* */
void *cvec_create(unsigned int count, size_t type_size);

/* Pushes an element to the back of the vector, element size is determined by stored type_size */
void *cvec_push_back(void *vec, void* data);

/* Pushes *count* elements to the back of the vector, element size is determined by stored type_size */
void *cvec_push_list(void* vec, unsigned int count, void *data);

/* Adds uninitialised elements to the vector, can be viewed as simply allocating a larger array */
void *cvec_add_elements(void *vec, unsigned int count);

/* Shrinks the vector to not include the last element */
void *cvec_pop(void *vec);

/* De initialises the vector and frees all memory associated */
void cvec_destroy(void* vec);

/* Gets the number of elements in the vector */
unsigned int cvec_getsize(void *vec);
