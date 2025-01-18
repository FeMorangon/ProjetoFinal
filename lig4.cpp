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

// As funções a seguir verificam a possibilidade de vitória do jogador
bool Lig4::verificarVertical(char jogador) {
    for (int coluna = 0; coluna < colunas; ++coluna) {
        for (int linha = 0; linha <= linhas - 4; ++linha) {
            if (tabuleiro[linha][coluna] == jogador &&
            tabuleiro[linha + 1][coluna] == jogador && 
            tabuleiro[linha + 2][coluna] == jogador && 
            tabuleiro[linha + 3][coluna] == jogador) {
                return true;
            }
        }
    }
    return false; // Nenhuma sequência vertical foi encontrada
}

bool Lig4::verificarHorizontal(char jogador) {
    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
            if (tabuleiro[linha][coluna] == jogador &&
                tabuleiro[linha][coluna + 1] == jogador &&
                tabuleiro[linha][coluna + 2] == jogador &&
                tabuleiro[linha][coluna + 3] == jogador) {
                return true;
            }
        }
    }
    return false; // Nenhuma sequência horizontal foi encontrada
}
bool Lig4::verificarDiagonal(char jogador) {
    // Aqui, verifica as diagonais existentes para baixo e para a direita
    for (int linha = 0; linha <= linhas - 4; ++linha) {
        for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
            if (tabuleiro[linha][coluna] == jogador &&
                tabuleiro[linha + 1][coluna + 1] == jogador &&
                tabuleiro[linha + 2][coluna + 2] == jogador &&
                tabuleiro[linha + 3][coluna + 3] == jogador) {
                return true;
            }
        }
    }

    // Aqui, verifica as diagonais existentes para cima e para a direita
    for (int linha = 3; linha < linhas; ++linha) {
        for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
            if (tabuleiro[linha][coluna] == jogador &&
                tabuleiro[linha - 1][coluna + 1] == jogador &&
                tabuleiro[linha - 2][coluna + 2] == jogador &&
                tabuleiro[linha - 3][coluna + 3] == jogador) {
                return true;
            }
        }
    }
    return false; // Nenhuma sequência diagonal foi encontrada
}
    // Verificando a possibilidade do empate no jogo
    bool Lig4::verificarEmpate() {
    for (int coluna = 0; coluna < colunas; ++coluna) {
        if (encontrarLinhaLivre(coluna) != -1) {
            return false; // Há colunas com espaços vazios, então o jogo ainda não acabou
        }
    }
    return true; // Todas as colunas estão cheias
}

// Condições de vitória no jogo
bool Lig4::verificarVitoria(char jogador) {
    return verificarVertical(jogador) || verificarHorizontal(jogador) || verificarDiagonal(jogador && !verificarEmpate());

}

// Impressão do tabuleiro do jogo
void Lig4::imprimirTabuleiro() {
    // Indica os números das colunas antes de imprimir o tabuleiro, para ajudar na visualização das colunas
    std::cout << "  ";
    for (int coluna = 0; coluna < colunas; ++coluna) {
        std::cout << coluna + 1 << "   ";
    }
    std::cout << std::endl;

    // Imprime o tabuleiro
    for (int linha = 0; linha < linhas; ++linha) {
        std::cout << "| ";
        for (int coluna = 0; coluna < colunas; ++coluna) {
            std::cout << tabuleiro[linha][coluna] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
