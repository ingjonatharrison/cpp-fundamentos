#include <windows.h>  // Beep
#include <stdio.h>

int main() {
    // frecuencia en Hz, duraci�n en milisegundos
    printf("\nVas escuchar 6 Beeps diferentes");
    Beep(440, 800);   
    Beep(500, 800);
    Beep(600, 800);
    Beep(700, 800);
    Beep(800, 800);
    Beep(900, 800);
    /*investiga sobre este tema, pero en los equipos de hoy
    en dia no se escuchan varias combinaciones de Beep*/
    return 0;
}