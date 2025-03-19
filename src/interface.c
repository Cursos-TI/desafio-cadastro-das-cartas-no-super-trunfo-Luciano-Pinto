/*
 * Created by lucianopinto on 21/02/25.
 * Arquivo de definição da interface do programa. 
 * Não relacionado com a interface das cartas, só do controle do progrma.
 */

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "interface.h"

#include <limits.h>

#include "dynamic_array.h"
#include "super_trunfo.h"

// Função para limpeza de buffer do teclado.
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void read_string_input(char *buffer, const size_t size, const char *prompt) {
    printf("%s", prompt);

    if (fgets(buffer, size > INT_MAX ? INT_MAX : (int) size, stdin)) {
        const size_t len = strcspn(buffer, "\n");

        if (len < size) {
            buffer[len] = '\0';
        }
    }
}

int read_int_input(const char *prompt) {
    char input[100];
    char *endptr;
    errno = 0;

    read_string_input(input, sizeof(input), prompt);

    const long value = strtol(input, &endptr, 10);
    if (errno != 0 || *endptr != '\0') {
        printf("Error: Invalid number.\n");
        exit(EXIT_FAILURE);
    }

    if (value > INT_MAX || value < INT_MIN)
    {
        printf("Erro: Valor fora do escopo para um int.\n");
        exit(EXIT_FAILURE);
    }

    return (int) value;
}

float read_float_input(const char *prompt) {
    char input[100];
    char *endptr;
    errno = 0;

    read_string_input(input, sizeof(input), prompt);

    const float value = strtof(input, &endptr);
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
        read_string_input(input, sizeof(input), "\nOpcao: ");
        opcao = input[0];

        switch  (opcao) {
            case '1':
                inserir_carta(array);
                break;
            case '2':
                exibir_menu_indice_de_cartas(array);
                break;
            case '3':
                escolher_cartas_para_comparar(array);
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

    CartaSuperTrunfo *carta_super_trunfo = encontrar_carta_por_codigo(array, input);

    if (carta_super_trunfo != NULL) {
        imprimir_carta(carta_super_trunfo);
    } else {
        printf("Carta com código %s não encontrada!", input);
    }
}

void exibir_indice_de_cartas(const DynamicArray *array) {
    printf("\n================\nÍndice de Cartas\n================\n");

    for (int i = 0; i < array->size; i++) {
        CartaSuperTrunfo *carta = (CartaSuperTrunfo*) get_element(array, i);

        if (carta) {
            printf("\n********************************************************************************\n");
            printf("Carta %3s\n", carta->codigo_carta);
            printf("Estado: %s\n", carta->estado);
            printf("Cidade: %s\n", carta->nome_cidade);
            printf("********************************************************************************\n");
        } else {
            printf("Erro ao acessar carta na posição %d\n", i);
        }

    }
}

// Função para exibição das cartas constantes no array.
void exibir_menu_indice_de_cartas(const DynamicArray *array) {
    while (TRUE) {
        printf("\n========================\nSuper Trunfo - Países\n========================\n");

        exibir_indice_de_cartas(array);

        printf("\n***********************************\n");
        printf("* Menu:                           *\n");
        printf("* 1- Exibir detalhes de uma carta *\n");
        printf("* 0- Voltar ao menu anterior      *\n");
        printf("***********************************\n");
        printf("Opção: ");

        char opcao = '\0';
        char input[10] = "\0";

        if (fgets(input, sizeof(input), stdin)) {
            const size_t index = strcspn(input, "\n");
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

void escolher_cartas_para_comparar(const DynamicArray *array) {
    while (TRUE) {
        printf("\n==================\nSuper Trunfo - Países\n==================\n");

        exibir_indice_de_cartas(array);

        char carta1[4] = "";
        read_string_input(carta1, sizeof(carta1), "Selecione a primeira carta a comparar: ");

        if (carta1[0] == '\0') {
            printf("Código de carta inválido! Tente outra vez ou crtl+c para ecerrar!");
            continue;
        }

        clear_buffer();

        char carta2[4] = "";
        read_string_input(carta2, sizeof(carta2), "\nSelecione a segunda carta a comparar: ");

        if (carta2[0] == '\0') {
            printf("Código de carta inválido! Tente outra vez ou crtl+c para ecerrar!");
            continue;
        }

        clear_buffer();

        const CartaSuperTrunfo *carta1_ptr = encontrar_carta_por_codigo(array, carta1);
        const CartaSuperTrunfo *carta2_ptr = encontrar_carta_por_codigo(array, carta2);

        comparar_cartas(*carta1_ptr, *carta2_ptr);
        break;
    }
}