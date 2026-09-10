//Evaluar una funcion
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int num;
    float v, val;

    //DE
    printf("\nIntroduzca Num:");
    scanf("%d",&num);
	printf("\nIntroduzca V:");
    scanf("%f",&v); 
    //Procerso 
    if(num == 1)
        val=100*v;
    else
        if(num == 2)
            val=pow(100,v);
        else
            if(num == 3)
            val==100/v;
            else
            val=0;

    //DS
    printf("Val: %f",val);
	
	printf("\n");
	system("pause");
    return 0;
}//fin del main