#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REN 10 /*constante para el
                total de renglones de la matriz*/
#define COL 12 /*constante para
                total de columnas de la matriz*/

//prototipos
void llenar();
void imprimir();
void buscar();

/* declaración de una matriz GLOBAL,
   su declaración está fuera del main
   en los primeros corchetes es el total de
   renglones y en los segundos corchetes el
   total de columnas */
int mat[ REN ][ COL ];

int main()
{
    srand( time( 0 ) ); //semillero de aleatorios
    printf( "Jonathan Rodriguez Ibarra\n" );
    printf( "\nProgramando usando una MATRIZ GLOBAL Y FUNCIONES\n" );
    llenar();   //Llama a la función llenar
    imprimir(); //Llama a la función imprimir
    buscar();   //Llama a la función buscar
    return 0;
}

void llenar()
{
    printf( "\nLlenando matriz...\n" );
    for ( int r = 0; r < REN; r++ )
	{
        for ( int c = 0; c < COL; c++ )
		{
            mat[ r ][ c ] = 1+rand() % ( 50-1+1 );
        }
    }
}

void imprimir()
{
    printf( "\nImprimiendo matriz\n" );
    for ( int r = 0; r < REN; r++ )
	{
        for ( int c = 0; c < COL; c++ )
		{
            printf( "%4d", mat[ r ][ c ] );
        }
        printf( "\n" );
    }
}

void buscar()
{
    int contador; /*variable local está dentro de
                    la función buscar*/
    int num;      /*variable local está dentro de
                    la función buscar*/

    printf( "\nBuscando un numero\n" );
    printf( "Cual numero buscas?: " );
    scanf( "%d", &num );
    contador = 0;

    for ( int r = 0; r < REN; r++ )
	{
        for ( int c = 0; c < COL; c++ )
		{
            if ( mat[ r ][ c ] == num ){
                contador = contador+1;
            }
        }
    }

    printf( "\nEl numero %d aparece %d veces ", num, contador );
}
