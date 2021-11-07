#include <iostream>

using namespace std;

#define N 6

class Polinomios {
    // Declaramos los atributos privados
    int Polinomio1[N];
    int Polinomio2[N];
    int Grado1;
    int Grado2;

    // Declaramos las funciones publicas
    public:
        void CargarPolinomios();
        void MostrarPolinomios();
        bool Iguales();
        void SumarPolinomios();
};

void Polinomios::CargarPolinomios() {
    // Inicializamos vectores
    for (int i = 0; i < N; i++) {
        Polinomio1[i] = 0;
        Polinomio2[i] = 0;
    }
    
    // Aqui ponemos un bucle while para hacer que el usuario tenga en cuenta que el grado maximo es 5
    do {
        cout << "Introduzca el valor del grado del primer polinomio (Maximo 5): ";
        cin >> Grado1;
    } while(Grado1 <= 0 || Grado1 > 5);
    cout << "Introduzca los valores del primer polinomio:\n";
    // Vamos a ir desde el final de la tabla hasta el principio para que al usuario le sea
    // más comodo poner los polinomios.
    for (int i = Grado1; i > -1; i--) {
        // Comparamos si es el termino independiente o si es una x para que no sea lioso
        if (i == 0)
            cout << "Valor del termino independiente: "; else cout << "Valor de x" << i << ": ";
        cin >> Polinomio1[i];
    }

    // Aqui ponemos un bucle while para hacer que el usuario tenga en cuenta que el grado maximo es 5
    do {
        cout << "Introduzca el valor del grado del segundo polinomio (Maximo 5): ";
        cin >> Grado2;
    } while(Grado2 <= 0 || Grado2 > 5);
    cout << "Introduzca los valores del segundo polinomio:\n";
    // Vamos a ir desde el final de la tabla hasta el principio para que al usuario le sea
    // más comodo poner los polinomios.
    for (int i = Grado2; i > -1; i--) {
        // Comparamos si es el termino independiente o si es una x para que no sea lioso
        if (i == 0)
            cout << "Termino independiente: "; else cout << "Valor de x" << i << ": ";
        cin >> Polinomio2[i];
    }
    cout << "\nSe han cargado correctamente los polinomios.";
}

void Polinomios::MostrarPolinomios() {
    cout << "Primer polinomio: ";
    // Para imprimir primero el grado 5 debemos ir desde el final hasta el principio
    for (int i = Grado1; i > -1; i--) {
        // Si el valor de un elemento es 0 no lo imprimimos y saltamos al siguiente
        if (Polinomio1[i] == 0) continue;

        if (i == 0) { // Si es el elemento del termino independiente no le ponemos x a la derecha
            // Aqui comparamos si el valor va a ser positivo para colocar el signo delante, si no no saldra y quedara raro.
            if (Polinomio1[i] > 0) cout << "+" << Polinomio1[i]; else cout << Polinomio1[i];
        } else {
            // Como no es el termino independiente le ponemos x a la derecha
            if (Polinomio1[i] > 0)
                cout << "+" << Polinomio1[i] << "x^" << i; else cout << Polinomio1[i] << "x^" << i;
        }
        cout << " ";
    }
    cout << "\nSegundo polinomio: ";
    // Para imprimir primero el grado 5 debemos ir desde el final hasta el principio
    for (int i = Grado2; i > -1; i--) {
        // Si el valor de un elemento es 0 no lo imprimimos y saltamos al siguiente
        if (Polinomio2[i] == 0) continue;

        // Si es el elemento del termino independiente no le ponemos x a la derecha
        if (i == 0) {
            // Aqui comparamos si el valor va a ser positivo para colocar el signo delante, si no no saldra y quedara raro.
            if (Polinomio2[i] > 0)
                cout << "+" << Polinomio2[i]; else cout << Polinomio2[i];
        } else {
            // Como no es el termino independiente le ponemos x a la derecha

            // Aqui comparamos si el valor va a ser positivo para colocar el signo delante, si no no saldra y quedara raro.
            if (Polinomio2[i] > 0)
                cout << "+" << Polinomio2[i] << "x^" << i; else cout << Polinomio2[i] << "x^" << i;
        }
        cout << " ";
    }
    cout << endl;
}

