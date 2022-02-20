#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

class empleados: public multimap<double,int> {
public:
    // constructor
    empleados(double desempeno,int id) {
        // validar que el desempeño sea mayor a 0
        if (desempeno > 0) {
            // insertar el empleado
            insert(make_pair(desempeno,id));
        }
    }
    // constructor vacio
    empleados() {
    }
    // destructor
    ~empleados() {
        // vaciar la lista
        clear();
    }
    // sobrecarga <<
    friend ostream& operator<<(ostream& os, const empleados& e) {
        // recorrer la lista
        for (auto it = e.begin(); it != e.end(); ++it) {
            // mostrar el id
            os << "{" << it->second << ", " << it->first << "} ";
        }
        // retornar el flujo
        return os;
    }
    // sobrecarga >>
    friend istream& operator>>(istream& is, empleados& e) {
        // leer el desempeño
        double desempeno;
        is >> desempeno;
        // leer el id
        int id;
        is >> id;
        // insertar el empleado
        e.insert(make_pair(desempeno,id));
        // retornar el flujo
        return is;
    }
};

// Algoritmo para agrupar n empleados en k grupos
vector< list < int > > Clasificar(empleados Em) {
    // Pedir el numero de grupos y el numero de empleados
    int k,n;
    bool valido=false;
    cout << "Grupos k: ";
    cin >> k;    
    // n es el numero de empleados
    n = Em.size();

    while(!valido){
        if(k>0 && n>0 && k<=n){
            valido=true;
        }else{
            cout << "Ingrese un numero valido: ";
            cin >> k;
        }
    }

    // Crear el vector de listas
    vector< list < int > > v;
    for(int i=0;i<k;i++){
        v.push_back(list<int>());
    }

    // i,...,n/k
    int i,i_aux,k_aux=0;

    for (i = 0; i <= (n/k); i++) {
        i_aux = i/k;
        cout << "i: " << i << " i_aux: " << i_aux << endl;
        // si i_aux es impar
        if (i_aux % 2 == 1) {
            // Agregar los empleados ((i_aux-1)(k)+1) a la lista 1,...,k
            for (int j = (i_aux-1)*k+1; j <= i_aux*k; j++) {
                v[k_aux].push_back(Em.begin()->second);
                Em.erase(Em.begin());
            }
            // incrementar k_aux
            k_aux++;
        } else {
            // Agregar los empleados ((i_aux-1)(k)+k) a la lista k,...,1
            for (int j = (i_aux-1)*k+k; j >= i_aux*k; j--) {
                v[k_aux].push_back(Em.begin()->second);
                Em.erase(Em.begin());
            }
            // decrementar k_aux
            k_aux--;
        }
    }
    // Agregar los empleados restantes a la lista k
    for (auto it = Em.begin(); it != Em.end(); ++it) {
        v[k_aux].push_back(it->second);
    }
    // retornar el vector de listas
    return v;
}

// Pruebas
void prueba1(){
    // crear la lista
    empleados e;
    // insertar los empleados
    e.insert(make_pair(1.23,1));
    e.insert(make_pair(1.24,2));
    e.insert(make_pair(1.19,3));
    e.insert(make_pair(1.22,4));
    e.insert(make_pair(1.3,5));
    e.insert(make_pair(1.213,6));
    e.insert(make_pair(1.198,7));
    e.insert(make_pair(1.193,8));
    e.insert(make_pair(1.88,9));
    e.insert(make_pair(1.26,10));
    e.insert(make_pair(1.232,11));
    e.insert(make_pair(1.2423,12));
    e.insert(make_pair(1.31,13));
    e.insert(make_pair(1.21365,14));
    e.insert(make_pair(1.223,15));
    e.insert(make_pair(1.312,16));
    e.insert(make_pair(1.291863,17));
    e.insert(make_pair(1.181233,18));
    e.insert(make_pair(1.19987,19));
    e.insert(make_pair(1.19875,20));
    // imprimir la lista
    cout << e << endl;
    // clasificar los empleados
    vector< list < int > > resultado = Clasificar(e);
    // imprimir los grupos
    for (int i = 0; i < resultado.size(); i++) {
        cout << "Grupo " << i+1 << ": ";
        for (auto it = resultado[i].begin(); it != resultado[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

}

// Programa Principal
int main() {
    // ejecutar las pruebas
    prueba1();
    // retornar el resultado
    return 0;
}



