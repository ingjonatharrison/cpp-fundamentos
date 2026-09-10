//Calificaciojn examen
//Jonathan Rodriguez Ibarra 
#include <stdio.h>

int main(){

    printf("\nJonathan Rodriguez Ibarra");
    //DVyC
    int calif;

    //DE
    printf("\nDame Una calificacion:");
    scanf("%d",&calif);
    
    //Procerso y DS
    if(calif<7)
        printf("\nReprobaste:");        
    else{
        if(calif>=7 && calif<=8)
            printf("\nBien");
        else{
            if(calif==9)
                printf("\nMuy bien");
            else{
                if(calif==10)
                    printf("\nExcelente");
                else
                    printf("\nError en la calificacion");
            }
        }
    }
    
    return 0;
}//fin del main