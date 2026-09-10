#include <stdio.h>
#include <stdlib.h>

#define REN 5
#define COL 6

/*APRENDIENDO A LLENAR UNA MATRIZ 
DE ENTEROS CON NUMEROS ALEATORIOS*/

int main(){
    printf("\nJonathan Rodriguez Ibarra");
    int mat[REN][COL];

    int r, c;
    //Llenando la matriz con numeros aleatorio
    for (r = 0; r < REN; r++){
        for (c = 0; c < COL; c++){
            mat[r][c] = 10 + rand() % (90 - 10 + 1);
        }
    }

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
