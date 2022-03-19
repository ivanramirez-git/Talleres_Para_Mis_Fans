package Modelo;

import java.util.ArrayList;

public class Cliente extends Usuario {

    // Reservaciones
    ArrayList<Reservacion> reservaciones;

    public Cliente(int id, String usuario, String nombre, String email, String password) {
        super(id, usuario, nombre, email, password);
        this.reservaciones = new ArrayList<Reservacion>();
    }

    public ArrayList<Reservacion> getReservaciones() {
        return reservaciones;
    }

    public void setReservaciones(ArrayList<Reservacion> reservaciones) {
        this.reservaciones = reservaciones;
    }

    public void addReservacion(Reservacion reservacion) {
        this.reservaciones.add(reservacion);
    }

    public void removeReservacion(Reservacion reservacion) {
        this.reservaciones.remove(reservacion);
    }

    public Reservacion getReservacion(int id) {
        for (Reservacion reservacion : this.reservaciones) {
            if (( reservacion).getId() == id) {
                return reservacion;
            }
        }
        return null;
    }

    public Reservacion getReservaciones(String fecha) {
        ArrayList<Reservacion> reservaciones = new ArrayList<Reservacion>();
        for (Reservacion reservacion : this.reservaciones) {
            if (( reservacion).getFecha() == fecha) {
                reservaciones.add(reservacion);
            }
        }
        return null;
    }


    @Override
    public String toString() {
        return "Cliente{" +
                "reservaciones=" + reservaciones +
                '}';
    }    
}
