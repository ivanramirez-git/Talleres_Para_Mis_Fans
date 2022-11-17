package ticobingo;

import java.util.HashMap;
import java.util.Map;

public class Estado {
    // mapa con toda la informacion de la aplicacion
    private Map<String, Object> state;

    // constructor
    public Estado() {
        state = new HashMap<>();
    }

    // metodos
    public void set(String key, Object value) {
        // valida que el key no sea nulo
        if (key != null) {
            state.put(key, value);
        }
    }

    public Object get(String key) {
        // valida que el key no sea nulo
        if (key != null) {
            return state.get(key);
        }
        return null;
    }

    public void remove(String key) {
        // valida que el key no sea nulo
        if (key != null) {
            state.remove(key);
        }
    }
    
    public void clear() {
        state.clear();
    }

    public boolean containsKey(String key) {
        // valida que el key no sea nulo
        if (key != null) {
            return state.containsKey(key);
        }
        return false;
    }

    @Override
    public String toString() {
        return state.toString();
    }

}
