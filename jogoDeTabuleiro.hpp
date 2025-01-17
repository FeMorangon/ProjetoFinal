#ifndef JOGODETABULEIRO_H
#define JOGODETABULEIRO_H

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
};

#endif
