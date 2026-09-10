#include <stdio.h>
#define REN 10
#define COL 10
//prototipos
void llenar();
void imprimir();
//matriz global
int mat[REN][COL]; // Matriz cuadrada de enteros de 10x10
int main(){
    printf("\nJonathan Rodriguez Ibarra\n");
    llenar(); 
    imprimir();    
    return 0;
}
void llenar(){
    for (int i = 0; i < REN; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == j) {
                mat[i][j] = 0;
            } else {
                mat[i][j] = 1;
            }
        }
    }
}
void imprimir(){
    printf("Matriz de %dx%d:\n", REN, COL);
    for (int i = 0; i < REN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%2d ", mat[i][j]); 
        }
        printf("\n");
    }
}
