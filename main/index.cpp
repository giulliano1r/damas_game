#include <stdio.h>
#include <iostream>
using namespace std;

template <size_t linhas, size_t colunas>
int preencher_matriz(int (&matriz)[linhas][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = 0;
        }
    }
}

template <size_t linhas, size_t colunas>
int imprimir_matriz(int (&matriz)[linhas][colunas]){
   for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    const int linhas = 8;
    const int colunas = 8;
    int matriz[linhas][colunas];

    preencher_matriz(matriz);

    //testes

    //tomar 
    matriz[1][5] = 1;
    matriz[2][6] = 9;
    matriz[2][4] = 9;

    //ficar
    // matriz[2][5] = 1;


    
    imprimir_matriz(matriz);

    //acoes
    if (matriz[1][5] == 1 ){
        if (matriz[1 + 1][5] == 0) { 
            cout << "pode se mover!" << endl;
        }else{
            cout << "ficar" << endl;
        }
        if (matriz[1 + 1][5 + 1] == 9  || matriz[1 + 1][5 - 1] == 9) { 
            cout << "pode tomar" << endl;
        }
    }


}