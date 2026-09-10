//Sumatoria de numeros
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int n, num, acum, contador;
    //DE
    printf("\nCuantos numeros quieres sumar?");
    scanf("%d",&n);
    //Procerso
    acum=0;
    contador=1;
    do{
    	printf("\nIngrese un numero");
    	scanf("%d",&num);
    	acum=acum+num;
    	contador++;
    } while (contador<=n);
    //DS
    printf("\nLa sumatoria es: %d", acum);  
	printf("\n");
	system("pause");
    return 0;
}//fin del main