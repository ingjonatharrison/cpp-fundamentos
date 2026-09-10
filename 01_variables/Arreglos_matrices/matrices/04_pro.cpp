#include <stdio.h>
#include <stdlib.h>

#define REN 4
#define COL 3

/*APRENDIENDO inicializar una matriz
   en el momento de su declaración*/

int main(){
    printf("\nJonathan Rodriguez Ibarra");
    int mat[REN][COL] = { {34, 56, 75}, {12, 98, 34}, {34, 78, 12}, {34, 23, 67} };
    int r, c;

    //imprimiendo la matriz
    printf("\nImprimiendo la matriz\n");
    for (r = 0; r < REN; r++){
        for (c = 0; c < COL; c++){
            printf("%5d", mat[r][c]);
        }
        printf("\n"); //cambio de renglón
    }

    return 0;
}
