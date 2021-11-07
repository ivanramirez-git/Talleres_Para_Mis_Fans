// este es el ejemplo más simple de esta ayuda, 
// toma dos numeros, los suma y muestra el resultado

Proceso Suma

    Definir A,B,C como Reales;

    // para cargar un dato, se le muestra un mensaje al usuario
    // con la instrucción Escribir, y luego se lee el dato en 
    // una variable (A para el primero, B para el segundo) con 
    // la instrucción Leer

    Escribir "Ingrese el primer numero:";
    Leer A;

    Escribir "Ingrese el segundo numero:";
    Leer B;


    // ahora se calcula la suma y se guarda el resultado en la
    // variable C mediante la asignación (<-)
    
    C <- A+B;


    // finalmente, se muestra el resultado, precedido de un 
    // mensaje para avisar al usuario, todo en una sola
    // instrucción Escribir
    
    Escribir "El resultado es: ",C;

FinProceso

// Busca los dos mayores de una lista de N datos

Proceso Mayores

    Definir datos,n,may1,may2,i Como Numeros;
    // primero se declara un arreglo de 200 elementos
    Dimension datos[200];
    
    // luego se pide al usuario ingresar la cantidad de datos, 
    // que no debera ser mayor a 200
    Escribir "Ingrese la cantidad de datos (de 2 a 200):";
    Leer n;
    
    // se leen uno por uno los 200 datos y se los guarda en el arreglo
    Para i<-0 Hasta n-1 Hacer
        Escribir "Ingrese el dato ",i+1,":";
        Leer datos[i];
    FinPara

    // se comparan los dos primeros y se toman como may1 (el mayor de los
    // dos) y may2 (el segundo mayor).
    Si datos[0]>datos[1] Entonces
        may1<-datos[0];
        may2<-datos[1];
    Sino
        may1<-datos[1];
        may2<-datos[0];
    FinSi
    // se recorren los demas elementos buscan si hay alguno mayor que may1 o may2
    Para i<-2 Hasta n-1 Hacer
        Si datos[i]>may1 Entonces // si hay un valor mayor que may1
            may2<-may1; // como may1 era el más grande, pasa a estar en segundo lugar
            may1<-datos[i]; // y el nuevo dato toma el primer puesto (mayor de todos)
        Sino // si no era mas grande que may1, todavia puede ser mas grande que may2
            Si datos[i]>may2 Entonces // si supera al segundo mayor que teniamos
                may2<-datos[i]; // se lo guarda como segundo mayor
            FinSi
        FinSi
    FinPara
    
    // se muestran los resultados
    Escribir "El mayor es: ",may1;
    Escribir "El segundo mayor es: ",may2;
    
FinProceso

// Este ejemplo muestra algunas de las variaciones posibles cuando se utiliza
// syntaxis flexible, instrucciones adicionales, y expresiones en lenguaje
// coloquial para las condiciones.

Proceso sin_titulo
    
    Definir a, b Como Entero
    
    Imprimir "Ingrese 3 numeros (los dos primeros deben ser enteros):"
    Leer a b c
    
    Si a Es Mayor Que b Y a Es Mayor Que c Entonces
        Escribir a " es el mayor"
    sino 
        Si b Es Mayor Que c Entonces
            Escribir b " es el mayor"
        Sino
            Escribir c " es el mayor"
        FinSi
    FinSi

    
    Mostrar "Pulse una tecla para continuar"
    Esperar Tecla
    Limpiar Pantalla
    
    Si a Es Par
        Escribir a " es par"
    Sino
        Escribir a " es impar"
    FinSi
    
    Escribir Sin Bajar "Los divisores de " b " son: "
    Para i Desde 1 Hasta b-1
        Si b Es Multiplo De i
            Escribir sin bajar i " "
        Fin Si
    Fin Para
    Escribir b
    
    Si c Es Entero 
        Mostrar C " es entero"
    Sino
        Mostrar C " es real"
    FinSi
    
FinProceso

// Estructuras de datos en Cadenas
Proceso Estructuras

	Empresa <- ""

	Escribir "Bienvenido al programa de empresas"
	Escribir "Ingrese el nombre de la empresa: "
	Leer nombreEmpresa

	Escribir "Ingrese el numero de sedes: "
	Leer sedesNumero

    Dimension nombresSedes[sedesNumero]

	Empresa <- "{°nombre°:°" + nombreEmpresa + "°,°sedes°:["

    Para i Desde 1 Hasta sedesNumero Hacer
        Escribir "Ingrese el nombre de la sede ",i,": "
        Leer nombresSedes[i]
        Empresa <- Empresa + "{°nombre°:°" + nombresSedes[i] + "°}"
        Si i<sedesNumero Entonces
            Empresa <- Empresa + ","
        FinSi
    FinPara

    Empresa <- Empresa + "]}"

    Escribir Empresa

    Mostrar "Pulse una tecla para continuar"

    Esperar Tecla
    Limpiar Pantalla

    Escribir "Ingrese el nombre de la sede a buscar: "
    Leer nombreSede

    Para i Desde 1 Hasta sedesNumero Hacer
        Si nombresSedes[i] Es Igual A nombreSede Entonces
            Escribir "La sede ",nombreSede," esta en la posicion ",i
        FinSi
    FinPara

    Mostrar "Pulse una tecla para continuar"

    Esperar Tecla
    Limpiar Pantalla
FinProceso    

// funcion que no recibe ni devuelve nada
SubProceso Saludar
    Escribir "Hola mundo!";
FinSubProceso

