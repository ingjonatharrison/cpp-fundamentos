#include <iostream>
#include <string>
using namespace std;

struct TFecha {
	int dd, mm, aa;
};

struct TAlumno {
	TFecha Fingreso;
    string Nombre;
    float c1, c2, c3, promedio;
};

void llena(TAlumno ISC2B[50], int n);
void muestra(TAlumno ISC2B[50], int n);
int buscar(TAlumno ISC2B[50], int n);

int main() {
	
	/*
	TAlumno al532;
	al532.Fingreso.dd=23;
	al532.Fingreso.mm=6;
	al532.Fingreso.aa=2025;
	*/
	
    int op, n = 0, pos;
    TAlumno ISC2B[50];

    do {
        cout << "\n------------------------ Menu --------------------------\n";
        cout << "1.- Llenar datos de alumno\n";
        cout << "2.- Mostrar datos de alumno\n";
        cout << "3.- Buscar alumno por nombre\n";
        cout << "4.- Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                llena(ISC2B, n);
                n++;
                break;

            case 2:
                muestra(ISC2B, n);
                break;

            case 3:
                pos = buscar(ISC2B, n);
                if (pos == -1) {
                    cout << "\nAlumno no encontrado\n";
                } else {
                    cout << "\nAlumno encontrado en la posicion: " << pos << endl;
                }
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

void llena(TAlumno ISC2B[50], int n) {
    cout << "Nombre del alumno: ";
    cin >> ISC2B[n].Nombre;

    cout << "Primer calificacion: ";
    cin >> ISC2B[n].c1;

    cout << "Segunda calificacion: ";
    cin >> ISC2B[n].c2;

    cout << "Tercer calificacion: ";
    cin >> ISC2B[n].c3;
    
    cout << "Fecha de ingreso por dia (formato dd): ";
    cin >> ISC2B[n].Fingreso.dd;
    
    cout << "Fecha de ingreso por mes (formato mm): ";
    cin >> ISC2B[n].Fingreso.mm;
    
    cout << "Fecha de ingreso por año: (formato aa): ";
    cin >> ISC2B[n].Fingreso.aa;

    ISC2B[n].promedio = (ISC2B[n].c1 + ISC2B[n].c2 + ISC2B[n].c3) / 3;
}

void muestra(TAlumno ISC2B[50], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--------------------------------------------------\n";
        cout << "Nombre del alumno: " << ISC2B[i].Nombre << endl;
        cout << "Primer calificacion: " << ISC2B[i].c1 << endl;
        cout << "Segunda calificacion: " << ISC2B[i].c2 << endl;
        cout << "Tercer calificacion: " << ISC2B[i].c3 << endl;
        cout << "Promedio: " << ISC2B[i].promedio << endl;
        cout << "Fecha de ingreso (formato dd/mm/aa): " << ISC2B[i].Fingreso.dd << "/" << ISC2B[i].Fingreso.mm << "/" << ISC2B[i].Fingreso.aa <<endl;
    }
}

int buscar(TAlumno ISC2B[50], int n) {
    string nombreBuscado;
    cout << "Ingrese nombre del alumno a buscar: ";
    cin >> nombreBuscado;
    for (int i = 0; i < n; i++) {
        if (ISC2B[i].Nombre == nombreBuscado) {
            return i;
        }
    }
    return -1;
}
