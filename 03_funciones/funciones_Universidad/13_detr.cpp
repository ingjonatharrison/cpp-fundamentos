#include <stdio.h>
#include <stdlib.h>
//Programa que intercambia los valores de dos variables

//prototipos
void swap();

//variables globales
int a, b, auxiliar;

int main(void)
{
    //notar que no hay declaracion de variables aqui dentro
    //se estan usando las variables globales
    printf( "\nJonathan Rodriguez Ibarra" );
    printf( "\nIntroduzca a: " );
    scanf( "%d", &a );
    printf( "\nIntroduzca b: " );
    scanf( "%d", &b );
    printf( "\nAntes de intercambio\n" );
    printf( "\na: %d\n", a );
    printf( "\nb: %d\n", b );
    swap();//llamar a la funcion
    printf( "\nDespues de intercambio\n" );
    printf( "\na: %d\n", a );
    printf( "\nb: %d\n", b );
    printf( "\n" );
    system( "pause" );
    return 0;
}//fin main

void swap()
{
    //Notar que no hay declaraciones de variables aqui dentro
    //Se estan usando las variables globales
    /*Para el intercambio en necesario apoyarnos de una
    variable auxiliar*/
   auxiliar = a;
   a = b;
   b = auxiliar;
}