#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
 
string leerLinea() {
    string s;
    if (!getline(cin, s)) {   // fin de entrada (Ctrl+D / Ctrl+Z)
        cout << "\nFin de la entrada. Saliendo...\n";
        exit(0);
    }
    return s;
}

string leerTexto(const string& mensaje) {
    while (true) {
        cout << mensaje;
        string s = leerLinea();
        if (!s.empty()) return s;
        cout << "  El texto no puede estar vacio.\n";
    }
}

int leerEntero(const string& mensaje, int minimo, int maximo) {
    while (true) {
        cout << mensaje;
        string s = leerLinea();
        try {
            size_t pos = 0;
            int v = stoi(s, &pos);
            if (pos == s.size() && v >= minimo && v <= maximo) return v;
        } catch (...) {}
        cout << "  Valor invalido. Ingresa un entero entre " << minimo << " y " << maximo << ".\n";
    }
}

double leerDecimal(const string& mensaje, double minimo, double maximo) {
    while (true) {
        cout << mensaje;
        string s = leerLinea();
        try {
            size_t pos = 0;
            double v = stod(s, &pos);
            if (pos == s.size() && v >= minimo && v <= maximo) return v;
        } catch (...) {}
        cout << "  Valor invalido. Ingresa un numero entre " << minimo << " y " << maximo << ".\n";
    }
}

bool leerBool(const string& mensaje) {
    while (true) {
        cout << mensaje << " (s/n): ";
        string s = leerLinea();
        if (s == "s" || s == "S") return true;
        if (s == "n" || s == "N") return false;
        cout << "  Responde 's' o 'n'.\n";
    }
}

string sn(bool b) { return b ? "Si" : "No"; }
 
int elegirObjeto(const string& clase, const string etiquetas[], int n) {
    cout << "\n=== " << clase << ": elige un objeto ===\n";
    for (int i = 0; i < n; i++)
        cout << " " << (i + 1) << ". " << etiquetas[i] << "\n";
    cout << " 0. Regresar al menu principal\n";
    int op = leerEntero("Opcion: ", 0, n);
    return op - 1;
}
 
class Libro {
private:
    string titulo;
    string autor;
    int paginas;
    bool disponible;
public:
    Libro() : titulo("Sin titulo"), autor("Desconocido"), paginas(0), disponible(true) {}
    Libro(string t, string a, int p, bool d) : titulo(t), autor(a), paginas(p), disponible(d) {}

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getPaginas() const { return paginas; }
    bool getDisponible() const { return disponible; }

    void setTitulo(string t) { titulo = t; }
    void setAutor(string a) { autor = a; }
    void setPaginas(int p) { paginas = (p < 0) ? 0 : p; }
    void setDisponible(bool d) { disponible = d; }

    void prestar() {
        if (disponible) { disponible = false; cout << "Libro prestado: \"" << titulo << "\".\n"; }
        else cout << "El libro ya se encuentra prestado.\n";
    }
    void devolver() {
        if (!disponible) { disponible = true; cout << "Libro devuelto: \"" << titulo << "\".\n"; }
        else cout << "El libro ya estaba en la biblioteca.\n";
    }
    string clasificarExtension() const {
        if (paginas == 0) return "Sin informacion de paginas";
        if (paginas < 150) return "Lectura corta";
        if (paginas < 400) return "Lectura mediana";
        return "Lectura extensa";
    }
    void mostrarInfo() const {
        cout << "\"" << titulo << "\" de " << autor << " (" << paginas << " pags.) - "
             << (disponible ? "Disponible" : "Prestado") << " - " << clasificarExtension() << "\n";
    }
};

