class Main {
    public static void main(String[] args) {
        Cajero c = new Cajero();
        float Consulta;
        float Opcion;
        float Retiro;
        float Salir;
        // Menu
        System.out.println("Bienvenido al cajero");
        do {
            System.out.println("1)Depositar");
            System.out.println("2)Consultar saldo");
            System.out.println("3)Retirar");
            System.out.println("4)Salir");
            System.out.println("Ingresa la opción correcta");
            Opcion = Float.parseFloat(System.console().readLine());
            switch ((int) Opcion) {
                case 1:
                    System.out.println("Ingresa el monto a depositar");
                    Salir = Float.parseFloat(System.console().readLine());
                    c.Deposito(Salir);
                    break;
                case 2:
                    Consulta = c.Consulta();
                    System.out.println("Tu saldo es de: " + Consulta);
                    break;
                case 3:
                    System.out.println("Ingresa el monto a retirar");
                    Retiro = Float.parseFloat(System.console().readLine());
                    c.Retiro(Retiro);
                    break;
                case 4:
                    System.out.println("Gracias por usar el cajero");
                    break;
                default:
                    System.out.println("Ingresa una opción correcta");
                    break;
            }
        } while (Opcion != 4);
    }
}