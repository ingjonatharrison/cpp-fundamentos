#include <iostream>
using namespace std;

//orgnos mercado negro

//captura de datos del usuario, se le entregan al main
//muestra el menu no da no recibe 
//el main muestra las opciones enumeradas precios no devuelve nada
//compra total

void DarPrecios(int);

int main(){
	int opcion;	

	do{
			//el main entrega a la funcion case 3:
		cout<<"-------precios-------"<<endl;
		cout<<"0.-salir"<<endl;
		cout<<"1.-cerebro"<<endl;
		cout<<"2.-ojos"<<endl;
		cout<<"3.-higado"<<endl;
		cout<<"4.-riñon"<<endl;
		
		cout<<"Cual opcion quieres ver?"<<endl;
		
		cin>>opcion;
		if(opcion!=0){
			DarPrecios(opcion);
		}
	}while (opcion!=0);
	
	return 0;
}

void DarPrecios(int opcion){
	if(opcion==1){
		cout<<"$ 5000"<<endl;
	}else if(opcion==2){
		cout<<"$ 20000"<<endl;
	}else if(opcion==3){
		cout<<"$ 15000"<<endl;
	} else if(opcion==4){
		cout<<"$ 70000"<<endl;
	}
}