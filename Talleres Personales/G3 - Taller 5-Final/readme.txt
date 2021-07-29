REQUERIMIENTOS
1. Contar con un compilador de C++ en el computador


INSTRUCCIONES PARA INICIAR EL JUEGO
1. Descomprimir la carpeta del taller .zip

2. Acceder por media de la consola de comandos a la ubicación de la carpeta descomprimida

3. Compilar el programa con el siguiente comando:
    > g++ taller.cpp -o taller

4. Ejecutar el programa con el siguiente comando:
    > taller


INSTRUCCIONES DEL JUEGO
Jugadores
    1. x -> Máquina
    2. o -> Usuario (oponente)

1. Cada vez que juega la máquina hace uso del algoritmo MIN-MAX para tomar sus decisiones
2. La máquina siempre es la primera en iniciar el juego
3. Cuando sea turno del usuario, se le pedirá que ingrese por entrada el número de la fila y columna del espacio en el que quiere poner su juego
    3.1. Tanto el valor de la fila como el de la columna deben estar entre el rango de [0-2]
    3.2. Si los datos son erróneos se le indicará al usuario para que vuelva a ingresar sus datos
    3.3. Si ya existe un carácter en la espacio se le indicará al usuario para que vuelva a ingresar sus datos
4. Extisten tres posibles finales
    4.1. Empatar
    4.2. Perder
    4.3. Ganar
5. Una vez termina la partida el programa finaliza
6. Si desea volver a jugar debe iniciar el ejecutable nuevamente con el comando
    > taller
7. Si desea salir mientras juega, ejecutar Ctrl C
