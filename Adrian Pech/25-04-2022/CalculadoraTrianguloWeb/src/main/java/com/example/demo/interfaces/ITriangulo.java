package com.example.demo.interfaces;

import com.example.demo.modelo.Triangulo;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ITriangulo extends CrudRepository<Triangulo, Integer> {

}