#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
struct dato{
	string ncel;
	string cedula;
	string clave;
	string email;
	long saldo;
};
int verif(dato datos[],int tam){
	for(int i=0;i<tam;i++){ 
	if(
	datos[i].cedula==""&&
	datos[i].ncel==""  &&
	datos[i].email=="" &&
	datos[i].clave=="" &&
	datos[i].saldo==0
	){return i;}
	}//for
	return 1000;
}//verif
bool rpta(string res){
	fflush(stdin);
	cout<<"DESEA CREAR UNA CUENTA?:  ";
		getline(cin,res);
	if(res=="si"||res=="SI"){
		return true;
	}else{
		return false;
	 }//else
}//rpta
bool validar(string clave){
	int longitud,i;
	bool t=true;
	longitud=clave.size();
	for(i=0;i<longitud;i++){
		if(clave[i]<48|| clave[i]>57){
			t=false;break;
		}//if
}//for
return t;
}//validar
string recibirClave(){
	int cantletras;
	bool comprob=true,respuesta;
	char a[50];
	// a vacio
	for(int i=0;i<50;i++){
		a[i]='\0';
	}//for
	string clave;
	cout<<"DIGITE SU CLAVE: ";
	cantletras=1;
do{
	cin>>a;
	cout<<"*";
	clave+=a;
	cantletras++;
	if(cantletras==5){
		comprob=validar(clave);
		if(comprob==false){
			cantletras=1;
			system("cls");
			cout<<"DIGITE NUEVAMENTE LA CLAVE..."<<endl;
			/*clave="";*/
		}//ifcomprob
	}//ifcantletras
}while(cantletras<=4||comprob==false);
return clave;
}//recibirClave
void crearCuenta(dato datos[], int tam){
 int pos;
 pos=verif(datos,tam);
 if(pos<tam){
 for( int i; i<=pos; i++){
 	
	cout<<"INGRESE SU NUMERO DE CEDULA: ";
	fflush(stdin);
 	getline(cin,datos[i].cedula);
 	cout<<"INGRESE SU EMAIL ";
 	fflush(stdin);
 	getline(cin,datos[i].email);
 	cout<<"INGRESE SU NUMERO DE CELULAR ";
 	getline(cin,datos[i].ncel);
	//datos[i].clave;
	datos[i].saldo=0;
	cout<<endl;
 }//for
}//if

 /*	cout<<"INGRESE CEDULA: ";
 	fflush(stdin);
 	getline(cin,datos[pos].cedula);
 	cout<<"INGRESE SU EMAIL ";
 	fflush(stdin);
 	getline(cin,datos[pos].email);
 	cout<<"INGRESE SU NUMERO DE CELULAR ";
 	getline(cin,datos[pos].ncel);*/
 	 	 	
 cout<<endl;
 return;
}//crearCuenta
void guardarArchivo(dato datos[],int tam){


	ofstream fs("datos.txt");
	for(int i=0; i< tam;i++){
		
		fs << datos[i].cedula<< " ";
		fs << datos[i].email << " ";
		fs << datos[i].ncel  << " ";
	/*	fs << datos[i].clave << " ";*/
		fs << datos[i].saldo << "\n";
                    
	}
	fs.close();
}//guardarArchivo
void leerArchivo(dato datos[],int tam){
	ifstream lectura; int lineas=0;
	string cedula;string ncel;string email;//string clave;	
	lectura.open("datos.txt", ios::in);
	if(!lectura){
		cout<<"EL ARCHIVO NO EXISTE "<<endl;
	}else{
		while(lectura.good()){if (lectura.get()=='\n')lineas++;}//if
		lectura.close();
		lectura.open("datos.txt", ios::in);
		int i=0;
		while(!lectura.eof()&&i<lineas){
			lectura >> cedula;
		/*	char *res = new char[cedula.size() + 1];
			copy(cedula.begin(), cedula.end(), res);*/
			datos[i].cedula = cedula;
			lectura >> email;
			datos[i].email = email;
			lectura >> ncel;
		/*	char *res3 = new char[ncel.size() + 1];
			copy(ncel.begin(), ncel.end(), res3);*/
			datos[i].ncel = ncel;
			/*lectura >> clave;
			datos[i].clave= clave;*/
			i++;
		}//while
			
	}//else
	lectura.close();//archivo cerrado
}//leerArchivo
//-----------------------------------
void listar(dato inf[],int tam){
 for(int i=0; i<tam; i++){
 	cout<<"CEDULA: "<<inf[i].cedula<<"\t";
 	cout<<"NUMERO DE CELULAR: "<<inf[1].ncel<<"\t";
 	cout<<"EMAIL: "<<inf[i].email<<endl;
 	//cout<<"CLAVE: "<<inf[1].clave<<endl;
 	cout<<"SALDO: "<<inf[i].saldo<<endl;
 }//for
}//listar
//-----------------------------------
bool claveCorrecta(dato datos[],int tam){
	string c;
	int i=0;
	cout<<"INGRESE CEDULA: ";
	fflush(stdin);
	getline(cin,c);
/*for(int i=0; i<tam;i++){
	if(c==datos[i].cedula){return true;}//if

if(c!=datos[i].cedula){return false;}
}//for*/

do{
if(c!=(datos[i].cedula)){
		i++;
		cout<<i;
		system("pause");
  }//false
  //listar(datos,tam);
 if(c==(datos[i].cedula)){
		return true;
 } 
}while(i==true);

return false;

}//claveCorrecta



