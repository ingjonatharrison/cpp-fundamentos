// Ejercicio 1: Conversion de tiempo (horas, minutos, segundos -> segundos totales)
#include <iostream>
using namespace std;

int leerNoNegativo(const char* mensaje)
{
    int valor;
    cout << mensaje;
    while (!(cin >> valor) || valor < 0)
    {
        cout << "Dato invalido. Ingresa un entero mayor o igual a 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return valor;
}

int main()
{
    cout << "=== CONVERSION DE TIEMPO A SEGUNDOS ===\n";

    // Entrada
    int horas = leerNoNegativo("Horas: ");
    int minutos = leerNoNegativo("Minutos: ");
    int segundos = leerNoNegativo("Segundos: ");

    // Procesamiento
    long long totalSegundos = (long long)horas * 3600 + minutos * 60 + segundos;

    // Salida
    cout << "\nDatos capturados:\n";
    cout << "  Horas:    " << horas << "\n";
    cout << "  Minutos:  " << minutos << "\n";
    cout << "  Segundos: " << segundos << "\n";
    cout << "\nTiempo total: " << totalSegundos << " segundos\n";

    return 0;
}
