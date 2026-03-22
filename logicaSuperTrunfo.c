#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Cidades

int main() {
    char estadoCidade1[3], estadoCidade2[3];
    char codigoCidade1[4], codigoCidade2[4];
    char nomeCidade1[20], nomeCidade2[20];
    unsigned long int populacaoCidade1, populacaoCidade2;
    float areaCidade1, areaCidade2;
    float PIBCidade1, PIBCidade2;
    int pontosCidade1 = 0, pontosCidade2 = 0;
    float densidadePopulacionalCidade1, densidadePopulacionalCidade2;
    float pibPerCapitaCidade1, pibPerCapitaCidade2;
    unsigned long int superPoderCidade1, superPoderCidade2;

    // Leitura dos dados da Cidade 1
    printf("Digite o estado da Cidade: ");
    scanf("%s", estadoCidade1);
    printf("Digite o código da Cidade 1 (3 caracteres): ");
    scanf("%s", codigoCidade1);
    printf("Digite o nome da Cidade 1: ");
    // ler string de forma segura, mesmo quando tiver espaços, usando fgets e removendo o newline
    getchar(); // Limpar o buffer do teclado antes de usar fgets
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    // Remover o newline do final da string
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';    
    
    printf("Digite a população da Cidade 1: ");
    scanf("%lu", &populacaoCidade1);
    printf("Digite a área da Cidade 1 (em km²): ");
    scanf("%f", &areaCidade1);
    printf("Digite o PIB da Cidade 1 (em bilhões): ");
    scanf("%f", &PIBCidade1);
    printf("Digite o número de pontos turísticos da Cidade 1: ");
    scanf("%d", &pontosCidade1);

    // Leitura dos dados da Cidade 2
    printf("Digite o estado da Cidade 2: ");
    scanf("%s", estadoCidade2);
    printf("Digite o código da Cidade 2 (3 caracteres): ");
    scanf("%s", codigoCidade2);
    printf("Digite o nome da Cidade 2: ");
    // ler string de forma segura, mesmo quando tiver espaços, usando fgets e removendo o newline
    getchar(); // Limpar o buffer do teclado antes de usar fgets
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    // Remover o newline do final da string
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("Digite a população da Cidade 2: ");
    scanf("%lu", &populacaoCidade2);
    printf("Digite a área da Cidade 2 (em km²): ");
    scanf("%f", &areaCidade2);
    printf("Digite o PIB da Cidade 2 (em bilhões): ");
    scanf("%f", &PIBCidade2);
    printf("Digite o número de pontos turísticos da Cidade 2: ");
    scanf("%d", &pontosCidade2);

    densidadePopulacionalCidade1 = (float) populacaoCidade1 / areaCidade1;
    densidadePopulacionalCidade2 = (float) populacaoCidade2 / areaCidade2;
    // Aqui multiplicamos o PIB por 1 bilhão (1000000000) para converter de bilhões para unidades monetárias antes de dividirmos pela população para obter o PIB per capita.
    pibPerCapitaCidade1 = (float) (PIBCidade1 * 1000000000) / populacaoCidade1;
    pibPerCapitaCidade2 = (float) (PIBCidade2 * 1000000000) / populacaoCidade2;
    // Para o super poder, vamos usar a soma da população, area, PIB per capita e pontos turísticos e o inverso da densidade populacional (1/densidade) para criar um valor único que representa a cidade.
    //superPoderCidade1 = populacaoCidade1 + areaCidade1 + pibPerCapitaCidade1 + pontosCidade1 + (1.0f / densidadePopulacionalCidade1);
    //superPoderCidade2 = populacaoCidade2 + areaCidade2 + pibPerCapitaCidade2 + pontosCidade2 + (1.0f / densidadePopulacionalCidade2);

    // Mostrar opções para o usuário escolher qual atributo comparar entre as duas cidades
    printf("\nEscolha um atributo para comparar as cartas (1-6):\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional\n");
    printf("6. PIB per capita\n");

    // Variáveis para armazenar o resultado da comparação    
    int atributoEscolhido, cartaVencedora;
    float pontosVencedor;

    // Leitura do atributo escolhido pelo usuário
    scanf("%d", &atributoEscolhido);

    // Comparação dos atributos escolhidos e determinação do vencedor
    switch (atributoEscolhido)
    {
    case 1:
        // Comparar população
        if (populacaoCidade1 > populacaoCidade2) {
            cartaVencedora = 1;
            pontosVencedor = populacaoCidade1;   
        }
        else if (populacaoCidade2 > populacaoCidade1) {
            cartaVencedora = 2;
            pontosVencedor = populacaoCidade2;   
        } else {
            cartaVencedora = 0; // Empate
            pontosVencedor = populacaoCidade1; // Ambos têm a mesma população
        }
        break;
    case 2:
        // Comparar área
        if (areaCidade1 > areaCidade2) {
            cartaVencedora = 1;
            pontosVencedor = areaCidade1;   
        }
        else if (areaCidade2 > areaCidade1) {
            cartaVencedora = 2;
            pontosVencedor = areaCidade2;   
        } else {
            cartaVencedora = 0; // Empate
            pontosVencedor = areaCidade1; // Ambas têm a mesma área
        }
        break;
    case 3:
        // Comparar PIB
        if (PIBCidade1 > PIBCidade2) {
            cartaVencedora = 1;
            pontosVencedor = PIBCidade1;   
        }
        else if (PIBCidade2 > PIBCidade1) {
            cartaVencedora = 2;
            pontosVencedor = PIBCidade2;   
        } else {
            cartaVencedora = 0; // Empate
            pontosVencedor = PIBCidade1; // Ambas têm o mesmo PIB
        }
        break;
    case 4:
        // Comparar pontos turísticos
        if (pontosCidade1 > pontosCidade2) {
            cartaVencedora = 1;
            pontosVencedor = pontosCidade1;
        }
        else if (pontosCidade2 > pontosCidade1) {
            cartaVencedora = 2;
            pontosVencedor = pontosCidade2;
        } else {
            cartaVencedora = 0; // Empate
            pontosVencedor = pontosCidade1; // Ambas têm o mesmo número de pontos turísticos
        }
        break;
    case 5:
        // Comparar densidade populacional (menor é melhor)
        if (densidadePopulacionalCidade1 < densidadePopulacionalCidade2) {
            cartaVencedora = 1;
            pontosVencedor = densidadePopulacionalCidade1;
        }
        else if (densidadePopulacionalCidade2 < densidadePopulacionalCidade1) {
            cartaVencedora = 2;
            pontosVencedor = densidadePopulacionalCidade2;
        } else {
            cartaVencedora = 0; // Empate
            pontosVencedor = densidadePopulacionalCidade1; // Ambas têm a mesma
        }
        break;
    case 6:
        // Comparar PIB per capita
        if (pibPerCapitaCidade1 > pibPerCapitaCidade2) {
            cartaVencedora = 1;
            pontosVencedor = pibPerCapitaCidade1;
        }
        else if (pibPerCapitaCidade2 > pibPerCapitaCidade1) {
            cartaVencedora = 2;
            pontosVencedor = pibPerCapitaCidade2;
        } else {
            cartaVencedora = 0; // Empate
            pontosVencedor = pibPerCapitaCidade1; // Ambas têm o mesmo PIB per capita
        }
        break;
    default:
        printf("Atributo inválido. Por favor, escolha um número entre 1 e 6.\n");
        return 1; // Encerra o programa com código de erro
    }
            
    // Exibição do resultado da comparação
    if (cartaVencedora == 1) {
        printf("A cidade vencedora é: %s (%s) com %.2f pontos!\n", nomeCidade1, estadoCidade1, pontosVencedor);
    } else if (cartaVencedora == 2) {
        printf("A cidade vencedora é: %s (%s) com %.2f pontos!\n", nomeCidade2, estadoCidade2, pontosVencedor);
    } else {
        printf("Empate! Ambas as cidades têm %.2f pontos para o atributo escolhido.\n", pontosVencedor);
    }
    
/*
    // Exibição dos dados da cidade 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estadoCidade1);
    printf("Código: %s\n", codigoCidade1);
    printf("Nome: %s\n", nomeCidade1);
    printf("População: %lu\n", populacaoCidade1);
    printf("Área: %.2f km²\n", areaCidade1);
    printf("PIB: %.2f bilhões\n", PIBCidade1);
    printf("Pontos turísticos: %d\n", pontosCidade1);
    printf("Densidade populacional: %.2f habitantes/km²\n", densidadePopulacionalCidade1);
    printf("PIB per capita: %.2f\n", pibPerCapitaCidade1);
    printf("Super Poder: %lu\n", superPoderCidade1);

    // Exibição dos dados da cidade 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estadoCidade2);
    printf("Código: %s\n", codigoCidade2);
    printf("Nome: %s\n", nomeCidade2);
    printf("População: %lu\n", populacaoCidade2);
    printf("Área: %.2f km²\n", areaCidade2);
    printf("PIB: %.2f bilhões\n", PIBCidade2);
    printf("Pontos turísticos: %d\n", pontosCidade2);
    printf("Densidade populacional: %.2f habitantes/km²\n", densidadePopulacionalCidade2);
    printf("PIB per capita: %.2f\n", pibPerCapitaCidade2);
    printf("Super Poder: %lu\n", superPoderCidade2);

    // Comparação dos resultados
    printf("\nComparação das cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", populacaoCidade1 > populacaoCidade2);
    printf("Área: Carta 1 venceu (%d)\n", areaCidade1 > areaCidade2);
    printf("PIB: Carta 1 venceu (%d)\n", PIBCidade1 > PIBCidade2);
    printf("Pontos turísticos: Carta 1 venceu (%d)\n", pontosCidade1 > pontosCidade2);
    printf("Densidade populacional: Carta 1 venceu (%d)\n", densidadePopulacionalCidade1 < densidadePopulacionalCidade2);
    printf("PIB per capita: Carta 1 venceu (%d)\n", pibPerCapitaCidade1 > pibPerCapitaCidade2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoderCidade1 > superPoderCidade2);
*/
    return 0;
}