void menuLibro(Libro objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Libro " + to_string(i + 1) + ": " + objs[i].getTitulo();
        int idx = elegirObjeto("LIBRO", et, n);
        if (idx < 0) return;
        Libro& o = objs[idx];
        int op;
        do {
            cout << "\n--- LIBRO " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set titulo\n 3. Set autor\n 4. Set paginas\n 5. Set disponible\n"
                 << " 6. Metodo prestar()\n 7. Metodo devolver()\n"
                 << " 8. Metodo clasificarExtension()\n 9. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 9);
            switch (op) {
                case 1:
                    cout << "Titulo: " << o.getTitulo() << "\nAutor: " << o.getAutor()
                         << "\nPaginas: " << o.getPaginas() << "\nDisponible: " << sn(o.getDisponible()) << "\n";
                    break;
                case 2: o.setTitulo(leerTexto("Nuevo titulo: ")); break;
                case 3: o.setAutor(leerTexto("Nuevo autor: ")); break;
                case 4: o.setPaginas(leerEntero("Nuevas paginas: ", 0, 20000)); break;
                case 5: o.setDisponible(leerBool("Esta disponible?")); break;
                case 6: o.prestar(); break;
                case 7: o.devolver(); break;
                case 8: cout << "Clasificacion: " << o.clasificarExtension() << "\n"; break;
                case 9: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
class Automovil {
private:
    string marca;
    string modelo;
    int velocidad;      // km/h
    bool encendido;
public:
    static const int VEL_MAXIMA = 200;

    Automovil() : marca("Generica"), modelo("Base"), velocidad(0), encendido(false) {}
    Automovil(string ma, string mo, int v, bool e) : marca(ma), modelo(mo), velocidad(v), encendido(e) {}

    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getVelocidad() const { return velocidad; }
    bool getEncendido() const { return encendido; }

    void setMarca(string m) { marca = m; }
    void setModelo(string m) { modelo = m; }
    void setVelocidad(int v) { velocidad = (v < 0) ? 0 : (v > VEL_MAXIMA ? VEL_MAXIMA : v); }
    void setEncendido(bool e) { encendido = e; if (!e) velocidad = 0; }

    void encender() {
        if (encendido) cout << "El automovil ya esta encendido.\n";
        else { encendido = true; cout << "Motor encendido.\n"; }
    }
    void apagar() {
        if (!encendido) cout << "El automovil ya esta apagado.\n";
        else if (velocidad > 0) cout << "No se puede apagar en movimiento. Frena primero.\n";
        else { encendido = false; cout << "Motor apagado.\n"; }
    }
    void acelerar(int incremento) {
        if (!encendido) { cout << "Enciende el motor primero.\n"; return; }
        setVelocidad(velocidad + incremento);
        cout << "Acelerando... velocidad actual: " << velocidad << " km/h\n";
    }
    void frenar(int decremento) {
        setVelocidad(velocidad - decremento);
        cout << "Frenando... velocidad actual: " << velocidad << " km/h\n";
    }
    void mostrarInfo() const {
        cout << marca << " " << modelo << " - " << (encendido ? "Encendido" : "Apagado")
             << " - " << velocidad << " km/h\n";
    }
};

void menuAutomovil(Automovil objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Auto " + to_string(i + 1) + ": " + objs[i].getMarca() + " " + objs[i].getModelo();
        int idx = elegirObjeto("AUTOMOVIL", et, n);
        if (idx < 0) return;
        Automovil& o = objs[idx];
        int op;
        do {
            cout << "\n--- AUTOMOVIL " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set marca\n 3. Set modelo\n 4. Set velocidad\n 5. Set encendido\n"
                 << " 6. Metodo encender()\n 7. Metodo apagar()\n"
                 << " 8. Metodo acelerar()\n 9. Metodo frenar()\n 10. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 10);
            switch (op) {
                case 1:
                    cout << "Marca: " << o.getMarca() << "\nModelo: " << o.getModelo()
                         << "\nVelocidad: " << o.getVelocidad() << " km/h\nEncendido: " << sn(o.getEncendido()) << "\n";
                    break;
                case 2: o.setMarca(leerTexto("Nueva marca: ")); break;
                case 3: o.setModelo(leerTexto("Nuevo modelo: ")); break;
                case 4: o.setVelocidad(leerEntero("Nueva velocidad (km/h): ", 0, 1000)); break;
                case 5: o.setEncendido(leerBool("Esta encendido?")); break;
                case 6: o.encender(); break;
                case 7: o.apagar(); break;
                case 8: o.acelerar(leerEntero("Incremento (km/h): ", 1, 200)); break;
                case 9: o.frenar(leerEntero("Decremento (km/h): ", 1, 200)); break;
                case 10: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
class Alumno {
private:
    string nombre;
    string matricula;
    string carrera;
    int semestre;
    double promedio;            // escala 0 - 10
    int examenesPresentados;
public:
    Alumno() : nombre("Sin nombre"), matricula("Sin matricula"), carrera("Sin carrera"),
               semestre(1), promedio(0.0), examenesPresentados(0) {}
    Alumno(string n, string m, string c, int s, double p, int e)
        : nombre(n), matricula(m), carrera(c), semestre(s), promedio(p), examenesPresentados(e) {}

    string getNombre() const { return nombre; }
    string getMatricula() const { return matricula; }
    string getCarrera() const { return carrera; }
    int getSemestre() const { return semestre; }
    double getPromedio() const { return promedio; }
    int getExamenesPresentados() const { return examenesPresentados; }

    void setNombre(string n) { nombre = n; }
    void setMatricula(string m) { matricula = m; }
    void setCarrera(string c) { carrera = c; }
    void setSemestre(int s) { semestre = (s < 1) ? 1 : s; }
    void setPromedio(double p) { promedio = (p < 0) ? 0 : (p > 10 ? 10 : p); }
    void setExamenesPresentados(int e) { examenesPresentados = (e < 0) ? 0 : e; }

    void presentarExamen(double calificacion) {
        // Recalcula el promedio como promedio acumulado
        promedio = (promedio * examenesPresentados + calificacion) / (examenesPresentados + 1);
        examenesPresentados++;
        cout << nombre << " presento un examen con " << calificacion
             << ". Nuevo promedio: " << fixed << setprecision(2) << promedio << "\n";
    }
    void avanzarSemestre() {
        semestre++;
        cout << nombre << " avanza al semestre " << semestre << ".\n";
    }
    bool estaEnRiesgoAcademico() const { return examenesPresentados > 0 && promedio < 7.0; }
    void mostrarInfo() const {
        cout << nombre << " (" << matricula << ") - " << carrera << ", semestre " << semestre
             << ", promedio " << fixed << setprecision(2) << promedio
             << ", examenes: " << examenesPresentados << "\n";
    }
};

void menuAlumno(Alumno objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Alumno " + to_string(i + 1) + ": " + objs[i].getNombre();
        int idx = elegirObjeto("ALUMNO", et, n);
        if (idx < 0) return;
        Alumno& o = objs[idx];
        int op;
        do {
            cout << "\n--- ALUMNO " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set nombre\n 3. Set matricula\n 4. Set carrera\n 5. Set semestre\n"
                 << " 6. Set promedio\n 7. Set examenesPresentados\n"
                 << " 8. Metodo presentarExamen()\n 9. Metodo avanzarSemestre()\n"
                 << " 10. Metodo estaEnRiesgoAcademico()\n 11. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 11);
            switch (op) {
                case 1:
                    cout << "Nombre: " << o.getNombre() << "\nMatricula: " << o.getMatricula()
                         << "\nCarrera: " << o.getCarrera() << "\nSemestre: " << o.getSemestre()
                         << "\nPromedio: " << fixed << setprecision(2) << o.getPromedio()
                         << "\nExamenes presentados: " << o.getExamenesPresentados() << "\n";
                    break;
                case 2: o.setNombre(leerTexto("Nuevo nombre: ")); break;
                case 3: o.setMatricula(leerTexto("Nueva matricula: ")); break;
                case 4: o.setCarrera(leerTexto("Nueva carrera: ")); break;
                case 5: o.setSemestre(leerEntero("Nuevo semestre (1-12): ", 1, 12)); break;
                case 6: o.setPromedio(leerDecimal("Nuevo promedio (0-10): ", 0, 10)); break;
                case 7: o.setExamenesPresentados(leerEntero("Examenes presentados: ", 0, 1000)); break;
                case 8: o.presentarExamen(leerDecimal("Calificacion del examen (0-10): ", 0, 10)); break;
                case 9: o.avanzarSemestre(); break;
                case 10: cout << (o.estaEnRiesgoAcademico() ? "SI esta en riesgo academico (promedio < 7).\n"
                                                             : "NO esta en riesgo academico.\n"); break;
                case 11: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
class CuentaBancaria {
private:
    string numeroCuenta;
    string titular;
    double saldo;
public:
    CuentaBancaria() : numeroCuenta("0000000000"), titular("Sin titular"), saldo(0.0) {}
    CuentaBancaria(string num, string tit, double s) : numeroCuenta(num), titular(tit), saldo(s) {}

    string getNumeroCuenta() const { return numeroCuenta; }
    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }

    void setNumeroCuenta(string n) { numeroCuenta = n; }
    void setTitular(string t) { titular = t; }
    void setSaldo(double s) { saldo = (s < 0) ? 0 : s; }

    void depositar(double monto) {
        if (monto <= 0) { cout << "El monto a depositar debe ser mayor a 0.\n"; return; }
        saldo += monto;
        cout << "Deposito exitoso. Saldo actual: $" << fixed << setprecision(2) << saldo << "\n";
    }
    bool tieneSaldoSuficiente(double monto) const { return monto <= saldo; }
    void retirar(double monto) {
        if (monto <= 0) { cout << "El monto a retirar debe ser mayor a 0.\n"; return; }
        if (!tieneSaldoSuficiente(monto)) { cout << "Fondos insuficientes.\n"; return; }
        saldo -= monto;
        cout << "Retiro exitoso. Saldo actual: $" << fixed << setprecision(2) << saldo << "\n";
    }
    void mostrarInfo() const {
        cout << "Cuenta " << numeroCuenta << " - Titular: " << titular
             << " - Saldo: $" << fixed << setprecision(2) << saldo << "\n";
    }
};

void menuCuenta(CuentaBancaria objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Cuenta " + to_string(i + 1) + ": " + objs[i].getTitular();
        int idx = elegirObjeto("CUENTA BANCARIA", et, n);
        if (idx < 0) return;
        CuentaBancaria& o = objs[idx];
        int op;
        do {
            cout << "\n--- CUENTA " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set numeroCuenta\n 3. Set titular\n 4. Set saldo\n"
                 << " 5. Metodo depositar()\n 6. Metodo retirar()\n"
                 << " 7. Metodo tieneSaldoSuficiente()\n 8. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 8);
            switch (op) {
                case 1:
                    cout << "Numero de cuenta: " << o.getNumeroCuenta() << "\nTitular: " << o.getTitular()
                         << "\nSaldo: $" << fixed << setprecision(2) << o.getSaldo() << "\n";
                    break;
                case 2: o.setNumeroCuenta(leerTexto("Nuevo numero de cuenta: ")); break;
                case 3: o.setTitular(leerTexto("Nuevo titular: ")); break;
                case 4: o.setSaldo(leerDecimal("Nuevo saldo: ", 0, 1e12)); break;
                case 5: o.depositar(leerDecimal("Monto a depositar: ", 0.01, 1e12)); break;
                case 6: o.retirar(leerDecimal("Monto a retirar: ", 0.01, 1e12)); break;
                case 7: {
                    double m = leerDecimal("Monto a verificar: ", 0.01, 1e12);
                    cout << (o.tieneSaldoSuficiente(m) ? "Si hay saldo suficiente.\n" : "No hay saldo suficiente.\n");
                    break;
                }
                case 8: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
class Mascota {
private:
    string nombre;
    string especie;
    int edad;       // anios
    int energia;    // 0 - 100
public:
    Mascota() : nombre("Sin nombre"), especie("Desconocida"), edad(0), energia(100) {}
    Mascota(string n, string es, int ed, int en) : nombre(n), especie(es), edad(ed), energia(en) {}

    string getNombre() const { return nombre; }
    string getEspecie() const { return especie; }
    int getEdad() const { return edad; }
    int getEnergia() const { return energia; }

    void setNombre(string n) { nombre = n; }
    void setEspecie(string e) { especie = e; }
    void setEdad(int e) { edad = (e < 0) ? 0 : e; }
    void setEnergia(int e) { energia = (e < 0) ? 0 : (e > 100 ? 100 : e); }

    void comer() {
        setEnergia(energia + 20);
        cout << nombre << " comio. Energia: " << energia << "\n";
    }
    void jugar() {
        if (energia < 25) { cout << nombre << " esta muy cansado para jugar. Dejalo comer o dormir.\n"; return; }
        setEnergia(energia - 25);
        cout << nombre << " jugo un rato. Energia: " << energia << "\n";
    }
    void dormir() {
        energia = 100;
        cout << nombre << " durmio y recupero toda su energia (100).\n";
    }
    void hacerSonido() const {
        if (especie == "Perro" || especie == "perro") cout << nombre << " dice: Guau guau!\n";
        else if (especie == "Gato" || especie == "gato") cout << nombre << " dice: Miau!\n";
        else cout << nombre << " hace un sonido caracteristico de su especie.\n";
    }
    void mostrarInfo() const {
        cout << nombre << " (" << especie << ", " << edad << " anios) - Energia: " << energia << "/100\n";
    }
};

void menuMascota(Mascota objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Mascota " + to_string(i + 1) + ": " + objs[i].getNombre();
        int idx = elegirObjeto("MASCOTA", et, n);
        if (idx < 0) return;
        Mascota& o = objs[idx];
        int op;
        do {
            cout << "\n--- MASCOTA " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set nombre\n 3. Set especie\n 4. Set edad\n 5. Set energia\n"
                 << " 6. Metodo comer()\n 7. Metodo jugar()\n 8. Metodo dormir()\n"
                 << " 9. Metodo hacerSonido()\n 10. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 10);
            switch (op) {
                case 1:
                    cout << "Nombre: " << o.getNombre() << "\nEspecie: " << o.getEspecie()
                         << "\nEdad: " << o.getEdad() << " anios\nEnergia: " << o.getEnergia() << "/100\n";
                    break;
                case 2: o.setNombre(leerTexto("Nuevo nombre: ")); break;
                case 3: o.setEspecie(leerTexto("Nueva especie (Perro/Gato/otra): ")); break;
                case 4: o.setEdad(leerEntero("Nueva edad (anios): ", 0, 100)); break;
                case 5: o.setEnergia(leerEntero("Nueva energia (0-100): ", 0, 100)); break;
                case 6: o.comer(); break;
                case 7: o.jugar(); break;
                case 8: o.dormir(); break;
                case 9: o.hacerSonido(); break;
                case 10: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
class Celular {
private:
    string marca;
    string modelo;
    int bateria;        // 0 - 100 %
    bool encendido;
public:
    Celular() : marca("Generico"), modelo("Basico"), bateria(100), encendido(false) {}
    Celular(string ma, string mo, int b, bool e) : marca(ma), modelo(mo), bateria(b), encendido(e) {}

    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }
    bool getEncendido() const { return encendido; }

    void setMarca(string m) { marca = m; }
    void setModelo(string m) { modelo = m; }
    void setBateria(int b) { bateria = (b < 0) ? 0 : (b > 100 ? 100 : b); }
    void setEncendido(bool e) { encendido = e; }

    void encender() {
        if (encendido) cout << "El celular ya esta encendido.\n";
        else if (bateria == 0) cout << "Bateria agotada. Conecta el cargador.\n";
        else { encendido = true; cout << "Celular encendido.\n"; }
    }
    void apagar() {
        if (!encendido) cout << "El celular ya esta apagado.\n";
        else { encendido = false; cout << "Celular apagado.\n"; }
    }
    void cargar(int porcentaje) {
        setBateria(bateria + porcentaje);
        cout << "Cargando... bateria: " << bateria << "%\n";
    }
    void llamar(const string& numero) {
        if (!encendido) { cout << "Enciende el celular para llamar.\n"; return; }
        if (bateria < 5) { cout << "Bateria insuficiente para realizar la llamada.\n"; return; }
        setBateria(bateria - 5);
        cout << "Llamando al " << numero << "... (bateria restante: " << bateria << "%)\n";
    }
    void mostrarInfo() const {
        cout << marca << " " << modelo << " - " << (encendido ? "Encendido" : "Apagado")
             << " - Bateria: " << bateria << "%\n";
    }
};

void menuCelular(Celular objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Celular " + to_string(i + 1) + ": " + objs[i].getMarca() + " " + objs[i].getModelo();
        int idx = elegirObjeto("CELULAR", et, n);
        if (idx < 0) return;
        Celular& o = objs[idx];
        int op;
        do {
            cout << "\n--- CELULAR " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set marca\n 3. Set modelo\n 4. Set bateria\n 5. Set encendido\n"
                 << " 6. Metodo encender()\n 7. Metodo apagar()\n"
                 << " 8. Metodo cargar()\n 9. Metodo llamar()\n 10. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 10);
            switch (op) {
                case 1:
                    cout << "Marca: " << o.getMarca() << "\nModelo: " << o.getModelo()
                         << "\nBateria: " << o.getBateria() << "%\nEncendido: " << sn(o.getEncendido()) << "\n";
                    break;
                case 2: o.setMarca(leerTexto("Nueva marca: ")); break;
                case 3: o.setModelo(leerTexto("Nuevo modelo: ")); break;
                case 4: o.setBateria(leerEntero("Nueva bateria (0-100): ", 0, 100)); break;
                case 5: o.setEncendido(leerBool("Esta encendido?")); break;
                case 6: o.encender(); break;
                case 7: o.apagar(); break;
                case 8: o.cargar(leerEntero("Porcentaje a cargar (1-100): ", 1, 100)); break;
                case 9: o.llamar(leerTexto("Numero a marcar: ")); break;
                case 10: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
class Producto {
private:
    string codigo;
    string nombre;
    double precio;
    int stock;
public:
    Producto() : codigo("P000"), nombre("Sin nombre"), precio(0.0), stock(0) {}
    Producto(string c, string n, double p, int s) : codigo(c), nombre(n), precio(p), stock(s) {}

    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }

    void setCodigo(string c) { codigo = c; }
    void setNombre(string n) { nombre = n; }
    void setPrecio(double p) { precio = (p < 0) ? 0 : p; }
    void setStock(int s) { stock = (s < 0) ? 0 : s; }

    void aplicarDescuento(double porcentaje) {
        if (porcentaje <= 0 || porcentaje > 100) { cout << "Porcentaje invalido.\n"; return; }
        precio -= precio * porcentaje / 100.0;
        cout << "Descuento del " << porcentaje << "% aplicado. Nuevo precio: $"
             << fixed << setprecision(2) << precio << "\n";
    }
    void vender(int cantidad) {
        if (cantidad <= 0) { cout << "Cantidad invalida.\n"; return; }
        if (cantidad > stock) { cout << "Stock insuficiente (disponibles: " << stock << ").\n"; return; }
        stock -= cantidad;
        cout << "Venta registrada: " << cantidad << " x $" << fixed << setprecision(2) << precio
             << " = $" << cantidad * precio << ". Stock restante: " << stock << "\n";
    }
    void reabastecer(int cantidad) {
        if (cantidad <= 0) { cout << "Cantidad invalida.\n"; return; }
        stock += cantidad;
        cout << "Inventario actualizado. Stock: " << stock << "\n";
    }
    void mostrarInfo() const {
        cout << "[" << codigo << "] " << nombre << " - $" << fixed << setprecision(2) << precio
             << " - Stock: " << stock << "\n";
    }
};

void menuProducto(Producto objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Producto " + to_string(i + 1) + ": " + objs[i].getNombre();
        int idx = elegirObjeto("PRODUCTO", et, n);
        if (idx < 0) return;
        Producto& o = objs[idx];
        int op;
        do {
            cout << "\n--- PRODUCTO " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set codigo\n 3. Set nombre\n 4. Set precio\n 5. Set stock\n"
                 << " 6. Metodo aplicarDescuento()\n 7. Metodo vender()\n"
                 << " 8. Metodo reabastecer()\n 9. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 9);
            switch (op) {
                case 1:
                    cout << "Codigo: " << o.getCodigo() << "\nNombre: " << o.getNombre()
                         << "\nPrecio: $" << fixed << setprecision(2) << o.getPrecio()
                         << "\nStock: " << o.getStock() << "\n";
                    break;
                case 2: o.setCodigo(leerTexto("Nuevo codigo: ")); break;
                case 3: o.setNombre(leerTexto("Nuevo nombre: ")); break;
                case 4: o.setPrecio(leerDecimal("Nuevo precio: ", 0, 1e9)); break;
                case 5: o.setStock(leerEntero("Nuevo stock: ", 0, 1000000)); break;
                case 6: o.aplicarDescuento(leerDecimal("Porcentaje de descuento (1-100): ", 0.01, 100)); break;
                case 7: o.vender(leerEntero("Cantidad a vender: ", 1, 1000000)); break;
                case 8: o.reabastecer(leerEntero("Cantidad a agregar: ", 1, 1000000)); break;
                case 9: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
class Ventilador {
private:
    string marca;
    bool encendido;
    int velocidad;      // 0 (apagado) a 3
    bool oscilando;
public:
    static const int VEL_MAXIMA = 3;

    Ventilador() : marca("Generico"), encendido(false), velocidad(0), oscilando(false) {}
    Ventilador(string m, int v, bool osc) : marca(m), encendido(v > 0), velocidad(v), oscilando(osc && v > 0) {}

    string getMarca() const { return marca; }
    bool getEncendido() const { return encendido; }
    int getVelocidad() const { return velocidad; }
    bool getOscilando() const { return oscilando; }

    void setMarca(string m) { marca = m; }
    void setEncendido(bool e) {
        encendido = e;
        if (e && velocidad == 0) velocidad = 1;
        if (!e) { velocidad = 0; oscilando = false; }
    }
    void setVelocidad(int v) {
        velocidad = (v < 0) ? 0 : (v > VEL_MAXIMA ? VEL_MAXIMA : v);
        encendido = (velocidad > 0);
        if (!encendido) oscilando = false;
    }
    void setOscilando(bool o) { oscilando = o && encendido; }

    void encender() {
        if (encendido) cout << "El ventilador ya esta encendido.\n";
        else { setEncendido(true); cout << "Ventilador encendido en velocidad 1.\n"; }
    }
    void apagar() {
        if (!encendido) cout << "El ventilador ya esta apagado.\n";
        else { setEncendido(false); cout << "Ventilador apagado.\n"; }
    }
    void aumentarVelocidad() {
        if (!encendido) { cout << "Enciende el ventilador primero.\n"; return; }
        if (velocidad == VEL_MAXIMA) cout << "Ya esta en la velocidad maxima (" << VEL_MAXIMA << ").\n";
        else { velocidad++; cout << "Velocidad: " << velocidad << "\n"; }
    }
    void disminuirVelocidad() {
        if (!encendido) { cout << "El ventilador esta apagado.\n"; return; }
        if (velocidad == 1) cout << "Ya esta en la velocidad minima. Usa apagar() para detenerlo.\n";
        else { velocidad--; cout << "Velocidad: " << velocidad << "\n"; }
    }
    void alternarOscilacion() {
        if (!encendido) { cout << "Enciende el ventilador primero.\n"; return; }
        oscilando = !oscilando;
        cout << "Oscilacion " << (oscilando ? "activada" : "desactivada") << ".\n";
    }
    void mostrarInfo() const {
        cout << "Ventilador " << marca << " - " << (encendido ? "Encendido" : "Apagado")
             << " - Velocidad: " << velocidad << " - Oscilacion: " << (oscilando ? "Si" : "No") << "\n";
    }
};

void menuVentilador(Ventilador objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Ventilador " + to_string(i + 1) + ": " + objs[i].getMarca();
        int idx = elegirObjeto("VENTILADOR", et, n);
        if (idx < 0) return;
        Ventilador& o = objs[idx];
        int op;
        do {
            cout << "\n--- VENTILADOR " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set marca\n 3. Set encendido\n 4. Set velocidad\n 5. Set oscilando\n"
                 << " 6. Metodo encender()\n 7. Metodo apagar()\n"
                 << " 8. Metodo aumentarVelocidad()\n 9. Metodo disminuirVelocidad()\n"
                 << " 10. Metodo alternarOscilacion()\n 11. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 11);
            switch (op) {
                case 1:
                    cout << "Marca: " << o.getMarca() << "\nEncendido: " << sn(o.getEncendido())
                         << "\nVelocidad: " << o.getVelocidad() << "\nOscilando: " << sn(o.getOscilando()) << "\n";
                    break;
                case 2: o.setMarca(leerTexto("Nueva marca: ")); break;
                case 3: o.setEncendido(leerBool("Esta encendido?")); break;
                case 4: o.setVelocidad(leerEntero("Nueva velocidad (0-3): ", 0, 3)); break;
                case 5: o.setOscilando(leerBool("Esta oscilando?")); break;
                case 6: o.encender(); break;
                case 7: o.apagar(); break;
                case 8: o.aumentarVelocidad(); break;
                case 9: o.disminuirVelocidad(); break;
                case 10: o.alternarOscilacion(); break;
                case 11: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
class RelojDigital {
private:
    int horas;          // 0 - 23
    int minutos;        // 0 - 59
    int segundos;       // 0 - 59
    bool formato24h;
public:
    RelojDigital() : horas(0), minutos(0), segundos(0), formato24h(true) {}
    RelojDigital(int h, int m, int s, bool f24) : horas(h), minutos(m), segundos(s), formato24h(f24) {}

    int getHoras() const { return horas; }
    int getMinutos() const { return minutos; }
    int getSegundos() const { return segundos; }
    bool getFormato24h() const { return formato24h; }

    void setHoras(int h) { horas = (h < 0) ? 0 : (h > 23 ? 23 : h); }
    void setMinutos(int m) { minutos = (m < 0) ? 0 : (m > 59 ? 59 : m); }
    void setSegundos(int s) { segundos = (s < 0) ? 0 : (s > 59 ? 59 : s); }
    void setFormato24h(bool f) { formato24h = f; }

    string horaComoTexto() const {
        int h = horas;
        string sufijo = "";
        if (!formato24h) {
            sufijo = (horas >= 12) ? " PM" : " AM";
            h = horas % 12;
            if (h == 0) h = 12;
        }
        string r = "";
        r += (h < 10 ? "0" : "") + to_string(h) + ":";
        r += (minutos < 10 ? "0" : "") + to_string(minutos) + ":";
        r += (segundos < 10 ? "0" : "") + to_string(segundos);
        return r + sufijo;
    }
    void mostrarHora() const { cout << "Hora actual: " << horaComoTexto() << "\n"; }
    void avanzarSegundos(int n) {
        long total = (long)horas * 3600 + minutos * 60 + segundos + n;
        total %= 86400;
        if (total < 0) total += 86400;
        horas = (int)(total / 3600);
        minutos = (int)((total % 3600) / 60);
        segundos = (int)(total % 60);
        cout << "Se avanzaron " << n << " segundo(s). ";
        mostrarHora();
    }
    void ajustarHora(int h, int m, int s) {
        setHoras(h); setMinutos(m); setSegundos(s);
        cout << "Hora ajustada. ";
        mostrarHora();
    }
    void cambiarFormato() {
        formato24h = !formato24h;
        cout << "Formato cambiado a " << (formato24h ? "24 horas" : "12 horas") << ". ";
        mostrarHora();
    }
};

void menuReloj(RelojDigital objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Reloj " + to_string(i + 1) + ": " + objs[i].horaComoTexto();
        int idx = elegirObjeto("RELOJ DIGITAL", et, n);
        if (idx < 0) return;
        RelojDigital& o = objs[idx];
        int op;
        do {
            cout << "\n--- RELOJ " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set horas\n 3. Set minutos\n 4. Set segundos\n 5. Set formato24h\n"
                 << " 6. Metodo mostrarHora()\n 7. Metodo avanzarSegundos()\n"
                 << " 8. Metodo ajustarHora()\n 9. Metodo cambiarFormato()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 9);
            switch (op) {
                case 1:
                    cout << "Horas: " << o.getHoras() << "\nMinutos: " << o.getMinutos()
                         << "\nSegundos: " << o.getSegundos() << "\nFormato 24h: " << sn(o.getFormato24h()) << "\n";
                    break;
                case 2: o.setHoras(leerEntero("Nuevas horas (0-23): ", 0, 23)); break;
                case 3: o.setMinutos(leerEntero("Nuevos minutos (0-59): ", 0, 59)); break;
                case 4: o.setSegundos(leerEntero("Nuevos segundos (0-59): ", 0, 59)); break;
                case 5: o.setFormato24h(leerBool("Usar formato de 24 horas?")); break;
                case 6: o.mostrarHora(); break;
                case 7: o.avanzarSegundos(leerEntero("Segundos a avanzar: ", 0, 1000000)); break;
                case 8: {
                    int h = leerEntero("Horas (0-23): ", 0, 23);
                    int m = leerEntero("Minutos (0-59): ", 0, 59);
                    int s = leerEntero("Segundos (0-59): ", 0, 59);
                    o.ajustarHora(h, m, s);
                    break;
                }
                case 9: o.cambiarFormato(); break;
            }
        } while (op != 0);
    }
}
 
class Cafetera {
private:
    string marca;
    bool encendida;
    int nivelAgua;          // ml (max 1000)
    int cafeGramos;         // g  (max 100)
    int temperatura;        // grados Celsius
public:
    static const int AGUA_MAXIMA = 1000;
    static const int CAFE_MAXIMO = 100;
    static const int AGUA_POR_TAZA = 200;
    static const int CAFE_POR_TAZA = 15;

    Cafetera() : marca("Generica"), encendida(false), nivelAgua(0), cafeGramos(0), temperatura(25) {}
    Cafetera(string m, bool e, int a, int c, int t)
        : marca(m), encendida(e), nivelAgua(a), cafeGramos(c), temperatura(t) {}

    string getMarca() const { return marca; }
    bool getEncendida() const { return encendida; }
    int getNivelAgua() const { return nivelAgua; }
    int getCafeGramos() const { return cafeGramos; }
    int getTemperatura() const { return temperatura; }

    void setMarca(string m) { marca = m; }
    void setEncendida(bool e) { encendida = e; temperatura = e ? 92 : 25; }
    void setNivelAgua(int a) { nivelAgua = (a < 0) ? 0 : (a > AGUA_MAXIMA ? AGUA_MAXIMA : a); }
    void setCafeGramos(int c) { cafeGramos = (c < 0) ? 0 : (c > CAFE_MAXIMO ? CAFE_MAXIMO : c); }
    void setTemperatura(int t) { temperatura = (t < 0) ? 0 : (t > 100 ? 100 : t); }

    void encender() {
        if (encendida) cout << "La cafetera ya esta encendida.\n";
        else { setEncendida(true); cout << "Cafetera encendida. Calentando a " << temperatura << " C.\n"; }
    }
    void apagar() {
        if (!encendida) cout << "La cafetera ya esta apagada.\n";
        else { setEncendida(false); cout << "Cafetera apagada.\n"; }
    }
    void llenarAgua(int ml) {
        setNivelAgua(nivelAgua + ml);
        cout << "Deposito de agua: " << nivelAgua << " / " << AGUA_MAXIMA << " ml\n";
    }
    void agregarCafe(int gramos) {
        setCafeGramos(cafeGramos + gramos);
        cout << "Cafe molido: " << cafeGramos << " / " << CAFE_MAXIMO << " g\n";
    }
    void prepararCafe() {
        if (!encendida) { cout << "Enciende la cafetera primero.\n"; return; }
        if (nivelAgua < AGUA_POR_TAZA) { cout << "Falta agua (se necesitan " << AGUA_POR_TAZA << " ml).\n"; return; }
        if (cafeGramos < CAFE_POR_TAZA) { cout << "Falta cafe (se necesitan " << CAFE_POR_TAZA << " g).\n"; return; }
        nivelAgua -= AGUA_POR_TAZA;
        cafeGramos -= CAFE_POR_TAZA;
        cout << "Tu cafe esta listo! Agua restante: " << nivelAgua << " ml, cafe restante: " << cafeGramos << " g.\n";
    }
    void mostrarInfo() const {
        cout << "Cafetera " << marca << " - " << (encendida ? "Encendida" : "Apagada")
             << " - Agua: " << nivelAgua << " ml - Cafe: " << cafeGramos << " g - Temp: " << temperatura << " C\n";
    }
};

void menuCafetera(Cafetera objs[], int n) {
    while (true) {
        string et[3];
        for (int i = 0; i < n; i++) et[i] = "Cafetera " + to_string(i + 1) + ": " + objs[i].getMarca();
        int idx = elegirObjeto("CAFETERA", et, n);
        if (idx < 0) return;
        Cafetera& o = objs[idx];
        int op;
        do {
            cout << "\n--- CAFETERA " << (idx + 1) << " ---\n"
                 << " 1. Get: consultar todos los atributos\n"
                 << " 2. Set marca\n 3. Set encendida\n 4. Set nivelAgua\n 5. Set cafeGramos\n 6. Set temperatura\n"
                 << " 7. Metodo encender()\n 8. Metodo apagar()\n"
                 << " 9. Metodo llenarAgua()\n 10. Metodo agregarCafe()\n"
                 << " 11. Metodo prepararCafe()\n 12. Metodo mostrarInfo()\n"
                 << " 0. Elegir otro objeto\n";
            op = leerEntero("Opcion: ", 0, 12);
            switch (op) {
                case 1:
                    cout << "Marca: " << o.getMarca() << "\nEncendida: " << sn(o.getEncendida())
                         << "\nNivel de agua: " << o.getNivelAgua() << " ml\nCafe: " << o.getCafeGramos()
                         << " g\nTemperatura: " << o.getTemperatura() << " C\n";
                    break;
                case 2: o.setMarca(leerTexto("Nueva marca: ")); break;
                case 3: o.setEncendida(leerBool("Esta encendida?")); break;
                case 4: o.setNivelAgua(leerEntero("Nuevo nivel de agua (0-1000 ml): ", 0, 1000)); break;
                case 5: o.setCafeGramos(leerEntero("Nuevos gramos de cafe (0-100): ", 0, 100)); break;
                case 6: o.setTemperatura(leerEntero("Nueva temperatura (0-100 C): ", 0, 100)); break;
                case 7: o.encender(); break;
                case 8: o.apagar(); break;
                case 9: o.llenarAgua(leerEntero("Mililitros a agregar: ", 1, 1000)); break;
                case 10: o.agregarCafe(leerEntero("Gramos a agregar: ", 1, 100)); break;
                case 11: o.prepararCafe(); break;
                case 12: o.mostrarInfo(); break;
            }
        } while (op != 0);
    }
}
 
int main() {
    const int N = 3;
    // Objeto 1 y 2: constructor con parametros | Objeto 3: constructor por defecto
    Libro libros[N] = {
        Libro("Cien anos de soledad", "Gabriel Garcia Marquez", 471, true),
        Libro("El principito", "Antoine de Saint-Exupery", 96, true),
        Libro()
    };
    Automovil autos[N] = {
        Automovil("Toyota", "Corolla", 0, false),
        Automovil("Nissan", "Versa", 60, true),
        Automovil()
    };
    Alumno alumnos[N] = {
        Alumno("Ana Lopez", "A01234567", "Ing. en Sistemas", 4, 9.2, 6),
        Alumno("Luis Martinez", "A01765432", "Ing. Industrial", 2, 6.5, 3),
        Alumno()
    };
    CuentaBancaria cuentas[N] = {
        CuentaBancaria("0012345678", "Maria Gonzalez", 15000.50),
        CuentaBancaria("0098765432", "Carlos Ramirez", 2300.00),
        CuentaBancaria()
    };
    Mascota mascotas[N] = {
        Mascota("Firulais", "Perro", 3, 80),
        Mascota("Michi", "Gato", 5, 40),
        Mascota()
    };
    Celular celulares[N] = {
        Celular("Samsung", "Galaxy A54", 85, true),
        Celular("Apple", "iPhone 13", 20, false),
        Celular()
    };
    Producto productos[N] = {
        Producto("P001", "Cuaderno profesional", 45.50, 100),
        Producto("P002", "Mochila escolar", 320.00, 15),
        Producto()
    };
    Ventilador ventiladores[N] = {
        Ventilador("Lasko", 2, true),
        Ventilador("Taurus", 0, false),
        Ventilador()
    };
    RelojDigital relojes[N] = {
        RelojDigital(10, 30, 45, true),
        RelojDigital(15, 59, 50, false),
        RelojDigital()
    };
    Cafetera cafeteras[N] = {
        Cafetera("Oster", true, 800, 60, 92),
        Cafetera("Mr. Coffee", false, 300, 20, 25),
        Cafetera()
    };

    int opcion;
    do {
        cout << "\n==========================================\n"
             << "   TAREA 1 - PROGRAMACION ORIENTADA A OBJETOS\n"
             << "==========================================\n"
             << " Selecciona la clase con la que quieres interactuar:\n"
             << "  1. Libro\n  2. Automovil\n  3. Alumno\n  4. Cuenta bancaria\n  5. Mascota\n"
             << "  6. Celular\n  7. Producto\n  8. Ventilador\n  9. Reloj digital\n 10. Cafetera\n"
             << "  0. Salir\n";
        opcion = leerEntero("Opcion: ", 0, 10);
        switch (opcion) {
            case 1: menuLibro(libros, N); break;
            case 2: menuAutomovil(autos, N); break;
            case 3: menuAlumno(alumnos, N); break;
            case 4: menuCuenta(cuentas, N); break;
            case 5: menuMascota(mascotas, N); break;
            case 6: menuCelular(celulares, N); break;
            case 7: menuProducto(productos, N); break;
            case 8: menuVentilador(ventiladores, N); break;
            case 9: menuReloj(relojes, N); break;
            case 10: menuCafetera(cafeteras, N); break;
        }
    } while (opcion != 0);

    cout << "\nHasta luego!\n";
    return 0;
}