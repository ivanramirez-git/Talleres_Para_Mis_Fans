#include <stdio.h>
#include "Cajero.h"
#include "Clientes.h"
main()
{
	int opc;
	
	do{
		printf("\n\n\tMenu General\n");
		printf("\n1. Cajero.");
		printf("\n2. Clientes.");
		printf("\n3. Efectivo.");
		printf("\n4. Retiros.");
		printf("\n5. Finalizar.\n");
            
        scanf("%d",&opc);
        
        if(opc == 1) Actualiza_Caj();
		if(opc == 2) Actualiza_Client();    
		
		}while(opc != 5);
	
	printf("\nSu proceso ha finalizado");
}
