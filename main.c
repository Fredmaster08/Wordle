
#include <stdio.h>

int main() {
    
    char board[6][5];
    char secret_word = '\0';

    for(int i = 0; i < 6; i++) {
        printf("\n");
        for(int j = 0; j < 5; j++) {
            scanf("%c", &board[i][j]);
            board[i][j] = '_';
            printf("%c ", board[i][j]);
            board[i][j] = '\0';
        }
    }


    return 0;
}
