//Area de un triangulo
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    float altura, area, base;

    //DE
    printf("\nIntroduzca la base:");
    scanf("%f",&base);
    printf("\nIntroduzca la altura:");
    scanf("%f",&altura);
    
    //Procerso
    area=base*altura/2;
    
    //DS
    printf("El area del triangulo es: %f", area);
	
	printf("\n");
	system("pause");
    return 0;
}//fin del main