// funcion que recibe un argumento por valor, y devuelve su doble
SubProceso res <- CalcularDoble(num) 
    Definir res como real;
    res <- num*2; // retorna el doble
FinSubProceso

// funcion que recibe un argumento por referencia, y lo modifica
SubProceso Triplicar(num por referencia) 
    num <- num*3; // modifica la variable duplicando su valor
FinSubProceso

// proceso principal, que invoca a las funciones antes declaradas
Proceso PruebaFunciones
    
    Definir x Como Real;
    
    Escribir "Llamada a la funcion Saludar:";
    Saludar; // como no recibe argumentos pueden omitirse los paréntesis vacios
    
    Escribir "Ingrese un valor numérico para x:";
    Leer x;
    
    Escribir "Llamada a la función CalcularDoble (pasaje por valor)";
    Escribir "El doble de ",x," es ", CalcularDoble(x);
    Escribir "El valor original de x es ",x;
    
    Escribir "Llamada a la función Triplicar (pasaje por referencia)";
    Triplicar(x);
    Escribir "El nuevo valor de x es ", x;
    
FinProceso

// Juego simple que pide al usuario que adivine un numero en 10 intentos

Proceso Adivina_Numero

    Definir intentos,num_secreto,num_ingresado Como Entero;
    intentos<-10;
    num_secreto <- azar(100)+1;
    
    Escribir "Adivine el numero (de 1 a 100):";
    Leer num_ingresado;
    Mientras num_secreto<>num_ingresado & intentos>1 Hacer
        Si num_secreto>num_ingresado Entonces
            Escribir "Muy bajo";
        Sino 
            Escribir "Muy alto";
        FinSi
        intentos <- intentos-1;
        Escribir "Le quedan ",intentos," intentos:";
        Leer num_ingresado;
    FinMientras
    
    Si num_secreto=num_ingresado Entonces
        Escribir "Exacto! Usted adivino en ",11-intentos," intentos.";
    Sino
        Escribir "El numero era: ",num_secreto;
    FinSi
    
FinProceso

// Calcula el promedio de una lista de N datos

Proceso Promedio

    Definir i,N como Entero;
    Definir acum,dato,prom como Reales;
    Escribir "Ingrese la cantidad de datos:";
    Leer n;
    
    acum<-0;
    
    Para i<-1 Hasta n Hacer
        Escribir "Ingrese el dato ",i,":";
        Leer dato;
        acum<-acum+dato;
    FinPara
    
    prom<-acum/n;
    
    Escribir "El promedio es: ",prom;
    
FinProceso

//    Lee los tres lados de un triangulo rectangulo, determina 
// si corresponden (por Pitargoras) y en caso afirmativo 
// calcula el area

Proceso TrianguloRectangulo
    

    // cargar datos
    Definir l1,l2,l3 Como Real;
    Escribir "Ingrese el lado 1:";
    Leer l1;
    Escribir "Ingrese el lado 2:";
    Leer l2;
    Escribir "Ingrese el lado 3:";
    Leer l3;
    
    // encontrar la hipotenusa (mayor lado)
    Definir cat1,cat2,hip Como Real;
    Si l1>l2 Entonces
        cat1<-l2;
        Si l1>l3 Entonces
            hip<-l1;
            cat2<-l3;
        Sino
            hip<-l3;
            cat2<-l1;
        FinSi
    Sino
        cat1<-l1;
        Si l2>l3 Entonces
            hip<-l2;
            cat2<-l3;
        Sino
            hip<-l3;
            cat2<-l2;
        FinSi
    FinSi
    
    // ver si cumple con Pitagoras
    Si hip^2 = cat1^2 + cat2^2 Entonces
        // calcualar area
        Definir area como real;
        area<-(cat1*cat2)/2;
        Escribir "El area es: ",area;
    Sino
        Escribir "No es un triangulo rectangulo.";
    FinSi
    
FinProceso

//   Se ingresa una lista de nombres (la lista termina
// cuando se ingresa un nombre en blanco) no permitiendo
// ingresar repetidos y luego se ordena y muestra

Proceso OrdenaLista
    
    Definir nombre,lista,aux Como Cadenas;
    Definir se_repite Como Logico;
    Definir cant,i,j,pos_menor Como Enteros;
    Dimension lista[200];
    
    Escribir "Ingrese los nombres (enter en blanco para terminar):";
    
    // leer la lista
    cant<-0;
    Leer nombre;
    Mientras nombre<>"" Hacer
        lista[cant]<-nombre;
        cant<-cant+1;
        Repetir // leer un nombre y ver que no este ya en la lista
            Leer nombre;
            se_repite<-Falso;
            Para i<-0 Hasta cant-1 Hacer
                Si nombre=lista[i] Entonces
                    se_repite<-Verdadero;
                FinSi
            FinPara
        Hasta Que ~ se_repite
    FinMientras
    
    // ordenar
    Para i<-0 Hasta cant-2 Hacer
        // busca el menor entre i y cant
        pos_menor<-i;
        Para j<-i+1 Hasta cant-1 Hacer
            Si lista[j]<lista[pos_menor] Entonces
                pos_menor<-j;
            FinSi
        FinPara
        // intercambia el que estaba en i con el menor que encontro
        aux<-lista[i];
        lista[i]<-lista[pos_menor];
        lista[pos_menor]<-aux;
    FinPara    
    
    // mostrar como queda la lista
    Escribir "La lista ordenada es:";
    Para i<-0 Hasta cant-1 Hacer
        Escribir "   ",lista[i];
    FinPara
    
FinProceso

