#include <iostream>
using namespace std;

const int MAX = 10; // tamaño máximo de la cola

bool colallena(int FI) {
    return (FI == MAX);
}

bool colavacia(int FR) {
    return (FR == 0);
}

bool inserta(int COLA[], int &FR, int &FI, int dato) {
    if (!colallena(FI)) {
        FI++;
        COLA[FI] = dato;
        if (FR == 0) FR = 1; 
        return true;
    } else {
        cout << "Cola llena, elemento no insertado\n";
        return false;
    }
}

int elimina(int COLA[], int &FR, int &FI) {
    if (FR != 0) {
        int dato = COLA[FR];
        if (FR == FI) {
            FR = FI = 0; 
        } else {
            if (FR == MAX) {
                FR = 1;
            } else {
                FR++;
            }
        }
        return dato;
    } else {
        cout << "Cola vacia\n";
        return -1; 
    }
}

void mostrar(int COLA[], int FR, int FI) {
    if (colavacia(FR)) {
        cout << "Cola vacia\n";
        return;
    }
    cout << "Elementos en la cola: ";
    for (int i = FR; i <= FI; i++) {
        cout << COLA[i] << " ";
    }
    cout << endl;
}

int main() {
    int COLA[MAX+1]; 
    int FR = 0, FI = 0; 
    int opc, dato;

    do {
        cout << "\n===== MENU COLA =====\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Verificar si cola llena\n";
        cout << "4. Verificar si cola vacía\n";
        cout << "5. Mostrar estado de la cola\n";
        cout << "6. Salir\n";
        cout << "Opcion: "; cin >> opc;

        switch(opc) {
            case 1:
                cout << "Ingrese dato: "; cin >> dato;
                inserta(COLA, FR, FI, dato);
                break;
            case 2:
                dato = elimina(COLA, FR, FI);
                if (dato != -1) cout << "Elemento eliminado: " << dato << endl;
                break;
            case 3:
                if (colallena(FI)) cout << "La cola esta llena\n";
                else cout << "La cola NO esta llena\n";
                break;
            case 4:
                if (colavacia(FR)) cout << "La cola esta vacia\n";
                else cout << "La cola NO esta vacia\n";
                break;
            case 5: mostrar(COLA, FR, FI); break;
            case 6: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opcion inválida\n";
        }
    } while(opc != 6);

    return 0;
}