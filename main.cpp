#include <iostream>
#include <math.h>
#include <cmath>
#include<stdlib.h>
#include<time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void pascal(int,int,int[],int[]);
void sumatoria();
void grafico();
void imprimir(int [], int tam);

int opcion = 0;
int menu() {
	while(true) {
		cout<<"Bienvenido "<<endl;
		cout<<"1.Pascal"<<endl;
		cout<<"2.Sumatoria"<<endl;
		cout<<"3.Grafico"<<endl;
		cout<<"4.Salir"<<endl;
		cout<<"Eliga una opcion: ";
		cin>>opcion;
		if(opcion >0 && opcion <5) {
			return opcion;
		}

	}
}
int main(int argc, char** argv) {
	while(opcion != 4) {
		switch(opcion=menu()) {
			case 1: {
				int max_n =0;
				do {
					cout<<"Ingrese un valor del 1 al 99: ";
					cin>>max_n;
				} while(max_n<1 || max_n>99);
				int salida[100];
				int res_anterior[100];

				for(int i = 0; i <100; i++) {
					salida[i]=0;
					res_anterior[i]=0;
				}
				pascal(0,max_n, res_anterior, salida);

				break;
			}
			case 2: {
				sumatoria();
				break;
			}
			case 3: {
				grafico();
				break;
			}
			case 4: {
				cout<<"Salir"<<endl;
				break;
			}
		}//fin switch

	}// fin while menu

	return 0;

}



void sumatoria() {
	int arreglo[20];
	
	for(int i = 0; i <20; i++) {
		arreglo[i]=1+rand()%99;
	}
	imprimir(arreglo,20);
	cout<<endl;
	double acum=0.0;
	double div = 0.0;
	double positivo =0.0;
	double acum2=0.0;
	for(int i=0; i<20; i++) {
		acum+= arreglo[i];

	}
	div= acum/20;
	for(int i=0; i<20; i++) {
		positivo=arreglo[i]-div;
		if(positivo <0) {
			(positivo)*-1.0;
		}


		acum2+= pow(positivo,2);

	}
	double total = sqrt(acum2/20.0);

	cout<<"El resultado es: "<<total<<endl;

}

void grafico() {
	int arreglo[10];
	int arreglo2[10];
	srand (time(NULL));
	for(int i = 0; i <10; i++) {

		arreglo[i]= 1+rand()% 19;
		arreglo2[i]= 1+rand()% 19;
	}
	imprimir(arreglo,10);
	imprimir(arreglo2,10);
	char x = 177;
	char y = 178;
	cout<<endl;
	for(int i = 0; i<10; i++) {
		cout<<endl;
		cout<<i+1<<". ";
		for(int j = 0; j<arreglo[i]; j++) {
			cout<<x<<" ";
		}
		cout<<endl;
		cout<<"   ";
		for(int j = 0; j< arreglo2[i]; j++) {
			cout<<y<<" ";
		}
		cout<<endl;
	}


}
void imprimir(int arreglo [],int tam) {
	cout<<"[ ";
	for(int i = 0; i<tam; i++) {
		cout<<arreglo[i]<<", ";
	}
	cout<<"] "<<endl;
}

void pascal(int n, int max_n,int res_anterior[],int salida[] ) {
	int final= 0;
	if(n==max_n) {
		cout<<endl;
		cout<<"Al fin lo pude hacer :D \n"<<endl;
		
	} else {
		if(n==final) {
			salida[n]=1;
			res_anterior[n]=1;
			cout<<salida[n]<<endl;
			pascal(n+1,max_n,res_anterior,salida);
		} else {
			for(int i = 0; i< n; i++) {

				salida[i]=res_anterior[i-1]+res_anterior[i];

				cout<<salida[i]<<" ";
			}

			for(int i = 0; i<n; i++) {
				res_anterior[i]=salida[i];
				salida[i]=final;
			}
			cout<<endl;
			pascal(n+1,max_n,res_anterior,salida);
		}

	}
}// fin pascal;


