#include <stdio.h>
#include <stdlib.h>

#define REN 3
#define COL 3

/*APRENDIENDO inicializar una matriz
  de forma manual casilla por casilla*/

void imprimir(); //prototipo

int mat[REN][COL]; //matriz global

int main(){

    printf("\nJonathan Rodriguez Ibarra");

    int r, c;
    mat[0][0] = 45;
    mat[0][1] = 12;
    mat[0][2] = 96;
    mat[1][0] = 23;
    mat[1][1] = 45;
    mat[1][2] = 75;
    mat[2][0] = 16;
    mat[2][1] = 49;
    mat[2][2] = 19;

    //imprimiendo la matriz
    imprimir();

    return 0;
} //fin main

void imprimir(){
    //imprimiendo la matriz
    int r, c;
    printf("\nImprimiendo la matriz\n");
    for (r = 0; r < REN; r++){
        for (c = 0; c < COL; c++){
            printf("%5d", mat[r][c]);
        }
        printf("\n"); //cambio de renglón
    }
} //fin imprimir
