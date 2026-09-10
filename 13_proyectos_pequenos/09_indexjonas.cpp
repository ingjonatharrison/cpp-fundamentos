#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#define Max_Movie 20 //Maximo de peliculas que se pueden almacenar en cartelera
#define Max_Salas 8 //Solo vamos a tener 8 salas en total
#define PRICE_VO 62 //Precio de los boletos
#define ALL_SENT 50 //Maximo de asientos por sala

using namespace std;

//Estructuras, uniones y enumeraciones
enum Idiomas{
    Espanol = 1,
    Ingles,
    Frances,
    Italiano
};

enum Generos{
    Romance = 1,
    Drama,
    Comedia,
    Accion
};

struct Pelicula{
    int id;
    char Nom[30];
    double DuMOVIE;
    Idiomas IDM;
    bool SUB;
    bool Tree;
    Generos GEN;
    int EdMin;
    int Sala;
    int horario;
    bool Lleno;
};

struct Cliente{
    char NOM_C[30];
};

struct FVenta{
    Cliente cliente;
    int boletos;
    float total;
};

struct Sala{
    int FI,COL;
    int **matriz;
};

struct Producto{
	int id, stock;
	char nombreP[30], categoria;
	float precio;
	bool activo;
};

struct Venta{
	int cantidad;
	float total;
};

//Prototipos
void CrearCascaron();
void Menu(int *op);
void PeliculasHorarios();
void CompraDeVoletos(int TOTAL_S[Max_Salas], Sala sala[]);
void ModiSala(int AUX_SALA, Sala sala[]);

//CHRIs_PART_Prototipes
void AltaDeProductos(int *N, Producto *p);
void BajaDeProductos(Producto *p, int *N);
void ModificarProducto(Producto *p, int *N);
bool BuscarProducto(char nombre[30], Producto *p, int *N);
void MostrarTodo(Producto *p, int *N);
void Inventario(Producto *p, int *N);
void A_Inventario(Producto *p, int *N);
void MostrarCompra();
void RealizarVenta(Producto *p, Venta v, int *N);

//UGALDEs_PART_Prototipes
void mostrar_ventas();
void Tvendido();
void IVA();
void corte();

int main (){
    int op, n=0, *N=&n;;
    Sala sala[Max_Salas];
    fstream FILE_MOVIE;
    fstream TICKET_FILE;
    
    Producto p[100];
    Venta v;

    for( int i = 0; i < Max_Salas; i++ ){
        sala[i].matriz = NULL;
        sala[i].FI= 0;
        sala[i].COL= 0;
    }

    int i = 0;
    int TOTAL_S[Max_Salas] = {0,0,0,0,0,0,0,0};

    TICKET_FILE.open("Ticket.txt", ios::out);
    if(!TICKET_FILE){
        cerr << "Archivo tiket con error, checa eso" << endl;
        return 1;
    }
    TICKET_FILE.close();

    do{
        Menu(&op);

        system("cls");
        switch (op) {
        case 0: cout << "Gracias por usar"; break;
        case 1: CompraDeVoletos(TOTAL_S, sala); break;
        case 2:{
            do{
                cout<<"\n======= BIENVENIDO A LA CAFETERIA Y DULCERIA =======\n"<<endl;
                cout<<"1. Dar de alta un producto"<<endl;
                cout<<"2. Dar de baja un producto"<<endl;
                cout<<"3. Modificar un producto"<<endl;
                cout<<"4. Buscar un producto"<<endl;
                cout<<"5. Mostrar todos los productos"<<endl;
                cout<<"6. Inventario productos"<<endl;
                cout<<"7. Abastecer inventario"<<endl;
                cout<<"8. Compra de productos"<<endl;
                cout<<"9. Salir de la cafeteria y dulceria\n"<<endl;
                cout<<"Elige una de las opciones: ";
                cin>>op;
                cout<<endl;
                switch(op){
                    case 1:
                        AltaDeProductos(&n, p);
                        break;
                    case 2:
                        BajaDeProductos(p, &n);
                        break;
                    case 3:
                        ModificarProducto(p, &n);
                        break;
                    case 4:{
                        char nombre[30];
                        cout<<"Ingresa el nombre del producto que deseas buscar: ";
                        cin>>nombre;
                        int band=BuscarProducto(nombre, p, &n);
                        if (band==false){
                            cout<<"No tenemos ese producto"<<endl;
                        }
                        break;
                    }
                    case 5:
                        MostrarTodo(p, &n);
                        break;
                    case 6:
                        Inventario(p, &n);
                        break;
                    case 7:
                        A_Inventario(p, &n);
                        break;
                    case 8:
                        RealizarVenta(p, v, &n);
                        break;
                    case 9:
                        cout<<"Saliendo del apartado de Cafeteria y Dulceria"<<endl;
                        break;
                    default:
                        cout<<"Opcion incorrecta, vuelve a intentarlo"<<endl;
                        break;
                }
            }while(op!=9);
        }
        break;
        case 3: {
            do{
            cout<<"--------------------------------"<<endl;
            cout<<"MENU DE CAJAS-------------------"<<endl;
            cout<<"1.MOSTRAR VENTAS----------------"<<endl;
            cout<<"2.TOTAL DE VENTAS---------------"<<endl;
            cout<<"3.IVA ACOMULADO-----------------"<<endl;
            cout<<"4.CORTE DE CAJA-----------------"<<endl;
            cout<<"5.SALIR DEL SISTEMA DE CAJAS----"<<endl;
            cout<<"ELIGE LA OPCION QUE OCUPES------"<<endl;
            cin>>op;
            
            switch(op)
            {
                case 1:
                mostrar_ventas();
                break;
                case 2: Tvendido();
                break;
                case 3:	IVA();
                    break;
                case 4:corte();
                    break;
                case 5: cout<<"ADIOS.........."<<endl;
                break;
                default:cout<<"LA OPCION QUE PUSISTE NO SE ENCUENTRA EN EL MENU, PON UNA QUE SI APAREZCA POR FAVOR"<<endl;
            }
            }while(op!=5);
        }
        break;
        case 4: PeliculasHorarios(); break;
        case 5: CrearCascaron(); break;
        case 6: 
        int AUX_SALA, FI, COL;
        do{
            cout << "\nDime que sala editar/cambiar" << endl; cin >> AUX_SALA;
            if(AUX_SALA > Max_Salas || AUX_SALA < 0) cout << "\nEl maximo de salas es: " << Max_Salas 
            << " Volver a intentar\n";
        }while(AUX_SALA > Max_Salas || AUX_SALA < 0);
        ModiSala(AUX_SALA - 1, sala); 
        break;
        default: cerr << "Valor invalido" << endl; break;
        }
    }while(op != 0);

    return 0;
}

