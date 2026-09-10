#include<stdio.h>
#include<stdlib.h>
#include<locale.h>//Libreria para mostrar text en español
/*Permite la captura de una contraseña, tienes
tres oportunidades, la contraseña es 12345, puedes 
cambiarla...
Si te equivocas las primeras do veces el msg
es Error en la contraseña, si te equivocas la tercera vez 
el msg es oportunidades guardadas
Cuando capturas bien la contraseña el msg es Bienvendio y
La intruccion break que rompe el ciclo*/
int main(int argc, char *argv[]){ //Mostrar tildes y ñ en c agregar int argc, char *argv[]
	setlocale(LC_ALL,"");//Se selecciona la localizacion
	printf("Jonathan Rodriguez Ibarra");
	int contador=1;
	int contra;
	while(contador <= 3){
		printf("\nDame la contraseña: ");
		scanf("%d", &contra);
		if(contra == 12345){
			printf("\nBienvenido!!!");
			break;//romper while
		}else{
			if(contador == 1 || contador == 2){ //Contador esta en 1 o 2
				printf("\nError en la contraseña");
			}else{ //Es porque el contador esta en 3
				printf("\nOportunidades agotadas");
			}//fin else	
		}//fin else	
		contador++;
	}//fin while
	printf("\n");
	system("pause");
	return 0;
}//fin main