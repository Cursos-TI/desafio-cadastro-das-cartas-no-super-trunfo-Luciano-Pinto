#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "super_trunfo.h"
#include "dynamic_array.h"


float calcularDensidadePopulacional(const float populacao, const float area) {
    return populacao / area;
}

float calcularPibPerCapta(const float populacao, const float pib) {
    return pib / populacao;
}

void imprimirCarta(CartaSuperTrunfo carta) {
    printf("\n*************************************\n");
    printf("Código da carta: %s\n", carta.codigo_carta);
    printf("Estado: %s\n", carta.estado);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("Área: %.2f Km2\n", carta.area);
    printf("População: %d hab.\n", carta.populacao);
    printf("Densidade Populacional: %.2f hab./Km2\n", calcularDensidadePopulacional((float) carta.populacao, carta.area));
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("PIB per capta: R$ %.2f\n", calcularPibPerCapta((float) carta.populacao, carta.pib));
    printf("Quantidade de Pontos Turísticos: %d\n", carta.qtd_pontos_turisticos);
    printf("*************************************\n");
}

void inserir_carta(DynamicArray *cartas) {
    char populacao_str[100] = "";
    char area_str[100] = "";
    char pib_str[100] = "";
    char qtd_pts_tur_str[100] = "";
    CartaSuperTrunfo nova_carta = {0};

    printf("\n==================\n");
    printf("Cadastro de Carta");
    printf("\n==================\n");

    printf("\n*******************************\n");
    printf("Digite as informações da carta:\n");
    printf("*******************************\n");

    // clearBuffer();
    printf("Código da carta: ");
    if (fgets(nova_carta.codigo_carta, sizeof(nova_carta.codigo_carta), stdin)) {
        nova_carta.codigo_carta[strcspn(nova_carta.codigo_carta, "\n")] = '\0';
    }

    clearBuffer();
    printf("Estado: ");
    if (fgets(nova_carta.estado, sizeof(nova_carta.estado), stdin)) {
        nova_carta.estado[strcspn(nova_carta.estado, "\n")] = '\0';
    }

    // clearBuffer();
    printf("Cidade: ");
    if (fgets(nova_carta.nome_cidade, sizeof(nova_carta.nome_cidade), stdin)) {
        nova_carta.nome_cidade[strcspn(nova_carta.nome_cidade, "\n")] = '\0';
    }

    // clearBuffer();
    printf("População: ");
    if (fgets(populacao_str, sizeof(populacao_str), stdin)) {
        populacao_str[strcspn(populacao_str, "\n")] = '\0';
    }

    char *endptr;
    errno = 0;
    const long populacao_temp = strtol(populacao_str, &endptr, 10);
    if (errno != 0 || *endptr != '\0') {
        printf("Error: Invalid population number.\n");
        exit(EXIT_FAILURE);
    }
    nova_carta.populacao = (int) populacao_temp;

    // clearBuffer();
    printf("Área (Km2): ");
    if (fgets(area_str, sizeof(area_str), stdin)) {
        area_str[strcspn(area_str, "\n")] = '\0';
    };
    errno = 0;
    const float area_tmp = strtof(area_str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        printf("Invalid area.\n");
        exit(EXIT_FAILURE);
    }
    nova_carta.area = area_tmp;

    // clearBuffer();
    printf("PIB (R$): ");
    if (fgets(pib_str, sizeof(pib_str), stdin)) {
        pib_str[strcspn(pib_str, "\n")] = '\0';
    }
    errno = 0;
    const float pib_tmp = strtof(pib_str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        printf("Invalid PIB.\n");
        exit(EXIT_FAILURE);
    }
    nova_carta.pib = pib_tmp;

    // clearBuffer();
    printf("Quantidade de Pontos Turísticos: ");
    if (fgets(qtd_pts_tur_str, sizeof(qtd_pts_tur_str), stdin)) {
        qtd_pts_tur_str[strcspn(qtd_pts_tur_str, "\n")] = '\0';
    };
    errno = 0;
    const long temp_qtd_pts_tur = strtol(qtd_pts_tur_str, &endptr, 10);
    if (errno != 0 || *endptr != '\0') {
        printf("Error: Invalid quantity of tourist attractions.\n");
        exit(EXIT_FAILURE);
    }
    nova_carta.qtd_pontos_turisticos = (int) temp_qtd_pts_tur;

    addElement(cartas, &nova_carta);

    printf("\n*****************************\n");
    printf("Carta Cadastrada com sucesso!");
    printf("\n*****************************\n");

    imprimirCarta(nova_carta);
}



