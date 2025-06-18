#include <stdio.h>
#include <string.h>

#define TAM 50

typedef struct {
    char estado[TAM];
    char nome[TAM];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular densidade populacional
float calcular_densidade(unsigned long int pop, float area) {
    return area > 0 ? (float)pop / area : 0.0;
}

// Função para calcular PIB per capita
float calcular_pib_per_capita(float pib, unsigned long int pop) {
    return pop > 0 ? pib / (float)pop : 0.0;
}

// Função para calcular Super Poder
float calcular_super_poder(Carta c) {
    float inverso_densidade = c.densidade > 0 ? 1.0f / c.densidade : 0.0f;
    return (float)c.populacao + c.area + c.pib + (float)c.pontos_turisticos + c.pib_per_capita + inverso_densidade;
}

// Função para ler os dados de uma carta
void ler_carta(Carta *c, int numero) {
    printf("Digite os dados da Carta %d:\n", numero);
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Nome: ");
    scanf(" %[^\n]", c->nome);

    printf("Populacao (unsigned long int): ");
    scanf("%lu", &c->populacao);

    printf("Area (float): ");
    scanf("%f", &c->area);

    printf("PIB (float): ");
    scanf("%f", &c->pib);

    printf("Numero de Pontos Turisticos (int): ");
    scanf("%d", &c->pontos_turisticos);

    c->densidade = calcular_densidade(c->populacao, c->area);
    c->pib_per_capita = calcular_pib_per_capita(c->pib, c->populacao);
    c->super_poder = calcular_super_poder(*c);
}

// Função para imprimir resultado da comparação
void comparar_e_imprimir(const char *atributo, int resultado) {
    printf("%s: Carta %d venceu (%d)\n", atributo, resultado ? 1 : 2, resultado);
}

int main() {
    Carta carta1, carta2;

    // Leitura
    ler_carta(&carta1, 1);
    ler_carta(&carta2, 2);

    printf("\nComparacao de Cartas:\n\n");

    // Comparações
    comparar_e_imprimir("Populacao", carta1.populacao > carta2.populacao);
    comparar_e_imprimir("Area", carta1.area > carta2.area);
    comparar_e_imprimir("PIB", carta1.pib > carta2.pib);
    comparar_e_imprimir("Pontos Turisticos", carta1.pontos_turisticos > carta2.pontos_turisticos);
    comparar_e_imprimir("Densidade Populacional", carta1.densidade < carta2.densidade);
    comparar_e_imprimir("PIB per Capita", carta1.pib_per_capita > carta2.pib_per_capita);
    comparar_e_imprimir("Super Poder", carta1.super_poder > carta2.super_poder);

    return 0;
}
