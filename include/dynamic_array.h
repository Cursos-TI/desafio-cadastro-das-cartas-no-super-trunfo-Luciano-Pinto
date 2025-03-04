//
// Created by lucianopinto on 20/02/25.
//

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// Estrutura para representar um Array Dinâmico
typedef struct {
    void *data;         // Ponteiro genérico para um dado a ser armazenado no array
    size_t elementSize; // Tamanho de cada elemento
    size_t size;        // Quantidade atual de elementos
    size_t capacity;    // Capacidade máxima antes do redimensionamento
} DynamicArray;

// Function prototypes
DynamicArray* create_array(size_t elementSize, size_t initialCapacity);

void add_element(DynamicArray *arr, const void *element);

void* get_element(const DynamicArray *arr, size_t index);

void free_array(DynamicArray *arr);

#endif //DYNAMIC_ARRAY_H
