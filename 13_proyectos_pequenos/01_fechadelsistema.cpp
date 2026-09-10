#include <stdio.h>
#include <time.h>

int main() {
    int dia, mes, anio;

    /* Obtener fecha actual del sistema */
    time_t t = time(NULL);
    struct tm fecha = *localtime(&t);

    /* Guardar en variables enteras */
    dia  = fecha.tm_mday;
    mes  = fecha.tm_mon + 1;     // tm_mon va de 0 a 11, por eso se suma 1
    anio = fecha.tm_year + 1900; // tm_year cuenta desde 1900

    /* Mostrar resultados */
    printf("Dia: %d\n", dia);
    printf("Mes: %d\n", mes);
    printf("Anio: %d\n", anio);

    return 0;
}
