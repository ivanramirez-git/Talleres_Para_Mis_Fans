#include <iostream>

using namespace std;

string informacion[4][4]={
   {"Ivan Rene", "22", "Secundaria", "Casado"},
   {"Uziel Jose", "17", "Primaria", "Soltero"},
   {"Rene Ramirez", "48", "Primaria", "Casado"},
   {"Estela Castro", "38", "Secundaria", "Casado"}
};

void cargarInformacion(){

   string entrada, texto;


   for(int i=0;i<4;i++){
      for(int j=0; j<4; j++){
         if(j==0){
            cout<<"Ingrese el nombre de la "<<i+1<<" persona: ";
            cin>>entrada;
            texto=entrada;
            cout<<"Ingrese el apellido de la "<<i+1<<" persona: ";
            cin>>entrada;
            texto= texto+ " " + entrada;

            informacion[i][j]=texto;
         }
         if(j==1){
            
            while(true){
               cout<<"Ingrese la edad de la "<<i+1<<" persona:";
               cin>>entrada;

               if(atoi(&entrada[0])>0){
                  informacion[i][j]=entrada;
                  break;
               }else{
                  cout<<"Por favor ingrese una edad valida.";
               }
            }
         }
         if(j==2){
            cout<<"Ingrese su nivel educativo (Primaria, Secundaria, Superior, Posgrado) :";
            cin>>entrada;
            informacion[i][j]=entrada;
         }
         if(j==3){
            cout<<"Ingrese su estado civil (Soltero, Casado, Viudo, Divorciado) :";
            cin>>entrada;
            informacion[i][j]=entrada;
         }
      }
   }
}


void EstCivilCasado(){
   for(int i = 0; i<4; i++){
      if(informacion[i][3]=="Casado"){

         cout<<"Nombre: "<<informacion[i][0]<<endl;
         cout<<"Edad: "<<informacion[i][1]<<endl;
         cout<<"Nivel educativo: "<<informacion[i][2]<<endl;
         cout<<"Estado civil: "<<informacion[i][3]<<endl;

      }
   }
}


void EduSecundaria(){

   for(int i = 0; i<4; i++){
      if(informacion[i][2]=="Secundaria"){

         cout<<"Nombre: "<<informacion[i][0]<<endl;
         cout<<"Edad: "<<informacion[i][1]<<endl;
         cout<<"Nivel educativo: "<<informacion[i][2]<<endl;
         cout<<"Estado civil: "<<informacion[i][3]<<endl;

      }
   }
   
}

int MayorEdad(){
   int contador=0;
   for(int i = 0; i<4; i++){
      //cout<<"SSS: "<<atoi(&informacion[i][1][0]);
      if( atoi(&informacion[i][1][0]) >= 18){
         contador++;
      }
   }
   return contador;   
}



int main(){

   cout<<"Cargar informacion."<<endl;
   //cargarInformacion();
   char opcion;
   do{
      cout<<".:: Menu ::."<<endl;
      cout<<"1. Mostrar toda la información de la(s) persona(s) con estado civil de casado. "<<endl;
      cout<<"2. Mostrar toda la información de la(s) persona(s) que tengan un nivel educativo secundaria."<<endl;
      cout<<"3. Mostrar la cantidad de la(s) persona(s) que son mayores de edad."<<endl;
      cout<<"4. Salir"<<endl;
      cin>>opcion;

      switch(opcion){

         case '1':
            EstCivilCasado();
         break;
         case '2':
            EduSecundaria();
         break;
         case '3':
            cout<<"Las personas mayores de edad son: "<<MayorEdad()<<" personas."<<endl;
         break;
         case '4':
            return 0;
         break;
      }
   }while(true);

	return 0;
}