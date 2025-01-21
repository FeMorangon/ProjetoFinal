#ifndef _JOGOS_
#define _JOGOS_

#include <iostream>
#include <string>
#include <vector>
#include "./cabecalhos.hpp"

using namespace std;

class Jogos{

    protected:

    int linhas;
    int colunas;
    
    int altura_celula;
    int largura_celula;

    string nome_do_jogo;

    static vector<string> lista_de_jogos;

    public:

    int num_max_partidas;
    vector<vector<int>> tabuleiro;

    // Construtor
    Jogos(int lin, int col, int alt, int lar): linhas(lin), colunas(col), altura_celula(alt), largura_celula(lar){
        inicializar();
    }

    // inicializar a matriz com o tamanho de acordo com o jogo
    void inicializar(){
        tabuleiro.resize(linhas, vector<int>(colunas, 0));  // Inicializa com zeros
    }

    // M�todo para acessar e modificar os elementos do tabuleiro
    int& acessar_elementos(int i, int j){
        return tabuleiro[i][j];
    }

    virtual int jogada_valida(int c1, int c2, int jogador) = 0;

    virtual int analisar_vitoria(int c1, int c2, int jogador) = 0;

    void imprimir(int linhas, int colunas, int altura, int largura);

    int rodada(int NUMmax_partidas, string nome1, string nome2, string nome_do_jogo, int linhas, int colunas, int altura, int largura, int contra_computador);

    int iniciarJogo(string nome1, string nome2, int contra_computador);
};

int Jogos::iniciarJogo(string nome1, string nome2, int contra_computador){
        system("cls");
        return rodada(num_max_partidas, nome1, nome2, nome_do_jogo, linhas, colunas, altura_celula, largura_celula, contra_computador);
    }

void Jogos::imprimir(int linhas, int colunas, int altura, int largura){

    SetConsoleCP(852);
    SetConsoleOutputCP(852);

    //imprimir n�meros
    for(int i=1; i <= colunas; i++){
    
        int num;

        (i == 1)? (num = largura/2) && (cout << endl) : (num = largura);

        for(int j=1; j <= num; j++){

            (j==1 && i==1)? cout << "   " : cout << " ";
        }

        (i==colunas)? cout << i << endl : cout << i;
    }
    // Imprimir linha superior
    cout << "  \xC9";
    for (int c = 0; c < colunas; c++) {
        for (int j = 1; j <= largura; j++) cout << "\xCD";
        (c == colunas - 1) ? cout << "\xBB" : cout << "\xCB";
    }

    for (int i = 0; i < linhas; i++) {
        // Imprimir linhas de conte�do
        for (int k = 0; k < altura; k++) {

            (k == altura/2)? cout << endl << i+1 << " \xBA" : cout << endl << "  \xBA";
            

            for (int j = 0; j < colunas; j++) {
                for (int l = 0; l < largura; l++) {
                    if (tabuleiro[i][j] == 1) cout << "\xDB";
                    else if (tabuleiro[i][j] == 2) cout << "\xB0";
                    else cout << " ";
                }
                cout << "\xBA";
            }
        }
        // Imprimir divis�ria entre as linhas (se n�o for a �ltima linha)
        if (i != linhas - 1) {
            cout << endl << "  \xCC";
            for (int c = 0; c < colunas; c++) {
                for (int j = 1; j <= largura; j++) cout << "\xCD";
                (c == colunas - 1) ? cout << "\xB9" : cout << "\xCE";
            }
        }
    }

    // Imprimir linha inferior
    cout << endl << "  \xC8";
    for (int c = 0; c < colunas; c++) {
        for (int j = 1; j <= largura; j++) cout << "\xCD";
        (c == colunas - 1) ? cout << "\xBC" : cout << "\xCA";
    }
    cout << endl;
}

int Jogos::rodada(int NUMmax_partidas, string nome1, string nome2, string nome_do_jogo, int linhas, int colunas, int altura, int largura, int contra_computador){

    int coordenada_x = 0, coordenada_y = 0;
    int vencedor = 0;
    mt19937 gerador(static_cast<unsigned int>(time(0)));

    int centralizar_palavra = ((largura*colunas) + colunas + 1 - 2); //subtrair tamanho da palavra

    for(int rodada=1; rodada <= NUMmax_partidas; rodada++){
            for(int jogador=1; jogador <= 2; jogador++){

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
                            for(int j = 1; j <= (centralizar_palavra - (string("Vit�ria De ").size() + nome1.size()))/2; j++){
                                cout << " ";
                            }
                            cout << "Vit�ria De " << nome1 << "!!!\n\n";
                            system("pause");
                            return 1;
                    break;

                    case 2:
                            for(int j = 1; j <= (centralizar_palavra - (string("Vit�ria De ").size() + nome2.size()))/2; j++){
                                cout << " ";
                            }
                            cout << "Vit�ria De " << nome2 << "!!!\n\n";
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

                    while(avaliar_jogada != 0){

                        uniform_int_distribution<> x(0, linhas-1); // n�mero aleat�rio para as linhas
                        coordenada_x = x(gerador);

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

                    while(avaliar_jogada != 0){
                    cin >> coordenada_x >> coordenada_y;
                
                    coordenada_x -= 1;
                    coordenada_y -= 1;

                    avaliar_jogada = jogada_valida(coordenada_x, coordenada_y, jogador);

                    if(avaliar_jogada == 1) cout << "ERRO: casa inexistente. Tente novamente: ";
                    if(avaliar_jogada == 2) cout << "ERRO: casa ocupada. Tente novamente: ";
                    if(avaliar_jogada == 3) cout << "ERRO: jogador nao realiza capturas. Tente novamente: ";
                    }
                }

                tabuleiro[coordenada_x][coordenada_y] = jogador;
            }
        }
        
    }

#endif
