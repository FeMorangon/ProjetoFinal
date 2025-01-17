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

void Partida::cadastrarJogador(const std::string& nome, const std::string& apelido) {
    std::string nome = registrarNomeJogador();
    std::string apelido = registrarApelidoJogador();

    if (jogadores.count(apelido) > 0) {
        std::cout << "ERRO: jogador repetido" << std::endl;
        return;
    }

    // Adicionar jogador cadastrado ao map
    jogadores[apelido] = {nome, apelido}; // No map, se uma chave já existe, o valor é sobrescrito
    std::cout << "Jogador " << apelido << "cadastrado com sucesso" << std::endl;

} // testar
