#include "cadastro.hpp"

std::string Partida::registrarNomeJogador() {
    std::string nome;
    std::cout << "Digite seu nome: ";
    std::getline(std::cin, nome);
    return nome;
}

std::string Partida::registrarApelidoJogador() {
    std::string apelido;
    std::cout << "Digite seu apelido: ";
    std::cin >> apelido;
    return apelido;
}