//Funciones 
void CrearCascaron(){
    fstream FILE_MOVIE;
    FILE_MOVIE.open("Cartelera.dat", ios::binary | ios::out);
    if(!FILE_MOVIE){
        cerr << "No fue posible crear el archivo";
        return;
    }else{
        cout << "Archivo correcto" << endl;
    }

    Pelicula MOVIE_INF = {0,"",0,(Idiomas)0,false,false,(Generos)0,0,0,0,false};//
    for( int i = 0; i < Max_Movie; i++ ) { FILE_MOVIE.write( reinterpret_cast<char*>(&MOVIE_INF), sizeof(MOVIE_INF)); }
    FILE_MOVIE.close();
}

void Menu(int *op){
    cout << "\n\n=======================================\n\tMenu\n=======================================" << endl
    << "0.-Salir" << endl
    << "1.-Compra de voletos" << endl
    << "2.-Dulceria Y Cafeteria" << endl
    << "3.-Cajas" << endl
    << "4.-'Admin' Editar cartelera" << endl
    << "5.-'Admin' Crear cascaron/Limpiar cascaron" << endl
    << "6.-'Admin' Modificar tamano de sala" << endl //Usar malloc o calloc
    << "Opcion: "; cin >> *op;
}

void CompraDeVoletos(int TOTAL_S[Max_Salas], Sala sala[]){
    fstream TICKET_FILE;
    Pelicula MOVIE_INF;
    FVenta V;
    fstream FILE_MOVIE;
    bool KNOW_B;
    int Voletos, AUX_ID; //A lo mejor las usamos como punteros para hacer un ticket con las compras de voletos y de tiendas (Las partes de mis compañeros)

    FILE_MOVIE.open("Cartelera.dat", ios::binary | ios::in);

    cout << "\n=======================================\n\tMostrando cartelera\n=======================================" << endl;
    while( FILE_MOVIE.read( reinterpret_cast<char*> (&MOVIE_INF), sizeof(Pelicula)) ) {
        if( MOVIE_INF.Lleno != false ){
            cout << "\nID de Pelicula: " <<  MOVIE_INF.id
            << "\nNombre de la pelicula: " <<  MOVIE_INF.Nom
            << "\nDuracion de la pelicula(hrs): " << MOVIE_INF.DuMOVIE;
            cout << "\nIdioma de la pelicula: "; 
            switch(MOVIE_INF.IDM){ 
                case Espanol: cout << "Español"; break;
                case Ingles: cout << "Ingles"; break;
                case Frances: cout << "Frances"; break; 
                case Italiano: cout << "Italiano"; break;
                default: cout << "No especificado"; break;
            }
            cout << "\nSubtitulos en la pelicula: " << endl;
                if(MOVIE_INF.SUB==true) cout << "SI"; else cout << "NO";
                cout << "\n3D en la pelicula: " << endl;
                if(MOVIE_INF.Tree==true) cout << "SI"; else cout << "NO";
                cout << "\nGenero principal: ";
                switch(MOVIE_INF.GEN){ 
                case Romance: cout << "Romance"; break;
                case Drama: cout << "Drama"; break;
                case Comedia: cout << "Comedia"; break; 
                case Accion: cout << "Accion"; break;
                default: cout << "No especificado"; break;
            }
            cout << "\nEdad minima: " << MOVIE_INF.EdMin
            << "\nSala en la que esta: " << MOVIE_INF.Sala
            << "\nHorario(24 hrs): " <<  MOVIE_INF.horario << "\n";
        }
    }
    FILE_MOVIE.close();
    system("pause");
    FILE_MOVIE.open("Cartelera.dat", ios::binary | ios::in);

    cout << "\n=======================================\n\tCompra de voletos\n=======================================\n"
    << "\nPrecio de los boletos: $" << PRICE_VO;

    do{
        KNOW_B = false;

        FILE_MOVIE.clear();
        FILE_MOVIE.seekg(0);
        cout << "\nDame el ID de la pelicula: "; cin >> AUX_ID; //Por ahora solo se compra los boletos, se pueden sentar donde quieran
        while( FILE_MOVIE.read( reinterpret_cast<char*> (&MOVIE_INF), sizeof(Pelicula)) ) {
            if(MOVIE_INF.Lleno && MOVIE_INF.id == AUX_ID) {
                KNOW_B = true;
                break;
            }
        }
        if(!KNOW_B) cout << "No hay registro de una ID como el que ingresaste\n VOLVER A INGRESAR ";
    }while(!KNOW_B);

    FILE_MOVIE.close();

    do{
        cout << "\nBoletos comprados: " << TOTAL_S[MOVIE_INF.Sala - 1];
        cout << "\n Cuantos?: "; cin >> V.boletos;
        if(TOTAL_S[MOVIE_INF.Sala - 1] + V.boletos > ALL_SENT ){
            cout << "\nSon muchos voletos o la sala esta llena\n Volver a introducir: ";
        } else {
            cout << "\nRegistrando\n";
            TOTAL_S[MOVIE_INF.Sala - 1] = TOTAL_S[MOVIE_INF.Sala - 1] + V.boletos;
            break;
        }
    }while(TOTAL_S[MOVIE_INF.Sala - 1] + V.boletos > ALL_SENT);

    int F,C;

    cout << "\nFI = " << sala[MOVIE_INF.Sala - 1].FI;
    cout << "\nCOL = " << sala[MOVIE_INF.Sala - 1].COL << endl;

    TICKET_FILE.open("Ticket.txt", ios::out | ios::trunc);

    if(sala[MOVIE_INF.Sala - 1].FI == 0 && sala[MOVIE_INF.Sala - 1].COL == 0 ){
        cout << "\nSala no creada" << endl; return;
    } 

    for( int i = 0; i < V.boletos; i++ ){
        bool Ter = false;
        do{
            cout << "\nDame en que fila el voleto " << i + 1 << ": " << endl; cin >> F;
            cout << "Dame en que columa el voleto " << i + 1 << ": " << endl; cin >> C;


            
            if( F >= 0 && F < sala[MOVIE_INF.Sala - 1].FI && C >= 0 && C < sala[MOVIE_INF.Sala - 1].COL ){
                if( sala[MOVIE_INF.Sala - 1].matriz[F][C] == 0 ){
                    sala[MOVIE_INF.Sala - 1].matriz[F][C] = 1;
                    Ter = true;
                }
                else{
                    cout << "\nAsiento ocupado\n";
                }
            } else{
                cout << "\nFila o columna invalida\n";
            }
            
        }while( !Ter );
    }
    

    cin.ignore();
    cout << "\n Dame el nombre del Cliente: "; cin.getline(V.cliente.NOM_C,30);
    cout << "\n=======================================\n\tImprimiendo ticket\n=======================================\n" << endl;

    V.total = V.boletos * PRICE_VO;
    
    if(TICKET_FILE){
       TICKET_FILE << "=======================================" << endl
       << "\t\tTICKET" << endl
       << "=======================================" << endl
       << "|    NOMBRE DEL CLIENTE: " << V.cliente.NOM_C << endl
       << "|    NOMBRE DE LA PELICULA: " << MOVIE_INF.Nom << endl
       << "|    SALA: " << MOVIE_INF.Sala << endl
       << "|    HORARIO(FORMATO 24 HRS): " << MOVIE_INF.horario << endl
       << "|    PRECIO DE VOLETO: $" << PRICE_VO << endl
       << "|    VOLETOS COMPRADOS: " << V.boletos << endl
       << "---------------------------------------" << endl
       << "|    TOTAL A PAGAR: " << V.total << endl
       << "---------------------------------------" << endl;
    } 
    TICKET_FILE.close();
}

