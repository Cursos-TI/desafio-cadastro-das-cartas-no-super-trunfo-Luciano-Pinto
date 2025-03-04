/*
 * Created by lucianopinto on 21/02/25.
 * Arquivo de definição da interface do programa. 
 * Não relacionado com a interface das cartas, só do controle do progrma.
 */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnested-externs"

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#include "interface.h"
#include "dynamic_array.h"
#include "super_trunfo.h"


// Função para limpeza de buffer do teclado.
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        continue;
    }
}

void read_string_input(char *buffer, size_t size, const char *prompt) {
    if (size == 0 || buffer == NULL) {
        return;
    }

    printf("%s", prompt);

    if (fgets(buffer, (int)(size > INT_MAX ? INT_MAX : size), stdin)) {
        size_t len = strcspn(buffer, "\n");

        // Ensure len is strictly within safe bounds
        if (len >= size) {
            len = size - 1;
        }

        // Absolute last safety check before writing null terminator
        if (len < size) {
            buffer[len] = '\0';
        }
    }

    // Secondary safety net in case something slips through
    buffer[size - 1] = '\0';
}

int read_int_input(const char *prompt) {
    char input[100];
    char *endptr;
    errno = 0;

    read_string_input(input, sizeof(input), prompt);
    
    long value = strtol(input, &endptr, 10);
    if (errno != 0 || *endptr != '\0') {
        printf("Error: Invalid number.\n");
        exit(EXIT_FAILURE);
    }
    return (int)value;
}

float read_float_input(const char *prompt) {
    char input[100];
    char *endptr;
    errno = 0;

    read_string_input(input, sizeof(input), prompt);
    
    float value = strtof(input, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        printf("Error: Invalid float.\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

double read_double_input(const char *prompt) {
    char input[100];
    char *endptr;
    errno = 0;

    read_string_input(input, sizeof(input), prompt);
    
    double value = strtod(input, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        printf("Error: Invalid double.\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

// Função de controle do programa com menu inicial e obtenção da opção do usuário.

void exibir_menu() {
    printf("\n*********************\n");
    printf("Super Trunfo - Países");
    printf("\n*********************\n");

    printf("\n***********************\n");
    printf("* Menu:               *\n");
    printf("* 1- Inserir carta    *\n");
    printf("* 2- Exibir cartas    *\n");
    printf("* 3- Comparar cartas  *\n");
    printf("* 0- Sair do programa *\n");
    printf("***********************\n");
}
void exibir_menu_inicial_e_obter_opcao(DynamicArray *array) {
    while (TRUE) {
        char input[10] = "\0";  // Buffer para armazenar a entrada
        char opcao = '\0';

        exibir_menu();        
        printf("\nOpção: ");

        if (fgets(input, sizeof(input), stdin)) {
            size_t index = strcspn(input, "\n");
            if (index < sizeof(input)) {
                input[index] = '\0';
            }

            // garante que não está vazio
            if (input[0] != '\0') {
                opcao = input[0];
            }
        }

        switch  (opcao) {
            case '1':
                inserir_carta(array);
                break;
            case '2':
                exibir_indice_de_cartas(array);
                break;
            case '3':
                printf("\nNão implementada!");
                break;
            case '0':
                free_array(array);
                exit(EXIT_SUCCESS);
            default:
                printf("\nOpção inválida! Tente novamente!\nPressione 'Enter' para continuar.");
                clear_buffer();
            break;
        }
    }
}


void exibir_detalhes_carta(const DynamicArray *array) {
    char input[10] = "\0";  // Buffer para armazenar a entrada

    printf("\n\n***************************************\n");
    read_string_input(input, sizeof(input), "Selecione a carta por seu código: ");

    for (int i = 0; i < array->size; i++) {
        const CartaSuperTrunfo *carta = get_element(array, i);
        if (strcmp(input, carta->codigo_carta) == 0) {
            imprimir_carta(*carta);
            return;
        }
    }
}

// Função para exibição das cartas constantes no array.
void exibir_indice_de_cartas(const DynamicArray *array) {
    while (TRUE) {
        printf("\n==================\nSuper Trunfo - Países\n==================\n");
        printf("\n================\nÍndice de Cartas\n================\n");

        for (int i = 0; i < array->size; i++) {
            CartaSuperTrunfo *carta = get_element(array, i);
            printf("\n********************************************************************************\n");
            printf("Carta %3s\n", carta->codigo_carta);
            printf("Estado: %s\n", carta->estado);
            printf("Cidade: %s\n", carta->nome_cidade);
            printf("********************************************************************************\n");
        }

        printf("\n***********************************\n");
        printf("* Menu:                           *\n");
        printf("* 1- Exibir detalhes de uma carta *\n");
        printf("* 0- Voltar ao menu anterior      *\n");
        printf("***********************************\n");
        printf("Opção: ");

        char opcao = '\0';
        char input[10] = "\0";

        if (fgets(input, sizeof(input), stdin)) {
            size_t index = strcspn(input, "\n");
            if (index < sizeof(input)) {
                input[index] = '\0';
            }

            if (input[0] != '\0') {
                opcao = input[0];
            }
        }

        switch  (opcao) {
            case '1':
                exibir_detalhes_carta(array);
                break;
            case '0':
                return;
            default:
                printf("\nOpção inválida! Tente novamente!\nPressione 'Enter' para continuar.");
                clear_buffer();
                break;
        }
    }
}

