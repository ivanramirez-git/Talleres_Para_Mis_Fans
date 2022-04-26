#include <stdio.h>

void CrearCaj();
int BuscaCaj(int cod_, FILE * arch){
};

struct regi{
	int CodCaj;
	char ubi[20];
	char ciud[20];
	int DenMen;
	int DenMay;
}CAJERO;

Actualiza_Caj(){
	
	FILE * fcaj;
	int pos;
	int y;
	
	CrearCaj();
	fcaj = fopen("cajero.dat", "r+");
	
	do{
		printf("\n\n\tCajero \n");
		printf("\n1.Actualizar");
		printf("\n2.Conslutar");
		printf("\n3.Finalizar\n");
		
		scanf("%d", &y);
		
		switch(y){
			case 1:{
				
				while(1){
					
					printf("\nCodigo de cajero \n"); 
					scanf("%d", &CAJERO.CodCaj);
					if(CAJERO.CodCaj == 0)
					break;
					
					pos = BuscaCaj(CAJERO.CodCaj, fcaj);
					
					if(pos == -1){
						printf("\nUbicacion: ");
						fflush(stdin); 
						gets(CAJERO.ubi);
						printf("\nCiudad: "); 
						fflush(stdin);
						gets(CAJERO.ciud);
						printf("\nDenominacion menor: "); scanf("%d", &CAJERO.DenMen);
						printf("\nDenominacion mayor: "); scanf("%d", &CAJERO.DenMay);
						
						fseek(fcaj, 0, SEEK_END);
						fwrite(&CAJERO, sizeof(CAJERO), 1, fcaj);
					}	
					else
					{
						fseek(fcaj, pos, SEEK_SET);
						fread(&CAJERO, sizeof(CAJERO), 1, fcaj);
						printf("\nCodigo de cajero: %d ", CAJERO.CodCaj);
						printf("\nNuevo codigo de cajero: "); 
						scanf("%d", &CAJERO.CodCaj);
						fflush(stdin); 
						printf("\nUbicacion: %s", CAJERO.ubi);
						printf("\nUbicacion nueva: "); 
						fflush(stdin); 
						gets(CAJERO.ubi);
						printf("\nCiudad : %s", CAJERO.ciud);
						printf("\nCiudad nueva: "); 
						fflush(stdin); 
						gets(CAJERO.ciud);
						printf("\nDenominacion menor: %d", CAJERO.DenMen);
						printf("\nDenominacion menor nueva: "); scanf("%d", &CAJERO.DenMen);
						printf("\nDenominacion mayor: %d ", CAJERO.DenMay);
						printf("\nDenominacion mayor nueva: "); scanf("%d", &CAJERO.DenMay);
					}
				fseek(fcaj, 0, SEEK_END);
				fwrite(&CAJERO, sizeof(CAJERO), 1, fcaj);	
				}break;
			}
			case 2:{
				FILE * fcaj;
				fcaj = fopen("cajero.dat", "r");
				
				printf("\nCajero \tUbicacion \tCiudad \tDenominaciones ");
				fread(&CAJERO, sizeof(CAJERO), 1, fcaj);
				
				while( !feof(fcaj) ){
					printf("\n%d \t%s \t%s \t%d \t%d ", CAJERO.CodCaj, CAJERO.ubi, CAJERO.ciud, CAJERO.DenMen, CAJERO.DenMay);
					fread(&CAJERO, sizeof(CAJERO), 1, fcaj);
				}
				fclose(fcaj);	
				break;
			}
		}
	}while(y < 3);
}

void CrearCaj()
{
    if(fopen("cajero.dat","r") == NULL)
    {
		FILE *r = fopen("cajero.dat","a");
		fclose(r);
    }
}

