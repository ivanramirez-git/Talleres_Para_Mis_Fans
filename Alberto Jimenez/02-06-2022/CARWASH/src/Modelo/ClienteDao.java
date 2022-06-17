/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import javax.swing.JOptionPane;
/**
 *
 * @author Jorge Alberto
 */
public class ClienteDao {
  Conexion cn= new Conexion();
Connection con;  
PreparedStatement ps;
public boolean RegistrarCliente(Cliente cl){
    String sql="INSERT INTO clientes(codigo,apellidop,apellidom,nombre,telefono,calle,numextint,colonia,ciudad,cp,estado,pais,correo) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?)";
try{
     con=cn.getConnection();
     ps=con.prepareStatement(sql);
     ps.setInt(1, cl.getCodigo());
     ps.setString(2, cl.getApellidop());
     ps.setString(3, cl.getApellidom());
     ps.setString(4, cl.getNombre());
     ps.setInt(5, cl.getTelefono());
     ps.setString(6, cl.getCalle());
     ps.setInt(7, cl.getNumextint());
     ps.setString(8, cl.getColonia());
     ps.setString(9, cl.getCiudad());
     ps.setInt(10, cl.getNumextint());
     ps.setString(11, cl.getEstado());
     ps.setString(12, cl.getPais());
     ps.setString(13, cl.getCorreo());
     ps.execute();
       return true;
               
}catch(SQLException e){
   JOptionPane.showMessageDialog(null,e.toString());
   return false;
}finally{
    try{
        con.close();
    }catch(SQLException e){
       System.out.println(e.toString());
    }
}
}
}
