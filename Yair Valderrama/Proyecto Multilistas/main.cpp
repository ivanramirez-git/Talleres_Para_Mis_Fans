#include <iostream>
#include <math.h>
#include "listaT.h"
#define PI 3.14159265358979323846

using namespace std;
/*
    SISTEMA UMBRAL DE CONTROL DE PLAGAS
    OMAR DAVID VALDERRAMA GUTIERREZ- 67000516

*/

/*
    Aplicacion
    Multilista 1
        Principal: cultivo
            Datos:
                Nombre Cultivo
                Numero Hectareas
        Secundaria: plagas
            Datos:
                Nombre Plaga
                Numero Frecuencia en kHz

    

*/

struct plaga{
    string nombre;
    float frecuencia;   
};

struct cultivo{
    string nombre;
    int hectareas;
    Lista<plaga> plagas; 
};

// siguientesT template <class T>
template <class T>
T siguientesT(Lista<T> lista, int longitud)
{
    if(longitud==0)
    {
        T a = lista.cabeza->dato;
        return a;
    }
    lista.cabeza = lista.cabeza->siguiente;
    return siguientesT(lista, longitud-1);
}

Lista<cultivo> ingresarDatosQuemados(){
    Lista<cultivo> cultivos;
    Lista<plaga> plagas;

    cultivos.listaVacia();
    plagas.listaVacia();

    cultivo c;
    plaga p;
    
    // Llenar lista de cultivos
    c.nombre = "Maiz";
    c.hectareas = 100;
    // Llenar lista de plagas    
    p.nombre = "Mosca Blanca";
    p.frecuencia = 0.1;
    plagas.insertarCabeza(p);
    p.nombre = "Topos";
    p.frecuencia = 0.2;
    plagas.insertarCabeza(p);
    p.nombre = "Grillos";
    p.frecuencia = 0.3;
    plagas.insertarCabeza(p);
    p.nombre = "Saltamontes";
    p.frecuencia = 0.4;
    plagas.insertarCabeza(p);
    p.nombre = "Araña";
    p.frecuencia = 0.5;
    plagas.insertarCabeza(p);

    c.plagas = plagas;
    cultivos.insertarCabeza(c);

    plagas.listaVacia();

    c.nombre = "Cebolla";
    c.hectareas = 200;
    // Llenar lista de plagas
    p.nombre = "Alacrán cebollero";
    p.frecuencia = 0.1;
    plagas.insertarCabeza(p);
    p.nombre = "Mosca de la cebolla";
    p.frecuencia = 0.2;
    plagas.insertarCabeza(p);
    p.nombre = "Gusanos de alambre";
    p.frecuencia = 0.3;
    plagas.insertarCabeza(p);
    p.nombre = "Nematodos";
    p.frecuencia = 0.4;
    plagas.insertarCabeza(p);

    c.plagas = plagas;
    cultivos.insertarCabeza(c);

    plagas.listaVacia();

    c.nombre = "Tomate";
    c.hectareas = 300;
    // Llenar lista de plagas
    p.nombre = "Araña Roja";
    p.frecuencia = 0.1;
    plagas.insertarCabeza(p);
    p.nombre = "Minador";
    p.frecuencia = 0.2;
    plagas.insertarCabeza(p);
    p.nombre = "Mosca Blanca";
    p.frecuencia = 0.3;
    plagas.insertarCabeza(p);
    p.nombre = "Polilla del tomate";
    p.frecuencia = 0.4;
    plagas.insertarCabeza(p);

    c.plagas = plagas;
    cultivos.insertarCabeza(c);    

    // Fin llenado de lista de cultivos
    return cultivos;    

}

void imprimirCultivos(Lista<cultivo> cultivos){
    for(int i = 0; i < cultivos.longitud(); i++){
        cultivo c = siguientesT(cultivos, i);
        cout << "Nombre: " << c.nombre << endl;
        cout << "Hectareas: " << c.hectareas << endl;
        cout << "Plagas: " << endl;
        for(int j = 0; j < c.plagas.longitud(); j++){
            plaga p = siguientesT(c.plagas, j);
            cout << "\tNombre: " << p.nombre << endl;
            cout << "\tFrecuencia: " << p.frecuencia << endl;
        }
    }
}

