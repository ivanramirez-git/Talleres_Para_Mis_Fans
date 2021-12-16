#include <stdio.h>
#include <stdlib.h> 

struct paciente {
    int dia_ingreso;
    int mes_ingreso;
    int anio_ingreso;
    float temperatura;
    char observaciones[250];
    char nombres_paciente[25];
    char apellidos_paciente[25];
    char email_paciente[25];
    long fono_paciente;
    int edad_paciente;
    int dia_diagnostico;
    int mes_diagnostico;
    int anio_diagnostico;
    int rut_medicoTratante;
    char clasificacion_triage[1];
    int nro_ingreso;
};

// Funcion que carga un archivo binario con la informacion de muchos pacientes, genera un archivo contactos_estrechos.dat, con los datos de contacto de los pacientes atendidos el 14 de diciembre de 2021. recibe como parametro el nombre del archivo a leer.
void cargar_archivo_binario(char *nombre_archivo){
    // Cargamos el archivo binario
    FILE *archivo_binario;
    // Lista de pacientes
    struct paciente *pacientes;
    // Cantidad de pacientes
    int cantidad_pacientes;
    int i;
    // Abrimos el archivo binario
    archivo_binario = fopen(nombre_archivo, "rb");
    // Si el archivo existe
    if (archivo_binario != NULL) {
        // Leemos la cantidad de pacientes
        fread(&cantidad_pacientes, sizeof (int), 1, archivo_binario);
        // Reservamos memoria para la lista de pacientes
        pacientes = (struct paciente *) malloc(cantidad_pacientes * sizeof (struct paciente));
        // Leemos la lista de pacientes
        fread(pacientes, sizeof (struct paciente), cantidad_pacientes, archivo_binario);
        // Cerramos el archivo binario
        fclose(archivo_binario);
        // Abrimos el archivo de texto
        FILE *archivo_texto;
        archivo_texto = fopen("contactos_estrechos.dat", "w");
        // Recorremos la lista de pacientes
        for (i = 0; i < cantidad_pacientes; i++) {
            // Si el paciente fue atendido el 14 de diciembre de 2021
            if (pacientes[i].dia_diagnostico == 14 && pacientes[i].mes_diagnostico == 12 && pacientes[i].anio_diagnostico == 2021) {
                // Imprimimos los datos del paciente
                fprintf(archivo_texto, "%s %s %s %s %ld %d %d %d %d %d %d %d %d %s\n", pacientes[i].nombres_paciente, pacientes[i].apellidos_paciente, pacientes[i].email_paciente, pacientes[i].observaciones, pacientes[i].fono_paciente, pacientes[i].dia_ingreso, pacientes[i].mes_ingreso, pacientes[i].anio_ingreso, pacientes[i].dia_diagnostico, pacientes[i].mes_diagnostico, pacientes[i].anio_diagnostico, pacientes[i].rut_medicoTratante, pacientes[i].clasificacion_triage, pacientes[i].nro_ingreso);
            }
        }
        // Cerramos el archivo de texto
        fclose(archivo_texto);
    }

    // Liberamos la memoria
    free(pacientes);
}

int main(){
    // Cargamos el archivo binario
    cargar_archivo_binario("pacientes.dat");
    // Fin
    return 0;
}