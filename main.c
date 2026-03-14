
#include <stdio.h>
#include <stdbool.h>

int main() {
    
    int col = 6;
    int row = 5;

    char board[col][row];
    char secret_word = '\0';

    bool isFilled = false;

    for(int i = 0; i < col; i++) {
        for(int j = 0; j < col; j++) {
            board[i][j] = '_';
        }
    }

    for(int i = 0; i < col; i++) {
        if(isFilled == true) break;
        for(int j = 0; j < row; j++) {
            if(board[i][j] == '_' && isFilled == false) {
                scanf(" %c", &board[i][j]);
                isFilled = true;
                break;
            }
        }
    }


    for(int i = 0; i < col; i++) {
        for(int j = 0; j < col; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }



    return 0;
}