Proceso Modulo
    Definir N,M Como Enteros;
    Escribir "Ingrese el numero: ";
    Leer N;
    Escribir "Ingrese el divisor: ";
    Leer M;
    Si N % M = 0 Entonces
        Escribir M," es divisor exacto de ",N,".";
    Sino
        Escribir "El resto de dividir ",N," por ",M," es: ",N % M;
    FinSi
FinProceso

// Muestra como hacer un menú simple con las estructuras Repetir-Hasta Que y Según

Proceso sin_titulo
    Definir OP Como Entero;
    Repetir
        // mostrar menu
        Limpiar Pantalla;
        Escribir "Menú de recomendaciones";
        Escribir "   1. Literatura";
        Escribir "   2. Cine";
        Escribir "   3. Música";
        Escribir "   4. Videojuegos";
        Escribir "   5. Salir";
        // ingresar una opcion
        Escribir "Elija una opción (1-5): ";
        Leer OP;
        // procesar esa opción
        Segun OP Hacer
            1:
                Escribir "Lecturas recomendables:";
                Escribir " + Esperándolo a Tito y otros cuentos de fúbol (Eduardo Sacheri)";
                Escribir " + El juego de Ender (Orson Scott Card)";
                Escribir " + El sueño de los héroes (Adolfo Bioy Casares)";
            2:
                Escribir "Películas recomendables:";
                Escribir " + Matrix (1999)";
                Escribir " + El último samuray (2003)";
                Escribir " + Cars (2006)";
            3:
                Escribir "Discos recomendables:";
                Escribir " + Despedazado por mil partes (La Renga, 1996)";
                Escribir " + Búfalo (La Mississippi, 2008)";
                Escribir " + Gaia (Mägo de Oz, 2003)";
            4:
                Escribir "Videojuegos clásicos recomendables";
                Escribir " + Día del tentáculo (LucasArts, 1993)";
                Escribir " + Terminal Velocity (Terminal Reality/3D Realms, 1995)";
                Escribir " + Death Rally (Remedy/Apogee, 1996)";
            5:
                Escribir "Gracias, vuelva prontos";
            De otro modo:
                Escribir "Opción no válida";
        FinSegun
        Escribir "Presione enter para continuar";
        Esperar Tecla;
    Hasta Que OP=5
FinProceso

// Separa un numero entero en sus digitos

Proceso Digitos
    
    Definir i,digito,pot,n,aux,cont Como Enteros;
    Escribir "Ingrese un numero entero postivo:";
    Leer n;
    
    // primero, contar cuantos digitos
    cont <- 0; 
    aux <- n;
    Mientras aux>0 hacer // mientras no sea cero
        cont <- cont + 1; // contar cuantos digitos
        aux <- trunc(aux/10); // dividir por 10 y despreciar los de
    FinMientras
    Escribir "El numero tiene ",cont," digitos";
    
    // luego, mostrarlos uno por uno 
    aux<-n;
    Para i<-1 hasta cont Hacer
        pot <- 10^(cont-i); // por cuanto hay que dividir para obtener el primer digito
        digito <- trunc (aux / pot); // obtener el digito
        aux <- aux - digito*pot; // quitar ese digito al numero
        Escribir "El digito ",i," es ",digito;
    FinPara
    
FinProceso

// calcula las raices de una ecuacion de segundo grado

Proceso Resolvente
    
    Definir a,b,c,disc,preal,pimag,r1,r2 Como Reales;
    // cargar datos
    Escribir "Ingrese el coeficiente A:";
    Leer a;
    Escribir "Ingrese el coeficiente B:";
    Leer b;
    Escribir "Ingrese el coeficiente C:";
    Leer c;
    
    // determinar si son reales o imaginarias
    disc <- b^2-4*a*c;
    Si disc<0 Entonces
        // si son imaginarias
        preal<- (-b)/(2*a);
        pimag<- rc(-disc)/(2*a);
        Escribir "Raiz 1: ",preal,"+",pimag,"i";
        Escribir "Raiz 2: ",preal,"-",pimag,"i";
    Sino
        Si disc=0 Entonces // ver si son iguales o distintas
            r <- (-b)/(2*a);
            Escribir "Raiz 1 = Raiz 2: ",r;
        Sino
            r1 <- ((-b)+rc(disc))/(2*a);
            r2 <- ((-b)-rc(disc))/(2*a);
            Escribir "Raiz 1: ",r1;
            Escribir "Raiz 2: ",r2;
        FinSi
    FinSi
    
FinProceso

// Encuentra los primeros N numeros primos

Proceso Primos
    
    Definir cant_a_mostrar,n,cant_mostrados,i Como Entero;
    Definir es_primo Como Logico;
    Escribir "Ingrese la cantidad de numeros primos a mostrar:";
    Leer cant_a_mostrar;
    
    Escribir "1: 2"; // el primer primo es 2, los otros son todos impares...
    cant_mostrados <- 1;
    n<-3;            // ...a partir de 3
    
    Mientras cant_mostrados<cant_a_mostrar Hacer
        
        es_primo <- Verdadero; // pienso que es primo hasta que encuentre con que dividirlo
        
        Para i<-3 hasta rc(n) con paso 2 Hacer // ya sabemos que es impar
            Si n % i = 0 entonces // si la division da exacta...
                es_primo <- Falso;  // ...ya no es primo
            FinSi
        FinPara
        
        Si es_primo Entonces
            cant_mostrados <- cant_mostrados + 1;
            Escribir cant_mostrados, ": ",n;
        FinSi
        
        n <- n + 2 ;
        
    FinMientras
    
FinProceso

