package com.example.demo.service;

import java.util.List;
import java.util.Optional;

import com.example.demo.interfaceService.IlibroService;
import com.example.demo.interfaces.ILibro;
import com.example.demo.modelo.Libro;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class LibroService implements IlibroService {

    @Autowired
    private ILibro data;

    @Override
    public List<Libro> listar() {
        return (List<Libro>) data.findAll();
    }

    @Override
    public Optional<Libro> listarId(int id) {
        return data.findById(id);
    }

    @Override
    public int save(Libro t) {
        int res=0;
        Libro libro = data.save(t);
        if(!libro.equals(null)){
            res=1;
        }
        return res;
    }

    @Override
    public void delete(int id) {
        data.deleteById(id);        
    }
    
}
