package com.example.demo.controllers;

import com.example.demo.entity.Usuario;
import com.example.demo.service.IUsuarioService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
public class LoginController {

    @Autowired
    private IUsuarioService usuarioService;

    @GetMapping("/auth/login")
    public String login(Model model) {
        model.addAttribute("usuario", new Usuario());
        return "login";
    }

    @GetMapping("/auth/registro")
    public String registroForm(Model model) {
        model.addAttribute("usuario", new Usuario());
        return "registro";
    }

    @PostMapping("/auth/registro")
    public String registro(@ModelAttribute Usuario usuario, BindingResult result, Model model) {

        if (result.hasErrors()) {
            // Log que diga que hay errores en el formulario
            System.out.println(". . : : ERROR EN EL FORMULARIO : : . .");
            System.out.println(result.toString());
            
            return "redirect:/auth/registro";
        }

        model.addAttribute("usuario", usuarioService.registrar(usuario));

        return "redirect:/auth/login";
    }
}