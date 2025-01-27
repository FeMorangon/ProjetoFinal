#ifndef _CADASTROS_
#define _CADASTROS_

#include "cabecalhos.hpp"

struct Cadastro{
    string nome = "";
    int pontos[4] = {0, 0, 0, 0};

    /*
    Significados:
    vetor[0] = total de pontos
    vetor[1] = pontos jogo da velha
    vetor[2] = pontos reversi
    vetor[3] = pontos lig4
    */
};

vector<Cadastro> guardar_cadastros;

class Cadastrar{
public:
    
    //Coloca os dados do arquivo em um vetor assim que o sistema atualizar
    Cadastrar(){
        string linha;

        stringstream dividir_linha;

        ifstream arquivo("./cadastros.txt");

        Cadastro jogador;

        if(arquivo.is_open()){
            while( getline(arquivo, linha)){

            dividir_linha.str(linha);

            dividir_linha >> jogador.nome >> jogador.pontos[0] >> jogador.pontos[1] >> jogador.pontos[2] >> jogador.pontos[3];

            guardar_cadastros.push_back(jogador);

            dividir_linha.clear();  // Limpa os flags de erro
            dividir_linha.str("");  // Limpa o conteúdo do buffer
            }
        }
        arquivo.close();
    }

    static void AtualizarPontos(int resultado, string jogador1, string jogador2, int computador, int jogo){

        int posicao_jogador1 = -1;
        int posicao_jogador2 = -1;

        for (int i = 0; i < guardar_cadastros.size(); i++) {
            if (guardar_cadastros[i].nome == jogador1) posicao_jogador1 = i;
            if (guardar_cadastros[i].nome == jogador2) posicao_jogador2 = i;   
        }

        switch(resultado){
            case 1:
                guardar_cadastros[posicao_jogador1].pontos[jogo] += 10;
            break;

            case 2:
                guardar_cadastros[posicao_jogador2].pontos[jogo] += 10;
            break;

            case 3:
                guardar_cadastros[posicao_jogador1].pontos[jogo] += 5;
                guardar_cadastros[posicao_jogador2].pontos[jogo] += 5;
            break;
        }
        
        guardar_cadastros[posicao_jogador1].pontos[0]  = guardar_cadastros[posicao_jogador1].pontos[1] + guardar_cadastros[posicao_jogador1].pontos[2] + guardar_cadastros[posicao_jogador1].pontos[3];

        if(computador == 2) guardar_cadastros[posicao_jogador2].pontos[0]  = guardar_cadastros[posicao_jogador2].pontos[1] + guardar_cadastros[posicao_jogador2].pontos[2] + guardar_cadastros[posicao_jogador2].pontos[3];
        
        ofstream arquivo("./cadastros.txt", ios::out);

        for(int i=0; i < guardar_cadastros.size(); i++){
            guardar_cadastros[i].pontos[0]  = guardar_cadastros[i].pontos[1] + guardar_cadastros[i].pontos[2] + guardar_cadastros[i].pontos[3];

            arquivo << guardar_cadastros[i].nome << " ";
            arquivo << guardar_cadastros[i].pontos[0] << " ";
            arquivo << guardar_cadastros[i].pontos[1] << " ";
            arquivo << guardar_cadastros[i].pontos[2] << " ";
            arquivo << guardar_cadastros[i].pontos[3] << endl;
        }

        arquivo.close();
    }

    static string InserirUsuario(){

        Cadastro jogador;
        
        ofstream arquivo("./cadastros.txt", ios::app);     // Usando ios::app (append) para acrescentar uma nova linha no arquivo, e não sobrescrever

        if(arquivo.is_open()){
            cout << "Insira seu nome: ";

            do{
                cin >> jogador.nome;
                if(jogador.nome.size() > 20) cout << "ERRO: tamanho maximo de 20 caracteres: " ;
            } while(jogador.nome.size() > 20);

            if (jogador.nome.find(' ') != string::npos) {
                
                replace(jogador.nome.begin(), jogador.nome.end(), ' ', '_');
            }

            jogador.pontos[0] = jogador.pontos[1] + jogador.pontos[2] + jogador.pontos[3];

            arquivo << jogador.nome << " ";
            arquivo << jogador.pontos[0] << " ";
            arquivo << jogador.pontos[1] << " ";
            arquivo << jogador.pontos[2] << " ";
            arquivo << jogador.pontos[3] << endl;

            arquivo.close();

            cout << "\nUsuario criado com sucesso\n\n";
        }
        else cout << "Nao foi possivel abrir o arquivo";

        guardar_cadastros.clear();

        Cadastrar atualizar;

        return jogador.nome;
    }

    static void ImprimirUsuarios(){

        system("cls");

        string titulos[4] = {"pontuacao total", "jogo da velha", "reversi", "lig 4"};

        cout << "============================= LISTA DE USUARIOS =============================" << endl;

        cout << "indice. nome            |";

        for(int i = 0; i < 4; i++){
            cout << " " << titulos[i] << " |";
        }

        cout << "\n=============================================================================\n\n";

        for(int i=0; i < guardar_cadastros.size(); i++){
            cout << i+1 << ". " << guardar_cadastros[i].nome;

            for(int j=1; j <= 21 - guardar_cadastros[i].nome.size(); j++){
                    cout << " ";
                }

            cout << "|";

            for(int j = 0; j < 4; j ++){
                int num_de_digitos = floor(log10(abs(guardar_cadastros[i].pontos[j])) + 1);

                int centralizar_pontos;

                (guardar_cadastros[i].pontos[j] == 0) ? centralizar_pontos = (titulos[j].size() + 1) : centralizar_pontos = ((titulos[j].size()) - num_de_digitos + 2);

                for(int k = 1; k <= centralizar_pontos; k++){
                    cout << " ";
                    if(k == (centralizar_pontos/2)) cout << guardar_cadastros[i].pontos[j];
                }
                cout << "|";
            }
            cout << endl;
        }
    }

    static void RemoverJogador(){
        
        int remover = -1;

        cout << "\nInsira o indice do usuario a ser removido: ";
        cin >> remover;

        remover  -= 1;

        guardar_cadastros.erase(guardar_cadastros.begin() + remover);

        ofstream arquivo("./cadastros.txt", ios::out);

        for(int i=0; i < guardar_cadastros.size(); i++){

            guardar_cadastros[i].pontos[0]  = guardar_cadastros[i].pontos[1] + guardar_cadastros[i].pontos[2] + guardar_cadastros[i].pontos[3];

            arquivo << guardar_cadastros[i].nome << " ";
            arquivo << guardar_cadastros[i].pontos[0] << " ";
            arquivo << guardar_cadastros[i].pontos[1] << " ";
            arquivo << guardar_cadastros[i].pontos[2] << " ";
            arquivo << guardar_cadastros[i].pontos[3] << endl;
        }

        cout << "Usuario removido com sucesso!";

        arquivo.close();
    }

    static string EscolherJogador(){

        int indice;
        
        cout << "Insira o indice do usuario escolhido: ";
        cin >> indice;

        return guardar_cadastros[indice-1].nome;
    }
};

#endif
