#include <stdio.h>
#include <stdlib.h>
/*Repetir varias veces una palabra*/

//prototipos
void capturarPalabra();
void repetir();

//variables globales
char palabra [ 30 ];

int main()
{
    char resp;
    do
    {
        capturarPalabra(); //Llamar a la funcion
        repetir(); //Llamar a la funcion
        printf( "\n\nQuieres imprimir de nuevo s/n: " );
        fflush( stdin );
        resp = getchar();
    } while ( resp == 's' );
    printf( "\n" );
    system( "pause" );
    return 0;
}//fin main

void capturarPalabra()
{
    printf( "\nDame una palabra:" );
    fflush( stdin );
    gets( palabra );
}

void repetir()
{
    int veces;
    printf("\nCuantas veces la quieres repetir: ");
    scanf( "%d", &veces );
    printf( "\n" );
    for ( int i = 1; i <= veces; i++)
    {
        for ( int j = 1; j <= veces; j++ )
        {
            printf( "%s ", palabra );
        } 
        printf( "\n" );
    }  
}