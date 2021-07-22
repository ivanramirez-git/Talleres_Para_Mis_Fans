// Your C++ Program

#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int main(){

    int v[20];

    srand(3);

    for(int i = 0; i<20; i++){
    	v[i]=rand() % 13 + 5;

    }

    cout<< (1 % 10 + 1) <<endl;
	cout<<"[ ";
    for(int i = 0; i<20; i++){
    	cout<<"| "<<v[i]<<" |";
    	
    }
    cout<<" ]"<<endl;

    //cout << "Hello World!";
    return 0;
}
