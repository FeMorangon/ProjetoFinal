// cadastro de jogadores (CJ <Apelido> <Nome>): adicionar novos jogadores pelo nome e apelido único
// remoção de jogadores (RJ <Apelido>): remover jogadores existentes
// listagem de jogadores (LJ [A|N]): mostrar todos os jogadores com seus respectivos números de vitórioas e derrotas em cada jogo
// início de partida (EP <Jogo: (R|L|V)> <Apelido Jogador 1> <Apelido Jogador 2>): iniciar uma partida entre dois jogadores em um dos jogos
// finalização do sistema (FS): encerrar a execução do sistema

#include <iostream>
#include <string>
#include <map>

// Informações do jogador
class Jogador {
public:
    std::string nome;
    std::string apelido;

    int vitoriasReversi = 0;
    int derrotasReversi = 0;
    int vitoriasLig4 = 0;
    int derrotasLig4 = 0;
    int vitoriasJogoVelha = 0;
    int derrotasJogoVelha = 0;
};

// Classe para gerenciar as partidas
class Partida {
private:
    std::map<std::string, Jogador> jogadores;

public:
    std::string registrarNomeJogador();
    std::string registrarApelidoJogador();

    void cadastrarJogador(const std::string& nome, const std::string& apelido);
};
