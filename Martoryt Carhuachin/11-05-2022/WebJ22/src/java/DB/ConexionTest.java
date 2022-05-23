/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DB;

import java.sql.SQLException;


public class ConexionTest 
{
    public static void main(String[] args) throws ClassNotFoundException, SQLException 
    {
        ConexionDB.MySQL();
        System.out.println("Conexion... OK");
    }
}