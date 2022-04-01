#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;


//Estructura de los nodos de la cola 

struct nodo{
	int dato;
	struct nodo *sgte;
};

//Estructura de la cola

struct cola{
	nodo *delante;
	nodo *atras;
	
};

//agregar elementos a la cola

void insertar(struct cola &p, int valor){
	struct nodo *aux = new(struct nodo); 
	aux->dato = valor;
	aux->sgte = NULL;
	
	
	
	
}

// mostrar elementos de una cola 

int borrar (struct cola &p){
	int num;
	struct nodo *aux;
	
	aux = p.adelante; //apunta el inicio la cola
	num = aux->dato
	p.adelante = (p.delante)->sgte;
	delete(aux);
	
	return num;
	
}


int main(){
	
	
	
	
	
	
	
	
	
	
	getch();
	return 0;
	
}