package com.example;

import javax.swing.*;
import javax.swing.table.TableModel;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Main {

    public static void main(String[] args) {
	// write your code here
        /*

        DBMS: MySQL (ver. 5.5.5-10.4.22-MariaDB)
        Case sensitivity: plain=lower, delimited=lower
        Driver: MySQL Connector/J (ver. mysql-connector-java-8.0.25 (Revision: 08be9e9b4cba6aa115f9b27b215887af40b159e0), JDBC4.2)
        Effective version: MariaDB (ver. 10.4.22)
        Ping: 24 ms
        SSL: no
        DATABASE: universidad
        Servidor: localhost
        Puerto: 3306
        Usuario: root
        Contraseña:


        Tabla: estudiantes
            id INT NOT NULL AUTO_INCREMENT,
            nombre VARCHAR(50) NOT NULL,
            telefono VARCHAR(10) NOT NULL,
            email VARCHAR(50) NOT NULL,
            anioingreso INT NOT NULL,
            PRIMARY KEY (id)

        */

        ResultSet resultSet = consulta("SELECT * FROM estudiantes");
        JTable table = new JTable((TableModel) resultSet);
        JScrollPane scrollPane = new JScrollPane(table);
        JFrame frame = new JFrame("Estudiantes");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(scrollPane);
        frame.pack();
        frame.setVisible(true);

    }

    // Query
    public static ResultSet consulta(String query) {
        // Conexion
        String url = "jdbc:mysql://localhost:3306/universidad";
        String path = "com.mysql.cj.jdbc.Driver";
        String user = "root";
        String password = "";
        Connection connection = null;

        // Query
        String sql = query;
        ResultSet resultSet = null;

        // Ejecutar query
        try {
            Class.forName(path);
            connection = DriverManager.getConnection(url, user, password);
            resultSet = connection.createStatement().executeQuery(sql);

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }

        return resultSet;
    }

}
