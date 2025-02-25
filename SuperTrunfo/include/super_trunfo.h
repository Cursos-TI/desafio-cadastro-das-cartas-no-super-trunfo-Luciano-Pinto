//
// Created by lucianopinto on 20/02/25.
//

#ifndef SUPER_TRUNFO_H
#define SUPER_TRUNFO_H
#include "dynamic_array.h"


// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char codigo_carta[4];
    char estado[100];
    char nome_cidade[100];
    int populacao;
    float area;
    float pib;
    int qtd_pontos_turisticos;
} CartaSuperTrunfo;

float calcularDensidadePopulacional(float populacao, float area);

float calcularPibPerCapta(float populacao, float pib);

void imprimirCarta(CartaSuperTrunfo carta);

void inserir_carta(DynamicArray *cartas);

#endif //SUPER_TRUNFO_H
