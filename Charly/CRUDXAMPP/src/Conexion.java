import java.sql.Connection;
import java.sql.DriverManager;

public class Conexion {

    // servidor: localhost
    // puerto: 3306
    // usuario: root
    // contraseña: 
    // base de datos: universidad
    private static final String URL = "jdbc:mysql://localhost:3306/universidad";
    private static final String USER = "root";
    private static final String PASSWORD = "";

    public static Connection getConnection() throws Exception {
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
