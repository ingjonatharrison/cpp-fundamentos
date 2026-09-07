#include <iostream>
#include <string>

using namespace std;

/*
    CLASE: Alumno
    CLASS: Student

    Una clase es un molde que define los datos y comportamientos
    que tendrán sus objetos.

    A class is a blueprint that defines the data and behaviors
    that its objects will have.
*/
class Alumno
{
public:

    // Atributos / Attributes
    string nombre;
    int edad;
    float promedio;

    /*
        Método para mostrar la información del alumno.
        Method to display the student's information.
    */
    void mostrar()
    {
        cout << "Nombre / Name: " << nombre << endl;
        cout << "Edad / Age: " << edad << endl;
        cout << "Promedio / GPA: " << promedio << endl;
    }
};

int main()
{
    /*
        OBJETO: alumno1
        OBJECT: alumno1

        Creamos un objeto a partir de la clase Alumno.
        We create an object from the Alumno class.
    */
    Alumno alumno1;

    // Asignamos valores a sus atributos.
    // We assign values to its attributes.
    alumno1.nombre = "Jonathan";
    alumno1.edad = 21;
    alumno1.promedio = 95.0;

    // Llamamos al método del objeto.
    // We call the object's method.
    alumno1.mostrar();

    return 0;
}