// Declaração da classe base

#ifndef JOGODETABULEIRO_H
#define JOGODETABULEIRO_H

#include <vector>

class JogoDeTabuleiro {
protected:
    int linhas;
    int colunas;
    std::vector<std::vector<char>> tabuleiro;

public:
    JogoDeTabuleiro(int linhas, int colunas);
    virtual ~JogoDeTabuleiro() = default;

    virtual bool fazerJogada(int coluna, char jogador) = 0;
    char getPosicao(int linha, int coluna) const;
    int getColunas() const;

// para o Lig4
    virtual bool verificarVertical(char jogador) = 0;
    virtual bool verificarHorizontal(char jogador) = 0;
    virtual bool verificarDiagonal(char jogador) = 0;
    
    virtual bool verificarEmpate() = 0; // Verificar se todas as posições do tabuleiro estão preenchidas
    virtual bool verificarVitoria(char jogador) = 0; // No lig4, implementar verificação de vitória na horizontal, vertical e diagonal

    virtual void imprimirTabuleiro() = 0;
};

#endif
