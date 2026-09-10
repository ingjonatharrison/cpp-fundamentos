#include <stdlib.h>
#include <stdio.h>
#include <time.h>  

//prototipos
void proceso();

char Res;

int main()
{
    srand( time( 0 ) );  

    printf("\nJonathan Rodriguez Ibarra ");
    do
    {
        proceso();
    } while ( Res == 's' || Res == 'S' );

    printf("\n");
    system("pause");
    return 0;
}

void proceso()
{
    int na, n, i;

    na = rand() % 100 + 1; 
    i = 0;

    do
    {
        printf("\nDame el valor de n: ");
        scanf("%d", &n);

        if( n < na )
        {
            printf("\nEl numero es mas grande");
        }
        else if( n > na )
        {
            printf("\nEl numero es mas chico");
        }

        i++;

    } while ( n != na );

    printf("\nFelicidades, lo hiciste en %d intentos", i);

    printf("\nRepetir s/n: ");
    fflush(stdin);
    Res = getchar();
}
