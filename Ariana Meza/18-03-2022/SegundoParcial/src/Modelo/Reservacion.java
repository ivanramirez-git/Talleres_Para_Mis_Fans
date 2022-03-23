package Modelo;

import java.io.Serializable;

public class Reservacion implements Serializable {

    // id, id_cliente, id_salon, fecha, hora_inicio, hora_fin
    private int id;
    private int id_cliente;
    private int id_salon;
    private String fecha;
    private String hora_inicio;
    private String hora_fin;
    
    public Reservacion(int id, int id_cliente, int id_salon, String fecha, String hora_inicio, String hora_fin) {
        this.id = id;
        this.id_cliente = id_cliente;
        this.id_salon = id_salon;
        this.fecha = fecha;
        this.hora_inicio = hora_inicio;
        this.hora_fin = hora_fin;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId_cliente() {
        return id_cliente;
    }

    public void setId_cliente(int id_cliente) {
        this.id_cliente = id_cliente;
    }

    public int getId_salon() {
        return id_salon;
    }

    public void setId_salon(int id_salon) {
        this.id_salon = id_salon;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public String getHora_inicio() {
        return hora_inicio;
    }

    public void setHora_inicio(String hora_inicio) {
        this.hora_inicio = hora_inicio;
    }

    public String getHora_fin() {
        return hora_fin;
    }

    public void setHora_fin(String hora_fin) {
        this.hora_fin = hora_fin;
    }

    @Override
    public String toString() {
        return "Reservacion{" + "id=" + id + ", id_cliente=" + id_cliente + ", id_salon=" + id_salon + ", fecha=" + fecha + ", hora_inicio=" + hora_inicio + ", hora_fin=" + hora_fin + '}';
    }

}  