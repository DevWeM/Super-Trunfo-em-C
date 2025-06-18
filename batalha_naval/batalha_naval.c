#include <stdio.h>

#define TAB_LINHAS 10
#define TAB_COLUNAS 10

#define NAVIO 3
#define AGUA 0
#define AREA_HABILIDADE 5

#define HABILIDADE_TAM 5 // tamanho das matrizes de habilidade (5x5)

// Função para criar a matriz do cone (apontando para baixo)
// Origem no topo central (linha 0, coluna 2)
// Exemplo do formato:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1
void criarCone(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int l = 0; l < HABILIDADE_TAM; l++) {
        for (int c = 0; c < HABILIDADE_TAM; c++) {
            // a largura do cone aumenta a cada linha para baixo
            // linha 0: coluna central (2)
            // linha 1: colunas 1 a 3
            // linha 2: colunas 0 a 4
            if ((l == 0 && c == 2) ||
                (l == 1 && c >= 1 && c <= 3) ||
                (l == 2 && c >= 0 && c <= 4)) {
                matriz[l][c] = 1;
            } else {
                matriz[l][c] = 0;
            }
        }
    }
}

// Função para criar a matriz da cruz
// Origem no centro (linha 2, coluna 2)
// Exemplo do formato:
// 0 0 1 0 0
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0
// 0 0 1 0 0
void criarCruz(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int l = 0; l < HABILIDADE_TAM; l++) {
        for (int c = 0; c < HABILIDADE_TAM; c++) {
            if (c == 2 || l == 2) {
                matriz[l][c] = 1;
            } else {
                matriz[l][c] = 0;
            }
        }
    }
}

// Função para criar a matriz do octaedro (vista frontal, forma de losango)
// Origem no centro (linha 2, coluna 2)
// Exemplo do formato:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1
// 0 1 1 1 0
// 0 0 1 0 0
void criarOctaedro(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int l = 0; l < HABILIDADE_TAM; l++) {
        for (int c = 0; c < HABILIDADE_TAM; c++) {
            // a distância Manhattan ao centro é usada para formar o losango
            int dist = abs(l - 2) + abs(c - 2);
            if (dist <= 2) {
                matriz[l][c] = 1;
            } else {
                matriz[l][c] = 0;
            }
        }
    }
}

// Função para sobrepor a matriz de habilidade no tabuleiro, centrando na posição (origemLinha, origemColuna)
void aplicarHabilidade(int tabuleiro[TAB_LINHAS][TAB_COLUNAS], int habilidade[HABILIDADE_TAM][HABILIDADE_TAM], int origemLinha, int origemColuna) {
    int meio = HABILIDADE_TAM / 2; // 2 para tamanho 5

    for (int l = 0; l < HABILIDADE_TAM; l++) {
        for (int c = 0; c < HABILIDADE_TAM; c++) {
            if (habilidade[l][c] == 1) {
                int tabLinha = origemLinha - meio + l;
                int tabColuna = origemColuna - meio + c;

                // Confirma que está dentro do tabuleiro
                if (tabLinha >= 0 && tabLinha < TAB_LINHAS && tabColuna >= 0 && tabColuna < TAB_COLUNAS) {
                    // Não sobrescreve navios (3)
                    if (tabuleiro[tabLinha][tabColuna] == AGUA) {
                        tabuleiro[tabLinha][tabColuna] = AREA_HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAB_LINHAS][TAB_COLUNAS] = {0};

    // Posiciona alguns navios manualmente para exemplo
    // Navio horizontal no meio
    for (int i = 3; i < 6; i++) {
        tabuleiro[4][i] = NAVIO;
    }
    // Navio vertical na esquerda
    for (int i = 1; i < 4; i++) {
        tabuleiro[i][2] = NAVIO;
    }

    // Cria as matrizes de habilidade
    int cone[HABILIDADE_TAM][HABILIDADE_TAM];
    int cruz[HABILIDADE_TAM][HABILIDADE_TAM];
    int octaedro[HABILIDADE_TAM][HABILIDADE_TAM];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 1, origemConeColuna = 4;
    int origemCruzLinha = 7, origemCruzColuna = 2;
    int origemOctaedroLinha = 5, origemOctaedroColuna = 7;

    // Aplica as habilidades
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval com Areas de Efeito:\n\n");
    for (int l = 0; l < TAB_LINHAS; l++) {
        for (int c = 0; c < TAB_COLUNAS; c++) {
            if (tabuleiro[l][c] == AGUA) {
                printf("0 ");
            } else if (tabuleiro[l][c] == NAVIO) {
                printf("3 ");
            } else if (tabuleiro[l][c] == AREA_HABILIDADE) {
                printf("5 ");
            }
        }
        printf("\n");
    }

    return 0;
}
