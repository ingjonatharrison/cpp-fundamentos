#include <iostream>
using namespace std;

void suma(int *A, int *B, int *C){
    *A = *A + 1;
    *B = *B + 2;
    *C = *C + 3;
}

int main(){
    int a = 10, b = 20, c = 30;

    int *A = &a, *B = &b, *C = &c;

    // Antes
    cout<<"a: "<<a<<" A: "<<*A<<endl;
    cout<<"b: "<<b<<" B: "<<*B<<endl;
    cout<<"c: "<<c<<" C: "<<*C<<endl;

    suma(A, B, C);

    // Después
    cout<<"\nDespues:\n";
    cout<<"a: "<<a<<" A: "<<*A<<endl;
    cout<<"b: "<<b<<" B: "<<*B<<endl;
    cout<<"c: "<<c<<" C: "<<*C<<endl;

    // Reset
    a = 0; b = 0; c = 0;

    cout<<"\nDirecciones:\n";
    cout<<"A: "<<A<<endl;
    cout<<"B: "<<B<<endl;
    cout<<"C: "<<C<<endl;

    return 0;
}