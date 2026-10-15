#include<iostream>
using namespace std;

void promedio(int n1, int n2){
    cout << "El promedio de los 2 numeros es: " << (n1+n2)/2.0 << endl;
}

void promedio(int n1, int n2, int n3){
    cout << "El promedio de los 3 numeros es: " << (n1+n2+n3)/3.0 << endl;
}

void promedio(int n1[], int tam){
    int suma = 0;
    for(int i=0; i<tam; i++){
        suma += n1[i];
    }
    cout << "El promedio de los " << tam << " numeros es: " << suma/tam << endl;
}

int main(){

    promedio(10, 20);
    promedio(10, 20, 30);
    promedio((int[]){10, 20, 30, 40, 50}, 5);

    return 0;
}