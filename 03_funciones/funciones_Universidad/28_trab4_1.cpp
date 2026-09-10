//Dados tres numeros
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int n1, n2, n3;

    //DE
    printf("\nIntroduzca el primer numero (Entero):");
    scanf("%d",&n1);
    printf("\nIntroduzca el segundo numero (Entero):");
    scanf("%d",&n2);
	printf("\nIntroduzca el tercer numero (Entero):");
    scanf("%d",&n3);
    
    
    //Procerso y DS
    if(n2<n3 && n2>n1)
    	printf("\n%d SI es MENOR que %d y MAYOR que %d.", n2, n3, n1);
    else{
    	printf("\n%d NO es MENOR que %d y MAYOR que %d.", n2, n3, n1);
    }
    
	printf("\n");
	system("pause");
    return 0;
}//fin del main