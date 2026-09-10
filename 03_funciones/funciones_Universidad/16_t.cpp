//Dia de la semana
//Jonathan Rodriguez Ibarra 
#include <stdio.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int dia;

    //DE
    printf("\nDame un numero:");
    scanf("%d",&dia);
    
    //Procerso y DS
    if(dia==1)
        printf("\nLunes");        
    else{
        if(dia==2)
            printf("\nMartes");
        else{
            if(dia==3)
                printf("\nMiercoles");
            else{
                if(dia==4)
                    printf("\nJueves");
                else{
                    if(dia==5)
                        printf("\nViernes");
                    else
                        printf("\nError el dia");
                }
            }           
        }
    }

    return 0;
}//fin del main