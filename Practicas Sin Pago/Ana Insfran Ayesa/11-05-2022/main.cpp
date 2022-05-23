#include <iostream>

using namespace std;

/*
La Empresa EI Porvenir S.A., desea conocer lo que debe pagar en concepto de horas extrasa
un grupo denempleados. Se sabe que una hora extra diurna, se paga el doble que una hora
normal.Y una hora extra nocturna se paga el doble de una hora normal más el 25%. Además,
que todos los empleados tienen sueldos diferentes, muestre el nuevo sueldo de cada uno de ellos
ylo que tendrá que pagar la empresa en concepto de horas extras.
*/
int main()
{
    cout << " .:: Bienvenidos a la Empresa EI Porvenir S.A. ::." << endl;
    float costo_hora_normal, costo_hora_extra_nocturna, costo_hora_extra_diurna, sueldo_total, sueldo_total_horas_extras;
    int hora_normal, hora_extra_nocturna, hora_extra_diurna;
    string salida;
    // Costo de hora normal
    cout << "Ingrese el costo de una hora normal: ";
    cin >> costo_hora_normal;
    int n = 0;
    do
    {
        n++;
        // Trabajador n
        cout << "Trabajador " << n << endl;
        // Horas normales
        cout << "Ingrese la cantidad de horas normales: ";
        cin >> hora_normal;
        // Horas extras nocturnas
        cout << "Ingrese la cantidad de horas extras nocturnas: ";
        cin >> hora_extra_nocturna;
        // Horas extras diurnas
        cout << "Ingrese la cantidad de horas extras diurnas: ";
        cin >> hora_extra_diurna;
        // Calculo de sueldo total
        sueldo_total = hora_normal * costo_hora_normal;
        sueldo_total_horas_extras = (hora_extra_nocturna * 2 * costo_hora_normal) + (hora_extra_diurna * 2 * costo_hora_normal * 1.25);
        // Salida
        cout << "Sueldo total: " << sueldo_total + sueldo_total_horas_extras << endl;
        cout << "Desea ingresar otro trabajador? (s/n): ";
        cin >> salida;
    } while (salida == "s");
    return 0;
}
