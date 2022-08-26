#include <string.h>
#include <stdio.h>
#include <stdbool.h>

struct producto
{
    int cantindad;
    char nombre[10] ;
    char iva;
    float precio;
    char codigo[4];
};

void imprimir_catalogo(struct producto catalogo[20], int n);
void agregar_producto (struct producto catalogo[20], int n, char buscarCodigo[10], int i);
bool validar_producto (char buscarCodigo[10],struct producto catalogo[20], int n);
int main()
{
    //printf("Hello World");
    struct producto catalogo[5];
    int n=5;
    
    catalogo[0].codigo = "P001";
    catalogo[0].nombre = "Atun";
    catalogo[0].precio = 1.58;
    catalogo[0].iva = 's';
    
    catalogo[1].codigo = "p002";
    catalogo[1].nombre = "Panela";
    catalogo[1].precio = 0.58;
    catalogo[1].iva = 'n';
    
    catalogo[2].codigo = "p003";
    catalogo[2].nombre = "Avena";
    catalogo[2].precio = 0.85;
    catalogo[2].iva = 'n';
    
    catalogo[3].codigo = "p004";
    catalogo[3].nombre = "sal";
    catalogo[3].precio = 1.10;
    catalogo[3].iva = 'n';
    
    catalogo[4].codigo = "p005";
    catalogo[4].nombre = "Gelatina";
    catalogo[4].precio = 1.50;
    catalogo[4].iva = 's';
    
    char buscarCodigo[10];
    imprimir_catalogo(catalogo, n);
    
    printf("Codigo del producto a buscar: ");
    scanf("%s",buscarCodigo);
    
    bool encontrado = validar_producto(buscarCodigo,catalogo,n);
    
    if(encontrado == false)
    {
       printf("Codigo no encontrado: "); 
    }
    else
    {
        agregar_producto(catalogo,n);
    }
    

    return 0;
}
void imprimir_catalogo(struct producto catalogo[20], int n, int i)
{
    for(int i=0;i<n;i++)
    {
        printf("\n");
        printf("Codigo: %s", catalogo[i].codigo);
        printf(" Nombre: %s", catalogo[i].nombre);
        printf(" Precio: %0.2f", catalogo[i].precio);
        printf(" IVA: %c", catalogo[i].iva);
    }
}
void agregar_producto (struct producto catalogo[20], int n, char buscarCodigo[10])
{
    int i=0;
    char opcion='a';
    while(opcion != 's')
    {
        printf("\n");
        printf("cantidad: ");
        scanf("%d",catalogo[n].cantidad);
        
        
    }
    
}

bool validar_producto (char buscarCodigo[10],struct producto catalogo[20], int n)
{
    int pos=-1;
    bool encontrado= false;
    for(int i=0;i<n;i++)
    {
        if(catalogo[i].codigo == buscarCodigo)
        {
            encontrado = true;
            pos = i;
            
        }
    }
    if(encontrado == true)
    {
        return true;
    }
    return false;
}
