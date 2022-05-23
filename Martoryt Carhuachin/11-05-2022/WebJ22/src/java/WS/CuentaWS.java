/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WS;

import DAO.CuentaDAO;
import DAO.ICuenta;
import VO.CuentaVO;
import java.util.Collection;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;

@WebService(serviceName = "CuentaWS")
public class CuentaWS 
{
    private ICuenta cuentaDao=new CuentaDAO();

    @WebMethod(operationName="Welcome")
    public String Welcome() {
        return "¡Bienvenido a mi Evaluacion espero aprobar profesor!";
    }
            
    @WebMethod(operationName="registrar")
    public String registrarCuenta(CuentaVO cuentaVO) {
        cuentaDao.insert(cuentaVO);
        return "Cuenta registrada correctamente";
    }
    
    @WebMethod(operationName="editar")
    public String editarCuenta(CuentaVO cuentaVO) {
        cuentaDao.update(cuentaVO);
        return "Cuenta editada correctamente";
    }
    
    @WebMethod(operationName="borrar")
    public String borrarCuenta(Integer CuentaId) {
        cuentaDao.delete(CuentaId);
        return "Cuenta borrada correctamente";
    }
    
    @WebMethod(operationName="buscar")
    public CuentaVO buscarCuenta(Integer CuentaId) {
        return cuentaDao.findById(CuentaId);  
    }
    
    @WebMethod(operationName="listar")
    public Collection<CuentaVO> listarCuenta() {
        return cuentaDao.findAll();
    }
}
