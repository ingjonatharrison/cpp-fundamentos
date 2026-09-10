#include <stdio.h>
#include <stdlib.h>

#define REN 4
#define COL 5

// Prototipos correctos (sin parámetros porque usamos matriz global)
void llenarMatriz();
void imprimirMatriz();
void sumatoriaRenglones();

// matriz global
int m[REN][COL];

int main(){
    printf("Jonathan Rodriguez Ibarra\n\n");

    llenarMatriz();
    printf("\nMatriz ingresada:\n");
    imprimirMatriz();

    printf("\nSumatoria por renglones:\n");
    sumatoriaRenglones();

    return 0;
}

// Llenar matriz
void llenarMatriz(){
    for(int i = 0; i < REN; i++){
        for(int j = 0; j < COL; j++){
            printf("Valor [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

// Imprimir matriz
void imprimirMatriz(){
    for(int i = 0; i < REN; i++){
        for(int j = 0; j < COL; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Sumatoria por renglones
void sumatoriaRenglones(){
    for(int i = 0; i < REN; i++){
        int suma = 0;
        for(int j = 0; j < COL; j++){
            suma += m[i][j];
        }
        printf("Renglón %d = %d\n", i, suma);
    }
}
