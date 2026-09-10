#include <stdio.h>
#include <stdlib.h>

//prototipos
void mostrarMenu();
void CalcularAreaTriangulo();
void CalcularAreaTriapecio();
void CalcularAreaRectangulo();

//variable global
int opcion;/*NOTAR QUE ESTA DECLARACION ESTA ANTES DEL main
significa que esa variable es local y puede ser utilizado en cualquier 
funcion del programa*/

int main()
{
    printf( "\nJonathan Rodriguez Ibarra" );
    do
    {
        mostrarMenu();
        switch ( opcion )
        {
        case 1: CalcularAreaTriangulo(); break;
        case 2: CalcularAreaTriapecio(); break;
        case 3: CalcularAreaRectangulo(); break;
        case 4: printf( "\nfin del programa" ); break;
        default:
            break;
                printf( "\nError en la opcion\n" );
        }//fin swich
    } while ( opcion != 4 );
    printf( "\n" );
    system( "pause" );
    return 0;
}//fin main

void mostrarMenu(void)
{
    printf( "\nCALCULO DE AERAS \n" );
    printf( "\n=============================== \n\n\n" );
    printf( "\n1.-Calcular EL Area DELTriangulo" );
    printf( "\n2.-Calcular EL Area DEL Triapecio" );
    printf( "\n3.-Calcular EL Area DEL Rectangulo" );
    printf( "\n4.-SALIR" );
    printf( "\nOpcion: " );
    scanf( "%d", &opcion ); /*nota que opcion no esta declarada en esta funcion
    se trata de una variable global*/

}

void CalcularAreaTriangulo()
{
    float area, base, altura;
    printf( "\nArea del triangulo \n" );
    printf( "\nBase: " );
    scanf( "%f", &base );
    printf( "\nAltura: " );
    scanf( "%f", &altura );
    //Para conseguir un valor real se hace una conversion explicita
    area = base*altura/2;
    printf( "\nEl area del triangulo es %.2f\n", area );
}

void CalcularAreaTriapecio()
{
    float area;
    int base_mayor, base_menor, altura;
    printf( "\nAEA DEL TRAPECIO \n" );
    printf( "\nBase mayor: " );
    scanf( "%d", &base_mayor );
    printf( "\nBase menor: " );
    scanf( "%d", &base_menor );
    printf( "\nAltura del trapecio" );
    scanf( "%d", &altura );
    //Para conseguir un valor real se utiliza 2.0
    area = ( ( base_mayor*base_menor ) /2.0 )*altura;
    printf( "\nEl area del trapecio es %.2f\n", area );
}

void CalcularAreaRectangulo()
{
    float area, base, altura;
    printf( "\nAREA DE UN RECTANGULO \n" );
    printf( "\nBase: " );
    scanf( "%f", &base );
    printf( "\nAltura: " );
    scanf( "%f", &altura );
    area = ( float ) base*altura;
    printf( "\nEl area del rectangulo es %.2f\n", area );
}