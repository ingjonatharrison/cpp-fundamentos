#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){
    fstream archivo;
    fstream MayoresA;

    string NombreP,Nom;
    string CodigoD;
    int Cantidad, opc;
    double Precio, Cant;

    do{
        cout << "====== Menu =====" << endl;
        cout << "1. Crear archivo (solo si es nuevo)" << endl;
        cout << "2. Agregar Producto" << endl;
        cout << "3. Mostrar productos" << endl;
        cout << "4. Borrar todo" << endl;
        cout << "5. Buscar por nombre" << endl; // Nombre del producto
        cout << "6. Buscar por cantidad de dinero" << endl; //De x dinero para arriva
        cout << "7. Salir del programa" << endl;
        cin >> opc;
        
        switch(opc){
            case 1:                    
                archivo.open("Productos.txt", ios::out);
                if (!archivo) { 
                    cerr << "No se pudo crear el archivo de productos" << endl;
                    return 1; 
                } else {
                    cout << "EL archivo ya existe \n";
                }
                archivo.close();
            break;

            case 2:
                archivo.open("Productos.txt", ios::out | ios::app);
                if (!archivo) {
                    cout << "Primero crea el archivo" << endl;
                } else {
                    cout << "Nombre del Producto: ";
                    cin >> NombreP;
                    cout << "Codigo del Producto: ";
                    cin >> CodigoD;
                    cout << "Cantidad de Producto: ";
                    cin >> Cantidad;
                    cout << "Precio del Producto: ";
                    cin >> Precio;
                    archivo << NombreP << " " << CodigoD << " " << Cantidad << " " << Precio << endl; cout << "Registrado!!\n";
                }
                archivo.close();
            break;

            case 3:
                archivo.open("Productos.txt", ios::in);
                if (!archivo) {
                    cout << "Primero crea el archivo" << endl;
                } else {
                    cout << "\n=== Contenido del archivo ===\n";
                    while (archivo >> NombreP >> CodigoD >> Cantidad >> Precio){
                        cout << "Nombre del Producto: " << NombreP 
                        << "\t | Codigo del Producto: " << CodigoD 
                        << "\t | Cantidad de Producto: " << Cantidad 
                        << "\t | Precio del Producto: $" << Precio << endl;
                    }
                }
                archivo.close();
            break;

            case 4: 
                archivo.open("Productos.txt", ios::out | ios::trunc);
                cout << "Borrando Datos del archivo!" << endl; 
                archivo.close();
                break;

            case 5: 
                archivo.open("Productos.txt", ios::in);
                if (!archivo) {
                    cout << "Primero crea el archivo" << endl;
                } else {
                    cout << "Dame el Nombre del producto a buscar" << endl; cin >> Nom;
                    while(archivo >> NombreP >> CodigoD >> Cantidad >> Precio){
                        if(NombreP == Nom){
                            cout << "=====Producto encontrado=====" << endl ;
                            cout << "Nombre del Producto: " << NombreP 
                            << "\t | Codigo del Producto: " << CodigoD 
                            << "\t | Cantidad de Producto: " << Cantidad 
                            << "\t | Precio del Producto: $" << Precio << endl;
                            archivo.close();
                            break;
                        }
                    }
                    cout << "Producto no encontrado" << endl;
                }
                archivo.close();
            break;

            case 6: 
                archivo.open("Productos.txt", ios::in);
                if (!archivo) {
                    cout << "Primero crea el archivo" << endl;
                } else {
                    MayoresA.open("ProductoMayor.txt", ios::out);
                    if (!archivo) { 
                        cerr << "No se pudo crear el archivo para productos mayores" << endl;
                        return 1; 
                    }
                    MayoresA.close();

                    cout << "Dame el dinero minimo" << endl; cin >> Cant;
                    cout << "====Productos mayores o iguales a: $" << Cant << "====" << endl;
                    while (archivo >> NombreP >> CodigoD >> Cantidad >> Precio){
                        if(Precio >= Cant){
                            cout << "Nombre del Producto: " << NombreP 
                            << "\t | Codigo del Producto: " << CodigoD 
                            << "\t | Cantidad de Producto: " << Cantidad 
                            << "\t | Precio del Producto: $" << Precio << endl;

                            //MayorA << NombreP << " " << CodigoD << " " << Cantidad << " " << Precio << endl; cout << "Registrado!!\n";
                        }
                   }
                }
                archivo.close();
            break;

            case 7: cout << "Gracias por usar el programa!" << endl; break;

            default: cerr << "Opcion invalida\n";
        }
    } while(opc != 7);

    return 0;
}
