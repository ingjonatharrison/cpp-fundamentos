#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Prototipos
void proceso();

int main()
{
    srand(time(0)); // Inicializa random
    printf("\nJonathan Rodriguez Ibarra ");
    proceso();
    printf("\n");
    system("pause");
    return 0;
}

void proceso()
{
    int a, b, c;
    float sld, ap = 0;
    char Nom[20];
    char re;

    printf("\nDame tu nombre: ");
    scanf("%s", Nom);

    printf("\nDame el sueldo: ");
    scanf("%f", &sld);

    printf("\nQuieres apostar (s/n): ");
    fflush(stdin);
    re = getchar();

    while (sld > 0 && (re == 's' || re == 'S'))
    {
        do
        {
            printf("\nCuanto vas a apostar: ");
            scanf("%f", &ap);
        } while (ap > sld);

        system("pause");

        a = rand() % 9 + 1;
        b = rand() % 9 + 1;
        c = rand() % 9 + 1;

        printf("\n\n %d - %d - %d", a, b, c);

        printf("\nJugador %s sueldo inicial: %.2f", Nom, sld);

        if (a == b && b == c)
        {
            // Gana ? se triplica la apuesta
            sld = sld + (ap * 3);
            printf("\nGanaste! Nuevo sueldo: %.2f", sld);
        }
        else
        {
            // Pierde la apuesta
            sld = sld - ap;
            printf("\nPerdiste! Nuevo sueldo: %.2f", sld);
        }

        printf("\n\nQuieres volver a jugar (s/n): ");
        fflush(stdin);
        re = getchar();
    }

    if (sld <= 0)
    {
        printf("\nTe quedaste sin saldo");
    }
    else
    {
        printf("\nGracias por jugar");
    }
}
