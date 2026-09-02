/*
    PROGRAMA 4: Estructuras dinámicas (Lista enlazada simple)
    Funciones: crear, llenar (manual/aleatorio), mostrar, buscar, eliminar, liberar
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Definicion de la estructura dinamica (nodo de la lista)
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Crea la lista vacia (un puntero nulo, sin nodos)
Nodo* crear() {
    return nullptr;
}

// Inserta un nuevo nodo al final de la lista (reserva memoria dinamica)
Nodo* insertarFinal(Nodo* cabeza, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;

    if (cabeza == nullptr) return nuevo;

    Nodo* temp = cabeza;
    while (temp->siguiente != nullptr)
        temp = temp->siguiente;
    temp->siguiente = nuevo;
    return cabeza;
}

// Llena la lista con "cantidad" nodos ingresados por el usuario
void llenarManual(Nodo* &cabeza, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        int val;
        cout << "Elemento " << i + 1 << ": ";
        cin >> val;
        cabeza = insertarFinal(cabeza, val);
    }
}

// Llena la lista con "cantidad" nodos de valores aleatorios
void llenarAleatorio(Nodo* &cabeza, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        int val = rand() % 100;
        cabeza = insertarFinal(cabeza, val);
    }
    cout << "Lista llenada aleatoriamente.\n";
}

// Muestra el contenido de la lista
void mostrar(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }
    Nodo* temp = cabeza;
    cout << "Lista: ";
    while (temp != nullptr) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL\n";
}

// Busca un valor dentro de la lista
bool buscar(Nodo* cabeza, int valor) {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        if (temp->dato == valor) return true;
        temp = temp->siguiente;
    }
    return false;
}

// Elimina el primer nodo que contenga el valor indicado
Nodo* eliminar(Nodo* cabeza, int valor) {
    if (cabeza == nullptr) {
        cout << "La lista esta vacia.\n";
        return nullptr;
    }
    // Caso: el valor esta en el primer nodo
    if (cabeza->dato == valor) {
        Nodo* aux = cabeza->siguiente;
        delete cabeza;
        cout << "Elemento eliminado.\n";
        return aux;
    }
    // Caso: el valor esta en medio o al final
    Nodo* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->dato != valor)
        actual = actual->siguiente;

    if (actual->siguiente != nullptr) {
        Nodo* aux = actual->siguiente;
        actual->siguiente = aux->siguiente;
        delete aux;
        cout << "Elemento eliminado.\n";
    } else {
        cout << "Valor no encontrado.\n";
    }
    return cabeza;
}

// Libera toda la memoria dinamica de la lista
void liberar(Nodo* &cabeza) {
    Nodo* temp;
    while (cabeza != nullptr) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cout << "Memoria de la lista liberada.\n";
}

int main() {
    srand(time(0));
    Nodo* lista = crear(); // lista vacia
    int opcion;

    do {
        cout << "\n===== MENU: ESTRUCTURAS DINAMICAS (Lista enlazada) =====\n";
        cout << "1. Llenar manualmente (indicar cantidad)\n";
        cout << "2. Llenar aleatoriamente (indicar cantidad)\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Buscar valor\n";
        cout << "5. Eliminar valor\n";
        cout << "6. Liberar lista completa\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int cantidad;
                cout << "¿Cuantos elementos desea agregar?: ";
                cin >> cantidad;
                if (cantidad <= 0) { cout << "Cantidad invalida.\n"; break; }
                llenarManual(lista, cantidad);
                break;
            }
            case 2: {
                int cantidad;
                cout << "¿Cuantos elementos desea agregar?: ";
                cin >> cantidad;
                if (cantidad <= 0) { cout << "Cantidad invalida.\n"; break; }
                llenarAleatorio(lista, cantidad);
                break;
            }
            case 3:
                mostrar(lista);
                break;
            case 4: {
                int val;
                cout << "Ingrese el valor a buscar: ";
                cin >> val;
                cout << (buscar(lista, val) ? "Valor encontrado.\n" : "Valor no encontrado.\n");
                break;
            }
            case 5: {
                int val;
                cout << "Ingrese el valor a eliminar: ";
                cin >> val;
                lista = eliminar(lista, val);
                break;
            }
            case 6:
                liberar(lista);
                break;
            case 7:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);

    liberar(lista); // liberación de seguridad
    return 0;
}