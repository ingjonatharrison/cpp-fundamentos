#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REN 10 /*constante para el
                total de renglones de la matriz*/
#define COL 12 /*constante para el
                total de columnas de la matriz*/

int main()
{
    srand( time( 0 )); //semillero de aleatorios
    printf( "Jonathan Rodriguez Ibarra\n" );
    printf( "\nProgramando TODO en el main usando una matriz local\n" );

    //matriz declarada como variable local (esta dentro del main)
    int mat[ REN ][ COL ];  /* declaracion de una matriz
	                        en los primeros corchetes es el total de
	                        renglones y en los segundos corchetes el
	                        total de columnas */

    int num, contador; //variable local

    printf( "\nLlenando matriz...\n" );
    for ( int r = 0; r < REN; r++ )
	{
        for ( int c = 0; c < COL; c++ )
		{
            mat[ r ][ c ] = 1+rand() % ( 50-1+1 );
        }
    }

    printf( "\nImprimiendo matriz\n" );
    for ( int r = 0; r < REN; r++ )
	{
        for ( int c = 0; c < COL; c++ )
		{
            printf( "%4d", mat[ r ][ c ] );
        }
        printf( "\n" );
    }

    printf( "\nBuscando un numero\n" );
    printf( "Cual numero buscas: " );
    scanf( "%d", &num );
    contador = 0;

    for ( int r = 0; r < REN; r++ )
	{
        for ( int c = 0; c < COL; c++ )
		{
            if ( mat[ r ][ c ] == num )
			{
                contador = contador+1;
            }
        }
    }

    printf( "\nEl numero %d aparece %d veces ", num, contador );

    return 0;
}
