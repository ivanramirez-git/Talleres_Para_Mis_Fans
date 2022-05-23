/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAO;

import VO.CuentaVO;
import java.util.Collection;


public interface ICuenta 
{
    public abstract void insert(CuentaVO vo);
    public abstract void update(CuentaVO vo);
    public abstract void delete(Integer cuentaId);
    public abstract CuentaVO findById(Integer cuentaId);
    public abstract Collection<CuentaVO> findAll();


}
