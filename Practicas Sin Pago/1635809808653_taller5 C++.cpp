#include <iostream>

using namespace std;                        

float division(float a,float b){
	float c=0;
	if(b>0){
		c=a/b;	
	}else
		c=0;
	return c;	
}

void programa1(){
	float a,b,res;
	cout<<"POR FAVOR DIGITE EL PRIMER VALOR:";
	cin>>a;
	cout<<"POR FAVOR DIGITE EL SEGUNDO VALOR:";
	cin>>b;
	res=division(a,b);
	cout<<"EL RESULTADO DE LA DIVISION ES:"<<res<<endl;

}//FIN PROGRAMA 1

void programa2(){
	int numeros[10];
	for(int i=0;i<10;i++){
		cout<<"DIGITE UN NUMERO:";
		cin>>numeros[i];
	}
	for(int i=0;i<10;i++){
		if(numeros[i]>99){
			cout<<"EL NUMERO "<<numeros[i]<<" ESTA EN EL INDICE "<<i<<endl;
		}
	}

}//FIN PROGRAMA 2

void programa3(){
	int numeros[10],promedio=0;
	for(int i=0; i<10; i++){
		cout<<"NUMERO ["<<i<<"]: ";
		cin>>numeros[i];
		
	}//PRIMER FOR
	//PROMEDIO
	for(int i=0; i<10; i++)
		promedio+=numeros[i];
		
	promedio=promedio/10;
	
	cout<<endl<<"EL PROMEDIO ES: "<<promedio<<endl;

	for(int i=0; i<10; i++)
		if (promedio==numeros[i])
			cout<<"EL PROMEDIO SE ENCUENTRA EN EL VECTOR"<<endl;
}//FIN PROGRAMA 3

string invertir(string cadena)
{
    int i,j,tam;
    string invertida;
    tam=cadena.length();
    for(i=tam-1;i>=0;i--)
    {
        invertida=invertida+cadena[i];
    }
    return invertida;
}
    
string vacio(string cadena){
	
	int i,tam;
	tam=cadena.length();
	if(tam==0)	
	{
		cout<<"LA CADENA ESTA VACIA"<<endl;	
	}//IF
	else{
		cout<<"LA CADENA INVERTIDA ES: "<<invertir(cadena)<<endl;	
	}//ELSE
	return cadena;
}//STRING VACIO

void programa4(){
	int  i,j,tam;
	string cadena;
	cout<<"DIGITE UNA CADENA: ";
	cin>>cadena;
	vacio(cadena);	
}//FIN PROGRAMA 4

void programa5(){
	cout<<"HASTA PRONTO..."<<endl;
	exit(0);
}//FIN PROGRAMA 5


int main(){
	int opcion=0;

	do{
	cout<<"1. DIVISION."<<endl;
	cout<<"2. POSICIONES CON NUMEROS CON MAS DE TRES DIGITOS."<<endl;
	cout<<"3. PROMEDIO ENTERO DE DATOS."<<endl;
	cout<<"4. CAPTURA DE CADENA."<<endl;
	cout<<"5. SALIR."<<endl<<endl;
	cout<<"POR FAVOR DIGITE SU OPCION--->";
	cin>>opcion;
	switch(opcion){
		case 1:
				programa1();	     
			break;
		case 2:
				programa2();
			break;
		case 3:
				programa3();
			break;
		case 4:
				programa4();
			break;
		case 5:
			programa5();
			break;
		}//switch

	}while(opcion!=5);
}