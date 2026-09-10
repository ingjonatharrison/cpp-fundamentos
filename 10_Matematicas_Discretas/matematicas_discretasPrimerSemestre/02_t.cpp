#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\nJonathan Rodriguez Ibarra");
    int n1 , n2, n3;
    printf("\nDame el numero 1: ");//DE
    scanf("%d",&n1);
    printf("\nDame el numero 2: ");
    scanf("%d",&n2);
    printf("\nDame el numero 3: ");
    scanf("%d",&n3);
    if (n1+n2==n3)//Proceso y DS
    {
        printf("\nIguales %d y %d suman %d", n1, n2, n3);
    }
    else
    {
        if (n2+n3==n1)
        {
            printf("\nIguales %d y %d suman %d", n2, n3, n1);
        }
        else
        {
            if (n1+n3==n2)
            {
                printf("\nIguales %d y %d suman %d", n1, n3, n2);
            }
            else{
                printf("\n Ninguna combinacion cumple");
            }
        }
    } 
	printf("\n");
	system("pause");
    return 0;
}//fin del main