#include <iostream>

using namespace std;

struct alumno{
    string nombre;
    string apellido;
    string trabajoPractico;
    string nro_documento;
    float notaPrimerParcial;
    float notaSegundoParcial;
    float notaExamenFinal;
    float calificacion;

};

float calificacion(float nota1, float nota2, float nota3){
    
    float calificacion;
    float porcentaje = (nota1 + nota2 + nota3)/15;
    if(porcentaje < 0.7){
        calificacion = 1;
    }else if(porcentaje >= 0.7 && porcentaje < 0.8){
        calificacion = 2;
    }else if(porcentaje >= 0.8 && porcentaje < 0.9){
        calificacion = 3;
    }else if(porcentaje >= 0.9 && porcentaje < 1){
        calificacion = 4;
    }else if(porcentaje >= 1){
        calificacion = 5;
    }
    return calificacion;
}

void llenarRegistro(alumno registro[10]){
    registro[0].nombre = "Augusto";
    registro[0].apellido = "Caballero";
    registro[0].nro_documento = "6.294.677";
    registro[0].notaPrimerParcial = 10;
    registro[0].notaSegundoParcial = 13;
    registro[0].notaExamenFinal = 15;
    registro[0].trabajoPractico = "Ciencias";
    registro[0].calificacion = calificacion(registro[0].notaPrimerParcial, registro[0].notaSegundoParcial, registro[0].notaExamenFinal);

    registro[1].nombre = "Ana";
    registro[1].apellido = "Gomez";
    registro[1].nro_documento = "6.621.337";
    registro[1].notaPrimerParcial = 13;
    registro[1].notaSegundoParcial = 15;
    registro[1].notaExamenFinal = 14;
    registro[1].trabajoPractico = "Tecnologias";
    registro[1].calificacion = calificacion(registro[1].notaPrimerParcial, registro[1].notaSegundoParcial, registro[1].notaExamenFinal);

    registro[2].nombre = "Emiliana";
    registro[2].apellido = "Rolon";
    registro[2].nro_documento = "2.098.789";
    registro[2].notaPrimerParcial = 11;
    registro[2].notaSegundoParcial = 14;
    registro[2].notaExamenFinal = 15;
    registro[2].trabajoPractico = "Lenguajes";
    registro[2].calificacion = calificacion(registro[2].notaPrimerParcial, registro[2].notaSegundoParcial, registro[2].notaExamenFinal);

    registro[3].nombre = "Eleno";
    registro[3].apellido = "Caballero";
    registro[3].nro_documento = "1.890.786";
    registro[3].notaPrimerParcial = 9;
    registro[3].notaSegundoParcial = 12;
    registro[3].notaExamenFinal = 14;
    registro[3].trabajoPractico = "Matematicas";
    registro[3].calificacion = calificacion(registro[3].notaPrimerParcial, registro[3].notaSegundoParcial, registro[3].notaExamenFinal);

    registro[4].nombre = "Araceli";
    registro[4].apellido = "Alvarenga";
    registro[4].nro_documento = "7.543.325";
    registro[4].notaPrimerParcial = 15;
    registro[4].notaSegundoParcial = 14;
    registro[4].notaExamenFinal = 13;
    registro[4].trabajoPractico = "Ciencias";
    registro[4].calificacion = calificacion(registro[4].notaPrimerParcial, registro[4].notaSegundoParcial, registro[4].notaExamenFinal);
    
    registro[5].nombre = "Blas";
    registro[5].apellido = "Caballero";
    registro[5].nro_documento = "4.678.905";
    registro[5].notaPrimerParcial = 7;
    registro[5].notaSegundoParcial = 13;
    registro[5].notaExamenFinal = 15;
    registro[5].trabajoPractico = "Matematicas";
    registro[5].calificacion = calificacion(registro[5].notaPrimerParcial, registro[5].notaSegundoParcial, registro[5].notaExamenFinal);

    registro[6].nombre = "Bruno";
    registro[6].apellido = "Rolon";
    registro[6].nro_documento = "6.289.908";
    registro[6].notaPrimerParcial = 15;
    registro[6].notaSegundoParcial = 14;
    registro[6].notaExamenFinal = 13;
    registro[6].trabajoPractico = "Ciencias";
    registro[6].calificacion = calificacion(registro[6].notaPrimerParcial, registro[6].notaSegundoParcial, registro[6].notaExamenFinal);

    registro[7].nombre = "Belen";
    registro[7].apellido = "Ríos";
    registro[7].nro_documento = "6.671.733";
    registro[7].notaPrimerParcial = 15;
    registro[7].notaSegundoParcial = 13;
    registro[7].notaExamenFinal = 14;
    registro[7].trabajoPractico = "Ciencias";
    registro[7].calificacion = calificacion(registro[7].notaPrimerParcial, registro[7].notaSegundoParcial, registro[7].notaExamenFinal);

    registro[8].nombre = "Emilce";
    registro[8].apellido = "Ortigoza";
    registro[8].nro_documento = "5.231.007";
    registro[8].notaPrimerParcial = 12;
    registro[8].notaSegundoParcial = 14;
    registro[8].notaExamenFinal = 15;
    registro[8].trabajoPractico = "Lenguajes";
    registro[8].calificacion = calificacion(registro[8].notaPrimerParcial, registro[8].notaSegundoParcial, registro[8].notaExamenFinal);

    registro[9].nombre = "Camila";
    registro[9].apellido = "Coronel";
    registro[9].nro_documento = "2.744.999";
    registro[9].notaPrimerParcial = 15;
    registro[9].notaSegundoParcial = 14;
    registro[9].notaExamenFinal = 13;
    registro[9].trabajoPractico = "Matematicas";
    registro[9].calificacion = calificacion(registro[9].notaPrimerParcial, registro[9].notaSegundoParcial, registro[9].notaExamenFinal);

}

int main()
{
    alumno registro[10];

    llenarRegistro(registro);

    // Imprimir los registros
    for (int i = 0; i < 10; i++)
    {
        cout << "Nombre: " << registro[i].nombre << endl;
        cout << "Apellido: " << registro[i].apellido << endl;
        cout << "Nro. de documento: " << registro[i].nro_documento << endl;
        cout << "Nota primer parcial: " << registro[i].notaPrimerParcial << endl;
        cout << "Nota segundo parcial: " << registro[i].notaSegundoParcial << endl;
        cout << "Nota examen final: " << registro[i].notaExamenFinal << endl;
        cout << "Trabajo practico: " << registro[i].trabajoPractico << endl;
        cout << "Calificacion: " << registro[i].calificacion << endl;
        cout << endl;
    }

    return 0;
}