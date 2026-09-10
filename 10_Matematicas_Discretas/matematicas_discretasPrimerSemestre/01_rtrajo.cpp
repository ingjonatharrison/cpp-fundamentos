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
    int n, i;
    long long M;

    do
    {
        printf("\nDame el valor de n (>=0): ");
        scanf("%d", &n);
    } while (n < 0);

    M = 1;

    for (i = 1; i <= n; i++)
    {
        M = M * i;
    }

    printf("\nEl factorial de %d es %lld", n, M);

    printf("\nRepetir s/n: ");
    fflush(stdin);
    Res = getchar();
}