void PeliculasHorarios(){ 
    Pelicula MOVIE_INF;
    fstream FILE_MOVIE;   
    int pos = 0, Dat, op,AUX;

    cout << "\n=======================================\n\tQue hacer\n=======================================" << endl
    << "1.-Agregar una pelicula" << endl
    << "2.-Editar una pelicula" << endl
    << "Opcion: "; cin >> op;

    if(op == 1){
        system("cls");

        cout << "\n=======================================\n\tAGREGANDO PELICULA\n=======================================" << endl;

        MOVIE_INF.id = 2;
        
        FILE_MOVIE.open("Cartelera.dat", ios::binary | ios::in | ios::out);
        do{
            if( MOVIE_INF.id < 1 || MOVIE_INF.id > Max_Movie ) cerr << "El limite es de 20 en cartelera, reintenta\n";
            cout << "Posicion en la que pondra la pelicula: "; cin >> MOVIE_INF.id;
        }while( MOVIE_INF.id < 1 || MOVIE_INF.id > Max_Movie );
        
        FILE_MOVIE.seekg( (MOVIE_INF.id - 1) * sizeof(Pelicula) );
        Pelicula temporal;
        FILE_MOVIE.read( reinterpret_cast<char*>(&temporal), sizeof(Pelicula) );

        if(temporal.Lleno) {
            cout << "\nREGISTRO OCUPADO\n";
            FILE_MOVIE.close();
            return;
        }

        cin.ignore();//quedo un salto de lunea basura, para poder guardar

        cout << "|| Nombre de la pelicula: " << endl; cin.getline(MOVIE_INF.Nom,30);
        cout << "|| Duracion de la pelicula(hrs): " << endl; cin >> MOVIE_INF.DuMOVIE;

        int OPIDI;
        cout << "|| Idioma de la pelicula:\nEspañol = 1\nIngles = 2\nFrances = 3\nItaliano = 4\nOpcion: "; cin >> OPIDI;
        MOVIE_INF.IDM = (Idiomas)OPIDI;

        cout << "|| Subtitulos en la pelicula (1=si,2=no): " << endl; cin >> AUX;
        if(AUX==1) MOVIE_INF.SUB=true; else MOVIE_INF.SUB=false;
        cout << "|| 3D en la pelicula (1=si,2=no): " << endl; cin >> AUX;
        if(AUX==1) MOVIE_INF.Tree=true; else MOVIE_INF.Tree=false;

        int OPGEN;
        cout << "|| Genero principal:\nRomance = 1\nDrama = 2\nComedia = 3\nAccion = 4\nOpcion: "; cin >> OPGEN;
        MOVIE_INF.GEN = (Generos)OPGEN;

        cout << "|| Edad minima: " << endl; cin >> MOVIE_INF.EdMin;
        do{
            cout << "|| Sala en la que esta: " << endl; cin >> MOVIE_INF.Sala;
            if(MOVIE_INF.Sala < 1 || MOVIE_INF.Sala > Max_Salas )cout << "\n\tSolo hay " << Max_Salas << " salas disponibles";
        }while(MOVIE_INF.Sala < 1 || MOVIE_INF.Sala > Max_Salas);
        cout << "|| Horario(24 hrs): " << endl; cin >> MOVIE_INF.horario; MOVIE_INF.Lleno = true;

        FILE_MOVIE.seekp( (MOVIE_INF.id - 1) * sizeof(Pelicula) );
        FILE_MOVIE.write( reinterpret_cast<char*>(&MOVIE_INF),sizeof(Pelicula) );
        FILE_MOVIE.close();

        cout << "Guardado con exito" << endl;
        
        }else if(op == 2){
            pos = 2;
            FILE_MOVIE.open("Cartelera.dat", ios::binary | ios::in | ios::out);

            do{
                if( pos < 1 || pos > Max_Movie ) cout << "EL maximo de peliculas es 20 ";
                cout << "\nQue pelicula quieres cambiar (dame la posicion): "; cin >> pos;
            //verificamos que exista el archivo, sino lo creamos ... si esta el archivo tomar los datos a cambiar y hacer el cambio   
            }while ( pos < 1 || pos > Max_Movie );

            FILE_MOVIE.seekg( (pos - 1) * sizeof(Pelicula) );
            FILE_MOVIE.read( reinterpret_cast<char*>(&MOVIE_INF), sizeof(Pelicula) );

            if(!MOVIE_INF.Lleno) {
                cout << "\nREGISTRO VASIO\n";
                FILE_MOVIE.close();
                return;
            }
            
            do{
                cout << "\n\n=======================================\n\tQue dato quieres cambiar de la pelicula\n=======================================\n" << endl
                << "0.-Cancelar " << endl
                << "1.-Nombre de la pelicula" << endl
                << "2.-Duracion de la pelicula" << endl
                << "3.-Idioma de la pelicula" << endl
                << "4.-Subtitulos en la pelicula" << endl
                << "5.-3D en la pelicula" << endl
                << "6.-Genero principal" << endl
                << "7.-Edad minima" << endl
                << "8.-Sala en la que esta" << endl
                << "9.-Horario: " << endl
                << "Opcion: "; cin >> Dat;
                
                system("cls");

                if( Dat == 0 ){cout << "Cancelando operacion\n"; break;} 

                cout << "\n\n=======================================\n\tDATOS ACTUALES\n======================================="
                << "\n|| Nombre de la pelicula: " <<  MOVIE_INF.Nom
                << "\n|| Duracion de la pelicula(hrs): " << MOVIE_INF.DuMOVIE;
                cout << "\n|| Idioma de la pelicula: "; 
                switch(MOVIE_INF.IDM){ 
                    case 1: cout << "Español"; break;
                    case 2: cout << "Ingles"; break;
                    case 3: cout << "Frances"; break; 
                    case 4: cout << "Italiano"; break;
                }
                cout << "\n|| Subtitulos en la pelicula: " << endl;
                    if(MOVIE_INF.SUB==true) cout << "SI"; else cout << "NO";
                    cout << "\n|| 3D en la pelicula: " << endl;
                    if(MOVIE_INF.Tree==true) cout << "SI"; else cout << "NO";
                    cout << "\n|| Genero principal: ";
                    switch(MOVIE_INF.GEN){ 
                    case 1: cout << "Romance"; break;
                    case 2: cout << "Drama"; break;
                    case 3: cout << "Comedia"; break; 
                    case 4: cout << "Accion"; break;
                }
                cout << "\n|| Edad minima: " << MOVIE_INF.EdMin
                << "\n|| Sala en la que esta: " << MOVIE_INF.Sala
                << "\n|| Horario: " <<  MOVIE_INF.horario;

                switch (Dat) {
                    case 1: cin.ignore(); cout << "\n\n|| NUEVO Nombre de la pelicula: " << endl; cin.getline(MOVIE_INF.Nom,30); break;//registramos el dato y lo cambiamos
                    case 2: cout << "\n\n|| NUEVO Duracion de la pelicula(hrs): " << endl; cin >> MOVIE_INF.DuMOVIE; break;
                    case 3: 
                        int OPIDI;
                        cout << "|| NUEVO Idioma de la pelicula:\nEspañol = 1\nIngles = 2\nFrances = 3\nItaliano = 4\nOpcion: "; cin >> OPIDI;
                        MOVIE_INF.IDM = (Idiomas)OPIDI; 
                    break;
                    case 4: cout << "\n\n|| NUEVO Subtitulos en la pelicula (1=si,2=no): " << endl; cin >> AUX; if(AUX==1) MOVIE_INF.SUB=true; else MOVIE_INF.SUB=false; break;
                    case 5: cout << "\n\n|| NUEVO 3D en la pelicula (1=si,2=no): " << endl; cin >> AUX; if(AUX==1) MOVIE_INF.Tree=true; else MOVIE_INF.Tree=false; break;
                    case 6: 
                        int OPGEN;
                        cout << "|| Genero principal:\nRomance = 1\nDrama = 2\nComedia = 3\nAccion = 4\nOpcion: "; cin >> OPGEN;
                        MOVIE_INF.GEN = (Generos)OPGEN; 
                    break;
                    case 7: cout << "\n\n|| NUEVO Edad minima: " << endl; cin >> MOVIE_INF.EdMin; break;
                    case 8:
                        do{
                            cout << "|| NUEVA Sala en la que esta: " << endl; cin >> MOVIE_INF.Sala;
                            if(MOVIE_INF.Sala < 1 || MOVIE_INF.Sala > Max_Salas )cout << "\n\tSolo hay " << Max_Salas << " salas disponibles";
                        }while(MOVIE_INF.Sala < 1 || MOVIE_INF.Sala > Max_Salas);
                    break;
                    case 9: cout << "\n\n|| NUEVO Horario: " << endl; cin >> MOVIE_INF.horario; MOVIE_INF.Lleno = true; break;
                    default: cerr << "\n\n|| Valor invalido" << endl; break;
                }
                MOVIE_INF.Lleno = true;

                FILE_MOVIE.seekp( (pos - 1) * sizeof(Pelicula));
                FILE_MOVIE.write( reinterpret_cast<char*>(&MOVIE_INF), sizeof(Pelicula) );

                if( Dat >= 1 && Dat <= 9) cout << "\nRegistro actualizado!!\n";

                if(Dat != 0) cout << "\n\nDesea cambiar otro dato? (0=No, Otro=Si): "; cin >> Dat;
            }while(Dat != 0);
            FILE_MOVIE.close();
    }
}

