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
    } while (Res == 's' || Res == 'S');

    printf("\n");
    system("pause");
    return 0;
}

void proceso()
{
    int n, j, i;
    float sum = 0;

    printf("\nDame el valor de n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            sum = sum + 1.0 / i;
        }
    }

    printf("\nResultado: %f", sum);

    printf("\nRepetir s/n: ");

    fflush(stdin);  // limpiar buffer
    Res = getchar();
}
