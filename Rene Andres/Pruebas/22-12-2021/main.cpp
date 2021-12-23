#include <iostream>
#include <fstream>
#include <vector>
/*
Dado cualquier mapa geografico con regiones continuas, entonces el mapa puede ser coloreado con cuatro colores diferentes, de forma que no queden regiones adyacentes con el
mismo color. Asumiremos que las regiones adyacentes comparten no solo un punto, sino todo un segmento de borde
(frontera) en comun.
En la figura se puede observar un mapa coloreado con 4 colores. Se desea escribir un programa que permita almacenar
una instancia del problema anterior.
*/

using namespace std;


// 1. (0.8 P) Almacenamiento de un conjunto de países
// • Completar la siguiente clase que permite almacenar un país:
class pais{
private:
    int id;
    string nombre;
    double poblacion; // En millones
public:
    // Constructor
    pais(int id, string nombre, double poblacion){
        this->id = id;
        this->nombre = nombre;
        this->poblacion = poblacion;
    }
    // Constructor vacio
    pais(){
        this->id = 0;
        this->nombre = "";
        this->poblacion = 0;
    }
    // Sobrecarga de operador <<
    friend ostream& operator<<(ostream& os, const pais& p){
        os << "Id: " << p.id;
        os << " Nombre: " << p.nombre;
        os << " Poblacion: " << p.poblacion;
        return os;
    }
    // Sobrecarga de operador >>
    friend istream& operator>>(istream& is, pais& p){
        // cout << "Id: ";
        is >> p.id;
        // cout << "Nombre: ";
        is >> p.nombre;
        // cout << "Poblacion: ";
        is >> p.poblacion;
        return is;
    }
    // Setters
    void setId(int id){
        this->id = id;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setPoblacion(double poblacion){
        this->poblacion = poblacion;
    }
    // Getters
    int getId(){
        return this->id;
    }
    string getNombre(){
        return this->nombre;
    }
    double getPoblacion(){
        return this->poblacion;
    }
};

// • Escribir una función que permita leer un conjunto de países desde el archivo ”países.txt” bajo el formato:
/*
n (numero de paises)
id  nombre_pais poblacionn
... ......  ......
*/
// y almacene la informacion en un arreglo dinamico ( pais * datos paises ).
int leer_paises(pais *&datos_paises){
    ifstream archivo("paises.txt");
    int n;
    archivo >> n;
    datos_paises = new pais[n];
    for(int i = 0; i < n; i++){
        archivo >> datos_paises[i];
    }
    archivo.close();
    return n;
}

// 2. (1.4 P) Usando los datos anteriores es posible definir las fronteras ( regiones adyacentes ) entre los distintos países. Definimos el par (id pais1, id pais2) si los países con dichos índices comparten una frontera.
// • Completar las siguientes clases:
class frontera
{
private:
    int id_pais1;
    int id_pais2;
public:
    // Constructor
    frontera(int id_pais1, int id_pais2){
        this->id_pais1 = id_pais1;
        this->id_pais2 = id_pais2;
    }
    // Constructor vacio
    frontera(){
        this->id_pais1 = 0;
        this->id_pais2 = 0;
    }
    // Sobrecarga de operador <<
    friend ostream& operator<<(ostream& os, const frontera& f){
        os << "Id 1: " << f.id_pais1;
        os << " Id 2: " << f.id_pais2;
        return os;
    }
    // Sobrecarga de operador >>
    friend istream& operator>>(istream& is, frontera& f){
        // cout << "Id 1: ";
        is >> f.id_pais1;
        // cout << "Id 2: ";
        is >> f.id_pais2;
        return is;
    }
    // Setters
    void set_id_pais1(int id_pais1){
        this->id_pais1 = id_pais1;
    }
    void set_id_pais2(int id_pais2){
        this->id_pais2 = id_pais2;
    }
    // Getters
    int get_id_pais1(){
        return this->id_pais1;
    }
    int get_id_pais2(){
        return this->id_pais2;
    }
};
class mapa:public vector<frontera>
{
private:
int n_paises;//Número de países
public:
    // Constructor
    mapa(int n_paises){
        this->n_paises = n_paises;
    }
    // Constructor vacio
    mapa(){
        this->n_paises = 0;
    }
    // Destructor
    ~mapa(){
        this->n_paises = 0;
    }
    // mayor(): Retorna el id del país con mayor número de países adyacentes.
    int mayor(){
        int mayor = 0;
        int contador_fronteras = 0;
        int id_mayor = 0;
        for(int i = 0; i < this->n_paises; i++){
            contador_fronteras = 0;
            for(int j = 0; j < this->size(); j++){
                if(this->at(j).get_id_pais1() == i){
                    contador_fronteras++;
                }
            }
            if(contador_fronteras > mayor){
                mayor = contador_fronteras;
                id_mayor = i;
            }
        }
        return id_mayor;
    }
    // sin frontera(int id pais): Retorna un vector con los id de los países que no comparten frontera con el identificador de entrada id país.
    vector<int> sin_frontera(int id_pais){
        vector<int> sin_frontera;
        vector<int> frontera_pais;
        // Buscar los que si comparten frontera con el país
        for(int i = 0; i < this->size(); i++){
            if(this->at(i).get_id_pais1() == id_pais){
                frontera_pais.push_back(this->at(i).get_id_pais2());
            }
            if(this->at(i).get_id_pais2() == id_pais){
                frontera_pais.push_back(this->at(i).get_id_pais1());
            }
        }
        // Agregar los que no comparten frontera con el país
        for(int i = 0; i < this->n_paises; i++){
            if(i != id_pais){
                bool compartido = false;
                for(int j = 0; j < frontera_pais.size(); j++){
                    if(i == frontera_pais[j]){
                        compartido = true;
                    }
                }
                if(!compartido){
                    sin_frontera.push_back(i);
                }
            }
        }
        return sin_frontera;
    }
    // con frontera(int id pais, pais * datos paises): Retorna un vector con los nombres de los países que comparten frontera con el identificador de entrada id país.
    vector<string> con_frontera(int id_pais, pais * datos_paises){
        vector<string> con_frontera;
        for(int i = 0; i < this->size(); i++){
            if(this->at(i).get_id_pais1() == id_pais)
                con_frontera.push_back(datos_paises[this->at(i).get_id_pais2()].getNombre());
            if(this->at(i).get_id_pais2() == id_pais)
                con_frontera.push_back(datos_paises[this->at(i).get_id_pais1()].getNombre());
        }
        return con_frontera;
    }
    // Sobrecargar >> usando el siguiente formato:
/*
numero_de_paises
numero_de_pares_fronterizos
id_pais_1 id_pais_2
.... ....
*/
    friend istream& operator>>(istream& is, mapa& m){
        int n_fronteras;
        is >> m.n_paises;
        is >> n_fronteras;
        for(int i = 0; i < n_fronteras; i++){
            frontera f;
            is >> f;
            m.push_back(f);
        }
        return is;
    }
    // Sobrecargar <<
    friend ostream& operator<<(ostream& os, const mapa& m){
        os << "Numero de paises: " << m.n_paises << endl;
        os << "Numero de fronteras: " << m.size() << endl;
        for(int i = 0; i < m.size(); i++){
            os << m.at(i) << endl;
        }
        return os;
    }
};
// • Leer los datos desde el archivo ”frontera.txt”
int leer_frontera(mapa &m, pais * datos_paises){
    ifstream archivo("frontera.txt");
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return -1;
    }
    archivo >> m;
    archivo.close();
    return 0;
}

