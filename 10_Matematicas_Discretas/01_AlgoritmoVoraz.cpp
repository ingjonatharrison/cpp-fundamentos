#include <iostream>
#include <set>
#include <map>
#include <limits>

using namespace std;

int main() {

    int CM, a, an;
    set<int, greater<int>> AUX_MO; // Set para guardar denominaciones ordenadas de mayor a menor
    map<int, int, greater<int>> desglose; // Map para contar cuantas monedas/billetes de cada tipo se utilizaron

    cout << "\n============================================\n"
    << "          CALCULADORA DE CAMBIO\n"
    << "============================================\n"
    << "\nCuantas denominaciones vas a usar: ";cin >> a;
    
    while (cin.fail() || a <= 0) {// Prevenir errores de entrada
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nERROR: Debes introducir un numero mayor que 0."
        << "\nCuantas denominaciones vas a usar: "; cin >> a;
    }

    cout << "\n--------------------------------------------\n"
    << "       INGRESO DE DENOMINACIONES\n"
    << "--------------------------------------------\n";

    for (int j = 0; j < a; j++) {
        cout << "\nDame el valor de la moneda/billete " << j + 1 << ": "; cin >> an;

        while (cin.fail() || an <= 0) { // Validar que sea un numero positivo
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "ERROR: La denominacion debe ser mayor que 0."
            << "\nDame el valor de la moneda/billete " << j + 1 << ": "; cin >> an;
        }

        if (AUX_MO.find(an) != AUX_MO.end()) { // Comprobar si ya existe
            cout << "AVISO: La denominacion " << an
            << " ya existe. No se agregara nuevamente.";
        } else {
            AUX_MO.insert(an);
            cout << "OK: Denominacion agregada.";
        }
    }
 
    cout << "\n\n============================================\n"
    << "        DENOMINACIONES DISPONIBLES\n"
    << "============================================\n";

    int posicion = 1;

    for (int moneda : AUX_MO) {
        cout << posicion << ". $" << moneda << "\n";
        posicion++;
    }

    cout << "\n--------------------------------------------\n"
    << "              CALCULAR CAMBIO\n"
    << "--------------------------------------------\n"
    << "\nCambio a dar: "; cin >> CM;

    while (cin.fail() || CM <= 0) { // Validar cambio
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR: El cambio debe ser mayor que 0."
        << "\nCambio a dar: "; cin >> CM;
    }
 
    int cambioOriginal = CM;
    int pasos = 0; // Contador de pasos

    cout << "\n\n============================================\n"
    << "              DESGLOSE DEL CAMBIO\n"
    << "============================================\n"
    << "\nCambio solicitado: $" << cambioOriginal << "\n";


    for (int tot : AUX_MO) {
        while (CM >= tot) {
            pasos++;
            CM = CM - tot;
            desglose[tot]++;// Registrar que utilizamos esta denominacion

            cout << "\nPaso " << pasos
            << " -> Se utiliza: $" << tot
            << " | Saldo restante: $" << CM;
        }
        if (CM == 0) {
            break;
        }
    }

    cout << "\n\n============================================\n"
    << "                 RESULTADO\n"
    << "============================================\n";

    if (CM == 0) {
        cout << "\nCAMBIO COMPLETADO CORRECTAMENTE.\n"
        << "\nDesglose:\n";

        int totalPiezas = 0;

        for (auto elemento : desglose) {
            int denominacion = elemento.first;
            int cantidad = elemento.second;
            int subtotal = denominacion * cantidad;

            cout << "\n$" << denominacion << " x " << cantidad << " = $" << subtotal;
            totalPiezas += cantidad;
        }
         
        cout << "\n\n--------------------------------------------\n"
        << "Cambio original : $" << cambioOriginal << "\n"
        << "Total de piezas : " << totalPiezas << "\n"
        << "Pasos realizados: " << pasos << "\n"
        << "--------------------------------------------\n";

    } else {
        cout << "\nNO SE PUDO COMPLETAR EL CAMBIO.\n"
        << "\nCambio original : $" << cambioOriginal
        << "\nCantidad entregada: $"<< cambioOriginal - CM
        << "\nCantidad faltante : $" << CM
        << "\n\nEsto significa que las denominaciones"
        << "\ndisponibles no permiten formar exactamente"
        << "\nel cambio solicitado."
        << "\n\nPasos realizados: " << pasos << "\n";
    }

    cout << "\n============================================\n"
    << "              FIN DEL PROGRAMA\n"
    << "============================================\n";
    system("pause");
    return 0;
}