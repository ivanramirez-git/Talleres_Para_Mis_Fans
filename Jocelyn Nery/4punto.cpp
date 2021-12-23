#include <iostream>

using namespace std;

struct libro{
    string titulo;
    string autor;
    int anio;
    string editorial;
    int edicion;
    string codigo;

};

// Generar codigo de libro
string generarCodigo(libro l){
    string codigo = l.autor.substr(0,4) + l.editorial.substr(0,3) + to_string(l.anio) + l.titulo.substr(0,4) + to_string(l.edicion)[0];
    cout << "Codigo: " << codigo << endl;
    return codigo;
}

int main(){
    libro l;
    cout << "Ingrese el titulo del libro: ";
    cin >> l.titulo;
    cout << "Ingrese el autor del libro: ";
    cin >> l.autor;
    cout << "Ingrese el año de publicacion del libro: ";
    cin >> l.anio;
    cout << "Ingrese la editorial del libro: ";
    cin >> l.editorial;
    cout << "Ingrese la edicion del libro: ";
    cin >> l.edicion;
    l.codigo = generarCodigo(l);
    return 0;
}