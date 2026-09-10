//Uso de operadores
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int dividendo, divisor, cociente, resto;

    //DE
    printf("\nIntroduzca el dividendo (Entero):");
    scanf("%d",&dividendo);
    printf("\nIntroduzca el divisor (Entero):");
    scanf("%d",&divisor);
    
    //Procerso
    cociente=dividendo/divisor;
    resto=dividendo%divisor;
    
    //DS
    printf("%d div %d = %d (Resto=%d)", dividendo, divisor, cociente, resto);
	
	printf("\n");
	system("pause");
    return 0;
}//fin del main