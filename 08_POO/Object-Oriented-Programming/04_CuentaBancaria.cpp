#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
public:
    string numeroCuenta;
    string titular;
    double saldo;

    void depositar(double cantidad) {
        saldo += cantidad;
        cout << "Deposito realizado." << endl;
    }

    void retirar(double cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retiro realizado." << endl;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    }

    void consultarSaldo() {
        cout << "Saldo actual: $" << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta1;

    cuenta1.numeroCuenta = "001234";
    cuenta1.titular = "Jonathan";
    cuenta1.saldo = 1000;

    cout << "Titular: " << cuenta1.titular << endl;

    cuenta1.consultarSaldo();

    cuenta1.depositar(500);
    cuenta1.consultarSaldo();

    cuenta1.retirar(300);
    cuenta1.consultarSaldo();

    return 0;
}