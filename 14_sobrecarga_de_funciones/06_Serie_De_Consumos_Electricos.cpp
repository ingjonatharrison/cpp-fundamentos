#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>
#include <sstream>
using namespace std;

class SerieConsumo {
private:
    int dias;        
    int* valores;    

    static void validarDias(int n) {
        if (n <= 0) throw invalid_argument("el numero de dias debe ser mayor que 0");
    }
    static void validarValor(int v) {
        if (v < 0) throw invalid_argument("los consumos no pueden ser negativos");
    }

public:
    explicit SerieConsumo(int n = 1) : dias(0), valores(0) {
        validarDias(n);
        valores = new int[n];
        dias = n;
        for (int i = 0; i < dias; i++) valores[i] = 0;
    }
    
    SerieConsumo(const SerieConsumo& otra) : dias(otra.dias), valores(new int[otra.dias]) {
        for (int i = 0; i < dias; i++) valores[i] = otra.valores[i];
    }

    ~SerieConsumo() { delete[] valores; }
    
    void establecer(int indice, int valor) {
        validarValor(valor);
        (*this)[indice] = valor;              
    }
    
    void establecer(const int* datos, int cantidad) {
        if (cantidad != dias) throw invalid_argument("la cantidad de datos no coincide con los dias");
        for (int i = 0; i < cantidad; i++) validarValor(datos[i]);
        for (int i = 0; i < cantidad; i++) valores[i] = datos[i];
    }
    
    void establecer(int valor) {
        validarValor(valor);
        for (int i = 0; i < dias; i++) valores[i] = valor;
    }
    
    int consultar(int indice) const { return (*this)[indice]; }
    long long consultar(int desde, int hasta) const {
        if (desde < 0 || hasta >= dias || desde > hasta)
            throw out_of_range("periodo fuera de rango");
        long long suma = 0;
        for (int i = desde; i <= hasta; i++) suma += valores[i];
        return suma;
    }

    long long total() const { return consultar(0, dias - 1); }
    int numeroDias() const { return dias; }
    const int* datos() const { return valores; }  
    
    SerieConsumo& operator=(const SerieConsumo& otra) {
        if (this == &otra) return *this;          
        int* nuevo = new int[otra.dias];           
        for (int i = 0; i < otra.dias; i++) nuevo[i] = otra.valores[i];
        delete[] valores;
        valores = nuevo;
        dias = otra.dias;
        return *this;                             
    }
    
    SerieConsumo operator+(const SerieConsumo& otra) const {
        if (dias != otra.dias) throw invalid_argument("no se pueden sumar series de distinta dimension");
        SerieConsumo r(dias);
        for (int i = 0; i < dias; i++) {
            long long s = (long long)valores[i] + otra.valores[i];
            if (s > numeric_limits<int>::max()) throw overflow_error("desbordamiento en la suma");
            r.valores[i] = (int)s;
        }
        return r;
    }
    
    SerieConsumo operator*(int factor) const {
        if (factor < 0) throw invalid_argument("el factor no puede ser negativo");
        SerieConsumo r(dias);
        for (int i = 0; i < dias; i++) {
            long long p = (long long)valores[i] * factor;
            if (p > numeric_limits<int>::max()) throw overflow_error("desbordamiento en el producto");
            r.valores[i] = (int)p;
        }
        return r;
    }
    
    friend SerieConsumo operator*(int factor, const SerieConsumo& s) { return s * factor; }
    
    bool operator==(const SerieConsumo& otra) const {
        if (dias != otra.dias) return false;
        for (int i = 0; i < dias; i++)
            if (valores[i] != otra.valores[i]) return false;
        return true;
    }
    bool operator!=(const SerieConsumo& otra) const { return !(*this == otra); }
    
    int& operator[](int i) {
        if (i < 0 || i >= dias) throw out_of_range("indice fuera de rango");
        return valores[i];
    }
    const int& operator[](int i) const {
        if (i < 0 || i >= dias) throw out_of_range("indice fuera de rango");
        return valores[i];
    }
    
    friend ostream& operator<<(ostream& os, const SerieConsumo& s) {
        os << s.dias;
        for (int i = 0; i < s.dias; i++) os << ' ' << s.valores[i];
        return os;
    }
    
    friend istream& operator>>(istream& is, SerieConsumo& s) {
        int n;
        if (!(is >> n)) return is;
        if (n <= 0) { is.setstate(ios::failbit); return is; }
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            if (!(is >> temp[i])) return is;                     
            if (temp[i] < 0) { is.setstate(ios::failbit); return is; }
        }
        SerieConsumo nueva(n);
        for (int i = 0; i < n; i++) nueva.valores[i] = temp[i];
        s = nueva;
        return is;
    }
};

static int pasadas = 0, falladas = 0;

