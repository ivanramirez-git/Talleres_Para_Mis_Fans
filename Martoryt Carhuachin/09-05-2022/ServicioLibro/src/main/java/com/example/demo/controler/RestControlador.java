package com.example.demo.controler;

import com.example.demo.interfaceService.IlibroService;
import com.example.demo.modelo.Libro;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

// import java.net.http.HttpResponse;
import java.util.List;
import java.util.Optional;

//@Controller
@RestController
@RequestMapping
public class RestControlador {

    @Autowired
    private IlibroService service;

    // Listar
    @GetMapping("/listar")
    public List<Libro> listar() {
        return service.listar();
    }

    // Guardar
    @PostMapping("/registrar")
    public String insert(@RequestBody Libro libro) {
        service.save(libro);
        return "{\"msg\":\"ok\"}";
    }

    // Eliminar
    @PostMapping("/eliminar")
    public String delete(@RequestBody Libro libro) {
        service.delete(libro.getId());
        return "{\"msg\":\"ok\"}";
    }

    // Listar por id
    @PostMapping("/listarId")
    public Optional<Libro> listarId(@RequestBody Libro libro) {
        return service.listarId(libro.getId());
    }    

    // Actualizar
    @PostMapping("/actualizar")
    public String update(@RequestBody Libro libro) {
        service.save(libro);
        return "{\"msg\":\"ok\"}";
    }

}
