#include <stdio.h>

/*
 * Simula movimentos complexos de peças de xadrez:
 * Torre - recursividade
 * Bispo - recursividade + loops aninhados
 * Rainha - recursividade
 * Cavalo - loops aninhados com múltiplas variáveis e controle com break/continue
 */

// ----- TORRE -----
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// ----- BISPO (recursivo) -----
void moverBispoRecursivo(int casas) {
    if (casas == 0) return;
    printf("Cima, Direita\n");
    moverBispoRecursivo(casas - 1);
}

// ----- BISPO (loops aninhados) -----
void moverBispoAninhado(int linhas, int colunas) {
    printf("Movimento do Bispo com Loops Aninhados:\n");
    for (int i = 1; i <= linhas; i++) {
        for (int j = 1; j <= colunas; j++) {
            if (i == j) {
                printf("Diagonal (%d,%d): Cima e Direita\n", i, j);
            }
        }
    }
    printf("\n");
}

// ----- RAINHA -----
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// ----- CAVALO -----
void moverCavaloComplexo() {
    printf("Movimento do Cavalo (Cima e Direita):\n");
    int movimentos = 0;

    for (int linha = 8; linha >= 1; linha--) {
        for (int coluna = 1; coluna <= 8; coluna++) {
            if (linha - 2 < 1 || coluna + 1 > 8) {
                continue; // ignora movimentos inválidos no tabuleiro
            }

            printf("Cavalo: Linha %d, Coluna %d -> ", linha, coluna);
            printf("2 para cima, 1 para direita\n");
            movimentos++;

            if (movimentos >= 5) break; // limita a 5 movimentos para não gerar saída excessiva
        }
        if (movimentos >= 5) break;
    }
    printf("\n");
}

int main() {
    // Movimento da TORRE
    printf("Movimento da Torre (Recursivo):\n");
    moverTorre(5);
    printf("\n");

    // Movimento do BISPO - Recursivo
    printf("Movimento do Bispo (Recursivo):\n");
    moverBispoRecursivo(5);
    printf("\n");

    // Movimento do BISPO - Loops Aninhados
    moverBispoAninhado(5, 5);

    // Movimento da RAINHA
    printf("Movimento da Rainha (Recursivo):\n");
    moverRainha(8);
    printf("\n");

    // Movimento do CAVALO
    moverCavaloComplexo();

    return 0;
}
