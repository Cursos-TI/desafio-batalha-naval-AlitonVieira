#include <stdio.h>

#define TAMANHO 10 //definindo o tamanho fixo do campo de batalha para facilitar alterações de tamanho posteriores

int main() {

    int tabuleiro[TAMANHO][TAMANHO];
    int i, j;

    for (i = 0; i < TAMANHO; i++){
        for (j = 0; j < TAMANHO; j++){
            tabuleiro[i][j] = 0;
        }
    }


    //DEFININDO NAVIOS
    int navio_vertical[3][2] = {
        {1, 2}, // linha 2, coluna c
        {2, 2}, // linha 3, coluna c
        {3, 2}  // linha 4, coluna c
    };

    int navio_horizontal[3][2] = {
        {5, 4}, // linha 6, coluna E
        {5, 5}, // linha 6, coluna F
        {5, 6}, // linha 6, coluna G
    };    

    int navio_diagonal_esquerda[3][2] = {
        {0, 6}, //linha 1, coluna G
        {1, 5}, //linha 2, coluna F
        {2, 4}  //linha 3, coluna E
    };

    int navio_diagonal_direita[3][2] = {
        {7, 2}, //linha 8, coluna H
        {8, 3}, //linha 9, coluna I
        {9, 4}  //linha 10, coluna J
    };

    //INSERINDO NAVIOS
    //VERTICAL

    for (i = 0; i < 3; i++) {
        int x = navio_vertical[i][0];
        int y = navio_vertical[i][1];
        tabuleiro[x][y] = 3;
    }

    //HORIZONTAL

    for (i = 0; i < 3; i++) {
        int x = navio_horizontal[i][0];
        int y = navio_horizontal[i][1];
        tabuleiro[x][y] = 3;
    }    

    //DIAGONAL ESQUERDA

    for (i = 0; i < 3; i++) {
        int x = navio_diagonal_esquerda[i][0];
        int y = navio_diagonal_esquerda[i][1];
        tabuleiro[x][y] = 3;
    }

    //DIAGONAL DIREITA

    for (i = 0; i < 3; i++) {
        int x = navio_diagonal_direita[i][0];
        int y = navio_diagonal_direita[i][0];
        tabuleiro[x][y] = 3;
    }


    //COLOCANDO NO CAMPO DE BATALHA

    printf("   ");
    for (j = 0; j < TAMANHO; j++) {
        printf("%2c ", 'A' + j); 
    }
    printf("\n"); 

    for (i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("%2d\n", i + 1);
    }

    printf("   ");
    for (j = 0; j < TAMANHO; j++) {
        printf("%2c ", 'A' + j);
    }
    printf("\n");    
    
    
    return 0;
}
