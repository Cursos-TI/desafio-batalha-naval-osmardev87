#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define LINHAS 10
#define COLUNAS 10

void iniciaTabuleiro(int tabuleiro[LINHAS][COLUNAS])
{
    for (int i = 0; i < LINHAS; i++)
    {

        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}

void colocaNavio(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, int direcao)
{

    switch (direcao)
    {
    case 1:
        for (int j = coluna; j < coluna + 3; j++)
            tabuleiro[linha][j] = 3;
        break;
    case 2:
        for (int i = linha; i < linha + 3; i++)
            tabuleiro[i][coluna] = 3;
        break;
    }
}

void mostraTabuleiro(int tabuleiro[LINHAS][COLUNAS])
{
    printf("\n\n==================== Batalha Naval ==================== \n\n");

    printf("  ");
    char letras = 'A';
    for (int n = 0; n < 10; n++)
    {
        printf("%3c", letras);
        letras++;
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++)
        {

            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n\n======================================================= \n\n");
}

void navioNaDiagonal(int tabuleiro[LINHAS][COLUNAS], int linha, int col)
{
    // batalha naval navio na diagonaç
    // coloca um navio de tamanho 3 na diagonal
    for (int i = 0; i < 3; i++)
    {
        if (linha + i < LINHAS && col + i < COLUNAS)
        {
            tabuleiro[linha + i][col + i] = 3;
        }
    }
}

void navioNaDiagonalInvertida(int tabuleiro[LINHAS][COLUNAS], int linha, int col)
{
    // batalha naval navio na diagonaç
    // coloca um navio de tamanho 3 na diagonal
    // navio diagonal invertida ( / )
    for (int i = 0; i < 3; i++)
    {
        if (linha + i < LINHAS && col - i >= 0)
        {
            tabuleiro[linha + i][col - i] = 3;
        }
    }
}

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.

    int tabuleiro[10][10];
    // Inicia o tabuleiro
    iniciaTabuleiro(tabuleiro);

    // VERTICAL
    colocaNavio(tabuleiro, 2, 2, 1);

    // HORISONTAL 
    colocaNavio(tabuleiro, 0, 1, 2);

    navioNaDiagonal(tabuleiro, 5, 2);

    navioNaDiagonalInvertida(tabuleiro, 4, 7);

    // mostar o tabuleiro
    mostraTabuleiro(tabuleiro);

    
    return 0;
}
