#include <stdio.h>

int main() {
    int Tabuleiro[10][10];

    for (int i = 0; i < 10; i++) {   // Inicializando tabuleiro com 0
        for (int j = 0; j < 10; j++) {
            Tabuleiro[i][j] = 0;
        }
    }

    for (int j=1; j<4; j++){ // atribuindo posição do navio horizontal, de B3 A D3
        if (j<0 || j>9){ // validação de posição válida
            printf("Posição inválida\n");
            break;
        }
        Tabuleiro[2][j] = 3;
    }
    
    for (int i=6; i<9; i++){ // atribuindo posição do navio vertical, de I7 a I9
        if (i<0 || i>9){ // validação de posição válida
            printf("Posição inválida\n");
            break;
        }
        if (Tabuleiro[i][8] == 3){ // validação de sobreposição de navios simplificada. Msg de erro será exibida e tabuleiro será imprimido com apenas o primeiro navio
            printf("Navios sobrepostos!\n");
            break;
        }
        Tabuleiro[i][8] = 3;
    }

    printf("   |"); // imprimindo espaço e demarcador da matriz
    for (int i = 65; i<75; i++) { // utilizando a tabela ASCII para imprimir as letras
        printf(" %c |", i); //impressão do índice da coluna, utilizando a tabela ASCII
    }

    printf("\n");

    for (int i = 0; i < 10; i++) { // loop aninhado para impressão do tabuleiro
        if (i<=8){ // condicional para imprimir o espaço antes do número, caso a numeração seja menor que 10 (posição 0 a 8 - 9 posições)
            printf(" %d |", i+1); //impressão do índice da linha
        }else{ // caso seja maior que 10, não imprime o espaço
            printf("%d |", i+1); // impressão do índice da linha, caso numeração >=10, ou posição no vetor >=9
        }
        for (int j = 0; j < 10; j++) {
            printf(" %d |", Tabuleiro[i][j]); //impressão do tabuleiro
        }
        printf("\n");
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
