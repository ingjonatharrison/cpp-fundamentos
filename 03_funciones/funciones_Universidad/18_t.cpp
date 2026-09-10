#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\nJonathan Rodriguez Ibarra");
    int op;//DVyC
    do
    {
        printf("\nQue quieres ordenar?");//DE
        printf("\n1) Hamburguesa");
        printf("\n2) Hot dog");
        printf("\n3) Torta");
        printf("\n4) Burrito");
        printf("\nSelecciona un numero entre 1 y 4: ");
        scanf("%d", &op);
        switch (op)//Proceso y DS
        {
        case 1:
            printf("\nHamburguesa a la orden");
            break;
        case 2:
            printf("\nHot dog a la orden");
            break;
        case 3:
            printf("\nTorta a la orden");
            break;
        case 4:
            printf("\nBurrito a la orden");
            break;
        default:
            printf("\nError, numero de 1 a 4");
            break;
        }
    } while (op<1 || op>4);
	printf("\n");
	system("pause");
    return 0;
}//fin del main