Proceso Factorizacion
    
    Definir num,div como Enteros;
    Definir factorizar,factor_primo como Logicos;
    Escribir "Ingrese el numero: ";
    Leer num;
    
    Escribir "Factorizacion: ";
    
    factorizar<-verdadero;
    
    Mientras factorizar & num>1 hacer
        div<-0;
        Si num/2 = trunc(num/2) Entonces
            Escribir 2;
            num<-num/2;
        Sino
            div<-1; factor_primo<-Verdadero;
            Mientras div<=rc(num) & factor_primo Hacer
                div <- div+2;
                Si num/div = trunc(num/div) Entonces
                    factor_primo <- Falso;
                FinSi
            FinMientras
            Si factor_primo Entonces
                escribir num;
                factorizar<-falso;
            sino
                escribir div;
                num<-num/div;
                factor_primo<-verdadero;
            FinSi
        FinSi
    FinMientras
    
FinProceso

// Este ejemplo muestra como utilizar las funciones para manejo 
// de cadenas de caracteres. Requiere que el perfil de lenguaje
// habilite estas funciones. Si al intentar ejecutar obtiene
// errores en las funciones, revise su configuración en el
// item "Opciones del lenguaje" del menú "Configurar".
Proceso sin_titulo
    
    Definir frase,vocales Como Caracter;
    Definir i,j,cantVocales Como Entero;
    
    // el usuario ingresa una frase, vamos a contar cuantas vocales tiene
    Escribir "Ingrese una frase";
    Leer frase;
    // pasamos toda la frase a minusculas para no tener que preguntar 2 veces por cada vocal
    frase<-Minusculas(frase);
    
    // lista de letras que vamos a buscar
    Vocales<-"aeiouáéíóúü";
    cantvocales<-0;
    
    // comparar todas las letras de frase con las de vocales y contar coincidencias
    Para i<-0 hasta Longitud(frase)-1 Hacer
        Para j<-0 hasta Longitud(vocales)-1 Hacer
            Si Subcadena(frase,i,i)=Subcadena(vocales,j,j) Entonces
                cantVocales<-cantVocales+1;
            FinSi
        FinPara
    FinPara
    
    Escribir "La frase contiene ",cantVocales," vocales.";
    
    
FinProceso

// Para poder ejecutar correctamente este ejemplo debe tener
// habilitada la sintaxis flexible en su perfil de lenguaje

Proceso sin_titulo    


    Definir A,i,elemento Como Enteros;
    // declara un arreglo de 10 elementos
    Dimension A[10];
    
    // recorre los 10 elementos y va asignandoles enteros aleatorios
    para cada elemento de A Hacer
        // elemento toma el contenido de cada posicion del arreglo
        // y si se modifica elemento se modifica el arreglo
        elemento <- azar(100);
    FinPara
    
    Escribir "Los elementos del arreglo son:";
    // recorre los 10 elementos utilizando subindices y los muestra en pantalla
    para i desde 0 hasta 9 Hacer
        escribir "Posición " i ": " A[i];
    FinPara
    
    Escribir ""; // deja una linea en blanco
    
    Escribir "En orden inverso:";
    // recorre los 10 elementos en orden inverso y los muestra en una misma linea
    para i desde 9 hasta 0 Hacer
        escribir sin bajar A[i] " ";
    FinPara
    
FinProceso

// Implementación del cálculo de una potencia mediante una función recursiva
// El paso recursivo se basa en que A^B = B*(A^(B-1))
// El paso base se base en que A^0 = 1

SubProceso  resultado <- Potencia (base, exponente)
    Definir resultado como Entero;
    Si exponente=0 Entonces
        resultado <- 1;
    sino 
        resultado <- base*Potencia(base,exponente-1); 
    FinSi
FinSubProceso

Proceso DosALaDiezRecursivo
    Definir exponente como Entero;
    Definir base como Entero;
    Escribir "Ingrese Base";
    Leer base;
    Escribir "Ingrese Exponente";
    Leer exponente;
    Escribir "El resultado es ",Potencia(base,exponente);
FinProceso

// Calcula el promedio de una lista de N datos utilizando un SubProceso

SubProceso prom <- Promedio ( arreglo, cantidad )
    Definir i como Entero;
    Definir suma como Real;
    Definir prom como Real;
    suma <- 0;
    Para i<-0 Hasta cantidad-1 Hacer
        suma <- suma + arreglo[i];
    FinPara
    prom <- suma/cantidad;
FinSubProceso

Proceso Principal

    Definir i,N como Entero;
    Definir acum,datos,prom como Reales;
    Dimension datos[100];
    Escribir "Ingrese la cantidad de datos:";
    Leer n;
    
    Para i<-0 Hasta n-1 Hacer
        Escribir "Ingrese el dato ",i+1,":";
        Leer datos[i];
    FinPara
    
    Escribir "El promedio es: ",Promedio(datos,n);
    
FinProceso

