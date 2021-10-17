#include <iostream>
using namespace std;
int main(){
	int j=0;
	for(int i=0;i<=20;i++){
		if(i%2 != 0){
			j=j+i;		
		}
	}
	cout<<j<<endl;
	return 0;
}
