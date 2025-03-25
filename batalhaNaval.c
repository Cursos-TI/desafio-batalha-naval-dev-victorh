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
        if (Tabuleiro[i][8] == 3){ // validação de sobreposição de navios simplificada. Ela chega a imprimir as posições sem sobreposição, porém quando existe uma sobreposição, ele para de alocar as demais posições e informa o erro. Em seguida imprime as posições.
            printf("Navios sobrepostos!\n");
            break;
        }
        Tabuleiro[i][8] = 3;
    }

    for (int i=4; i<7; i++){ //atribuindo posição na diagonal de E5 a G7
        if (i<0 || i>9){ // validação de posição válida
            printf("Posição inválida\n");
            break;
        }
        if (Tabuleiro[i][i] == 3){ // validação de sobreposição de navios simplificada. Ela chega a imprimir as posições sem sobreposição, porém quando existe uma sobreposição, ele para de alocar as demais posições e informa o erro. Em seguida imprime as posições.
            printf("Navios sobrepostos!\n");
            break;
        }
        Tabuleiro[i][i] = 3;
    }

    for (int i=8, j=1; i>5 && j<4; i--, j++) { //atribuindo posição na diagonal de B9 a D7. Trabalhando com loop complexo ao invés de aninhado.
        if (i<0 || i>9 || j<0 || j>9){ // validação de posição válida
            printf("Posição inválida\n");
            break;
        }
        if (Tabuleiro[i][j] == 3){ // validação de sobreposição de navios simplificada. Ela chega a imprimir as posições sem sobreposição, porém quando existe uma sobreposição, ele para de alocar as demais posições e informa o erro. Em seguida imprime as posições.
            printf("Navios sobrepostos!\n");
            break;
        }
        Tabuleiro[i][j] = 3;
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
    return 0;
}