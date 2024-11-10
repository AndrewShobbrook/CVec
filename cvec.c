#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "cvec.h"

typedef struct {
    unsigned int elements;
    unsigned int capacity;
    size_t type_size;
} CVecHeader;

void *cvec_create(unsigned int count, size_t type_size) {
    void *data = malloc(sizeof(CVecHeader) + count * type_size);
    CVecHeader *header = data;
    header->elements = count;
    header->capacity = count;
    header->type_size = type_size;
    return data + sizeof(CVecHeader);
}

void *cvec_push_back(void *vec, void* data) {
    CVecHeader *header = vec - sizeof(CVecHeader);
    header->elements += 1;
    if (header->elements > header->capacity) {
        header->capacity *= 2;
        printf("capacity: %lu\n", header->capacity);
        header = realloc(header, sizeof(CVecHeader) + header->capacity * header->type_size);
        printf("header: %lu\n", header);
        vec = header + sizeof(CVecHeader);
    }
    memccpy(vec + (header->elements - 1) * header->type_size, data, 1, header->type_size);
    return vec;
}

void *cvec_push_list(void* vec, unsigned int count, void *data) {
    CVecHeader *header = vec - sizeof(CVecHeader);
    header->elements += 1;
    if (header->elements > header->capacity) {
        header->capacity *= 2;
        if (header->elements > header->capacity) header->capacity = header->elements;

        header = realloc(header, sizeof(CVecHeader) + header->capacity * header->type_size);
        vec = header + sizeof(CVecHeader);
    }
    memccpy(vec + (header->elements - 1) * header->type_size, data, count, header->type_size);
    return vec;
}

void *cvec_add_elements(void *vec, unsigned int count) {
    CVecHeader *header = vec - sizeof(CVecHeader);
    header->elements += 1;
    if (header->elements > header->capacity) {
        header->capacity *= 2;
        if (header->elements > header->capacity) header->capacity = header->elements;

        header = realloc(header, sizeof(CVecHeader) + header->capacity * header->type_size);
        vec = header + sizeof(CVecHeader);
    }
    return vec;
}

void *cvec_pop(void *vec) {
    CVecHeader *header = vec - sizeof(CVecHeader);
    header->elements -= 1;
    header->capacity = header->elements;
    header = realloc(header, sizeof(CVecHeader) + header->capacity * header->type_size);
    vec = header + sizeof(CVecHeader);
    return vec;
}

void cvec_destroy(void* vec) {
    free(vec - sizeof(CVecHeader));
}

unsigned int cvec_getsize(void *vec) {
    CVecHeader *header = vec - sizeof(CVecHeader);
    return header->elements;
}
