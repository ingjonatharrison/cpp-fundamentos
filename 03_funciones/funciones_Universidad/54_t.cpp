//Resultado de serie n
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int n, cant, band;

    //DE
    printf("\nIntroduzca el numero:");
    scanf("%d",&n);

    //Procerso y DS
    cant=2;
    band=1;
    printf("\n");

    while (cant<=n){
        printf("%d, ",cant);
        if(band==1){
            cant=cant+3;
            band=0;
        }
        else{
            cant=cant+2;
            band=1;
        }
    }
    
	printf("\n");
	system("pause");
    return 0;
}//fin del main