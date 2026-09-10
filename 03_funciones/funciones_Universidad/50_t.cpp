//Programa que recibe un numero
//Imprime su tabla de multiplicar
#include<stdio.h>
#include<stdlib.h>
int main(){ 
	printf("Jonathan Rodriguez Ibarra");
	int num, tabla;
	printf("\nEscriba un numero: ");
	scanf("%d",&num);
	for(tabla=1; tabla<=10; tabla++){
		printf("%d x %d = %d\n", num, tabla, num*tabla);
	}
	printf("\n");
	system("pause");
	return 0;
}//fin main