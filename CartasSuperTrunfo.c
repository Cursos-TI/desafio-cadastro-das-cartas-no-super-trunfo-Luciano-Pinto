#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    // Dados da carta
    char codigo_carta[4] = "";
    char estado[100] = "";

    // Dados da cidade
    char nome_cidade[100] ;
    int populacao = 0;
    float area = 0.0f;
    float pib = 0.0f;
    int qtd_pontos_turisticos = 0;


    // Inicio do processamento
    printf("\n==================\n");
    printf("Cadastro de Carta");
    printf("\n==================\n");

    printf("\n");
    printf("\n*******************************\n");
    printf("Digite as informações da carta:");
    printf("\n*******************************\n");
    printf("Código da carta: ");
    scanf(" %3s", codigo_carta);
    printf("Estado: ");
    scanf("  %99s", estado);
    printf("Cidade: ");
    scanf("  %9s", nome_cidade);
    printf("População: ");
    scanf(" %d", &populacao);
    printf("Área (Km2): ");
    scanf(" %f", &area);
    printf("PIB (R$): ");
    scanf(" %f", &pib);
    printf("Quantidade de Pontos Turísticos: ");
    scanf(" %d", &qtd_pontos_turisticos);


    printf("\n*****************************\n");
    printf("Carta Cadastrada com sucesso!");
    printf("\n*****************************\n");

    printf("Código da carta: %s\n", codigo_carta);
    printf("Estado: %s\n", estado);
    printf("Cidade: %s\n", nome_cidade);
    printf("População: %d\n", populacao);
    printf("Área (Km2): %.2f\n", area);
    printf("PIB (R$): %.2f\n", pib);
    printf("Quantidade de Pontos Turísticos: %d\n", qtd_pontos_turisticos);


    return 0;
}
