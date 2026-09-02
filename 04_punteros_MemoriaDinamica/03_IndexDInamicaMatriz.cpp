/*
    PROGRAMA 3: Memoria dinámica con una matriz de tipo entero
    Funciones: crear, llenar (manual/aleatorio), mostrar, buscar, eliminar, liberar
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Reserva memoria dinámica para una matriz de "filas" x "columnas"
int** crear(int filas, int columnas) {
    int** m = new int*[filas];
    for (int i = 0; i < filas; i++)
        m[i] = new int[columnas];
    return m;
}

// Llena la matriz con valores ingresados por el usuario
void llenarManual(int** m, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> m[i][j];
        }
    }
}

// Llena la matriz con valores aleatorios
void llenarAleatorio(int** m, int filas, int columnas) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            m[i][j] = rand() % 100;
    cout << "Matriz llenada aleatoriamente.\n";
}

// Muestra el contenido de la matriz
void mostrar(int** m, int filas, int columnas) {
    if (m == nullptr) {
        cout << "La matriz esta vacia.\n";
        return;
    }
    cout << "Matriz:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

// Busca un valor y devuelve su posicion (fila, columna) mediante referencias
bool buscar(int** m, int filas, int columnas, int valor, int &fi, int &ci) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (m[i][j] == valor) {
                fi = i; ci = j;
                return true;
            }
        }
    }
    return false;
}

// Elimina (pone en cero) el valor de una posicion especifica
void eliminarValor(int** m, int filas, int columnas, int fila, int col) {
    if (fila < 0 || fila >= filas || col < 0 || col >= columnas) {
        cout << "Posicion invalida.\n";
        return;
    }
    m[fila][col] = 0;
    cout << "Valor eliminado (puesto en 0) en [" << fila << "][" << col << "].\n";
}

// Libera toda la memoria dinámica de la matriz
void liberar(int** &m, int filas) {
    if (m == nullptr) return;
    for (int i = 0; i < filas; i++)
        delete[] m[i];
    delete[] m;
    m = nullptr;
    cout << "Memoria de la matriz liberada.\n";
}

int main() {
    srand(time(0));
    int** matriz = nullptr;
    int filas = 0, columnas = 0;
    int opcion;

    do {
        cout << "\n===== MENU: MATRIZ DINAMICA =====\n";
        cout << "1. Crear matriz (indicar filas y columnas)\n";
        cout << "2. Llenar manualmente\n";
        cout << "3. Llenar aleatoriamente\n";
        cout << "4. Mostrar matriz\n";
        cout << "5. Buscar valor\n";
        cout << "6. Eliminar valor (por posicion)\n";
        cout << "7. Liberar matriz completa\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                if (matriz != nullptr) {
                    cout << "Ya existe una matriz, liberela antes de crear otra (opcion 7).\n";
                    break;
                }
                cout << "Ingrese el numero de filas: ";
                cin >> filas;
                cout << "Ingrese el numero de columnas: ";
                cin >> columnas;
                if (filas <= 0 || columnas <= 0) {
                    cout << "Dimensiones invalidas.\n";
                    filas = columnas = 0;
                    break;
                }
                matriz = crear(filas, columnas);
                cout << "Matriz creada de " << filas << "x" << columnas << ".\n";
                break;
            }
            case 2:
                if (matriz == nullptr) cout << "Primero cree la matriz (opcion 1).\n";
                else llenarManual(matriz, filas, columnas);
                break;
            case 3:
                if (matriz == nullptr) cout << "Primero cree la matriz (opcion 1).\n";
                else llenarAleatorio(matriz, filas, columnas);
                break;
            case 4:
                mostrar(matriz, filas, columnas);
                break;
            case 5: {
                if (matriz == nullptr) { cout << "Primero cree la matriz (opcion 1).\n"; break; }
                int val, fi, ci;
                cout << "Ingrese el valor a buscar: ";
                cin >> val;
                if (buscar(matriz, filas, columnas, val, fi, ci))
                    cout << "Valor encontrado en la posicion [" << fi << "][" << ci << "]\n";
                else
                    cout << "Valor no encontrado.\n";
                break;
            }
            case 6: {
                if (matriz == nullptr) { cout << "Primero cree la matriz (opcion 1).\n"; break; }
                int fi, ci;
                cout << "Ingrese la fila: ";
                cin >> fi;
                cout << "Ingrese la columna: ";
                cin >> ci;
                eliminarValor(matriz, filas, columnas, fi, ci);
                break;
            }
            case 7:
                liberar(matriz, filas);
                break;
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 8);

    if (matriz != nullptr) { // liberación de seguridad
        for (int i = 0; i < filas; i++) delete[] matriz[i];
        delete[] matriz;
    }
    return 0;
}