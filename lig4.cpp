#include <iostream>
#include "lig4.hpp"

Lig4::Lig4(int linhas, int colunas) : JogoDeTabuleiro(6,7) {}

int Lig4::encontrarLinhaLivre(int coluna) {
    if (coluna < 0 || coluna > colunas) {
        std::cerr << "A coluna eh invalida." << std::endl;
    }

    for (int i = linhas - 1; i >= 0; --i) {
        if (tabuleiro[i][coluna] == ' ') {
            return i;
        } //  Determina a primeira linha disponível na coluna escolhida -> de 5 a 0
    }
    return -1; // Coluna cheia
}

bool Lig4::fazerJogada(int coluna, char jogador) {
    int linha = encontrarLinhaLivre(coluna);
    if (linha != -1) {
        tabuleiro[linha][coluna] = jogador;
        return true; // Jogada válida
    }
    return false; // Jogada inválida
}
