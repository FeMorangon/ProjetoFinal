#ifndef _VELHA_
#define _VELHA_

#include "./jogos.hpp"

class Velha: public Jogos{

    public:

    Velha(): Jogos(3, 3, 6, 18){
        num_max_partidas = 9;
        nome_do_jogo = "JOGO DA VELHA";
        inicializar();
    };

    int jogada_valida(int c1, int c2, int jogador) override {

        if(c1 > 2 || c1 < 0 || c2 > 2 || c2 < 0) return 1;
        
        else if(tabuleiro[c1][c2] != 0) return 2;
        
        else return 0;
    }

    int analisar_vitoria(int c1, int c2, int jogador) override{

        //Ver se o tabuleiro est� cheio
        
        int tabuleiro_vazio = 0;

        for(int i=0; i < linhas; i++){
            for(int j=0; j < colunas; j++){
                if(tabuleiro[i][j] == 0) tabuleiro_vazio = 1;
            }
        }

        if(tabuleiro_vazio == 0) return 3;

        //percorrer diagonais
        /*for(int i=0; i < linhas; i++){
            for(int j=0; j < colunas; j++){
                if(tabuleiro[i+1][j+1])
            }
        }*/

       for(int i=1; i <= 2 ; i++){

        if ((tabuleiro[0][0] == i && tabuleiro[0][1] == i && tabuleiro[0][2] == i) ||
            (tabuleiro[1][0] == i && tabuleiro[1][1] == i && tabuleiro[1][2] == i) ||
            (tabuleiro[2][0] == i && tabuleiro[2][1] == i && tabuleiro[2][2] == i) ||
            (tabuleiro[0][0] == i && tabuleiro[1][0] == i && tabuleiro[2][0] == i) ||
            (tabuleiro[0][1] == i && tabuleiro[1][1] == i && tabuleiro[2][1] == i) ||
            (tabuleiro[0][2] == i && tabuleiro[1][2] == i && tabuleiro[2][2] == i) ||
            (tabuleiro[0][0] == i && tabuleiro[1][1] == i && tabuleiro[2][2] == i) ||
            (tabuleiro[0][2] == i && tabuleiro[1][1] == i && tabuleiro[2][0] == i) ) return i;

       }
        return 0;
    }
};
 
#endif
