#include <iostream>
using namespace std;

int main(){
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