void ModiSala(int AUX_SALA, Sala sala[]){
    cout << "Numero de filas de la sala:" << endl; cin >> sala[AUX_SALA].FI;
    cout << "Numero de columnas de la sala:" << endl; cin >> sala[AUX_SALA].COL;

    sala[AUX_SALA].matriz = (int**) calloc(sala[AUX_SALA].FI, sizeof(int*));

    for ( int i = 0; i < sala[AUX_SALA].FI; i++ ) sala[AUX_SALA].matriz[i] = (int*) calloc(sala[AUX_SALA].COL, sizeof(int));

    for( int f = 0; f < sala[AUX_SALA].FI; f++ ){
        for( int c = 0; c < sala[AUX_SALA].COL; c++ ){
            sala[AUX_SALA].matriz[f][c] = 0;
        }
    }
}

//CHRIs_PART_FUNTION

void AltaDeProductos(int *N, Producto *p){
	cout<<"-------------------------------------------------"<<endl;
	if(*N>=100){
		cout<<"El inventario esta lleno"<<endl;
		return;
	}
	int id;
	cout<<"Ingrese ID: ";
	cin>>id;
	for(int i=0; i<*N; i++){
		if(p[i].id==id){
			cout<<"Ese ID ya esta registrado"<<endl;
			return;
		}
	}
	p[*N].id=id;
	cout<<"Ingrese el nombre del producto: ";
	cin.ignore(1000, '\n');
	cin.getline(p[*N].nombreP, 30);
	do{
		cout<<"Categoria (C para Cafeteria o D para Dulceria): ";
		cin>>p[*N].categoria;
	}while(p[*N].categoria!='C' && p[*N].categoria!='D' && p[*N].categoria!='c' && p[*N].categoria!='d');
	do{
		cout<<"Ingrese el precio: ";
		cin>>p[*N].precio;
	}while(p[*N].precio<=0);
	do{
		cout<<"Stock: ";
		cin>>p[*N].stock;
	}while(p[*N].stock<0);
	if(p[*N].stock==0){
		p[*N].activo=false;
	}else{
		p[*N].activo=true;
	}
	*N=*N+1;
	cout<<"-------------------------------------------------"<<endl;
}

