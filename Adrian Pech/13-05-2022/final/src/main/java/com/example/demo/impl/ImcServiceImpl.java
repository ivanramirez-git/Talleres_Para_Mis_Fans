package com.example.demo.impl;

import java.util.List;

import com.example.demo.dao.IImcDAO;
import com.example.demo.entity.Imc;
import com.example.demo.entity.Usuario;
import com.example.demo.service.IImcService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class ImcServiceImpl implements IImcService{

    @Autowired
    private IImcDAO imcDao;

    @Override
    public List<Imc> findByUsuario(Usuario usuario) {
        return imcDao.findByUsuario(usuario);
    }

    @Override
    public Imc registrarImc(Imc imc) {
        return imcDao.save(imc);
    }
    
}
