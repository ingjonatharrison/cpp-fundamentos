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
    int num, dig, aux;

    printf("\nDame el numero: ");
    scanf("%d", &num);

    aux = num; 

    while ( aux > 0 )
    {
        dig = aux % 10;   

        if ( dig == 3 )
        {
            break;        
        }

        aux = aux / 10;   
    }

    if ( aux > 0 ) 
    {
        printf("\nSi tiene numeros 3 ");
    }
    else
    {
        printf("\nNo tiene numeros 3 ");
    }

    printf("\nRepetir s/n: ");
    fflush(stdin);
    Res = getchar();
}
