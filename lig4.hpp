#ifndef LIG4_H
#define LIG4_H

#include "jogoDeTabuleiro.hpp"

class Lig4 : public JogoDeTabuleiro {
public:
    // Construtor
    Lig4(int linhas, int colunas);
    int encontrarLinhaLivre(int coluna);
    bool fazerJogada(int coluna, char jogador) override;
};

#endif
