package com.example.demo.interfaceService;

import java.util.List;
import java.util.Optional;

import com.example.demo.modelo.Libro;

public interface IlibroService {
    public List<Libro> listar();
    public Optional<Libro> listarId(int id);
    public int save(Libro t);
    public void delete(int id);
}
