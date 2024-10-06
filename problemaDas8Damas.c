/*
8 Queens Problem
*/

#include <stdio.h>

// Function to print the chessboard
void printBoard(int board[8][8]) {
    int i, j;
    printf("   ");
    for (i = 0; i < 8; i++) {
        printf(" %d ", i + 1);
    }
    printf("\n");

    for (i = 0; i < 8; i++) {
        printf(" %d ", 8 - i);
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 1) {
                printf(" Q ");
            } else if (board[i][j] == -1) {
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

// Function to place a queen on the board
void placeQueen(int board[8][8]) {
    int x, y, i, j;

    // Loop to get valid queen position from user
    do {
        printf("Enter the X position of the queen: ");
        scanf("%d", &x);

        printf("Enter the Y position of the queen: ");
        scanf("%d", &y);

        if (x < 1 || x > 8 || y < 1 || y > 8) {
            printf("Position out of the board. Try again.\n");
            continue;
        }

        // Check if the position is not -1
        if (board[8 - y][x - 1] == -1) {
            printf("Invalid position. Try again.\n");
        } else {
            break;
        }
    } while (1);

    y = 8 - y;
    x -= 1;
    
    board[y][x] = 1;
    printf("Queen placed at position X %d and Y %d\n", x + 1, 8 - y);

    // Mark vertical positions with -1
    for (i = 0; i < 8; i++) {
        if(board[i][x] == 0) {
            board[i][x] = -1;
        }
    }

    // Mark horizontal positions with -1
    for (i = 0; i < 8; i++) {
        if(board[y][i] == 0) {
            board[y][i] = -1;
        }
    }

    // Mark diagonal positions with -1
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if(board[i][j] == 0) {
                if(i - j == y - x || i + j == y + x) {
                    board[i][j] = -1;
                }
            }
        }
    }

}

int main() {
    int board[8][8] = {0};

    char continuePlacing;
    do {
        placeQueen(board);
        printBoard(board);
        printf("Do you want to place another queen? (y/n): ");
        scanf(" %c", &continuePlacing);
    } while (continuePlacing == 'y' || continuePlacing == 'Y');

    return 0;
}