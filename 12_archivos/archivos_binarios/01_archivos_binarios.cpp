#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Carreras{
    int ID;
    int duracionS;
    int numDMaestros;
    char nombreDCarrera[30];
    char Departamento[30];
};

int main(){
    fstream ARCH_BIN;
    int op;
    Carreras al;

    do{
        cout << "\n================================"
		<< "\n\tMENU"
		<< "\n================================"
		<< "\n1.- Crear cascaron"
		<< "\n2.- Agregar"
		<< "\n3.- Mostrar una carrera"
		<< "\n4.- Buscar"
		<< "\n0.- Salir"
		<< "\nOpcion: "; cin >> op;

        switch(op){

        case 1:{
            ARCH_BIN.open("ARCHIV.dat", ios::binary | ios::out | ios::trunc);

            if(!ARCH_BIN){ cout << "Error al crear el archivo.\n"; break; }

            Carreras WHITE = {0,0,0,"",""};

            for(int i = 0; i < 20; i++){ ARCH_BIN.write(reinterpret_cast<char*>(&WHITE), sizeof(Carreras)); }

            ARCH_BIN.close();
            cout << "\nCascaron creado correctamente.\n";
            break;
        }

        case 2:{
            ARCH_BIN.open("ARCHIV.dat", ios::binary | ios::in | ios::out);

            if(!ARCH_BIN){ cout << "Primero crea el cascaron.\n"; break; }

            cout << "\nIngresa el ID (1-20, 0 para salir): "; cin >> al.ID;

            while(al.ID > 0 && al.ID <= 20){

                cin.ignore();
                cout << "Nombre de la carrera: "; cin.getline(al.nombreDCarrera, 30);
                cout << "Duracion total de semestres: "; cin >> al.duracionS;
                cin.ignore();
                cout << "Departamento al que pertenece: "; cin.getline(al.Departamento, 30);
                cout << "Numero de maestros: "; cin >> al.numDMaestros;

                ARCH_BIN.seekp((al.ID - 1) * sizeof(Carreras), ios::beg);
                ARCH_BIN.write(reinterpret_cast<char*>(&al), sizeof(Carreras));

                cout << "\nDatos grabados correctamente."
				<< "\nIngresa otro ID (1-20, 0 para salir): "; cin >> al.ID;
            }

            ARCH_BIN.close();
            break;
        }

        case 3:{
            ARCH_BIN.open("ARCHIV.dat", ios::binary | ios::in);

            if(!ARCH_BIN){ cout << "No existe el archivo.\n"; break; }

            int id;
            cout << "Dame el ID de la carrera: "; cin >> id;

            if(id < 1 || id > 20){
                cout << "ID fuera de rango.\n";
                ARCH_BIN.close();
                break;
            }

            ARCH_BIN.seekg((id - 1) * sizeof(Carreras), ios::beg);
            ARCH_BIN.read(reinterpret_cast<char*>(&al), sizeof(Carreras));

            if(al.ID != 0){
                cout << "\n===== DATOS DE LA CARRERA ====="
				<< "\nID: " << al.ID
				<< "\nNombre: " << al.nombreDCarrera
				<< "\nSemestres: " << al.duracionS
				<< "\nDepartamento: " << al.Departamento
				<< "\nNumero de maestros: " << al.numDMaestros
				<< endl;
            } else {
                cout << "\nNo existe una carrera con ese ID.\n";
            }
            ARCH_BIN.close();
            break;
        }

        case 4:{
			ARCH_BIN.open("ARCHIV.dat", ios::binary | ios::in);
			if(!ARCH_BIN){ cout << "No existe el archivo.\n"; break;}

			char nombreBuscar[30];
			bool encontrado = false;

			cin.ignore();
			cout << "Ingresa el nombre de la carrera a buscar: "; cin.getline(nombreBuscar, 30);

			while(ARCH_BIN.read(reinterpret_cast<char*>(&al), sizeof(Carreras))){
				if(strcmp(al.nombreDCarrera, nombreBuscar) == 0)
				{
					encontrado = true;
					cout << "\n===== CARRERA ENCONTRADA ====="
					<< "\nID: " << al.ID
					<< "\nNombre: " << al.nombreDCarrera
					<< "\nSemestres: " << al.duracionS<< "\nDepartamento: " << al.Departamento
					<< "\nNumero de maestros: "<< al.numDMaestros << endl;
					break;
				}
			}
			if(!encontrado) cout << "\nNo existe una carrera con ese nombre.\n";

			ARCH_BIN.close();
			break;
		}
        case 0: cout << "\nGracias por usar el programa.\n"; break;
        default: cout << "\nOpcion invalida.\n";
        }
    }while(op != 0);

    return 0;
}