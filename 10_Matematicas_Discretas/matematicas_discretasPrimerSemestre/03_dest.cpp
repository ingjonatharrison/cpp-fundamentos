#include<stdio.h>
#include<stdlib.h>
/*Imprimir factorial de un numero
5! 1*2*3*4*5 = 120 */
int main(){ 
	printf("\nJonathan Rodriguez Ibarra\n");
	int n, fact, k;
	char resp='s';
	while(resp == 's'){//forzamos que entre la primera ves
		printf("\nDame un numero: ");
		scanf("%d", &n);
		fact=1;
		printf("\n%d! = ",n);
		for(k=1; k<=n; k++){
			printf("%d", k);
			if(k==n){
				printf("= ");
			}else{
				printf("x");
			}
			fact=fact*k;
		}//fin for k
		printf("%d", fact); //saliendo del ciclo imprimimos acumulador
		printf("\n");
		printf("\nDeseas repetir el programa s/n: ");
		fflush(stdin);
		scanf("%c", &resp);
	}//fin while
	printf("\n");
	system("pause");
	return 0;	
}//fin main