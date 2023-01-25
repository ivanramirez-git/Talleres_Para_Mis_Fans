// Desarrollar un script que realice las siguientes tareas:

// Se ingresen como argumentos de entrada (al menos un argumento), una lista de uno o más nombres de elementos a verificar. En caso de que no se ingrese al menos un argumento de entrada, saldrá un mensaje de: "SE REQUIERE AL MENOS UN ARGUMENTO DE ENTRADA", y se saldrá del script. (vale 2.0 ptos.)
// Luego se debe presentar un menú que se ejecute indefinidamente; el mismo que tiene las siguientes opciones: (vale 1.5 ptos.)
//    a) USUARIOS

//    b) TIPO DE ARCHIVOS

//    c) Salir

// Para el literal a) se deberá ingresar desde el teclado, dos números enteros que representan las columnas a seleccionar del archivo (/etc/passwd). Luego, se debe imprimir en pantalla las dos columnas seleccionadas (del archivo /etc/passwd) y en la línea final el número de usuarios que tiene (número de líneas del archivo passwd) el sistema. (vale 2.0 ptos.)
// Para el literal b) se deben usar los argumentos de entrada ingresados (1 o varios), a esta lista de argumentos se debe verificar qué tipo de archivo es (textual, ejecutable o bloque o no es archivo). Luego, se debe mostrar en pantalla la lista de argumentos ingresados y a lado el mensaje de qué tipo de archivo es; en formato de tabla la presentación del resultado. (vale 4.0 ptos.)
// Con el literal c) se sale del script. (vale 0.5 ptos.)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char *menu[] = {"a) USUARIOS", "b) TIPO DE ARCHIVOS", "c) Salir"};
    char *opcion;
    char *archivo = "/etc/passwd";
    
    if (argc < 2)
    {
        printf("SE REQUIERE AL MENOS UN ARGUMENTO DE ENTRADA \n");
        exit(1);
    }

    do
    {
        printf(" MENU \n");
        for (int i = 0; i < 3; i++)
        {
            printf("%s \n", menu[i]);
        }
        printf("Ingrese una opcion: ");
        scanf("%s", opcion);
        switch (opcion[0])
        {
        case 'a':
            printf("USUARIOS \n");
            // file 
            FILE *file;
            file = fopen(archivo, "r");
            if (file == NULL)
            {
                printf("Error al abrir el archivo \n");
                exit(1);
            }
            // columnas
            int columna1, columna2;
            printf("Ingrese la columna 1: ");
            scanf("%d", &columna1);
            printf("Ingrese la columna 2: ");
            scanf("%d", &columna2);
            // lectura
            char *linea = NULL;
            size_t len = 0;
            ssize_t read;
            int contador = 0;
            while ((read = getline(&linea, &len, file)) != -1)
            {
                char *token = strtok(linea, ":");
                int i = 1;
                while (token != NULL)
                {
                    if (i == columna1 || i == columna2)
                    {
                        printf("%s \t", token);
                    }
                    token = strtok(NULL, ":");
                    i++;
                }
                printf(" \n");
                contador++;
            }
            printf("Numero de usuarios: %d \n", contador);
            fclose(file);
            if (linea)
            {
                free(linea);
            }

            break;
        case 'b':
            printf("TIPO DE ARCHIVOS \n");
            // argumentos
            for (int i = 1; i < argc; i++)
            {
                struct stat st;
                if (stat(argv[i], &st) == 0)
                {
                    printf("%s \t", argv[i]);
                    if (S_ISREG(st.st_mode))
                    {
                        printf("Archivo \t");
                    }
                    else if (S_ISDIR(st.st_mode))
                    {
                        printf("Directorio \t");
                    }
                    else if (S_ISCHR(st.st_mode))
                    {
                        printf("Dispositivo de caracteres \t");
                    }
                    else if (S_ISBLK(st.st_mode))
                    {
                        printf("Dispositivo de bloques \t");
                    }
                    else if (S_ISFIFO(st.st_mode))
                    {
                        printf("FIFO \t");
                    }
                    else if (S_ISLNK(st.st_mode))
                    {
                        printf("Enlace simbolico \t");
                    }
                    else if (S_ISSOCK(st.st_mode))
                    {
                        printf("Socket \t");
                    }
                    else
                    {
                        printf("No es archivo \t");
                    }
                    printf(" \n");
                }
                else
                {
                    printf("Error al obtener el tipo de archivo \n");
                }
            }
            break;
        case 'c':
            printf("SALIR \n");
            break;
        default:
            printf("OPCION NO VALIDA \n");
            break;
        }
    } while (opcion[0] != 'c');

    return 0;
}