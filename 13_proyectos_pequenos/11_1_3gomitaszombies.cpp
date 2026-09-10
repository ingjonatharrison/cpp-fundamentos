#include <iostream>
#include <string>
using namespace std;

// Prototipos
int menu();
void llena(string name);
void muestra();
int ayudas(int n);

int main() {
    int op, n = 0, cont;
    string name;

    do {
        // SOLUCIÓN: Llamar a la función solo una vez y asignar su valor
        op = menu(); 

        switch (op) {
            case 1:
                cout << "Cual es tu nombre? ";
                cin >> name;
                llena(name);
                break;

            case 2:
                muestra();
                break;

            case 3:
                cout << "Cuantas gomitas vas a comprar: ";
                cin >> n;
                cont = ayudas(n);
                cout << "\n------------------------ AVISO --------------------------\n";
                cout << "Ayudaste a " << cont << " Zombies (3 por cada gomita)\n";
                cout << "---------------------------------------------------------\n";
                break;

            case 4:
                cout << "Gracias!!!\n";
                break;

            default:
                cout << "\nDato invalido\n";
        }
    } while (op != 4);

    return 0;
}

int menu() {
    int op;
    cout << "\n--- Menu ---" << endl;
    cout << "1.- Guardar nombre" << endl;
    cout << "2.- Anuncio" << endl;
    cout << "3.- Cuantos Zombies ayudas" << endl;
    cout << "4.- Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> op;
    return op;
}

void llena(string name) {
    cout << "Bienvenido " << name << endl;
}

void muestra() {
    cout << "\n--- Anuncio ---" << endl;
    cout << "Los zombies dominaron al mundo con sus gomitas..." << endl;
}

int ayudas(int n) {
    // Inicializamos en 0 para evitar valores basura de la memoria
    int cont = n * 3; 
    return cont;
}