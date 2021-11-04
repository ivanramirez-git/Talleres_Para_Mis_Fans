#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    float x[50],y[50],z,l, valor=0;
int n;

cout<<"ingrese el numero de elementos: "; cin>>n;
 cout<<"ingrese x: ";

for(int i=0; i<n; i++){
 cin>>x[i];
}

      cout<<endl;
cout<<"ingrese y: ";
for(int i=0; i<n; i++){
              cin>>y[i];

}
  cout<<endl;

cout<<endl<<"ingrese z: "; cin>>z;

 for(int i=0; i<n ;i++){
        l=y[i];
        for(int j=0; j<n; j++){
          if(i!=j){
             l=(l*(z-x[j]))/(x[i]-x[j]);
            }
        }
       valor=valor+l;
 }

 cout<<endl<<endl<<"El valor al polinomio de interpolacion en Z = "<<z<<" es : "<< valor<<endl;
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
