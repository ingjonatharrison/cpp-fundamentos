// Ejercicio 3: Estadisticas de un vector dinamico
#include <iostream>
using namespace std;

int main()
{
    cout << "=== ESTADISTICAS DE UN VECTOR DINAMICO ===\n";

    int cantidad;
    cout << "Cantidad de valores a almacenar: ";
    while (!(cin >> cantidad) || cantidad <= 0)
    {
        cout << "Dato invalido. Ingresa un entero mayor a 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    double* vector = new double[cantidad];   // tamano definido en ejecucion

    // Captura
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Elemento [" << i << "]: ";
        while (!(cin >> vector[i]))
        {
            cout << "Dato invalido. Ingresa un numero real: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Calculos
    double suma = 0.0;
    double mayor = vector[0];
    double menor = vector[0];
    for (int i = 0; i < cantidad; i++)
    {
        suma += vector[i];
        if (vector[i] > mayor) mayor = vector[i];
        if (vector[i] < menor) menor = vector[i];
    }
    double promedio = suma / cantidad;

    // Resultados
    cout << "\nVector: [ ";
    for (int i = 0; i < cantidad; i++)
    {
        cout << vector[i] << (i < cantidad - 1 ? ", " : " ");
    }
    cout << "]\n";
    cout << "Suma:     " << suma << "\n";
    cout << "Promedio: " << promedio << "\n";
    cout << "Mayor:    " << mayor << "\n";
    cout << "Menor:    " << menor << "\n";

    delete[] vector;
    vector = nullptr;

    cout << "\nMemoria liberada correctamente.\n";
    return 0;
}
