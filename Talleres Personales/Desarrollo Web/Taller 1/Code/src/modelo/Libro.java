package modelo;

public class Libro {
    private String titulo;
    private String descripcion;
    private String autor;
    private int precio;
    private int anoPublicacion;
    private int paginas;

    public Libro(String titulo, String descripcion, String autor, int precio, int anoPublicacion, int paginas) {
        this.titulo = titulo;
        this.descripcion = descripcion;
        this.autor = autor;
        this.precio = precio;
        this.anoPublicacion = anoPublicacion;
        this.paginas = paginas;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getPrecio() {
        return precio;
    }

    public void setPrecio(int precio) {
        this.precio = precio;
    }

    public int getAnoPublicacion() {
        return anoPublicacion;
    }

    public void setAnoPublicacion(int anoPublicacion) {
        this.anoPublicacion = anoPublicacion;
    }

    public int getPaginas() {
        return paginas;
    }

    public void setPaginas(int paginas) {
        this.paginas = paginas;
    }

    @Override
    public String toString() {
        return "Libro{" +
                "Descripcion='" + descripcion + '\'' +
                ", Precio=" + precio +
                ", Año de publicacion=" + anoPublicacion +
                ", Paginas=" + paginas +
                '}';
    }
}
