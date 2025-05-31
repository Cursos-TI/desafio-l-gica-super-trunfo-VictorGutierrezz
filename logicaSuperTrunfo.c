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

    int attr1, attr2;
    float valor1_carta1 = 0, valor2_carta1 = 0, valor1_carta2 = 0, valor2_carta2 = 0;
    float soma1 = 0, soma2 = 0;

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

    // Menu: Escolha de dois atributos
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &attr1);

    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 5; i++) {
            if (i != attr1) {
                switch (i) {
                    case 1: printf("1 - Populacao\n"); break;
                    case 2: printf("2 - Area\n"); break;
                    case 3: printf("3 - PIB\n"); break;
                    case 4: printf("4 - Pontos Turisticos\n"); break;
                    case 5: printf("5 - Densidade Demografica\n"); break;
                }
            }
        }
        printf("Opcao: ");
        scanf("%d", &attr2);
    } while (attr1 == attr2 || attr2 < 1 || attr2 > 5);

    // Atribuição dos valores dos atributos
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? attr1 : attr2;
        float *valCarta1 = (i == 1) ? &valor1_carta1 : &valor2_carta1;
        float *valCarta2 = (i == 1) ? &valor1_carta2 : &valor2_carta2;

        switch (atributo) {
            case 1:
                *valCarta1 = populacao;
                *valCarta2 = populacao2;
                break;
            case 2:
                *valCarta1 = area;
                *valCarta2 = area2;
                break;
            case 3:
                *valCarta1 = pib;
                *valCarta2 = pib2;
                break;
            case 4:
                *valCarta1 = pontosturisticos;
                *valCarta2 = pontosturisticos2;
                break;
            case 5:
                *valCarta1 = densidade;
                *valCarta2 = densidade2;
                break;
        }
    }

    // Comparação e soma
    printf("\nComparando %s vs %s\n", cidade, cidade2);
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? attr1 : attr2;
        float val1 = (i == 1) ? valor1_carta1 : valor2_carta1;
        float val2 = (i == 1) ? valor1_carta2 : valor2_carta2;

        const char* nomeAttr;
        switch (atributo) {
            case 1: nomeAttr = "Populacao"; break;
            case 2: nomeAttr = "Area"; break;
            case 3: nomeAttr = "PIB"; break;
            case 4: nomeAttr = "Pontos Turisticos"; break;
            case 5: nomeAttr = "Densidade Demografica"; break;
        }

        printf("\n%s:\n", nomeAttr);
        printf("Carta 1 (%s): %.2f\n", cidade, val1);
        printf("Carta 2 (%s): %.2f\n", cidade2, val2);

        if (atributo == 5) { // Menor vence
            printf("Resultado: %s\n", (val1 < val2) ? cidade : (val2 < val1) ? cidade2 : "Empate");
        } else {
            printf("Resultado: %s\n", (val1 > val2) ? cidade : (val2 > val1) ? cidade2 : "Empate");
        }

        soma1 += (atributo == 5) ? -val1 : val1;  // Inverte o valor para soma comparável
        soma2 += (atributo == 5) ? -val2 : val2;
    }

    // Resultado final
    printf("\n--- Resultado Final ---\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", cidade, soma1);
    printf("%s: %.2f\n", cidade2, soma2);

    if (soma1 > soma2) {
        printf("Vencedora: Carta 1 (%s)\n", cidade);
    } else if (soma2 > soma1) {
        printf("Vencedora: Carta 2 (%s)\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

