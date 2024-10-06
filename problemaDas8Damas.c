/*
Problema das 8 Damas
*/

#include <stdio.h>

void printarTabuleiro(int tabuleiro[8][8]) {
    int i, j;
    printf("   ");
    for (i = 0; i < 8; i++) {
        printf(" %d ", i + 1);
    }
    printf("\n");

    for (i = 0; i < 8; i++) {
        printf(" %d ", 8 - i);
        for (j = 0; j < 8; j++) {
            if (tabuleiro[i][j] == 1) {
                printf(" Q ");
            } else if (tabuleiro[i][j] == -1) {
                printf(" * ");
            } else {
                printf(" . ");
            }
        }
        printf(" %d\n", 8 - i);
    }

    printf("   ");
    for (i = 0; i < 8; i++) {
        printf(" %d ", i + 1);
    }
    printf("\n");
}

void colocarDama(int tabuleiro[8][8]) {
    int x, y, i, j;

    do {
        printf("Digite a posicao da dama em X: ");
        scanf("%d", &x);

        printf("Digite a posicao da dama em Y: ");
        scanf("%d", &y);

        if (x < 1 || x > 8 || y < 1 || y > 8) {
            printf("Posicao fora do tabuleiro. Tente novamente.\n");
            continue;
        }

        // Verificar se a posicao não é -1
        if (tabuleiro[8 - y][x - 1] == -1) {
            printf("Posicao invalida. Tente novamente.\n");
        } else {
            break;
        }
    } while (1);

    y = 8 - y;
    x -= 1;
    
    tabuleiro[y][x] = 1;
    printf("Dama colocada na posicao X %d e Y %d\n", x + 1, 8 - y);

    // Colocar -1 nas vertical
    for (i = 0; i < 8; i++) {
        if(tabuleiro[i][x] == 0) {
            tabuleiro[i][x] = -1;
        }
    }

    // Colocar -1 nas horizontais
    for (i = 0; i < 8; i++) {
        if(tabuleiro[y][i] == 0) {
            tabuleiro[y][i] = -1;
        }
    }

    // Colocar -1 nas diagonais
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if(tabuleiro[i][j] == 0) {
                if(i - j == y - x || i + j == y + x) {
                    tabuleiro[i][j] = -1;
                }
            }
        }
    }

}

int main() {
    int tabuleiro[8][8] = {0};

    char continuar;
    do {
        colocarDama(tabuleiro);
        printarTabuleiro(tabuleiro);
        printf("Deseja colocar outra dama? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    return 0;
}