#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int diaAUX, mesAUX, anioAUX, semitaroot, AuxTarot, edad, aux, dia, mes, anio, auxdias;
char MesesC[12][15] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

void capturaFecha();
void imprimirFormatoLargo();
void imprimirEdad();
void imprimirNumeroTarot();

int main(){
	printf( "\nJonathan Rodriguez Ibarra\n" );
    char r;
    do{
        fflush(stdin);
        capturaFecha();
        imprimirFormatoLargo();
        imprimirEdad();
        imprimirNumeroTarot();
        printf("\nUsar de nuevo? (s/n) ");
        fflush(stdin);
        scanf("%c", &r);
    }while(r == 's');
    return 0;
}

void capturaFecha(){
    time_t t = time(NULL);
    struct tm fecha = *localtime(&t);
    diaAUX  = fecha.tm_mday;
    mesAUX  = fecha.tm_mon + 1;
    anioAUX = fecha.tm_year + 1900;
    printf("\nDatos de tu fecha de nacimiento\n");
    do{
        printf("\nIngresa el anio de nacimiento: ");
        scanf("%d", &anio);
        if (anio > anioAUX)
            printf("\nTe pasasteeeeee\n");
    } while (anio > anioAUX);
    if (anio % 400 == 0) aux = 1;
    else if (anio % 100 == 0) aux = 0;
    else if (anio % 4 == 0) aux = 1;
    else aux = 0;
    do{
        printf("\nIngresa el numero del mes: ");
        scanf("%d", &mes);
        if (mes < 1 || mes > 12) printf("\nEse no es un mes valido (Entre 1 y 12).");
    } while (mes < 1 || mes > 12);
    switch (mes){
        case 2:
            auxdias = (aux == 1 ? 29 : 28);
            break;
        case 4: case 6: case 9: case 11:
            auxdias = 30;
            break;
        default:
            auxdias = 31;
    }
    do{
        printf("\nIngresa el dia: ");
        scanf("%d", &dia);
        if (dia < 1 || dia > auxdias) printf("\nEste mes tiene %d dias, vuelve a ingresar el dia.\n", auxdias);
    } while (dia < 1 || dia > auxdias);
    edad = anioAUX - anio;
}

void imprimirFormatoLargo(){
    printf("\n\nImprimiendo la fecha\n\n%d de %s de %d", dia, MesesC[mes - 1], anio);
}

void imprimirEdad(){
    printf("\n\nCalculando la edad...\n");  
    if (mesAUX < mes || (mesAUX == mes && dia > diaAUX)) edad--;
    Sleep(1500);
    printf("\nEdad actual: %d", edad);
}

void imprimirNumeroTarot(){
    printf("\n\nCalculando el Tarot...\n");
    semitaroot = dia + mes + anio;
    while (semitaroot > 9){
        AuxTarot = 0;
        while (semitaroot > 0){
            AuxTarot += semitaroot % 10;
            semitaroot /= 10;
        }
        semitaroot = AuxTarot;
    }
    Sleep(1500);
    printf("\nEl tarot es: %d\n", semitaroot);
}