//
// Created by lucianopinto on 20/02/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dynamic_array.h"

// Função de inicialização do Array Dinâmico
DynamicArray* createArray(const size_t elementSize, const size_t initialCapacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (arr == NULL) {
      printf("Alocação de memoria falhou\n");
      exit(EXIT_FAILURE);
    }

    arr->data = malloc(initialCapacity * elementSize);
    if (!arr->data) {
        printf("Alocação de memoria falhou\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    arr->elementSize = elementSize;
    arr->size = 0;
    arr->capacity = initialCapacity;

    return arr;
}

void addElement(DynamicArray *arr, const void *element) {
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;

    void *temp = realloc(arr->data, arr->capacity * arr->elementSize);

    if (!temp) {
        printf("Alocação de memoria falhou\n");
        free(arr->data);
        free(arr);
        exit(EXIT_FAILURE);
    }
    arr->data = temp;
  }

  // Insere o conteúdo de "element" para o aray.
  memcpy((char*) arr->data + (arr->size * arr->elementSize), element, arr->elementSize);
  arr->size++;
}

void* getElement(const DynamicArray *arr, const size_t index) {
  if (index >= arr->size) {
    printf("Index out of bounds\n");
    return NULL;
  }

  return (char*) arr->data + (index * arr->elementSize);
}

void freeArray(DynamicArray *arr) {
  free(arr->data);
  free(arr);
}