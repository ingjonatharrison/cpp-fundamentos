/* Indice de masa corporal */
#include<stdio.h>//importante para que funcione el printf, scanf y getchar
#include<math.h>//importante para que funcione el pow
int main(){
	printf("Jonathan Rodriguez Ibarra");
	//DVyC
	float peso, estatura, imc;
	char resp;
	do{
		printf("\nDame tu peso en kilos: ");
		scanf("%f",&peso);
		printf("\nDame tu estatura en mts: ");
		scanf("%f",&estatura);
		imc=peso/pow(estatura,2);
		printf("\nTu indice de masa corporal = %.2f",imc);
		printf("\n");
		printf("\n|       Tabla informativa       |");
		printf("\n|Menor a 18: Peso Bajo          |");
		printf("\n|De 18 a 24.9: Peso Normal      |");
		printf("\n|De 25 a 26.9: SobrePeso        |");
		printf("\n|Mayor a 27: Obesidad           |");
		printf("\n|De 27 a 29.9: Obesidad grado I |");
		printf("\n|De 30 a 39.9: obesidad grado II|");
		printf("\n|Mayor a 40: Obesidad grado III |");
		printf("\n\n");
		printf("\nDeseas repetir la solucion s/n:");
		fflush(stdin);//libera el buffer de entrada
		resp=getchar();//Esta es otra manera de leer un tipo char
	}while (resp=='s' || resp=='S'); //Se colocan con Alt-124(Teclado numerico)
	printf("\n");
	system("pause");
	return 0;
}//fin main