void BajaDeProductos(Producto *p, int *N){
	int id;
	bool band=false;
	cout<<"Ingrese el ID del producto que quiere dar de baja: ";
	cin>>id;
	for(int i=0; i<*N; i++){
		if(p[i].id==id){
			cout<<"Producto encontrado, ahora "<<p[i].nombreP<<" estara inactivo"<<endl;
			p[i].activo=false;
			band=true;
			break;
		}
	}
	if(band==false){
		cout<<"Ese ID no corresponde a ningun producto"<<endl;
		return;
	}
}

void ModificarProducto(Producto *p, int *N){
	int id;
	cout<<"-------------------------------------------------"<<endl;
	cout<<"Ingresa el ID del producto que deseas modificar: ";
	cin>>id;
	for(int i=0; i<*N; i++){
		if(p[i].id==id){
			cout<<"Producto encontrado"<<endl;
			cout<<"Ingrese el nombre del producto: ";
			cin>>p[i].nombreP;
			do{
				cout<<"Categoria (C para Cafeteria o D para Dulceria): ";
				cin>>p[i].categoria;
				if(p[i].categoria!='C' && p[i].categoria!='D' && p[i].categoria!='c' && p[i].categoria!='d') cout << "Letra invalida, REINTENTAR: " << endl;
			}while(p[i].categoria!='C' && p[i].categoria!='D' && p[i].categoria!='c' && p[i].categoria!='d');
			do{
				cout<<"Ingrese el precio: ";
				cin>>p[i].precio;
			}while(p[i].precio<=0);
			do{
				cout<<"Stock: ";
				cin>>p[i].stock;
			}while(p[i].stock<0);
			if(p[i].stock==0){
				p[i].activo=false;
			}else{
				p[i].activo=true;
			}
			break;
		}
	}
	cout<<"-------------------------------------------------"<<endl;
}

