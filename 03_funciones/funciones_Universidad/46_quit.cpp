//Programa que captura un caracter y un numero
//e imprime un triangulo invertido del total de renglones
//que indique el numero, formado con el caracter
//solicitado
#include<stdio.h>
#include<stdlib.h>
int main(){ 
	printf("\nJonathan Rodriguez Ibarra\n");
	char letra;
	int numero,i;
	printf("\nEscriba una letra: ");
	scanf("%c",&letra);
	printf("\nEscriba un numero: ");
	scanf("%d",&numero);
	printf("\n");
	while(numero>0){
		for (i=0;i<numero; i++){
			printf("%c",letra);
		}
		printf("\n");
		numero--;
	}
	printf("\n");
	system("pause");
	return 0;
}//fin main