// Pruebas 
// Punto 1
void pruebas_leer_paises(){
    pais *datos_paises;
    int n = leer_paises(datos_paises);
    cout << "Numero de paises: " << n << endl;
    for(int i = 0; i < n; i++){
        cout << datos_paises[i] << endl;
    }
}

// Punto 2
void pruebas_leer_frontera(){
    mapa m;
    pais *datos_paises;
    int n = leer_paises(datos_paises);
    leer_frontera(m, datos_paises);
    cout << m << endl;
    // Funciones miembro
    cout << "Mayor: " << m.mayor() << endl;
    for(int i = 0; i < n; i++){
        vector<int> sin_frontera = m.sin_frontera(i);
        cout << "Sin frontera de " << datos_paises[i].getNombre() << ": ";
        for(int j = 0; j < sin_frontera.size(); j++){
            cout << datos_paises[sin_frontera[j]].getNombre() << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        vector<string> con_frontera = m.con_frontera(i, datos_paises);
        cout << "Con frontera de " << datos_paises[i].getNombre() << ": ";
        for(int j = 0; j < con_frontera.size(); j++){
            cout << con_frontera[j] << " ";
        }
        cout << endl;
    }
}

int main(){
    // Punto 1
    cout << "Punto 1" << endl;
    pruebas_leer_paises();
    // Punto 2
    cout << "Punto 2" << endl;
    pruebas_leer_frontera();
    return 0;
}
