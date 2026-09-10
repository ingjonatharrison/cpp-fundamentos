#include<stdio.h>
#include<stdlib.h>
int main(){ 
	printf("\nJonathan Rodriguez Ibarra\n");
	float centigrados, conv;
	char resp='s';
	while(resp == 's'){//forzamos que entre la primera ves
		printf("\nDame la temperatura en grados centigrados: ");
		scanf("%f", &centigrados);
		conv=centigrados*9/5.0+32;//formula conversa
		printf("\nLa conversion de %.2f Centigrados a farenheir es %.2f ", centigrados, conv);
		printf("\n");
		printf("\nDeseas repetir el programa s/n");
		fflush(stdin);
		scanf("%c", &resp);
	}//fin while
	printf("\n");
	system("pause");
	return 0;	
}//fin main