//Uso de operadores
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int dividendo, divisor;

    //DE
    printf("\nIntroduzca el dividendo (Entero):");
    scanf("%d",&dividendo);
    printf("\nIntroduzca el divisor (Entero):");
    scanf("%d",&divisor);
    
    //Procerso y DS
    printf("%d div %d = %d (Resto=%d)", dividendo, divisor, dividendo/divisor, dividendo%divisor);
	
	printf("\n");
	system("pause");
    return 0;
}//fin del main