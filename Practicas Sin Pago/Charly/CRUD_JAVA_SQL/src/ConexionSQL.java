import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ConexionSQL {
    /*
    id Primaria	int(10)
    nombre	varchar
    carrera	varchar(50)
    carrera	varchar(50)

    localhost
    db: ejercicio
    user: root
    pass:
    */

    public static ResultSet query(String sql) {
        try {
            return DriverManager.getConnection("jdbc:mysql://localhost/ejercicio", "root", "").createStatement().executeQuery(sql);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
}
