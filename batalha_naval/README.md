# Batalha Naval 🛥️

Este projeto simula o jogo **Batalha Naval** em C, desenvolvido em quatro fases: desde a criação do tabuleiro até a aplicação de habilidades especiais com áreas de efeito.

## 🧩 Etapas do Projeto

### ✅ Nível Novato: Posicionando Navios no Tabuleiro

- Criação de um tabuleiro 10x10 (matriz bidimensional), inicializado com água (`0`).
- Dois navios posicionados:
  - Um horizontalmente.
  - Outro verticalmente.
- As posições dos navios são representadas com o valor `3`.

### ✅ Nível Aventureiro: Exibição do Tabuleiro

- Impressão visual clara do tabuleiro com os navios.
- Uso de loops aninhados para exibição formatada.

### ✅ Nível Mestre: Habilidades Especiais

- Implementadas 3 habilidades com áreas de efeito:
  - **Cone**
  - **Cruz**
  - **Octaedro (losango frontal)**
- Cada habilidade é uma matriz de `0` (sem efeito) e `1` (área afetada).
- Áreas afetadas são sobrepostas ao tabuleiro e marcadas com `5`.

## 📌 Legenda do Tabuleiro

- `0`: Água
- `3`: Parte de navio
- `5`: Área de efeito de habilidade

## 🧪 Como executar

### Requisitos

- Compilador C (como `gcc`)

### Compilação

No terminal, dentro da pasta `batalha_naval`, digite:

```bash
gcc batalha_naval/batalha_naval.c -o batalha_naval/batalha_naval

Se compilou:

./batalha_naval/batalha_naval