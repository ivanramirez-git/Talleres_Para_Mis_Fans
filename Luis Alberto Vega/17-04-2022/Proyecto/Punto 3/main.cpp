// bibliotecas
#include "../Biblioteca/biblioteca.h"

// funciones y procedimientos
int menu(){
    
    do{
        system("cls");
        color(16);
        gotoxy(10,2);
        printf("**** M e n u P r i n c i p a l ****");
        gotoxy(10,4);
        printf("================================================");
        gotoxy(10,6);
        printf("1- Ingresar Datos Vehiculos");
        gotoxy(10,8);
        printf("2- Ver Estadisticas Vehiculos Lavados segun tipo de Lavado");
        gotoxy(10,10);
        printf("3- Ver Estadisticas Vehiculos Lavados por tipo de Vehiculo");
        gotoxy(10,12);
        printf("4- Ver Grafico Vehiculos Lavados por Tipo de lavado");
        gotoxy(10,14);
        printf("5- Ver Grafico Vehiculos Lavados por Tipo de vehiculo");
        gotoxy(10,16);
        printf("6- Salir");
        gotoxy(10,18);
        printf("================================================");
        gotoxy(10,20);
        printf("Ingrese su opcion ----> ");
        gotoxy(10,22);
        printf("================================================");
        gotoxy(35,20);
        switch(getch()){
            case '1':
                return 1;
                break;
            case '2':
                return 2;
                break;
            case '3':
                return 3;
                break;
            case '4':
                return 4;
                break;
            case '5':
                return 5;
                break;
            case '6':
                return 6;
                break;
            default:
                printf("Opcion no valida");
                break;
        }
    }while(true);
}

// variables de ambito global
int numeroTransaccion;

int cantidadVehiculosTipoSencillos, cantidadVehiculosTipo4x4, cantidadVehiculosTipoMicrobusCamion;
float dineroRecaudadoPorVehiculosTipoSencillos, dineroRecaudadoPorVehiculosTipo4x4, dineroRecaudadoPorVehiculosTipoMicrobusCamion;

int cantidadSoloLavado, cantidadLavadoAspiradoEncerado;
float dineroRecaudadoPorLavadoSencillos, dineroRecaudadoPorLavadoAspiradoEncerado;

// funciones y procedimientos
void ingresarDatosVehiculos(){
    numeroTransaccion++;
    // variables de ambito local
    char numeroplaca[10], marca[20], modelo[20];
    int tipoVehiculo, tipoLavado, contadorVehiculos;
    float precio;

// proceso
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Ingresar Datos Vehiculos");
    gotoxy(10,4);
    printf("Ingrese el numero de placa: ");
    scanf("%s", numeroplaca);
    gotoxy(10,6);
    printf("Ingrese la marca: ");
    scanf("%s", marca);
    gotoxy(10,8);
    printf("Ingrese el modelo: ");
    scanf("%s", modelo);
    do{
        gotoxy(10,10);
        printf("Ingrese el tipo de vehiculo (1= Sencillo 2=4x4 3= Microbus o Camion): ");
        scanf("%d", &tipoVehiculo);
    }while(tipoVehiculo < 1 || tipoVehiculo > 3);
    do{
        gotoxy(10,12);
        printf("Ingrese el tipo de lavado (1=Solo Lavado, 2= Lavado, Aspirado y Encerado): ");
        scanf("%d", &tipoLavado);
    }while(tipoLavado < 1 || tipoLavado > 2);

    if(tipoVehiculo == 1){
        if(tipoLavado == 1){
            precio = 3000;
            dineroRecaudadoPorVehiculosTipoSencillos += precio;
            cantidadSoloLavado++;
            dineroRecaudadoPorLavadoSencillos += precio;

        }else{
            precio = 5000;
            dineroRecaudadoPorVehiculosTipoSencillos += precio;
            cantidadLavadoAspiradoEncerado++;
            dineroRecaudadoPorLavadoAspiradoEncerado += precio;
        }
        cantidadVehiculosTipoSencillos++;
    }else if(tipoVehiculo == 2){
        if(tipoLavado == 1){
            precio = 5000;
            dineroRecaudadoPorVehiculosTipo4x4 += precio;
            cantidadSoloLavado++;
            dineroRecaudadoPorLavadoSencillos += precio;
        }else{
            precio = 7000;
            dineroRecaudadoPorVehiculosTipo4x4 += precio;
            cantidadLavadoAspiradoEncerado++;
            dineroRecaudadoPorLavadoAspiradoEncerado += precio;
        }
        cantidadVehiculosTipo4x4++;
    }else{
        if(tipoLavado == 1){
            precio = 7000;
            dineroRecaudadoPorVehiculosTipoMicrobusCamion += precio;
            cantidadSoloLavado++;
            dineroRecaudadoPorLavadoSencillos += precio;
        }else{
            precio = 12000;
            dineroRecaudadoPorVehiculosTipoMicrobusCamion += precio;
            cantidadLavadoAspiradoEncerado++;
            dineroRecaudadoPorLavadoAspiradoEncerado += precio;
        }
        cantidadVehiculosTipoMicrobusCamion++;
    }
    gotoxy(10,14);
    printf("Numero de factura: %d", numeroTransaccion);
    gotoxy(10,16);
    printf("Numero de placa: %s", numeroplaca);
    gotoxy(10,18);
    printf("Marca: %s", marca);
    gotoxy(10,20);
    printf("Modelo: %s", modelo);
    gotoxy(10,22);
    printf("Tipo de vehiculo: ");
    switch(tipoVehiculo){
        case 1:
            printf("Sencillo");
            break;
        case 2:
            printf("4x4");
            break;
        case 3:
            printf("Microbus o Camion");
            break;
    }
    gotoxy(10,24);
    printf("Tipo de lavado: ");
    switch(tipoLavado){
        case 1:
            printf("Solo Lavado");
            break;
        case 2:
            printf("Lavado, Aspirado y Encerado");
            break;
    }
    gotoxy(10,26);
    printf("Precio a pagar: %.2f", precio);
    gotoxy(10,28);
    printf("Desea continuar (S/N): ");
    switch(toupper(getch())){
        case 'S':
            ingresarDatosVehiculos();
            break;
        case 'N':
            return;
            break;
        default:
            printf("Opcion no valida");
            getch();
            ingresarDatosVehiculos();
            break;
    }
}

