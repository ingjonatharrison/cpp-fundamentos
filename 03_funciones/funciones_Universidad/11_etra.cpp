#include <stdio.h>

/*Imprime las letras mayusculas o minusculas */

//prototipos
void imprimeLetras();

int main()
{
    printf( "\nJonathan Rodriguez Ibarra" );
    char resp;
    do
    {
        imprimeLetras(); //llamar a la funcion
        printf( "\n\nQuieres imprimir de nuevo s/n: " );
        fflush(stdin);
        resp=getchar();//forma de leer un char
    } while ( resp == 's' );
    return 0;
}//fin main

void imprimeLetras()
{
    //usando la tabla de codigo ASCII
    //Las mayusculas van del codigo 65 al 90
    //Las minusculas van del codigo 97 al 122
    int op, ini, fin;
    printf( "\nSelecciona (1)mayusculas (2)minusculas " );
    scanf( "%d", &op );
    if ( op == 1 )
    {
        ini = 65;
        fin = 90;
    }
    else
    {
        ini = 97;
        fin = 122;
    } 
    printf( "\n" );
    for ( int i = ini; i <= fin; i++)
    {
        printf( "%c,", i );
    }
}
