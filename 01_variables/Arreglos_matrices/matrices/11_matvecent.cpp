#include <stdio.h>
#define REN 6
#define COL 3

int main(){
    printf("\nJonathan Rodriguez Ibarra");    
    //declaracion de variables globales
    char estudiante[REN][30]; //Matriz para nombre
    int edad[REN];            //Edades de cada estudiante
    float calif[REN][COL];    //3 calificaciones por estudiante    
    //Llenar nombres y edades
    for (int i=0; i<REN; i++){
        printf("\nDame el nombre del estudiante %d: ", i+1);
        fflush(stdin);
        gets(estudiante[i]);
        printf("Dame la edad del estudiante %d: ", i+1);
        scanf("%d", &edad[i]);        
    }
    //Llenar calificaciones
    for (int i=0; i<REN; i++){
        printf("\nNombre: %s", estudiante[i]);
        for (int j=0; j<COL; j++){
            printf("\nDame calificacion %d: ", j+1);
            scanf("%f", &calif[i][j]);    
        }
    }
    //Imprimiendo datos
    float acum;
    printf("\nDatos de estudiantes....\n");
    for (int i=0; i<=80; i++){
        printf("%c", 219); //codigo ASCII 219 = bloque sólido  
    }
    for (int i=0; i<REN; i++){
        printf("\n%-15s %-4d anios calificaciones: ", estudiante[i], edad[i]);     
        acum = 0;
        for (int j=0; j<COL; j++){
            printf("%.2f ", calif[i][j]);
            acum += calif[i][j];
        }
        printf(" Promedio: %.2f", acum / COL);
    }
    return 0;
}
