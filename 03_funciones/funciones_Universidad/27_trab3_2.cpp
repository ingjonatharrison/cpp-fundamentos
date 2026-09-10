//la suma de dos numeros
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int a, b;

    //DE
    printf("\nIntroduzca el primer numero (Entero):");
    scanf("%d",&a);
    printf("\nIntroduzca el segundo numero (Entero):");
    scanf("%d",&b);
    
    //Procerso y DS
    if(a+b>0)
    	printf("\nLa suma SI es mayor a cero.");
    else{
    	printf("\nLa suma NO es mayor a cero.");
    }
    
	printf("\n");
	system("pause");
    return 0;
}//fin del main