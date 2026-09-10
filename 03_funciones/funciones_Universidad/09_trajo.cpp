#include <stdlib.h>
#include <stdio.h>

//prototipos
void proceso();

char Res;

int main()
{
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
    int n, cont, i;

    // Validación: un número primo debe ser mayor o igual a 2
    do
    {
        printf("\nDame el valor de n (>=2): ");
        scanf("%d", &n);
    } while ( n < 2 );

    cont = 0;

    for ( i = 1; i <= n; i++ )
    {
        if ( n % i == 0 )
        {
            cont++;
        }
    }

    if ( cont == 2 )
    {
        printf("\n%d SI es un numero primo", n);
    }
    else
    {
        printf("\n%d NO es un numero primo", n);
    }

    printf("\nRepetir s/n: ");
    fflush(stdin);
    Res = getchar();
}
