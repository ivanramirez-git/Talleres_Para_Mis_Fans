
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

#define cupDsctoS '';
struct Cliente
{
    char nombre[50];
    char apellidos[50];
    int edad;
    char dni[8];
    char domicilio[50];
    char codigo[5];
};
struct ventas
{
    int numjugada;     //	#JUGADAS
    int numAzar;       //	ESCOGER NUMEROS AL AZAR
    int precioPagar;   //  PRECIO A PAGAR
    char cupDscto[50]; // CUPON DE DSCTO (S/n)
    char codCupon[4];  // CODIGO CUPON (X4JN)
};
struct Sorteo
{
    int mes;              //	ESCOGER MES
    int dia;              //	ESCOGER DIA
    int HORA;             //	ESCOGER HORA
    int telf;             //	TELEFENO REFERENCIA
    char TRATAMIENTO[50]; // TRATAMIENTO de datos
};

// declaramos los Procesos ;
void mantenimientoDeClientes();
void crearRegistroCliente();
void mostrarArchivoCliente();
void eliminarArchivoCliente();
void editarArchivoCliente();
void buscarArchivoCliente();

void mantenimientoDeVentas();
void crearRegistroVentas();
void mostrarArchivoVentas();
void editarArchivoVentas();
void buscarArchivoVentas();

void mantenimientoDeSorteos();
void registroDeSorteo();
void reporteDeSorteo();

// validaciones
bool validar_edad(int edad);
bool validar_dni(char dni[8]);

int main()
{
    int opcion;
    char opc = 's';
    while (opc == 's')
    {
        system("cls");
        cout << "\n\n";
        cout << "===============================================================" << endl;
        cout << "=======BIENVENIDO A LA CASA DE APUESTAS 'INNOMBRABLES==========" << endl;
        cout << "===============================================================" << endl
             << endl;
        cout << "===================Menu principal==========================" << endl;
        cout << "1. Datos de cliente: " << endl;
        cout << "2. Venta de cartilla: " << endl;
        cout << "3. Datos para sorteo: " << endl;
        cout << "4. Salir" << endl
             << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        if (opcion > 3 && opcion <= 0)
        {
            cout << "\n \t\t\tOpcion invalida!!!" << endl;
            cout << "\n \t\t\tIngrese la Opcion Correcta: ";
            cin >> opcion;
        }
        switch (opcion)
        {
        case 1:
            mantenimientoDeClientes();
            break;
        case 2:
            mantenimientoDeVentas();
            break;
        case 3:
            mantenimientoDeSorteos();
            break;
        }
        cout << "Desea Regresar al SISTEMA DE REGISTRO DE APUESTAS  S/N ";
        fflush(stdin); ////It's a function which allows you to flush [clear] the input buffer.
        cin >> opc;
    }
    system("Pause()");
    return 0;
}

void mantenimientoDeClientes()
{
    int opcion;
    char opc = 's';
    while (opc == 's')
    {
        system("cls");
        cout << "\n\n";
        cout << "=======CASA DE APUESTAS EL SALADO==========" << endl
             << endl;
        cout << "============Menu de Cliente===============" << endl;
        cout << "1. Ingresar datos del cliente " << endl;
        cout << "2. Mostrar datos del cliente" << endl;
        cout << "3. Eliminar cliente" << endl;
        cout << "4. Buscar cliente" << endl;
        cout << "5. Modificar cliente" << endl;
        cout << "6. Regresar" << endl
             << endl;
        cout << "\n\n";
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin >> opcion;
        if (opcion > 5 && opcion <= 0)
        {
            cout << "\n \t\t\tOpcion invalida!!!" << endl;
            cout << "\n \t\t\tIngrese la Opcion Correcta: ";
            cin >> opcion;
        }
        switch (opcion)
        {
        case 1:
            crearRegistroCliente();
            break;
        case 2:
            mostrarArchivoCliente();
            break;
        case 3:
            eliminarArchivoCliente();
            break;
        case 4:
            editarArchivoCliente();
            break;
        case 5:
            // buscarArchivoCliente();
            break;
        case 6:
            main();
            break;
        }
    }
    system("Pause()");
}
void crearRegistroCliente()
{
    system("cls");
    FILE *F; // FILE es variable de tipo archivo y *file es el puntero;
    Cliente A = {0};
    do
    {
        cout << "DNI ---> ";
        cin >> A.dni;
    } while (validar_dni(A.dni) == false);
    cout << "Nombre ---> ";
    cin >> A.nombre;
    cout << "Apellido ---> ";
    cin >> A.apellidos;
    do
    {
        cout << "Edad: ";
        cin >> A.edad;
    } while (validar_edad(A.edad) == false);
    F = fopen("datosCliente.txt", "a+"); // a+ (agregar) //fopen (abrir archivo)
    if (F == NULL)
    {
        cout << "No se puede abrir el Archivo" << endl;
        exit(1); //(usually) indicates unsucessful termination
    }

    fwrite(&A, sizeof(A), 1 /* numero de archivoa a guardar*/, F /*(rn donde se guarda)*/);
    fclose(F);
    // avisando al usuario;
    cout << "Client archivado\n\n"
         << endl;
    system("Pause()");
}

