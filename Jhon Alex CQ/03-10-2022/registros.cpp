#include <iostream>
#include <cstring>

using namespace std;

// pedir nombre direccion sexo sueldo
// encabezados: codigo, nombre, direccion, sexo, sueldo
void pedirDatos(int num_registro, char *codigo, char *nombre, char *direccion, char &sexo, float &sueldo) {
    // Codigo es COD01, COD02, COD03, COD04, COD05, dependiendo del numero de registro
    strcpy(codigo, "COD");
    char num[3];
    sprintf(num, "%02d", num_registro);
    strcat(codigo, num);
    // Nombre
    cout << "Ingrese el nombre: ";
    cin.ignore();
    cin.getline(nombre, 100);
    cout << "Ingrese la direccion: ";
    cin.getline(direccion, 100);
    cout << "Ingrese el sexo: ";
    cin >> sexo;
    cout << "Ingrese el sueldo: ";
    cin >> sueldo;
}

// mostrar datos
void mostrarDatos(char codigo[][5], char nombre[][100], char direccion[][100], char sexo[], float sueldo[], int n) {
    
    // -----------------------------------------------
    // | CODIGO | NOMBRE | DIRECCION | SEXO | SUELDO |
    // -----------------------------------------------
    // | COD01    | Juan   | Lima      | M    | 1000   |
    // | COD02    | Maria  | Lima      | F    | 2000   |
    // | COD03    | Pedro  | Lima      | M    | 3000   |
    // | COD04    | Ana    | Lima      | F    | 4000   |
    // -----------------------------------------------

    // Imprimir tabla organizada con espacios definidos
    cout << "-----------------------------------------------" << endl;
    cout << "| CODIGO | NOMBRE | DIRECCION | SEXO | SUELDO |" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "| " << codigo[i] << " | " << nombre[i] << " | " << direccion[i] << " | " << sexo[i] << " | " << sueldo[i] << " |" << endl;
    }
    cout << "-----------------------------------------------" << endl;
    
}

// main
int main() {
    // pedir datos
    int n;
    cout << "Ingrese el numero de registros: ";
    cin >> n;
    char codigo[n][5];
    char nombre[n][100];
    char direccion[n][100];
    char sexo[n];
    float sueldo[n];
    for (int i = 0; i < n; i++) {
        pedirDatos(i + 1, codigo[i], nombre[i], direccion[i], sexo[i], sueldo[i]);
    }
    // mostrar datos
    mostrarDatos(codigo, nombre, direccion, sexo, sueldo, n);
    return 0;
}

