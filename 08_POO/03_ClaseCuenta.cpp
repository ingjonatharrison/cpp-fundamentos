#include <iostream>
#include <string>

using namespace std;

/*
    CLASE: Cuenta
    CLASS: Account

    Representa una cuenta bancaria sencilla.
    Represents a simple bank account.
*/
class Cuenta
{
private:

    /*
        Estos atributos son privados.
        These attributes are private.

        No pueden modificarse directamente desde fuera
        de la clase.

        They cannot be modified directly from outside
        the class.
    */
    string titular;
    double saldo;

public:

    /*
        CONSTRUCTOR
        CONSTRUCTOR

        Inicializa el objeto cuando se crea.
        Initializes the object when it is created.
    */
    Cuenta(string nombre, double cantidadInicial)
    {
        titular = nombre;
        saldo = cantidadInicial;
    }

    /*
        MÉTODO: depositar
        METHOD: deposit

        Agrega dinero al saldo si la cantidad es válida.
        Adds money to the balance if the amount is valid.
    */
    void depositar(double cantidad)
    {
        if (cantidad > 0)
        {
            saldo += cantidad;
        }
    }

    /*
        MÉTODO: retirar
        METHOD: withdraw

        Retira dinero solamente si la cantidad es válida
        y existe suficiente saldo.

        Withdraws money only if the amount is valid
        and there is enough balance.
    */
    void retirar(double cantidad)
    {
        if (cantidad > 0 && cantidad <= saldo)
        {
            saldo -= cantidad;
        }
    }

    /*
        MÉTODO: mostrar
        METHOD: display

        Muestra la información de la cuenta.
        Displays the account information.
    */
    void mostrar()
    {
        cout << "Titular / Account holder: " << titular << endl;
        cout << "Saldo / Balance: $" << saldo << endl;
    }
};

int main()
{
    /*
        Creamos un objeto de tipo Cuenta.
        We create an object of type Account.
    */
    Cuenta cuenta("Jonathan", 1000.0);

    // Realizamos un depósito.
    // We make a deposit.
    cuenta.depositar(500.0);

    // Realizamos un retiro.
    // We make a withdrawal.
    cuenta.retirar(200.0);

    // Mostramos la información.
    // We display the information.
    cuenta.mostrar();

    return 0;
}