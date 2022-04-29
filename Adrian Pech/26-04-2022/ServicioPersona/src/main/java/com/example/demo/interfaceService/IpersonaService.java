package com.example.demo.interfaceService;

import java.util.List;
import java.util.Optional;

import com.example.demo.modelo.Persona;

public interface IpersonaService {
    public List<Persona> listar();
    public Optional<Persona> listarId(int id);
    public int save(Persona t);
    public void delete(int id);
}
