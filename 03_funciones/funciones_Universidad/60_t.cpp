//convierte numeros decimales a romanos del rango de 1 a 3999
#include <stdio.h>
//prototipo
void romano();
int main()
{
	printf("\nJonathan Rodriguez Ibarra");
	printf("");
	romano();//llamada a la funcion
	return 0;
}//fin main
void romano()
{
	int n, a, b, c, d, op= 1;
	while(op == 1)
	{
		printf("\nPROGRAMA QUE CONVIERTE NUMEROS DECIMALES A ROMANOS \n\n Proporciona el numero a convertir: \n");
		scanf("%d", &n);
		if(n >= 1 && n<3999)
		{
			printf("Equivalente: ");
			d = n % 10;
			n = n / 10;
			c = n % 10;
			n = n / 10;
			b = n % 10;
			a = n / 10;
			switch (a)
			{
				case 1: printf("M"); break;
				case 2: printf("MM"); break;
				case 3: printf("MMM"); break;
				default: break;
			}//fin switch
			switch (b)
			{
				case 1: printf("C"); break;
				case 2: printf("CC"); break;
				case 3: printf("CCC"); break;
				case 4: printf("CD"); break;
				case 5: printf("D"); break;
				case 6: printf("DC"); break;
				case 7: printf("DCC"); break;
				case 8: printf("DCCC"); break;
				case 9: printf("CM"); break;
				default: break;
			}//fin switch
			switch (c)
			{
				case 1: printf("X"); break;
				case 2: printf("XX"); break;
				case 3: printf("XXX"); break;
				case 4: printf("XL"); break;
				case 5: printf("L"); break;
				case 6: printf("LX"); break;
				case 7: printf("LXX"); break;
				case 8: printf("LXXX"); break;
				case 9: printf("XC"); break;
				default: break;
			}//fin switch
			switch (d)
			{
				case 1: printf("I"); break;
				case 2: printf("II"); break;
				case 3: printf("III"); break;
				case 4: printf("IV"); break;
				case 5: printf("V"); break;
				case 6: printf("V"); break;
				case 7: printf("VII"); break;
				case 8: printf("VIII"); break;
				case 9: printf("IX"); break;
				default: break;
			}//fin switch
		}//fin parte verdadera del if
		else
		{
			printf("\nError en el numero ...... ");
		}
		printf("\n");
		printf("\nDeseas repetir el programa si(1) no (2)");
		scanf("%d", &op);
	}//fin while
}//fin funcion cajero