#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
	int i,n,c,j,k,f,r,a,b,opcion;
	float talla[n],peso[n],s,aux,sum; 
	string nombre[n];
	printf("\n ingrese un aopcion\n ");
	printf( "\n 1=media(ARITMETICA,GEOMETRICA,ARMONICA) \n ");printf( "\n 2=moda\n  ");printf( "\n 3=mediana\n  ");printf( "\n 4=Varianza y DESVIACION ESTANDAR \n ");
	printf( "\n 5=COEFICIENTE DE PERSON \n ");scanf("\n  %d",&opcion);
	switch (opcion)
	{
case 1:
	{
		    int op;
			printf("\ningrese el tipo de media ");printf("\n1=MEDIA ARITMETICA");
			printf("\n2=MEDIA GEOMETRICA");printf("\n3=MEDIA ARMONICA");scanf("%d",&op);
			switch (op)
			{
			case 1:
				{
				printf("\n ingrese la dimension del vector : ");scanf("%d",&n);
    			s=0;
				c=0;
				sum=0;
				for(i=0;i<=n-1;i=i+1)
				{
				printf("\n ingrese el nombre (%d) :",i);scanf("%s",&nombre[i]);	
				printf("\ningrese el talla (%d) : ",i);scanf("%f",&talla[i]);
				printf("\ningrese el peso (%d) : ",i);scanf("%f",&peso[i]);
				printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
	   		 	s=s+talla[i];
        		c=c+1;
        		sum=sum+peso[i];
				}
				printf("\nla media del peso es: %f",sum/c);
				printf("\nla media del talla es: %f", s/c);
				printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
				for(k=0;k<=n-1;k=k+1)
				{
					for(j=0;j<n-1;j=j+1)
					{
             			if(talla[k]>talla[j])
             			{
             				aux=talla[k];
             				talla[k]=talla[j];
             				talla[j]=aux;	
			 			}
			   			if(peso[k]>peso[j])
             			{
             			aux=peso[k];
             			peso[k]=peso[j];
             			peso[j]=aux;	
			 			}
					}
				}
			printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
			for(f=0;f<=n-1;f=f+1)
			{
			 printf("\ntalla posicion (%d) es : %0.2f\n",f,talla[f]);
			}
			printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
			for(r=0;r<=n-1;r=r+1)
			{
			 printf("\npeso posicion (%d) es : %0.2f\n",r,peso[r]);
			}
		}
		case 2:
		{
			float m,mp,mgtalla,mgpeso;
				printf("\n ingrese la dimension del vector : ");scanf("%d",&n);
				m=1;
				mp=1;
				
			for(i=0;i<=n-1;i=i+1)
			{
			printf("\n ingrese el nombre (%d) :",i);scanf("%s",&nombre[i]);	
			printf("\ningrese el talla (%d) : ",i);scanf("%f",&talla[i]);
			printf("\ningrese el peso (%d) : ",i);scanf("%f",&peso[i]);
			printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
			m=talla[i]*m;
			mp=peso[i]*mp;
			}
			mgtalla=pow(m,1.0/n);
			mgpeso=pow(mp,1.0/n);
			printf("\nla media GEOMETRICA del talla es: %f",mgtalla);
			printf("\nla media  GEOMETRICA del peso  es: %f", mgpeso);
			printf("\n<::::::::::::::::::: ::::::::::::::::::::::::::::>\n");
			break;
		}
		case 3:
			{
				float mt,su,sup,mp,mhp,mht;
				printf("\n ingrese la dimension del vector : ");scanf("%d",&n);
			
				su=0;
				sup=0;
			for(i=0;i<=n-1;i=i+1)
			{
			printf("\n ingrese el nombre (%d) :",i);scanf("%s",&nombre[i]);	
			printf("\ningrese el talla (%d) : ",i);scanf("%f",&talla[i]);
			printf("\ningrese el peso (%d) : ",i);scanf("%f",&peso[i]);
			printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
			mt=1.0/talla[i];
			su=su+mt;
			mp=1.0/peso[i];
			sup=sup+mp;
			}
			mht=n/su;
			mhp=n/sup;
			printf("\nla media ARMONICA del talla es: %f",mht);
			printf("\nla media  ARMONICA del peso  es: %f", mhp);
			printf("\n<::::::::::::::::::: ::::::::::::::::::::::::::::>\n");
			break;
			break;	
			}
			
		default:
		{
		printf("\nERROR");	
		}
    	break;
	 }
	}
case 2:
	{
	printf("\npeso posicion ");	
	}
    break;
case 8:
	{
		int ii,n,a,b,tt,cont,t_mayor,p_mayor;
	float moda_talla,moda_peso,talla[n],peso[n];
	string nombre[n];
	printf("\n ingrese la dimension del vector : ");scanf("%d",&n);
	for(ii=0;ii<=n-1;ii=ii+1)
	{
	printf("\ningrese el talla (%d) : ",ii);scanf("%f",&talla[ii]);
	printf("\ningrese el peso (%d) : ",ii);scanf("%f",&peso[ii]);
	printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
    }
    tt=0;t_mayor=0;cont=0;p_mayor=0;
	for(a=0;a<=n-1;a=a+1)
	{
		for(b=0;b<n-1;b=b+1)
		{
             if(talla[a]==talla[b] && a!=b)
             {
             	tt=tt+1;	
			 }
			 
			    if(peso[a]==peso[b]&& a!=b)
             	{
            		cont=cont+1;
				}
		}
			if(tt>t_mayor)
			{
			t_mayor=tt;
			moda_talla=talla[a];
			}
			tt=0;		
			if(cont>p_mayor)
			{
			p_mayor=cont;
			moda_peso=peso[a];
	  		}
			cont=0;
	}
	printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
	if(t_mayor==0)
	{
		printf("\n NO EXISTE MODA DE LA TALLA\n ");
	} else
	{
		printf("\n LA MODA DE LA TALLA ES : %0.2f",moda_talla);	
	}
	if(p_mayor==0)
	{
		printf("\n NO EXISTE MODA DEL PESO\n ");
	} else
	{
		printf("\n LA MODA DEL PESO ES : %0.2f",moda_peso);
	}
	printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");	
	break;
	}
	case 3:
	{
		printf("\nMEDIANA \n")	;
			int n,aux,x;
	cout<<"ingrese el numero de elementos: ";
	cin>>n;
	int array[n];
	for (int i=0; i<n;i=i+1)
	{
		cout<<"ingrese el elememto ["<<i<<"] : ";
		cin>>array[i];
	}
	for(int i=0;i<n;i=i+1)
	{
		for(int j=0; j<n-1;j=j+1)
		{
			if(array[j]>array[j+1])
			{
				aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
			}
		}
	}
	cout<<"\narreglo ordenado de manera ascendete "<<endl;
	for ( x=0; x<n;x=x+1)
	{
		cout<<array[x]<<" ";	
	}
	cout<<"\nla mediana es: ";
	if (n%2 !=0) // impar
	{
		cout<<array[n/2]<<endl;
	}
	else
	{
	cout<<(array[n/2]+array[(n/2)-1])*1.0/2<<endl;	
	}
	break;
		
	}
	case 4:
	{
			int c,i,j,n;
	float talla[n],peso[n],sum,s,suma,t,q,rp,rt,fio,v;
	float qq,vv,fio2,suma_talla,tt;
	string nombre[n];
	printf("\n ingrese la dimension del vector : ");scanf("%d",&n);
    s=0;
	c=0;
	sum=0;
	for(i=0;i<=n-1;i=i+1)
	{
	printf("\n ingrese el nombre (%d) :",i);scanf("%s",&nombre[i]);	
	printf("\ningrese el talla (%d) : ",i);scanf("%f",&talla[i]);
	printf("\ningrese el peso (%d) : ",i);scanf("%f",&peso[i]);
	printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
	    s=s+talla[i];
        c=c+1;
        sum=sum+peso[i];
	}
	rp=sum/c;//media
	printf("\nla media del peso es: %f",rp);
	rt=s/c;//media
	printf("\nla media del talla es: %f", rt);
	printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
	for(j=0;j<=n-1;j=j+1)	
	{
		q=peso[j]-rp;
	 t=pow(q,2);
	 suma=suma+t;
	 
	 qq=talla[j]-rt;
	 tt=pow(qq,2);
	 suma_talla=suma_talla+tt;
	  
	}
	v=suma/n;
	vv=suma_talla/n;
	printf("\nla varianza  de la TALLA es : %f",vv);
	printf("\nla varianza  del PESO es : %f",v);
	printf("\n:::::::::::::::::::::::::::::::::::\n");
	fio=sqrt(v);
	fio2=sqrt(vv);
	printf("\nla DESVIACION estandar de la TALLA es  : %f",fio2);
	printf("\nla DESVIACION estandar del PESSO es : %f",fio);
	break;
		}
	case 5:
		{ 
			int c,i,j,n;
	float talla[n],peso[n],r,rr,R,suma_talla,suma_peso,sum,rpt;
	string nombre[n];
	printf("\n ingrese la dimension del vector : ");scanf("%d",&n);
	for(i=0;i<=n-1;i=i+1)
	{
	printf("\n ingrese el nombre (%d) :",i);scanf("%s",&nombre[i]);	
	printf("\ningrese el talla (%d) : ",i);scanf("%f",&talla[i]);
	printf("\ningrese el peso (%d) : ",i);scanf("%f",&peso[i]);
	printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
	}
	printf("\n<:::::::::::::::::::::::::::::::::::::::::::::::>\n");
	for(j=0;j<=n-1;j=j+1)	
	{
		suma_peso=suma_peso+peso[j];// sumas de pesos
		r=pow(peso[j],2);
		R=peso[j]*talla[j]; //multiplicacio de peso por talla
        sum=sum+R; //sumatoria de la multiplicacion
        
        suma_talla=suma_talla +talla[j];//suma de talla
        rr=pow(talla[j],2);
	}
	rpt=(sum*suma_talla)-(suma_peso*suma_talla);
	printf("EL COEFICIENTE DE PERSON PARA DATOS AGRUPADOS (peso,talla) ES: %f",rpt);
	break;
		}
	 default:
	 {
	 	printf("\n ingrese un numero del 1 al 4\n");
	 }	
	}
}