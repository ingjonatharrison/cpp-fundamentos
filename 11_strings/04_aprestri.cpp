#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void UsoString();

int main()
{
    printf("\nJonathan Rodriguez Ibarra");
    UsoString();
    printf("\n");
    system("pause");
    return 0;
}

void UsoString()
{
    /*inicializa cadenas, los corchetes quedan vacíos
    porque toman el valor del tamaño de la cadena.*/
    char origen[] = "Hola mundo";
    char destino[50];
    char palabra1[30] = "uva";
    char palabra2[30] = "uva";
    char palabra3[] = "manzana";

    // strcpy
    printf("\nstrcpy\n");
    strcpy(destino, origen);
    printf("Cadena original: %s\n", origen);
    printf("Cadena copiada: %s\n\n", destino);

    // strlen
    printf("\nstrlen\n");
    int longitud = strlen(origen);
    printf("longitud de '%s' = %d caracteres \n\n", origen, longitud);

    // recorrer caracter por caracter
    printf("\nRecorrido de la cadena\n");
    for (int i = 0; i < longitud; i++)
    {
        printf("caracter %d: %c \n", i, origen[i]);
    }
    printf("\n");

    // strcmp
    printf("strcmp\n");
    printf("Escribe la primera palabra: ");
    scanf("%29s", palabra1);
    printf("Escribe la segunda palabra: ");
    scanf("%29s", palabra2);

    int resultado = strcmp(palabra1, palabra2);

    printf("\nResultado de strcmp(\"%s\",\"%s\") = %d\n", palabra1, palabra2, resultado);

    if (resultado == 0)
    {
        printf("Las cadenas son IGUALES\n");
    }
    else if (resultado < 0)
    {
        printf("NO SON IGUALES '%s' es MENOR alfabeticamente que '%s'\n", palabra1, palabra2);
    }
    else
    {
        printf("NO SON IGUALES '%s' es MAYOR alfabeticamente que '%s'\n", palabra1, palabra2);
    }
}
