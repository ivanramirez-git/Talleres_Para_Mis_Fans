#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
//Complete su codigo


void encuentraVocales(char *frase,char *vocales){
    int numVocales=0;
    int i=0, j=0;
    bool a=false,e=false,is=false,o=false,u=false;
    while (frase[i] != '\0'){
    	
    	char letraActual = tolower(frase[i]);
    	    	
    	if (letraActual == 'a'){
    		vocales[0]='a';
    		a=true;
   		}
    	if (letraActual == 'e'){    		
    		vocales[1]='e';
    		e=true;
    	}
    	if (letraActual == 'i'){    		
    		vocales[2]='i';
    		is=true;
		}
    	if (letraActual == 'o'){    		
    		vocales[3]='o';
    		o=true;
		}
    	if (letraActual == 'u'){    		
    		vocales[4]='u';
			u=true;
		}
		
		i=i+1;
    }
	//	printf("\nVocales: %s", vocales);
}

int main(){
    char frase[50];
    char vocales[5];
    vocales[0]='0';
    vocales[1]='0';
    vocales[2]='0';
    vocales[3]='0';
    vocales[4]='0';
    
    printf("Vocales en una frase: ");
    
    scanf("%s",frase);

    printf("\nFrase: %s", frase);

    //Complete su codigo
    encuentraVocales(frase,vocales);//Se buscan las vocales contenidas en frase y se almacena de forma ordenada en vocales 
    printf("\nVocales: ");
    int i;
    for(i=0;i<5;i++){
    	if(vocales[i]!='0')
    		printf("%c",vocales[i]);
	}
    
    
    return 0;    
}

//Complete su codigo