Proceso Misil

    Escribir "Presione una tecla para iniciar el lanzamiento!";
    Esperar Tecla;
    
    Definir cohete como Texto;
    Definir i,j,estado como Enteros;
    
    // el arreglo cohete tiene el dibujo del cohete como lineas de texto
    dimension cohete[9];
    cohete[0]<-"   /|\   ";
    cohete[1]<-"   |B|   ";
    cohete[2]<-"   |O|   ";
    cohete[3]<-"   |M|   ";
    cohete[4]<-"   |B|   ";
    cohete[5]<-"  //|\\  ";
    cohete[6]<-" ******* ";
    cohete[7]<-"* * * * *";
    cohete[8]<-" * * * * ";
    
    // primero se muestra la primer parte del dibujo y la cuenta regresiva
    Para i<-1 hasta 11 Hacer
        Borrar Pantalla;
        Para j<-1 hasta 15 Hacer
            Escribir "";
        FinPara
        Para j<-0 hasta 5 Hacer
            Escribir cohete[j];
        FinPara
        Escribir "";
        Escribir "Lanzamiento en ",11-i;
        Esperar 1 Segundo;
    FinPara
    
    // despues se muestra el dibujo completo y cada vez mas arriba
    Para i<-1 hasta 15 Hacer
        Borrar Pantalla;
        Para j<-i hasta 15 Hacer
            Escribir "";
        FinPara
        Para j<-0 hasta 7 Hacer
            Escribir cohete[j];
        FinPara
        si i>1 Entonces
            Escribir " * * * * ";
        finsi
        Esperar 1/i Segundo;
    FinPara
    
    // finalmente se va modificando el dibujo para hacer la explosion
    // estado tiene un entero que dice en que parte de la explosion va cada linea del dibujo
    Dimension estado[6];
    estado[0]<-3; estado[1]<-2; estado[2]<-1;
    estado[3]<-2; estado[4]<-3; estado[5]<-4;
    Para i<-1 hasta 10 Hacer
        Borrar Pantalla;
        Para j<-0 hasta 5 Hacer
            Estado[j]<-Estado[j]-1;
            segun Estado[j] Hacer
                0:  cohete[j]<-"    +    ";
                -1,-5: cohete[j]<-"   +X+   ";
                -2,-4: cohete[j]<-"  +XXX+  ";
                -3: cohete[j]<-" +XXXXX+ ";
                -6: cohete[j]<-"         ";
            FinSegun
            Escribir cohete[j];
        FinPara
        
        Esperar .2 Segundos;
    FinPara
    
FinProceso

Proceso Romanos
    
    // leer el número
    Definir Numero como Numerico;
    Escribir "Ingrese un número entre 1 y 1000";
    Leer Numero;
    
    // controlar que sea válido para convertir
    Definir SePuedeConvertir Como Logico;
    SePuedeConvertir<-Verdadero;
    Si Numero=0 Entonces
        Escribir "No existe ningún símbolo para representar el 0";
        SePuedeConvertir<-Falso;
    FinSi
    Si Numero<>trunc(numero) Entonces
        Escribir "El número debe ser entero";
        SePuedeConvertir<-Falso;
    FinSi
    Si Numero>1000 Entonces
        Escribir "Muy alto";
        SePuedeConvertir<-Falso;
    FinSi
    Si Numero<0 Entonces
        Escribir "Debe ser positivo";
        SePuedeConvertir<-Falso;
    FinSi
    
    // realizar la conversión
    Si SePuedeConvertir Entonces        
        Si Numero=1000 Entonces
            Escribir "M";
        Sino
            Dimension nu[10], nd[10], nc[10]; // notación para unidades, decenas y centenas
            Definir nu,nd,nc Como Caracter;
            nu[0]<-''; nu[1]<-'I'; nu[2]<-'II'; nu[3]<-'III'; nu[4]<-'IV'; nu[5]<-'V'; nu[6]<-'VI'; nu[7]<-'VII'; nu[8]<-'VIII'; nu[9]<-'IX';
            nd[0]<-''; nd[1]<-'X'; nd[2]<-'XX'; nd[3]<-'XXX'; nd[4]<-'XL'; nd[5]<-'L'; nd[6]<-'LX'; nd[7]<-'LXX'; nd[8]<-'LXXX'; nd[9]<-'XC';
            nc[0]<-''; nc[1]<-'C'; nc[2]<-'CC'; nc[3]<-'CCC'; nc[4]<-'CD'; nc[5]<-'D'; nc[6]<-'DC'; nc[7]<-'DCC'; nc[8]<-'DCCC'; nc[9]<-'CM';
            Definir centenas,decenas,unidades como numeros;
            centenas<-trunc(Numero/100) % 10;
            decenas<-trunc(Numero/10) % 10;
            unidades<-Numero % 10;
            Escribir nc[centenas],nd[decenas],nu[unidades];
        FinSi
    FinSi
    
FinProceso

//    El objetivo del juego es mover los discos de la torre 1 a la 3 en la
// menor cantidad de movimientos posible. No se puede colocar un disco de 
// un tamanio sobre otro mas chico

//     Hay una matriz que representa las torres, cada columna contiene
//  nros que representan los tamanios de los discos en esas torres (solo
//  interesan los valores hasta la cantidad de discos de esa torre).
//  Cuantos discos tiene cada torre lo dice el vector cant_discos. 

