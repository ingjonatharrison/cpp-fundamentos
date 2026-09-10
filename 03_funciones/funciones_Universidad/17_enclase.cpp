#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REN 4
#define COL 5

// matrices globales
char obreros[REN][7];
int edad[REN];
int prod[REN][COL];

// Prototipos
void llenarNomEdades();
void llenarProduccion();
void imprimir();

int main()
{
    printf("\nJonathan Rodriguez Ibarra");
    srand(time(0));  
    llenarNomEdades();
    llenarProduccion();
    imprimir();
    printf("\n");
    system("pause");
    return 0;
}

void llenarNomEdades()
{
    for(int i = 0; i < REN; i++)
    {
        printf("\nDame nombre del obrero %d: ", i+1);
        fflush(stdin);
        gets(obreros[i]);

        printf("Dame la edad de %s: ", obreros[i]);
        scanf("%d", &edad[i]);
    }
}

void llenarProduccion()
{
    for(int r = 0; r < REN; r++)
    {
        for(int c = 0; c < COL; c++)
        {
            prod[r][c] = 30 + rand() % (70 - 30 + 1);
        }
    }
}

//agregue para imprimir todo
void imprimir()
{
    printf("\n REPORTE \n");

    for(int i = 0; i < REN; i++)
    {
        printf("\nObrero: %s  - Edad: %d\n", obreros[i], edad[i]);
        printf("Produccion: ");

        for(int c = 0; c < COL; c++)
        {
            printf("%d ", prod[i][c]);
        }
        printf("\n");
    }
}
