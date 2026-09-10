//Programa que captura un numero e imprime
//La suma de sus digitos
#include<stdio.h>
#include<stdlib.h>
int main(){ 
	printf("\nJonathan Rodriguez Ibarra\n");
	int numero, suma;
	char resp;
	do{
		suma = 0; //acumulador a 0
		printf("\nEscriba un numero entero positivo: ");
		scanf("%d",&numero);
		if(numero < 10)
			suma=numero;
		else{
			while(numero>=10){
				suma = suma+numero%10;//actualiza acumulador
				numero = numero /10;
			}//fim while
			suma = suma + numero;
		}//fin else
		printf("\nLa suma de las cifras del numero %d es: %d", numero, suma);
		printf("\n\nQuieres hacer otro calculo s/n: ");
		fflush(stdin);//funcion que limpia el buffer de entrada
		resp=getchar();//otra manera de capturar un caracter
	}while(resp == 's');//fin while
	printf("\n");
	system("pause");
	return 0;
}//fin main