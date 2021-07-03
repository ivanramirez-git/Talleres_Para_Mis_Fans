// Your C++ Program
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>    
#include <utility>

#include "DATA/Dato.h"
#include "AVL/AVL.h"
#include "MINHEAP/minHeap.h"

using namespace std;



// Funcion que imprime un nodo	
void print(Node<int>* node){
	if(node) {
		print(node->leftSon);
		std::cout << "key = "<< node->key << "\n";
		print(node->rightSon);
	}
}	

// Funcion que corta las frases cuando encuent una coma 
vector<string> split(string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}


void imprimirVector(vector<int> imprime) {
	for(int i = 0; imprime.size()>i;i++) {
		cout<<imprime[i]<<endl;
	}
}

void imprimirMapa(vector<int> claves, map<int,Dato> valores) {
	Dato temporal;
	for(int i = 0; claves.size()>i;i++) {
		temporal=valores[claves[i]];
		temporal.imprimirDato();
	}
}

// Funcion que lee el archivo y carga los datos en las estructuras

pair<map<int,Dato>,vector<int> > leerArchivo(string ruta) { 
   	
   	string texto;
   	ifstream leerArchivo;
	leerArchivo.open(&ruta[0]);
	vector<int> edades;
	
	map<int,Dato> personas;
	
	if(leerArchivo.fail())
	{
		cout<<"El archivo no fue encontrado";
	}
	for(int i=0;getline(leerArchivo,texto);i++) {
		vector<string>	resultados = split(texto,',');
		Dato temporal;
		temporal.setNombre(resultados[0]);
		temporal.setEdad(atoi(&resultados[1][0]));
		temporal.setRut(resultados[2]);
		temporal.setVacunado(resultados[3]=="S");
		temporal.setEnfermedad(resultados[4]=="S");
		temporal.setVacio(false);
		
		//temporal.imprimirDato();
		
		edades.push_back(temporal.getEdad());
		personas[temporal.getEdad()]=temporal;
		
	}
	
	//imprimirVector(edades);
	
	//cout<<"Vamos que vamos: "<<personas[20].getNombre()<<endl;
	
	leerArchivo.close();
	pair <map<int,Dato>,vector<int> > pareja (personas,edades);
	return  pareja;

}

bool guardarArchivo(string ruta, map<int,Dato> personas, vector<int> edades) {
	
	//minHeap
	Dato datoTemporal;
	MinHeap minheap;
	string texto;
	
	for(int i=0;i<edades.size();i++) {
		datoTemporal=personas[edades[i]];
		minheap.insertKey(datoTemporal.getEdad());	
	}
	
	texto="";
	
	for(int i = 0; i<edades.size();i++) {
		datoTemporal=personas[minheap.getMin()];
		texto = texto+datoTemporal.toString()+"\n";
		minheap.extract();
	}
	
	//cout<<texto<<endl;
	
	ofstream guardarArchivo;
	guardarArchivo.open(&ruta[0]);
	guardarArchivo << texto;
	guardarArchivo.close();
	
	return true;
}

