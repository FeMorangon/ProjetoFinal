#ifndef _CONNECTFOUR_
#define _CONNECTFOUR_

#include "./jogos.hpp"

class ConnectFour: public Jogos{

    public:

    ConnectFour(): Jogos(6, 7, 3, 9){
        num_max_partidas = 42;
        nome_do_jogo = "CONNECT FOUR";
        inicializar();
    };

    int jogada_valida(int c1, int c2, int jogador) override {

        if(c2 > 6 || c2 < 0) return -1; //casa inexistente

        int coordenada_x = -1;

        for(int i = c1; i >= 0; i--){
            if(tabuleiro[i][c2] == 0) {
                coordenada_x = i;
                return coordenada_x;
                break;
            } else continue;
        }

        if(coordenada_x == -1) return -2;
        
        //else if(tabuleiro[c1][c2] != 0) return 2;
        
        else return 0;
    }

    int analisar_vitoria(int c1, int c2, int jogador) override {

        for(int i=1; i <= 2; i++){

            for (int coluna = 0; coluna < colunas; ++coluna) {
                for (int linha = 0; linha <= linhas - 4; ++linha) {
                    if (tabuleiro[linha][coluna] == i &&
                        tabuleiro[linha + 1][coluna] == i && 
                        tabuleiro[linha + 2][coluna] == i && 
                        tabuleiro[linha + 3][coluna] == i) return i;
                    }
            }

            for (int linha = 0; linha < linhas; ++linha) {
                for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
                    if (tabuleiro[linha][coluna] == i &&
                        tabuleiro[linha][coluna + 1] == i &&
                        tabuleiro[linha][coluna + 2] == i &&
                        tabuleiro[linha][coluna + 3] == i) return i;
                }
            }

            // Aqui, verifica as diagonais existentes para baixo e para a direita
            for (int linha = 0; linha <= linhas - 4; ++linha) {
                for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
                    if (tabuleiro[linha][coluna] == i &&
                        tabuleiro[linha + 1][coluna + 1] == i &&
                        tabuleiro[linha + 2][coluna + 2] == i &&
                        tabuleiro[linha + 3][coluna + 3] == i) return i;
                }
            }

            for (int linha = 3; linha < linhas; ++linha) {
                for (int coluna = 0; coluna <= colunas - 4; ++coluna) {
                    if (tabuleiro[linha][coluna] == i &&
                        tabuleiro[linha - 1][coluna + 1] == i &&
                        tabuleiro[linha - 2][coluna + 2] == i &&
                        tabuleiro[linha - 3][coluna + 3] == i) return i;
                }
            }
        }

        //Ver se o tabuleiro est� cheio

        int tabuleiro_vazio = 0;
        
        for(int j=0; j < colunas; j++){
            for(int i=0; i < linhas; i++){
                if(tabuleiro[i][j] == 0) tabuleiro_vazio = 1;
            }
        }

        if(tabuleiro_vazio == 0) return 3; // empate

        return 0;
    }

    int rodada(int NUMmax_partidas, string nome1, string nome2, string nome_do_jogo, int linhas, int colunas, int altura, int largura, int contra_computador) override {

    int coordenada_x = 0, coordenada_y = 0;
    int vencedor = 0;
    mt19937 gerador(static_cast<unsigned int>(time(0)));

    int centralizar_palavra = ((largura*colunas) + colunas + 1 - 2); //subtrair tamanho da palavra

    for(int rodada=1; rodada <= NUMmax_partidas; rodada++){
            for(int jogador=1; jogador <= 2; jogador++){

                coordenada_x = linhas - 1;

                int avaliar_jogada = -1;

                system("cls");

                //Imprimir nome do jogo
                for(int i=1; i <= centralizar_palavra - nome_do_jogo.size(); i++){
                    (i == 1)? cout << "  =" : cout << "=";
                    if(i == (centralizar_palavra - nome_do_jogo.size())/2) cout << " " << nome_do_jogo << " ";
                }

                cout << "\n\n";

                //Imprimir qual rodada  �
                for(int i=1; i <= centralizar_palavra - string("RODADA X").size(); i++){
                    (i == 1)? cout << "   " : cout << " ";
                    if(i == (centralizar_palavra - string("RODADA X").size())/2) cout << " RODADA " << rodada << "\n";
                }

                //Imprimir tabuleiro
                imprimir(linhas, colunas, altura_celula, largura_celula);

                SetConsoleCP(1252);
                SetConsoleOutputCP(1252);

                //Vendo se vai ou n�o terminar o jogo
                vencedor = analisar_vitoria(linhas, colunas, jogador);

                if(vencedor != 0){

                    cout << endl;

                    switch(vencedor){
                    case 1:
                            for(int j = 1; j <= (centralizar_palavra - (string("Vitória De ").size() + nome1.size()))/2; j++){
                                cout << " ";
                            }
                            cout << "Vitória De " << nome1 << "!!!\n\n";
                            system("pause");
                            return 1;
                    break;

                    case 2:
                            for(int j = 1; j <= (centralizar_palavra - (string("Vitória De ").size() + nome2.size()))/2; j++){
                                cout << " ";
                            }
                            cout << "Vitória De " << nome2 << "!!!\n\n";
                            system("pause");

                            if(contra_computador == 1) return 2;
                            else return 4;
                    break;

                    case 3:
                            for(int j = 1; j <= (centralizar_palavra - (string("Empate!!!").size()))/2; j++){
                                cout << " ";
                            }
                            cout << "Empate" << "!!!\n\n";
                            system("pause");
                            return 3;
                    break;
                    }



                }

                //Vez de fulano
                cout << "\nVez de ";

                //Jogada do computador - se for jogador x computador
                if(contra_computador == 2 && jogador == 2){

                    cout << "Computador: ";

                    while(avaliar_jogada == -1 || avaliar_jogada == -2){

                        uniform_int_distribution<> y(0, colunas-1); // n�mero aleat�rio para as colunas
                        coordenada_y = y(gerador);

                        avaliar_jogada = jogada_valida(coordenada_x, coordenada_y, jogador);
                    }
                        cout << coordenada_x + 1 << " " << coordenada_y + 1 << "\n\n";

                        system("pause");
                }

                //Jogada pessoa
                else{

                    (jogador == 1)? cout << nome1 << ": " : cout << nome2 << ": ";

                    while(avaliar_jogada == -1 || avaliar_jogada == -2){
                    cin >> coordenada_y;
                
                    coordenada_y -= 1;
                    
                    avaliar_jogada = jogada_valida(coordenada_x, coordenada_y, jogador);

                    if(avaliar_jogada == -1) cout << "ERRO: casa inexistente. Tente novamente: ";
                    if(avaliar_jogada == -2) cout << "ERRO: coluna ocupada. Tente novamente: ";
                    }
                }

                tabuleiro[avaliar_jogada][coordenada_y] = jogador;
            }
        }
        
    }

};
 
#endif
