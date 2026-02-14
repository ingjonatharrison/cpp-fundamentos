#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void mostrarMenu() {//funciones que solo muestran, no reciben, no mandan
    cout << "\n--- MENU ---" << endl;
    cout << "1. Saludar" << endl;
    cout << "2. Mostrar numero aleatorio" << endl;
    cout << "3. Salir" << endl;
    cout << "Selecciona una opcion: ";
}

void saludar() {
    cout << "Hola Jonathan, sigue aprendiendo C++!" << endl;
}

void mostrarAleatorio() {
    cout << "Numero aleatorio: " << rand() % 100 << endl;
}

int main() {
    srand(time(NULL));

    int opcion;

    do {
        mostrarMenu();//se inicia la funcion
        cin >> opcion;

        if (opcion == 1) {
            saludar();
        }
        else if (opcion == 2) {
            mostrarAleatorio();
        }
        else if (opcion == 3) {
            cout << "Saliendo del programa..." << endl;
        }
        else {
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 3);

    return 0;
}