Proceso Hanoi
    
    Definir torres,cant_discos,discos,i Como Enteros;
    Dimension torres[3,10], cant_discos[3];
    
    // pedir y validar cuantos discos colocar en la primer torre
    Escribir "Ingrese el nro de discos (1-8):";
    leer discos;
    mientras discos<1 | discos>8 Hacer
        Escribir "El numero de discos debe ser mayor a 0 y menor a 5:";
        leer discos;
    finmientras

    // inicializar los datos
    cant_discos[0]<-discos;
    cant_discos[1]<-0;
    cant_discos[2]<-0;
    Para i<-0 Hasta discos-1 hacer
        torres[0,i]<-discos-i+1;
    FinPara
    
    
    // jugar!
    Definir j,t0,t1,t2,disco_a_mover,cant_movs Como Enteros;
    Definir puede_mover Como Logico;
    cant_movs<-0;
    Mientras cant_discos[2]<>discos Hacer // mientras no esten todos los discos en la tercer torre, el juego sigue
        
        Limpiar Pantalla;
        
        Para i<-0 Hasta 2 Hacer // dibujar las tres torres
            escribir "Torre ",i+1;
            si cant_discos[i]=0 Entonces
                Escribir "";
            sino
                para j<-cant_discos[i]-1 hasta 0 con paso -1 Hacer // recorrer los discos de la torre, de arriba hacia abajo
                    segun torres[i,j] Hacer // dibujar cada disco
                        1: Escribir "                   XX";
                        2: Escribir "                 XXXXXX";
                        3: Escribir "               XXXXXXXXXX";
                        4: Escribir "             XXXXXXXXXXXXXX";
                        5: Escribir "           XXXXXXXXXXXXXXXXXX";
                        6: Escribir "         XXXXXXXXXXXXXXXXXXXXXX";
                        7: Escribir "       XXXXXXXXXXXXXXXXXXXXXXXXXX";
                        8: Escribir "     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
                    finsegun
                FinPara
            finsi
            Escribir "   ----------------------------------";
            Escribir "";
        FinPara
        
        // solicitar movimiento
        Escribir "Mover desde la torre: ";
        leer t1;
        Escribir "hacia la torre: ";
        leer t2;
        
        si t1<1 | t1>3 | t2<1 | t2>3 Entonces // controlar que el nro de torre sea valido
            Escribir "Movimiento invalido";
            Esperar Tecla;
        sino
            Si cant_discos[t1-1]=0 Entonces // controlar que la torre 1 tengo al menos un disco
                Escribir "Movimiento invalido";
                Esperar Tecla;
            Sino
                disco_a_mover <- torres[t1-1,cant_discos[t1-1]-1]; // obtener tamanio del disco que se quiere mover
                puede_mover<-verdadero;
                Si cant_discos[t2-1]<>0 entonces // controlar que la torre dos no tenga discos o tenga solo discos mas grandes
                    Si torres[t2-1,cant_discos[t2-1]-1]<disco_a_mover Entonces
                        puede_mover<-Falso;
                    FinSi
                FinSi
                Si puede_mover Entonces // si paso todos los controles, mover
                    cant_movs <- cant_movs+1;
                    cant_discos[t2-1]<-cant_discos[t2-1]+1;
                    torres[t2-1,cant_discos[t2-1]-1] <- disco_a_mover;
                    cant_discos[t1-1]<-cant_discos[t1-1]-1;
                Sino
                    Escribir "Movimiento invalido";
                    Esperar Tecla;
                FinSi
            FinSi
        FinSi
    
    FinMientras
    
    // mostrar resultado
    Limpiar Pantalla;
    Escribir "Juego finalizado en ",cant_movs," movimientos!";
    
FinProceso

Proceso TaTeTi
    
    // incializa dos matrices de 3x3, una para guardar la ficha que se ve, 
    // y otra para un valor asociado a la ficha, para un jugador sera 1, para
    // el otro 2, entoces para ver quien gano se multiplica por fila, por 
    // columna y por diagonal, si el resultado es 1 gano el primer jugador,
    // si es 8 gano el segundo, si es 0 es porque faltaba completar, si
    // es otra cosa, estan las tres fichas, pero no son del mismo jugador
    Dimension Tab1[3,3]
    Dimension Tab2[3,3]
    Para i<-1 Hasta 3 Hacer
        Para j<-1 Hasta 3 Hacer
            Tab1[i,j]<-0
            Tab2[i,j]<-" "
        FinPara
    FinPara
    TurnoJugador1<-Verdadero
    Terminado<-Falso
    Ganador<-Falso
    CantTurnos<-0
    
    Mientras ~ Terminado hacer
        
        // dibuja el tablero
        Borrar Pantalla
        Escribir " "
        Escribir "      ||     ||     "
        Escribir "   ",Tab2[1,1],"  ||  ",Tab2[1,2],"  ||  ",Tab2[1,3]
        Escribir "     1||    2||    3"
        Escribir " =====++=====++======"
        Escribir "      ||     ||     "
        Escribir "   ",Tab2[2,1],"  ||  ",Tab2[2,2],"  ||  ",Tab2[2,3]
        Escribir "     4||    5||    6"
        Escribir " =====++=====++======"
        Escribir "      ||     ||     "
        Escribir "   ",Tab2[3,1],"  ||  ",Tab2[3,2],"  ||  ",Tab2[3,3]
        Escribir "     7||    8||    9"
        Escribir " "
        
        Si ~ Ganador y CantTurnos<9 Entonces
            
            // carga auxiliares segun a qué jugador le toca
            Si TurnoJugador1 Entonces
                Ficha<-'O'; Valor<- 1; Objetivo<-1
                Escribir "Turno del jugador 1 (X)"
            Sino
                Ficha<-'X'; Valor<- 2; Objetivo<-8
                Escribir "Turno del jugador 2 (O)"
            FinSi
            
            // pide la posición para colocar la ficha y la valida
            Escribir "Ingrese la Posición (1-9):"
            
            Repetir
                Leer Pos
                Si Pos<1 o Pos>9 Entonces
                    Escribir "Posición incorrecta, ingrese nuevamente: "
                    Pos<-99;
                Sino
                    i<-trunc((Pos-1)/3)+1
                    j<-((Pos-1) MOD 3)+1
                    Si Tab1[i,j]<>0 Entonces
                        pos<-99
                        Escribir "Posición incorrecta, ingrese nuevamente: "
                    FinSi
                FinSi
            Hasta Que Pos<>99
            // guarda la ficha en la matriz tab2 y el valor en tab1
            CantTurnos<-CantTurnos+1
            Tab1[i,j]<-Valor
            Tab2[i,j]<-Ficha
            
            // verifica si ganó, buscando que el producto de las fichas en el tablero de Objetivo
            aux_d1<-1; aux_d2<-1
            Para i<-1 hasta 3 hacer
                aux_i<-1; aux_j<-1
                aux_d1<-aux_d1*Tab1[i,i]
                aux_d2<-aux_d2*Tab1[i,4-i]
                Para j<-1 hasta 3 hacer
                    aux_i<-aux_i*Tab1[i,j]
                    aux_j<-aux_j*Tab1[j,i]
                FinPara
                Si aux_i=Objetivo o aux_j=Objetivo Entonces
                    Ganador<-Verdadero
                FinSi
            FinPara
            Si aux_d1=Objetivo o aux_d2=Objetivo Entonces
                Ganador<-Verdadero
            Sino
                TurnoJugador1 <- ~ TurnoJugador1
            FinSi
            
        Sino
            
            Si Ganador Entonces
                Escribir "Ganador: "
                Si TurnoJugador1 Entonces
                    Escribir "Jugador 1!"
                Sino
                    Escribir "Jugador 2!"
                FinSi
            Sino
                Escribir "Empate!"
            FinSi
            Terminado<-Verdadero
            
        FinSi
        
    FinMientras
    
