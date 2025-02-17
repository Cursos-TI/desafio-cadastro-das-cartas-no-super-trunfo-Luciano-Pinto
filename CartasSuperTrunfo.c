#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

typedef struct CartaSuperTrunfo {
    char codigo_carta[4];
    char estado[100];
    char nome_cidade[100];
    int populacao;
    float area;
    float pib;
    int qtd_pontos_turisticos;
} carta_super_trunfo;

float calcularDensidadePopulacional(float populacao, float area) {
    return populacao / area;
}

float calcularPibPerCapta(float populacao, float pib) {
    return pib / populacao;
}

void initializeArray(carta_super_trunfo array[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        array[i].populacao = 0;
        strcpy(array[i].codigo_carta, "");
        strcpy(array[i].estado, "");
        strcpy(array[i].nome_cidade, "");
        array[i].area = 0.0f;
        array[i].pib = 0.0f;
        array[i].qtd_pontos_turisticos = 0;
    }
}

carta_super_trunfo inserir_carta() {
    char populacao_str[100] = "";
    char area_str[100] = "";
    char pib_str[100] = "";
    char qtd_pts_tur_str[100] = "";
    carta_super_trunfo nova_carta = {0};

    printf("\n==================\n");
    printf("Cadastro de Carta");
    printf("\n==================\n");

    printf("\nDigite as informações da carta:\n");
    printf("Código da carta: ");
    scanf(" %3s", nova_carta.codigo_carta);
    printf("Estado: ");
    scanf(" %99s", nova_carta.estado);
    printf("Cidade: ");
    scanf(" %99s", nova_carta.nome_cidade);
    printf("População: ");
    scanf(" %99s", populacao_str);

    char *endptr;
    errno = 0;
    long populacao_temp = strtol(populacao_str, &endptr, 10);
    if (errno != 0 || *endptr != '\0') {
        printf("Error: Invalid population number.\n");
        exit(EXIT_FAILURE);
    }
    nova_carta.populacao = (int) populacao_temp;

    printf("Área (Km2): ");
    scanf(" %99s", area_str);
    errno = 0;
    float area_tmp = strtof(area_str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        printf("Invalid area.\n");
        exit(EXIT_FAILURE);
    }
    nova_carta.area = area_tmp;

    printf("PIB (R$): ");
    scanf(" %99s", pib_str);
    errno = 0;
    float pib_tmp = strtof(pib_str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        printf("Invalid PIB.\n");
        exit(EXIT_FAILURE);
    }
    nova_carta.pib = pib_tmp;

    printf("Quantidade de Pontos Turísticos: ");
    scanf(" %99s", qtd_pts_tur_str);
    errno = 0;
    long temp_qtd_pts_tur = strtol(qtd_pts_tur_str, &endptr, 10);
    if (errno != 0 || *endptr != '\0') {
        printf("Error: Invalid quantity of tourist attractions.\n");
        exit(EXIT_FAILURE);
    }
    nova_carta.qtd_pontos_turisticos = (int) temp_qtd_pts_tur;

    printf("\n*****************************\n");
    printf("Carta Cadastrada com sucesso!");
    printf("\n*****************************\n");

    printf("Código da carta: %s\n", nova_carta.codigo_carta);
    printf("Estado: %s\n", nova_carta.estado);
    printf("Cidade: %s\n", nova_carta.nome_cidade);
    printf("Área: %.2f Km2\n", nova_carta.area);
    printf("População: %d hab.\n", nova_carta.populacao);
    printf("Densidade Populacional: %.2f hab./Km2\n", calcularDensidadePopulacional((float)nova_carta.populacao, nova_carta.area));
    printf("PIB: R$ %.2f\n", nova_carta.pib);
    printf("PIB per capta: R$ %.2f\n", calcularPibPerCapta((float)nova_carta.populacao, nova_carta.pib));
    printf("Quantidade de Pontos Turísticos: %d\n", nova_carta.qtd_pontos_turisticos);

    return nova_carta;
}

int main() {
    carta_super_trunfo cartas[SIZE];
    initializeArray(cartas);

    carta_super_trunfo new_card = inserir_carta();
    cartas[0] = new_card;

    printf("\nCarta salva no array com sucesso.\n");

    return 0;
}
