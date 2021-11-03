#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>

using namespace std;

// Funcion f(x)=f(x) = e^x-x^2-x-1
double f(double x)
{
    return exp(x)-pow(x,2)-x-1;
}

void reglaFalsa(){
    double a=1;
    double b=2;
    double tol=0.00001;
    bool salida=true;

    while(salida){
        double h = -(b-a)/(f(b)-f(a))*f(a);
        cout << "a: " << a << " b: " << b << " h: " << h << endl;
        if(abs(h) < tol){
            salida=false;
        }
        a = a + h;
    }
}

// Funcion que pinta triangulo de pascal
void trianguloPascal(){
    int n, i, j;
    int arreglo[10][10];
    int suma;
    int nivel=10;
    int numero=1;

    for(i=0; i<nivel; i++){
        for(j=0; j<=i; j++){
            arreglo[i][j]=numero;
            numero=numero*(i-j)/(j+1);
        }
        numero=1;
    }

    for(i=0; i<nivel; i++){
        for(j=0; j<=i; j++){
            cout << arreglo[i][j] << " ";
        }
        cout << endl;
    };
}

void imprimirDiagonales(){
    int alturaIntroducida;
	int altura = 1;
	int i = 0;
	int espaciosInternos = 5 - 1;
	int espaciosDelantes = 0;
	
	if((5 < 3) || (5 % 2 == 0)){
		cout<<"Error";
	} else {
		while(altura < 5 / 2 + 1){
			for(i = 1; i <= espaciosDelantes; i++){
				cout<<" ";
			}
			cout<<"*";
			for(i = 1; i < espaciosInternos; i++){
				cout<<" ";
			}
			cout<<"*";
			cout<<""<<endl;
			altura++;
			espaciosDelantes++;
			espaciosInternos -= 2;
		}
		espaciosInternos = 0;
		espaciosDelantes = 5 / 2;
		altura = 1;
		while(altura <= 5 / 2 + 1){
			for(i = 1; i <= espaciosDelantes; i++){
				cout<<" ";
			}
			cout<<"*";
			for(i = 1; i < espaciosInternos; i++){
				cout<<" ";
			}
			if(altura>1){
				cout<<"*";
			}
			cout<<""<<endl;
			altura++;
			espaciosDelantes--;
			espaciosInternos+=2;
		}
	}
}

void numeroMayor(int vector[], int n){
    printf("El numero mayor es:");
    //Imprimir numero mayor
    int mayor=0;
    for(int i = 0; i < n; i++){
        if(mayor < vector[i]){
            mayor = vector[i];
        }
    }
    printf("%d\n", mayor);
                
}

void numeroMenor(int vector[], int n){
    printf("El numero menor es:");
    //Imprimir numero menor
    int menor=100;
    for(int i = 0; i < n; i++){
        if(menor > vector[i]){
            menor = vector[i];
        }
    }
    printf("%d\n", menor);
}

void imprimirCantidades(int vector[], int n){
    printf("La cantidad de 1,2...10 es: ");
                //Imprimir cantidad de 1,2...10
                int cantidad[10] = {0};
                //La cantidad de 1,2...10 es la cantidad de veces que aparece el numero en el vector
                for(int i = 0; i < n; i++){
                    if(vector[i] == 1){
                        cantidad[0]++;
                    }
                    if(vector[i] == 2){
                        cantidad[1]++;
                    }
                    if(vector[i] == 3){
                        cantidad[2]++;
                    }
                    if(vector[i] == 4){
                        cantidad[3]++;
                    }
                    if(vector[i] == 5){
                        cantidad[4]++;
                    }
                    if(vector[i] == 6){
                        cantidad[5]++;
                    }
                    if(vector[i] == 7){
                        cantidad[6]++;
                    }
                    if(vector[i] == 8){
                        cantidad[7]++;
                    }
                    if(vector[i] == 9){
                        cantidad[8]++;
                    }
                    if(vector[i] == 10){
                        cantidad[9]++;
                    }
                }
                //Imprimir cantidad de 1,2...10 con porcentaje
                printf("\n");
                for(int i = 0; i < 10; i++){
                    printf("%d: Cantidad: %d, Porcentaje: %.2f%%\n", i+1, cantidad[i], (float)cantidad[i]/n*100);
                }
}

void mediaAritmetica(int vector[], int n){
    printf("La media aritmetica es: ");
    //Imprimir media aritmetica
    float media = 0;
    for(int i = 0; i < n; i++){
        media += vector[i];
    }
    media = media / n;
    printf("%f\n", media);
}
// Aleatorios
void imprimirAleatorios(){
    srand(time(NULL));

    int n;
    char opcion='a';

    // Se pide el numero de intentos
    printf("cuantos numeros aleatorios genero: ");
    scanf("%d", &n);

    //Vector de enteros para almacenar numeros aleatorios
    int *vector = (int*)malloc(n * sizeof(int));

    //Generar numeros aleatorios
    for (int i = 0; i < n; i++) {
        vector[i] = (rand() % 99) + 1;
    }
        
    // Menu que se repite switch case
    while(opcion != 'f'){
        // Imprimir menu
        printf("(a) mostrar los datos generados\n(b) numero mayor\n(c) numero menor\n(d) media aritmetica\n(e) cantidad de 1,2...10 y sus porcentajes\n(f) salir\n");
        // escanear opcion
        scanf(" %c", &opcion);
        
        switch(opcion){
            case 'a':
                printf("Los datos generados son:\n");
                //Imprimir numeros aleatorios
                for (int i = 0; i < n; i++) {
                    printf("%d\n", vector[i]);
                }   
                break;
            case 'b':
                // Imprimir numero mayor
                numeroMayor(vector, n);
                break;

            case 'c':
                //Imprimir numero menor
                numeroMenor(vector, n);

                break;
            case 'd':
                // Imprimir media aritmetica
                mediaAritmetica(vector, n);

                break;
            case 'e':
                // Imprimir cantidad de 1,2...10 y sus porcentajes
                imprimirCantidades(vector, n);
                break;
            case 'f':
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }
}

int main()
{
    cout<<".:: Bienvenidx ::."<<endl;
    int opcion;
    
    while(opcion!=0){
        cout<<"1. Metodo regla falsa"<<endl;
        cout<<"2. Triangulo de pascal"<<endl;
        cout<<"3. Diagonales"<<endl;
        cout<<"4. Aleatorios"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        cout<<endl;
        switch(opcion){
            case 1:
                // Regla falsa
                reglaFalsa();
            break;

            case 2:
                // Triangulo de pascal apuntado a la izquierda
                trianguloPascal();
            break;

            case 3:
                // Diagonales
                imprimirDiagonales();
            break;
            case 4:
                // Aleatorios
                imprimirAleatorios();
                break;
            case 0:
                cout<<"Adios"<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }    
    return 0;
}