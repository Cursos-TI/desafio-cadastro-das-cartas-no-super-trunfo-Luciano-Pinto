//
// Created by lucianopinto on 21/02/25.
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include <super_trunfo.h>

#include "dynamic_array.h"

#define TRUE 1
#define FALSE 0

/*
* Funções para controle de buffer e input de dados
*/
void clear_buffer();

void read_string_input(char *buffer, size_t size, const char *prompt);

int read_int_input(const char *prompt);

float read_float_input(const char *prompt);

double read_double_input(const char *prompt);

/*
* Funções para controle de menu e interação com o usuário
*/

void exibir_menu();

void exibir_menu_inicial_e_obter_opcao(DynamicArray *array);

void exibir_detalhes_carta(const DynamicArray *array);

void exibir_menu_indice_de_cartas(const DynamicArray *array);

void exibir_indice_de_cartas(const DynamicArray *array);

void escolher_cartas_para_comparar(const DynamicArray *array);

void comparar_cartas(CartaSuperTrunfo carta1, CartaSuperTrunfo carta2);

#endif //INTERFACE_H
