//Iguales o menor
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int n1, n2;

    //DE
    printf("\nIntroduzca el primer numero:");
    scanf("%d",&n1);
	printf("\nIntroduzca el segundo numero:");
    scanf("%d",&n2); 

    //Procerso y DS
    if(n1 == n2)
        printf("\nLos numeros son iguales");
    else
        if(n1>n2)
            printf("\n%d es el menor", n2);
        else
            printf("\n%d es el menor", n1);

	printf("\n");
	system("pause");
    return 0;
}//fin del main