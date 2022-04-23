// Se le solicita realizar un sistema que lleve el control de “N” ventas de entradas de los cines del Mall Paseo Las Flores.
// bibliotecas
#include "../Biblioteca/biblioteca.h"

// funciones y de los procedimientos
int menu(){
    do{
        system("cls");
        color(16);
        gotoxy(10,2);
        printf("Menu Principal");
        gotoxy(10,4);
        printf("1- Realizar Transaccion");
        gotoxy(10,6);
        printf("2- Ver Estadisticas");
        gotoxy(10,8);
        printf("3- Ver Graficos");
        gotoxy(10,10);
        printf("4- Salir");
        gotoxy(10,12);
        printf("Opcion: ");
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
            default:
                printf("Opcion no valida");
                break;
        }        
    }while(true);
}

// variables de ambito global
int numeroTransaccion, cantidadTransaccionesColonesDolares, cantidadTransaccionesDolaresColones;
float dineroCambiadoColonesDolares, dineroCambiadoDolaresColones;

void ingresarTransaccion(){
    numeroTransaccion++;
    char cedula[10], nombre[30], fecha[11], tipoCambio[2], valorDolar[10], valorColones[10];
    int tipoCambioInt;
    float valorDolarFloat, montoACambiarFloat;
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Ingresar Cambio");
    gotoxy(10,4);
    printf("Numero Transaccion: %d", numeroTransaccion);
    gotoxy(10,6);
    printf("Cedula: ");
    scanf("%s", cedula);
    gotoxy(10,8);
    printf("Nombre: ");
    fflush(stdin);
    gets(nombre);
    gotoxy(10,10);
    printf("Fecha: ");
    scanf("%s", fecha);
    do{
        gotoxy(10,12);
        printf("Tipo de Cambio: ");
        scanf("%s", tipoCambio);
        tipoCambioInt = ctoi(tipoCambio);
    }while(tipoCambioInt < 1 || tipoCambioInt > 2);
    do{
        gotoxy(10,14);
        printf("Valor del Dolar: ");
        scanf("%s", valorDolar);
        valorDolarFloat = ctof(valorDolar);
    }while(valorDolar < 0);
    do{
        gotoxy(10,16);
        printf("Monto a Cambiar: ");
        scanf("%s", valorColones);
        montoACambiarFloat = ctof(valorColones);
    }while(montoACambiarFloat < 0);

    if(tipoCambioInt == 1){
        cantidadTransaccionesColonesDolares++;
        dineroCambiadoColonesDolares += montoACambiarFloat;
    

        // mostrar datos
        system("cls");
        color(22);
        gotoxy(10,2);
        printf("Cambio Ingresado");
        gotoxy(10,4);
        printf("Numero Transaccion: %d", numeroTransaccion);
        gotoxy(10,6);
        printf("Cedula: %s", cedula);
        gotoxy(10,8);
        printf("Nombre: %s", nombre);
        gotoxy(10,10);
        printf("Fecha: %s", fecha);
        gotoxy(10,12);
        printf("Tipo de Cambio: ");
        gotoxy(10,14);
        printf("<1 Colones> <X Dolares>");
        gotoxy(10,16);
        printf("Valor del Dolar: %.2f", valorDolarFloat);
        gotoxy(10,18);
        printf("Monto a Cambiar: %.2f", montoACambiarFloat);
        gotoxy(10,20);
        printf("Monto cambiado: %.2f", montoACambiarFloat/valorDolarFloat);
        gotoxy(10,22);
        float comision007 = montoACambiarFloat/valorDolarFloat * 0.007;
        printf("Comision: %.2f", comision007);
        
    }else{
        cantidadTransaccionesDolaresColones++;
        dineroCambiadoDolaresColones += montoACambiarFloat;

        // mostrar datos
        system("cls");
        color(22);
        gotoxy(10,2);
        printf("Cambio Ingresado");
        gotoxy(10,4);
        printf("Numero Transaccion: %d", numeroTransaccion);
        gotoxy(10,6);
        printf("Cedula: %s", cedula);
        gotoxy(10,8);
        printf("Nombre: %s", nombre);
        gotoxy(10,10);
        printf("Fecha: %s", fecha);
        gotoxy(10,12);
        printf("Tipo de Cambio: ");
        gotoxy(10,14);
        printf("<X Dolares> <2 Colones>");
        gotoxy(10,16);
        printf("Valor del Dolar: %.2f", valorDolarFloat);
        gotoxy(10,18);
        printf("Monto a Cambiar: %.2f", montoACambiarFloat);
        gotoxy(10,20);
        printf("Monto cambiado: %.2f", montoACambiarFloat * valorDolarFloat);
        gotoxy(10,22);
        float comision005 = montoACambiarFloat * valorDolarFloat * 0.005;
        printf("Comision: %.2f", comision005);

    }

    gotoxy(10,24);
    printf("Desea Continuar S/N: ");
    switch(toupper(getch())){
        case 'S':
            ingresarTransaccion();
            break;
        case 'N':
            return;
            break;
        default:
            printf("Opcion invalida");
            getch();
            break;
    }

}

void estadisticasTransacciones(){
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Estadisticas Transacciones");
    gotoxy(10,4);
    printf("Cantidad Transacciones Colones a Dolares..: %d", cantidadTransaccionesColonesDolares);
    gotoxy(10,6);
    printf("Dinero Cambiado Colones a Dolares.........: %.2f", dineroCambiadoColonesDolares);
    gotoxy(10,8);
    printf("Promedio Dinero Cambiado Colones a Dolares: %.2f", dineroCambiadoColonesDolares / cantidadTransaccionesColonesDolares);
    gotoxy(10,10);
    printf("Cantidad Transacciones Dolares a Colones..: %d", cantidadTransaccionesDolaresColones);
    gotoxy(10,12);
    printf("Dinero Cambiado Dolares a Colones.........: %.2f", dineroCambiadoDolaresColones);
    gotoxy(10,14);
    printf("Promedio Dinero Cambiado Dolares a Colones: %.2f", dineroCambiadoDolaresColones / cantidadTransaccionesDolaresColones);
    gotoxy(10,16);
    printf("<Pulse cualquier tecla para regresar al menu>");
    getch();
}

void graficoCantidadTransacciones(){
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Grafico Cantidad Transacciones realizadas por tipo de Moneda");
    gotoxy(10,4);
    printf("Colones a Dolares ");
    for(int i = 0; i < cantidadTransaccionesColonesDolares; i++){
        // ▓ = 178
        printf("%c", 178);
    }
    gotoxy(10,6);
    printf("Dolares a Colones ");
    for(int i = 0; i < cantidadTransaccionesDolaresColones; i++){
        // ▓ = 178
        printf("%c", 178);
    }
    gotoxy(10,8);
    printf("<Pulse cualquier tecla para regresar al menu>");
    getch();
}

// main
int main(){
    numeroTransaccion = 0;
    do{
        switch(menu()){
            case 1:
                ingresarTransaccion();
                break;
            case 2:
                estadisticasTransacciones();
                break;
            case 3:
                graficoCantidadTransacciones();
                break;
            case 4:
                system("cls");
                return 0;
                break;
        }
    }while(true);
}

