#include <stdio.h>
#define REN 5

/*APRENDIENDO a Llenar una matriz de char
  en el momento de la declaración*/

int main(){ 
	printf("\nJonathan Rodriguez Ibarra");
    char ciudades[REN][30]={"Leon","Aguascalientes","Guadalajara","Zacatecas","Morelia"};
    int r;
    /*imprimiendo la matriz de char*/
    printf("\nImprimiendo la matriz de caracteres\n");
    for (r=0 ; r<REN ; r++)
        printf("%s ", ciudades[r]);

    return 0;
}//fin main
