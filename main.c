
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_ROWS 6
#define MAX_LETTERS 5
#define WORDLE 5
#define MAX_SIZE 256


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

void print_board(char board[MAX_ROWS][MAX_LETTERS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_LETTERS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void fill_in(char board[MAX_ROWS][MAX_LETTERS], char buffer[MAX_SIZE]) {
    for (int i = 0; i < strlen(buffer) - 1; i++) {
        buffer[i] = board[i];
    }
}

int main() {

    char board[MAX_ROWS][MAX_LETTERS];

    init_board(board);

    while(1) {

        print_board(board);
        char buffer[MAX_SIZE];
        fgets(buffer, MAX_SIZE, stdin);
        printf("%s\n", buffer);
        printf("%d\n", strlen(buffer) - 1);
    

        if (!validate_input(buffer)) {
            continue;
        }
        fill_in(board, buffer);
        
    }           

    return 0;
}
