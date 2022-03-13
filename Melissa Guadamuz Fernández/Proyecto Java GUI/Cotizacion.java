package exportac;

public class Cotizacion {

    // Identificador de cotización: Debe ser un número aletorio entre 0 y 1000.
    private int id;
    // Fecha de la cotización: Valor que almacena la fecha del día en que se realizó la cotización, debe ser igual a la fecha de ejecución del programa.
    private String fecha;
    // Kilogramos a exportar: Corresponde un valor en kilogramos que puede contener decimales. El valor mínimo permitido es 1 Kilogramo.
    private double kg;
    /*
    Zona de la Exportación (9 Zonas):
        - Nueva Inglaterra (Maine, Nuevo Hampshire, Vermont, Massachusetts, Connecticut, Rhode Island).
        - Atlántico Medio (Nueva York, Pensilvania, Nueva Jersey).
        - Atlántico Sur (Maryland, Delaware, Virginia Occidental, Virginia, Carolina del Norte, Carolina del Sur, Georgia, Florida).
        - Centro Norte Oriental (Michigan, Wisconsin, Illinois, Indiana, Ohio) o Centro Sur Oriental (Kentucky, Tennessee, Alabama, Misisipi).
        - Centro Norte Occidental (Minnesota, Dakota del Norte, Dakota del Sur, Iowa, Nebraska, Misuri, Kansas).
        - Centro Sur Occidental (Arkansas, Oklahoma, Texas, Luisiana).
        - Montaña (Montana, Idaho, Wyoming, Colorado, Utah, Nevada, Arizona, Nuevo México).
        - Pacífico (Alaska, Washington, Oregón, California, Hawái).
    */
    private String zona;
    // Dirección de Entrega: Corresponde a una dirección física dentro de los EEUU para donde se entregara la carga. La misma debe al menos tener 20 Caracteres alfanuméricos, con la finalidad de ser lo más específico.
    private String direccion;

    // Constructor de la clase Cotización.
    public Cotizacion(String fecha, double kg, String zona, String direccion) {
        // Generar un número aleatorio entre 0 y 1000.
        this.id = (int) (Math.random() * 1000);
        // Fecha de la cotización: Valor que almacena la fecha del día en que se realizó la cotización, debe ser igual a la fecha de ejecución del programa.
        this.fecha = LocalDateTime.now().toString();
        this.zona = zona;
        this.direccion = direccion;
    }

    // Método que retorna el identificador de la cotización.
    public int getId() {
        return id;
    }

    // Método que retorna la fecha de la cotización.
    public String getFecha() {
        return fecha;
    }

    // Método que retorna el valor en kilogramos que se desea exportar.
    public double getKg() {
        return kg;
    }

    // Método que retorna la zona de la exportación.
    public String getZona() {
        return zona;
    }

    // Método que retorna la dirección de entrega.
    public String getDireccion() {
        return direccion;
    }

    // Método que modifica el identificador de la cotización.
    public void setId(int id) {
        this.id = id;
    }

    // Método que modifica la fecha de la cotización.
    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    // Método que modifica el valor en kilogramos que se desea exportar.
    public void setKg(double kg) {
        this.kg = kg;
    }

    // Método que modifica la zona de la exportación.
    public void setZona(String zona) {
        this.zona = zona;
    }

    // Método que modifica la dirección de entrega.
    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    // Método que retorna una cadena de caracteres con la información de la cotización.
    @Override
    public String toString() {
        return "Cotización{" + "id=" + id + ", fecha=" + fecha + ", kg=" + kg + ", zona=" + zona + ", direccion=" + direccion + '}';
    }

    // Calcula el precio de la cotización.

    /* El costo de la exportación es de $75 dólares por Kilogramo.
        Conversiones:
        Medida                      Formula de Conversión
        Kilogramos a gramos         Valor en Kg * 1.000
        Kilogramos a libras         Valor en Kg * 2.20462
        Kilogramos a toneladas      Valor en Kg / 1000.
    */
    public String calcularPrecio() {
        // Dividir el total de kilogramos en toneladas y lo que sobre en libras y lo que sobre en gramos.
        double total;
        double aux;
        double toneladas;
        double libras;
        double gramos;

        // Calculo de la cantidad de toneladas.
        total = kg;
        aux = total / 1000;
        toneladas = aux % 1000;
        // Calculo de la cantidad de libras.
        total = kg - (toneladas * 1000);
        aux = total * 2.20462;
        libras = aux % 2.20462;
        // Calculo de la cantidad de gramos.
        total = kg - (toneladas * 1000) - (libras / 2.20462);
        gramos = total % 1000;

        // Retorna una cadena de caracteres con la información de la cotización.
        return  "Cotización: " + id + "\n" + 
                "Fecha: " + fecha + "\n" + 
                "Kilogramos: " + kg + "\n" + 
                "Zona: " + zona + "\n" + 
                "Dirección: " + direccion + 
                "\n" + "Toneladas: " + toneladas + 
                "\n" + "Valor (toneladas): $" + (75 * toneladas/1000) +
                "\n" + "Libras: " + libras +
                "\n" + "Valor (libras): $" + (75 * libras*2.20462) +
                "\n" + "Gramos: " + gramos +
                "\n" + "Valor (gramos): $" + (75 * gramos*1000) + 
                "\n" + "Total: $" + (75 * kg);
    }

}