void verEstadisticasVehiculosLavados(){
    
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Ver Estadisticas Vehiculos Lavados");
    gotoxy(10,4);
    printf("Cantidad de Vehiculos Tipo Sencillos: %d", cantidadVehiculosTipoSencillos);
    gotoxy(10,6);
    printf("Dinero Recaudado por Vehiculos Tipo Sencillos: %.2f", dineroRecaudadoPorVehiculosTipoSencillos);
    gotoxy(10,10);
    printf("Cantidad de Vehiculos Tipo 4x4: %d", cantidadVehiculosTipo4x4);
    gotoxy(10,12);
    printf("Dinero Recaudado por Vehiculos Tipo 4x4: %.2f", dineroRecaudadoPorVehiculosTipo4x4);
    gotoxy(10,16);
    printf("Cantidad de Vehiculos Tipo Microbus o Camion: %d", cantidadVehiculosTipoMicrobusCamion);
    gotoxy(10,18);
    printf("Dinero Recaudado por Vehiculos Tipo Microbus o Camion: %.2f", dineroRecaudadoPorVehiculosTipoMicrobusCamion);
    gotoxy(10,22);
    printf("Presione cualquier tecla para continuar...");
    getch();

}

void verEstadisticasVehiculosLavadosTipoLavado(){
    
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Ver Estadisticas Vehiculos Lavados Tipo Lavado");
    gotoxy(10,4);
    printf("Cantidad de Vehiculos de solo Lavado: %d", cantidadSoloLavado);
    gotoxy(10,6);
    printf("Dinero Recaudado por Vehiculos de solo Lavado: %.2f", dineroRecaudadoPorLavadoSencillos);
    gotoxy(10,8);
    printf("Promedio Dinero Recaudado por Vehiculos de solo Lavado: %.2f", dineroRecaudadoPorLavadoSencillos/cantidadSoloLavado);
    gotoxy(10,12);
    printf("Cantidad de Vehiculos con Lavado, Aspirado y Encerado: %d", cantidadLavadoAspiradoEncerado);
    gotoxy(10,14);
    printf("Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: %.2f", dineroRecaudadoPorLavadoAspiradoEncerado);
    gotoxy(10,16);
    printf("Promedio Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: %.2f", dineroRecaudadoPorLavadoAspiradoEncerado/cantidadLavadoAspiradoEncerado);
    gotoxy(10,20);
    printf("Presione cualquier tecla para continuar...");
    getch();

}

void verGraficoVehiculosLavadosTipoLavado(){
    
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Grafico Vehiculos lavados por tipo de lavado");
    gotoxy(10,4);
    printf("Sencillo: ");
    gotoxy(10,6);
    for(int i=0; i<cantidadSoloLavado; i++){
        // 178 = ▓
        printf("%c", 178);
    }
    gotoxy(10,8);
    printf("Completo: ");
    gotoxy(10,10);
    for(int i=0; i<cantidadLavadoAspiradoEncerado; i++){
        // 178 = ▓
        printf("%c", 178);
    }
    gotoxy(10,12);
    printf("<Pulse tecla para regresar al menu>");
    getch();

}

void verGraficoVehiculosLavadosTipoVehiculo(){
    
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Grafico Vehiculos lavados por tipo de Vehiculo");
    gotoxy(10,4);
    printf("Veh. Sencillos: ");
    gotoxy(10,6);
    for(int i=0; i<cantidadVehiculosTipoSencillos; i++){
        // 178 = ▓
        printf("%c", 178);
    }
    gotoxy(10,8);
    printf("Veh. 4x4: ");
    gotoxy(10,10);
    for(int i=0; i<cantidadVehiculosTipo4x4; i++){
        // 178 = ▓
        printf("%c", 178);
    }
    gotoxy(10,12);
    printf("Veh. Pesados: ");
    gotoxy(10,14);
    for(int i=0; i<cantidadVehiculosTipoMicrobusCamion; i++){
        // 178 = ▓
        printf("%c", 178);
    }
    gotoxy(10,16);
    printf("<Pulse tecla para regresar al menu>");
    getch();

}

// main
int main(){
    numeroTransaccion = 0;
    do{
        switch(menu()){
            case 1:
                ingresarDatosVehiculos();
                break;
            case 2:
                verEstadisticasVehiculosLavadosTipoLavado();
                break;
            case 3:
                verEstadisticasVehiculosLavados();
                break;
            case 4:
                verGraficoVehiculosLavadosTipoLavado();
                break;
            case 5:
                verGraficoVehiculosLavadosTipoVehiculo();
                break;
            case 6:
                system("cls");
                return 0;
                break;
        }
    }while(true);
}