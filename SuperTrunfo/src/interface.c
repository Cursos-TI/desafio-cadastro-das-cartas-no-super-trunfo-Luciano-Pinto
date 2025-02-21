//
// Created by lucianopinto on 21/02/25.
//

#include "nterface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"
#include "super_trunfo.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenuInicialEObterOpcao(DynamicArray *array) {
    while (TRUE) {
        char input[10] = "\0";  // Buffer para armazenar a entrada
        char opcao = '\0';

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
        printf("\nOpção: ");

        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

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
                exibirIndiceDeCartas(array);
                break;
            case '3':
                printf("\nNão implementada!");
                break;
            case '0':
                freeArray(array);
            exit(EXIT_SUCCESS);
            default:
                printf("\nOpção inválida! Tente novamente!\nPressione 'Enter' para continuar.");
            while (getchar() != '\n') {}// Consume all leftover input
            break;
        }
    }
}

void exibirIndiceDeCartas(const DynamicArray *array) {
    char input[10] = "\0";  // Buffer para armazenar a entrada
    char opcao = '\0';

    while (TRUE) {
        printf("\n*********************\n");
        printf("Super Trunfo - Países");
        printf("\n*********************\n");

        printf("\n================\n");
        printf("Índice de Cartas");
        printf("\n================\n");

        for (int i = 0; i < array->size; i++) {
            CartaSuperTrunfo *carta = getElement(array, i);
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

        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            // garante que não está vazio
            if (input[0] != '\0') {
                opcao = input[0];
            }
        }

        switch  (opcao) {
            case '1':
                printf("\n\n*******************************\n");
                printf("Selecione a carta pelo código: ");
                input[0] = '\0';
                // clearBuffer();
                if (fgets(input, sizeof(input), stdin)) {
                    input[strcspn(input, "\n")] = '\0';
                }
                for (int i = 0; i < array->size; i++) {
                    const CartaSuperTrunfo *carta = getElement(array, i);
                    if (strcmp(input, carta->codigo_carta) == 0) {
                        imprimirCarta(*carta);
                        break;
                    }
                }
                break;
            case '0':
                return;
            default:
                printf("\nOpção inválida! Tente novamente!\nPressione 'Enter' para continuar.");
            while (getchar() != '\n') {}// Consume all leftover input
            break;
        }
    }
}