#include<iostream>
#include<math.h>
using namespace std;

bool comprobar(int reinas[],int n,int k){
	int i;
	for(i =0;i<k;i++){
		if((reinas[i]==reinas[k])or(abs(k-i)==abs(reinas[k]-reinas[i]))){
			return false;	
		}
	}
	return true;
}

void Nreinas(int reinas[],int n,int k){
	if(k==n){
		for (int i=0; i<n; i++){
			cout<<reinas[i]<<" , ";
		}
		cout<<endl;
	}
	else{
		for(reinas[k]=0;reinas[k]<n;reinas[k]++){
			if(comprobar(reinas, n,k)){
				Nreinas(reinas,n,k+1);
			}	
		}
	}
}

// Funcion que implenta el juego de las 8 reinas
void juego8reinas(){
    int reinas[8];
    Nreinas(reinas,8,0);
}

int main(){
	int k=0;
	int cant;
	cout<<"**********Grupo 9************\n\n";
	cout<<"1.-Chin Basurto Adrian Alberto";
	cout<<"\n2.-Molina Toapanta Juan Carlos";
	cout<<"\n3.-Alcocer Cocha Kevin Anthony (Coordinador)";
	cout<<"\n4.-Molineros Tayupanta David Alejandro";
	cout<<"\n5.-Calero Carchipulla Juan Daniel";


	cout<<"\n\nIngrese la Cantidad de Reynas:";
	juego8reinas();
    return 0;
    
	
}