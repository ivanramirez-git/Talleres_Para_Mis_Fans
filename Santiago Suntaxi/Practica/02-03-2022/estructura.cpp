#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

struct carro{
    char placa[6];
    char marca[12];
    float avaluo;
};

// Guardar datos en archivo
void guardar(carro c[], int n){
    ofstream archivo;
    // Guardar Columnas
    archivo.open("carros.txt", ios::out);
    archivo << "Placa" << "\t" << "Marca" << "\t" << "Avaluo" << endl;
    int i;
    for(i = 0; i < n-1; i++){
        archivo << c[i].placa << "\t" << c[i].marca << "\t" << c[i].avaluo << endl;
    }
    archivo << c[i].placa << "\t" << c[i].marca << "\t" << c[i].avaluo;

    archivo.close();
}

// Cargar datos desde archivo
int cargar(carro c[]){
    int n = 0;
    ifstream archivo;
    archivo.open("carros.txt", ios::in);
    if(archivo.fail()){
        return 0;
    }
    // Ignorar los encabezados
    archivo.ignore(MAX, '\n');
    while(!archivo.eof()){
        archivo >> c[n].placa >> c[n].marca >> c[n].avaluo;
        n++;
        archivo.ignore(MAX, '\n');
    }
    return n;
}

// Insertar datos en la estructura
int insertar(carro c[], int n){
    if(n == MAX){
        cout << "No se pueden insertar mas datos" << endl;
        return n;
    }
    cout << "Ingrese la placa del carro: ";
    cin >> c[n].placa;
    cout << "Ingrese la marca del carro: ";
    cin >> c[n].marca;
    cout << "Ingrese el avaluo del carro: ";
    cin >> c[n].avaluo;
    n++;
    return n;
}

// Listar datos de la estructura
void listar(carro c[], int n){
    for(int i = 0; i < n; i++){
        cout << i << ".- " << c[i].placa << " " << c[i].marca << " " << c[i].avaluo << endl;
    }
}

// Modifiicar datos de la estructura
int modificar(carro c[], int n){
    int pos;
    listar(c, n);
    cout << "Ingrese la posicion del carro a modificar: ";
    cin >> pos;
    if(pos < 0 || pos >= n){
        cout << "Posicion invalida" << endl;
        return n;
    }

    cout << "Ingrese la nueva placa del carro: ";
    cin >> c[pos].placa;
    cout << "Ingrese la nueva marca del carro: ";
    cin >> c[pos].marca;
    cout << "Ingrese el nuevo avaluo del carro: ";
    cin >> c[pos].avaluo;

    return n;
}

// Menu
void menu(){
    cout << "1. Insertar" << endl;
    cout << "2. Modificar" << endl;
    cout << "3. Listar" << endl;
    cout << "0. Salir" << endl;
}

// Main
int main(){
    carro c[MAX];
    int n = 0;
    // Cargo los datos desde el archivo
    n = cargar(c);
    int opcion;
    do{
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                n = insertar(c, n);                
                guardar(c, n);
                break;
            case 2:
                n = modificar(c, n);
                guardar(c, n);
                break;
            case 3:
                listar(c, n);
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }while(opcion != 0);
    return 0;
}