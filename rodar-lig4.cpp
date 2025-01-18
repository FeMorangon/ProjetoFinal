#include <iostream>
#include "lig4.hpp"

int main() {
    Lig4 jogo(6, 7);

    char jogador = 'X';
    int coluna;

    while (true) {
        jogo.imprimirTabuleiro();

        std::cout << "Jogador " << jogador << ", escolha uma coluna: ";
        std::cin >> coluna;

        std::cout << std::endl;

        if (coluna >= 1 && coluna <= jogo.getColunas() && jogo.encontrarLinhaLivre(coluna - 1)) {
            if (jogo.fazerJogada(coluna - 1, jogador)) {
                if (jogo.verificarVitoria(jogador)) {
                    jogo.imprimirTabuleiro();
                    std::cout << "Jogador " << jogador << " venceu!" << std::endl;
                    break;
                } else if (jogo.verificarEmpate()) {
                    std::cout << "Empate!" << std::endl;
                    break;
                }
                
                jogador = (jogador == 'X') ? 'O' : 'X'; // Alterna os jogadores
            } else {
                std::cout << "Posicao ja ocupada. Tente novamente." << std::endl;
            }

        } else {
            std::cout << "Jogada invalida. Tente novamente." << std::endl;
        }
    }
  
    return 0;
}
