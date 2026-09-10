#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int opc, intentos, a, b, res, correcto, calif, i;
char seguir, nombre[ 30 ];

void modoRepaso();
void modoExamen();

int main(){
    printf( "\nJonathan Rodriguez Ibarra\n" );
    srand( time( 0 ) );
    do{
        printf( "\nMENU\n1) Modo Repaso\n2) Modo Examen\n3) Salir\n" );
        scanf( "%d", &opc );
        switch( opc ){
            case 1: modoRepaso(); break;
            case 2: modoExamen(); break;
        }
    }while(opc!=3);
    return 0;
}

void modoRepaso(){
    do{
        a = 1 + rand()%10;
        b = 1 + rand()%10;
        correcto = a*b;
        intentos = 1;
        while( intentos <= 3 ){
            printf( "\nCuanto es %d x %d ? ", a, b );
            scanf( "%d", &res );
            if( res==correcto ){
				//sonido
				Beep(440, 800); Beep(900, 800);
                printf("\nCORRECTO!\a\n");
                break;
            }else{
				//sonido
				Beep(800, 800); Beep(500, 800);
                printf("\nINCORRECTO!\a\n");
            }
            intentos++;
        }
        if( intentos > 3 ){
            printf( "\nLa respuesta es %d\n", correcto );
            printf( "%d x %d = ",a ,b );
            for( i = 0; i < b; i++ ){
                printf( "%d", a );
                if( i < b-1 ) printf( "+" );
            }
            printf( " = %d\n", correcto );
        }
        printf( "\n¿Desea seguir repasando? (s/n) " );
        scanf( " %c", &seguir );
    }while( seguir == 's' );
}

void modoExamen(){
    printf( "\nNombre del niño: " );
    scanf( "%s", nombre );
    calif = 0;
    for(  i = 1; i <= 6; i++ ){
        a= 1+rand()%10;
        b= 1+rand()%10;
        printf( "\n(%d) Cuanto es %d x %d ? ", i, a, b );
        scanf( "%d", &res );
        if( res == a*b ){
            printf( "Correcto!\n" );
            calif+=1;
        }else{
            printf( "Incorrecto\n" );
        }
    }
    printf( "\nCALIFICACION = %d\n", calif );
    if( calif >= 4 ){
		Beep(900, 800); Beep(440, 800); Beep(900, 800);
        printf( "\nMUY BIEN %s, FELICIDADES!\n", nombre );
    }else{
		Beep(440, 800); Beep(900, 800); Beep(440, 800);
        printf( "\nANIMO %s, SIGUE PRACTICANDO!\n", nombre );
    }
}