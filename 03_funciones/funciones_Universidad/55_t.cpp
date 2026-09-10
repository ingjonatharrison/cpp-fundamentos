//Numeros de 3 sifras
//Jonathan Rodriguez Ibarra 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int cont, cent, dec, uni, res;

    //DE
    cont=100;

    //Procerso y DS
    printf("\n");
    while (cont<=999){
        cent=cent/100;
        dec=cont%100/10;
        uni=cont%100%10;
        res=pow(cent,3)+pow(uni,3);

        if(res==cont){
            printf("%d, ",cont);
        }
        cont++;
    }
    
	printf("\n");
	system("pause");
    return 0;
}//fin del main