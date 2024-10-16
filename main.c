#include <stdio.h>
#include <stdbool.h>

#define N 8

void imprimirSolucao(int tabuleiro[N][N]) {
    // Função para imprimir a solução do tabuleiro
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", tabuleiro[i][j]);
        printf("\n");
    }
}

bool estaSeguro(int tabuleiro[N][N], int linha, int coluna) {
    int i, j;

    // Verifica esta linha na esquerda
    for (i = 0; i < coluna; i++)
        if (tabuleiro[linha][i])
            return false;

    // Verifica a diagonal superior esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j])
            return false;

    // Verifica a diagonal inferior esquerda
    for (i = linha, j = coluna; j >= 0 && i < N; i++, j--)
        if (tabuleiro[i][j])
            return false;

    return true;
}

bool resolverNQUtil(int tabuleiro[N][N], int coluna) {
    // Caso base: Se todas as rainhas forem colocadas
    if (coluna >= N)
        return true;

    // Considera esta coluna e tenta colocar todas as rainhas em todas as linhas uma por uma
    for (int i = 0; i < N; i++) {
        if (estaSeguro(tabuleiro, i, coluna)) {
            // Coloca a rainha no tabuleiro[i][coluna]
            tabuleiro[i][coluna] = 1;

            // Recursivamente coloca o resto das rainhas
            if (resolverNQUtil(tabuleiro, coluna + 1))
                return true;

            // Se colocar a rainha no tabuleiro[i][coluna] não leva a uma solução, remove a rainha do tabuleiro[i][coluna]
            tabuleiro[i][coluna] = 0;
        }
    }

    // Se a rainha não puder ser colocada em nenhuma linha nesta coluna, retorna false
    return false;
}

bool resolverNQ() {
    int tabuleiro[N][N] = {0};

    // Inicializa o tabuleiro com 0's e usa resolverNQUtil() para resolver o problema
    if (!resolverNQUtil(tabuleiro, 0)) {
        printf("Solucao nao existe");
        return false;
    }

    // Imprime a solução
    imprimirSolucao(tabuleiro);
    return true;
}

int main() {
    // Inicia a resolução do problema das N rainhas
    resolverNQ();
    return 0;
}