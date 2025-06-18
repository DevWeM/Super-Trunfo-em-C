#include <stdio.h>
#include <string.h>

#define TAM 50

typedef struct {
    char nome[TAM];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// Funções auxiliares
float calcular_densidade(unsigned long int pop, float area) {
    return area > 0 ? (float)pop / area : 0.0;
}

float calcular_pib_per_capita(float pib, unsigned long int pop) {
    return pop > 0 ? pib / (float)pop : 0.0;
}

void mostrar_menu_atributos(int ignorar) {
    printf("\nEscolha um atributo:\n");
    if (ignorar != 1) printf("1. Populacao\n");
    if (ignorar != 2) printf("2. Area\n");
    if (ignorar != 3) printf("3. PIB\n");
    if (ignorar != 4) printf("4. Pontos Turisticos\n");
    if (ignorar != 5) printf("5. Densidade Demografica\n");
    if (ignorar != 6) printf("6. PIB per Capita\n");
    printf("Opcao: ");
}

// Função que retorna o valor de um atributo específico
float obter_valor_atributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade;
        case 6: return c.pib_per_capita;
        default: return 0.0;
    }
}

const char* nome_atributo(int opcao) {
    switch (opcao) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 215000000, 8516000, 2500.5, 60, 0, 0};
    Carta carta2 = {"Argentina", 45000000, 2780000, 900.3, 40, 0, 0};

    // Cálculo dos atributos derivados
    carta1.densidade = calcular_densidade(carta1.populacao, carta1.area);
    carta2.densidade = calcular_densidade(carta2.populacao, carta2.area);
    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    do {
        mostrar_menu_atributos(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 6) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 6);

    // Escolha do segundo atributo, excluindo o primeiro
    do {
        mostrar_menu_atributos(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
            printf("Opcao invalida ou repetida. Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1);

    // Obter valores dos atributos
    float valor1_a = obter_valor_atributo(carta1, atributo1);
    float valor2_a = obter_valor_atributo(carta2, atributo1);
    float valor1_b = obter_valor_atributo(carta1, atributo2);
    float valor2_b = obter_valor_atributo(carta2, atributo2);

    // Comparação individual (considerando densidade como exceção)
    int vitoria1 = 0, vitoria2 = 0;

    if (atributo1 == 5) { // densidade (menor vence)
        valor1_a < valor2_a ? vitoria1++ : vitoria2++;
    } else {
        valor1_a > valor2_a ? vitoria1++ : vitoria2++;
    }

    if (atributo2 == 5) {
        valor1_b < valor2_b ? vitoria1++ : vitoria2++;
    } else {
        valor1_b > valor2_b ? vitoria1++ : vitoria2++;
    }

    // Soma dos atributos
    float soma1 = valor1_a + valor1_b;
    float soma2 = valor2_a + valor2_b;

    // Resultado final
    printf("\n=== Comparacao Final ===\n\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Atributo 1: %s\n", nome_atributo(atributo1));
    printf("  %s: %.2f\n", carta1.nome, valor1_a);
    printf("  %s: %.2f\n\n", carta2.nome, valor2_a);

    printf("Atributo 2: %s\n", nome_atributo(atributo2));
    printf("  %s: %.2f\n", carta1.nome, valor1_b);
    printf("  %s: %.2f\n\n", carta2.nome, valor2_b);

    printf("Soma dos Atributos:\n");
    printf("  %s: %.2f\n", carta1.nome, soma1);
    printf("  %s: %.2f\n\n", carta2.nome, soma2);

    if (soma1 > soma2) {
        printf("Resultado: %s venceu a rodada!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("Resultado: %s venceu a rodada!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
