#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\nJonathan Rodriguez Ibarra");
    char PAIS;//DVyC
    float tp;
    int bol;
    #define EUA 1000;
    #define IS 1350;
    #define MEX 300;
    #define JAP 2000;
    printf("\nA que pais desea viajar");//DE
    PAIS=getchar();
    printf("\nCuantos boletos necesita");
    scanf("%d",&bol);
    if (PAIS != 'E' && PAIS != 'I' && PAIS != 'M' && PAIS != 'J')
    {
        printf("\nERROR");
    }
    else
    {
        switch (PAIS)
        {
        case 'E':
            tp=bol*EUA;
            break;
        case 'I':
            tp=bol*IS;
            break;
        case 'M':
            tp=bol*MEX;
            break;
        case 'J':
            tp=bol*JAP;
            break;

        }
        printf("\nTotal a pagar: %f", tp);
    }
	printf("\n");
	system("pause");
    return 0;
}//fin del main