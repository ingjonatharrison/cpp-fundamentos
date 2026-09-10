#include <stdio.h>
#include <stdlib.h>
#define REN 5

/*APRENDIENDO a Llenar una matriz de char
  usando scanf*/

int main(){
	printf("\nJonathan Rodriguez Ibarra");
    char ciudades[REN][30]; /*almacenara 5 ciudades cada una
                               con una longitud maxima de 30 caracteres*/

    int r;
    /*LAS MATRICES DE char es posible programarlas
      solo con un ciclo*/
    for (r=0; r<REN; r++){
        printf("\nDame el nombre de una ciudad %d: ", r);
        gets(ciudades[r]);
    }

    /*imprimiendo la matriz de char*/
    printf("\nImprimiendo la matriz de caracteres\n");
    for (r=0; r<REN; r++){
        printf("\n%s", ciudades[r]);/*notar que aunque se trata
                                        de una matriz ES POSIBLE usar SOLO el
                                        ciclo de los renglones, no es necesario
                                        el segundo ciclo GRACIAS a que el
                                        uso del gets() ayuda a detectar el fin
                                        del string
                                        de cada renglón*/
    }

    return 0;
}//fin main
