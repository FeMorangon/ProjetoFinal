#include "./velha.hpp"
#include "./reversi.hpp"
#include "./lig4.hpp"
#include "./cadastros.hpp"

string jogador1, jogador2;
int escolha_de_oponente;
int escolher_nome = 0;
int escolha_do_jogo = 0;
int voltar_pagina = 0;

int jogoVelha(){
    Velha jogo_da_velha;
    return jogo_da_velha.iniciarJogo(jogador1, jogador2, escolha_de_oponente);
    system("pause");
    system("cls");
}

int jogoReversi(){
    Reversi jogo_reversi;
    return jogo_reversi.iniciarJogo(jogador1, jogador2, escolha_de_oponente);
    system("pause");
    system("cls");
}

int jogoConnect4(){
    ConnectFour jogo_connectfour;
    return jogo_connectfour.iniciarJogo(jogador1, jogador2, escolha_de_oponente);
    system("pause");
    system("cls");
}

int EscolherOponente(){

    system("cls");

    cout << "================================= BEM VINDO =================================" << "\n\n";
    cout << "Seja bem vindo! Antes de come�ar, voc� gostaria de jogar contra:" << "\n\n";
    cout << "1 - Um Amigo\n2 - Computador\n\n";
    cout << "Escolha: ";

    do{
        cin >> escolha_de_oponente;
        if(escolha_de_oponente > 2 || escolha_de_oponente < 1) cout << "Erro: op��o inv�lida. Escolha novamente: ";
    } while(escolha_de_oponente > 2 || escolha_de_oponente < 1);

    return 3;
}

int EscolherNome(){

    for(int i = 1; i <= 2; i++){

        if(escolha_de_oponente == 2 && i == 2) break;

        do {
            system("cls");

            cout << "================================= BEM VINDO =================================" << "\n\n";

            Cadastrar::ImprimirUsuarios();

            cout << "\n" << "=============================================================================" << "\n\n";

            if(escolha_de_oponente == 2) cout << "Jogador, escolha entre as op��es!\n\n";

            else{
                (i == 1) ? cout << "Jogador 1, � a sua vez de escolher!\n\n" : cout << "Jogador 2, � a sua vez de escolher!\n\n";
            } 
    
            cout << "1 - Sair\n2 - Voltar\n\n3 - Inserir Novo Usu�rio\n4 - Remover Usu�rio\n5 - Jogar Sem Nome\n6 - Escolher Usu�rio\n\nEscolha: ";

            do{
                cin >> escolher_nome;
                if(escolher_nome > 6 || escolher_nome < 1) cout << "Erro: op��o inv�lida. Escolha novamente: ";
            } while(escolher_nome > 6 || escolher_nome < 1);

            if(escolher_nome == 4) Cadastrar::RemoverJogador();
            
            }while(escolher_nome == 4);

            switch(escolher_nome){
            
                case sair: 
                    if(escolher_nome == sair) break;
                break;

                case voltar:
                    if(escolher_nome == voltar) break;
                break;

                case 3:
                    (i == 1) ? jogador1 = Cadastrar::InserirUsuario() : jogador2 = Cadastrar::InserirUsuario();
                break;

                case 5:
                    (i == 1) ? jogador1 = "Jogador 1" : jogador2 = "Jogador 2";
                break;

                case 6:
                    (i == 1) ? jogador1 = Cadastrar::EscolherJogador() : jogador2 = Cadastrar::EscolherJogador();
                break;
            }

        if(escolher_nome == sair || escolher_nome == voltar) break;
    }
    if(escolher_nome == sair) return 1;
    else if(escolher_nome == voltar) return 2;
    else return 0;
}

int EscolherJogo() {

    int resultado = 0;

    escolha_do_jogo = 0;

    while (escolha_do_jogo != sair && escolha_do_jogo != voltar) {
        system("cls");

        cout << "================================ BEM VINDO ================================\n\n";
        cout << "Escolha uma op��o:\n";
        cout << "\n1 - Sair\n2 - Voltar\n\n3 - Jogo da Velha\n4 - Reversi\n5 - Lig4\n\nEscolha Sua Op��o: ";

        do {
            cin >> escolha_do_jogo;

            if (escolha_do_jogo > 5 || escolha_do_jogo < 1) cout << "Op��o inv�lida, tente novamente: ";

        } while (escolha_do_jogo > 5 || escolha_do_jogo < 1);

        cout << "\n===========================================================================\n";

        switch (escolha_do_jogo) {

            case sair:
                if(escolha_do_jogo == sair) break;
            break;

            case voltar:
                if(escolha_do_jogo == voltar) break;
            break;

            case velha:

                resultado = jogoVelha();
                Cadastrar::AtualizarPontos(resultado, jogador1, jogador2, contra_computador, 1);
                break;

            case reversi:
                resultado = jogoReversi();
                Cadastrar::AtualizarPontos(resultado, jogador1, jogador2, contra_computador, 2);
                break;

            case connect4:
                resultado = jogoConnect4();
                Cadastrar::AtualizarPontos(resultado, jogador1, jogador2, contra_computador, 3);
                break;

            default:
                cout << "Op��o inv�lida, tente novamente.\n";
                break;
        }
    }
    if(escolha_do_jogo == voltar) return 3;
    else return 1;
}

int main(){

    Cadastrar usuarios;

    //=======================================================================================//

    //Para o compilador aceitar acentos do portugu�s
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    //=======================================================================================//

    while(voltar_pagina != sair){

        voltar_pagina = EscolherOponente();

        while(voltar_pagina == 3){

            voltar_pagina = EscolherNome();
            if(voltar_pagina == 1) break;

            while(voltar_pagina == 0){
                voltar_pagina = EscolherJogo();
                if(voltar_pagina == 1) break;
            }
        }
    }

    return 0;
}
