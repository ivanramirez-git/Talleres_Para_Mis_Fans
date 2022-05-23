package com.example.demo.service;

import java.util.List;

import com.example.demo.entity.Imc;
import com.example.demo.entity.Usuario;

public interface IImcService {
    public List<Imc> findByUsuario(Usuario usuario);
    public Imc registrarImc(Imc imc);
}
