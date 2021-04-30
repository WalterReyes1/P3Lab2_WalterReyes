#include <iostream>
#include <math.h>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void pascal(int,int,int[],int[]);
void sumatoria();
void grafico();
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
				do{
				cout<<"Ingrese un valor del 1 al 99: ";
				cin>>max_n;	
				}while(max_n<1 || max_n>99);
					int salida[100];
					int res_anterior[100];
					
					for(int i = 0; i <100;i++){
						salida[i]=0;
						res_anterior[i]=0;
					}
					pascal(0,max_n,res_anterior,salida);
					
				break;
			}
			case 2: {
				sumatoria();
				break;
			}
			case 3: {
				//grafico();
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
void pascal(int n, int max_n,int res_anterior [100], int salida [100] ){
	
	int x = n+1;
	if(n==max_n){
		
	}else{
		if(n==0){
			salida[n]=1;
			res_anterior[n]=1;	
			salida[x]=1;		
			cout<<salida[n]<<endl;
			pascal(n+1,max_n,res_anterior,salida);
		}else{
			
			for(int i = x; i<=n;i++){
				salida[i]=1;
				
				salida[i]=res_anterior[i-1]+res_anterior[i];
			}
			
			
			cout<<endl;
			
		}
		
	pascal(n+1,max_n,res_anterior,salida);	
	}
}// fin pascal;

void sumatoria(){
	int arreglo[]= {6,2,3,1};
	double acum=0.0;
	double div = 0.0;
	double positivo =0.0;
	double acum2=0.0;
	for(int i=0; i<4;i++){
		acum+= arreglo[i];
		
	}
	div= acum/4;
	for(int i=0;i<4;i++){
	positivo=arreglo[i]-div;
		if(positivo <0){
			(positivo)*-1.0;
			
		}
		
		
		acum2+= pow(positivo,2);
		
	}
	double total = sqrt(acum2/4.0);
	
	cout<<"El resultado es: "<<total<<endl;
	
	
	
}