void mostrarArchivoCliente()
{
    system("cls");
    Cliente A;
    // leyendo disco;
    FILE *J;
    J = fopen("datosCliente.txt", "a+");

    if (J == NULL)
    {
        cout << "No se puede Abrir el Archivo" << endl;
        exit(1);
    }

    cout << "========================================\n"
         << endl;
    cout << "Codigo\tNombre\tApellido\tEdad" << endl;
    cout << "----------------------------------------\n"
         << endl;

    fread(&A, sizeof(A), 1, J);
    while (!feof(J)) // Mientras no sea fin del archivo recorre,leemos cada archivo; feof(G)
    {
        // desplegando estructuras
        cout << A.codigo;
        cout << "\t" << A.nombre;
        cout << "\t" << A.apellidos;
        cout << setw(12) << A.edad;
        cout << "\n"
             << endl;
        fread(&A, sizeof(A), 1, J);
    }; // termina el while;

    fclose(J);

    cout << "\n\n";
    system("Pause()");
}
void eliminarArchivoCliente()
{
}

void editarArchivoCliente()
{
    system("cls");
    Cliente A;
    FILE *PP;
    FILE *GG;
    int hallado = 0;
    int codigo;
    int removed01;
    int renamed01;
    // cargando clave a buscar;
    cout << "Codigo a Buscar ";
    cin >> codigo;
    getchar();
    PP = fopen("datosCliente.txt", "r+");
    if (PP == NULL)
    {
        cout << "No se Puede abrir el Archivo\n"
             << endl;
        exit(1);
    }
    GG = fopen("Temporales.txt", "a+");
    if (GG == NULL)
    {
        cout << "No se puede abrir el Archivo\n"
             << endl;
        exit(1);
    }
    cout << "========================================\n"
         << endl;
    cout << "Codigo\tNombre\tApellido\tEdad" << endl;
    cout << "----------------------------------------\n"
         << endl;
    fread(&A, sizeof(A), 1, PP);

    while (!feof(PP)) // aquello retorna 1 o true cuando ya no hay mas data para ser leido desde del flujo de el archivo de entra, en otro caso sera 0;
    {

        cout << "Nuevo Nombre ---> ";
        gets(A.nombre);
        cout << "Nuevo Apellido ---> ";
        gets(A.apellidos);

        hallado = 1;

        fread(&A, sizeof(A), 1, PP);
    };
    fclose(PP);
    fclose(GG);

    removed01 = remove("datosCliente.txt"); // elimina;
    cout << "REMOVIDO"
         << "  " << removed01;
    renamed01 = rename("Temporales.txt", "datosCliente.txt"); // renombrar;
    cout << "RENOMBRADO"
         << "  " << renamed01;
    // avisando
    if (hallado == 0)
        cout << "No Existe ese CODIGO ....\n\n";
    else
        cout << "Registro Eliminado\n\n"
             << endl;

    system("Pause()");
}
/*mantenimiento de ventas*/
void mantenimientoDeVentas()
{
    int opcion;
    char opc = 's';
    while (opc == 's')
    {
        system("cls");
        cout << "\n\n";
        cout << "=======CASA DE APUESTAS EL SALADO==========" << endl
             << endl;
        cout << "============Menu de Venta===============" << endl;
        cout << "1. Registrar venta " << endl;
        cout << "2. Mostrar resumen de venta" << endl;
        cout << "3. Eliminar venta" << endl;
        cout << "4. Buscar venta" << endl;
        cout << "5. Modificar venta" << endl;
        cout << "6. Regresar" << endl
             << endl;
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin >> opcion;
        if (opcion > 5 && opcion <= 0)
        {
            cout << "\n \t\t\tOpcion invalida!!!" << endl;
            cout << "\n \t\t\tIngrese la Opcion Correcta: ";
            cin >> opcion;
        }
        switch (opcion)
        {
        case 1:
            crearRegistroVentas();
            break;
        case 2:
            mostrarArchivoVentas();
            break;
        case 3:
            // eliminarArchivoVentas();
            break;
        case 4:
            editarArchivoVentas();
            break;
        case 5:
            buscarArchivoVentas();
            break;
        case 6:
            main();

            fflush(stdin); // It's a function which allows you to flush [clear] the input buffer.
            break;
        }
    }
    system("Pause()");
}
void crearRegistroVentas()
{
    system("cls");
    FILE *P; // FILE es variable de tipo archivo y *file es el puntero;
    ventas B;
    // capturando Datos;

    cout << "Ingrese la cantidad de jugadas: ";
    cin >> B.numjugada;

    cout << "Escoger un numero al azar : ";
    cin >> B.numAzar;
    cout << "Precio a Pagar: ";
    cin >> B.precioPagar;
    cout << "tiene cupon de descuento S/N ";
    cin >> B.cupDscto;
    /*if (cupDsctoS=='')
    {

    }else{

    }*/

    P = fopen("datosVendedor.txt", "a+"); // a+ (agregar) //fopen (abrir archivo)

    // Consistencia de exito de apertura del archivo

    if (P == NULL)
    {
        cout << "No se puede abrir el Archivo" << endl;
        exit(1);
    }

    fwrite(&B, sizeof(B), 1 /* numero de archivoa a guardar*/, P /*(rn donde se guarda)*/);
    fclose(P);

    // avisando al usuario;
    cout << "Vendedor archivado\n\n"
         << endl;
    system("Pause()");
}
void mostrarArchivoVentas()
{
    system("cls");
    ventas B;
    FILE *G;

    G = fopen("datosVendedor.txt", "a+"); // G = fopen( "D:\UPN\Estructura de Datos\Proyect\Sistema de registro de Notas","a+");
    // consistencia del archivo
    if (G == NULL)
    {
        cout << "No se puede abrir el archivo\n"
             << endl;
        exit(1);
    }
    cout << "========================================\n"
         << endl;
    cout << "Codigo\tNombre\tApellido\tCartilla llena" << endl;
    cout << "----------------------------------------\n"
         << endl;

    fread(&B, sizeof(B), 1, G);
    while (!feof(G)) // that returns nonzero (meaning TRUE) when there are no more data to be read from an input file stream, and zero (meaning FALSE) otherwise.
    {                // desplegando estructura;
        cout << B.numjugada;
        cout << "\t" << B.cupDscto;
        cout << "\t" << B.numAzar;
        cout << setw(12) << B.precioPagar;
        cout << "\n"
             << endl;
        fread(&B, sizeof(B), 1, G);
    };
    // no olvidar cerrar el archivo;
    fclose(G);

    cout << "\n\n";
    system("Pause()");
}
void buscarArchivoVentas()
{
    system("cls");
    ventas B;
    FILE *H;
    int codigo;
    // cargando la clave a buscar;
    cout << "Codigo a Buscar ---> ";
    cin >> codigo;
    getchar(); // This function reads in a character. It returns the character as the ASCII value of that character.
    // This function will wait for a key to be pressed before continuing with the program.

    // abirendo,leyendo y cargando la lectura;
    H = fopen("datosVendedor.txt", "a+");
    // consistencia del archivo
    if (H == NULL)
    {
        cout << "No se puede abrir el archivo\n"
             << endl;
        exit(1);
    }
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyoñ{ñ-
    cout << "========================================\n"
         << endl;
    cout << "Codigo\tNombre\tApellido\tCartilla elegida" << endl;
    cout << "----------------------------------------\n"
         << endl;
    fread(&B, sizeof(B), 1, H);
    while (!feof(H))
    {

        cout << B.numjugada;
        cout << "\t" << B.numAzar;
        cout << "\t" << B.precioPagar;
        cout << setw(12) << B.cupDscto;
        cout << "\n";

        fread(&B, sizeof(B), 1, H);
    };
    // cerrar el archivo;
    fclose(H);

    cout << "\n\n";
    system("Pause()");
}
void editarArchivoVentas()
{
    system("cls");
    ventas B;
    FILE *PP;
    FILE *GG;
    int hallado = 0;
    int codigo;
    int removed01;
    int renamed01;
    // cargando clave a buscar;
    cout << "DNI a Buscar ---> ";
    cin >> codigo;
    getchar(); // This function reads in a character. It returns the character as the ASCII value of that character.
    // This function will wait for a key to be pressed before continuing with the program.

    // abriendo, leyendo y cargando archivo;
    PP = fopen("datosVendedor.txt", "r+");
    //  r == abre un fichero para lectura. Si el fichero no existe devuelve error.
    // + == símbolo utilizado para abrir el fichero para lectura y escritura.
    // consistencia de la apertura del archivo;
    if (PP == NULL)
    {
        cout << "No se Puede abrir el Archivo\n"
             << endl;
        exit(1);
    }
    GG = fopen("Temporales.txt", "a+");
    // a abre un fichero para añadir datos al final del mismo. Si no existe se crea
    //+ símbolo utilizado para abrir el fichero para lectura y escritura.

    // consistencia del archivo;
    if (GG == NULL)
    {
        cout << "No se puede abrir el Archivo\n"
             << endl;
        exit(1); // exit(1) (usually) indicates unsucessful termination. However, it's usage is non-portable.
    }
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    cout << "========================================\n"
         << endl;
    cout << "DNI\tNombre\tApellido\tCartilla seleccopmada" << endl;
    cout << "----------------------------------------\n"
         << endl;
    fread(&B, sizeof(B), 1, PP);

    while (!feof(PP)) // aquello retorna 1 o true cuando ya no hay mas data para ser leido desde del flujo de el archivo de entra, en otro caso sera 0;
    {

        cout << "Numero de jugada ";
        //	 gets(B.numAzar);
        cout << "Numero al azar ";
        // gets(B.numAzar);
        cout << "Precio a Pagar ";
        /*	 gets(B.precioPagar);
            fwrite(&B,sizeof(B),1,GG);*/
        hallado = 1;
        // Para leer y escribir en ficheros que no sean de texto las operaciones que se
        //  deben utilizar son fread y fwrite.
        fwrite(&B, sizeof(B), 1, GG);
        // Escribe tantos datos como indique numero de datos en el fichero, tomando los
        // datos a partir de la dirección del dato.

        fread(&B, sizeof(B), 1, PP);
        // Lee tantos datos como indique numero de datos del fichero, colocando
        // los datos leídos a partir de la dirección del dato.
    };
    fclose(PP);
    fclose(GG);

    // Removiendo y eliminando
    // Recordar que los nombres Directorios/carpetas y Archivos de datos no
    //  pueden tener mas de 8.3  caracteres
    removed01 = remove("datosVendedor.txt"); // elimina;
    cout << "REMOVIDO"
         << "  " << removed01;
    renamed01 = rename("Temporales.txt", "datosVendedor.txt"); // renombrar;
    cout << "RENOMBRADO"
         << "  " << renamed01;
    // avisando
    if (hallado == 0)
        cout << "No Existe ese CODIGO ....\n\n";
    else
        cout << "Registro Eliminado\n\n"
             << endl;

    system("Pause()");
}

void eliminarArchivoVentas()
{
    system("cls");
    ventas B;
    FILE *PP;
    FILE *GG;
    int hallado = 0;
    int codigo;
    int removed01;
    int renamed01;
    // cargando clave a buscar;
    cout << "DNI a Buscar ---> ";
    cin >> codigo;
    getchar(); // This function reads in a character. It returns the character as the ASCII value of that character.
    // This function will wait for a key to be pressed before continuing with the program.

    // abriendo, leyendo y cargando archivo;
    PP = fopen("datosVendedor.txt", "r+");
    //  r == abre un fichero para lectura. Si el fichero no existe devuelve error.
    // + == símbolo utilizado para abrir el fichero para lectura y escritura.
    // consistencia de la apertura del archivo;
    if (PP == NULL)
    {
        cout << "No se Puede abrir el Archivo\n"
             << endl;
        exit(1);
    }
    GG = fopen("Temporales.txt", "a+");
    // a abre un fichero para añadir datos al final del mismo. Si no existe se crea
    //+ símbolo utilizado para abrir el fichero para lectura y escritura.

    // consistencia del archivo;
    if (GG == NULL)
    {
        cout << "No se puede abrir el Archivo\n"
             << endl;
        exit(1); // exit(1) (usually) indicates unsucessful termination. However, it's usage is non-portable.
    }
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    cout << "========================================\n"
         << endl;
    cout << "DNI\tNombre\tApellido\tCartilla seleccopmada" << endl;
    cout << "----------------------------------------\n"
         << endl;
    fread(&B, sizeof(B), 1, PP);

    while (!feof(PP)) // aquello retorna 1 o true cuando ya no hay mas data para ser leido desde del flujo de el archivo de entra, en otro caso sera 0;
    {

        cout << "Numero de jugada ";
        // gets(B.numAzar);
        cout << "Numero al azar ";
        // gets(B.numAzar);
        cout << "Precio a Pagar ";
        /*	 gets(B.precioPagar);
            fwrite(&B,sizeof(B),1,GG);*/
        hallado = 1;

        fwrite(&B, sizeof(B), 1, GG);
        // Escribe tantos datos como indique numero de datos en el fichero, tomando los
        // datos a partir de la dirección del dato.

        fread(&B, sizeof(B), 1, PP);
        // Lee tantos datos como indique numero de datos del fichero, colocando
        // los datos leídos a partir de la dirección del dato.
    };
    fclose(PP);
    fclose(GG);

    // Removiendo y eliminando
    // Recordar que los nombres Directorios/carpetas y Archivos de datos no
    //  pueden tener mas de 8.3  caracteres
    removed01 = remove("datosVendedor.txt"); // elimina;
    cout << "REMOVIDO"
         << "  " << removed01;
    renamed01 = rename("Temporales.txt", "datosVendedor.txt"); // renombrar;
    cout << "RENOMBRADO"
         << "  " << renamed01;
    // avisando
    if (hallado == 0)
        cout << "No Existe ese CODIGO ....\n\n";
    else
        cout << "Registro Eliminado\n\n"
             << endl;

    system("Pause()");
}

void mantenimientoDeSorteos()
{
    system("cls");
    int opcion;
    char opc = 's';
    while (opc == 's')
    {
        system("cls");
        cout << "\n\n";
        cout << "\t\t  ====== MANTENIMIENTO Cartillas ======";
        cout << "\n\n                                          ";
        cout << "\n \t\t\t 1. Registrar Cartillas";
        cout << "\n \t\t\t 2. Reporte de Cartiillas por Clientes";
        cout << "\n \t\t\t 3. Mensaje de Salida";
        cout << "\n\n";
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin >> opcion;
        if (opcion > 5 && opcion <= 0)
        {
            cout << "\n \t\t\tOpcion invalida!!!" << endl;
            cout << "\n \t\t\tIngrese la Opcion Correcta: ";
            cin >> opcion;
        }
        switch (opcion)
        {
        case 1:
            // registroDeSorteos();
            break;

        case 2:
            reporteDeSorteo();
            break;
        case 3:
            cout << "\n\n";
            cout << "Desea Regresar a MANTENIMIENTO DE CLIENTES S/N ?\n"
                 << endl;
            fflush(stdin); // It's a function which allows you to flush [clear] the input buffer.
            cin >> opc;
            break;
        }
    }
    system("Pause()");
}
void registroDeSorteos()
{
    system("cls");
    FILE *FF; //  variable Puntero para Abrir  el archivo existente;
    FILE *GG; // variable Puntero para crear un archivo temporal;
    Cliente A;
    int hallado = 0;
    int remove01;
    int rename01;
    int codigo;
    // cargando clave para buscar;
    cout << "Codigo a Buscar ---> ";
    cin >> codigo;
    getchar(); // getchar solo te va capturar el primer caracter;
    // Abriendo, leyendo,cargando estructura;//
    FF = fopen("datosCliente.txt", "r+"); //  r == abre un fichero para lectura. Si el fichero no existe devuelve error.
                                          // + == símbolo utilizado para abrir el fichero para lectura y escritura.
    // consistencia de la apertura del archivo;

    if (FF == NULL)
    {
        cout << "No se puede abrir el archivo\n " << endl;
        exit(1);
    }
    GG = fopen("Tempt.txt", "a+");
    // consistencia del archivo;
    if (GG == NULL)
    {
        cout << "No se puede abrir el Archivo\n";
        exit(1);
    }
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    cout << "========================================\n"
         << endl;
    cout << "Nombre\tApellido\tCartilla" << endl;
    cout << "----------------------------------------\n"
         << endl;

    fread(&A, sizeof(A), 1, FF);
    // proceso de  reescritura;
    while (!feof(FF))
    {
        if (A.codigo > "")
        {
            cout << A.nombre;
            cout << "\t" << A.apellidos;
            cout << "\n";
            cout << "\n\t\t----INGRESE LOS NUMEROS-----" << endl;
            cout << "\n";
            /*cout<<"Numero 1: "<<endl;
                cin>>A.;
            cout<<"Numero 2: "<<endl;
            cin>>A.ep;
            cout<<"Numero 3 "<<endl;
            cin>>A.ef;
            fwrite(&A, sizeof(A), 1, GG); // fwrite (direcc_dato, tamaño_dato, numero_datos, punt_fichero);
            hallado = 1;*/
        }
        else
        {
            fwrite(&A, sizeof(A), 1, GG);
        }
        fread(&A, sizeof(A), 1, FF);

    }; // termina el while;
    // cerrando archivos;

    fclose(FF);
    fclose(GG);

    remove01 = remove("datosCliente.txt");
    cout << "REMOVIDO"
         << "  " << remove01;
    rename01 = rename("Tempt.txt", "datosCliente.txt");
    cout << "AGREGADO NOTAS"
         << "  " << rename01;
    // avisando;
    if (hallado == 0)
        cout << "No existe este CODIGO \n\n";
    else
        cout << "Registro Actualizado" << endl;
    system("Pause()");
}
void reporteDeSorteo()
{
    system("cls");

    Cliente A;
    // leyendo disco;
    FILE *J;
    // G = fopen("c:/FDatos/Alumnos.dat","a+");
    J = fopen("datosCliente.txt", "a+");

    // Consistencia de exito de apertura del archivo
    if (J == NULL)
    {
        cout << "No se puede Abrir el Archivo" << endl;
        exit(1);
    }

    cout << "=======================================================\n"
         << endl;
    cout << "Nombre\tApellido\tCartilla\tNumerro1\tNumero2\tNumero3" << endl;
    cout << "-------------------------------------------------------\n"
         << endl;

    fread(&A, sizeof(A), 1, J);
    while (!feof(J)) // Mientras no sea fin del archivo recorre,leemos cada archivo; feof(G)
    {
        // desplegando estructuras

        cout << A.nombre;
        cout << "\t" << A.apellidos;
        /*cout<<setw(12)<<A.;
        cout<<setw(12)<<A.NumeroF;
        cout<<"\t\t"<<A.ep;
        cout<<"\t\t"<<A.ef;*/
        cout << "\n"
             << endl;
        fread(&A, sizeof(A), 1, J);
    }; // termina el while;

    fclose(J);

    cout << "\n\n";
    system("Pause()");
}

bool validar_edad(int edad)
{
    if (edad >= 18)
    {
        return true;
    }
    else
    {
        cout << endl
             << "Ud es menor de edad, no puede jugar" << endl
             << endl;
        return false;
    }
}

bool validar_dni(char dni[8])
{
    if (strlen(dni) == 8)
    {
        return true;
    }
    else
    {
        cout << endl
             << "ERROR: El dni tener 8 caracteres" << endl
             << endl;
        return false;
    }
}
