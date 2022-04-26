
public class Cajero {
    float Saldo_F=0;
    float Retiro=0;
    float Consulta(){
        return Saldo_F;
    }
    float Retiro(float Retiro){
        Saldo_F=Saldo_F-Retiro;
        return Saldo_F;
    }
    float Deposito(float Deposito){
        Saldo_F=Saldo_F+Deposito;
        return Saldo_F;
    }
    Cajero(){
    }

}