/*
El cliente constantemente realizara retiros, el sistema debe solicitar el numero de cuenta y el password,
del cliente, esto con el objetivo de validar los datos.
Despues se debe verificar que el valor a retirar sea menor que el saldo existente en la cuenta, considerando 
que el costo de la transaccion es de 2000.
En caso que el saldo sea menor al valor a retirar mas el costo de la transaccion, se debe mostrar un mensaje
al usuario que diga "Fondos insuficientes".
*/

//Funcion que realiza un retiro
void retiro(dato datos[],int tam){
	string c;
	int i=0;
	cout<<"INGRESE CEDULA: ";
	fflush(stdin);
	getline(cin,c);
	do{
	if(c!=(datos[i].cedula)){
		i++;
		cout<<i;
		system("pause");
  }//false
  //listar(datos,tam);
 if(c==(datos[i].cedula)){
		break;
 }
}while(i==true);

	cout<<"INGRESE SU CLAVE: ";
	string clave;
	fflush(stdin);
	getline(cin,clave);
	if(clave==datos[i].clave){
		cout<<"INGRESE EL VALOR A RETIRAR: ";
		int valor;
		cin>>valor;
		if(valor<=datos[i].saldo){
			datos[i].saldo=datos[i].saldo-valor-2000;
			cout<<"SALDO ACTUAL: "<<datos[i].saldo<<endl;
		}else{
			cout<<"FONDOS INSUFICIENTES"<<endl;
		}//if
	}else{
		cout<<"CLAVE INCORRECTA"<<endl;
	}//if
}//retiro
//-----------------------------------
//Funcion que realiza un deposito




int main(){
	int tam=1000;
	dato datos[tam];
	int opcion=0;
	verif(datos,tam);
	leerArchivo(datos,tam);
	
do{
	system("cls");
	cout << "1. CREACION DE UNA CUENTA. " << endl;
	cout << "2. INICIAR SESION."<<endl;
	cout <<	"ELIJA LA OPCION: ";
	cin>>opcion;
switch(opcion){
case 1:{
	system("cls");
	string res;
	cout<<"1. CREAR CUENTA..."<<endl;
 if(rpta(res)==true){
	crearCuenta(datos,tam);
	guardarArchivo(datos,tam);
	cout<<"CUENTA CREADA SATISFACTORIAMENTE"<<endl;
	}else{
	cout<<"VOLVIENDO AL MENU...";
	system("pause");
	break;
}//else	
break;
}//case1
case 2:{
	system("cls");
	cout<<"2. INICIAR SESION..."<<endl;
	long long c=0;
	int op=0;
if(claveCorrecta(datos,tam)==true){
do{
	system("cls");
	cout << "1. CONSIGNACIONES. " << endl;
	cout << "2. CONSULTAS DE SALDO. " << endl;
	cout << "3. RETIROS. " << endl;
	cout << "4. INSCRIBIR PAGOS. " << endl;
	cout << "5. PAGOS. " << endl;
	cout << "6. CANCELACION DE LA CUENTA. " << endl;
	cout << "7. SALIR. " << endl;
	cout << "QUE OPCION DESEA REALIZAR? ";
	cin >> op;
	fflush(stdin);
switch(op){
case 1:{
	cout<<"SE LOGRO"<<endl;
	system("pause");
	break;
}//case1
}//switch
}while(op>=1&&op<9);
	break;
	
}else{
	cout<<"USUARIO NO EXISTENTE\n";
	system("pause");
break;
}//else
 
}//case2
}//switch
}while(opcion>=1&&opcion<=2);		
}//main 




