bool BuscarProducto(char nombre[30], Producto *p, int *N){
	cout<<"-------------------------------------------------"<<endl;
	for(int i=0; i<*N; i++){
		if(strcmp(nombre, p[i].nombreP)==0){
			if(p[i].activo==true){
				cout<<"Producto encontrado"<<endl;
				cout<<"ID: "<<p[i].id<<endl;
				cout<<"Nombre: "<<p[i].nombreP<<endl;
				cout<<"Categoria: "<<p[i].categoria<<endl;
				cout<<"Precio: "<<p[i].precio<<endl;
				cout<<"Stock: "<<p[i].stock<<endl;
				cout<<"-------------------------------------------------"<<endl;
				return true;
			}else{
				cout<<"En este momento no hay stock de este producto, lo repondremos lo antes posible"<<endl;
			}
			return true;
		}
	}
	return false;
}

void MostrarTodo(Producto *p, int *N){
	cout<<"\n=================== CAFETERIA ===================\n"<<endl;
	for(int i=0; i<*N; i++){
		if((p[i].categoria=='C' || p[i].categoria!='c') && p[i].activo==true){
			cout<<"-------------------------------------------------"<<endl;
			cout<<"ID: "<<p[i].id<<endl;
			cout<<"Nombre: "<<p[i].nombreP<<endl;
			cout<<"Categoria: "<<p[i].categoria<<endl;
			cout<<"Precio: "<<p[i].precio<<endl;
			cout<<"Stock: "<<p[i].stock<<endl;
			cout<<"-------------------------------------------------"<<endl;
		}
	}
	cout<<"\n=================== DULCERIA ===================\n"<<endl;
	for(int i=0; i<*N; i++){
		if((p[i].categoria=='D' || p[i].categoria!='d') && p[i].activo==true){
			cout<<"-------------------------------------------------"<<endl;
			cout<<"ID: "<<p[i].id<<endl;
			cout<<"Nombre: "<<p[i].nombreP<<endl;
			cout<<"Categoria: "<<p[i].categoria<<endl;
			cout<<"Precio: "<<p[i].precio<<endl;
			cout<<"Stock: "<<p[i].stock<<endl;
			cout<<"-------------------------------------------------"<<endl;
		}
	}
}

