package com.example.demo.controllers;

import java.util.List;

import javax.servlet.http.HttpSession;

import com.example.demo.entity.Imc;
import com.example.demo.entity.Usuario;
import com.example.demo.service.IImcService;
import com.example.demo.service.IUsuarioService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/")
public class PrivateController {

    @Autowired
    private IUsuarioService usuarioService;

    @Autowired
    private IImcService imcService;

    
    
    @RequestMapping("/private/index")
    public String index(Authentication auth, HttpSession session) {

        String username = auth.getName();
        
        if(session.getAttribute("usuario") == null) {
            Usuario usuario = usuarioService.findByUsername(username);
            List<Imc> imcs = imcService.findByUsuario(usuario);
            usuario.setImc(imcs);
            usuario.setPassword(null);
            session.setAttribute("usuario", usuario);
        }
        return "index";
    }    

    @PostMapping("/registroImc")
    public String registroImc(Authentication auth, @ModelAttribute Imc imc, BindingResult result, Model model) {

        String username = auth.getName();

        if (result.hasErrors()) {
            // Log que diga que hay errores en el formulario
            System.out.println(". . : : ERROR EN EL FORMULARIO : : . .");
            System.out.println(result.toString());
        } else {
            Usuario usuario = usuarioService.findByUsername(username);
            imc.setUsuario(usuario);
            imc.calcularIMC();
            imcService.registrarImc(imc);
        }
        return "redirect:/private/index";
    }

    @GetMapping("/registroImc")
    public String registroForm(Model model) {
        model.addAttribute("imc", new Imc());
        return "index";
    }

}
