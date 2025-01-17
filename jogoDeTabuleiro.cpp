#include "jogoDeTabuleiro.hpp"

JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
} // Cada elemento é inicializado com o caractere de espaço, para garantir que, no início do jogo, todas as posições do tabuleiro estejam vazias

char JogoDeTabuleiro::getPosicao(int linha, int coluna) const {
    return tabuleiro[linha][coluna];
} // Acessar os valores do tabuleiro, uma vez que os atributos são privados

int JogoDeTabuleiro::getColunas() const {
    return colunas;
}
