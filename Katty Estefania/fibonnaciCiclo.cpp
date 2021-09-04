#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,n,ser,d;
	int f,a,b;
	printf ("Ingrese el numero de Fibonaccis que desea:  ");
	scanf (" %d" ,&n);
	a=0;
	b=1;
	for(i=1;i<=n;i++)
	{
		f=a+b;
		if(f%2!=0)
			printf( "%d  ",f);
		b=a;
		a=f;
	}
	return 0;

}
