#include <stdio.h>
#include <stdlib.h>//system("pause")
/* La tabla del codigo ASCII se compone de 255 caracteres,
cada caracter tiene un numero enterp (codigo) que lo representa
por el ciclo inicia desde 0 y va hasta el 255, algunos caracteres 
NO SON IMPRIMIBLES por eso no los veras en el listado, por ejemplo,
el espacio en blaco, el tabulador, el return entre otros*/
/*Te muestra los codigos y su caracter de 25 en 25*/
void codigo();
int main()
{
	printf("\nJonathan Rodriguez Ibarra");
	printf("");
	codigo();//llamada a la funcion
	return 0;
}//fin main
void codigo()
{
	int i, contador = 0;
	printf("\nTabla del codigo ASCII\n");
	for(i = 0; i < 256; i++)
	{
		printf("\n%d => %c", i, i);/*se imprime dos veces la i que es el contador del ciclo
		, la primera vez se imprime como entero y la segunda vez como caracter*/
		contador++;
		if(contador == 25)
		{
			contador = 0;//reseteamos contador
			printf("\n");
			system("pause");
		}//fin if
	}//fin for
}//fin codigo