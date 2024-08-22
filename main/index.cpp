#include <stdio.h>
#include <iostream>
#include <vector>
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

bool verifica_mover(int (&matriz)[8][8], int linha, int coluna){
    if (matriz[linha + 1][coluna] == 0) { 
        return true;
    }
    return false;
}

bool verifica_tomar(int (&matriz)[8][8], int linha, int coluna){
    if (matriz[linha + 1][coluna + 1] == 9  || matriz[linha + 1][coluna - 1] == 9) { 
        return true;
    }
    return false;
}

int mover_peca(int (&matriz)[8][8],int linha, int coluna) {
    matriz[linha + 1][coluna] = 1;
    matriz[linha][coluna] = 0;
    imprimir_tabuleiro(matriz);
}

int realizar_acoes(int (&matriz)[8][8], int acao, int linha, int coluna){
    switch (acao){
        case 1: 
            mover_peca(matriz,linha,coluna);
            break;
        case 2:
            //funcao tomar
            break;
    }
}

int escolher_peca(int (&matriz)[8][8]){
    int x,y;
    int acao;

    cout << "escolha a peca que deseja ultilziar" << endl;
    cin >> x >> y;
    x = x - 1;
    y = y - 1;

    if (matriz[x][y] == 1){ 
        bool mover = verifica_mover(matriz,x,y);
        bool tomar = verifica_tomar(matriz,x,y);

        if (mover) {
            cout << "1. Digite 1 para mover-se" << endl;
            cout << "3. Digite 3 para escolher outra peca" << endl;
            cin >> acao;
        }
        else if (tomar && mover){
            cout << "1. Digite 1 para mover-se" << endl;
            cout << "2. Digite 2 para tomar" << endl;
            cout << "3. Digite 3 para escolher outra peca" << endl;
            cin >> acao;
        }
        else if (tomar){
            cout << "2. Digite 2 para tomar" << endl;
            cout << "3. Digite 3 para escolher outra peca" << endl;
            cin >> acao;
        }
        else{
            cout << "nenhuma acao disponivel" << endl;
            escolher_peca(matriz);
        }
        if (acao == 3){
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
    imprimir_tabuleiro(matriz);

    //start_game
    while(x != 0){
        escolher_peca(matriz);
        cout << "digite 0 se quiser parar o jogo" << endl;
        cout << "digite qualquer numero para continuar" << endl;
        cin >> x;
    }
}

