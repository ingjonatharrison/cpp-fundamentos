#include <stdlib.h>
#include <stdio.h>

//prototipos
void proceso();

char Res;

int main()
{
    printf( "\nJonathan Rodriguez Ibarra " );
    do
    {
        proceso();
    } while ( Res == 's' || Res == 'S' );
    printf( "\n" );
    system( "pause" );
    return 0;
}

void proceso()
{
    int n, i, ContP = 0, ContN = 0;
    float Pos = 0, Neg = 0, PosF, NegF, Num;
    printf( "\nCuantos numeros quieres ingresar: " );
    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        printf( "\nDame un num Positivo o Negativo: " );
	    scanf( "%f", &Num );
	    if ( Num <= -1 )
	    {
	        Neg = Neg + Num;
	        ContN++;
	    }
	    if ( Num >= 1 )
	    {
	        Pos = Pos + Num;
	        ContP++;
	    }
    }
    PosF = Pos/ContP;
    NegF = Neg/ContN;
    printf( "\nPromedio de numeros positivos: %f\nPromedio de numeros negativos: %f ", PosF, NegF );
    printf( "\nRepetir s/n: " );
    fflush( stdin );
    Res = getchar();
}