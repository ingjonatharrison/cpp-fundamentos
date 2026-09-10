#include <stdlib.h>
#include <stdio.h>
#include <math.h>   

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
    int n, i, x;
    float re = 1.0;   

    printf("\nDame el valor de x: ");
    scanf("%d", &x);

    printf("\nDame el valor de n: ");
    scanf("%d", &n);

    for ( i = 1; i <= n; i++ )
    {
        re = re + 1.0 / pow(x, i);
    }

    printf("\nEl resultado de la suma es: %f", re);

    printf("\nRepetir s/n: ");
    fflush(stdin);
    Res = getchar();
}
