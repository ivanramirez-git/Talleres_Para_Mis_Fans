class main {
    public static void main(String[] args) throws Exception {
        System.out.println("Ejerccio 1");
        System.out.println();
        // Escribir un programa que acepte solo numeros mas grandes en cada ciclo while.
        int numero = -1;
        int actual = 0;
        while (actual > numero) {
            numero = actual;
            System.out.print("Escriba un numero: ");
            actual = Integer.parseInt(System.console().readLine());
        }
        System.out.println(actual + " no es mayor al numero anterior");

        System.out.println();

        System.out.println("Ejerccio 2");
        System.out.println();
        // Escribir un programa que pida numeros mientras no se escriba un numero neagaivo o cero.
        // El programa dera dezplegar la suma de los numeros introducidos. Ademas informar cuantos digitos pares y cuantos impares fueron introducidos.
        int suma = 0;
        int numero2 = 1;
        int contadorPares = 0;
        int contadorImpares = 0;
        while(numero2 > 0) {
            System.out.print("Escriba un numero: ");
            numero2 = Integer.parseInt(System.console().readLine());
            if(numero2 > 0) {
                suma += numero2;
                if(numero2 % 2 == 0) {
                    contadorPares++;
                } else {
                    contadorImpares++;
                }
            }
        }
        System.out.println("La suma de los numeros introducidos es: " + suma);
        System.out.println("El numero de pares introducidos es: " + contadorPares);
        System.out.println("El numero de impares introducidos es: " + contadorImpares);

    }
}