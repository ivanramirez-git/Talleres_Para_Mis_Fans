#include <iostream>
#include <fstream> //libreria para ocupar archivos

using namespace std;

void menu()
{
  cout << "\t\tMenu.\n\n\n";
  cout << "1. Agregar persona " << endl;
  cout << "2. Ver personas" << endl;
  cout << "3. ESC" << endl;
  cout << "Selecciona: " << endl;
}

void agregar();
void ver();
bool validarDNI(string dni);

int main()
{
  int opcion;

  do
  {
    menu();
    while (true)
    {
      cin >> opcion;
      // debe ser entre 1 y 3
      if (opcion >= 1 && opcion <= 3)
      {
        break;
      }
      cout << "Opcion incorrecta. Intenta de nuevo." << endl;
    }
    switch (opcion)
    {
    case 1:
      agregar();
      break;
    case 2:
      ver();
      break;
    }
  } while (opcion != 3); //esc

  return 0;
}

// Personas.txt
// Nombre, Apellido, DNI
// Juan, Perez, 12345678

// Funciones
bool validarDNI(string dni)
{
  // Si existe en el archivo
  ifstream archivo("Personas.txt");
  if (archivo.is_open())
  {
    string linea;
    while (getline(archivo, linea))
    {
      if (linea.find(dni) != string::npos) // si en esa li
      {
        return false;
      }
    }
    archivo.close();
  }
  return true;
}

void agregar()
{
  ofstream archivo;
  archivo.open("Personas.txt", ios::app);
  if (archivo.fail())
  {
    cout << "Error al abrir el archivo." << endl;
    return;
  }
  string nombre, apellido, dni;
  cout << "Ingrese nombre: ";
  cin >> nombre;
  cout << "Ingrese apellido: ";
  cin >> apellido;
  cout << "Ingrese DNI: ";
  cin >> dni;
  if (validarDNI(dni))
  {
    archivo << nombre << "," << apellido << "," << dni << endl;
    cout << "Persona agregada." << endl;
  }
  else
  {
    cout << "DNI incorrecto o existente." << endl;
  }
  archivo.close();
}

void ver()
{
  ifstream archivo;
  archivo.open("Personas.txt");
  if (archivo.fail())
  {
    cout << "Error al abrir el archivo." << endl;
    return;
  }
  string nombre, apellido, dni;
  cout << "Nombre\tApellido\tDNI" << endl;
  while (true)
  {
    archivo >> nombre >> apellido >> dni;
    if (archivo.eof())
    {
      break;
    }
    cout << nombre << "\t" << apellido << "\t" << dni << endl;
  }
  archivo.close();
}
