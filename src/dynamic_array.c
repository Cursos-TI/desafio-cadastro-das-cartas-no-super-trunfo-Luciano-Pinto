/**
 * Created by lucianopinto on 20/02/25.
 * Arquivo de definição do Array Dinâmico
 */


#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de inicialização do Array Dinâmico
DynamicArray* create_array(const size_t elementSize, const size_t initialCapacity) {
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

// Função de inserção de elementos no array dinâmico
void add_element(DynamicArray *arr, const void *element) {
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

// Função de obtenção de um elemento do array por índice
void* get_element(const DynamicArray *arr, const size_t index) {
  if (index >= arr->size) {
    printf("Index out of bounds\n");
    return NULL;
  }

  return arr->data + (index * arr->elementSize);
}


// Função de liberação da memória do array dinâmico e seu próprio espaço de memória
void free_array(DynamicArray *arr) {
  free(arr->data);
  free(arr);
}