void imprimirCultivosJSON(Lista<cultivo> cultivos){
    for(int i = 0; i < cultivos.longitud(); i++){
        cultivo c = siguientesT(cultivos, i);
        cout << "{" << endl;
        cout << "\t\"nombre\": \"" << c.nombre << "\"," << endl;
        cout << "\t\"hectareas\": " << c.hectareas << "," << endl;
        cout << "\t\"plagas\": [" << endl;
        for(int j = 0; j < c.plagas.longitud(); j++){
            plaga p = siguientesT(c.plagas, j);
            cout << "\t\t{" << endl;
            cout << "\t\t\t\"nombre\": \"" << p.nombre << "\"," << endl;
            cout << "\t\t\t\"frecuencia\": " << p.frecuencia << endl;
            if(j != c.plagas.longitud() - 1)
                cout << "\t\t}," << endl;
            else
                cout << "\t\t}" << endl;
        }
        if(i != cultivos.longitud() - 1)
            cout << "\t]," << endl;
        else
            cout << "\t]" << endl;
        cout << "}" << endl;
    }
}

// Imprime lista numerada de cultivos
void imprimirCultivosNumerados(Lista<cultivo> cultivos){
    for(int i = 0; i < cultivos.longitud(); i++){
        cultivo c = siguientesT(cultivos, i);
        cout << i+1 << ". " << c.nombre << endl;
    }
}

// Retorna cultivo indicado de acuerdo a lista numerada de cultivos
cultivo obtenerCultivo(Lista<cultivo> cultivos, int num){
    return siguientesT(cultivos, num-1);
}

// Imprime lista numerada de plagas segun indice del cultivo
void imprimirPlagasNumeradas(cultivo c){
    for(int i = 0; i < c.plagas.longitud(); i++){
        plaga p = siguientesT(c.plagas, i);
        cout << i+1 << ". " << p.nombre << endl;
    }
}

// Retorna plaga indicada de acuerdo a la lista numerada de plagas
plaga obtenerPlaga(cultivo c, int indice){
    return siguientesT(c.plagas, indice-1);
}

// Imprime todas las plagas de todos los cultivos sin repetir
void imprimirPlagasConocidasJSON(Lista<cultivo> cultivos){
    Lista<plaga> plagas;
    plagas.listaVacia();
    for(int i = 0; i < cultivos.longitud(); i++){
        cultivo c = siguientesT(cultivos, i);
        for(int j = 0; j < c.plagas.longitud(); j++){
            plaga p = siguientesT(c.plagas, j);
            plagas.insertarCabeza(p);
        }
    }
    cout << "{" << endl;
    cout << "\t\"plagas\": [" << endl;
    for(int i = 0; i < plagas.longitud(); i++){
        plaga p = siguientesT(plagas, i);
        cout << "\t\t{" << endl;
        cout << "\t\t\t\"nombre\": \"" << p.nombre << "\"," << endl;
        cout << "\t\t\t\"frecuencia\": " << p.frecuencia << endl;
        if(i != plagas.longitud() - 1)
            cout << "\t\t}," << endl;
        else
            cout << "\t\t}" << endl;
    }
    cout << "\t]" << endl;
    cout << "}" << endl;
}

// Imprime lista numerada de plagas conocidas sin repetir
void imprimirPlagasConocidas(Lista<cultivo> cultivos){
    Lista<plaga> plagas;
    plagas.listaVacia();
    for(int i = 0; i < cultivos.longitud(); i++){
        cultivo c = siguientesT(cultivos, i);
        for(int j = 0; j < c.plagas.longitud(); j++){
            plaga p = siguientesT(c.plagas, j);
            plagas.insertarCabeza(p);
        }
    }
    for(int i = 0; i < plagas.longitud(); i++){
        plaga p = siguientesT(plagas, i);
        cout << i << ": " << p.nombre << endl;
    }
}

