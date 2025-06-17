#include <stdio.h>

#define TAM 5

void mostrarTabuleiro(char tab[TAM][TAM]) {
    printf("  1 2 3 4 5\n");
    for(int i = 0; i < TAM; i++) {
        printf("%c ", 'A' + i);
        for(int j = 0; j < TAM; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int naviosRestantes(char tab[TAM][TAM]) {
    int count = 0;
    for(int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++)
            if(tab[i][j] == 'N') count++;
    return count;
}

int main() {
    char tabuleiro[TAM][TAM] = {
        {' ', ' ', 'N', ' ', ' '},
        {'N', ' ', ' ', ' ', 'N'},
        {' ', ' ', ' ', 'N', ' '},
        {' ', 'N', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'N'}
    };

    char tabVisivel[TAM][TAM];
    for(int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++)
            tabVisivel[i][j] = '.';

    printf("=== Batalha Naval ===\n");
    mostrarTabuleiro(tabVisivel);

    int totalNavios = naviosRestantes(tabuleiro);

    while(totalNavios > 0) {
        char linha;
        int coluna;

        printf("Digite a posição para atacar (ex: A3): ");
        scanf(" %c%d", &linha, &coluna);

        int l = linha - 'A';
        int c = coluna - 1;

        if(l < 0 || l >= TAM || c < 0 || c >= TAM) {
            printf("Posição inválida! Tente novamente.\n");
            continue;
        }

        if(tabVisivel[l][c] != '.') {
            printf("Você já atacou essa posição. Tente outra.\n");
            continue;
        }

        if(tabuleiro[l][c] == 'N') {
            printf("Acertou!\n");
            tabVisivel[l][c] = 'X';
            tabuleiro[l][c] = ' ';
            totalNavios--;
        } else {
            printf("Água!\n");
            tabVisivel[l][c] = 'O';
        }

        mostrarTabuleiro(tabVisivel);
    }

    printf("Parabéns! Você afundou todos os navios.\n");

    return 0;
}
