#include <iostream>

using namespace std;

int main(){
    // N Choferes x 6 dias de la semana
    int n;
    // Preguntar cuanos choferes hay
    cout << "Cuantos choferes hay? ";
    cin >> n;
    // Declarar un arreglo de n choferes
    string empresa[n][6];

    // Datos de prueba
    if(n>0){
        
        empresa[0][0] = "Nixon";
        empresa[0][1] = "64";
        empresa[0][2] = "32";
        empresa[0][3] = "37";
        empresa[0][4] = "45";
        empresa[0][5] = "22";
        
    }

    if(n>1){
        
        empresa[1][0] = "Sanchez";
        empresa[1][1] = "65";
        empresa[1][2] = "33";
        empresa[1][3] = "38";
        empresa[1][4] = "46";
        empresa[1][5] = "23";
        
    }

    if(n>2){
        
        empresa[2][0] = "Lopez";
        empresa[2][1] = "66";
        empresa[2][2] = "34";
        empresa[2][3] = "39";
        empresa[2][4] = "47";
        empresa[2][5] = "24";
        
    }

    if(n>3){
        
        empresa[3][0] = "Gonzalez";
        empresa[3][1] = "67";
        empresa[3][2] = "35";
        empresa[3][3] = "40";
        empresa[3][4] = "48";
        empresa[3][5] = "25";
        
    }

    if(n>4){
        
        empresa[4][0] = "Rodriguez";
        empresa[4][1] = "68";
        empresa[4][2] = "36";
        empresa[4][3] = "41";
        empresa[4][4] = "49";
        empresa[4][5] = "26";
        
    }

    if(n>5){
        
        empresa[5][0] = "Martinez";
        empresa[5][1] = "69";
        empresa[5][2] = "37";
        empresa[5][3] = "42";
        empresa[5][4] = "50";
        empresa[5][5] = "27";
        
    }

    if(n>6){
        
        empresa[6][0] = "Gomez";
        empresa[6][1] = "70";
        empresa[6][2] = "38";
        empresa[6][3] = "43";
        empresa[6][4] = "51";
        empresa[6][5] = "28";
        
    }
    // Vector que suma cuandos kilometros recorrio cada chofer en la semana
    for(int i=0; i<n; i++){
        int suma = 0;
        for(int j=0; j<6; j++){
            suma = suma + atoi(empresa[i][j].c_str());
        }
        cout << "El chofer " << empresa[i][0] << " recorrio " << suma << " kilometros en la semana" << endl;
    }
    return 0;
}