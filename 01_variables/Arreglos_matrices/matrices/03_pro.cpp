#include <stdio.h>
#include <stdlib.h>

#define REN 3
#define COL 2

/*APRENDIENDO A LLENAR UNA MATRIZ DE
ENTEROS CON el scanf*/

int main(){
    printf("\nJonathan Rodriguez Ibarra");
    int mat[REN][COL];
    int r, c;

    //Llenando la matriz con numeros aleatorio
    for (r = 0; r < REN; r++){
        for (c = 0; c < COL; c++){
            printf("\nDame el valor para el renglón %d columna %d: ", r, c);
            scanf("%d", &mat[r][c]);
        }
    }

    //Imprimiendo la matriz
    printf("\nImprimiendo la matriz\n");
    for (r = 0; r < REN; r++){
        for (c = 0; c < COL; c++){
            printf("%5d", mat[r][c]);
        }
        printf("\n"); //cambio de renglón
    }

    return 0;
}
