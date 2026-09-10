#include <stdio.h>
#include <time.h>//para manejo de aleatorios
#include <stdlib.h>//para manejo de aleatorios
/*Adivina el numero tienes 10 oportunidades
el numero a adivinar se generara de forma aleatoria
en un rango entre 100 y 900 */
//prototipo
void adivina();
int main()
{
	printf("\nJonathan Rodriguez Ibarra");
	printf("");
	srand(time(0));
	adivina();//llamada a la funcion
	return 0;
}//fin main
void adivina()
{
	int op, juego, num, contador = 1;
	char nom [30];
	printf("\nAdivina el numero, el numero generado esta ");
	printf("entre 100 y 900, tienes 10 oportunidades para adivinar\n");
	do
	{
		printf("\nComo te llamas? ");
		fflush(stdin);
		gets(nom);//es para captura cadenas
		juego = 100 + rand()%(900-100+1);//limite esta entre 100 y 900
		/*Si quieres ver a pantalla el numero aleatorio que se genera 
		quita el comentario de la linea 31 es valido minetras haces pruebas*/
		//printf("\n%d--->", juego);
		while (contador <= 10)
		{
			printf("\nAdivina el numero: ");
			scanf("%d", &num);
			if(num == juego)
			{
				printf("\nFelicitaciones %s adivinaste el numero en %d intentos", nom, contador);
				break;//rompe el while
			}
			else
			{
				if(contador == 10)
				{
				printf("\nLastima %s, no le atinaste, te acabaste tus 10 oportunidades, el numero era %d", nom, juego);
				}
				else
				{
					if(num > juego)
					{
						printf("\nEl numero es menor a %d", num);
					}
					else
					{
						printf("\nEl numero es mayor a %d", num);
					}
				}
				contador++;
			}//else
		}//fin while
		printf("\n");
		printf("\nQuieres jugar otra vez? si(1) no(2)");
		scanf("%d", &op);
	}while(op == 1);
}//fin funcion cajero