package com.example.demo.service;

import java.util.List;
import java.util.Optional;

import com.example.demo.interfaceService.ItrianguloService;
import com.example.demo.interfaces.ITriangulo;
import com.example.demo.modelo.Triangulo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class TrianguloService implements ItrianguloService {

    @Autowired
    private ITriangulo data;

    @Override
    public List<Triangulo> listar() {
        return (List<Triangulo>) data.findAll();
    }

    @Override
    public Optional<Triangulo> listarId(int id) {
        return data.findById(id);
    }

    @Override
    public int save(Triangulo t) {
        int res=0;
        Triangulo triangulo = data.save(t);
        if(!triangulo.equals(null)){
            res=1;
        }
        return res;
    }

    @Override
    public void delete(int id) {
        data.deleteById(id);        
    }
    
}
