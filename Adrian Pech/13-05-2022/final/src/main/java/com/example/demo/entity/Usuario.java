package com.example.demo.entity;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

@Entity
@Table(name = "usuarios")
public class Usuario implements Serializable {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id_usuario")
    private Long id;
    @Column(name = "nombre")
    private String nombre;
    @Column(name = "email")
    private String email;
    @Column(name = "username")
    private String username;
    @Column(name = "password")
    private String password;
    @Column(name = "fecha_nacimiento")
    private String fechanacimiento;
    @Column(name = "sexo")
    private String sexo;
    @OneToMany(mappedBy = "usuario", cascade = { CascadeType.PERSIST, CascadeType.MERGE, CascadeType.DETACH,
            CascadeType.REFRESH })
    private List<Imc> imc;

    public void agregarImc(Imc imc) {
        if (this.imc == null) {
            this.imc = new ArrayList<>();
        } else {
            imc.setUsuario(this);
            this.imc.add(imc);
        }
    }

    public List<Imc> getImc() {
        return imc;
    }

    public void setImc(List<Imc> imc) {
        this.imc = imc;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getFechanacimiento() {
        return fechanacimiento;
    }

    public void setFechanacimiento(String fechanacimiento) {
        this.fechanacimiento = fechanacimiento;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public Usuario() {
    }

    public Usuario(String nombre, String email, String username, String password, String fechanacimiento,
            String sexo) {
        this.nombre = nombre;
        this.email = email;
        this.username = username;
        this.password = password;
        this.fechanacimiento = fechanacimiento;
        this.sexo = sexo;
    }

    @Override
    public String toString() {
        return "Usuario{" + "id=" + id + ", nombre=" + nombre + ", email=" + email + ", username=" + username
                + ", password=" + password + ", fechanacimiento=" + fechanacimiento + ", sexo=" + sexo + '}';
    }
}
