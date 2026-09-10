//Equivalencia
//Jonathan Rodriguez Ibarra
#include <stdio.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int td, h, m, s;

    //DE
    printf("\nTotal de Dias:");
    scanf("%d",&td);
    
    //procerso
    //Calcular distancia recorrida
    h=td*24;
    m=h*60;
    s=m*60;
    
    //DS
    printf("\nHoras: %d", h);
    printf("\nMinutos: %d", m);
    printf("\nSegundos: %d", s);

    return 0;
}//fin del main

