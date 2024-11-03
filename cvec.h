#include <stdlib.h>


void *cvec_create(unsigned int count, size_t type_size);

void *cvec_push_back(void *vec, void* data);

void *cvec_push_list(void* vec, unsigned int count, void *data);

void *cvec_add_elements(void *vec, unsigned int count);

void *cvec_pop(void *vec);

void cvec_destroy(void* vec);

unsigned int cvec_getsize(void *vec);