// Calcular cuantos dispositivos cubren el area de los cultivos
int calcularDispositivos(cultivo c, float radioDispositivoMetros){
    // Calcular el area de los dispositivos
    float areaDispositivos = PI * radioDispositivoMetros * radioDispositivoMetros;
    
    // Calcular el area de los cultivos 1 hectarea = 10000 metros cuadrados
    float areaCultivos = c.hectareas * 10000;

    // Calcular cuantos dispositivos que cubren el cultivo
    float dispositivos = areaCultivos / areaDispositivos;
    return dispositivos + 1;
}

// plagaNombre(cultivos, indice, indicePlaga)
// Devuelve el nombre de la plaga en el indicePlaga del cultivo en el indice
string plagaNombre(Lista<cultivo> cultivos, int indice, int indicePlaga){
    cultivo c = siguientesT(cultivos, indice);
    plaga p = siguientesT(c.plagas, indicePlaga);
    return p.nombre;
}

// cultivoNombre(cultivos, indice)
// Devuelve el nombre del cultivo en el indice
string cultivoNombre(Lista<cultivo> cultivos, int indice){
    cultivo c = siguientesT(cultivos, indice);
    return c.nombre;
}

// recomendarFrecuencia(cultivos, indice, indicePlaga);
// Devuelve la frecuencia recomendada de la plaga en el indicePlaga del cultivo en el indice
float recomendarFrecuencia(Lista<cultivo> cultivos, int indice, int indicePlaga){
    cultivo c = siguientesT(cultivos, indice);
    plaga p = siguientesT(c.plagas, indicePlaga);
    return p.frecuencia;
}

// Funcion que inscribe una plaga en un cultivo pidiendo los datos de la plaga
void inscribirPlagas(cultivo &c){
    plaga p;
    cout << "Nombre de la plaga: ";
    cin >> p.nombre;
    cout << "Frecuencia de la plaga: ";
    cin >> p.frecuencia;
    c.plagas.insertarCabeza(p);
}

// Funcion que agrega un cultivo a la lista de cultivos pidiendo los datos del cultivo y de las plagas, agregando plagas hasta que el usuario indique que no quiere agregar mas plagas
void agregarCultivo(Lista<cultivo> &cultivos){
    string nombre;
    float hectareas;
    cout << "Ingrese el nombre del cultivo: ";
    cin >> nombre;
    cout << "Ingrese el numero de hectareas del cultivo: ";
    cin >> hectareas;
    cultivo c;
    c.nombre = nombre;
    c.hectareas = hectareas;
    int opcion;
    cout << "Desea agregar plagas al cultivo? (1. Si, 2. No): ";
    cin >> opcion;
    while(opcion == 1){
        inscribirPlagas(c);
        cout << "Desea agregar plagas al cultivo? (1. Si, 2. No): ";
        cin >> opcion;
    }
    cultivos.insertarCabeza(c);
}


