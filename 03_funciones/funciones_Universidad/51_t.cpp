//Tabla de multiplicar
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int tabla, res, cont;

    //DE
    printf("\nQue tabla deseas ver?");
    scanf("%d",&tabla);

    //Procerso y DS
    cont=1;
    do{
        res=tabla*cont;
        printf("\n%d X %d = %d", tabla, cont, res);
        cont++;
    } while (cont<=10);
        
	printf("\n");
	system("pause");
    return 0;
}//fin del main
