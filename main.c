
#include <stdio.h>

#define MAX_ROWS 6
#define MAX_LETTERS 5

int main() {

    char board[MAX_ROWS][MAX_LETTERS];
    char input[MAX_ROWS][MAX_LETTERS];

    while(1) {

        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_LETTERS; j++) {
                board[i][j] = '_';
                printf("%c ", board[i][j]);
                board[i][j] = *input[i];
            }
            fgets(*input, sizeof(input), stdin);
            printf("\n");
        }

    }

    return 0;
}
