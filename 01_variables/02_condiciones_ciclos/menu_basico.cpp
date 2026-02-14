#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

using namespace std;

// Programa con menú básico usando ciclos y condiciones
int main() {
    srand(time(NULL));  // Inicializa la semilla para números aleatorios

    int opcion;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Saludar" << endl;
        cout << "2. Mostrar numero aleatorio" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Hola Jonathan, sigue aprendiendo C++!" << endl;
        }
        else if (opcion == 2) {
            cout << "Numero aleatorio: " << rand() % 100 << endl;//Genera un numero del 0 al 100
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
