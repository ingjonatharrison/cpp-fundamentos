#include <stdio.h>
#include <stdlib.h>
#define REN 8
#define COL 25

//prototipos
void avanza();
void retrocede();

//variables globales
int i = 0;
char canciones[ REN ][ COL ] = { "imagine","yesterday","Roar","Help!","dreams","fireloork","stay","lover" };

int main()
{
    int op;
    do
    {
        printf( "\n1.-AVANZA" );
        printf( "\n2.-RETROCEDE" );
        printf( "\n3.-SALIR" );
        printf( "\nOpcion: " );
        scanf( "%d", &op );
        switch ( op )
        {
        case 1: avanza(); break;
        case 2: retrocede(); break;
        case 3: printf( "\nadios" ); break;
        default:
            break;
                printf( "\nError en la opcion(entre 1 y 3)\n" );
        }//fin swich
    } while ( op != 3);
    printf( "\n" );
    system( "pause" );
    return 0;
}//fin main

void avanza()
{
    if ( i == 7 )
    {
        i = 0;
    }
    else
    {
        i++;
    }
    printf( "\n Tocando %s ", canciones[ i ] );
}

void retrocede()
{
    if ( i == 0 )
    {
        i = 7;
    }
    else
    {
        i--;
    }
    printf( "\n Tocando %s ", canciones[ i ] );
}