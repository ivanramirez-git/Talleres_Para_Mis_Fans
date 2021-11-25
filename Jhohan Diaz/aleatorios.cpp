#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

class azar{
    private:
        int datosNumericos[50];

    public:
        // Llena los datos de forma aleatoria ente 1 y 500 con semilla Time(0)
        void llenarDatos(){
            srand(time(0));
            for(int i=0; i<50; i++){
                datosNumericos[i] = rand()%500+1;
            }
        }
        // Imprime los datos datos = [n1, n2, n3, ..., n50]
        void mostrarDatos(){
            cout << "[";
            for(int i=0; i<50; i++){
                if(i==49)
                    cout << datosNumericos[i];
                else
                    cout << datosNumericos[i] << ", ";

            }
            cout << "]" << endl;
            cout << endl;
        }
        // Ordena los datos de menor a mayor
        void ordenarDatos(){
            int aux;
            for(int i=0; i<50; i++){
                for(int j=0; j<50; j++){
                    if(datosNumericos[i]<datosNumericos[j]){
                        aux = datosNumericos[i];
                        datosNumericos[i] = datosNumericos[j];
                        datosNumericos[j] = aux;
                    }
                }
            }
        }
        // Busca el dato buscado en los datos
        void buscarDatos(int buscado){
            int contador = 0;
            for(int i=0; i<50; i++){
                if(datosNumericos[i]==buscado){
                    contador++;
                }
            }
            if(contador==0){
                cout << "El dato buscado no se encuentra en los datos" << endl;
            }
            else{
                cout << "El dato buscado se encuentra en los datos " << contador << " veces" << endl;
            }
        }


        // Funciones de Impresion
        void media(){
            float suma = 0;
            for(int i=0; i<50; i++){
                suma += datosNumericos[i];
            }
            cout << "La media de los datos es: " << suma/50.0 << endl;
        }
        void desviacionEstandar(){
            int suma = 0;
            for(int i=0; i<50; i++){
                suma += datosNumericos[i];
            }
            int media = suma/50;
            int suma2 = 0;
            for(int i=0; i<50; i++){
                suma2 += (datosNumericos[i]-media)*(datosNumericos[i]-media);
            }
            cout << "La desviacion estandar de los datos es: " << sqrt(suma2/50) << endl;
        }
        void mayor(){
            int mayor = datosNumericos[0];
            for(int i=0; i<50; i++){
                if(datosNumericos[i]>mayor){
                    mayor = datosNumericos[i];
                }
            }
            cout << "El mayor de los datos es: " << mayor << endl;
        }
        void menor(){
            int menor = datosNumericos[0];
            for(int i=0; i<50; i++){
                if(datosNumericos[i]<menor){
                    menor = datosNumericos[i];
                }
            }
            cout << "El menor de los datos es: " << menor << endl;
        }
        void promedio(){
            float suma = 0;
            for(int i=0; i<50; i++){
                suma += datosNumericos[i];
            }
            cout << "El promedio de los datos es: " << suma/50.0 << endl;
        }
        void mediana(){
            int mediana;
            int temp[50];
            for(int i=0; i<50; i++){
                temp[i] = datosNumericos[i];
            }
            for(int i=0; i<50; i++){
                for(int j=0; j<50; j++){
                    if(temp[i]<temp[j]){
                        int aux = temp[i];
                        temp[i] = temp[j];
                        temp[j] = aux;
                    }
                }
            }
            if(temp[25]%2==0){
                mediana = (temp[25]+temp[26])/2;
            }
            else{
                mediana = temp[25];
            }
            cout << "La mediana de los datos es: " << mediana << endl;
        }
        // Constructor y Destructor
        azar(){
            llenarDatos();
            //ordenarDatos();
            mostrarDatos();
        }
        ~azar(){
            cout << "Destruyendo objeto" << endl;
        }
};

// Menu
void menu(){
    cout << "1. Media" << endl;
    cout << "2. Desviacion Estandar" << endl;
    cout << "3. Mayor" << endl;
    cout << "4. Menor" << endl;
    cout << "5. Promedio" << endl;
    cout << "6. Mediana" << endl;
    cout << "7. Buscar" << endl;
    cout << "8. Salir" << endl;
}

int main(){
    azar a = azar();
    int opcion;
    do{
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                a.media();
                break;
            case 2:
                a.desviacionEstandar();
                break;
            case 3:
                a.mayor();
                break;
            case 4:
                a.menor();
                break;
            case 5:
                a.promedio();
                break;
            case 6:
                a.mediana();
                break;
            case 7:
                int buscado;
                cout << "Ingrese el dato a buscar: ";
                cin >> buscado;
                a.buscarDatos(buscado);
                break;
            case 8:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    }while(opcion!=8);

    return 0;
}