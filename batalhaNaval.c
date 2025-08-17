#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10 //definindo o tamanho fixo do campo de batalha para facilitar alterações de tamanho posteriores
#define HABILIDADE 5 //definindo tamanho fixo das habilidades para facilitar futuras alterações

//Aplicar habilidade no tabuleiro
void aplicHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[HABILIDADE][HABILIDADE], int origemX, int origemY) {
    int i,j;
    int offset = HABILIDADE / 2; //centralizando a matriz
    
    for (i = 0; i < HABILIDADE; i++) {
        for(j = 0; j < HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {  //só irá aplicar se a matriz tiver 1
                int x = origemX + (i - offset);
                int y = origemY + (j - offset);

                //Limites do tabuleiro
                if (x >=0 && x < TAMANHO && y >=0 && y < TAMANHO) {
                    if (tabuleiro[x][y] == 0) {
                        tabuleiro[x][y] = 5;
                    }
                }
            }
        }
    }
} 

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
        int y = navio_diagonal_direita[i][1];
        tabuleiro[x][y] = 3;
    }


    //HABILIDADES
    int cone[HABILIDADE][HABILIDADE];
    int cruz[HABILIDADE][HABILIDADE];
    int octaedro[HABILIDADE][HABILIDADE];

    //CONE
    for (i = 0; i < HABILIDADE; i++) {
        for (j = 0; j < HABILIDADE; j++) {
            if (j >= (HABILIDADE/2 - i) && j <= (HABILIDADE/2 + i) && i <= HABILIDADE/2)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    //CRUZ
    for (i = 0; i < HABILIDADE; i++) {
        for (j = 0; j < HABILIDADE; j++) {
            if (i == HABILIDADE/2 || j == HABILIDADE/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    //octaedro
    for (i = 0; i < HABILIDADE; i++) {
        for (j = 0; j < HABILIDADE; j++) {
            if (abs(i - HABILIDADE/2) + abs(j - HABILIDADE/2) <= HABILIDADE/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;        
        }
    }

    //Aplicando habilidades no tabuleiro
    aplicHabilidade(tabuleiro, cone, 2, 7);
    aplicHabilidade(tabuleiro, cruz, 7, 7);
    aplicHabilidade(tabuleiro, octaedro, 4, 1);


    //Imprimindo campo de batalha

    printf("   ");
    for (j = 0; j < TAMANHO; j++) {
        printf("%2c ", 'A' + j); 
    }
    printf("\n"); 

    for (i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) printf(" ~ "); //água
            else if (tabuleiro[i][j] == 3) printf(" # "); //navio
            else if (tabuleiro[i][j] == 5) printf(" * "); //habilidade
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
