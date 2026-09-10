#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAM 8

char nom[ TAM ][ 20 ] = { "Luis", "Ana", "Juan", "Pedro", "Mario", "Angel", "Fernando", "Maria" };
int pistola[ TAM ];

void llenar();
void jugar();

int main(){
    printf( "\nJonathan Rodriguez Ibarra\n" );
    printf( "\nRULETA RUSA\n" );
    for( int i = 0; i <= TAM-1; i++ ){
        printf( "\n%s", nom[ i ] );
    }
    srand( time( 0 ) );
    llenar();
    jugar();
    return 0;
}

void llenar(){
    for( int i = 0; i < TAM; i++ ) 
        pistola[ i ] = 0;
    pistola[ rand() % TAM ] = 1; 
}

void jugar(){
    int turno = rand() % TAM; // JUGADOR INICIAL
    int muerto = -1;          // Guardará quién muere
    printf("\n\nJugador inicial: %s\n", nom[ turno ]);
    while( 1 )
    {
        printf( "\nDispara %s", nom[ turno ] );
        getchar();
        if( pistola[ turno ] == 1 )
        {
            Beep(440, 800); 
            Beep(900, 800); 
            Beep(440, 800);
            printf( "\nBAM!!!! %s perdio\n", nom[ turno ] );
            muerto = turno;   // Se guarda quién murió
            break;
        }
        else printf( "\nClic...\n" );
        turno++;
        if( turno >= TAM ) turno = 0;
    }
    printf("\nMurio: %s\n", nom[ muerto ]);
    printf("\nSobrevivieron:\n");
    for( int i = 0; i < TAM; i++ ){
        if( i != muerto )
            printf("- %s\n", nom[ i ] );
    }
    printf("\nPosicion de la bala");
    printf("\n[ ");
    for (int i = 0; i < TAM; i++){
        printf("%d ", pistola[i]);
    }
    printf("]\n");
}