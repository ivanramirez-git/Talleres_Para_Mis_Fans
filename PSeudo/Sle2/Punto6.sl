

// Punto 6
// Una empresa de ventas de electrodomesticos ha decidido guardar en una matriz, las ventas realizadas por sus 15 vendedores, por mes en el periodo de un año.
// Realizar un programa que permita cargar la matriz y devuelva como resultado el vendedor con mayor venta, el promedio de ventas y el mes qye mas ha vendido.
var
    Empresa : matriz [15,12] numerico
    Empleados : vector [15] cadena
    Meses : vector [12] cadena
    MayorVenta,PromedioVentas,MesVenta:numerico
    num1,num2,num3 : numerico
    contador,contador1,contador2,contador3:numerico
    aux:numerico
inicio
    //cls()
    // Datos quemados
    Empleados[1]="Juan"
    Empleados[2]="Pedro"
    Empleados[3]="Maria"
    Empleados[4]="Esteban"
    Empleados[5]="Pablo"
    Empleados[6]="Jorge"
    Empleados[7]="Sebastian"
    Empleados[8]="Anibal"
    Empleados[9]="Ricardo"
    Empleados[10]="Alejandra"
    Empleados[11]="Sandra"
    Empleados[12]="Cristian"
    Empleados[13]="Angela"
    Empleados[14]="Daniela"
    Empleados[15]="Carolina"

    Meses[1]="Enero"
    Meses[2]="Febrero"
    Meses[3]="Marzo"
    Meses[4]="Abril"
    Meses[5]="Mayo"
    Meses[6]="Junio"
    Meses[7]="Julio"
    Meses[8]="Agosto"
    Meses[9]="Septiembre"
    Meses[10]="Octubre"
    Meses[11]="Noviembre"
    Meses[12]="Diciembre"

    // Datos de la matriz aleatorios
    contador=1
    mientras(contador<=15){
        contador1=1
        mientras(contador1<=12){
            Empresa[contador,contador1]=random(100)
            contador1=contador1+1
        }
        contador=contador+1
    }

    // Imprimir matriz con nombre de empleado y meses de ventas
    imprimir("\nMatriz de ventas:\n")
    contador=1
    mientras(contador<=15){
        contador1=1
        mientras(contador1<=12){
            imprimir(Empresa[contador,contador1]," ")
            contador1=contador1+1
        }
        imprimir("\t",Empleados[contador])
        imprimir("\n")
        contador=contador+1
    }

    // menu repetir hasta que el usuario ingrese una opcion valida
    desde num3=1 hasta 10{
        // Mostrar menu
        imprimir("\n\nMenu:\n")
        imprimir("1. Mayor venta\n")
        imprimir("2. Promedio de ventas\n")
        imprimir("3. Mes con mayor venta\n")
        imprimir("4. Salir\n")
        imprimir("\nIngrese una opcion: ")
        leer(num1)

        // Validar opcion
        si(num1<1 || num1>4){
            imprimir("\nOpcion invalida")
        }
        si(num1==1){
            // Buscar mayor venta
            MayorVenta=Empresa[1,1]
            contador=1
            mientras(contador<=15){
                contador1=1
                mientras(contador1<=12){
                    si(Empresa[contador,contador1]>MayorVenta){
                        MayorVenta=Empresa[contador,contador1]
                        contador2=contador
                        contador3=contador1
                    }
                    contador1=contador1+1
                }
                contador=contador+1
            }

            // Imprimir resultado
            imprimir("\nEl empleado con mayor venta fue: ",Empleados[contador2])
            imprimir("\nEl mes con mayor venta fue: ",Meses[contador3])
            imprimir("\nLa venta fue: ",MayorVenta)
        }
        si(num1==2){
            // Calcular promedio de ventas
            PromedioVentas=0
            contador=1
            mientras(contador<=15){
                contador1=1
                mientras(contador1<=12){
                    PromedioVentas=PromedioVentas+Empresa[contador,contador1]
                    contador1=contador1+1
                }
                contador=contador+1
            }
            PromedioVentas=PromedioVentas/15

            // Imprimir resultado
            imprimir("\nEl promedio de ventas fue: ",PromedioVentas)
        }
        si(num1==3){
            // Buscar mes con mayor venta
            MayorVenta=Empresa[1,1]
            contador=1
            mientras(contador<=15){
                contador1=1
                mientras(contador1<=12){
                    si(Empresa[contador,contador1]>MayorVenta){
                        MayorVenta=Empresa[contador,contador1]
                        contador2=contador
                        contador3=contador1
                    }
                    contador1=contador1+1
                }
                contador=contador+1
            }

            // Imprimir resultado
            imprimir("\nEl mes con mayor venta fue: ",Meses[contador3])
            imprimir("\nLa venta fue: ",MayorVenta)
        }
        si(num1==4){
            // Salir
            imprimir("\nSaliendo...")
        }
    }
fin
