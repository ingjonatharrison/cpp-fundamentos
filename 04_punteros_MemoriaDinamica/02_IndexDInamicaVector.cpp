/*
    PROGRAMA 2: Memoria dinámica con un vector (arreglo) de tipo entero
    Funciones: crear, llenar (manual/aleatorio), mostrar, buscar, eliminar, liberar
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Reserva memoria dinámica para "tam" enteros
int* crear(int tam) {
    return new int[tam];
}

// Llena el vector con valores ingresados por el usuario
void llenarManual(int* arr, int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }
}

// Llena el vector con valores aleatorios
void llenarAleatorio(int* arr, int tam) {
    for (int i = 0; i < tam; i++) arr[i] = rand() % 100;
    cout << "Vector llenado aleatoriamente.\n";
}

// Muestra el contenido del vector
void mostrar(int* arr, int tam) {
    if (tam == 0 || arr == nullptr) {
        cout << "El vector esta vacio.\n";
        return;
    }
    cout << "Vector: [ ";
    for (int i = 0; i < tam; i++) cout << arr[i] << " ";
    cout << "]\n";
}

// Busca un valor y devuelve su posicion (-1 si no existe)
int buscar(int* arr, int tam, int valor) {
    for (int i = 0; i < tam; i++)
        if (arr[i] == valor) return i;
    return -1;
}

// Elimina el elemento en la posicion "pos", reduciendo el tamaño del vector
void eliminar(int* &arr, int &tam, int pos) {
    if (pos < 0 || pos >= tam) {
        cout << "Posicion invalida.\n";
        return;
    }
    int* nuevo = new int[tam - 1];
    for (int i = 0, j = 0; i < tam; i++) {
        if (i == pos) continue;
        nuevo[j++] = arr[i];
    }
    delete[] arr;
    arr = nuevo;
    tam--;
    cout << "Elemento eliminado correctamente.\n";
}

// Libera toda la memoria del vector
void liberar(int* &arr, int &tam) {
    delete[] arr;
    arr = nullptr;
    tam = 0;
    cout << "Memoria del vector liberada.\n";
}

int main() {
    srand(time(0));
    int* vector = nullptr;
    int tam = 0;
    int opcion;

    do {
        cout << "\n===== MENU: VECTOR DINAMICO =====\n";
        cout << "1. Crear vector (indicar tamaño)\n";
        cout << "2. Llenar manualmente\n";
        cout << "3. Llenar aleatoriamente\n";
        cout << "4. Mostrar vector\n";
        cout << "5. Buscar valor\n";
        cout << "6. Eliminar elemento (por posicion)\n";
        cout << "7. Liberar vector completo\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                if (vector != nullptr) {
                    cout << "Ya existe un vector, libere el actual antes de crear otro (opcion 7).\n";
                    break;
                }
                cout << "Ingrese el tamaño del vector: ";
                cin >> tam;
                if (tam <= 0) { cout << "Tamaño invalido.\n"; tam = 0; break; }
                vector = crear(tam);
                cout << "Vector creado con " << tam << " espacios.\n";
                break;
            }
            case 2:
                if (vector == nullptr) cout << "Primero cree el vector (opcion 1).\n";
                else llenarManual(vector, tam);
                break;
            case 3:
                if (vector == nullptr) cout << "Primero cree el vector (opcion 1).\n";
                else llenarAleatorio(vector, tam);
                break;
            case 4:
                mostrar(vector, tam);
                break;
            case 5: {
                if (vector == nullptr) { cout << "Primero cree el vector (opcion 1).\n"; break; }
                int val;
                cout << "Ingrese el valor a buscar: ";
                cin >> val;
                int pos = buscar(vector, tam, val);
                if (pos != -1) cout << "Valor encontrado en la posicion: " << pos << endl;
                else cout << "Valor no encontrado.\n";
                break;
            }
            case 6: {
                if (vector == nullptr) { cout << "Primero cree el vector (opcion 1).\n"; break; }
                int pos;
                cout << "Ingrese la posicion a eliminar (0 a " << tam - 1 << "): ";
                cin >> pos;
                eliminar(vector, tam, pos);
                break;
            }
            case 7:
                liberar(vector, tam);
                break;
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 8);

    if (vector != nullptr) delete[] vector; // liberación de seguridad
    return 0;
}