bool Polinomios::Iguales() {
    for (int i = 0; i < N; i++) {
        // Si alguno de los elementos de los dos polinomios (en el mismo indice) no son iguales devolvemos FALSO
        if (Polinomio1[i] != Polinomio2[i]) return false;
    }
    // Como el return automaticamente se salta el for y la funcion devolvemos true ya que nunca se
    // ha cumplido la condicion del if.
    return true;
}

void Polinomios::SumarPolinomios() {
    // Primero le mostramos al usuario los polinomios que va a sumar
    MostrarPolinomios();

    cout << "Suma de los polinomios: ";

    int grado = Grado1;
    if (Grado1 < Grado2) grado = Grado2;

    for (int i = grado; i > -1; i--) {
        // Declaramos una variable temporal que guarde el valor de la suma del indice correspondiente
        int currElemento = Polinomio1[i] + Polinomio2[i];
        if (i == 0) { // Si es el elemento del termino independiente no le ponemos x a la derecha
            // Aqui comparamos si el valor va a ser positivo para colocar el signo delante, si no no saldra y quedara raro.
            if (currElemento > 0)
                cout << "+" << currElemento; else cout << currElemento;
        } else {
            // Como no es el termino independiente le ponemos x a la derecha
            // Aqui comparamos si el valor va a ser positivo para colocar el signo delante, si no no saldra y quedara raro.
            if (currElemento > 0)
                cout << "+" << currElemento << "x^" << i; else cout << currElemento << "x^" << i;
        }
        cout << " ";
    }
}

int main() {
    // Considere que estoy en un sistema operativo de tipo Linux, de todas
    // maneras intentare poner las ordenes de Windows. Disculpe las molestias.
    int accion;
    // Declaramos una variable booleana para saber si el usuario ha cargado los polinomios
    bool cargados = false;

    Polinomios obj;

    // Ponemos dos bucles while, el primero debe ser para controlar si el usuario quiere salir
    // y el segundo para saber cuando el usuario ha seleccionado una opcion incorrecta
    do {
        do {
            cout << "\n\n\t\tOPERACIONES CON DOS POLINOMIOS\n";
            cout << "\t1. Cargar polinomios.\n";
            cout << "\t2. Mostrar polinomios.\n";
            cout << "\t3. Sumar polinomios.\n";
            cout << "\t4. Ver si los dos polinomios son iguales.\n";
            cout << "\t5. Salir.\n";
            cout << "\nSeleccione una accion: ";
            cin >> accion;
            // Si se sale del intervalo ponemos el mensaje de error
            if (accion < 1 || accion > 5) cout << "\nOpcion incorrecta. Vuelva a intentarlo.\n";
        } while(accion < 1 || accion > 5);

        cout << endl;
        switch(accion) {
            case 1:
                obj.CargarPolinomios();
                cargados = true;
                break;
            case 2:
                // Comprobar si se han cargado los polinomios
                if (cargados)
                    obj.MostrarPolinomios(); else cout << "Debe cargar los polinomios.\n";
                break;
            case 3:
                // Comprobar si se han cargado los polinomios
                if (cargados) {
                    obj.SumarPolinomios();
                } else {
                    cout << "Debe cargar los polinomios.\n";
                }
                break;
            case 4:
                // Comprobar si se han cargado los polinomios
                if (cargados) {
                    if (obj.Iguales()) {
                        cout << "Los dos polinomios son iguales.\n";
                    } else {
                        cout << "Los dos polinomios no son iguales.\n";
                    }
                } else {
                    cout << "Debe cargar los polinomios.\n";
                }
                break;
        }
    } while(accion != 5);

    cout << "Gracias por usar mi programa. Hasta pronto!\n";
    return 0;
}