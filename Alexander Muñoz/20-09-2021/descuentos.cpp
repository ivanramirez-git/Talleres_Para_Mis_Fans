#include <iostream>

using namespace std;

int main(){
	float compra;
	cout<<"Ingrese el valor de la compra: ";
	cin>>compra;
	
	if(compra >= 20000 && compra < 100000){
		cout<<"Su descuentos es del 20%\nTotal: "<<compra*0.8<<endl;
	}else if(compra >= 100000 && compra < 300000){
		cout<<"Su descuentos es del 20%\nTotal: "<<compra*0.6<<endl;
	}else if(compra > 300000){
		cout<<"Su descuentos es del 20%\nTotal: "<<compra*0.5<<endl;
	}else{
		cout<<"Su compra no tiene descuentos\nTotal: "<<compra<<endl;
	}
	return 0;
}
