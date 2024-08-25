#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int iniciar_tabuleiro(int (&matriz)[8][8],int linhas, int colunas){
    
    //preenche tudo com zero
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = 0;
        }
    }

    //insere as peças "brancas"
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < colunas; ++j){
            if((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0)){
                matriz[i][j] = 1;
            }
        }
    }

    //insere as peças "pretas"
    for(int i = 5; i < 8; ++i){
        for(int j = 0; j < colunas; ++j){
            if((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0)){
                matriz[i][j] = 9;
            }
        }
    }
}

int imprimir_tabuleiro(int (&matriz)[8][8], bool jogador, int linhas, int colunas){
    
    if(jogador){
        cout << endl;
        cout << "    ** " << "jogador 1 **" << endl;
        cout << endl;
    }
    else{
        cout << endl;
        cout << "    ** " << "jogador 2 **" << endl;
        cout << endl;
    }
    
    cout << "    ";
    for(int i = 0; i < linhas; i++){
        cout << i + 1 << " " ;
    }
    cout << endl;
    cout << "    " << "---------------" << endl;
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

//jogador 1 = true;
//jogador 2 = false;
bool verifica_mover_direita(int (&matriz)[8][8], int linha, int coluna, bool jogador){
    if (jogador){
        if (matriz[linha + 1][coluna + 1] == 0) { 
            return true;
        }
    }
    else{
        if (matriz[linha - 1][coluna + 1] == 0) { 
            return true;
        }
    }
    
    return false;
}

bool verifica_mover_esquerda(int (&matriz)[8][8], int linha, int coluna, bool jogador){
    if (jogador){
        if (matriz[linha + 1][coluna - 1] == 0) { 
            return true;
        }
    }
    else{
        if (matriz[linha - 1][coluna - 1] == 0) { 
            return true;
        }
    }
    
    return false;
}

bool verifica_tomar_direita(int (&matriz)[8][8], int linha, int coluna, bool jogador){
    if (jogador){
        if (matriz[linha + 1][coluna + 1] == 9 && matriz[linha + 2][coluna + 2] == 0 ) { 
            return true;
        }
    }
    else{
        if (matriz[linha - 1][coluna + 1] == 1 && matriz[linha - 2][coluna + 2] == 0 ) { 
            return true;
        }
    }  
    return false;
}

bool verifica_tomar_esquerda(int (&matriz)[8][8], int linha, int coluna, bool jogador){
    if (jogador){
        if (matriz[linha + 1][coluna - 1] == 9 && matriz[linha + 2][coluna - 2] == 0) { 
            return true;;
        }
    }
    else{
        if (matriz[linha - 1][coluna - 1] == 1 && matriz[linha - 2][coluna - 2] == 0) { 
            return true;;    
        }
    }
    return false;
}

int mover_peca_direita(int (&matriz)[8][8],int linha, int coluna, bool jogador) {
    if (jogador){
        matriz[linha + 1][coluna + 1] = 1;
        matriz[linha][coluna] = 0;
    }
    else{
        matriz[linha - 1][coluna + 1] = 9;
        matriz[linha][coluna] = 0;
    }
}

int mover_peca_esquerda(int (&matriz)[8][8],int linha, int coluna, bool jogador) {
    if (jogador){
        matriz[linha + 1][coluna - 1] = 1;
        matriz[linha][coluna] = 0;
    }
    else{
        matriz[linha - 1][coluna - 1] = 9;
        matriz[linha][coluna] = 0;
    }
}

int tomar_peca_direita(int (&matriz)[8][8],int linha, int coluna, bool jogador){
    if (jogador){
        matriz[linha][coluna] = 0;
        matriz[linha + 1][coluna + 1] = 0;
        matriz[linha + 2][coluna + 2] = 1;
    }
    else{
        matriz[linha][coluna] = 0;
        matriz[linha - 1][coluna + 1] = 0;
        matriz[linha - 2][coluna + 2] = 9;
    }
}

int tomar_peca_esquerda(int (&matriz)[8][8],int linha, int coluna, bool jogador){
    if (jogador){
        matriz[linha][coluna] = 0;
        matriz[linha + 1][coluna - 1] = 0;
        matriz[linha + 2][coluna - 2] = 1;
    }
    else{
        matriz[linha][coluna] = 0;
        matriz[linha - 1][coluna - 1] = 0;
        matriz[linha - 2][coluna - 2] = 9;
    }
}

int realizar_acoes(int (&matriz)[8][8], int acao, int linha, int coluna, bool jogador){
    switch (acao){
        case 1: 
            mover_peca_esquerda(matriz,linha,coluna,jogador);
            break;
        case 2:
            mover_peca_direita(matriz,linha,coluna,jogador);
            break;
        case 3:
            tomar_peca_direita(matriz,linha,coluna,jogador);
            break;
        case 4:
            tomar_peca_esquerda(matriz,linha,coluna,jogador);
            break;
    }
}

int escolher_peca(int (&matriz)[8][8], bool jogador, int linhas, int colunas){
    int x,y;
    int acao;

    imprimir_tabuleiro(matriz,jogador,linhas,colunas);
    cout << endl;
    cout << "Escolha a peca que deseja ultilziar" << endl;
    cout << endl;
    cout << "linha: ";
    cin >> x ;
    cout << "coluna: ";
    cin >> y ;
    x = x - 1;
    y = y - 1;

    if (matriz[x][y] == 1 || matriz[x][y] == 9){ 
        bool mover_esquerda = verifica_mover_esquerda(matriz,x,y,jogador);
        bool mover_direita = verifica_mover_direita(matriz,x,y,jogador);
        bool tomar_esquerda = verifica_tomar_direita(matriz,x,y,jogador);
        bool tomar_direita = verifica_tomar_esquerda(matriz,x,y,jogador);

        if(mover_esquerda){
            cout << "1. Digite 1 para mover-se para esquerda" << endl;
        }
        if(mover_direita){
            cout << "2. Digite 2 para mover-se para direita" << endl;
        }
        if(tomar_esquerda){
            cout << "3. Digite 3 para tomar a peca a direita" << endl;
        }
        if(tomar_direita){
            cout << "4. Digite 4 para tomar a peca a esquerda" << endl;
        }
        if(!tomar_esquerda && !tomar_direita && !mover_esquerda && !mover_direita){
            cout << "Nenhuma acao disponivel" << endl;
        }
        cout << "5. Digite 5 para escolher outra peca" << endl;
        cin >> acao;

        if (acao == 5){
            escolher_peca(matriz,jogador,linhas,colunas);
        }
        realizar_acoes(matriz,acao,x,y,jogador);
    }
    else {
        cout << "escolha outra peca!" << endl;
        escolher_peca(matriz,jogador,linhas,colunas);
    }
}

int main(){

    int x;
    bool jogador = true;
    const int linhas = 8;
    const int colunas = 8;
    int matriz[linhas][colunas];
  
    iniciar_tabuleiro(matriz,linhas,colunas);

    //start_game
    while(x != 0){
        system("cls");
        escolher_peca(matriz,jogador,linhas,colunas);
        jogador = !jogador;
        system("cls");
        escolher_peca(matriz,jogador,linhas,colunas);
        jogador = !jogador;
    }
}

