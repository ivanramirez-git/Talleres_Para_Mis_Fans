package com.example.demo.dao;

import java.util.List;

import com.example.demo.entity.Imc;
import com.example.demo.entity.Usuario;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface IImcDAO extends JpaRepository<Imc, Long> {    
    public List<Imc> findByUsuario(Usuario usuario);
}