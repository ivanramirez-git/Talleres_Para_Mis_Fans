namespace Jose_Mexico
{
    public class Banco
    {
        // Atributos
        private List<Cliente> clientes; // Lista de clientes
        private string nombre; // Nombre del banco
        private string direccion; // Direccion del banco
        private string telefono; // Telefono del banco
        // Constructor
        public Banco()
        {
            this.nombre = "Jose Mexico";
            this.direccion = "Mi Casa 123";
            this.telefono = "08022022";
            this.clientes = new List<Cliente>();
        }

        // Cliente

        // Clase Cliente
        private class Cliente
        {
            // Atributos
            private string nombre;
            private string direccion;
            private string telefono;
            private List<Cuenta> cuentas; // Lista de cuentas


            // Constructor
            public Cliente(string nombre, string direccion, string telefono)
            {
                this.nombre = nombre;
                this.direccion = direccion;
                this.telefono = telefono;
                this.cuentas = new List<Cuenta>();
            }

            // Getters
            public string getNombre()
            {
                return this.nombre;
            }
            public string getDireccion()
            {
                return this.direccion;
            }
            public string getTelefono()
            {
                return this.telefono;
            }

            // Setters
            public void setNombre(string nombre)
            {
                this.nombre = nombre;
            }
            public void setDireccion(string direccion)
            {
                this.direccion = direccion;
            }
            public void setTelefono(string telefono)
            {
                this.telefono = telefono;
            }

            // ToString
            public override string ToString()
            {
                return "Nombre: " + this.nombre + "\nDireccion: " + this.direccion + "\nTelefono: " + this.telefono + "\nCuentas: \n" + cuentas.ToString();
            }

            private class Cuenta
            {
                // Tarjeta
                private int[] numeroTarjeta; // 16 digitos
                private int codigoSeguridad; // 3 digitos
                private string fechaVencimiento; // MM/AA
                private int nip; // Pin de 4 digitos
                private double saldo; // Saldo inicial de 0
                private List<double> movimientos; // Lista de movimientos

                // Constructor
                public Cuenta(int[] numeroTarjeta, int codigoSeguridad, string fechaVencimiento, int nip)
                {
                    this.numeroTarjeta = numeroTarjeta;
                    this.codigoSeguridad = codigoSeguridad;
                    this.fechaVencimiento = fechaVencimiento;
                    this.nip = nip;
                    this.saldo = 0;
                    this.movimientos = new List<double>();
                }

                public Cuenta(){
                    this.numeroTarjeta = new int[16];
                    this.codigoSeguridad = 0;
                    this.fechaVencimiento = "";
                    this.nip = 0;
                    this.saldo = 0;
                    this.movimientos = new List<double>();
                }

                // Setters
                public void setNumeroTarjeta(int[] numeroTarjeta)
                {
                    this.numeroTarjeta = numeroTarjeta;
                }

                public void setCodigoSeguridad(int codigoSeguridad)
                {
                    this.codigoSeguridad = codigoSeguridad;
                }

                public void setFechaVencimiento(string fechaVencimiento)
                {
                    this.fechaVencimiento = fechaVencimiento;
                }

                public void setNip(int nip)
                {
                    this.nip = nip;
                }

                public void setSaldo(double saldo)
                {
                    this.saldo = saldo;
                }

                // Getters

                public int[] getNumeroTarjeta()
                {
                    return this.numeroTarjeta;
                }

                public int getCodigoSeguridad()
                {
                    return this.codigoSeguridad;
                }

                public string getFechaVencimiento()
                {
                    return this.fechaVencimiento;
                }

                public int getNip()
                {
                    return this.nip;
                }

                public double getSaldo()
                {
                    return this.saldo;
                }

                public List<double> getMovimientos()
                {
                    return this.movimientos;
                }

                // toString
                public override string ToString()
                {
                    return "Numero de tarjeta: " + Program.intArrayToString(this.numeroTarjeta) + "\nCodigo de seguridad: " + this.codigoSeguridad + "\nFecha de vencimiento: " + this.fechaVencimiento + "\nNip: " + this.nip + "\nSaldo: " + this.saldo + "\nMovimientos: " + Program.doubleListToString(this.movimientos);
                }

                // Metodos
                public bool validarNumeroTarjeta(int [] t){
                    if(t[0] == this.numeroTarjeta[0] && t[1] == this.numeroTarjeta[1] && t[2] == this.numeroTarjeta[2] && t[3] == this.numeroTarjeta[3] && t[4] == this.numeroTarjeta[4] && t[5] == this.numeroTarjeta[5] && t[6] == this.numeroTarjeta[6] && t[7] == this.numeroTarjeta[7] && t[8] == this.numeroTarjeta[8] && t[9] == this.numeroTarjeta[9] && t[10] == this.numeroTarjeta[10] && t[11] == this.numeroTarjeta[11] && t[12] == this.numeroTarjeta[12] && t[13] == this.numeroTarjeta[13] && t[14] == this.numeroTarjeta[14] && t[15] == this.numeroTarjeta[15]){
                        return true;
                    }
                    return false;
                }

                public bool validarNip(int n){
                    if(n == this.nip){
                        return true;
                    }
                    return false;
                }

            }
                
            // Metodos
            public void agregarCuenta(int[] numeroTarjeta, int codigoSeguridad, string fechaVencimiento, int nip)
            {
                this.cuentas.Add(new Cuenta(numeroTarjeta, codigoSeguridad, fechaVencimiento, nip));
            }

            // Buscar numero de tarjeta
            public bool buscarCuenta(int[] numeroTarjeta)
            {
                foreach (Cuenta c in this.cuentas)
                {
                    if (c.validarNumeroTarjeta(numeroTarjeta))
                    {
                        return true;
                    }
                }
                return false;
            }

            // Validar nip
            public bool validarNip(int[] numeroTarjeta, int nip)
            {
                foreach (Cuenta c in this.cuentas)
                {
                    if (c.validarNumeroTarjeta(numeroTarjeta))
                    {
                        if (c.validarNip(nip))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }

        }

        // Metodos

        // Alta a un cliente
        public bool altaCliente()
        {
            // Pedir datos
            Program.imprimir("Alta de nuevo cliente\n");
            Program.imprimir("Ingrese un nombre: ");
            string nombre = Program.leer();
            Program.imprimir("Ingrese una direccion: ");
            string direccion = Program.leer();
            Program.imprimir("Ingrese un telefono: ");
            string telefono = Program.leer();

            // Validar datos
            if (nombre.Length == 0)
            {
                Program.imprimir("El nombre no puede estar vacio\n");
                return false;
            }

            if (direccion.Length == 0)
            {
                Program.imprimir("La direccion no puede estar vacia\n");
                return false;
            }

            if (telefono.Length == 0)
            {
                Program.imprimir("El telefono no puede estar vacio\n");
                return false;
            }

            // Crear cliente
            Cliente c = new Cliente(nombre, direccion, telefono);
            // Pedir datos
            Program.imprimir("Alta de una tarjeta para el cliente " + c.getNombre() + "\n");
            //int numeroTarjeta = Program.entero();
            int[] numeroTarjeta = GenerarNumeroTarjeta();
            // Numero de tarjeta
            Program.imprimir("Numero de tarjeta generado: " + Program.intArrayToString(numeroTarjeta) + "\n");
            int codigoSeguridad = Program.aleatorio(100, 999);
            // Codigo de seguridad
            Program.imprimir("Codigo de seguridad generado: " + codigoSeguridad.ToString() + "\n");
            Program.imprimir("Ingrese una fecha de vencimiento (MM/AA): ");
            string fechaVencimiento = Program.leerFecha();
            Program.imprimir("Ingrese un NIP: ");
            int nip = Program.leerPin();
            // Vuelta a pedir NIP
            Program.imprimir("Ingrese el NIP nuevamente: ");
            int nip2 = Program.leerPin();

            // Validar datos
            if (numeroTarjeta.Length != 16)
            {
                Program.imprimir("El numero de tarjeta debe tener 16 digitos\n");
                return false;
            }

            if (codigoSeguridad < 100 || codigoSeguridad > 999)
            {
                Program.imprimir("El codigo de seguridad debe tener 3 digitos\n");
                return false;
            }

            if (fechaVencimiento.Length != 5)
            {
                Program.imprimir("La fecha de vencimiento debe tener el formato MM/AA\n");
                return false;
            }

            if (nip < 1000 || nip > 9999)
            {
                Program.imprimir("El nip debe tener 4 digitos\n");

                return false;
            }

            // Validar los 2 NIP
            if (nip != nip2)
            {
                Program.imprimir("Los NIP no coinciden\n");
                return false;
            }

            // Crear cuenta
            c.agregarCuenta(numeroTarjeta, codigoSeguridad, fechaVencimiento, nip);

            // Agregar cliente a la lista
            this.clientes.Add(c);

            // Imprimir el cliente

            Program.imprimir("Cliente agregado satisfactoriamente\n");

            return true;
        }

        // Metodos privados de banco
        // Generar digitos de tarjeta
        private int[] GenerarNumeroTarjeta()
        {
            int[] numeroTarjeta = new int[16];

            for (int i = 0; i < 16; i++)
            {
                int num = Program.aleatorio(0, 9);
                //Program.imprimir(num.ToString());
                numeroTarjeta[i] = num;
            }
            // Validar que no se repita el mismo numero en la lista de clientes
            if (buscarCliente(numeroTarjeta) != null)
            {
                return GenerarNumeroTarjeta();
            }
            return numeroTarjeta;
        }

        // Metodos privados de clientes
        private Cliente? buscarCliente(int[] numeroTarjeta)
        {
            foreach (Cliente c in this.clientes)
            {
                if (c.buscarCuenta(numeroTarjeta))
                {
                    return c;
                }
            }
            return null;
        }

        // Transacciones publicas
        // Retiro de efectivo
        public bool retiroEfectivo(int[] numeroTarjeta, int pin, double monto)
        {
            // Buscar cliente
            Cliente? c = this.buscarCliente(numeroTarjeta);
            if (c == null)
            {
                Program.imprimir("No se encontro el cliente\n");
                return false;
            }

            // Validar nip
            if (!c.validarNip(numeroTarjeta,pin))
            {
                Program.imprimir("El nip ingresado es incorrecto\n");
                return false;
            }

            // Validar saldo
            if (c.getSaldo() < monto)
            {
                Program.imprimir("El saldo es insuficiente\n");
                return false;
            }

            // Retiro
            c.setSaldo(c.getSaldo() - monto);
            c.getMovimientos().Add(-monto);

            Program.imprimir("Retiro realizado satisfactoriamente\n");
            // Imprimir saldo
            Program.imprimir("Saldo actual: " + c.getSaldo().ToString()+"\n");
            return true;
        }

        // Deposito de efectivo
        public bool depositoEfectivo(int[] numeroTarjeta, double monto)
        {
            // Buscar cliente
            Cliente? c = this.buscarCliente(numeroTarjeta);
            if (c == null)
            {
                Program.imprimir("No se encontro el cliente\n");
                return false;
            }

            // Deposito
            c.setSaldo(c.getSaldo() + monto);
            c.getMovimientos().Add(monto);

            Program.imprimir("Deposito realizado satisfactoriamente\n");
            // Imprimir saldo
            Program.imprimir("Saldo actual: " + c.getSaldo().ToString()+"\n");
            return true;
        }

        // Cambio de pin
        public bool cambioPin(int[] numeroTarjeta, int pin, int nuevoPin)
        {
            // Buscar cliente
            Cliente? c = this.buscarCliente(numeroTarjeta);
            if (c == null)
            {
                Program.imprimir("No se encontro el cliente\n");
                return false;
            }

            // Validar pin
            if (c.getNip() != pin)
            {
                Program.imprimir("El pin ingresado es incorrecto\n");
                return false;
            }

            // Cambio de pin
            c.setNip(nuevoPin);

            Program.imprimir("Pin cambiado satisfactoriamente\n");
            return true;
        }

        // Transferencia a otra cuenta
        public bool transferencia(int[] numeroTarjetaOrigen, int pin, int[] numeroTarjetaDestino, double monto)
        {
            // Buscar cliente
            Cliente? c = this.buscarCliente(numeroTarjetaOrigen);
            if (c == null)
            {
                Program.imprimir("No se encontro el cliente\n");
                return false;
            }

            // Validar pin
            if (c.getNip() != pin)
            {
                Program.imprimir("El pin ingresado es incorrecto\n");
                return false;
            }

            // Validar saldo
            if (c.getSaldo() < monto)
            {
                Program.imprimir("El saldo es insuficiente\n");
                return false;
            }

            // Buscar cliente destino
            Cliente? cDestino = this.buscarCliente(numeroTarjetaDestino);
            if (cDestino == null)
            {
                Program.imprimir("No se encontro el cliente destino\n");
                return false;
            }

            // Transferencia
            c.setSaldo(c.getSaldo() - monto);
            c.getMovimientos().Add(-monto);
            cDestino.setSaldo(cDestino.getSaldo() + monto);
            cDestino.getMovimientos().Add(monto);

            Program.imprimir("Transferencia realizada satisfactoriamente\n");
            // Imprimir saldo
            Program.imprimir("Saldo actual: " + c.getSaldo().ToString()+"\n");
            return true;
        }

        // Consulta de saldo
        public bool consultaSaldo(int[] numeroTarjeta, int pin)
        {
            // Buscar cliente
            Cliente? c = this.buscarCliente(numeroTarjeta);
            if (c == null)
            {
                Program.imprimir("No se encontro el cliente\n");
                return false;
            }

            // Validar pin
            if (c.getNip() != pin)
            {
                Program.imprimir("El pin ingresado es incorrecto\n");
                return false;
            }

            // Mostrar saldo
            Program.imprimir("Saldo: " + c.getSaldo()+"\n");
            return true;
        }

        // Control de acceso
        public bool controlAcceso(int[] numeroTarjeta, int pin)
        {
            // Buscar cliente
            Cliente? c = this.buscarCliente(numeroTarjeta);
            if (c == null)
            {
                Program.imprimir("No se encontro el cliente\n");
                return false;
            }

            // Validar pin
            if (c.getNip() != pin)
            {
                Program.imprimir("El pin ingresado es incorrecto\n");
                return false;
            }

            Program.imprimir("Acceso permitido\n");
            return true;
        }

        // Listar Nombre, Numero de tarjeta, Saldo de todos los clientes
        public void listarClientesSaldo()
        {
            foreach (Cliente c in this.clientes)
            {
                Program.imprimir(c.ToString()+"\n");
                Program.imprimir("\n");
            }
        }

        // ToString
        public override string ToString()
        {
            return "Nombre: " + this.nombre + "\nDireccion: " + this.direccion + "\nTelefono: " + this.telefono;
        }
    }
}