void Inventario(Producto *p, int *N){
	for(int i=0; i<*N; i++){
		cout<<"----------------------------------------------"<<endl;
		cout<<"ID: "<<p[i].id<<endl;
		cout<<"Nombre: "<<p[i].nombreP<<endl;
		cout<<"Categoria: "<<p[i].categoria<<endl;
		cout<<"Precio: "<<p[i].precio<<endl;
		cout<<"Stock: "<<p[i].stock<<endl;
		if(p[i].stock<=100){
			cout<<"ALERTA, ES RECOMENDABLE VOLVER A SURTIR"<<endl;
		}
		cout<<"----------------------------------------------"<<endl;
	}
}

void A_Inventario(Producto *p, int *N){
	int id, cant, resp;
	bool band;
	cout<<"-------------------------------------------------"<<endl;
	do{
		cout<<"Deseas ver antes el inventario? (1) Si (2) No";
		cin>>resp;
		if(resp==1){
			Inventario(p, N);
		}
	}while(resp!=1 && resp!=2);
	cout<<"Ingresa el ID del producto que deseas anadir stock: ";
	cin>>id;
	for(int i=0; i<*N; i++){
		if(p[i].id==id){
			do{
				cout<<"Cuanto deseas anadir? ";			
				cin>>cant;
			}while(cant<=0);
			p[i].stock=p[i].stock+cant;
			band=true;
		}
	}
	if(band==false){
		cout<<"ID incorrecto"<<endl;
	}
}

