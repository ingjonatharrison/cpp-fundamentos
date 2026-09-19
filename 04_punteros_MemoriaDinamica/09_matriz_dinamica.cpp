// Ejercicio 4: Matriz dinamica y suma por filas
#include <iostream>
using namespace std;

int leerPositivo(const char* mensaje)
{
    int valor;
    cout << mensaje;
    while (!(cin >> valor) || valor <= 0)
    {
        cout << "Dato invalido. Ingresa un entero mayor a 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return valor;
}

int main()
{
    cout << "=== MATRIZ DINAMICA Y SUMA POR FILAS ===\n";

    int filas = leerPositivo("Numero de filas: ");
    int columnas = leerPositivo("Numero de columnas: ");

    // Construccion de la matriz
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = new int[columnas];
    }

    // Captura
    cout << "\nCaptura de elementos:\n";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Elemento [" << i << "][" << j << "]: ";
            while (!(cin >> matriz[i][j]))
            {
                cout << "Dato invalido. Ingresa un entero: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }

    // Mostrar matriz
    cout << "\nMatriz capturada:\n";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }

    // Suma por filas
    cout << "\nSuma de cada fila:\n";
    for (int i = 0; i < filas; i++)
    {
        int sumaFila = 0;
        for (int j = 0; j < columnas; j++)
        {
            sumaFila += matriz[i][j];
        }
        cout << "  Fila " << i << ": " << sumaFila << "\n";
    }

    // Liberacion: primero cada fila, despues el arreglo de apuntadores
    for (int i = 0; i < filas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
    matriz = nullptr;

    cout << "\nMemoria liberada correctamente.\n";
    return 0;
}
