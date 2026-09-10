#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    int filas, columnas;

    cout << "Numero de filas: ";
    cin >> filas;

    cout << "Numero de columnas: ";
    cin >> columnas;

    // Crear matriz dinámica
    int **matriz;

    matriz = (int**)calloc(filas, sizeof(int*));

    for(int i = 0; i < filas; i++) {
        matriz[i] = (int*)calloc(columnas, sizeof(int));
    }

    // Capturar datos
    cout << "\nIngresa los valores de la matriz:\n";

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {

            cout << "[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];

        }
    }

    // Mostrar matriz
    cout << "\nMatriz capturada:\n\n";

    for(int i = 0; i < filas; i++) {

        for(int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }

        cout << endl;
    }

    // Liberar memoria
    for(int i = 0; i < filas; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}