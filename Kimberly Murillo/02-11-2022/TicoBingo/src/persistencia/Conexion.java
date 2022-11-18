/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package persistencia;

import java.sql.Connection;
import java.sql.DriverManager;

/**
 *
 * @author nitro5
 */

public class Conexion {

    // servidor: localhost
    // puerto: 3306
    // usuario: root
    // contraseña: 
    // base de datos: historial
    private static final String URL = "jdbc:mysql://localhost:3306/historial";
    private static final String USER = "root";
    private static final String PASSWORD = "";

    public Connection getConnection() throws Exception {
        Class.forName("com.mysql.cj.jdbc.Driver");
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    public Object consulta(String sql) throws Exception {
        return getConnection().createStatement().executeQuery(sql);
    }

    public void ingresar(String sql) throws Exception {
        getConnection().createStatement().executeUpdate(sql);
    }

}
