#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *cabecera1[10] = {"Distrito", "Candidato", "Candidato", "Candidato", "Candidato"};
    char *cabecera2[30] = {"", "A", "B", "C", "D"};

    int distrito[5][4] = {
        {194, 48, 206, 45},
        {180, 20, 320, 16},
        {221, 90, 140, 20},
        {432, 50, 821, 14},
        {820, 61, 946, 18}
    };

    // Imprimir la tabla anterior con cabeceras incluidas
    int espacios = 0;
    int i, j;
    // Cabecera1
    for(i = 0; i < 5; i++){
        espacios =  strlen(cabecera1[i]);
        printf("%*s ", espacios, cabecera1[i]);
    }
    printf("\n");
    // Cabecera2
    for(i = 0; i < 5; i++){
        espacios = strlen(cabecera1[i])/2;
        printf(" %*s%*s ", espacios, cabecera2[i],espacios,"");
    }
    printf("\n");
    // Datos
    for(i = 0; i < 5; i++){
        printf("    %d   ",i+1);
        for(j = 0; j < 4; j++){
            printf("%*d", 9, distrito[i][j]);
        }
        printf("\n");
    }

    // Calcular e imprimir el numero total de votos por candidato
    int *votos;
    votos = (int *) malloc(sizeof(int)*4);
    for(i = 0; i < 4; i++){
        votos[i] = 0;
    }

    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){
            votos[j] += distrito[i][j];
        }
    }

    printf("\n\n");
    printf("Votos por candidato:\n");
    for(i = 0; i < 4; i++){
        printf("Candidato %s: %d\n", cabecera2[i+1], votos[i]);
    }

    // Si algun candidatos recibe mas del 50 % de los votos Mostrar el candidatos mas votado y declararlo ganador
    int votosTotales=0;
    for(i = 0; i < 4; i++){
        votosTotales += votos[i];
    }

    int indiceCandiMasVotado = -1;
    int votosCandidatoMasVotado = -1;
    for(i = 0; i < 4; i++){
        if(votos[i] > votosCandidatoMasVotado){
            indiceCandiMasVotado = i;
            votosCandidatoMasVotado = votos[i];
        }
    }

    if(votosCandidatoMasVotado > (votosTotales+0.0)/(2+0)){
        printf("\nEl candidato %s es el ganador con %d votos, total de votos: %d\n", cabecera2[indiceCandiMasVotado+1], votosCandidatoMasVotado, votosTotales);
    }


    // ¿Que candidato gano en el distrito 4?
    int votosDistrito4[4] = {0,0,0,0};
    for(i = 0; i < 4; i++){
        votosDistrito4[i] += distrito[3][i];
    }

    int indiceCandiMasVotadoDistrito4 = -1;
    int votosCandidatoMasVotadoDistrito4 = -1;
    for(i = 0; i < 4; i++){
        if(votosDistrito4[i] > votosCandidatoMasVotadoDistrito4){
            indiceCandiMasVotadoDistrito4 = i;
            votosCandidatoMasVotadoDistrito4 = votosDistrito4[i];
        }
    }

    printf("\nEl candidato %s gano en el distrito 4 con %d votos\n", cabecera2[indiceCandiMasVotadoDistrito4+1], distrito[3][indiceCandiMasVotadoDistrito4]);

    return 0;
}