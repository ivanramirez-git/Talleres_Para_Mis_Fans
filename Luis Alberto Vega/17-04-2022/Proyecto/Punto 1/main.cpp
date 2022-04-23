// Se le solicita realizar un sistema que lleve el control de “N” ventas de entradas de los cines del Mall Paseo Las Flores.
// bibliotecas
#include "../Biblioteca/biblioteca.h"

// funciones y de los procedimientos
int menu(){
    
    do{
        system("cls");
        color(15);
        gotoxy(10,2);
        printf("Menu Principal");
        gotoxy(10,4);
        printf("1- Ingresar Venta");
        gotoxy(10,6);
        printf("2- Ver Estadisticas");
        gotoxy(10,8);
        printf("3- Ver Graficos");
        gotoxy(10,10);
        printf("4- Salir");
        gotoxy(10,12);
        printf("Ingrese una opcion: ");
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
                printf("Opcion invalida");
                getch();
                break;
        }
    }while(true);
}

// variables de ambito global
int cantidadSala1, cantidadSala2, cantidadSala3, numeroTransaccion;
float recaudadoSala1, recaudadoSala2, recaudadoSala3;

void ingresarVenta(){
    numeroTransaccion++;
    char cedula[10], nombre[30], numeroSala[2], cantidadEntradas[3], precioEntrada[5];
    int sala, cantidad;
    float precio, subtotal, impuesto, total;
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("Ingresar Venta");
    gotoxy(10,4);
    printf("Numero Transaccion: %d", numeroTransaccion);
    gotoxy(10,6);
    printf("Cedula: ");
    scanf("%s", cedula);
    gotoxy(10,8);
    printf("Nombre: ");
    fflush(stdin);
    gets(nombre);
    do{
        gotoxy(10,10);
        printf("Numero Cine: ");
        scanf("%s", numeroSala);
        sala = ctoi(numeroSala);
    }while(sala < 1 || sala > 3);
    do{
        gotoxy(10,12);
        printf("Cantidad Entradas: ");
        scanf("%s", cantidadEntradas);
        cantidad = ctoi(cantidadEntradas);
    }while(cantidad < 0);
    do{
        gotoxy(10,14);
        printf("Precio por Entrada: ");
        scanf("%s", precioEntrada);
        precio = ctof(precioEntrada);
    }while(precio < 0);

    subtotal = cantidad * precio;
    impuesto = subtotal * 0.13;
    total = subtotal + impuesto;

    switch(sala){
        case 1:
            recaudadoSala1 += total;
            cantidadSala1 += cantidad;
            break;
        case 2:
            recaudadoSala2 += total;
            cantidadSala2 += cantidad;
            break;
        case 3:
            recaudadoSala3 += total;
            cantidadSala3 += cantidad;
            break;
    }

    system("cls");
    color(22);
    gotoxy(10,2);
    printf("Venta Ingresada");
    gotoxy(10,4);
    printf("Numero Transaccion: %d", numeroTransaccion);
    gotoxy(10,6);
    printf("Cedula: %s", cedula);
    gotoxy(10,8);
    printf("Nombre: %s", nombre);
    gotoxy(10,10);
    printf("Numero Cine: \n");
    switch(sala){
        case 1:
            gotoxy(10,12);
            printf("<X Sala 1>\t<2 Sala 2>\t<3 Sala 3>");
            break;
        case 2:
            gotoxy(10,12);
            printf("<1 Sala 1>\t<X Sala 2>\t<3 Sala 3>");
            break;
        case 3:
            gotoxy(10,12);
            printf("<1 Sala 1>\t<2 Sala 2>\t<X Sala 3>");
            break;
    }
    gotoxy(10,14);
    printf("Cantidad Entradas: %d", cantidad);
    gotoxy(10,16);
    printf("Precio por Entrada: %.2f", precio);
    gotoxy(10,18);
    printf("Subtotal de Venta: %.2f", subtotal);
    gotoxy(10,20);
    printf("Impuesto IVA: %.2f", impuesto);
    gotoxy(10,22);
    printf("Total Pagar: %.2f", total);
    
    // Desear Continuar S/N
    do{
        gotoxy(10,24);
        printf("Desear Continuar S/N: ");
        switch(toupper(getch())){
            case 'S':
                ingresarVenta();
                break;
            case 'N':
                return;
                break;
            default:
                printf("Opcion invalida");
                getch();
                break;
        }
    }while(true);
    
}

/*

*********    Ver Ventas    ****************** 
    Cantidad Entrada Vendidas Sala 1: 
             Dinero Recaudado Sala 1: 
    Cantidad Entrada Vendidas Sala 2: 
             Dinero Recaudado Sala 2: 
    Cantidad Entrada Vendidas Sala 3: 
             Dinero Recaudado Sala 3: 
    Cantidad Total Entradas Vendidas: 
             Dinero Total Recaudado.: 
    
    <Pulse tecla para Abandonar>

*/
void verVentas(){
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("*********    Ver Ventas    ******************");
    gotoxy(10,4);
    printf("Cantidad Entrada Vendidas Sala 1: %d", cantidadSala1);
    gotoxy(19,6);
    printf("Dinero Recaudado Sala 1: %.2f", recaudadoSala1);
    gotoxy(10,8);
    printf("Cantidad Entrada Vendidas Sala 2: %d", cantidadSala2);
    gotoxy(19,10);
    printf("Dinero Recaudado Sala 2: %.2f", recaudadoSala2);
    gotoxy(10,12);
    printf("Cantidad Entrada Vendidas Sala 3: %d", cantidadSala3);
    gotoxy(19,14);
    printf("Dinero Recaudado Sala 3: %.2f", recaudadoSala3);
    gotoxy(10,16);
    printf("Cantidad Total Entradas Vendidas: %d", cantidadSala1 + cantidadSala2 + cantidadSala3);
    gotoxy(19,18);
    printf("Dinero Total Recaudado.: %.2f", recaudadoSala1 + recaudadoSala2 + recaudadoSala3);
    gotoxy(10,20);
    printf("<Pulse tecla para Abandonar>");
    getch();
    system("cls");
}

/*

*******Grafico Ventas Entradas por Sala******* 
 
Sala 1 ▓▓▓▓▓▓▓▓▓▓ 
 
Sala 2 ▓▓▓▓▓▓
 
Sala 3 ▓▓▓▓▓▓▓▓▓
 
<Pulse tecla para Abandonar> 

*/
void graficoVentas(){
    system("cls");
    color(16);
    gotoxy(10,2);
    printf("*******Grafico Ventas Entradas por Sala*******");
    gotoxy(10,4);
    printf("Sala 1 ");
    for(int i = 0; i < cantidadSala1; i++){
        // 178 = ▓
        printf("%c", 178);
    }
    gotoxy(10,6);
    printf("Sala 2 ");
    for(int i = 0; i < cantidadSala2; i++){
        printf("%c", 178);
    }
    gotoxy(10,8);
    printf("Sala 3 ");
    for(int i = 0; i < cantidadSala3; i++){
        printf("%c", 178);
    }
    gotoxy(10,10);
    printf("<Pulse tecla para Abandonar>");
    getch();
}

// main
int main(){
    numeroTransaccion = 0;
    do{
        switch(menu()){
            case 1:
                ingresarVenta();
                break;
            case 2:
                verVentas();
                break;
            case 3:
                graficoVentas();
                break;
            case 4:
                system("cls");
                return 0;
                break;
        }
    }while(true);
}