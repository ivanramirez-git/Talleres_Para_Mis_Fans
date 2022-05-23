/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DB;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class ConexionDB 
{
    
    public static Connection MySQL() throws ClassNotFoundException, SQLException 
    {
        Class.forName("com.mysql.cj.jdbc.Driver");
        String url="jdbc:mysql://localhost:3306/db_demo?useSSL=false&allowPublicKeyRetrieval=true";
        
        return DriverManager.getConnection(url,"root","72959630");
    }   
}