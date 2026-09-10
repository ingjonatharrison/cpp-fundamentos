#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void LlenarManual(int cubo[10][10][10], int f, int c, int z);
void LlenarAleatorio(int cubo[10][10][10], int f, int c, int z);
void mostrarMatriz(int cubo[10][10][10], int f, int c, int z);

int main(){
	int cubo[10][10][10]; 
    int f, c, z, opcion;	
    
    cout << "Ingrese Filas: "; cin >> f;
    cout << "Ingrese Columnas: "; cin >> c;
    cout << "Ingrese Profundidad: "; cin >> z;

    do{
        cout << "\n----------- MENU ----------" << endl;
        cout << "1.- Llenar manual" << endl;
        cout << "2.- Llenar aleatorio" << endl;
        cout << "3.- Mostrar cubo" << endl;
        cout << "4.- Salir" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        switch(opcion){
            case 1: LlenarManual(cubo, f, c, z); break;
            case 2: LlenarAleatorio(cubo, f, c, z); break;
            case 3: mostrarMatriz(cubo, f, c, z); break;
            case 4: cout << "Saliendo..." << endl; break;
            default: cout << "Invalido" << endl;
        }
    } while(opcion != 4);

    return 0;
}

void LlenarManual(int cubo[10][10][10], int f, int c, int z) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            for(int a = 0; a < z; a++){
                cout << "cubo[" << i << "][" << j << "][" << a << "]: ";
                cin >> cubo[i][j][a];
            }
        }
    }
}

void LlenarAleatorio(int cubo[10][10][10], int f, int c, int z) {
    srand(time(NULL));
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            for(int a = 0; a < z; a++){
                cubo[i][j][a] = rand() % 10;
            }
        }
    }
    cout << "Cubo rellenado con valores pequenos." << endl;
}

void mostrarMatriz(int cubo[10][10][10], int f, int c, int z) {
    
    for (int a = 0; a < z; a++) {
        cout << "\n--- PROFUNDIDAD (Z) " << a << " ---" << endl;
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) {
                cout << "[" << cubo[i][j][a] << "]" << "\t";
            }
            cout << endl;
        }
    }
}