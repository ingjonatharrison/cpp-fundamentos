#include<iostream>
using namespace std;

void CalcularArea(int Lado){
    cout << "El area del cuadrado es: " << Lado*Lado << endl; 
}

void CalcularArea(double Base, double Altura1){
    cout << "El area del rectangulo es: " << Base*Altura1 << endl; 
}

void CalcularArea(double BaseMa, double BaseMe, double Altura2){
    cout << "El area del trapecio es: " << ((BaseMa+BaseMe)*Altura2)/2 << endl; 
}

int main(){

    int Lado;
    double Base, Altura1, BaseMa, BaseMe, Altura2;

    CalcularArea(Lado);
    CalcularArea(Base, Altura1);
    CalcularArea(BaseMa, BaseMe, Altura2);

    return 0;
}