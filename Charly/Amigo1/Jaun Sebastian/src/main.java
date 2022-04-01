import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author aulasingenieria
 */
public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here  
        
        
        Connection con = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");            
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ejercicio", "root", "");
        } catch (ClassNotFoundException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
        TecnoMecanica t = new TecnoMecanica(con);
        t.setVisible(true);
    }

    // Conexion a la base de datos
    
}
