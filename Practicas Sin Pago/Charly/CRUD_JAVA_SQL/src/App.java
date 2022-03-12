import java.sql.ResultSet;

public class App {
    public static void main(String[] args) throws Exception {

        // Imprimir tabla "estudiantes"
        System.out.println("Estudiantes");
        System.out.println("----------");
        ResultSet rs = ConexionSQL.query("SELECT * FROM estudiantes");
        while (rs.next()) {
            System.out.println(rs.getString("nombre") + " " + rs.getString("apellido"));
        }
        
    }
}
