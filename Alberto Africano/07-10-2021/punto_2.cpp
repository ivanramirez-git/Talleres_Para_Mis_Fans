#include < iostream >
#include < stdio.h >
#include < complex >
using namespace std ;

// definicion de una funcion inline para calcular minimo entre a y b

inline int minimo (int a , int b ) {
	int n ;
	if(a < b ) {
		n = a ;
	}
	else {
		n = b ;
	}
	return n ;
}

int x ,y , z ;

int main () {
	cin>> x;
	cin>> y;
	z = minimo (x , y ) ;
		cout < <"el valor minimo es " <<z < < endl ;
	}
system ( pause ) ;
}