int main(){
    Lista<cultivo> cultivos;
    cultivos.listaVacia();

    cultivos = ingresarDatosQuemados();
    /*
    cout << "La longitud de la lista es: " << cultivos.longitud() << endl;

    //imprimirCultivosJSON(cultivos);

    // Calcular cuantos dispositivos se necesitan en cada cultivo para controlar la plag
    // Ingresar datos del dispositivo de ultrasonidos

    cultivo consultaCultivo;
    plaga consultaPlaga;


    cout << "Ingrese el alcance del dispositivo en metros: ";
    float alcance;
    cin >> alcance;

    cout << "Lista de cultivos:" << endl;
    imprimirCultivosNumerados(cultivos);

    cout << "Ingrese el indice del cultivo que desea controlar: ";
    int indiceCultivo;
    cin >> indiceCultivo;

    consultaCultivo = obtenerCultivo(cultivos, indiceCultivo);

    cout << "Lista de plagas del cultivo " << consultaCultivo.nombre << ":" << endl;
    imprimirPlagasNumeradas(consultaCultivo);

    cout << "Ingrese el indice de la plaga que desea controlar: ";
    int indicePlaga;
    cin >> indicePlaga;

    consultaPlaga = obtenerPlaga(consultaCultivo, indicePlaga);

    // Calcular cuantos dispositivos cubren el area del cultivo
    int dispositivos = calcularDispositivos(consultaCultivo, alcance);
    cout << "Se necesitan " << dispositivos << " dispositivos para controlar la plaga " << consultaPlaga.nombre << " en el cultivo " << consultaCultivo.nombre << endl;

    // Recomendar freciencia para la configuracion del dispositivo para controlar la plaga consultada
    cout << "La frecuencia recomendada para la plaga " << consultaPlaga.nombre << " en el dispositivo es: " << consultaPlaga.frecuencia << " kHz."<< endl;

    // Informacion del cultivos
    // Preguntar si desea toda la informacion de los cultivos
    cout << "Desea toda la informacion de los cultivos? (s/n): ";
    char respuesta;
    cin >> respuesta;
    if(respuesta == 's'){
        imprimirCultivosJSON(cultivos);
    }
    */

    // Menu repetitivo
    /*
    Agregar cultivo
    Calcular cuantos dispositivos cubren el area del cultivo
    Recomendar frecuencia para la configuracion del dispositivo para controlar la plaga consultada
    Informacion de los cultivos
    Salir
    */
    int opcion;
    do{
        cout << "Menu:" << endl;
        cout << "1. Agregar cultivo" << endl;
        cout << "2. Calcular cuantos dispositivos cubren el area del cultivo" << endl;
        cout << "3. Recomendar frecuencia para la configuracion del dispositivo para controlar la plaga consultada" << endl;
        cout << "4. Informacion de los cultivos" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        // Menu con if
        if(opcion == 1){
            agregarCultivo(cultivos);
        }
        else if(opcion == 2){
            cout << "Ingrese el alcance del dispositivo en metros: ";
            float alcance;
            cin >> alcance;
            cout << "Lista de cultivos:" << endl;
            imprimirCultivosNumerados(cultivos);
            cout << "Ingrese el indice del cultivo que desea controlar: ";
            int indiceCultivo;
            cin >> indiceCultivo;
            cultivo consultaCultivo = obtenerCultivo(cultivos, indiceCultivo);
            cout << "Se necesitan " << calcularDispositivos(consultaCultivo, alcance) << " dispositivos para controlar la plaga en el cultivo " << consultaCultivo.nombre << endl;
        }
        else if(opcion == 3){
            cout << "Ingrese el alcance del dispositivo en metros: ";
            float alcance;
            cin >> alcance;
            cout << "Lista de cultivos:" << endl;
            imprimirCultivosNumerados(cultivos);
            cout << "Ingrese el indice del cultivo que desea controlar: ";
            int indiceCultivo;
            cin >> indiceCultivo;
            cultivo consultaCultivo = obtenerCultivo(cultivos, indiceCultivo);
            cout << "Lista de plagas del cultivo " << consultaCultivo.nombre << ":" << endl;
            imprimirPlagasNumeradas(consultaCultivo);
            cout << "Ingrese el indice de la plaga que desea controlar: ";
            int indicePlaga;
            cin >> indicePlaga;
            plaga consultaPlaga = obtenerPlaga(consultaCultivo, indicePlaga);
            cout << "La frecuencia recomendada para la plaga " << consultaPlaga.nombre << " en el dispositivo es: " << consultaPlaga.frecuencia << " kHz."<< endl;
        }
        else if(opcion == 4){
            imprimirCultivosJSON(cultivos);
        }
        else if(opcion == 5){
            cout << "Saliendo..." << endl;
        }
        else{
            cout << "Opcion invalida" << endl;
        }

    }while(opcion != 5);


    return 0;
}
