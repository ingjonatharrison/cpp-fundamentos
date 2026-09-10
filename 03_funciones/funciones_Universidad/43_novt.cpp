#include<stdio.h>
#include<stdlib.h>
/*Imprimir una serie, si n=6 se ve
lo siguiente 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6*/
int main(){ 
	printf("\nJonathan Rodriguez Ibarra\n");
	int n, k, j;
	char resp='s';
	while(resp == 's'){//forzamos que entre la primera ves
		printf("\nHasta que numero quieres la serie: ");
		scanf("%d", &n);
		for(k=1; k<=n; k++){
			for(j=1; j<=k; j++){
				printf("%d, ",k);
			}//fin for j
		printf("\n");
		}//fin for k
		printf("\n");
		printf("\nDeseas repetir el programa s/n: ");
		fflush(stdin);
		scanf("%c", &resp);
	}//fin while
	printf("\n");
	system("pause");
	return 0;	
}//fin main