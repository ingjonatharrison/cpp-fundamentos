//Multiplo
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int num;

    //DE
    printf("\nIntroduzca el numero:");
    scanf("%d",&num);

    //Procerso y DS
    if(num%2 == 0 && num%5 == 0)
        printf("\nSi, el mumero es multiplo de 5 y 2");
    else
        printf("\nNo, el mumero no es multiplo de 5 y 2");

	printf("\n");
	system("pause");
    return 0;
}//fin del main