#include <iostream>

using namespace std;

int main(){
    int num_materias, promedio, colegiatura, iva, descuento;
    
    cout << "Ingrese el numero de materias: ";
    cin >> num_materias;
    
    cout << "Ingrese el promedio del alumno: ";
    cin >> promedio;
    
    colegiatura = num_materias * 100;
    iva = colegiatura * 0.1;
    
    if(promedio >= 9){
        descuento = colegiatura * 0.3;
        cout << "El descuento es de: " << descuento << endl;
        cout << "El total a pagar es de: " << colegiatura - descuento << endl;
        
        
    }else{
        cout << "El iva es de: " << iva << endl;
        cout << "El total a pagar es de: " << colegiatura + iva << endl;        
    }
    
    return 0;
}