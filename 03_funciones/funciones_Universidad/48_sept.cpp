#include<stdio.h>
#include<stdlib.h>
int main(){ 
	printf("\nJonathan Rodriguez Ibarra\n");
	int categoria;
	char resp;
	float sueldo, horasextra, sueldototal, precioporhoraextra;
	do{
		printf("\nDame el sueldo: ");//Datos de entrada
		scanf("%f", &sueldo);
		printf("\nDame horas extra trabajadas: ");
		scanf("%f", &horasextra);
		do{//valida categoria
			printf("\nDame la categoria 1..4 : ");
			scanf("%d", &categoria); //2
		}while(categoria<1 || categoria>4);//fin while
		if(horasextra > 30){
			horasextra=30;//si trabajo mas de 30 solo se le pagan 30 hrs extra
		}//proceso
		switch(categoria){ //Obtiene el pago por hora de acuerdo a categoria
			case 1: precioporhoraextra=30; break;
			case 2: precioporhoraextra=38; break;
			case 3: precioporhoraextra=50; break;
			case 4: precioporhoraextra=70; break;
		}//Fin switch -- calcular el sueldo final
		sueldo = sueldo + (horasextra*precioporhoraextra);
		/*imprimir el resultado	-- usar %.2f es para que solo se impriman dos decimales*/
		printf("\n%.2f hrs extra pagadas a %.2f = %.2f ", horasextra, precioporhoraextra, horasextra*precioporhoraextra);
		printf("\nEl sueldo total es: %.2f ", sueldo);//imprime con dos decimales
		printf("\n");
		printf("\nQuieres hacer el calculo de otro sueldo s/n: ");
		fflush(stdin);//limpia el buffer de entrada antes de la captura ç
		resp = getchar();
	}while(resp == 's');//fin de while
	printf("\n");
	system("pause");
	return 0;	
}//fin main