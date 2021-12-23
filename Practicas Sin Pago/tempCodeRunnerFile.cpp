#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

// Funcion Lowis Elvis
bool isPrime(long int n)
{
    if (n <= 1) return false;
    int i=2;
    while(i*i<=n)
    {
        if(n%i==0) return false;
        i++;
    }
    return true;
}

// Reporte
void reporte()
{
    // Generar un reporte de rendimiento de la funcion isPrime
    bool resultado;
    int errores = 0;
    // Prueba 1:
    clock_t t1i = clock();
    resultado = isPrime(1);
    clock_t t1f = clock();
    cout << "Prueba 1: isPrime(1) = " << (resultado ? "true" : "false") << "; (" << (t1f - t1i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(1) = false" << endl;
    }
    // Prueba 2:
    clock_t t2i = clock();
    resultado = isPrime(0);
    clock_t t2f = clock();
    cout << "Prueba 2: isPrime(0) = " << (resultado ? "true" : "false") << "; (" << (t2f - t2i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(0) = false" << endl;
    }
    // Prueba 3:
    clock_t t3i = clock();
    resultado = isPrime(-1);
    clock_t t3f = clock();
    cout << "Prueba 3: isPrime(-1) = " << (resultado ? "true" : "false") << "; (" << (t3f - t3i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(-1) = false" << endl;
    }
    // Prueba 4:
    clock_t t4i = clock();
    resultado = isPrime(2);
    clock_t t4f = clock();
    cout << "Prueba 4: isPrime(2) = " << (resultado ? "true" : "false") << "; (" << (t4f - t4i) / (double)1000 << " milesimas)" << endl;
    if (!resultado){
        errores++;
        cout << "ERROR: isPrime(2) = true" << endl;
    }
    // Prueba 5:
    clock_t t5i = clock();
    resultado = isPrime(3);
    clock_t t5f = clock();
    cout << "Prueba 5: isPrime(3) = " << (resultado ? "true" : "false") << "; (" << (t5f - t5i) / (double)1000 << " milesimas)" << endl;
    if (!resultado){
        errores++;
        cout << "ERROR: isPrime(3) = true" << endl;
    }
    // Prueba 6:
    clock_t t6i = clock();
    resultado = isPrime(407);
    clock_t t6f = clock();
    cout << "Prueba 6: isPrime(407) = " << (resultado ? "true" : "false") << "; (" << (t6f - t6i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(407) = false" << endl;
    }
    // Prueba 7:
    clock_t t7i = clock();
    resultado = isPrime(999999991);
    clock_t t7f = clock();
    cout << "Prueba 7: isPrime(999999991) = " << (resultado ? "true" : "false") << "; (" << (t7f - t7i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(999999991) = false" << endl;
    }
    // Prueba 8:
    clock_t t8i = clock();
    resultado = isPrime(-13001);
    clock_t t8f = clock();
    cout << "Prueba 8: isPrime(-13001) = " << (resultado ? "true" : "false") << "; (" << (t8f - t8i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(-13001) = false" << endl;
    }
    // Prueba 9:
    clock_t t9i = clock();
    resultado = isPrime(9999997);
    clock_t t9f = clock();
    cout << "Prueba 9: isPrime(9999997) = " << (resultado ? "true" : "false") << "; (" << (t9f - t9i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(9999997) = false" << endl;
    }
    // Prueba 10:
    clock_t t10i = clock();
    resultado = isPrime(9876511);
    clock_t t10f = clock();
    cout << "Prueba 10: isPrime(9876511) = " << (resultado ? "true" : "false") << "; (" << (t10f - t10i) / (double)1000 << " milesimas)" << endl;
    if (!resultado){
        errores++;
        cout << "ERROR: isPrime(9876511) = true" << endl;
    }
    // Prueba 11:
    clock_t t11i = clock();
    resultado = isPrime(4);
    clock_t t11f = clock();
    cout << "Prueba 11: isPrime(4) = " << (resultado ? "true" : "false") << "; (" << (t11f - t11i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(4) = false" << endl;
    }
    // Prueba 12:
    clock_t t12i = clock();
    resultado = isPrime(5);
    clock_t t12f = clock();
    cout << "Prueba 12: isPrime(5) = " << (resultado ? "true" : "false") << "; (" << (t12f - t12i) / (double)1000 << " milesimas)" << endl;
    if (!resultado){
        errores++;
        cout << "ERROR: isPrime(5) = true" << endl;
    }
    // Prueba 13:
    clock_t t13i = clock();
    resultado = isPrime(6);
    clock_t t13f = clock();
    cout << "Prueba 13: isPrime(6) = " << (resultado ? "true" : "false") << "; (" << (t13f - t13i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(6) = false" << endl;
    }
    // Prueba 14:
    clock_t t14i = clock();
    resultado = isPrime(7);
    clock_t t14f = clock();
    cout << "Prueba 14: isPrime(7) = " << (resultado ? "true" : "false") << "; (" << (t14f - t14i) / (double)1000 << " milesimas)" << endl;
    if (!resultado){
        errores++;
        cout << "ERROR: isPrime(7) = true" << endl;
    }
    // Prueba 15:
    clock_t t15i = clock();
    resultado = isPrime(8);
    clock_t t15f = clock();
    cout << "Prueba 15: isPrime(8) = " << (resultado ? "true" : "false") << "; (" << (t15f - t15i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(8) = false" << endl;
    }
    // Prueba 16:
    clock_t t16i = clock();
    resultado = isPrime(9);
    clock_t t16f = clock();
    cout << "Prueba 16: isPrime(9) = " << (resultado ? "true" : "false") << "; (" << (t16f - t16i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(9) = false" << endl;
    }
    // Prueba 17:
    clock_t t17i = clock();
    resultado = isPrime(10);
    clock_t t17f = clock();
    cout << "Prueba 17: isPrime(10) = " << (resultado ? "true" : "false") << "; (" << (t17f - t17i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(10) = false" << endl;
    }
    // Prueba 18:
    clock_t t18i = clock();
    resultado = isPrime(11);
    clock_t t18f = clock();
    cout << "Prueba 18: isPrime(11) = " << (resultado ? "true" : "false") << "; (" << (t18f - t18i) / (double)1000 << " milesimas)" << endl;
    if (!resultado){
        errores++;
        cout << "ERROR: isPrime(11) = true" << endl;
    }
    // Prueba 19:
    clock_t t19i = clock();
    resultado = isPrime(12);
    clock_t t19f = clock();
    cout << "Prueba 19: isPrime(12) = " << (resultado ? "true" : "false") << "; (" << (t19f - t19i) / (double)1000 << " milesimas)" << endl;
    if (resultado){
        errores++;
        cout << "ERROR: isPrime(12) = false" << endl;
    }
    // Prueba 20:
    clock_t t20i = clock();
    resultado = isPrime(13);
    clock_t t20f = clock();
    cout << "Prueba 20: isPrime(13) = " << (resultado ? "true" : "false") << "; (" << (t20f - t20i) / (double)1000 << " milesimas)" << endl;
    if (!resultado){
        errores++;
        cout << "ERROR: isPrime(13) = true" << endl;
    }
    // Reporte General
    string nombre = "Lowis Elvis";
    cout << "Reporte General:" << endl;
    cout << "Funcion de: " << nombre << endl;
    cout << "El tiempo total de ejecucion fue de " << (t20f - t1i) / (double)1000 << " milesimas" << endl;
    cout << "Se encontraron " << errores << " errores" << endl;
    // Efectividad
    double efectividad = (double)100 - (double)(errores * 100) / 20;
    cout << "Efectividad: " << efectividad << "%" << endl;
    // Efiiciencia
    double eficiencia = (double)(t20f - t1i) / (double)1000 / (double)20;
    cout << "Eficiencia: " << eficiencia << " milesimas por prueba" << endl;
    // Si es > a 1 milesima es lento
    if (eficiencia > 1){
        cout << "La eficiencia es muy lenta" << endl;
    } else {
        cout << "La eficiencia es buena" << endl;
    }
}

// Programa Principal
int main()
{
    reporte();
    return 0;
}

