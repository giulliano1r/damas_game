#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int iniciar_tabuleiro(int (&matriz)[8][8]){
    
    const int linhas = 8;
    const int colunas = 8;

    //preenche tudo com zero
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = 0;
        }
    }

    //insere as peças "pretas"
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = 1;
        }
    }

    //insere as peças "brancas"
    for(int i = 6; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = 9;
        }
    }
}

int imprimir_tabuleiro(int (&matriz)[8][8]){
    
    const int linhas = 8;
    const int colunas = 8;
    // vector<char> v({'A','B','C','D','E','F','G','H'});

    for(int i = 0; i < linhas; i++){
        cout << i + 1 << " | ";
        for(int j = 0; j < colunas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "    " << "---------------" << endl;
    cout << "    ";
    for(int i = 0; i < linhas; i++){
        cout << i + 1 << " " ;
    }
    cout << endl;
}

bool verifica_mover(int (&matriz)[8][8], int linha, int coluna){
    if (matriz[linha + 1][coluna] == 0) { 
        return true;
    }
    return false;
}

bool verifica_tomar_direita(int (&matriz)[8][8], int linha, int coluna){
    if (matriz[linha + 1][coluna + 1] == 9 && matriz[linha + 2][coluna + 2] == 0 ) { 
        return true;;
    }
    return false;
}

bool verifica_tomar_esquerda(int (&matriz)[8][8], int linha, int coluna){
    if (matriz[linha + 1][coluna - 1] == 9 && matriz[linha + 2][coluna - 2] == 0) { 
        return true;;
    }
    return false;
}

int mover_peca(int (&matriz)[8][8],int linha, int coluna) {
    matriz[linha + 1][coluna] = 1;
    matriz[linha][coluna] = 0;
}

int tomar_peca_direita(int (&matriz)[8][8],int linha, int coluna){
    matriz[linha][coluna] = 0;
    matriz[linha + 1][coluna + 1] = 0;
    matriz[linha + 2][coluna + 2] = 1;
    
}

int tomar_peca_esquerda(int (&matriz)[8][8],int linha, int coluna){
    matriz[linha][coluna] = 0;
    matriz[linha + 1][coluna - 1] = 0;
    matriz[linha + 2][coluna - 2] = 1;
}

int realizar_acoes(int (&matriz)[8][8], int acao, int linha, int coluna){
    switch (acao){
        case 1: 
            mover_peca(matriz,linha,coluna);
            break;
        case 2:
            tomar_peca_direita(matriz,linha,coluna);
            break;
        case 3:
            tomar_peca_esquerda(matriz,linha,coluna);
            break;
    }
}

int escolher_peca(int (&matriz)[8][8]){
    int x,y;
    int acao;

    imprimir_tabuleiro(matriz);
    cout << endl;
    cout << "escolha a peca que deseja ultilziar" << endl;
    cin >> x >> y;
    x = x - 1;
    y = y - 1;

    if (matriz[x][y] == 1){ 
        bool mover = verifica_mover(matriz,x,y);
        bool tomar_esquerda = verifica_tomar_direita(matriz,x,y);
        bool tomar_direita = verifica_tomar_esquerda(matriz,x,y);

        if(mover){
            cout << "1. Digite 1 para mover-se" << endl;
        }
        if(tomar_esquerda){
            cout << "2. Digite 2 para tomar a peca a direita" << endl;
        }
        if(tomar_direita){
            cout << "3. Digite 3 para tomar a peca a esquerda" << endl;
        }
        if(!tomar_esquerda && !tomar_direita && !mover ){
            cout << "Nenhuma acao disponivel" << endl;
        }
        cout << "4. Digite 4 para escolher outra peca" << endl;
        cin >> acao;

        if (acao == 4){
            escolher_peca(matriz);
        }
        realizar_acoes(matriz,acao,x,y);
    }
    else {
        cout << "escolha outra peca!" << endl;
        escolher_peca(matriz);
    }
}

int main(){

    int x;

    const int linhas = 8;
    const int colunas = 8;
    int matriz[linhas][colunas];
  
    iniciar_tabuleiro(matriz);

    //start_game
    while(x != 0){
        system("cls");
        escolher_peca(matriz);
    }
}

