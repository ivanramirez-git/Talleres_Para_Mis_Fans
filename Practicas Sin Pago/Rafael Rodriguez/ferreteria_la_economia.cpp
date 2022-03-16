#include <iostream>
#include <time.h>

using namespace std;

double tiempo_inicial, tiempo_pausado, tiempo_actual;
bool corriendo, pausado, detenido;

// Cronometro: iniciar, pausar, reanudar, detener, obtener tiempo transcurrido
void iniciar();
void pausar();
void reanudar();
void detener();
void obtener_tiempo_transcurrido();
void refrescar_tiempo();
void real();

int main()
{
    // Menu
    int opcion;
    do
    {
        cout << "1. Iniciar cronometro" << endl;
        cout << "2. Pausar cronometro" << endl;
        cout << "3. Reanudar cronometro" << endl;
        cout << "4. Detener cronometro" << endl;
        cout << "5. Obtener tiempo transcurrido" << endl;
        cout << "6. Mostrar el coronometro en tiempo real" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:
            cout << "Iniciando cronometro..." << endl;
            iniciar();
            break;
        case 2:
            cout << "Pausando cronometro..." << endl;
            pausar();
            break;
        case 3:
            cout << "Reanudando cronometro..." << endl;
            reanudar();
            break;
        case 4:
            cout << "Deteniendo cronometro..." << endl;
            detener();
            break;
        case 5:
            cout << "Obteniendo tiempo transcurrido..." << endl;
            obtener_tiempo_transcurrido();
            break;
        case 6:
            cout << "Mostrando el cronometro en tiempo real..." << endl;
            real();
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

    } while (opcion != 0);

    return 0;
}

void iniciar()
{
    tiempo_inicial = clock();
    corriendo = true;
    pausado = false;
    detenido = false;
}

void pausar()
{
    if (corriendo)
    {
        tiempo_pausado = clock();
        corriendo = false;
        pausado = true;
        detenido = false;
    }
    else
    {
        cout << "El cronometro no esta corriendo" << endl;
    }
}

void reanudar()
{
    if (pausado)
    {
        tiempo_inicial += clock() - tiempo_pausado;
        corriendo = true;
        pausado = false;
        detenido = false;
    }
    else
    {
        cout << "El cronometro no esta pausado" << endl;
    }
}

void detener()
{
    if (corriendo || pausado)
    {
        tiempo_actual = clock();
        tiempo_inicial = tiempo_actual;
        corriendo = false;
        pausado = false;
        detenido = true;
    }
    else
    {
        cout << "El cronometro no esta corriendo ni pausado" << endl;
    }
}

void obtener_tiempo_transcurrido()
{
    if (detenido)
    {
        cout << "El tiempo transcurrido es: " << (tiempo_actual - tiempo_inicial) / CLOCKS_PER_SEC << " segundos" << endl;
    }
    else if (pausado)
    {
        cout << "El tiempo transcurrido es: " << (tiempo_pausado - tiempo_inicial) / CLOCKS_PER_SEC << " segundos" << endl;
    }
    else
    {
        cout << "El tiempo transcurrido es: " << (clock() - tiempo_inicial) / CLOCKS_PER_SEC << " segundos" << endl;
    }
}

void refrescar_tiempo()
{
    if (corriendo)
    {
        tiempo_actual = clock();
    }
}

void real()
{
    int segundos, minutos, horas;
    double tiempo_transcurrido;
    bool corriendo_aux, pausado_aux, detenido_aux;
    corriendo_aux = corriendo;
    pausado_aux = pausado;
    detenido_aux = detenido;
    int inicio, salida = 30;

    cout << "Cuantos segundos quieres que el cronometro muestre? ";
    cin >> salida;
    cout << endl;
    if (!corriendo)
    {
        iniciar();
    }

    while (true)
    {
        refrescar_tiempo();
        tiempo_transcurrido = (tiempo_actual - tiempo_inicial) / CLOCKS_PER_SEC;
        segundos = tiempo_transcurrido;
        minutos = segundos / 60;
        segundos = segundos % 60;
        horas = minutos / 60;
        minutos = minutos % 60;
        string segundos_str = to_string(segundos);
        string minutos_str = to_string(minutos);
        string horas_str = to_string(horas);
        inicio = segundos;
        if (segundos < 10)
        {
            segundos_str = "0" + segundos_str;
        }
        if (minutos < 10)
        {
            minutos_str = "0" + minutos_str;
        }
        if (horas < 10)
        {
            horas_str = "0" + horas_str;
        }
        // Eliminar las demas lineas en la consola e imprimir una sola linea del tiempo
        cout << horas_str << ":" << minutos_str << ":" << segundos_str << endl;

        if (corriendo_aux)
        {
            corriendo = true;
        }
        if (pausado_aux)
        {
            pausado = true;
        }
        if (detenido_aux)
        {
            detenido = true;
        }
        if (detenido)
        {
            break;
        }
        if (inicio >= salida || !corriendo)
        {
            break;
        }
    }
}