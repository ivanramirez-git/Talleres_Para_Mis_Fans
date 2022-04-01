#include <iostream>
#define MAX_CANCIONES 20

using namespace std;

struct Cancion{
    string titulo;
    string artista;
    string album;
    float puntaje;
    int duracion;
};
// Validar que los segundos sean menores a 60
int validarDuracion(int segundos){
    string duracion;
    int min;
    int sec;
    bool valido = false;
    while(!valido){
        cout << "Ingrese la duracion de la cancion (m.ss): ";
        cin >> duracion;
        min = stoi(duracion.substr(0,duracion.find(".")));
        sec = stoi(duracion.substr(duracion.find(".")+1));
        if(sec < 60){
            valido = true;
        }
        else{
            cout << "La duracion de la cancion debe ser menor a 60 segundos" << endl;
        }
    }
    return min*60 + sec;
}

Cancion ingresarCancion(){
    Cancion cancion;
    string duracion;
    int min;
    int sec;
    cout << "Ingrese el titulo de la cancion: ";
    cin >> cancion.titulo;
    cout << "Ingrese el artista de la cancion: ";
    cin >> cancion.artista;
    cout << "Ingrese el album de la cancion: ";
    cin >> cancion.album;
    cout << "Ingrese el puntaje de la cancion: ";
    cin >> cancion.puntaje;
    cancion.duracion = validarDuracion(cancion.duracion);
    return cancion;
}

// Ordenar de A-Z
void ordenarAZ(Cancion canciones[], int cantidad){
    Cancion aux;
    for(int i = 0; i < cantidad; i++){
        for(int j = i+1; j < cantidad; j++){
            if(canciones[i].titulo > canciones[j].titulo){
                aux = canciones[i];
                canciones[i] = canciones[j];
                canciones[j] = aux;
            }
        }
    }
}

// Listar Catalogo
void listarCatalogo(Cancion canciones[], int cantidad){
    for(int i = 0; i < cantidad; i++){
        cout << "Titulo: " << canciones[i].titulo << endl;
        cout << "Artista: " << canciones[i].artista << endl;
        cout << "Puntaje: " << canciones[i].puntaje << endl;
        cout << "Duracion: " << canciones[i].duracion << endl;
    }
}

// Ordenar por Artistas A-Z
void ordenarArtistas(Cancion canciones[], int cantidad){
    Cancion aux;
    for(int i = 0; i < cantidad; i++){
        for(int j = i+1; j < cantidad; j++){
            if(canciones[i].artista > canciones[j].artista){
                aux = canciones[i];
                canciones[i] = canciones[j];
                canciones[j] = aux;
            }
        }
    }
}

// Mostrar que cancion tiene el puntaje mas alto
void puntajeMasAlto(Cancion canciones[], int cantidad){
    int puntajeMasAlto = 0;
    int posicion = 0;
    for(int i = 0; i < cantidad; i++){
        if(canciones[i].puntaje > puntajeMasAlto){
            puntajeMasAlto = canciones[i].puntaje;
            posicion = i;
        }
    }
    cout << "La cancion con el puntaje mas alto es: " << canciones[posicion].titulo << endl;
}

// Promedio de duracion de las canciones
float promedioDuracion(Cancion canciones[], int cantidad){
    float duracionTotal = 0;
    for(int i = 0; i < cantidad; i++){
        duracionTotal += canciones[i].duracion;
    }
    return duracionTotal/cantidad;
}

// Ordenar por puntaje de manera descendente, del mas alto al mas bajo
void ordenarPuntaje(Cancion canciones[], int cantidad){
    Cancion aux;
    for(int i = 0; i < cantidad; i++){
        for(int j = i+1; j < cantidad; j++){
            if(canciones[i].puntaje < canciones[j].puntaje){
                aux = canciones[i];
                canciones[i] = canciones[j];
                canciones[j] = aux;
            }
        }
    }
}

// Mostrar cancione por album
void cancionesPorAlbum(Cancion canciones[], int cantidad){
    string album;
    cout << "Ingrese el album: ";
    cin >> album;
    for(int i = 0; i < cantidad; i++){
        if(canciones[i].album.find(album) != string::npos){
            cout << "Titulo: " << canciones[i].titulo << endl;
            cout << "Artista: " << canciones[i].artista << endl;
            cout << "Puntaje: " << canciones[i].puntaje << endl;
            cout << "Duracion: " << canciones[i].duracion << endl;
        }
    }
}

// Mostrar cuantas canciones tienen puntaje 5
int cantidadPuntaje5(Cancion canciones[], int cantidad){
    int cantidad5 = 0;
    for(int i = 0; i < cantidad; i++){
        if(canciones[i].puntaje == 5){
            cantidad5++;
        }
    }
    return cantidad5;
}
// Datos de prueba
void llenarDatos(Cancion canciones[], int cantidad){
    canciones[0].titulo = "Cancion 1";
    canciones[0].artista = "Artista 1";
    canciones[0].album = "Album 1";
    canciones[0].puntaje = 5;
    canciones[0].duracion = 120;
    canciones[1].titulo = "Cancion 2";
    canciones[1].artista = "Artista 2";
    canciones[1].album = "Album 2";
    canciones[1].puntaje = 4;
    canciones[1].duracion = 120;
    canciones[2].titulo = "Cancion 3";
    canciones[2].artista = "Artista 3";
    canciones[2].album = "Album 3";
    canciones[2].puntaje = 3;
    canciones[2].duracion = 120;
    canciones[3].titulo = "Cancion 4";
    canciones[3].artista = "Artista 4";
    canciones[3].album = "Album 4";
    canciones[3].puntaje = 2;
    canciones[3].duracion = 120;


// Programa Principal
int main(){
    Cancion canciones[10];
    int cantidad = 0;
    int opcion;
    do{
        cout << "1. Ingresar Cancion" << endl;
        cout << "2. Ordenar por Titulo A-Z" << endl;
        cout << "3. Listar Catalogo" << endl;
        cout << "4. Ordenar por Artistas A-Z" << endl;
        cout << "5. Mostrar que cancion tiene el puntaje mas alto" << endl;
        cout << "6. Promedio de duracion de las canciones" << endl;
        cout << "7. Ordenar por puntaje de manera descendente, del mas alto al mas bajo" << endl;
        cout << "8. Mostrar canciones por album" << endl;
        cout << "9. Cantidad de canciones con puntaje 5" << endl;
        cout << "10. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                canciones[cantidad] = ingresarCancion();
                cantidad++;
                break;
            case 2:
                ordenarAZ(canciones, cantidad);
                break;
            case 3:
                listarCatalogo(canciones, cantidad);
                break;
            case 4:
                ordenarArtistas(canciones, cantidad);
                break;
            case 5:
                puntajeMasAlto(canciones, cantidad);
                break;
            case 6:
                cout << "El promedio de duracion de las canciones es: " << promedioDuracion(canciones, cantidad) << endl;
                break;
            case 7:
                ordenarPuntaje(canciones, cantidad);
                break;
            case 8:
                cancionesPorAlbum(canciones, cantidad);
                break;
            case 9:
                cout << "La cantidad de canciones con puntaje 5 es: " << cantidadPuntaje5(canciones, cantidad) << endl;
                break;
            case 10:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    }while(opcion != 10);
    return 0;
}