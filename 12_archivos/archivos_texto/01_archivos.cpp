#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){
    fstream archivo;
    int opc;
    int ID;
    string nombre;
    string semestre;
    double promedio;
    string Tel;

    do{
        cout << "====== Menu =====" << endl;
        cout << "1. Crear archivo (nuevo)" << endl;
        cout << "2. Llenar archivo" << endl;
        cout << "3. Mostrar archivo" << endl;
        cout << "4. Salir del programa" << endl;
        cin >> opc;
        
        switch(opc){
            case 1:                    
                archivo.open("alumnos.txt", ios::out); // sobrescribe archivo
                if (!archivo) { 
                    cerr << "No se pudo crear el archivo de alumnos" << endl;
                    return 1; 
                } else {
                    cout << "Archivo creado correctamente\n";
                }
                archivo.close();
            break;

            case 2:
                archivo.open("alumnos.txt", ios::out | ios::app); // agrega al final
                cout << "ID: ";
                cin >> ID;
                cout << "Nombre: ";
                cin >> nombre;
                cout << "Semestre: ";
                cin >> semestre;
                cout << "Promedio: ";
                cin >> promedio;
                cout << "Telefono Cel: ";
                cin >> Tel;
                archivo << ID << " " << nombre << " " << semestre << " " << promedio << " " << Tel << endl;
                archivo.close();
                cout << "Listo!!\n";
            break;

            case 3:
                archivo.open("alumnos.txt", ios::in);
                if (!archivo) {
                    cout << "Primero crea el archivo" << endl;
                } else {
                    cout << "\n=== Contenido del archivo ===\n";
                    while (archivo >> ID >> nombre >> semestre >> promedio >> Tel){
                        cout << "ID: " << ID 
                             << " | Nombre: " << nombre 
                             << " | Semestre: " << semestre 
                             << " | Promedio: " << promedio 
                             << " | Telefono: " << Tel << endl;
                    }
                }
                archivo.close();
            break;

            case 4: cout << "Gracias por usar el programa!" << endl; break;

            default: cerr << "Opcion invalida\n";
        }
    } while(opc != 4);

    return 0;
}
