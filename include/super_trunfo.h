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
    double super_poder;
} CartaSuperTrunfo;

float calcular_densidade_populacional(int populacao, float area);

double calcular_pib_per_capta(int populacao, double pib);

double calcular_super_poder(int populacao, float area, double pib, int qtd_pontos_turisticos);

CartaSuperTrunfo* encontrar_carta_por_codigo(const DynamicArray *array, const char *codigo);

void imprimir_carta(const CartaSuperTrunfo *carta);

void inserir_carta(DynamicArray *cartas);

void comparar_cartas(CartaSuperTrunfo carta1, CartaSuperTrunfo carta2);

#endif //SUPER_TRUNFO_H
