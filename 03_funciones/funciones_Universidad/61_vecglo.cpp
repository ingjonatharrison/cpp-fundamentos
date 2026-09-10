#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 15

// Prototipos de funciones
void llenar();
void imprimir();
void promedio();
void buscar();

// Vector global
int vector[TAM];

int main() 
{
    srand( time ( 0 ) ); 
    printf( "\nJonathan Rodriguez Ibarra" );
    llenar();
    imprimir();
    promedio();
    buscar();
    printf( "\n" );
    system( "pause" );
    return 0;
}

void llenar() 
{
    printf( "\nLlenando vector... " );
    for ( int i = 0; i < TAM; i++ ) 
    {
        vector[ i ] = 6 + rand() % ( 180-6+1 ); // números entre 6 y 180
        printf( "\nListo " );
    }
}

void imprimir() 
{
    printf( "\nContenido del vector:\n" );
    for ( int i = 0; i < TAM; i++ ) 
    {
        printf( "\nvec[%d] = %d ", i, vector[i] );
    }
    printf( "\n" );
}

void promedio() 
{
    printf( "\nPromedio del vector... " );
    float acum = 0;
    for ( int i = 0; i < TAM; i++ ) 
    {
        acum += vector[i];
    }
    printf( "\nEl promedio es: %.2f\n ", acum );
}

void buscar() 
{
    int num, encontrado = 0;
    printf( "Ingrese un numero a buscar: " );
    scanf( "%d", &num );

    for ( int i = 0; i < TAM; i++ ) 
    {
        if ( vector[i] == num ) 
        {
            printf( "El numero %d se encuentra en la posicion %d.\n", num, i );
            encontrado = 1;
            break;
        }
    }
    if ( !encontrado ) 
    {
        printf( "El numero %d NO se encuentra en el vector.\n", num );
    }
}
