#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\nJonathan Rodriguez Ibarra");
    int numero;
    printf("\nIntroduzca el numero del dado:");
    scanf("%d",&numero); 
    switch(numero){
    	case 1:
    		printf("\nEn la cara opuesta esta el \"seis\".");
    	break;
    	case 2:
    		printf("\nEn la cara opuesta esta el \"cinco\".");
    	break;
    	case 3:
    		printf("\nEn la cara opuesta esta el \"cuatro\".");
    	break;
    	case 4:
    		printf("\nEn la cara opuesta esta el \"tres\".");
    	break;
    	case 5:
    		printf("\nEn la cara opuesta esta el \"dos\".");
    	break;
    	case 6:
    		printf("\nEn la cara opuesta esta el \"uno\".");
    	break;
    	default:
    		printf("\nERROR: Numero incorrecto.");
	}	    
	printf("\n");
	system("pause");
    return 0;
}