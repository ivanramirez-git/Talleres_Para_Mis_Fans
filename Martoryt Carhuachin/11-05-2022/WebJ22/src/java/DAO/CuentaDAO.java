/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAO;

import DB.ConexionDB;
import VO.CuentaVO;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.Collection;

public class CuentaDAO implements ICuenta
{
    private Connection conn;
    private PreparedStatement ps;
    private ResultSet rs;
    
   
    @Override
    public void insert(CuentaVO vo)
    {
        try
        {
            conn=ConexionDB.MySQL();
            
            String SQL="insert into cuentas(pelicula,precio,plataforma,fvencimiento,cuentasdisponibles) values(?,?,?,?,?)";
            ps=conn.prepareCall(SQL);
            
            ps.setString(1,vo.getPelicula());
            ps.setDouble(2,vo.getPrecio());
            ps.setString(3,vo.getPlataforma());
            ps.setDate(4,new java.sql.Date(vo.getFvencimiento().getTime()));
            ps.setInt(5,vo.getCuentasdisponibles());
            
            int rows=ps.executeUpdate();
            if(rows!=1){
                System.out.println("Error INSERT!"); 
            } 
        }
        catch(Exception ex){
            ex.printStackTrace();
        }  
    }

    @Override
    public void update(CuentaVO vo) 
    {
        try
        {
            conn=ConexionDB.MySQL();
            
            String SQL="update cuentas set pelicula=?,precio=?,plataforma=?,fvencimiento=?,cuentasdisponibles=? where cuentaId=?";
            ps=conn.prepareCall(SQL);
            
            ps.setString(1,vo.getPelicula());
            ps.setDouble(2,vo.getPrecio());
            ps.setString(3,vo.getPlataforma());
            ps.setDate(4,new java.sql.Date(vo.getFvencimiento().getTime()));
            ps.setInt(5,vo.getCuentasdisponibles());
            ps.setInt(6,vo.getCuentaId());
            
            int rows=ps.executeUpdate();
            if(rows!=1){
                System.out.println("Error UPDATE!"); 
            } 
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
    }

    @Override
    public void delete(Integer cuentaId) 
    {
        try
        {
            conn=ConexionDB.MySQL();
            
            String SQL="delete from cuentas where cuentaId=?";
            ps=conn.prepareCall(SQL);
            
            ps.setInt(1,cuentaId);
            
            int rows=ps.executeUpdate();
            if(rows!=1){
                System.out.println("Error DELETE!"); 
            } 
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
    }

    @Override
    public CuentaVO findById(Integer cuentaId) 
    {
        CuentaVO vo=null;
        
        try
        {
            conn=ConexionDB.MySQL();
            
            String SQL="select * from cuentas where cuentaId=?";
            ps=conn.prepareCall(SQL);
            
            ps.setInt(1,cuentaId);
            
            rs=ps.executeQuery();
            
            if(rs.next())
            {
                vo=new CuentaVO();
                
                vo.setCuentaId(rs.getInt("cuentaId"));
                vo.setPelicula(rs.getString("pelicula"));
                vo.setPrecio(rs.getDouble("precio"));
                vo.setPlataforma(rs.getString("plataforma"));
                vo.setFvencimiento(rs.getDate("fvencimiento"));
                vo.setCuentasdisponibles(rs.getInt("cuentasdisponibles"));
            }
                
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
        
        return vo;
    }

    @Override
    public Collection<CuentaVO> findAll() 
    {
        Collection<CuentaVO> list=new ArrayList<>();
        
        try
        {
            conn=ConexionDB.MySQL();
            
            String SQL="select * from cuentas order by cuentaId";
            ps=conn.prepareCall(SQL);
            
            rs=ps.executeQuery();
            
            while(rs.next())
            {
                CuentaVO vo=new CuentaVO();
                
                vo.setCuentaId(rs.getInt("cuentaId"));
                vo.setPelicula(rs.getString("pelicula"));
                vo.setPrecio(rs.getDouble("precio"));
                vo.setPlataforma(rs.getString("plataforma"));
                vo.setFvencimiento(rs.getDate("fvencimiento"));
                vo.setCuentasdisponibles(rs.getInt("cuentasdisponibles"));
                
                list.add(vo);
            }    
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
        return list;
    }
} 
       
