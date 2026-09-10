#include <stdio.h>
#include <iostream>

using namespace std;

void suma(int *A, int *B, int *r){
    *r=*A+*B;
}

int main() {
    int a = 5, b = 6;
    int resultado;

    suma(&a, &b, &resultado);

    cout << "resultado: " << resultado << endl;

    return 0;
}