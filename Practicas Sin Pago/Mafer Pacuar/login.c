#include <stdio.h>
#include <string.h>

// funcion recursiva que lea un usuario y contraseña y haga el inicio de sesion y muestre las credenciales
void login(char user[], char pass[], int flag[]) 
{
    // si el flag es 0, entonces se lee el usuario
    if (flag[0] == 0) 
    {
        printf("Usuario: ");
        scanf("%s", user);
        printf("\n");
        printf("Contraseña: ");
        scanf("%s", pass);
        flag[0] = 1;
        login(user, pass, flag);
    }
    // si el flag es 1, entonces se lee la contraseña
    else if (flag[0] == 1) 
    {
        printf("Contrasena: ");
        scanf("%s", pass);
        flag[0] = 2;
        login(user, pass, flag);
    }
    // si el flag es 2, entonces se hace el inicio de sesion
    else if (flag[0] == 2) 
    {
        if (strcmp(user, "admin") == 0 && strcmp(pass, "admin") == 0) 
        {
            printf("Bienvenido %s\n", user);
        }
        else 
        {
            printf("Usuario o contraseña incorrectos\n");
            flag[0] = 0;
            login(user, pass, flag);
        }
    }
}

int main() 
{
    char user[20];
    char pass[20];
    int flag[1] = {0};
    login(user, pass, flag);
    return 0;
}