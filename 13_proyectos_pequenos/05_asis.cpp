#include <iostream>
#include <string>

using namespace std;

struct NombreC {
    string nombre1;
    string nombre2;
    string ApePA;
    string ApeMA;
};

struct fecha {
    int dia;
    int mes;
    int año;
};

struct Informacion {
    fecha Fe;
    NombreC NoC;
    string genero;
    string telefono;
    string correo;
};

int main() {
    Informacion persona;
    int opcion;

    do {
        cout << endl << "MENU" << endl;
        cout << "1. Ingresar tus datos personales para el juego de gotcha" << endl;
        cout << "2. Mostrar datos guardados (verifica que esten bien)" << endl;
        cout << "3. Enviar datos para la invitacion..." << endl << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer para usar getline después

        switch (opcion) {
            case 1:
                cout << endl << " Ingrese Nombres" << endl;
                cout << "Primer Nombre: "; 
                getline(cin, persona.NoC.nombre1);
                cout << "Segundo Nombre: "; 
                getline(cin, persona.NoC.nombre2);
                cout << "Apellido Paterno: "; 
                getline(cin, persona.NoC.ApePA);
                cout << "Apellido Materno: "; 
                getline(cin, persona.NoC.ApeMA);
                cout << endl << " Ingrese Fecha de Nacimiento (con solo numeros)" << endl;
                cout << "Dia: "; 
                cin >> persona.Fe.dia;
                cout << "Mes: "; 
                cin >> persona.Fe.mes;
                cout << "Año: "; 
                cin >> persona.Fe.año;
                cin.ignore();// Limpiar el buffer para usar getline después
                cout << endl << "Datos Adicionales" << endl;
                cout << "Genero: "; 
                getline(cin, persona.genero);
                cout << "Telefono: "; 
                getline(cin, persona.telefono);
                cout << "Correo: "; 
                getline(cin, persona.correo);
                cout << endl << "Datos guardados con exito!" << endl;
                break;
            case 2:
                if (persona.NoC.nombre1.empty()) { //Aqui si es verdadero "Que la variable no tenga contenido" y la condicion es falsa "que la variable tiene contenido"
                    cout << endl << "No hay datos registrados aun." << endl;
                } else {
                    cout << endl << "INFORMACION REGISTRADA" << endl;
                    cout << "Nombre: " << persona.NoC.nombre1 << " " << persona.NoC.nombre2 << " " << persona.NoC.ApePA << " " << persona.NoC.ApeMA << endl;
                    cout << "Fecha: " << persona.Fe.dia << "/" << persona.Fe.mes << "/" << persona.Fe.año << endl;
                    cout << "Genero: " << persona.genero << endl;
                    cout << "Telefono: " << persona.telefono << endl;
                    cout << "Correo: " << persona.correo << endl;
                }
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 3);

    return 0;
}