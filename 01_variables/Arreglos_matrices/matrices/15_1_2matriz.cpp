#include<iostream>
#include<string>

using namespace std;

bool Primo(int numero){
	if(){
		
	}else{
		
	}
}

void Tabla(int numero){
	for(int i=1; i==11; i++){
		cout<<numero<<"X"<<i<<"="<<numero*i<<endl;
	}
}

int Suma(){
	int Vec[4];
	int Aux;
	for(int i=0; i>=5; i++){
		cout<<"dame el dato "<<i+1<<" a sumar: ";
		cin>>Vec[i];
	}
	for(int i=0; i>=5; i++){
		Aux+=Vec[i];
	}
	return Aux;
}

void Matriz(){
	for(){
		
		for(){
			
		}
	}
}

int main(){
	int numero;
	int Aux;
	char Op;
	do{
		char Menu();
		Op=Menu();
		switch(Op){
			case 'P':
				cout<<"Dame el numero: "<<endl;
				cin>>numero;
				Primo(numero);
				break;
			case 'T':
				cout<<"Dame el numero de la tabla que quieres ver: "<<endl;
				cin>>numero;
				Tabla(numero);
				break;
			case 'D':
				Suma();
				Aux=Suma();
				break;
			case 'M':
				Matriz();
				break;
			case 'S':
				cout<<"Gracias!!"<<endl;
				break;
			default:
				cout<<"Caracter invalido"<<endl;
				break;
		}
	}while(Op!='S');
	return 0;
}

char Menu(){
	int Op;
	cout<<endl<<"--------------------------MENU--------------------------"<<endl;
	cout<<"------------------SOLO USA UN CARACTER------------------"<<endl;
	cout<<"'P'= Saber si es un numero primo o no"<<endl;
	cout<<"'T'= Tabla de multiplicar"<<endl;
	cout<<"'D'= Suma de 5 datos"<<endl;
	cout<<"'M'= Captura de una matriz de 4X3 y contar los < a 10"<<endl;
	cout<<"'S'= SALIR"<<endl;
	cin>>Op;
	return Op;
}
