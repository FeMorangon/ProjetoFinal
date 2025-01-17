#include <iostream>

using namespace std;

int main() {
    int tabuleiro[3][3] = {0}, coordenadas[9][2] = {0};

    for (int a = 0; a < 9; a++) {
        cout << ".:JOGADA " << a + 1 << ":." << endl;
        
        do {
            if (a % 2 == 0)
                cout << "Jogador X: ";
            else
                cout << "Jogador O: ";

            cin >> coordenadas[a][0] >> coordenadas[a][1];

            if (coordenadas[a][0] > 3 || coordenadas[a][1] > 3 || coordenadas[a][0] < 1 || coordenadas[a][1] < 1) {
                cout << "ERRO: coordenadas inexistentes" << endl;
            } else if (tabuleiro[coordenadas[a][0] - 1][coordenadas[a][1] - 1] != 0) {
                cout << "ERRO: a casa " << coordenadas[a][0] << " " << coordenadas[a][1] << " está ocupada" << endl;
            }
        } while (coordenadas[a][0] > 3 || coordenadas[a][1] > 3 || coordenadas[a][0] < 1 || coordenadas[a][1] < 1 || tabuleiro[coordenadas[a][0] - 1][coordenadas[a][1] - 1] != 0);

        if (a % 2 == 0)
            tabuleiro[coordenadas[a][0] - 1][coordenadas[a][1] - 1] = 1;
        else
            tabuleiro[coordenadas[a][0] - 1][coordenadas[a][1] - 1] = 2;

        // Imprimindo Tabuleiro
        for (int i = 0; i < 3; i++) {
            cout << endl;
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == 1)
                    cout << "[x]";
                else if (tabuleiro[i][j] == 2)
                    cout << "[o]";
                else
                    cout << "[ ]";
            }
        }

        // Verificação de vitória
        int vencedor = 0;
        for (int i = 1; i <= 2; i++) {
            if ((tabuleiro[0][0] == i && tabuleiro[0][1] == i && tabuleiro[0][2] == i) ||
                (tabuleiro[1][0] == i && tabuleiro[1][1] == i && tabuleiro[1][2] == i) ||
                (tabuleiro[2][0] == i && tabuleiro[2][1] == i && tabuleiro[2][2] == i) ||
                (tabuleiro[0][0] == i && tabuleiro[1][0] == i && tabuleiro[2][0] == i) ||
                (tabuleiro[0][1] == i && tabuleiro[1][1] == i && tabuleiro[2][1] == i) ||
                (tabuleiro[0][2] == i && tabuleiro[1][2] == i && tabuleiro[2][2] == i) ||
                (tabuleiro[0][0] == i && tabuleiro[1][1] == i && tabuleiro[2][2] == i) ||
                (tabuleiro[0][2] == i && tabuleiro[1][1] == i && tabuleiro[2][0] == i)) {
                vencedor = i;
                break;
            }
        }

        if (vencedor != 0) {
            cout << "\n\nVITÓRIA DO JOGADOR " << (vencedor == 1 ? "X" : "O") << endl;
            break;
        }

        cout << "\n\n";
    }
    return 0;
}
