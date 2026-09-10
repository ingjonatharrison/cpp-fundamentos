#include <iostream>
#include <string.h>

using namespace std;

struct str_nombre {
    char nombre[20];
    char apellido[20];
};

struct str_entrenador {
    str_nombre nomC;
    int nivel;
    char equipo; // a = Azul , y = amarillo  , r = rojo
    char pokemons[3][20];
};

// Prototipos
void capturar(str_entrenador lista[], int tam);
void mostrar(str_entrenador entrenador);
void buscarPokemon(str_entrenador lista[], int tam);
void filtrarDatos(str_entrenador lista[], int tam);
void editarEntrenador(str_entrenador lista[], int tam); 
void intercambiarPokemon(str_entrenador lista[], int tam);

int main() {
    const int TAM = 4;
    str_entrenador lista[TAM];
    int opcion;
    bool datosCargados = false;

    do {
        cout << "\n--- SISTEMA DE GESTION POKEMON ---" << endl;
        cout << "1. Registrar todos los entrenadores" << endl;
        cout << "2. Mostrar todos los entrenadores" << endl;
        cout << "3. Buscar entrenador por nombre de Pokemon" << endl;
        cout << "4. Filtrar (por Equipo o Nivel)" << endl;
        cout << "5. Editar datos de un entrenador" << endl;
        cout << "6. Intercambiar Pokemon" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (!datosCargados && opcion > 1) {
            cout << "Error: Primero debe cargar los datos (Opcion 1)." << endl;
            continue;
        }

        switch (opcion) {
            case 1: capturar(lista, TAM); datosCargados = true; break;
            case 2: for(int i=0; i<TAM; i++) mostrar(lista[i]); break;
            case 3: buscarPokemon(lista, TAM); break;
            case 4: filtrarDatos(lista, TAM); break;
            case 5: editarEntrenador(lista, TAM); break;
            case 6: intercambiarPokemon(lista, TAM); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}

void filtrarDatos(str_entrenador lista[], int tam) {
    int subOpcion;
    cout << "\n¿Como desea filtrar?\n1. Por Equipo\n2. Por Nivel minimo\nOpcion: ";
    cin >> subOpcion;

    if (subOpcion == 1) {
        char f;
        cout << "Ingrese equipo (a/y/r): "; cin >> f;
        for (int i = 0; i < tam; i++) {
            if (lista[i].equipo == f) mostrar(lista[i]);
        }
    } else if (subOpcion == 2) {
        int nMin;
        cout << "Mostrar entrenadores con nivel mayor o igual a: "; cin >> nMin;
        for (int i = 0; i < tam; i++) {
            if (lista[i].nivel >= nMin) mostrar(lista[i]);
        }
    } else {
        cout << "Opcion no valida." << endl;
    }
}

void editarEntrenador(str_entrenador lista[], int tam) {
    int indice;
    cout << "Ingrese el numero del entrenador a editar (1-" << tam << "): ";
    cin >> indice;
    indice--; // Ajuste

    if (indice >= 0 && indice < tam) {
        cout << "--- Editando a: " << lista[indice].nomC.nombre << " ---" << endl;
        cout << "Nuevo Nombre: "; cin >> lista[indice].nomC.nombre;
        cout << "Nuevo Apellido: "; cin >> lista[indice].nomC.apellido;
        cout << "Nuevo Nivel: "; cin >> lista[indice].nivel;
        do {
            cout << "Nuevo Equipo (a/y/r): "; cin >> lista[indice].equipo;
        } while (lista[indice].equipo != 'a' && lista[indice].equipo != 'y' && lista[indice].equipo != 'r');
        
        for (int p = 0; p < 3; p++) {
            cout << "Nuevo Pokemon " << p + 1 << ": ";
            cin >> lista[indice].pokemons[p];
        }
        cout << "¡Datos actualizados correctamente!" << endl;
    } else {
        cout << "Indice fuera de rango." << endl;
    }
}

void capturar(str_entrenador lista[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "\nDatos del entrenador " << i + 1 << endl;
        cout << "Nombre: "; cin >> lista[i].nomC.nombre;
        cout << "Apellidos: "; cin >> lista[i].nomC.apellido;
        cout << "Nivel: "; cin >> lista[i].nivel;
        do {
            cout << "Equipo (a=Azul, y=Amarillo, r=Rojo): "; cin >> lista[i].equipo;
        } while (lista[i].equipo != 'a' && lista[i].equipo != 'y' && lista[i].equipo != 'r');
        for (int p = 0; p < 3; p++) {
            cout << "Pokemon " << p + 1 << ": "; cin >> lista[i].pokemons[p];
        }
    }
}

void mostrar(str_entrenador entrenador) {
    cout << "-----------------------" << endl;
    cout << "Entrenador: " << entrenador.nomC.nombre << " " << entrenador.nomC.apellido << endl;
    cout << "Nivel: " << entrenador.nivel << " | Equipo: " << (entrenador.equipo=='a'?"Azul":entrenador.equipo=='y'?"Amarillo":"Rojo") << endl;
    cout << "Pokemons: ";
    for (int p = 0; p < 3; p++) cout << "[" << entrenador.pokemons[p] << "] ";
    cout << endl;
}

void buscarPokemon(str_entrenador lista[], int tam) {
    char buscado[20];
    bool encontrado = false;
    cout << "Pokemon a buscar: "; cin >> buscado;
    for (int i = 0; i < tam; i++) {
        for (int p = 0; p < 3; p++) {
            if (strcmp(lista[i].pokemons[p], buscado) == 0) {
                cout << "Poseedor: " << lista[i].nomC.nombre << " " << lista[i].nomC.apellido << endl;
                encontrado = true;
            }
        }
    }
    if (!encontrado) cout << "No se encontro ese Pokemon." << endl;
}

void intercambiarPokemon(str_entrenador lista[], int tam) {
    int e1, e2, p1, p2;
    cout << "ID Entrenador A (1-" << tam << "): "; cin >> e1;
    cout << "ID Entrenador B (1-" << tam << "): "; cin >> e2;
    e1--; e2--;
    cout << "Indice Pokemon de " << lista[e1].nomC.nombre << " (1-3): "; cin >> p1;
    cout << "Indice Pokemon de " << lista[e2].nomC.nombre << " (1-3): "; cin >> p2;
    p1--; p2--;
    char temp[20];
    strcpy(temp, lista[e1].pokemons[p1]);
    strcpy(lista[e1].pokemons[p1], lista[e2].pokemons[p2]);
    strcpy(lista[e2].pokemons[p2], temp);
    cout << "¡Intercambio exitoso!" << endl;
}