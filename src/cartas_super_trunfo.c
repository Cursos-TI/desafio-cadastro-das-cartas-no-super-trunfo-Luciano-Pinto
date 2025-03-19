#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "super_trunfo.h"
#include "dynamic_array.h"

float calcular_densidade_populacional(const int populacao, const float area) {
    return (float) populacao / area;
}

double calcular_pib_per_capta(const int populacao, const double pib) {
    return pib / (double) populacao;
}

double calcular_super_poder(const int populacao, const float area, const double pib, const int qtd_pontos_turisticos)
{
    const double pib_per_capta = calcular_pib_per_capta(populacao, pib);
    const double densidade_populacional = calcular_densidade_populacional(populacao, area);
    const double total = (double)populacao + (double)area + (double)pib + (double)qtd_pontos_turisticos + pib_per_capta + (1.0
        / densidade_populacional);
    return total;
}

CartaSuperTrunfo* encontrar_carta_por_codigo(const DynamicArray *array, const char *codigo) {
    for (int i = 0; i < array->size; i++) {
        const CartaSuperTrunfo *carta = get_element(array, i);
        if (strcmp(codigo, carta->codigo_carta) == 0) {
            // imprimir_carta(carta);
            return get_element(array, i);
        }
    }
    return NULL;
}

// Função para impressão de uma carta já gerada.
void imprimir_carta(const CartaSuperTrunfo *carta) {
    printf("\n******************************************\n");
    printf("Código da carta: %s\n", carta->codigo_carta);
    printf("Estado: %s\n", carta->estado);
    printf("Cidade: %s\n", carta->nome_cidade);
    printf("Área: %.2f Km2\n", carta->area);
    printf("População: %d hab.\n", carta->populacao);
    printf("Densidade Populacional: %.2f hab./Km2\n", calcular_densidade_populacional(carta->populacao, carta->area));
    printf("PIB: R$ %.2lf\n", carta->pib);
    printf("PIB per capta: R$ %.2lf\n", calcular_pib_per_capta(carta->populacao, carta->pib));
    printf("Quantidade de Pontos Turísticos: %d\n", carta->qtd_pontos_turisticos);
    printf("Super Poder da Carta: %.2lf\n", carta->super_poder);
    printf("******************************************\n");
}

void inserir_carta(DynamicArray *cartas) {
    CartaSuperTrunfo *nova_carta = calloc(1, sizeof(CartaSuperTrunfo));

    printf("\n==================\nCadastro de Carta\n==================\n");
    printf("\n*******************************\nDigite as informações da carta:\n*******************************\n");


    read_string_input(nova_carta->codigo_carta, sizeof(nova_carta->codigo_carta), "Código da carta: ");

    clear_buffer();

    read_string_input(nova_carta->estado, sizeof(nova_carta->estado), "Estado: ");

    read_string_input(nova_carta->nome_cidade, sizeof(nova_carta->nome_cidade), "Cidade: ");

    nova_carta->populacao = read_int_input("População (hab.): ");

    nova_carta->area = read_float_input("Area (Km2): ");

    nova_carta->pib = read_double_input("PIB (R$): ");

    nova_carta->qtd_pontos_turisticos = read_int_input("Quantidade de Pontos Turísticos: ");

    nova_carta->super_poder = calcular_super_poder(nova_carta->populacao, nova_carta->area, nova_carta->pib, nova_carta->qtd_pontos_turisticos);

    add_element(cartas, nova_carta);

    printf("\n*****************************\nCarta Cadastrada com sucesso!\n*****************************\n");

    imprimir_carta(nova_carta);
}

void comparar_cartas(const CartaSuperTrunfo carta1, const CartaSuperTrunfo carta2) {
    int total_carta1 = 0, total_carta2 = 0;

    printf("\n********************\nComparação de Cartas\n********************\n");

    if (carta1.populacao > carta2.populacao) {
        printf("\nPopulação: Carta 1 venceu (1)\n");
        total_carta1++;
    } else {
        printf("\nPopulação: Carta 2 venceu (0)\n");
        total_carta2++;
    }

    if (carta1.area > carta2.area) {
        printf("Area: Carta 1 venceu (1)\n");
        total_carta1++;
    } else {
        printf("Area: Carta 2 venceu (0)\n");
        total_carta2++;
    }

    if (carta1.pib > carta2.pib) {
        printf("PIB: Carta 1 venceu (1)\n");
        total_carta1++;
    } else {
        printf("PIB: Carta 2 venceu (0)\n");
        total_carta2++;
    }

    if (carta1.qtd_pontos_turisticos > carta2.qtd_pontos_turisticos) {
        printf("Pontos Turísticos: Carta 1 venceu (1)\n");
        total_carta1++;
    } else {
        printf("Pontos Turísticos: Carta 2 venceu (0)\n");
        total_carta2++;
    }

    const float carta1_dens_pop = calcular_densidade_populacional(carta1.populacao, carta1.area);
    const float carta2_dens_pop = calcular_densidade_populacional(carta2.populacao, carta2.area);

    if (carta1_dens_pop > carta2_dens_pop) {
        printf("Densidade Populacional: Carta 2 venceu (0)\n");
        total_carta2++;
    } else {
        printf("Densidade Populacional: Carta 1 venceu (1)\n");
        total_carta1++;
    }

    const double carta1_pib_per_capta = calcular_pib_per_capta(carta1.populacao, carta1.pib);
    const double carta2_pib_per_capta = calcular_pib_per_capta(carta2.populacao, carta2.pib);

    if (carta1_pib_per_capta > carta2_pib_per_capta) {
        printf("PIB per capta: Carta 1 venceu (1)\n");
        total_carta1++;
    } else {
        printf("PIB per capta: Carta 2 venceu (0)\n");
        total_carta2++;
    }

    if (carta1.super_poder > carta2.super_poder) {
        printf("Super poder: Carta 1 venceu (1)\n");
        total_carta1++;
    } else {
        printf("Super poder: Carta 2 venceu (0)\n");
        total_carta2++;
    }

    if (total_carta1 > total_carta2) {
        printf("\n*****************\nCarta %s Venceu!\n*****************\n", carta1.codigo_carta);
    } else {
        printf("\n*****************\nCarta %s Venceu!\n*****************\n", carta2.codigo_carta);
    }

}