int main() {
	
    // Se cargan los datos del archivo en las estructuras
    pair <map<int,Dato>,vector<int> > pareja = leerArchivo("Datos/El_Bueno.txt");
    
    map<int,Dato> personas = pareja.first;
    vector<int> edades = pareja.second;
	Dato datoTemporal;
    
    //Arboles
    
    //AVL
    Node<int> root = Node<int>(121);
	AVL<int> avl = AVL<int>(&root);
	
	//minHeap
	MinHeap minheap;
	
	for(int i=0;i<edades.size();i++) {
		avl.insert(edades[i]);
		datoTemporal=personas[edades[i]];
		
		if(!datoTemporal.getVacunado()){
			//datoTemporal.imprimirDato();
			minheap.insertKey(datoTemporal.getEdad());
		}

		//personas[edades[i]]
		//if()	
	}
	avl.deleteNode(121);
	
	//cout<<endl<<endl;
	//print(avl.getRoot());
	//imprimirMapa(edades,personas);
	
	//imprimirVector(edades);    
    
    int indice;
    string ruta;
    string textoTemporal;
    char cadenaTemporal[20];
    int numeroVacunas=0;

    // Men�
    cout<<".:: BIENVENIDX ::."<<endl;
    while(true) {
        // Imprimir las opciones
        cout<<endl;
        cout<<"1. Nuevas Personas Para Vacunar"<<endl;
        cout<<"2. Nuevas Vacunas"<<endl;
        cout<<"3. Estadisticas"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"-> ";
        cin>>indice;
        switch(indice) {

            // El sistema debe preguntar cuántas personas nuevas va a agregar
            case 1:     

                int count;

                cout<<"Cuantas personas nuevas desea agregar"<<endl;
                cout<<"-> ";
                cin>>count;

                // Se debe solicitar nombre, RUT, edad y estado de vacunación de cada una de ellas
                for (int i = 0; i < count; ++i) {
                    if(true) {
                    	
                    	// Puede guardar hata 19 letras
                        cout<<" Ingrese el nombre de la "<<i+1<<" persona: ";
                        
                        cin>>cadenaTemporal;
                        textoTemporal=cadenaTemporal;
                        cin>>cadenaTemporal;
                        textoTemporal=textoTemporal+" "+cadenaTemporal;
                        datoTemporal.setNombre(textoTemporal);
                        
                        cout<<" Ingrese la edad: ";
                        cin>>indice;
                        datoTemporal.setEdad(indice);
                        
                        cout<<" Ingrese el RUT: ";
                        cin>>textoTemporal;
                        datoTemporal.setRut(textoTemporal);
                        
                        cout<<" Ingrese S si esta vacunado o N si no lo esta: ";
                        cin>>textoTemporal;
                        datoTemporal.setVacunado(textoTemporal=="S");
                        
                        cout<<" Ingrese S si tiene enfermedad cronica o N si no tiene: ";
                        cin>>textoTemporal;
                        datoTemporal.setEnfermedad(textoTemporal=="S");
                        
                        datoTemporal.setVacio(false);
                        
                        cout<<" Se agrego correctamente"<<endl;
                    }
                    
                    //datoTemporal.imprimirDato();
                    
                    edades.push_back(datoTemporal.getEdad());
                    personas[datoTemporal.getEdad()]=datoTemporal;
                    
                    avl.insert(datoTemporal.getEdad());
                    
                    if(!datoTemporal.getVacunado()) {
	                    minheap.insertKey(datoTemporal.getEdad());
	                    
					}
                	//imprimirMapa(edades,personas);
                }
            break;

            case 2:
            	
            	int i,j,k;
            	
            	k=minheap.get_size();
            	/*
            	for(int i=0;i<k;i++) {
            		datoTemporal=personas[minheap.getMin()];
            		datoTemporal.imprimirDato();
            		minheap.extract();
				}
            	*/
            	
            	// El usuario indica cuantas vacunas han llegado
				cout<<" Ingrese el numero de vacunas disponibles: ";
            	cin>>j;
            	
         	    //  El sistema informa por pantalla a quiénes se le debe suministrar
            	cout<<" Las personas a vacunar son por prioridad de edad de menor a mayor son: "<<endl;
            	for(i=0;i<j && i<k;i++) {
            		
	            		cout<<" "<<i+1<<": ";
	            		datoTemporal=personas[minheap.getMin()];
	            		datoTemporal.imprimirDato();
	            		datoTemporal.setVacunado(true);
	            		personas[minheap.getMin()]=datoTemporal;
	            		minheap.extract();
            		
				}
				
				numeroVacunas+=-i+j;
				
            break;

            // 
            case 3:

                bool falla;
                falla=true;

                // Submenú
                while(falla) {
                    cout<<"Estadisticas"<<endl<<endl;
                    cout<<" 3.1. Cuantas personas estan vacunadas y cuantas no lo estan."<<endl;
                    cout<<" 3.2. Quien es la persona mas antigua en el puesto de vacunacion que no esta vacunada."<<endl;
                    cout<<" 3.3. Cual es la edad promedio de las personas en el puesto de vacunacion."<<endl;
                    cout<<" 3.4. Si un RUT especifico (entregado por pantalla) esta o no vacunado."<<endl;
                    cout<<" 3.5. Listado completo de todas las personas en el refugio con toda su informacion."<<endl;
                    cout<<" 3.6. Cuantas vacunas sobran."<<endl;
                    cout<<"-> 3.";
                    cin>>indice;
                    falla=false;

                    switch(indice) {
                        case 1:
						//Cuantas personas estan vacunadas y cuantas no
							int numVacunados, numNoVacunados;
							numVacunados=0;
							numNoVacunados=0;
							for(int i=0;i<edades.size();i++) {
								datoTemporal = personas[edades[i]];
								if(datoTemporal.getVacunado()){
									numVacunados++;
								}else {
									numNoVacunados++;
								}
							}
							cout<<" Numero de personas vacunadas: ";
							cout<<numVacunados<<endl;
							cout<<" Numero de personas no vacunadas: ";
							cout<<numNoVacunados<<endl;
							
							
                        break;
                        case 2:
                        	// La persona mas antigua que no esta vacunada
                        	cout<< " La persona mas antigua que no esta vacunada es: "<<endl<<" ";
							falla=true;
                        	for(int i=0; i<edades.size()&&falla;i++) {
                        		datoTemporal = personas[edades[i]];
                        		if(!datoTemporal.getVacunado()) {
                        			datoTemporal.imprimirDato();
									falla=false;	
								}                        		
							}
							if(falla) {
								cout<<" Todos estan vacunados."<<endl;
							}
                        	
							falla=false;
                        break;
                        case 3:
                        	// Cual es la edad promedio de las personas en el puesto de vacunacion
                        	float edadSuma;
                        	float promedio;
                        	
                        	edadSuma=0;
                        	promedio=0;
                        	
							for(int i=0;i<edades.size();i++) {
								edadSuma+=edades[i];
							}
							promedio=edadSuma/edades.size();
							
							cout<< "La edad promedio de las personas en lista es: "<< promedio<<endl;
							
                        break;
                        case 4:
                        	//Rut especifico
                        	
                        	cout<<" Por favor ingrese un RUT: ";
                        	cin>>textoTemporal;
                        	falla = true;
                        	
                        	for(int i=0;i<edades.size() && falla;i++) {
								datoTemporal=personas[edades[i]];
								if(datoTemporal.getRut()==textoTemporal) {
									falla=false;
									if(datoTemporal.getVacunado()) {
										cout<<" La persona con el RUT: "<<datoTemporal.getRut()<< " esta Vacunada"<<endl;
									}else {
										cout<<" La persona con el RUT: "<<datoTemporal.getRut()<< " NO esta Vacunada"<<endl;
									}																		
								} 
							}
							if(falla) {
								cout<<"La persona con el RUT: "<<textoTemporal<<" no esta registrada."<<endl;
							}							
                        	falla = false;
                        break;
                        case 5:
                        	//Listado
                        	
                        	for(int i=0;i<edades.size();i++) {
                        		datoTemporal=personas[edades[i]];
                        		cout<<" "<<i+1<<": ";
                        		datoTemporal.imprimirDato();
							}
                        	
                        
                        break;
                        case 6:
                        	cout<<" El numero de vacunas es: "<<numeroVacunas<<endl;
                        break;
                        default:
                            cout<<"Por favor ingrese una opcion valida."<<endl;
                            falla=true;
                        break;
                    }

                }

            break;
            case 4:
            	cout<<"Ingrese un nombre para el archivo: ";
            	cin>>ruta;
            	if(guardarArchivo("Datos/"+ruta+".txt",personas,edades)) {
            		cout<<"Se guardo el archivo "<< ruta <<"."<<endl;
				}else {
					cout<<"Ocurrio un error cuando se intentaba guardar el archivo "<< ruta <<endl;
					return -1;
				}
            	
                return 0;
            break;
            default:
                cout<<"Por favor ingrese una opcion valida"<<endl;
            break;

        }

    }

}
