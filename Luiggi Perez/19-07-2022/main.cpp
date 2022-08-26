#include <iostream>
#include <string>
// Colores de impresion
#define RESET "\x1B[0m"
#define ROJO "\x1B[31m"
#define VERDE "\x1B[32m"
#define AZUL "\x1B[34m"
#define AMARILLO "\x1B[33m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"


using namespace std;

bool es_bisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}
// formato: dd mm aaaa
bool valida_fecha(string fecha) {
    int dia, mes, anio;
    sscanf(fecha.c_str(), "%d %d %d", &dia, &mes, &anio);
    if (dia < 1 || dia > 31) return false;
    if (mes < 1 || mes > 12) return false;
    if (mes == 2 && dia > 29) return false;
    if (mes == 2 && dia == 29 && !es_bisiesto(anio)) return false;
    return true;
}
// formato: hh mm
bool valida_hora(string hora) {
    int horas, minutos;
    sscanf(hora.c_str(), "%d %d", &horas, &minutos);
    if (horas < 0 || horas > 23) return false;
    if (minutos < 0 || minutos > 59) return false;
    return true;
}
// valida que la fecha de salida solo puede ser igual o 1 dia despues de la fecha de ingreso, si la fecha de salida es igual a la de ingreso, la hora de salida debe ser mayor a la de ingreso
bool valida_fecha_hora_de_salida(string fecha_ingreso, string hora_ingreso, string fecha_salida, string hora_salida) {
    int dia_ingreso, mes_ingreso, anio_ingreso, hora_ingreso_i, minutos_ingreso;
    int dia_salida, mes_salida, anio_salida, hora_salida_i, minutos_salida;
    sscanf(fecha_ingreso.c_str(), "%d %d %d", &dia_ingreso, &mes_ingreso, &anio_ingreso);
    sscanf(hora_ingreso.c_str(), "%d %d", &hora_ingreso_i, &minutos_ingreso);
    sscanf(fecha_salida.c_str(), "%d %d %d", &dia_salida, &mes_salida, &anio_salida);
    sscanf(hora_salida.c_str(), "%d %d", &hora_salida_i, &minutos_salida);
    if (anio_salida < anio_ingreso) return false;
    if (anio_salida == anio_ingreso && mes_salida < mes_ingreso) return false;
    if (anio_salida == anio_ingreso && mes_salida == mes_ingreso && dia_salida < dia_ingreso) return false;
    if (anio_salida == anio_ingreso && mes_salida == mes_ingreso && dia_salida == dia_ingreso && hora_salida_i < hora_ingreso_i) return false;
    if (anio_salida == anio_ingreso && mes_salida == mes_ingreso && dia_salida == dia_ingreso && hora_salida_i == hora_ingreso_i && minutos_salida < minutos_ingreso) return false;
    return true;
}
// a_cadena: string a convertir a cadena
string a_cadena(int a_cadena) {
    string cadena;
    while (a_cadena > 0) {
        cadena += (a_cadena % 10) + '0';
        a_cadena /= 10;
    }
    for (int i = 0; i < cadena.length() / 2; i++) {
        char aux = cadena[i];
        cadena[i] = cadena[cadena.length() - i - 1];
        cadena[cadena.length() - i - 1] = aux;
    }
    return cadena;
}
// formato: Total horas trabajadas: hh hora(s) mm minuto(s)
string calcula_total_horas_trabajadas(string fecha_ingreso, string hora_ingreso, string fecha_salida, string hora_salida) {
    int dia_ingreso, mes_ingreso, anio_ingreso, hora_ingreso_i, minutos_ingreso;
    int dia_salida, mes_salida, anio_salida, hora_salida_i, minutos_salida;
    sscanf(fecha_ingreso.c_str(), "%d %d %d", &dia_ingreso, &mes_ingreso, &anio_ingreso);
    sscanf(hora_ingreso.c_str(), "%d %d", &hora_ingreso_i, &minutos_ingreso);
    sscanf(fecha_salida.c_str(), "%d %d %d", &dia_salida, &mes_salida, &anio_salida);
    sscanf(hora_salida.c_str(), "%d %d", &hora_salida_i, &minutos_salida);
    int horas_trabajadas = hora_salida_i - hora_ingreso_i;
    int minutos_trabajados = minutos_salida - minutos_ingreso;
    if (minutos_trabajados < 0) {
        horas_trabajadas--;
        minutos_trabajados += 60;
    }
    if (horas_trabajadas < 0) {
        horas_trabajadas += 24;
    }
    return "Total horas trabajadas: " + a_cadena(horas_trabajadas) + " hora(s) " + a_cadena(minutos_trabajados) + " minuto(s)";
}

int main() {
    string fecha_ingreso, hora_ingreso, fecha_salida, hora_salida;
    cout << ROJO << "Ingrese la fecha de ingreso (dd mm aaaa): " << VERDE;
    getline(cin, fecha_ingreso);    
    cout << AZUL << "Ingrese la hora de ingreso (hh mm): " << VERDE;
    getline(cin, hora_ingreso);
    cout << ROJO <<  "Ingrese la fecha de salida (dd mm aaaa): " << VERDE;
    getline(cin, fecha_salida);
    cout << AZUL <<"Ingrese la hora de salida (hh mm): " << VERDE;
    getline(cin, hora_salida);
    if (valida_fecha(fecha_ingreso) && valida_hora(hora_ingreso) && valida_fecha(fecha_salida) && valida_hora(hora_salida) && valida_fecha_hora_de_salida(fecha_ingreso, hora_ingreso, fecha_salida, hora_salida)) {
        cout << AMARILLO << calcula_total_horas_trabajadas(fecha_ingreso, hora_ingreso, fecha_salida, hora_salida);
    } else {
        cout << "Fecha o hora invalida";
    }
    return 0;
}

