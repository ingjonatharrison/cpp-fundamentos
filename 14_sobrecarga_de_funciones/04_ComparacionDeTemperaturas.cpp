#include<iostream>
using namespace std;

class temperatura{
    private:
        float grados;
    public:
        temperatura();
        temperatura(float);

        friend void CompararTemperatura(temperatura, temperatura);
        friend void CompararTemperatura(temperatura, float);

        void mostrar();
};

temperatura::temperatura(){
    grados = 0.0;
}

temperatura::temperatura(float grados){
    this->grados = grados;
}

void CompararTemperatura(temperatura t1, temperatura t2){
    if(t1.grados > t2.grados){
        cout << "La primera temperatura es mayor." << endl;
    }else if(t1.grados < t2.grados){
        cout << "La segunda temperatura es mayor." << endl;
    }else{
        cout << "Ambas temperaturas son iguales." << endl;
    }
}

void CompararTemperatura(temperatura t1, float grados){
    if(t1.grados > grados){
        cout << "La temperatura del objeto es mayor." << endl;
    }else if(t1.grados < grados){
        cout << "La temperatura del valor es mayor." << endl;
    }else{
        cout << "Ambas temperaturas son iguales." << endl;
    }
}

void temperatura::mostrar(){
    cout << "Temperatura: " << grados << "°C" << endl;
}

int main(){

    temperatura t1(25.5f);
    temperatura t2(30.0f);

    t1.mostrar();
    t2.mostrar();

    cout << "\n--- Comparando dos objetos ---" << endl;
    CompararTemperatura(t1, t2);

    cout << "\n--- Comparando objeto contra valor ---" << endl;
    float valor = 20.0f;
    CompararTemperatura(t1, valor);

    return 0;
}

/*

¿Por qué se requieren dos declaraciones friend?

Porque comparar(Temperatura, Temperatura) y comparar
(Temperatura, float) son dos funciones distintas, aunque 
compartan nombre. La amistad se concede a una función concreta, 
identificada por su nombre y su lista de parámetros. Declarar 
una como amiga no le da permiso a la otra, así que cada una 
necesita su propia línea friend para poder acceder al atributo 
privado grados.

¿Qué parámetros permiten distinguirlas?

El segundo parámetro: en una es de tipo Temperatura y en la otra 
es float. Esa diferencia en la lista de parámetros es lo que permite 
la sobrecarga. El compilador elige la versión según el tipo del 
segundo argumento con que se llame. (El tipo de retorno no sirve 
para distinguirlas; ambas son void.)

¿Por qué se usan sin el operador punto?

Porque no son miembros de la clase. Una función amiga solo tiene 
permiso de acceder a los miembros privados, pero sigue siendo una 
función global independiente. Por eso se llama comparar(t1, t2) y 
no t1.comparar(t2). El operador punto se usa para invocar métodos 
que pertenecen a un objeto, y dichos métodos reciben automáticamente 
el puntero this. Una función amiga no tiene this, así que los objetos 
con los que trabaja se le pasan explícitamente como parámetros, 
y accede a sus datos escribiendo t1.grados, t2.grados, algo que solo 
puede hacer gracias a la declaración friend.

*/