FinProceso

Proceso Empresa
    EstructuraEmpresa <- ""

    // Bienvenida
    Escribir "Bienvenido al programa de Empresa"

    textoAuxiliar<-""
    numeroAuxiliar <- 0

    N<-0
    M<-0
    P<-0

    Escribir "Ingrese el nombre de la empresa: "
    Leer textoAuxiliar
    EstructuraEmpresa<-EstructuraEmpresa+"{°nombre°:°"+textoAuxiliar+"°,°sedes°:["

    Escribir "Ingrese el numero de sedes: "
    Leer N

    i<-1
    Mientras i<=N hacer
        Escribir "Ingrese el nomnbre de la sede: "
        Leer textoAuxiliar
        EstructuraEmpresa<-EstructuraEmpresa+"{°nombre°:°"+textoAuxiliar+"°secciones°:["

        Escribir "Ingrese el numero de secciones de la sede " textoAuxiliar ": "
        Leer M

        j<-1
        Mientras j<=M Hacer
            Escribir "Ingrese el nombre de la seccion: "
            Leer textoAuxiliar
            EstructuraEmpresa<-EstructuraEmpresa+"{°nombre°:°"+textoAuxiliar+"°empleados°:["

            Escribir "Ingrese el numero de empleados de la seccion " textoAuxiliar ": "
            Leer P

            k<-1
            Mientras k<=P Hacer
                Escribir "Ingrese el nombre del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+"{°nombre°:°"+textoAuxiliar+"°sexo°:°"

                Escribir "Ingrese el sexo del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°edad°:°"

                Escribir "Ingrese la edad del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°salarioBasico°:°"

                Escribir "Ingrese el salario basico del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°deducciones°:"

                Escribir "Ingrese el valor de deducciones del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°}"

                k<-k+1
            FinMientras
            P<-0

            EstructuraEmpresa<-EstructuraEmpresa+"]}"

            j<-j+1
        FinMientras
        M<-0

        EstructuraEmpresa<-EstructuraEmpresa+"]}"

        i<-i+1
    FinMientras
    N<-0

    EstructuraEmpresa<-EstructuraEmpresa+"]}"

    Escribir "Estructura de datos: "

    Escribir EstructuraEmpresa

FinProceso

// Una empresa esta dividida en N sedes, cada sede en M secciones, y cada seccion tiene un P de empleados.
// De cada empleado se conoce nombre, sexo, edad, salario basico y deducciones.
// Guardar los datos en estructura de datos
// Elabore un algoritmo que permita calcular e imprimir:

Proceso Empresa
    EstructuraEmpresa <- ""

    // Bienvenida
    Escribir "Bienvenido al programa de Empresa"

    textoAuxiliar<-""
    numeroAuxiliar <- 0

    N<-0
    M<-0
    P<-0

    Escribir "Ingrese el nombre de la empresa: "
    Leer textoAuxiliar
    EstructuraEmpresa<-EstructuraEmpresa+"{°nombre°:°"+textoAuxiliar+"°,°sedes°:[{"

    Escribir "Ingrese el numero de sedes: "
    Leer N

    i<-1
    Mientras i<=N hacer
        Si i>1 Entonces
            EstructuraEmpresa<-EstructuraEmpresa+",{"
        FinSi
        Escribir "Ingrese el nomnbre de la sede: "
        Leer textoAuxiliar
        EstructuraEmpresa<-EstructuraEmpresa+"°nombre°:°"+textoAuxiliar+"°,°secciones°:[{"

        Escribir "Ingrese el numero de secciones de la sede " textoAuxiliar ": "
        Leer M

        j<-1
        Mientras j<=M Hacer
            Si j>1 Entonces
                EstructuraEmpresa<-EstructuraEmpresa+",{"
            FinSi
            Escribir "Ingrese el nombre de la seccion: "
            Leer textoAuxiliar
            EstructuraEmpresa<-EstructuraEmpresa+"°nombre°:°"+textoAuxiliar+"°,°empleados°:[{"

            Escribir "Ingrese el numero de empleados de la seccion " textoAuxiliar ": "
            Leer P

            k<-1
            Mientras k<=P Hacer
                Si k>1
                    EstructuraEmpresa<-EstructuraEmpresa+",{"
                FinSi
                Escribir "Ingrese el nombre del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+"°nombre°:°"+textoAuxiliar+"°,°sexo°:°"

                Escribir "Ingrese el sexo del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°,°edad°:°"

                Escribir "Ingrese la edad del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°,°salarioBasico°:°"

                Escribir "Ingrese el salario basico del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°,°deducciones°:°"

                Escribir "Ingrese el valor de deducciones del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°}"

                k<-k+1
            FinMientras
            P<-0

            EstructuraEmpresa<-EstructuraEmpresa+"]}"

            j<-j+1
        FinMientras
        M<-0

        EstructuraEmpresa<-EstructuraEmpresa+"]}"
        
        i<-i+1
    FinMientras
    N<-0

    EstructuraEmpresa<-EstructuraEmpresa+"]}"

    Escribir "Estructura de datos: "

    Escribir EstructuraEmpresa

    // Consultas
    Consultas(EstructuraEmpresa)

FinProceso

// Dado un objeto:
/*
{
  °nombre°: °Abc°,
  °sedes°: [
    {
      °nombre°: °Tame°,
      °secciones°: [
        {
          °nombre°: °CasaIvan°,
          °empleados°: [
            {
              °nombre°: °Ivan°,
              °sexo°: °M°,
              °edad°: °22°,
              °salarioBasico°: °1787365°,
              °deducciones°: °209846°
            },
            {
              °nombre°: °Mo nica°,
              °sexo°: °F°,
              °edad°: °21°,
              °salarioBasico°: °1894387°,
              °deducciones°: °340871°
            }
          ]
        },
        {
          °nombre°: °CasaAlejandra°,
          °empleados°: [
            {
              °nombre°: °Alejandra°,
              °sexo°: °F°,
              °edad°: °21°,
              °salarioBasico°: °1437333°,
              ° deducciones°: °209841°
            }
          ]
        }
      ]
    },
    {
      °nombre°: °Saravena°,
      °secciones°: [
        {
          °nombre°: °CasaClaris°,
          °empleados°: [
            {
              °nombre°: °Claris°,
              °sexo°: °F°,
              °edad°: °23°,
              °salarioBasico°: °1987654°,
              °deducciones°: °123321°
            },
            {
              °n ombre°: °Uziel°,
              °sexo°: °M°,
              °edad°: °19°,
              °salarioBasico°: °787654°,
              °deducciones°: °84000°
            }
          ]
        }
      ]
    }
  ]
}
*/
// Realizares las siguientes consultas:
// a) El promedio de edad de los empleados por cada seccion y por cada sede.
// b) El porcentaje de mujeres de 18 anos por seccion y por sede.
// c) El numero de mujeres que ganan mas de 4 salarios minimos por seccion.
// d) Un mensaje "si existe al menos un empleado hombre que gane mas de 20 salarios minimos" de toda la empresa.
// e) El nombre y la edad de la mujer mas joven por cada seccion.
// f) El nombre y la edad del hombre mas viejo por cada sede.
// g) El valor de las deducciones mas altas de toda la empresa.
// h) El promedio de salarios netos de las mujeres mayores de 18 años por sede y seccion.
// i) El porcentaje de empleados hombres que ganan menos de dos salarios minimos por cada seccion.
// j) El salario neto mas bajo de toda la empresa.

SubProceso Consultas(EstructuraEmpresa)
    // Consultas
    
    
FinSubProceso



















// Nuevo algoritmo
Proceso principal
	
    // Punto 1
    punto1_aleatorios
	
    // Punto 2
    punto2_cadenas
	
	
	
FinProceso

SubProceso punto1_aleatorios
    // Ingrese un vector de 15 posiciones de manera aleatoria
	
    dimension Vector(15)
	
    i<-1
    Mientras i<=15 Hacer
        Vector[i]<-Azar(40)
        i<-i+1
    FinMientras
    // Mostrar vector
    Escribir "Vector: "
	
    i<-1
    Mientras i<=15 Hacer
        Escribir Vector[i]
        i<-i+1
    FinMientras
	
    // Ordenar de manera ascendente
	
    i<-1
    Mientras i<=15 Hacer
        j<-i+1
        Mientras j<=15 Hacer
            Si Vector[i]>Vector[j]
                Vector[i]<-Vector[i]+Vector[j]
                Vector[j]<-Vector[i]-Vector[j]
                Vector[i]<-Vector[i]-Vector[j]
            FinSi
            j<-j+1
        FinMientras
        i<-i+1
    FinMientras
	
    // Mostrar el vector ordenado
    Escribir "Vector ordenado: "
	
    i<-1
    Mientras i<=15 Hacer
        Escribir Vector[i]
        i<-i+1
    FinMientras
	
FinSubProceso

SubProceso punto2_cadenas
    // Ingrese una cadena de texto
    Escribir "Ingrese una cadena de texto: "
    Leer texto
	Escribir "Una cadena mas grande de texto: "
    Leer texto2	
    // Cuantas veces aparece texto en texto2?    
    j<-longitud(texto)
	i<-longitud(texto2)	
	contador<-0
    k<-1	
    //Escribir "Las longitudes son j: " j " y i: " i " y k: " k
    cade2<-subcadena(texto2,k,j)
    Mientras k<i Hacer
        //Escribir "Cadena 2: " cade2
        Si cade2==texto
            contador<-contador+1
        FinSi
        k<-k+1
        j<-j+1		
        //Escribir "Las longitudes son j: " j " y i: " i " y k: " k		
        cade2<-subcadena(texto2,k,j)
    FinMientras
    // Mostrar el resultado
    Escribir "El texto aparece ",contador," veces en la cadena"
	
FinSubProceso

