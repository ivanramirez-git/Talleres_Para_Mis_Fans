#include <stdio.h>

void CrearClient();
int BuscaClient(int Cod_, FILE * cl){
}

struct trCliente{
	
	int CodClient;
	char NomClient[25];
	int NumCuent;
	float Balance;
	
};

Actualiza_Client(){
	
	FILE * Fcli;
	trCliente vrCli;
	int site;
	int x;
	
	CrearClient();
	Fcli = fopen("cliente.dat", "r+");
	
	do{
	
		printf("\n\n\tClientes\n");
		printf("\n1.Actualizar");
		printf("\n2.Conslutar");
		printf("\n3.Finalizar\n");
		scanf("%d", &x);
		
		switch(x){
			case 1:{
				while(1){
					printf("\nCodigo cliente \n"); scanf("%d", &vrCli.CodClient);
					if(vrCli.CodClient == 0)
					break;
					
					site = BuscaClient(vrCli.CodClient, Fcli);
					
					if(site == -1){
						fflush(stdin);
						printf("\nNombre del cliente: "); gets(vrCli.NomClient);
						printf("\nNumero de cuenta: "); scanf("%d", &vrCli.NumCuent);
						printf("\nBalance : "); scanf("%2.f", &vrCli.Balance);
					}
					else
					{
						fseek(Fcli, 0, SEEK_END);
						fwrite(&vrCli, sizeof(vrCli), 1, Fcli);
						
						printf("\nCodigo cliente: %d ", vrCli.CodClient);
						printf("\nNuevo codigo cliente"); scanf("%d", &vrCli.CodClient);
						printf("\nNombre del cliente: %s ", vrCli.NomClient);
						fflush(stdin);
						printf("\nNuevo nombre del cliente: "); gets(vrCli.NomClient);
						printf("\nNumero de cuenta: %d ", vrCli.NumCuent);
						printf("\nNuevo numero de cuenta: "); scanf("%d", &vrCli.NumCuent);
						printf("\nBalance : %2.f ", vrCli.Balance);
						printf("\nNuevo balance: "); scanf("%2.f", &vrCli.Balance);
					}
					fseek(Fcli, 0, SEEK_END);
					fwrite(&vrCli, sizeof(vrCli), 1, Fcli);
				}
			break;
			}
			case 2:{
				
				fseek(Fcli, 0, SEEK_END);
				fread(&vrCli, sizeof(vrCli), 1, Fcli);
				
				printf("\nCodigo \t Nombre del cliente \t Numero de cuenta \t Balance ");
				
				while(!feof(Fcli)){
					printf("\n%d \t %s \t %d \t %2.f ", vrCli.CodClient, vrCli.NomClient, vrCli.NumCuent, vrCli.Balance);
					fread(&vrCli, sizeof(vrCli), 1, Fcli);
				}
				break;
			}
			fclose(Fcli);
		}		
	}while(x < 3);
	fclose(Fcli);
}

void CrearClient()
{
    if(fopen("cliente.dat","r") == NULL)
    {
		FILE *r = fopen("cliente.dat","a");
		fclose(r);
    }
}
