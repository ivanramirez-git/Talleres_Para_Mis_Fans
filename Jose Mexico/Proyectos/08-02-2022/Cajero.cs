namespace Jose_Mexico
{
    public class Cajero
    {
        public static void iniciar(Banco b)
        {
            // Control de acceso
            Program.imprimir("Control de acceso\n");
            Program.imprimir("Ingrese su numero de tarjeta\n");
            int[] numeroTarjeta = Program.leerNumeroTarjeta();
            // Imprimir el numeros de tarjeta
            Program.imprimir("Su numero de tarjeta es: ");
            Program.imprimir(Program.intArrayToString(numeroTarjeta));
            Program.imprimir("\n");
            // Leer el pin
            Program.imprimir("Ingrese su NIP: ");
            int nip = Program.leerPin();

            if (b.controlAcceso(numeroTarjeta, nip))
            {
                // Menu
                Boolean salir = false;
                while (!salir)
                {
                    Program.imprimir("a. Consulta de saldo\n");
                    Program.imprimir("b. Deposito en efectivo\n");
                    Program.imprimir("c. Transferencia a otra cuenta\n");
                    Program.imprimir("d. Retiro de efectivo\n");
                    Program.imprimir("e. Cambiar NIP\n");
                    Program.imprimir("f. Salir\n");
                    Program.imprimir("Ingrese una opcion: ");
                    char opcion = Program.caracter();
                    if (opcion == 'a')
                    {
                        b.consultaSaldo(numeroTarjeta, nip);
                    }
                    else if (opcion == 'b')
                    {
                        // Pedir el monton a depositar
                        Program.imprimir("Ingrese el monto a depositar: ");
                        double monto = Program.leerMonto();
                        b.depositoEfectivo(numeroTarjeta, monto);

                    }
                    else if (opcion == 'c')
                    {
                        // transferencia(int [] numeroTarjetaOrigen, int pin, int [] numeroTarjetaDestino, double monto)
                        Program.imprimir("Ingrese el numero de tarjeta de la cuenta destino: ");
                        int[] numeroTarjetaDestino = Program.leerNumeroTarjeta();
                        Program.imprimir("Ingrese el monto a transferir: ");
                        double monto = Program.leerMonto();
                        b.transferencia(numeroTarjeta, nip, numeroTarjetaDestino, monto);

                    }
                    else if (opcion == 'd')
                    {
                        // Retiro de efectivo
                        Program.imprimir("Ingrese el monto a retirar: ");
                        double monto = Program.leerMonto();
                        b.retiroEfectivo(numeroTarjeta, nip, monto);

                    }
                    else if (opcion == 'e')
                    {
                        // Cambiar NIP
                        Program.imprimir("Ingrese el nuevo NIP: ");
                        int nuevoNIP = Program.leerPin();
                        b.cambioPin(numeroTarjeta, nip, nuevoNIP);

                    }
                    else if (opcion == 'f')
                    {
                        salir = true;
                    }
                    else
                    {
                        Program.imprimir("Opcion invalida\n");
                    }
                }
            }
        }
    }
}