package com.example.demo.security;

import com.example.demo.dao.IUsuarioDAO;
import com.example.demo.entity.Usuario;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.core.userdetails.User.UserBuilder;
import org.springframework.stereotype.Service;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.User;

@Service
public class UserDetailsServiceImpl implements UserDetailsService {

    @Autowired
    private IUsuarioDAO usuarioDao;

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        Usuario usuario = usuarioDao.findByUsername(username);
        UserBuilder builder = null;

        if (usuario != null) {
            builder = User.withUsername(username);
            builder.disabled(false);
            builder.password(usuario.getPassword());
            builder.authorities(new SimpleGrantedAuthority("ROLE_USER"));
        } else {
            throw new UsernameNotFoundException("Usuario no encontrado");
        }

        return builder.build();
    }
    
}
