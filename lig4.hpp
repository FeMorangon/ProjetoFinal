#ifndef _CONNECTFOUR_
#define _CONNECTFOUR_

#include "./jogos.hpp"

class ConnectFour: public Jogos{

    public:

    ConnectFour(): Jogos(6, 7, 3, 9){
        num_max_partidas = 42;
        nome_do_jogo = "CONNECT FOUR";
        inicializar();
    };

    int jogada_valida(int c1, int c2, int jogador) override {

        if(c1 > 5 || c1 < 0 || c2 > 6 || c2 < 0) return 1;
        
        else if(tabuleiro[c1][c2] != 0) return 2;
        
        else return 0;
    }

    int analisar_vitoria(int c1, int c2, int jogador) override{

        for(int i=1; i <= 2; i++){

            for (int coluna = 0; coluna < colunas; ++coluna) {
                for (int linha = 0; linha <= linhas - 4; ++linha) {
                    if (tabuleiro[linha][coluna] == i &&
                        tabuleiro[linha + 1][coluna] == i && 
                        tabuleiro[linha + 2][coluna] == i && 
                        tabuleiro[linha + 3][coluna] == i) return 1;
                    }
            }

            for (int linha = 0; linha < linhas; ++linha) {
                for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
                    if (tabuleiro[linha][coluna] == i &&
                        tabuleiro[linha][coluna + 1] == i &&
                        tabuleiro[linha][coluna + 2] == i &&
                        tabuleiro[linha][coluna + 3] == i) return 1;
                }
            }

            // Aqui, verifica as diagonais existentes para baixo e para a direita
            for (int linha = 0; linha <= linhas - 4; ++linha) {
                for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
                    if (tabuleiro[linha][coluna] == i &&
                        tabuleiro[linha + 1][coluna + 1] == i &&
                        tabuleiro[linha + 2][coluna + 2] == i &&
                        tabuleiro[linha + 3][coluna + 3] == i) return 1;
                }
            }

            for (int linha = 3; linha < linhas; ++linha) {
                for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
                    if (tabuleiro[linha][coluna] == i &&
                        tabuleiro[linha - 1][coluna + 1] == i &&
                        tabuleiro[linha - 2][coluna + 2] == i &&
                        tabuleiro[linha - 3][coluna + 3] == i) return 1;
                }
            }
        }

        //Ver se o tabuleiro est� cheio

        int tabuleiro_vazio = 0;
        
        for(int j=0; j < colunas; j++){
            for(int i=0; i < linhas; i++){
                if(tabuleiro[i][j] == 0) tabuleiro_vazio = 1;
            }
        }

        if(tabuleiro_vazio == 0) return 3; // empate

        return 0;
    }
};
 
#endif
