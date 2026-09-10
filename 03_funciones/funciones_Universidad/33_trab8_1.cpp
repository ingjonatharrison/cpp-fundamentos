//Dados dos numeros
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int a, b, suma, multiplicacion;

    //DE
    printf("\nIntroduzca el primer numero (Entero):");
    scanf("%d",&a);
	printf("\nIntroduzca el segundo numero (Entero):");
    scanf("%d",&b);
    
    //Procerso y DS
	if(suma>multiplicacion)
    	printf("\nLa suma es mayor.");
    else
    	/* Inicio del anidamiento */
    	if(multiplicacion>suma)
    		printf("La multiplicacion es mayor.");
    	else
    		printf("La suma y multiplicacion es mayor.");
		/* Fin del anidamiento */
	
	printf("\n");
	system("pause");
    return 0;
}//fin del main