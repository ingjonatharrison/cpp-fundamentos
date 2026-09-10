//Sueldo
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int cont, suel_25K, n;
    float nom, suel;
    //DE
    cont=1;
    nom=0;
    suel_25K=0;
    printf("\nCuantos sueldos pagara?");
    scanf("%d",&n);
    //Procerso
    do{
    	printf("\nIngrese el sueldo del empleado %d", cont);
    	scanf("%f",&suel);
    	nom=nom+suel;
        if(suel>25000){
        	suel_25K++;
		}
        cont++;
    } while (cont<=n);
    //DS
    printf("\nLa nomina total a pagar es de: $%f \nLa cantidad de empleados con un sueldo mayor a $25,000 es: %d", nom, suel_25K);  
	printf("\n");
	system("pause");
    return 0;
}//fin del main