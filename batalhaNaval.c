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

    int navio_horizontal[4][2] = {
        {5, 4}, // linha 6, coluna E
        {5, 5}, // linha 6, coluna F
        {5, 6}, // linha 6, coluna G
        {5, 7}  // linha 6, coluna H
    };    

    //INSERINDO NAVIOS
    //VERTICAL

    for (i = 0; i < 3; i++) {
        int x = navio_vertical[i][0];
        int y = navio_vertical[i][1];
        tabuleiro[x][y] = 3;
    }

    //HORIZONTAL

    for (i = 0; i < 4; i++) {
        int x = navio_horizontal[i][0];
        int y = navio_horizontal[i][1];
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
