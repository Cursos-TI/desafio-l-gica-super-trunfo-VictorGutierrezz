#include <stdio.h>
#include <string.h>

int main() {
    char Estado[3], codigo[4], cidade[50];
    int pontosturisticos;
    long int populacao;
    float area, pib, densidade, pibCapita;

    char Estado2[3], codigo2[4], cidade2[50];
    int pontosturisticos2;
    long int populacao2;
    float area2, pib2, densidade2, pibCapita2;

    int opcao;

    // Entrada da Carta 1
    printf("Estado: ");
    scanf("%2s", Estado);

    printf("Codigo: ");
    scanf("%3s", codigo);

    printf("Cidade: ");
    getchar();
    fgets(cidade, sizeof(cidade), stdin);
    cidade[strcspn(cidade, "\n")] = 0;

    printf("Populacao: ");
    scanf("%ld", &populacao);

    printf("Area (em km²): ");
    scanf("%f", &area);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosturisticos);

    // Entrada da Carta 2
    printf("\nEstado: ");
    scanf("%2s", Estado2);

    printf("Codigo: ");
    scanf("%3s", codigo2);

    printf("Cidade: ");
    getchar();
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Populacao: ");
    scanf("%ld", &populacao2);

    printf("Area (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosturisticos2);

    // Cálculos
    densidade = populacao / area;
    densidade2 = populacao2 / area2;

    pibCapita = pib * 1000000000 / populacao;
    pibCapita2 = pib2 * 1000000000 / populacao2;

    // Menu interativo
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    printf("\nComparando %s vs %s\n", cidade, cidade2);

    switch(opcao) {
        case 1:
            printf("Populacao: %ld (Carta 1) vs %ld (Carta 2)\n", populacao, populacao2);
            if (populacao > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (populacao2 > populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Area: %.2f km² (Carta 1) vs %.2f km² (Carta 2)\n", area, area2);
            if (area > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (area2 > area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("PIB: %.2f bilhões (Carta 1) vs %.2f bilhões (Carta 2)\n", pib, pib2);
            if (pib > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (pib2 > pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Pontos Turisticos: %d (Carta 1) vs %d (Carta 2)\n", pontosturisticos, pontosturisticos2);
            if (pontosturisticos > pontosturisticos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (pontosturisticos2 > pontosturisticos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Densidade Demografica: %.2f hab/km² (Carta 1) vs %.2f hab/km² (Carta 2)\n", densidade, densidade2);
            if (densidade < densidade2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (densidade2 < densidade) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}

