/*
Problema das 8 Damas
*/

#include <stdio.h>

void printarTabuleiro(int tabuleiro[8][8]) {
    int i, j;
    for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf("  %d", tabuleiro[i][j]);
            }
        printf("\n");
    }
}

void colocarDama(int tabuleiro[8][8]) {
    int x, y;

    printf("Digite a posicao da dama em X: ");
    scanf("%d", &x);
    printf("Digite a posicao da dama em Y: ");
    scanf("%d", &y);
    
    y = 8 - y;
    x -= 1;
    
    tabuleiro[y][x] = 1;
    printf("Dama colocada na posicao X %d e Y %d\n", x + 1, 8 - y);

}

int main() {
    int tabuleiro[8][8] = {0};

    colocarDama(tabuleiro);
    printarTabuleiro(tabuleiro);

    return 0;
}