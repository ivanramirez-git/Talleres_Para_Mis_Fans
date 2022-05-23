package com.example.demo.service;

import com.example.demo.entity.Usuario;

public interface IUsuarioService {
    public Usuario findByUsername(String username);
    public Usuario registrar(Usuario usuario);
}
