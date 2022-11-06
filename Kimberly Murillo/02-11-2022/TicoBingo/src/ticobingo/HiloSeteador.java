package ticobingo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class HiloSeteador extends Thread {

    private Estado estado;
    // cola de peticiones, peticion es un mapa con key y value
    private List<Map<String, Object>> peticiones;

    public HiloSeteador(Estado estado) {
        this.estado = estado;
        this.peticiones = new ArrayList<>();
    }

    @Override
    public void run() {
        // setea el valor de la variable
        while (true) {
            // si hay peticiones
            if (peticiones.size() > 0) {
                // obtiene la primera peticion
                Map<String, Object> peticion = peticiones.get(0);
                // obtiene el key
                String key = (String) peticion.keySet().toArray()[0];
                // obtiene el value validar que no sea null o este vacio
                Object value = peticion.get(key);
                // setea el valor, validar que valor y clave no esten vacios o no sean nulos
                if (value != null && !value.toString().isEmpty() && key != null && !key.isEmpty()) {
                    estado.set(key, value);
                }
                // elimina la peticion
                peticiones.remove(0);
            }
            // espera 10 milisegundos
            try {
                Thread.sleep(10);
            } catch (InterruptedException ex) {
                System.out.println("Error: " + ex.getMessage());
                Thread.currentThread().interrupt();
            }
        }
    }

    public void setState(String key, Object value) {
        // crea un mapa con key y value
        Map<String, Object> peticion = new HashMap<>();
        peticion.put(key, value);
        // agrega la peticion a la cola
        peticiones.add(peticion);
        // System.out.println("Peticion agregada: " + key + " = " + value);
    }

}