void verificar(const string& nombre, bool ok) {
    cout << (ok ? "[OK]    " : "[FALLO] ") << nombre << endl;
    if (ok) pasadas++; else falladas++;
}

template <typename Excepcion, typename F>
bool lanza(F f) {
    try { f(); } catch (const Excepcion&) { return true; } catch (...) { return false; }
    return false;
}

void ejecutarPruebas() {
    pasadas = falladas = 0;
    cout << "\n===== PRUEBAS MINIMAS =====\n";

    // Construcción
    SerieConsumo a(3);
    bool ceros = (a.numeroDias() == 3 && a[0] == 0 && a[1] == 0 && a[2] == 0);
    verificar("Construccion: tamano 3 y contenido en 0", ceros);
    verificar("Construccion: tamano 0 rechazado", lanza<invalid_argument>([] { SerieConsumo x(0); }));
    verificar("Construccion: tamano negativo rechazado", lanza<invalid_argument>([] { SerieConsumo x(-4); }));

    int d1[] = {10, 20, 30};
    a.establecer(d1, 3);                 
    a.establecer(1, 25);                 
    verificar("Sobrecarga establecer(arreglo) y establecer(indice,valor)", a[0] == 10 && a[1] == 25 && a[2] == 30);
    verificar("Consulta de periodo consultar(0,1) = 35", a.consultar(0, 1) == 35);
    verificar("Valor negativo rechazado", lanza<invalid_argument>([&] { a.establecer(0, -1); }));
    
    SerieConsumo b(a);
    b[0] = 999;
    verificar("Copia: modificar la copia no altera el original", a[0] == 10 && b[0] == 999);
    verificar("Copia: arreglos en direcciones distintas", a.datos() != b.datos());
    
    SerieConsumo c = a;
    c = c;
    verificar("Autoasignacion: A = A conserva el contenido", c == a);
    SerieConsumo e(7), f(2);
    e = f = a;
    verificar("Asignacion encadenada e = f = a", e == a && f == a && e.datos() != a.datos());
    
    int d2[] = {1, 2, 3};
    SerieConsumo g(3);
    g.establecer(d2, 3);
    SerieConsumo h = a + g;
    verificar("Suma compatible: {10,25,30}+{1,2,3}={11,27,33}", h[0] == 11 && h[1] == 27 && h[2] == 33);
    verificar("Suma incompatible detectada", lanza<invalid_argument>([&] { SerieConsumo z(5); SerieConsumo r = a + z; (void)r; }));

    SerieConsumo p1 = a * 2, p2 = 2 * a;
    verificar("Producto: A*2 == 2*A", p1 == p2);
    verificar("Producto: valores {20,50,60}", p1[0] == 20 && p1[1] == 50 && p1[2] == 60);
    verificar("Producto: factor 0 da ceros", (a * 0) == SerieConsumo(3));
    verificar("Producto: factor negativo rechazado", lanza<invalid_argument>([&] { SerieConsumo r = a * -1; (void)r; }));
    verificar("Producto: desbordamiento detectado", lanza<overflow_error>([&] { SerieConsumo r = a * 2000000000; (void)r; }));

    SerieConsumo i1 = a;
    SerieConsumo i2 = a;
    i2[2] += 1;
    verificar("Igualdad: copias iguales", i1 == a && !(i1 != a));
    verificar("Igualdad: difieren en una componente", i2 != a);
    verificar("Igualdad: distinta dimension => distintas", SerieConsumo(2) != SerieConsumo(3));

    a[0] = 77;
    verificar("Subindice: consulta y modificacion validas", a[0] == 77 && a.consultar(0) == 77);
    verificar("Subindice: indice -1 controlado", lanza<out_of_range>([&] { (void)a[-1]; }));
    verificar("Subindice: indice == dias controlado", lanza<out_of_range>([&] { (void)a[3]; }));
    verificar("Subindice: limites 0 y dias-1 validos", a[0] == 77 && a[2] == 30);
    a[0] = 10;

    istringstream in("4 5 6 7 8   2 1 2   3 9");
    SerieConsumo l, m, n;
    in >> l >> m;
    verificar("Flujos >>: captura de dos series", l.numeroDias() == 4 && l[3] == 8 && m.numeroDias() == 2);
    in >> n;
    verificar("Flujos >>: captura insuficiente activa failbit", in.fail());
    ostringstream out;
    out << m << " | " << l;                  
    verificar("Flujos <<: encadenado -> \"2 1 2 | 4 5 6 7 8\"", out.str() == "2 1 2 | 4 5 6 7 8");

    SerieConsumo o1 = a, o2 = g;
    SerieConsumo res = o1 + o2;
    SerieConsumo res2 = o1 * 3;
    (void)res; (void)res2;
    verificar("Persistencia: + y * no alteran los operandos", o1 == a && o2 == g);

    cout << "Resultado: " << pasadas << " pasadas, " << falladas << " falladas.\n";
}

