package com.example.demo.service;

import java.util.List;
import java.util.Optional;

import com.example.demo.interfaceService.IpersonaService;
import com.example.demo.interfaces.IPersona;
import com.example.demo.modelo.Persona;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class PersonaService implements IpersonaService {

    @Autowired
    private IPersona data;

    @Override
    public List<Persona> listar() {
        return (List<Persona>) data.findAll();
    }

    @Override
    public Optional<Persona> listarId(int id) {
        return data.findById(id);
    }

    @Override
    public int save(Persona t) {
        int res=0;
        Persona persona = data.save(t);
        if(!persona.equals(null)){
            res=1;
        }
        return res;
    }

    @Override
    public void delete(int id) {
        data.deleteById(id);        
    }
    
}
