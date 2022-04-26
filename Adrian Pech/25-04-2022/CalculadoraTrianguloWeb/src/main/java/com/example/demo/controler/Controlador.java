package com.example.demo.controler;

import com.example.demo.interfaceService.ItrianguloService;
import com.example.demo.modelo.Triangulo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.validation.Valid;

import java.util.List;
import java.util.Optional;

@Controller
@RequestMapping
public class Controlador {

    @Autowired
    private ItrianguloService service;

    @GetMapping("/listar")
    public String listar(Model model) {
        List<Triangulo> triangulos = service.listar();
        model.addAttribute("triangulos", triangulos);
        return "index";
    }

    @GetMapping("/new")
    public String agregar(Model model) {
        model.addAttribute("triangulo", new Triangulo());
        return "form";
    }

    @PostMapping("/save")
    public String save(@Valid Triangulo triangulo, Model model) {
        triangulo.calcular();
        service.save(triangulo);
        return "redirect:/listar";
    }

    @GetMapping("/editar/{id}")
    public String editar(@PathVariable int id, Model model) {
        Optional<Triangulo> triangulo = service.listarId(id);
        model.addAttribute("triangulo", triangulo);
        return "form";
    }

    @GetMapping("/eliminar/{id}")
    public String eliminar(@PathVariable int id) {
        service.delete(id);
        return "redirect:/listar";
    }

}
