package com.example.demo.impl;

import com.example.demo.dao.IUsuarioDAO;
import com.example.demo.entity.Usuario;
import com.example.demo.service.IUsuarioService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

@Service
public class UsuarioServiceImpl implements IUsuarioService{

    @Autowired
    private BCryptPasswordEncoder passwordEncoder;

    @Autowired
    private IUsuarioDAO usuarioDao;

    @Override
    public Usuario findByUsername(String username) {
        return usuarioDao.findByUsername(username);
    }

    @Override
    public Usuario registrar(Usuario usuario) {
        usuario.setPassword(passwordEncoder.encode(usuario.getPassword()));
        return usuarioDao.save(usuario);
    }
    
}
