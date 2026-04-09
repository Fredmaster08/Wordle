
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_ROWS 6
#define MAX_LETTERS 5
#define WORDLE 5
#define MAX_SIZE 256

#define YELLOW "\x1b[33m"
#define GREEN "\x1b[32m"

#define CLEAR "\x1B[2J\x1B[H"
#define BOLD "\x1b[1m"
#define RESET "\x1b[0m"

void init_board(char board[MAX_ROWS][MAX_LETTERS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_LETTERS; j++) {
            board[i][j] = '_';
        }
    } 
}

bool validate_input(char buffer[MAX_SIZE]) {
    if (strlen(buffer) - 1 != WORDLE) {
        printf("Invalid Length.\n");
        return false;
    }
    for (int i = 0; i < strlen(buffer) - 1; i++) {
        char c = buffer[i];
        if (!isalpha(c)) {
            printf("Enter valid character.\n");
            return false;
        }
    }
    return true;
}

void print_board(char board[MAX_ROWS][MAX_LETTERS], const char* wordle) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_LETTERS; j++) {
            if(board[i][j] == wordle[j]) {
                printf(GREEN BOLD"%c " RESET, board[i][j]);
            }
            else {
                bool found = false;
                for (int k = 0; k < WORDLE; k++) {
                    if (board[i][j] == wordle[k]) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    printf(YELLOW "%c " RESET, board[i][j]);
                } else {
                    printf("%c ", board[i][j]);
                }
            }
        }
        printf("\n");
    }
}

void fill_in(char board[MAX_ROWS][MAX_LETTERS], char buffer[MAX_SIZE], int* row) {
    for (int i = 0; i < WORDLE; i++) {
        board[*row][i] = toupper(buffer[i]);
    }
    (*row)++;
}

int main() {

    printf(CLEAR);

    char board[MAX_ROWS][MAX_LETTERS];
    int row = 0;
    const char* wordle = "FIRES";

    init_board(board);
    print_board(board, wordle);

    while(1) {

        char buffer[MAX_SIZE];
        fgets(buffer, MAX_SIZE, stdin);
    
        if (!validate_input(buffer)) {
            continue;
        }
        fill_in(board, buffer, &row);
        printf(CLEAR);
        print_board(board, wordle);
        
    }           

    return 0;
}
