#include <stdio.h>
#include <iostream>
#include <vector>
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
    
    vector<char> v({'A','B','C','D','E','F','G','H'});

    for(int i = 0; i < linhas; i++){
        cout << i + 1 << " | ";
        for(int j = 0; j < colunas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "    ";
    for(int i = 0; i < linhas; i++){
        cout << v[i] << " " ;
    }
    cout << endl;

}

int acoes(int (&matriz)[8][8], int x, int y){
     if (matriz[x][y] == 1 ){
        if (matriz[x + 1][y] == 0) { 
            cout << "pode se mover!" << endl;
        }else{
            cout << "ficar" << endl;
        }
        if (matriz[x + 1][y + 1] == 9  || matriz[x + 1][y - 1] == 9) { 
            cout << "pode tomar" << endl;
        }
    }

}

int main(){

    int x,y;

    const int linhas = 8;
    const int colunas = 8;
    int matriz[linhas][colunas];
  

    preencher_matriz(matriz);
    matriz[2][3] = 1;
    matriz[7][7] = 1;
    matriz[4][1] = 1;
    imprimir_matriz(matriz);

    cout << "digite a peca que quer mover" << endl;
    cin >> x >> y;
    acoes(matriz,x,y);

    
   

}

