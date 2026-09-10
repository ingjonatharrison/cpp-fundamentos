//Distancia de dos puntos
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    float x1, x2, y1, y2, dist;

    //DE
    printf("\nIntroduzca X1:");
    scanf("%f",&x1);
	printf("\nIntroduzca X2:");
    scanf("%f",&x2);
    printf("\nIntroduzca Y1:");
    scanf("%f",&y1);
	printf("\nIntroduzca Y2:");
    scanf("%f",&y2);
    
    //Procerso 
    dist= sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    //DS
    printf("La distancia entre los 2 puntos es: %f",dist);
	
	printf("\n");
	system("pause");
    return 0;
}//fin del main