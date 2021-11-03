#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int DF = 500;  //Dimension Fisica

/////////////////////////////////////////////////////////////////////////////////////////////////////
void pausa();
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-----------STRUCT---------------////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct una_categoria{    //Categoria que almacena codigo y su descripcion
    int codigo;
    string descripcion;
    };

struct un_prestamo{  // Prestamo que almacena la informacion del prestamo
    int categoria;
    int prestatario;
    string descripcion;
    bool estado;
    int codigo;
    };

struct un_prestatario{ // Almacena un prestatario
    int codigo;
    string apellido;
    string nombre;
    };

struct una_categoria_ordenada{
    string nombre;
    string apellido;
    string categoria;
    string descripcion;};

//--- Estructura para almacenar arreglos y dimensiones ---

/* Son estructuras para almacenar un arreglo de dimension logica correspondiente
  a cada uno de los tripos creados anteriormente. Cada posicion de los vectores
  tiene los datos que se almacenan en las estructuras anterior. */

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-----------ARREGLOS---------------/////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
int codigoDeCategoriaAutogenerado=0;
int codigoDePrestatarioAutogenerado=0;
int posicion=0;
int codigoDePrestamoAutogenerado=0;
int cantidadDePrestamos=0;
////////////////////////////////////////////////////////////////////////////////////////////////////
int haycategorias=0;
int hayprestatarios=0;
int hayprestamos=0;
int devueltos=0;
int eliminados=0;
int eliminadosP=0;
////////////////////////////////////////////////////////////////////////////////////////////////////
/* Las variables de dimension logica sirven para saber cuantos campos de cada arreglo estan
 ocupados con datos ultiles para el usuario del programa. Se utilizan para agregar datos
 al dinal de los utiles, y tambien para imprimir la cantidad justa de datos utilizados. */

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-----------MENU---------------/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: que el usuario elija a que opcion del menu quiere entrar.
   Parametros: no tiene poque no hacen falta para esta parte de programa.
   Retorno: opcion que el usuario eligio. */

int menu_principal(){
    char valor;
    bool auxiliar=false;
    do{
        system("cls");
        cin.clear();
    cout<< endl<< "*** MENU PRINCIPAL *** "<<endl<<endl
        <<"Por favor elija una de las opciones a continuacion:"<<endl<<endl
        <<"A. Administrar y consultar categorias y prestatarios"<<endl
        <<"B. Administrar prestamos"<<endl
        <<"C. Consultar Prestamos"<<endl
        <<"D. Salir"<<endl
        <<"Ingrese opcion: ";
    cin>>valor;
    valor=toupper(valor);
    return valor;
    }while(auxiliar!=true);
}//imprime y da a elegir una opcion del menu principal.

/////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: que el usuario elija a que opcion del menu de de "Administrar y consultar
    Categorias y Prestatarios" quiere entrar.
    Parametros: no tiene porque no hacen falta para esta parte de programa.
    Retorno: opcion que el usuario eligio */

int categorias_y_prestatarios(){
    char valor ;
    bool auxiliar=false;
    do{
    system("cls");
    cin.clear();
    cout<<endl<<"*** ADMINISTRAR Y CONSULTAR CATEGORIAS Y PRESTATARIOS:"<<endl<<endl
       <<"A. Agregar categoria"<<endl
       <<"B. Modificar categoria"<<endl
       <<"C. Eliminar categoria"<<endl
       <<"D. Agregar prestatario"<<endl
       <<"E. Modificar prestatario"<<endl
       <<"F. Eliminar prestatario"<<endl<<endl
       <<"ingrese un caracter diferente a los anteriores para volver al menu principal"<<endl
       <<"Ingrese opcion: ";
    cin>> valor;
    valor=toupper(valor);
    return valor;
    }while(auxiliar!=true);
}//imprime y da a elegir una opcion del menu secundario.

///////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: que el usuario elija a que opcion del menu de "Administrar prestamos"
            quiere entrar.
   Prametros: no tiene porque no hace falta para esta parte de programa.
   Retorno opcion que el usuario eligio. */

int administrar_prestamos(){
    char valor;
    bool auxiliar=false;
    do{
    system("cls");
    cin.clear();
    cout<<endl<< "*** ADMINISTRAR PRESTAMOS: "<<endl<<endl
        <<"A. Agregar prestamo"<<endl
        <<"B. Modificar prestamo"<<endl
        <<"C. Eliminar prestamo"<<endl
        <<"D. Devolver prestamo"<<endl<<endl
        <<"ingrese un caracter diferente a los anteriores para volver al menu principal"<<endl
        <<"Ingresar opcion: ";
    cin>>valor;
    valor=toupper(valor);
    return valor;
    }while(auxiliar!=true);
}//Imprime y da a elegir una opcion del menu secundario

