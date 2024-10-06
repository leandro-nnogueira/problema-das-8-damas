/*
Problema das 8 Damas
*/

#include <stdio.h>

void printarTabuleiro(int tabuleiro[8][8]) {
    int i, j;
    for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf(" %d", tabuleiro[i][j]);
            }
        printf("\n");
    }
}

void colocarDama(int tabuleiro[8][8], int linha, int coluna) {
    int x, y;

    printf("Digite a posicao da dama em X: ");
    scanf("%d", &x);
    printf("Digite a posicao da dama em Y: ");
    scanf("%d", &y);
    
    y = 8 - y;
    x -= 1;
    
    tabuleiro[y][x] = 1;
    printf("Dama colocada na posicao X %d e Y %d\n", x + 1, 8 - y);

    verificarHorizontal(x, y);

}

void verificarHorizontal(int tabuleiro[8][8], int x, int y) {
    for (int i = 0; i < 8; i++){
        if(i != x && tabuleiro[i][y] == 1){
            return 1;
        }
    }
    return 0;
}

int main() {
    int tabuleiro[8][8] = {0};

    colocarDama(tabuleiro);

//verifica a linha
for (i = 0; i < 8; i++){
    if(tabuleiro[linha][i]);
    
}   
    printarTabuleiro(tabuleiro);
    verificarHorizontal(tabuleiro);
    

    return 0;
}