package com.example.demo.interfaceService;

import java.util.List;
import java.util.Optional;

import com.example.demo.modelo.Triangulo;

public interface ItrianguloService {
    public List<Triangulo> listar();
    public Optional<Triangulo> listarId(int id);
    public int save(Triangulo t);
    public void delete(int id);
}
