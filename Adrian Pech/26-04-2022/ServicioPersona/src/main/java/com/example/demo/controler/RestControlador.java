package com.example.demo.controler;

import com.example.demo.interfaceService.IpersonaService;
import com.example.demo.modelo.Persona;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.net.http.HttpResponse;
import java.util.List;

//@Controller
@RestController
@RequestMapping
public class RestControlador {

    @Autowired
    private IpersonaService service;

    @GetMapping("/listarJson")
    public List<Persona> listar() {
        return service.listar();
    }

    @PostMapping("/saveJson")
    public String insert(@RequestBody Persona persona) {
        persona.llenarCampos();
        service.save(persona);
        return "{\"msg\":\"ok\"}";
    }
}
