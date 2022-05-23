package com.example.demo.interfaces;

import com.example.demo.modelo.Libro;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ILibro extends CrudRepository<Libro, Integer> {

}