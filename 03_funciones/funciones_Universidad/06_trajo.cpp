#include <stdlib.h>
#include <stdio.h>

// Prototipos
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
    int n, i, NMC, Num;

    printf("\nDame el valor de n: ");
    scanf("%d", &n);

    // Captura del primer número
    printf("\nDame el valor del primer numero: ");
    scanf("%d", &Num);

    // Inicializamos NMC con el primer número
    NMC = Num;

    // Empieza desde 2 porque el primero ya se pidió
    for ( i = 2; i <= n; i++ )
    {
        printf("\nIngresa el numero %d: ", i );
        scanf("%d", &Num);

        if ( Num < NMC )
        {
            NMC = Num;
        }
    }

    printf("\nEl numero mas chico es %d ", NMC);

    printf("\nRepetir s/n: ");
    fflush(stdin);
    Res = getchar();
}
