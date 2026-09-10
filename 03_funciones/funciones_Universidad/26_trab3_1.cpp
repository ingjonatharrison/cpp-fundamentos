//la suma de dos numeros
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int a, b, suma;

    //DE
    printf("\nIntroduzca el primer numero (Entero):");
    scanf("%d",&a);
    printf("\nIntroduzca el segundo numero (Entero):");
    scanf("%d",&b);
    
    //Procerso
    suma=a+b;
    
    //DS
    if(suma>0)
    	printf("\nLa suma SI es mayor a cero. %d",suma);
    else{
    	printf("\nLa suma NO es mayor a cero. %d",suma);
    }
    
	printf("\n");
	system("pause");
    return 0;
}//fin del main