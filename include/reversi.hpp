#ifndef _REVERSI_
#define _REVERSI_

#include "./jogos.hpp"

class Reversi: public Jogos{
public:
    Reversi(): Jogos(8, 8, 3, 9){
        tabuleiro[3][3] = 1;
        tabuleiro[3][4] = 2;
        tabuleiro[4][3] = 2;
        tabuleiro[4][4] = 1;

        nome_do_jogo = "REVERSI";

        num_max_partidas = 60;

        inicializar();
    };

    int jogada_valida(int c1, int c2, int jogador) override {

        int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
        int adversario = (jogador == 1) ? 2 : 1;
        int captura = 0;

        if (c1 > 7 || c1 < 0 || c2 > 7 || c2 < 0) return 1; // A  peça foi colocada fora do tabuleiro
        if (tabuleiro[c1][c2] != 0) return 2; // A  peça foi colocada em casa ocupada

        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (j == 0 && k == 0) continue;
                
                int na = c1 + j, nb = c2 + k;

                if (na >= 0 && na < 8 && nb >= 0 && nb < 8 && tabuleiro[na][nb] == adversario) {
                    for (int i = 0; i < 8; i++) {
                        int x = c1 + direcoes[i][0], y = c2 + direcoes[i][1];
                        int dx = x, dy = y;
                        int tem_adversario = 0;

                        while (x < 8 && x >= 0 && y < 8 && y >= 0 && tabuleiro[x][y] == adversario) {
                            tem_adversario = 1;
                            x += direcoes[i][0];
                            y += direcoes[i][1];
                        }

                        if (tem_adversario && x < 8 && x >= 0 && y < 8 && y >= 0 && tabuleiro[x][y] == jogador) {
                            while (dx != x || dy != y) {
                                tabuleiro[dx][dy] = jogador;
                                dx += direcoes[i][0];
                                dy += direcoes[i][1];
                            }
                            captura = 1;
                        }
                    }
                    if (captura) return 0;
                }           
            }
        }
        return 3;
    }

    int analisar_vitoria(int c1, int c2, int jogador) override{

        int tabuleiro_vazio = 0;
        int casas_jogador1 = 0;
        int casas_jogador2 = 0;

        for(int i=0; i < linhas; i++){
            for(int j=0; j < colunas; j++){
                if(tabuleiro[i][j] == 0) tabuleiro_vazio = 1;

                if(tabuleiro[i][j] == 1) casas_jogador1 += 1;

                if(tabuleiro[i][j] == 2) casas_jogador2 += 1;
            }
        }

        if(tabuleiro_vazio != 0) return 0;
        if(casas_jogador1 > casas_jogador2) return 1;
        if(casas_jogador1 < casas_jogador2) return 2;
        if(casas_jogador1 == casas_jogador2) return 3;
    }
};

#endif
