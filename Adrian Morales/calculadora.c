// Calculadora para calcular la suma, resta y multiplicacion de numeros binarios, decimal y morse.
#include "biblioteca.h"

// Pruebas
void prueba1()
{

    int i;

    // binario a decimal
    char bin1[] = "10101010";
    char bin2[] = "10101011";
    char bin3[] = "10101000";

    int dec1[1];
    int dec2[1];
    int dec3[1];

    // binario a decimal
    btod(bin1, dec1);
    printf("bin1: %s a decimal: %d\n", bin1, dec1[0]);

    btod(bin2, dec2);
    printf("bin2: %s a decimal: %d\n", bin2, dec2[0]);

    btod(bin3, dec3);
    printf("bin3: %s a decimal: %d\n", bin3, dec3[0]);

    // decimal a binario
    dec1[0] = 10;
    dec2[0] = 255;
    dec3[0] = 13157;

    char bin4[8] = "";
    char bin5[8] = "";
    char bin6[8] = "";

    dtob(dec1, bin4);
    printf("dec1: %d a binario: %s\n", dec1[0], bin4);

    dtob(dec2, bin5);
    printf("dec2: %d a binario: %s\n", dec2[0], bin5);

    dtob(dec3, bin6);
    printf("dec3: %d a binario: %s\n", dec3[0], bin6);

    // morse a decimal
    char morse1[] = ".____.....";
    char morse2[] = "..___.....";
    char morse3[] = "..___...__....._____.____";

    int morse1dec[1];
    int morse2dec[1];
    int morse3dec[1];

    // morse a decimal
    mtod(morse1, morse1dec);
    printf("morse1: %s a decimal: %d\n", morse1, morse1dec[0]);

    mtod(morse2, morse2dec);
    printf("morse2: %s a decimal: %d\n", morse2, morse2dec[0]);

    mtod(morse3, morse3dec);
    printf("morse3: %s a decimal: %d\n", morse3, morse3dec[0]);

    // decimal a morse
    morse1dec[0] = 10;
    morse2dec[0] = 23;
    morse3dec[0] = 23501;

    char morse4[30];
    char morse5[30];
    char morse6[30];

    dtom(morse1dec, morse4);
    printf("dec1: %d a morse: %s\n", morse1dec[0], morse4);

    dtom(morse2dec, morse5);
    printf("dec2: %d a morse: %s\n", morse2dec[0], morse5);

    dtom(morse3dec, morse6);
    printf("dec3: %d a morse: %s\n", morse3dec[0], morse6);
}

// Recibe un comando de operacion y lo ejecuta, retorna el resultado en decimal
int operacion(char comando[])
{
    /*
        Ejemplo:
        B101+M.....-D2
    */

    int resultado = 0;
    int operandos[10];
    int numeroOperandos = 0;
    char operadores[10];
    int numeroOperadores = 0;

    int i = 0;
    for (i = 0; i < strlen(comando); i++)
    {

        if (toupper(comando[i]) == 'B')
        {
            
            // Copiar hasta que encuentre un operador +, -, *, /
            int j = i;
            while (comando[j] != '+' && comando[j] != '-' && comando[j] != '*' && comando[j] != '/')
            {
                j++;
            }
            j--;
            // Copiar el valor del binario
            char binario[j - i + 1];
            strncpy(binario, &comando[i + 1], j - i);
            binario[j - i] = '\0';
            // Convertir el binario a decimal
            int decimal[1];
            btod(binario, decimal);
            // Guardar el resultado en el arreglo de operandos
            operandos[numeroOperandos] = decimal[0];
            numeroOperandos++;
            i = j;
        }
        else if (toupper(comando[i]) == 'M')
        {
            // Copiar hasta que encuentre un operador +, -, *, /
            int j = i;
            while (comando[j] != '+' && comando[j] != '-' && comando[j] != '*' && comando[j] != '/')
            {
                j++;
            }
            j--;
            // Copiar el valor del morse
            char morse[j - i + 1];
            strncpy(morse, &comando[i + 1], j - i);
            morse[j - i] = '\0';
            // Convertir el morse a decimal
            int decimal[1];
            mtod(morse, decimal);
            // Guardar el resultado en el arreglo de operandos
            operandos[numeroOperandos] = decimal[0];
            numeroOperandos++;
            i = j;
        }
        else if (toupper(comando[i]) == 'D')
        {
            // Copiar hasta que encuentre un operador +, -, *, /
            int j = i;
            while (comando[j] != '+' && comando[j] != '-' && comando[j] != '*' && comando[j] != '/')
            {
                j++;
            }
            j--;
            // Copiar el valor del decimal
            char decimal[j - i + 1];
            strncpy(decimal, &comando[i + 1], j - i);
            decimal[j - i] = '\0';
            // Convertir el decimal a decimal
            int decimal2[1];
            dtod(decimal, decimal2);
            // Guardar el resultado en el arreglo de operandos
            operandos[numeroOperandos] = decimal2[0];
            numeroOperandos++;
            i = j;
        }
        else if (comando[i] == '+' || comando[i] == '-' || comando[i] == '*' || comando[i] == '/')
        {
            // Guardar el operador en el arreglo de operadores
            operadores[numeroOperadores] = comando[i];
            numeroOperadores++;
        }

        // Si llegamos al final del comando, terminamos
        if (i == strlen(comando) - 1)
        {
            break;
        }
    }

    // Ejecutar operaciones
    int j = 0;
    for (j = 0; j < numeroOperadores; j++)
    {
        if (operadores[j] == '+')
        {
            resultado = operandos[j] + operandos[j + 1];
        }
        else if (operadores[j] == '-')
        {
            resultado = operandos[j] - operandos[j + 1];
        }
        else if (operadores[j] == '*')
        {
            resultado = operandos[j] * operandos[j + 1];
        }
        else if (operadores[j] == '/')
        {
            resultado = operandos[j] / operandos[j + 1];
        }
    }

    return resultado;
}

// interprete de comandos
/*
    B: Binario
    M: Morse
    D: Decimal
    RES: Resultado
    Q: Salir
    +,_,*,/: Operaciones

    Ejemplo:
    B101+M.....
    RESD
    10
*/
void interprete()
{
    char comando[30];
    int decimal[1];
    char binario[8];
    char morse[30];

    do
    {
        printf("\n> ");
        scanf("%s", comando);
        switch (comando[0])
        {
        case 'B':
        case 'M':
        case 'D':
            // Operaciones
            decimal[0] = operacion(comando);
            break;
        case 'R':
            // mostrar resultado
            // Ejemplo:
            // RESD
            // 10
            switch (toupper(comando[3]))
            {
            case 'B':
                // Convertir el resultado a binario
                dtob(decimal, binario);
                printf("%s\n", binario);
                break;
            case 'M':
                // Convertir el resultado a morse
                dtom(decimal, morse);
                printf("%s\n", morse);
                break;
            case 'D':
                // Convertir el resultado a decimal
                printf("%d\n", decimal[0]);
                break;
            }
            break;
        case 'Q':
            // salir
            return;
            break;
        default:
            // comando invalido
            break;
        }
    } while (1 == 1);
}

// Funcion principal
int main()
{
    prueba1();
    interprete();
    return 0;
}
