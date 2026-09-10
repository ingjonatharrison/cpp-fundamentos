#include <stdio.h>
#include <stdlib.h>
#include <string.h>//<---------strcpy
#define REN 5

/*APRENDIENDO a Llenar una matriz de char
  de forma manual  renglón por renglón*/

int main(){
	printf("\nJonathan Rodriguez Ibarra");
    char ciudades[REN][30]; /*almacenara 5 ciudades cada una
                               con una longitud max de 30 caracteres*/
    int r;

    strcpy(ciudades[0], "Leon");           //asigna al renglón 0 de la matriz la palabra Leon
    strcpy(ciudades[1], "Aguascalientes"); //asigna al renglón 1 de la matriz la palabra Aguascalientes
    strcpy(ciudades[2], "Guadalajara");    //asigna al renglón 2 de la matriz la palabra Guadalajara
    strcpy(ciudades[3], "Zacatecas");      //asigna al renglón 3 de la matriz la palabra Zacatecas
    strcpy(ciudades[4], "Morelia");        //asigna al renglón 4 de la matriz la palabra Morelia

    /*imprimiendo la matriz de char*/
    printf("\nImprimiendo la matriz de caracteres\n");
    for (r=0; r<REN; r++)
        printf("%s ", ciudades[r]);

    return 0;
}//fin main