//////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: que el usuario elija a que opcion del menu de "Consultar prestamos"
              quiere entrar.
   Parametros: no tiene porque no hace falta para esta parte de programa.
   Retorno: opcion que el usuario eligio. */

int consultar_prestamo(){
    char valor;
    bool auxiliar=false;
    system("cls");
    cin.clear();
    cout<<endl<<"*** CONSULTAR PRESTAMOS: "<<endl<<endl
        <<"A. Cantidad de objetos prestados por categoria"<<endl
        <<"B. Listado de prestamos por categoria"<<endl
        <<"C. Listado de prestamos ordenados por categoria o prestatario"<<endl
        <<"D. Listar todos los prestatarios que tiene al menos un objeto prestado"<<endl<<endl
        <<"ingrese un caracter diferente los anteriores para volver al menu principal"<<endl
        <<"Ingrese opcion: ";
    cin>>valor;
    valor=toupper(valor);
    return valor;
}//Imprime y da a eligeir una opcion del menu secundario

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-----------CATEGORIAS---------------///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: agregar una categoria despues de la ultima ingresada, en el atrreglo que se encuentra almacenado dentro del struct
              que recibe como parametro.
   Parametro: estructura que almacena las categorias y sus dimension.
   Retorno: no tiene valor de retorno ya que actua directamente soble el arreglo, que se encuentra dentro del struct y
            la dimension logica.*/

