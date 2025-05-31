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
    
    printf("Carta 1 - %s: %d\n", cidade , populacao);
    printf("Carta 2 - %s: %d\n", cidade2 , populacao2);
    if(populacao > populacao2){
		printf("Resultado: Carta 1 (%s) venceu!", cidade);
	}else{
		printf("Resultado: Carta 2 (%s) venceu!", cidade2);
	}
	
	
    
    
    return 0;
}