int leerEntero(const string& msg) {
    int v;
    cout << msg;
    while (!(cin >> v)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada no valida. " << msg;
    }
    return v;
}

int elegirEquipo(const vector<SerieConsumo>& eq) {
    if (eq.empty()) { cout << "No hay equipos registrados.\n"; return -1; }
    int i = leerEntero("Numero de equipo (0-" + to_string(eq.size() - 1) + "): ");
    if (i < 0 || i >= (int)eq.size()) { cout << "Equipo inexistente.\n"; return -1; }
    return i;
}

void mostrarMenu() {
    cout << "\n===== SERIES DE CONSUMO ELECTRICO =====\n"
         << "1. Registrar equipo (captura con >>: n v1 ... vn)\n"
         << "2. Mostrar equipos (<<)\n"
         << "3. Consumo total y numero de dias\n"
         << "4. Consultar / modificar un dia ([])\n"
         << "5. Sumar dos equipos (+)\n"
         << "6. Multiplicar por factor (serie*f y f*serie)\n"
         << "7. Comparar dos equipos (==, !=)\n"
         << "8. Copiar un equipo (constructor de copia) y asignar (=)\n"
         << "9. Consumo de un periodo (consultar(desde,hasta))\n"
         << "10. Ejecutar pruebas automaticas\n"
         << "0. Salir\n";
}

int main() {
    vector<SerieConsumo> equipos;
    int op;
    do {
        mostrarMenu();
        op = leerEntero("Opcion: ");
        try {
            switch (op) {
            case 1: {
                SerieConsumo s;
                cout << "Capture: dias y luego los consumos (enteros >= 0): ";
                if (cin >> s) { equipos.push_back(s); cout << "Equipo " << equipos.size() - 1 << " registrado.\n"; }
                else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Captura invalida o insuficiente; no se registro nada.\n";
                }
                break;
            }
            case 2:
                if (equipos.empty()) cout << "Sin equipos.\n";
                for (size_t i = 0; i < equipos.size(); i++) cout << "Equipo " << i << ": " << equipos[i] << endl;
                break;
            case 3: {
                int i = elegirEquipo(equipos);
                if (i >= 0) cout << "Dias: " << equipos[i].numeroDias() << "  Total: " << equipos[i].total() << endl;
                break;
            }
            case 4: {
                int i = elegirEquipo(equipos);
                if (i < 0) break;
                int dia = leerEntero("Indice del dia: ");
                cout << "Valor actual: " << equipos[i][dia] << endl;       
                if (leerEntero("Modificar? (1=si, 0=no): ") == 1) {
                    int nuevo = leerEntero("Nuevo valor: ");
                    equipos[i].establecer(dia, nuevo);
                    cout << "Actualizado: " << equipos[i] << endl;
                }
                break;
            }
            case 5: {
                int i = elegirEquipo(equipos); if (i < 0) break;
                int j = elegirEquipo(equipos); if (j < 0) break;
                cout << "Resultado: " << equipos[i] + equipos[j] << endl;
                break;
            }
            case 6: {
                int i = elegirEquipo(equipos); if (i < 0) break;
                int f = leerEntero("Factor entero >= 0: ");
                cout << "serie*factor: " << equipos[i] * f << endl;
                cout << "factor*serie: " << f * equipos[i] << endl;
                break;
            }
            case 7: {
                int i = elegirEquipo(equipos); if (i < 0) break;
                int j = elegirEquipo(equipos); if (j < 0) break;
                cout << "== : " << (equipos[i] == equipos[j] ? "verdadero" : "falso") << endl;
                cout << "!= : " << (equipos[i] != equipos[j] ? "verdadero" : "falso") << endl;
                break;
            }
            case 8: {
                int i = elegirEquipo(equipos); if (i < 0) break;
                SerieConsumo copia(equipos[i]);                // constructor de copia
                equipos.push_back(copia);
                cout << "Copia registrada como equipo " << equipos.size() - 1 << ".\n";
                if (equipos.size() >= 2) {
                    equipos[0] = equipos.back();               // asignacion a objeto existente
                    cout << "Equipo 0 sobrescrito por asignacion: " << equipos[0] << endl;
                }
                break;
            }
            case 9: {
                int i = elegirEquipo(equipos); if (i < 0) break;
                int d = leerEntero("Dia inicial: ");
                int h = leerEntero("Dia final: ");
                cout << "Consumo del periodo: " << equipos[i].consultar(d, h) << endl;
                break;
            }
            case 10: ejecutarPruebas(); break;
            case 0: cout << "Hasta luego.\n"; break;
            default: cout << "Opcion no valida.\n";
            }
        } catch (const exception& ex) {
            cout << "Operacion invalida: " << ex.what() << endl;
        }
    } while (op != 0);
    return 0;
}