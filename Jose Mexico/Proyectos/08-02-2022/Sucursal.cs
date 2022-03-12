namespace Jose_Mexico
{
    public class Sucursal
    {
        public static void iniciar(Banco b)
        {
            // Desea abrir una cuenta
            Program.imprimir("Desea agregar un nuevo cliente? (s/n): ");
            char respuesta = Program.caracter();
            if (respuesta == 's')
            {
                b.altaCliente();
            }
            else
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
                        // Program.imprimir("a. Alta nuevo cliente\n");
                        Program.imprimir("b. Retiro de efectivo\n");
                        Program.imprimir("c. Deposito de efectivo\n");
                        Program.imprimir("d. Cambio de NIP\n");
                        Program.imprimir("e. Salir\n");
                        Program.imprimir("Ingrese una opcion: ");
                        char opcion = Program.caracter();
                        /*if (opcion == 'a')
                        {
                            b.altaCliente();
                        }
                        else*/
                        if (opcion == 'b')
                        {
                            // Retiro de efectivo
                            Program.imprimir("Ingrese el monto a retirar: ");
                            double monto = Program.leerMonto();
                            b.retiroEfectivo(numeroTarjeta, nip, monto);

                        }
                        else if (opcion == 'c')
                        {
                            // Pedir el monton a depositar
                            Program.imprimir("Ingrese el monto a depositar: ");
                            double monto = Program.leerMonto();
                            b.depositoEfectivo(numeroTarjeta, monto);
                        }
                        else if (opcion == 'd')
                        {
                            // Cambiar NIP
                            Program.imprimir("Ingrese el nuevo NIP: ");
                            int nuevoNIP = Program.leerPin();
                            b.cambioPin(numeroTarjeta, nip, nuevoNIP);

                        }
                        else if (opcion == 'e')
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
}