void RealizarVenta(Producto *p, Venta v, int *N){
	fstream archivo;
	v.total=0;
	int resp, id, opcion;
	bool band=false;
	archivo.open("Compras_Totales.txt",ios::out);
    if(!archivo){
        cout<<"No se pudo abrir el archivo"<<endl;
        return;
    }else{
        cout<<"El achivo ya existe"<<endl;
    }
    archivo.close();
	do{
		do{
			cout<<"Deseas antes ver el menu? (1) Si (2) No: ";
			cin>>resp;
			if(resp==1){
				MostrarTodo(p, N);
			}
		}while(resp!=2 && resp!=1);
		cout<<"Ingresa el ID del producto que deseas comprar: ";
		cin>>id;
		for(int i=0; i<*N; i++){
			if(id==p[i].id){
				band=true;
				do{
					cout<<"Cuantos quieres? ";
					cin>>v.cantidad;
					if(v.cantidad>p[i].stock){
						cout<<"Lo siento, solo tenemos "<<p[i].stock<<" "<<p[i].nombreP<<endl;
					}
				}while(v.cantidad>p[i].stock);
				v.total=v.total+(p[i].precio*v.cantidad);
				p[i].stock=p[i].stock-v.cantidad;
				if(p[i].stock==0){
					p[i].activo=false;
				}
				archivo.open("Compras_Totales.txt",ios::out|ios::app);
				if(!archivo){
					cerr<<"No se pudo abrir el archivo"<<endl; cin.get();
					return;
				}
				archivo<<p[i].id<<" "<<p[i].nombreP<<" "<<v.cantidad<<" "<<v.total<<endl;
				archivo.close();
				break;
			}
		}
		if(band==false){
			cout<<"Ese id no existe"<<endl;
			return;
		}
		getchar();
		cout<<"Deseas agregar otro producto? (1) Si (2) No: ";
		cin>>opcion;
		cout<<"------------------------------------------"<<endl;
	}while(opcion==1);
	cout<<"------------------------------------------"<<endl;
}

//UGALDEs_PART_FUNTION
void mostrar_ventas()
{
	fstream archivo;
	archivo.open("Compras_Totales.txt",ios::in);
	if(!archivo)
	{
		cerr<<"ERROR EN EL ARCHIVO,NO EXISTE"<<endl;
		return;
	}
	int id,cantidad;
	char nombreP[30];
	float total;
	cout<<"LAS VENTAS DEL DIA FUERON........"<<endl;
	while(archivo>>id>>nombreP>>cantidad>>total)
	{
	cout<<"------------------------------------"<<endl;
	cout<<"ID:"<<id<<endl;
	cout<<"NOMBRE: "<<nombreP<<endl;
	cout<<"CANTIDAD DEL PRODUCTO:"<<cantidad<<endl;
	cout<<"TOTAL DE LA VENTA: "<<total<<endl;
	cout<<"------------------------------------"<<endl;
   }
   archivo.close();
}
void Tvendido()
{
	fstream archivo;
	archivo.open("Compras_Totales.txt",ios::in);
	if(!archivo)
	{
		cerr<<"NO HAY VENTAS REGISTRADAS "<<endl;
		return;
	}
	float totalv=0;
	int id,cantidad;
	char nombreP[30];
	float total;
	while(archivo>>id>>nombreP>>cantidad>>total)
	{
		totalv=totalv+total;
		cout<<"LAS VENTAS TOTALES DEL DIA FUERON: "<<endl<<totalv<<endl;
	}
	archivo.close();
}

void IVA()
{
	fstream archivo;
	archivo.open("Compras_Totales.txt",ios::in);
	if(!archivo)
	{
		cerr<<"NO HAY IVA"<<endl;
		return ;
	}
	int id,cantidad;
	char nombreP[30];
	float total,totalv=0;
	while(archivo>>id>>nombreP>>cantidad>>total)
	{
		totalv=totalv+total;
	}
	archivo.close();
	float iva=totalv*0.16;
	cout<<"VENTAS TOTALES   :"<<totalv<<endl;
	cout<<"IVA GENERAL     : "<<iva<<endl;
}

void corte()
{
	fstream archivo;
	archivo.open("Compras_Totales.txt",ios::in);
	if(!archivo)
	{
		cerr<<"ERROR ,NO HAY DATOS AGREGADOS"<<endl;
		return;
	}
	int id,cantidad,tdp=0,numv=0;
	char nombreP[30];
	float total,totalv=0;
	while(archivo>>id>>nombreP>>cantidad>>total)
	{
		totalv=totalv+total;
		tdp=tdp+cantidad;
		numv++;
	}
	archivo.close();
		cout<<"-----------------------------"<<endl;
		cout<<endl;
		cout<<"CORTE DE CAJA----------------"<<endl;
		cout<<"NUMERO DE VENTAS REALIZADAS"<<endl<<numv<<endl;
	    cout<<"PRODUCTOS VENDIDOS "<<endl<<tdp<<endl;
	    cout<<"GANADO EN EL DIA "<<endl<<totalv<<endl;
	    cout<<"TOTAL DEL IVA GENERADO"<<endl<<totalv*0.16<<endl;
	    cout<<"----------------------------------"<<endl;
}
