#include <iostream>
using namespace std;

void MostrarDato(int Dato){
    cout << "Valor Entero: " << Dato << endl;
}

void MostrarDato(double Dato){
    cout << "Valor Decimal: " << Dato << endl;
}

void MostrarDato(char Dato){
    cout << "Valor de Caracter: " << Dato << endl;
}

int main(){

    int DatoE = 10;
    double DatoD = 15.2;
    char DatoC = 'A';

    MostrarDato(DatoE);
    MostrarDato(DatoD);
    MostrarDato(DatoC);

    return 0;
}