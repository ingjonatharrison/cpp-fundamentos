//Sumatorias
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int acum, cont;

    //DE
    acum=0;
    cont=500;

    //Procerso
    printf("\n");
    do{
        if(cont%3==0){
            printf("%d, ", cont);
            acum=acum+cont;
        }
        cont++;
    } while (cont<=600);

    //DS
    printf("\nSumatoria: %d",acum);
        
	printf("\n");
	system("pause");
    return 0;
}//fin del main