#include <stdio.h>
/* cajero automatico*/
//prototipo
void cajero();
int main()
{
	printf("\nJonathan Rodriguez Ibarra");
	printf("");
	cajero();//llamada a la funcion
	return 0;
}//fin main
void cajero()
{
	int cantidad, op;
	do
	{
		printf("\nCajero Automatico\n");
		printf("\nSolo puedes retirar cantidades entre &50 y $8000 ");
		printf("\ny la cantidad debe ser multiplo de $50 ");
		printf("\nEste cajero tiene billetes de $50, $100, $200, y $500\n");
		do
		{
			printf("\nCantidad a retirar: ");
			scanf("%d", &cantidad);
			if(!(cantidad <= 8000 && cantidad >= 50 && cantidad % 50 == 0))
			{
				printf("\nError en la cantidad a retirar \n");
			}
		}while (!(cantidad <= 8000 && cantidad >= 50 && cantidad % 50 == 0));
		printf("\nEntrega de dinero\n");
		printf("\n\Billetes de $500 ..... %d", cantidad / 500);
		printf("\nBilletes de $200 ..... %d", cantidad % 500 / 200);
		printf("\nBilletes de $100 ..... %d", cantidad % 500 %200 / 100);
		printf("\nBilletes de $50 ..... %d", cantidad % 500 % 200 % 100 / 50);
		printf("\n");
		printf("\nDeseas hacer otro retiro 1(si) 0(no) ");
		scanf("%d", &op);
	}while (op == 1);
}//fin funcion cajero