
// Punto 7
// Tenemos una matriz que almacena el porcentaje de inflacion de cada mes de 5 años consecutivos, en el cual la fila representa un año en particular.
// El programa debe permitir al usuario las siguientes opciones:
// 1. Imprimir en pantalla un cuadro comparativo con la siguiente estructura:
/*
    Año/Mes Enero Febrero Marzo Abril ...
    2005
    2006
    ...
*/
// 2. Imprimir el promedio de un determinado mes..
// 3. Imprimir en pantalla la suma de las inflaciones de un determinado año.

var
    // Matriz de inflaciones
    porcentaje : matriz [5,12] numerico
    // Variables auxiliares
    num1, num2, num3 : numerico
    contador, contador1, contador2, contador3 : numerico
    // Variables para el menu
    opcion : numerico
    // Variables para el promedio
    promedio : numerico
    // Variables para la suma
    suma : numerico
    // Variables para el cuadro comparativo
    años : vector [5] numerico
    mes : vector [12]  cadena

inicio

    // Datos de años y meses
    años[1]=2005
    años[2]=2006
    años[3]=2007
    años[4]=2008
    años[5]=2009
    mes[1]="Enero"
    mes[2]="Febrero"
    mes[3]="Marzo"
    mes[4]="Abril"
    mes[5]="Mayo"
    mes[6]="Junio"
    mes[7]="Julio"
    mes[8]="Agosto"
    mes[9]="Septiembre"
    mes[10]="Octubre"
    mes[11]="Noviembre"
    mes[12]="Diciembre"


    // Datos de la matriz de inflaciones alatorios
    contador=1
    mientras(contador<=5){
        contador1=1
        mientras(contador1<=12){
            porcentaje[contador,contador1]=random(100)
            contador1=contador1+1
        }
        contador=contador+1
    }

   

    // Menu
    desde num3=1 hasta 10{
        // Mostrar menu
        imprimir("\n\nMenu:\n")
        imprimir("1. Cuadro comparativo\n")
        imprimir("2. Promedio de inflacion de un determinado mes\n")
        imprimir("3. Suma de inflaciones de un determinado año\n")
        imprimir("4. Salir\n")
        imprimir("\nIngrese una opcion: ")
        leer(num1)

        // Validar opcion
        si(num1<1 || num1>4){
            imprimir("\nOpcion invalida")
        }
        si(num1==1){
             // Imprimir matriz con cuadro comparativo con años y con Meses
            /*
            Año/Mes Enero Febrero Marzo Abril ...
            2005
            2006
            ...
            */
            imprimir("\n\nCuadro comparativo con años contra meses:\n")
            contador=1
            // imprimir encabezado  
            imprimir("\n\t")
            imprimir("Años/Mes")
            mientras(contador<=12){
                imprimir(mes[contador],"\t")
                contador=contador+1
            }
            // imprimir años y datos
            contador=1
            mientras(contador<=5){
                imprimir("\n",años[contador],"\t")
                contador1=1
                mientras(contador1<=12){
                    imprimir(porcentaje[contador,contador1],"\t")
                    contador1=contador1+1
                }
                contador=contador+1
            }
        }
        si(num1==2){
            // Promedio de inflacion de un determinado mes
            imprimir("\nIngrese el mes: ")
            leer(num2)
            si(num2<1 || num2>12){
                imprimir("\nMes invalido")
            }
            contador=1
            promedio=0
            mientras(contador<=5){
                promedio=promedio+porcentaje[contador,num2]
                contador=contador+1
            }
            promedio=promedio/5
            imprimir("\nEl promedio de inflacion del mes ",mes[num2]," fue: ",promedio)
        }
        si(num1==3){
            // Suma de inflaciones de un determinado año
            imprimir("\nIngrese el año: ")
            leer(num3)
            si(num3<1 || num3>5){
                imprimir("\nAño invalido")
            }
            contador=1
            suma=0
            mientras(contador<=12){
                suma=suma+porcentaje[num3,contador]
                contador=contador+1
            }
            imprimir("\nLa suma de inflaciones del año ",años[num3]," fue: ",suma)
        }
        si(num1==4){
            // Salir
            imprimir("\nSaliendo...")
        }
    }
fin