// Vectores dinamicos
#include <iostream>

using namespace std;

// Imprimir splash
void mensajeInicial(){
    cout << 
    "***********************************************************\n"
    "*****         E                                       *****\n"
    "*****            L                                    *****\n"
    "*****               E          2                      *****\n"
    "*****                  C          0                   *****\n"
    "*****                     I          2                *****\n"
    "*****                        O          2             *****\n"
    "*****                           N                     *****\n"
    "*****                              E                  *****\n"
    "*****                                 S               *****\n"
    "***********************************************************\n"
    << endl;
}

// Llenado de votos: indiceDistrito = llenarVotos(votos, indiceDistrito, candidatos, numeroCandidatos, numeroDistritos);
void llenarVotos(int **votos, char candidatos[], int numeroCandidatos, int numeroDistritos){
    for ( int i = 0 ; i < numeroCandidatos ; i++ ){
        cout << "Candidato "<< candidatos[i] << ": " << endl;        
        votos[i] = new int[numeroDistritos];
        for ( int j = 0 ; j < numeroDistritos ; j++ ){            
            int *votos_temp = new int[j+1];
            cout << "Ingrese la cantidad de votos [" << j+1 << "]: ";
            cin >> votos_temp[j];
            votos[i][j] = votos_temp[j];
            delete[] votos_temp;
        }
    }
}

// Mensaje al llenar votos
void mensajeVotos(){
    cout << 
    "************************************************************\n"
    "*****                 LLENADO DE VOTOS                 *****\n"
    "************************************************************\n"
    << endl;
}

// Imprimir votos
void imprimirVotos(int **votos, int cantidad, char candidatos[], int numeroCandidatos){
    
    cout << 
    "************************************************************\n"
    "*****                IMPRESION DE VOTOS                *****\n"
    "************************************************************\n"
    << endl;
    for ( int i = 0 ; i < numeroCandidatos ; i++ ){
        int suma = 0;
        cout << "Candidato " << candidatos[i] << endl;
        for(int j = 0; j < cantidad; j++){
            cout << "Distrito [" << j+1 << "]: " << votos[i][j] << endl;
            suma += votos[i][j];
        }
        cout << "La suma total de los votos del candidato "<< candidatos[i] <<" es: " << suma << " votos"<< endl;
    }
    cout << 
    "************************************************************\n"
    << endl;
}

// Main
int main(){
    mensajeInicial();
    int cantidad = 0;
    char candidatos[] = "ABCD";
    int numeroCandidatos = 4;
    int numeroDistritos = 5;
    int *votos[5] = {0};

    mensajeVotos();
    llenarVotos(votos, candidatos, numeroCandidatos, numeroDistritos);

    imprimirVotos(votos, numeroDistritos, candidatos, numeroCandidatos);
    
    return 0;
}
