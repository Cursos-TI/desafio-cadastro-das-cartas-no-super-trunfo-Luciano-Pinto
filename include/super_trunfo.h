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
    double pib;
    int qtd_pontos_turisticos;
} CartaSuperTrunfo;

float calcular_densidade_populacional(float populacao, float area);

double calcular_pib_per_capta(double populacao, double pib);

void imprimir_carta(CartaSuperTrunfo carta);

void inserir_carta(DynamicArray *cartas);


#endif //SUPER_TRUNFO_H
