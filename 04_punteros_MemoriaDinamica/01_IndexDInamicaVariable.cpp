/*
    PROGRAMA 1: Memoria dinámica con una variable de tipo entero
    Funciones: crear, llenar (manual/aleatorio), mostrar, buscar, eliminar
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Reserva memoria dinámica para un entero
int* crear() {
    return new int;
}

// Llena la variable con un valor ingresado por el usuario
void llenarManual(int* p) {
    cout << "Ingrese el valor entero: ";
    cin >> *p;
}

// Llena la variable con un valor aleatorio
void llenarAleatorio(int* p) {
    *p = rand() % 100; // valores entre 0 y 99
    cout << "Valor generado aleatoriamente: " << *p << endl;
}

// Muestra el valor almacenado
void mostrar(int* p) {
    if (p != nullptr)
        cout << "Valor almacenado: " << *p << endl;
    else
        cout << "No hay memoria reservada." << endl;
}

// Busca si el valor almacenado coincide con el buscado
bool buscar(int* p, int valor) {
    if (p == nullptr) return false;
    return (*p == valor);
}

// Libera la memoria dinámica reservada
void eliminar(int* &p) {
    if (p != nullptr) {
        delete p;
        p = nullptr;
        cout << "Memoria liberada correctamente." << endl;
    } else {
        cout << "No hay memoria que liberar." << endl;
    }
}

int main() {
    srand(time(0));
    int* variable = nullptr;
    int opcion;

    do {
        cout << "\n===== MENU: VARIABLE DINAMICA =====\n";
        cout << "1. Crear variable (reservar memoria)\n";
        cout << "2. Llenar manualmente\n";
        cout << "3. Llenar aleatoriamente\n";
        cout << "4. Mostrar valor\n";
        cout << "5. Buscar valor\n";
        cout << "6. Eliminar (liberar memoria)\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (variable == nullptr) {
                    variable = crear();
                    cout << "Memoria reservada correctamente.\n";
                } else {
                    cout << "Ya existe una variable creada.\n";
                }
                break;
            case 2:
                if (variable == nullptr) cout << "Primero cree la variable (opcion 1).\n";
                else llenarManual(variable);
                break;
            case 3:
                if (variable == nullptr) cout << "Primero cree la variable (opcion 1).\n";
                else llenarAleatorio(variable);
                break;
            case 4:
                mostrar(variable);
                break;
            case 5: {
                if (variable == nullptr) {
                    cout << "Primero cree la variable (opcion 1).\n";
                    break;
                }
                int val;
                cout << "Ingrese el valor a buscar: ";
                cin >> val;
                cout << (buscar(variable, val) ? "Valor encontrado.\n" : "Valor no encontrado.\n");
                break;
            }
            case 6:
                eliminar(variable);
                break;
            case 7:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);

    if (variable != nullptr) delete variable; // liberación de seguridad
    return 0;
}