void agregar_categoria(una_categoria cat[], int dim){
    /* Agrega las distintas categorias de los prestamos que el usuario hizo. a cada una
            se le asocia un codigo automaticamente/
          */
    cout <<"Ingrese la descripcion: "   ;
    getline(cin>>ws,cat[dim].descripcion);
    cout<<"Codigo de Categoria: "<<codigoDeCategoriaAutogenerado<<endl;
    cat[dim].codigo=codigoDeCategoriaAutogenerado;
    dim++; //incrementa dim_logica
    codigoDeCategoriaAutogenerado ++; //Autoincrementa cada vez que creo una categoria.
    haycategorias++;

    /* Agrega las distintas categorias de los prestamos que el usuario hizo. a cada una
        se le asocia un codigo automaticamente*/
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: modificar la descripcion de una categoria.
   Parametro: estructura que almacena las categorias y sus dimension.
   Retorno: no tiene valor de retorno ya que actua directamente sobre el arreglo.*/

void modificar_categoria(una_categoria cat[], int dim){
    if(haycategorias!=0){
        int codigo;
        string descripcion;
        for(int x=0;x<dim;x++){
            cout<<"Categoria: "<<cat[x].descripcion<<"         Codigo: "<<cat[x].codigo<<endl;
        }
        cout <<"Ingrese el codigo autogenerado de la categoria a modificar: ";
        cin >> codigo;
        int i=0;
        while (i<dim && cat[i].codigo != codigo){
            i++;
        }
        if(cat[i].codigo==codigo){
            cout <<"Ingrese la nueva descripcion: "    ;
            getline(cin>>ws,cat[i].descripcion);
        }
        else{
            cout<<"El codigo de la categoria es incorrecto."<<endl;
        }
    }
    else{
        cout<<"No hay categorias que modificar."<<endl;
    }


    /* El usuario puede modificar la descripcion de una categoria anteriormente ingresada. */
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: eliminar categoria del arreglo.
   Parametros: estructura que almacena las categorias y su dimension.
   Retorno: no tiene valor de retorno ya que actua directamente sobre el arreglo.*/

void eliminar_categoria(una_categoria cat[], int dim, un_prestamo pres[], int dim_c){
    if(haycategorias !=0){
        int codigo;
        for(int muestra=0; muestra<dim_c; muestra++){
            cout<<"Categoria: "<<cat[muestra].descripcion<<"         Codigo: "<<cat[muestra].codigo<<endl;
        }
        cout <<"Ingrese el codigo autogenerado de la categoria a eliminar: "    ;
        cin >> codigo;
        int i=0;
        while (i<dim_c && cat[i].codigo != codigo){
            i++;
        }
        while(codigo!=cat[i].codigo){
            cout<<"El codigo ingresado es inexistente, por favor ingrese otro;"<<endl;
            cin >> codigo;
            int i=0;
            while (i<dim_c && cat[i].codigo != codigo){
                i++;
            }
        }
        int p=0;
        if(cat[i].codigo==codigo){
            if(dim==0){
                for(int j=i ; j<dim_c ; j++){
                    cat[j].descripcion=cat[j+1].descripcion;
                    }
                for(int h=i ; h<dim_c ; h++){
                    cat[h].codigo=cat[h+1].codigo;
                }
                dim_c--;
                haycategorias--;
                codigoDeCategoriaAutogenerado--;
                eliminados++;
                cout<<"La categoria ha sido eliminada."<<endl;
            }
            else{

                while (p<dim-1 && pres[p].categoria != cat[i].codigo){
                    p++;
                }
                if(pres[p].categoria!=cat[i].codigo){
                    for(int j=i ; j<dim_c ; j++){
                        cat[j].descripcion=cat[j+1].descripcion;
                        }
                    for(int h=i ; h<dim_c ; h++){
                        cat[h].codigo=cat[h+1].codigo;
                    }
                    dim_c--;
                    eliminados++;
                    codigoDeCategoriaAutogenerado--;
                    haycategorias--;
                    cout<<"La categoria ha sido eliminada."<<endl;
                }
                else{
                    cout << endl << "La categoria no puede eliminarse debido a que hay prestamos pendientes o emitidos"<<endl;
                }}



                }


            }
    /* El usuariopuede eliminar categorias anteriormente ingresadas. Si tiene prestamos
        pendientes no funciona.*/


    else{
        cout<<"No hay categorias que eliminar."<<endl;
    }}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-----------PRESTATARIOS---------------/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*Proposito: agregar un nuevo prestatario al arreglo.
  Parametros: estructura que almacena las prestatarios y su dimension.
  Retorno: no tiene valor de retorno ya que actua directamente sobre el arreglo. */

void agregar_prestatario(un_prestatario pre[], int dim){
    cout <<"Ingrese su apellido: "    ;
    getline(cin>>ws,pre[dim].apellido);
    pre[dim].apellido[0]=toupper(pre[dim].apellido[0]);
    cout <<"Ingrese la nombre: "    ;
    getline(cin>>ws,pre[dim].nombre);
    pre[dim].nombre[0]=toupper(pre[dim].nombre[0]);
    cout<<"Codigo de Prestatario: "<<codigoDePrestatarioAutogenerado<<endl;
    pre[dim].codigo=codigoDePrestatarioAutogenerado;
    codigoDePrestatarioAutogenerado++;
    dim++;
    hayprestatarios++;
    cout<<" ";
}
// Agrega a un prestatario al arreglo y incrementa su dimension
/////////////////////////////////////////////////////////////////////////////////////////////////////

/*Proposito: modificar el apellido y nombre de los prestatarios.
  Parametros: estructura que almacena los prestatarios y su dimension.
  Retorno: no tiene valor de retorno ya que actua directamente sobre el arreglo. */

void modificar_prestatario(un_prestatario pre[],int dim){
    if(hayprestatarios!=0){
        int codigo;
        for(int muestra=0; muestra<codigoDePrestatarioAutogenerado; muestra++){
            cout<<pre[muestra].apellido<<"   "<<pre[muestra].nombre<<" ------- codigo: "<<pre[muestra].codigo<<endl;
        }
        cout <<"Ingrese el codigo autogenerado de prestatario a modificar"    ;
        cin >> codigo;
        if(codigo>codigoDePrestatarioAutogenerado){
            cout<<"Codigo ingresado es inexistente."<<endl;
        }
        else{
            int i=0;
          while (i<dim && pre[i].codigo != codigo){
              i++;
           }
           if(pre[i].codigo==codigo){
                string nuevo_nombre;
                cout <<"Ingrese el nuevo nombre "    ;
                getline(cin>>ws,pre[i].nombre);
               string nuevo_apellido;
                cout <<"Ingrese el nuevo apellido "    ;
                getline(cin>>ws,pre[i].apellido);
            }
        }
    }
    else{
        cout<<"No hay prestatarios que mdoficiar."<<endl;
    }
} /* El usuario puede modificar los datos de la persona a la
        cual se le presto el objeto.*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

/*Proposito: eliminar prestatarios.
  Parametros: estructura que almacena los prestatarios y su dimension.
  Retorno: no tiene valor de retorno ya que actua directamente sobre el arreglo. */

void eliminar_prestatario(un_prestatario pre[],int dim, un_prestamo pres[], int dim_p){
    if(hayprestatarios !=0){
        int codigo;
        for(int muestra=0; muestra<codigoDePrestatarioAutogenerado; muestra++){
            cout<<pre[muestra].apellido<<"   "<<pre[muestra].nombre<<" ------- codigo: "<<pre[muestra].codigo<<endl;
        }
        cout <<"Ingrese el codigo autogenerado de el prestatario a eliminar: "    ;
        cin >> codigo;
        int i=0;
        while (i<dim_p && pre[i].codigo != codigo){
            i++;
        }
        while (codigo!=pre[i].codigo){
            cout<<"El codigo ingresado es inexistente, por favor ingrese otro;"<<endl;
            cin >> codigo;
            int i=0;
            while (i<dim_p && pre[i].codigo != codigo){
                i++;}
        }
        int p=0;
        while (p<dim && pres[p].categoria != pre[i].codigo){
            p++;
        }
        if(i!=0){
            if(pres[p].categoria!=pre[i].codigo){
                for(int j=i ; j<dim_p ; j++){
                    pre[j].nombre=pre[j+1].nombre;
                    pre[j].apellido=pre[j+1].apellido;
                    pre[j].codigo=pre[j+1].codigo-1;
                }
                dim_p--;
                codigoDePrestatarioAutogenerado--;
                eliminadosP++;
                cout<<"Prestatario eliminado."<<endl;
            }
            else{
                cout << endl << "El prestatario no puede eliminarse debido a que hay prestamos pendientes o emitidos"<<endl;
            }
        }
        else{
            if(dim==0){
                for(int j=i ; j<dim_p ; j++){
                    pre[j].nombre=pre[j+1].nombre;
                    pre[j].apellido=pre[j+1].apellido;
                    pre[j].codigo=pre[j+1].codigo-1;}
                dim_p--;
                codigoDePrestatarioAutogenerado--;
                eliminadosP++;
                cout<<"Prestatario eliminado."<<endl;
                hayprestatarios--;
            }
            else{
                while (p<dim-1 && pres[p].prestatario != pre[i].codigo){
                    p++;}
                if(pres[p].categoria==pre[i].codigo){
                    cout << endl << "El prestatario no puede eliminarse debido a que hay prestamos pendientes"<<endl;
                }
                else{
                for(int j=i ; j<dim_p ; j++){
                    pre[j].nombre=pre[j+1].nombre;
                    pre[j].apellido=pre[j+1].apellido;
                    pre[j].codigo=pre[j+1].codigo;}
                dim_p--;
                codigoDePrestatarioAutogenerado--;
                eliminadosP++;
                cout<<"Prestatario eliminado."<<endl;
                hayprestatarios--;
                }

            }
        }
    }
    else{
        cout<<"No hay prestatarios para eliminar."<<endl;
    }
}/* Borra por completo un prestarario y sus datos */
////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-----------PRESTAMOS---------------////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: Cargar un prestamo
   Paramentros: estructura en el que se agrega un prestamo
   y se integra una determinada informacion.
   Retorno: no tiene retorno ya que actua directamente dentro del arreglo */

void agregar_prestamo(int haycategorias, int hayprestatarios, un_prestamo pres[],int dim, una_categoria cat[], un_prestatario pre[], int dim_c, int dim_p){
    string respuesta;
    if(haycategorias !=0 && hayprestatarios !=0){
        cout << "Desea ver las actuales categorias ? (S/N)";
        cin >> respuesta;
        respuesta[0]=tolower(respuesta[0]);
        if(respuesta=="s"){
            for(int i=0 ; i<dim_c ; i++){
                cout << "Descripcion: " << cat[i].descripcion << endl;
                cout << "Codigo: " << cat[i].codigo << endl;
            }
        }
        int codigo;
        cout << "Ingrese el codigo de categoria: ";
        cin >> codigo;
        while(cat[codigo].codigo!=codigo){
            cout << "Codigo incorrecto, por favor vuelva a ingresar... ";
            cin >> codigo;
        }
        pres[posicion].categoria=codigo;
        string respuesta2;
        cout << "Desea ver los actuales prestatarios ? (S/N)";
        cin >> respuesta2;
        respuesta2[0]=tolower(respuesta2[0]);
        if(respuesta2=="s"){
            for(int p=0 ; p<dim_p; p++){
                cout << "Apellido: " << pre[p].apellido << endl;
                cout << "Nombre: " << pre[p].nombre << endl;
                cout << "Codigo: " << pre[p].codigo << endl;
            }
        }
        int codigo2;
        cout << "Ingrese el codigo de prestatario: ";
        cin >> codigo2;
        while(pre[codigo2].codigo!=codigo2){
            cout << "Codigo incorrecto, por favor vuelva a ingresar... ";
            cin >> codigo2;
        }
        pres[posicion].prestatario=codigo2;
        string descripcion;
        cout <<"Ingrese la descripcion del prestamo: "    ;
        getline(cin>>ws,pres[dim].descripcion);
        bool estado=true;
        pres[posicion].estado=estado;
        cout << "El codigo del prestamo es:" << codigoDePrestamoAutogenerado << endl;
        pres[posicion].codigo=codigoDePrestamoAutogenerado;
        codigoDePrestamoAutogenerado++;
        posicion++;
        dim++;
        cantidadDePrestamos++;
        cout<<" ";
        hayprestamos++;
    }
    else{
        cout<<"No hay categorias o prestatarios para poder realizar la operacion."<<endl;
    }
}/* Esta funcion se encarga de cargar un prestamo que el usuario ingrese, mediante un struct */
////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: Modificar un prestamo.
   Parametros: estructura con un prestamo.
   Retorno: no tiene retorno ya que actua directamente dentro del arreglo */

void modificar_prestamo(un_prestamo pres[],int dim){
    if(hayprestamos !=0){
        int x=0;
        for(x=0; x<codigoDePrestamoAutogenerado; x++){
            cout<< "Descripcion: " << pres[x].descripcion<<endl<<"    Codigo: "<<pres[x].codigo<< endl;
        }
        int codigo;
        string descripcionNueva;
        cout << "Ingrese el codigo autogenerado de el prestamo a modificar: ";
        cin >> codigo;
        int i=0;
        while (i<dim && pres[i].codigo != codigo){
            i++;
        }
        if(pres[i].codigo==codigo){
            cout <<"Ingrese la nueva descripcion: "    ;
            getline(cin>>ws,pres[i].descripcion);
        }
    }
    else{
        cout<<"No hay prestamos para modificar."<<endl;
    }

} /*Esta funcion se encarga de modificar un prestamo previamente ingresado */
////////////////////////////////////////////////////////////////////////////////////////////////////

/*  Proposito: Eliminar una prestamo
    Parametros: estructura con un prestamo cargado
    Retorno: no tiene retorno ya que actua directamente dentro del arreglo */

void eliminar_prestamo(un_prestamo pres[],int dim){
    if(hayprestamos !=0){
        int x=0;
        for(x=0; x<codigoDePrestamoAutogenerado; x++){
            cout<< "Descripcion: " << pres[x].descripcion<<"    Codigo: "<<pres[x].codigo<< endl;
        }
        int codigo;
        cout <<"Ingrese el codigo del prestamo a eliminar"    ;
        cin >> codigo;
        cout << "viejo"<< endl << pres[0].categoria << pres[0].codigo << pres[0].descripcion << pres[0].estado << pres[0].prestatario;
        for(int j=codigo ; j<dim ; j++){
            pres[j].descripcion=pres[j+1].descripcion;
        }
        for(int j=codigo ; j<dim ; j++){
            pres[j].categoria=pres[j+1].categoria;
        }
        for(int j=codigo ; j<dim ; j++){
            pres[j].prestatario=pres[j+1].prestatario;
        }
        for(int j=codigo ; j<dim ; j++){
            pres[j].estado=pres[j+1].estado;
        }
        for(int j=codigo ; j<dim ; j++){
            pres[j].codigo=pres[j+1].codigo;
        }
        dim--;
        hayprestamos--;
        codigoDePrestamoAutogenerado--;
        posicion--;
    }
    else{
        cout<<"No hay prestamos para eliminar."<<endl;
    }

}/* Esta funcion se encarga de eliminar un prestamo por completo */
////////////////////////////////////////////////////////////////////////////////////////////////////

/* Proposito: Modificar estado de prestamo
   Parametros: structura con prestamo almacenado
   Retorno: no tiene retorno ya que actua directamente dentro del arreglo */

void devolver_prestamo(un_prestamo pres[],int dim, int dim_p, un_prestatario pre[]){
    if(hayprestamos-devueltos!=0){
        for(int x=0;x<dim;x++){
            cout << pres[x].descripcion << pres[x].codigo << pres[x].estado << pres[x].categoria<< pres[x].prestatario<<endl;
        }
        int i=0;
        int auxiliar2=0;
        for(i=0; i<dim_p; i++){
            for(int x=0; x<dim; x++){
                if(pre[i].codigo==pres[x].prestatario){
                    if(pres[x].estado==true){
                        if(auxiliar2==0){
                            cout<<pre[i].apellido<<" "<<pre[i].nombre<<" Codigo: "<<pre[i].codigo<<endl;
                            auxiliar2++;
                        }
                    }
                }
            }
            auxiliar2=0;
        }
        int eleccion;
        cout << "Elija el codigo de su prestatario: ";
        cin >> eleccion;
        while(eleccion>dim){
            cout<<"Codigo ingresado inexistente, vuelva a ingresar..."<<endl;
            cin >> eleccion;}


            for(int j=0; j<dim ;j++){
                if(pres[j].estado==true){
                    if(pres[j].prestatario==eleccion){
                        cout<<" Numero: " << pres[j].codigo+1/*Porque tiene que ser 1 el primero */ << " Descripcion: "<<pres[j].descripcion << endl;
                    }
                }
            }
            int eleccion2=0;
            cout << "Ingrese el numero del prestamo a devolver: ";
            cin >> eleccion2;
            eleccion2=eleccion2-1;
            while(pre[eleccion].codigo!=pres[eleccion2].prestatario){
                cout << "Numero incorrecto, vuelva a ingresar";
                cin >> eleccion2;
                eleccion2=eleccion2-1;
            }
            pres[eleccion2].estado=false;

            devueltos++;
    }
    else{
        cout << "No hay prestamos para devolver..."<< endl;
    }
}

 /* Esta funcion se encarga de dar de alta o baja a un prestamo */
////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////-----------CONSULTAS---------------////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
void cantidad_objetos_categoria(un_prestamo pres[], int dim,una_categoria cat[],int dim_c){
    if(hayprestamos!=0){
    cout << " Cantidad de prestamos por categoria " <<endl;
    int f=0;
    for(int x=0; x<dim_c; x++){
       for(int y=0; y<dim; y++){
           if(cat[x].codigo==pres[y].categoria){
               f++;
           }

       }
       while(f!=0){
       cout << cat[x].descripcion << " tiene " <<f << " prestamos" <<endl;
       f=0;
       }
   }
   cout << "Hay " << hayprestamos-devueltos<< " prestamos emitidos en total." <<endl;
    }
    else{
        cout << "No hay prestamos cargados..."<<endl;
    }


    /* Parametros: imprimir cuantos prestamos tiene cada categoria.
   Parametros: estructura que almacenan las categorias y los prestamos.
   Retorno: no tiene valor de retorno ya que solamente imprime informacion.*/

}/* Devuelve la cantidad de prestamos asociados que tiene cada una de las categorias.*/
////////////////////////////////////////////////////////////////////////////////////////////////////
void prestamos_en_una_categoria(una_categoria cat[],int dim_c,un_prestamo pres[],int dim, un_prestatario pre[],int dim_p){
    if(hayprestamos!=0){
        cout << " Listado de prestamos por categoria "<<endl;
    int prestatario1=0;
    int z;
    int llegamos;
    int cant_prestamos=0;
    for(int x=0; x<dim_c ; x++){
        cout << "Categoria " << cat[x].descripcion<< endl << " Codigo : " << cat[x].codigo << endl;
    }
    cout << "Elija una opcion ";
    int eleccion;
    cin >> eleccion;
    if(eleccion<dim_c){
    cout << "De la categoria " << cat[eleccion].descripcion <<" los prestamos pendientes son los siguientes: "<<endl;
    for(int y=0; y<dim ; y++){
        llegamos=0;
        z=-1;
        while(llegamos==0 && z<dim_p){
            z++;
            if(pres[y].prestatario==pre[z].codigo){
                prestatario1=z;
                llegamos++;
            }
            }
        if(cat[eleccion].codigo==pres[y].categoria && pres[y].estado==true){
            cant_prestamos++;
            cout << pres[y].descripcion <<" prestado a " << pre[prestatario1].apellido << " " << pre[prestatario1].nombre<< endl;
            }
    }}
    else{
        cout << "Esta categoria no existe..."<< endl;
    }
    if(cant_prestamos==0){
        cout << " Esta categoria no tiene prestamos activos..."<< endl;
    }
    }
else{
    cout << "No hay prestamos emitidos.."<<endl;}}




    /* Parametros: imprime los prestamos de una categoria categoria.
   Parametros: estructura que almacenan categorias, los prestamos y los prestatarios.
   Retorno: no tiene valor de retorno ya que solamente imprime informacion.*/

/* Devuelve todos los prestamos existentes en una categoria que el usuario seleccione.*/
////////////////////////////////////////////////////////////////////////////////////////////////////
void prestamos_por_categoria_o_prestatario(una_categoria cat[], int dim_c, un_prestamo pres[], int dim, un_prestatario pre[], int dim_p, una_categoria_ordenada cato[]){
    int hayPendientes=0;
    int llegueP=0;
    int llegueC=0;
    string respuesta;
    int posicion=0;
    for(int x=0; x<dim; x++){
        if(pres[x].estado==true){
            hayPendientes++;
        }
    }
    if(hayPendientes!=0){
        cout<< "¿Clasificar el listado por Categoría (C) o Prestatario (P)?";
        cout <<"Ingrese su respuesta: "    ;

        cin >> respuesta;
        respuesta=toupper(respuesta[0]);

        while(respuesta!="C" && respuesta!="P"){
                    cout << "Respuesta incorrecta, vuelva a ingresar..."<< endl;
                    cin >> respuesta;
                    respuesta=toupper(respuesta[0]);
                       }


        if(respuesta=="P"){
            while(llegueP==0){
                llegueP++;
                 for(int y=0; y<dim ;y++){
                     llegueP=0;
                     if(pres[y].estado==true){
                         for(int z=0; z<dim_c ; z++){
                             if(pres[y].categoria==cat[z].codigo){
                                 for(int c=0; c<dim_p ; c++){
                                     if(pres[y].prestatario==pre[c].codigo && llegueP==0){
                                         cato[posicion].categoria=cat[z].descripcion;
                                         cato[posicion].descripcion=pres[y].descripcion;
                                         cato[posicion].apellido=pre[c].apellido;
                                         cato[posicion].nombre=pre[c].nombre;
                                         llegueP++;
                                         posicion++;
                                     }
                                 }
                             }
                          }
                     }
                 }
             }
            string aux;
            string aux1;
            string aux2;
            string aux3;
                for(int i=0; i<dim-devueltos; i++){
                    for(int j=i+1; j<dim-devueltos; j++){
                        if(cato[i].apellido>cato[j].apellido){
                            aux=cato[i].categoria; aux1=cato[i].descripcion; aux2=cato[i].apellido; aux3=cato[i].nombre;
                            cato[i].categoria=cato[j].categoria; cato[i].descripcion=cato[j].descripcion; cato[i].apellido=cato[j].apellido; cato[i].nombre=cato[j].nombre;
                            cato[j].categoria=aux; cato[j].descripcion=aux1; cato[j].apellido=aux2; cato[j].nombre=aux3;
                        }
                    }
                }
                cout<<" En orden alfabetico: "<<endl;
                for(int i=0; i<dim-devueltos; i++){
                    cout<<cato[i].apellido <<" " << cato[i].nombre <<" "<< cato[i].descripcion <<" " << cato[i].categoria<<endl;
                }
          }


        if(respuesta=="C"){
            while(llegueC==0){
                llegueC++;
                 for(int y=0; y<dim ;y++){
                     llegueC=0;
                     if(pres[y].estado==true){
                         for(int z=0; z<dim_c ; z++){
                             if(pres[y].categoria==cat[z].codigo){
                                 for(int c=0; c<dim_p ; c++){
                                     if(pres[y].prestatario==pre[c].codigo && llegueC==0){
                                         cato[posicion].categoria=cat[z].descripcion;
                                         cato[posicion].descripcion=pres[y].descripcion;
                                         cato[posicion].apellido=pre[c].apellido;
                                         cato[posicion].nombre=pre[c].nombre;
                                         //cout << "Descripcion del prestamo "<< pres[y].descripcion <<" Prestatario " << pre[c].apellido << " "<< pre[c].nombre;
                                         llegueC++;
                                         posicion++;
                                     }
                                 }
                             }
                          }
                     }
                 }
             }
            string aux;
            string aux1;
            string aux2;
            string aux3;
                for(int i=0; i<dim-devueltos; i++){
                    for(int j=i+1; j<dim-devueltos; j++){
                        if(cato[i].categoria>cato[j].categoria){
                            aux=cato[i].categoria; aux1=cato[i].descripcion; aux2=cato[i].apellido; aux3=cato[i].nombre;
                            cato[i].categoria=cato[j].categoria; cato[i].descripcion=cato[j].descripcion; cato[i].apellido=cato[j].apellido; cato[i].nombre=cato[j].nombre;
                            cato[j].categoria=aux; cato[j].descripcion=aux1; cato[j].apellido=aux2; cato[j].nombre=aux3;
                        }
                    }
                }
                cout<<" En orden alfabetico: "<<endl;
                for(int i=0; i<dim-devueltos; i++){
                    cout<<cato[i].categoria <<" " << cato[i].descripcion <<" "<< cato[i].apellido <<" " << cato[i].nombre<<endl;
                }
          }

}


    else{
    cout << "No hay prestamos pendientes "<< endl;
        } }





/*Parametros: imprimir todos los prestamos ordenados segun su categoria o prestatario.
   Parametros: estructura que almacenan categorias, los prestamos y los prestatarios.
   Retorno: no tiene valor de retorno ya que solamente imprime informacion.*/

 /* Devuelve un listado con las categorias o los prestatarios
        y la descripcion de los prestamos asociados a el/ella. */
////////////////////////////////////////////////////////////////////////////////////////////////////
void prestatarios_activos(un_prestatario pre[], int dim_p, un_prestamo pres[], int dim){
    if(hayprestamos!=0){
    int cant_prestamos;
    for(int x=0; x<dim_p; x++){
        cant_prestamos=0;
        for(int y=0; y<dim; y++){
            if(pre[x].codigo==pres[y].prestatario){
                if(pres[y].estado==true){
                     cant_prestamos++;
                }
            }
        }
        if(cant_prestamos!=0){
        cout << "Nombre " << pre[x].nombre << endl<< " Apellido " << pre[x].apellido << endl<< " Cantidad de prestamos sin devolver " << cant_prestamos<< endl;
    }}


    }
else{
    cout<<"No hay prestamos emitidos..."<< endl;}}

    /* Parametros: imprime que prestatario tiene objetos sin devolver.
   Parametros: estructura que almacenan los prestamos y los prestatarios.
   Retorno: no tiene valor de retorno ya que solamente imprime informacion.*/

/* Devulve una lista con todos los prestatarios que aun no devolvieron un objeto.*/
////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////--------------MAIN-----------------////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
///////////////////////////////////////////////////////////////////////////////////////////////////
//                   VARIABLES PARA EL MENU

    char valorc = 'C';
    char valorb = 'B';
    char valora = 'A';
    char valord = 'D';
/////////////////////////////////////////////////////////////////////////////////////////////////////

//                   DEMAS COSAS

    una_categoria categorias[DF];
    un_prestamo prestamos[DF];
    un_prestatario prestatarios[DF];
    una_categoria_ordenada categorias_ordenadas[DF];
    int dim_log_c=0;
    int dim_log_p=0;
    int dim_log=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////

//                  TODA LA EJECUCION DEL MENU

    int valor; //crea la variable en la que se va a almacenar la opcion del menu principal.

    do{ //elije las categorias de los distintos menus.

        valor=menu_principal();  //elije el valor del primer menu.

        if (valor==valora){
            switch(categorias_y_prestatarios()){
                case 'A':{
                    system("cls");
                    agregar_categoria(categorias,dim_log_c);
                    dim_log_c++;
                    pausa();
                    break;
                }
                case 'B':{
                    system("cls");
                    modificar_categoria(categorias, dim_log_c);
                    pausa();
                    break;
                }
                case 'C':{
                    system("cls");
                    eliminar_categoria(categorias,dim_log, prestamos, dim_log_c);
                    if(eliminados!=0){
                        dim_log_c--;
                        eliminados=0;
                    }
                    pausa();
                    break;
                }
                case 'D':{
                    system("cls");
                    agregar_prestatario(prestatarios, dim_log_p);
                    dim_log_p++;
                    pausa();
                    break;
                }
                case 'E':{
                    system("cls");
                    modificar_prestatario(prestatarios, dim_log_p);
                    pausa();
                    break;
                }
              case 'F':{
                    system("cls");
                    eliminar_prestatario(prestatarios, dim_log, prestamos, dim_log_p);
                    if(eliminadosP!=0){
                        dim_log_p--;
                        eliminados=0;
                    }
                    pausa();
                    break;
              }
                default:{
                    cout<<"opcion incorrecta";
                    break;
                }
            };
        }
        if (valor==valorb){
            switch(administrar_prestamos()){
                case 'A':{
                    system("cls");
                    agregar_prestamo(haycategorias, hayprestatarios, prestamos, dim_log, categorias, prestatarios, dim_log_c, dim_log_p);
                    dim_log++;
                    pausa();
                    break;
                }
                case 'B':{
                    system("cls");
                    modificar_prestamo(prestamos, dim_log);
                    pausa();
                    break;
                }
                case 'C':{
                    system("cls");
                    eliminar_prestamo(prestamos, dim_log);
                    dim_log--;
                    pausa();
                    break;
                }
                case 'D':{
                    system("cls");
                    devolver_prestamo(prestamos, dim_log, dim_log_p, prestatarios);
                    pausa();
                    break;
                }
            }
        }
        if (valor==valorc){
            switch(consultar_prestamo()){
            case 'A':{
                system("cls");
                cantidad_objetos_categoria(prestamos, dim_log,categorias,dim_log_c);
                pausa();
                break;
            }
            case 'B':{
                system("cls");
                prestamos_en_una_categoria(categorias,dim_log_c,prestamos, dim_log,prestatarios, dim_log_p);
                pausa();
                break;
            }
            case 'C':{
                system("cls");
                prestamos_por_categoria_o_prestatario(categorias, dim_log_c, prestamos, dim_log, prestatarios, dim_log_p, categorias_ordenadas);
                pausa();
                break;
            }
            case 'D':{
                system("cls");
                prestatarios_activos(prestatarios, dim_log_p, prestamos, dim_log);
                pausa();
                break;
            }
            default:{
                    cout<<"opcion incorrecta";
                    break;
                }
            };
        }
        if (valor==valord){
            cout<<"el programa finalizo con exito";
            break;
        }

    } while (valor!=true);
//--------------------------------------------------------------------------------------------------------

    return 0;
}

////////////////////////FUNCION QUE BOR RA EL EJECUTADOR AL FIN DE CADA BLOQUE//////////////////////////////
void pausa()
{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
