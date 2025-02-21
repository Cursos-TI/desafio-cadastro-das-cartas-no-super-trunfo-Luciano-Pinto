//
// Created by lucianopinto on 20/02/25.
//

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stddef.h>

typedef struct {
    void *data;         // Ponteiro genérico para um dado a ser armazenado no array
    size_t elementSize; // Tamanho de cada elemento
    size_t size;        // Quantidade atual de elementos
    size_t capacity;    // Capacidade máxima antes do redimensionamento
} DynamicArray;

// Function prototypes
DynamicArray* createArray(size_t elementSize, size_t initialCapacity);

void addElement(DynamicArray *arr, const void *element);

void* getElement(const DynamicArray *arr, size_t index);

void freeArray(DynamicArray *arr);

#endif //DYNAMIC_ARRAY_H
