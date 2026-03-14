
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
        for(int j = 0; j < row; j++) {
            if(board[i][j] == '_') {
                if(isFilled == false) break;
                else {
                    scanf("%c", &board[i][j]);
                }
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
