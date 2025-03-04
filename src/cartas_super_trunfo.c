#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "super_trunfo.h"
#include "dynamic_array.h"


float calcular_densidade_populacional(const float populacao, const float area) {
    return populacao / area;
}

double calcular_pib_per_capta(const double populacao, const double pib) {
    return pib / populacao;
}

// Função para impressão de uma carta já gerada.
void imprimir_carta(CartaSuperTrunfo carta) {
    printf("\n*************************************\n");
    printf("Código da carta: %s\n", carta.codigo_carta);
    printf("Estado: %s\n", carta.estado);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("Área: %.2f Km2\n", carta.area);
    printf("População: %d hab.\n", carta.populacao);
    printf("Densidade Populacional: %.2f hab./Km2\n", calcular_densidade_populacional((float) carta.populacao, carta.area));
    printf("PIB: R$ %.2lf\n", carta.pib);
    printf("PIB per capta: R$ %.2lf\n", calcular_pib_per_capta((double) carta.populacao, carta.pib));
    printf("Quantidade de Pontos Turísticos: %d\n", carta.qtd_pontos_turisticos);
    printf("*************************************\n");
}

void inserir_carta(DynamicArray *cartas) {
    CartaSuperTrunfo nova_carta = {0};

    printf("\n==================\nCadastro de Carta\n==================\n");
    printf("\n*******************************\nDigite as informações da carta:\n*******************************\n");


    read_string_input(nova_carta.codigo_carta, sizeof(nova_carta.codigo_carta), "Código da carta: ");

    clear_buffer();

    read_string_input(nova_carta.estado, sizeof(nova_carta.estado), "Estado: ");

    read_string_input(nova_carta.nome_cidade, sizeof(nova_carta.nome_cidade), "Cidade: ");

    nova_carta.populacao = read_int_input("População: ");

    nova_carta.area = read_float_input("Area: ");

    nova_carta.pib = read_double_input("PIB: ");

    nova_carta.qtd_pontos_turisticos = read_int_input("Quantidade de Pontos Turísticos: ");

    add_element(cartas, &nova_carta);

    printf("\n*****************************\nCarta Cadastrada com sucesso!\n*****************************\n");

    imprimir_carta(nova_carta);
}



