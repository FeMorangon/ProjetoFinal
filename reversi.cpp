
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int tabuleiro[8][8] = {0};
int coordenadas[60][2];

void imprimir(int tab[8][8]) {
    cout << "\n    ";
    for (int k = 1; k < 9; k++) {
        cout << k << "   ";
    }
    cout << endl;
    
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << " |";
        for (int j = 0; j < 8; j++) {
            if (tab[i][j] == 1) cout << " x |";
            else if (tab[i][j] == 2) cout << " o |";
            else if (tab[i][j] == 3) cout << " * |";
            else cout << "   |";
        }
        cout << endl;
    }
}

int condicoes(int a, int b, int c) {
    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
    int adversario = (c == 1) ? 2 : 1;
    int captura = 0;

    if (a > 7 || a < 0 || b > 7 || b < 0) return 1;
    if (tabuleiro[a][b] != 0) return 2;

    for (int j = -1; j <= 1; j++) {
        for (int k = -1; k <= 1; k++) {
            if (j == 0 && k == 0) continue;
            int na = a + j, nb = b + k;

            if (na >= 0 && na < 8 && nb >= 0 && nb < 8 && tabuleiro[na][nb] == adversario) {
                for (int i = 0; i < 8; i++) {
                    int x = a + direcoes[i][0], y = b + direcoes[i][1];
                    int dx = x, dy = y;
                    int tem_adversario = 0;

                    while (x < 8 && x >= 0 && y < 8 && y >= 0 && tabuleiro[x][y] == adversario) {
                        tem_adversario = 1;
                        x += direcoes[i][0];
                        y += direcoes[i][1];
                    }

                    if (tem_adversario && x < 8 && x >= 0 && y < 8 && y >= 0 && tabuleiro[x][y] == c) {
                        while (dx != x || dy != y) {
                            tabuleiro[dx][dy] = c;
                            dx += direcoes[i][0];
                            dy += direcoes[i][1];
                        }
                        captura = 1;
                    }
                }
                if (captura) return 0;
            }
        }
    }
    return 3;
}

void rodada(int a) {
    int erro, c1, c2;
    for (int i = 1; i <= 2; i++) {
        do {
            cout << "\nJogador " << i << ": ";
            cin >> coordenadas[a][0] >> coordenadas[a][1];
            c1 = coordenadas[a][0] - 1;
            c2 = coordenadas[a][1] - 1;

            erro = condicoes(c1, c2, i);

            if (erro == 1) cout << "ERRO: casa inexistente\n";
            if (erro == 2) cout << "ERRO: casa ocupada\n";
            if (erro == 3) cout << "ERRO: jogador nao realiza capturas\n";
        } while (erro != 0);

        tabuleiro[c1][c2] = i;
        imprimir(tabuleiro);
    }
}

int main() {
    srand(time(NULL));

    tabuleiro[3][3] = 1;
    tabuleiro[3][4] = 2;
    tabuleiro[4][3] = 2;
    tabuleiro[4][4] = 1;

    int vitoria_1 = 0, vitoria_2 = 0;

    cout << "              TABULEIRO\n";
    imprimir(tabuleiro);

    for (int i = 1; i <= 60; i++) {
        cout << "\n\n             .:RODADA " << i << ":.\n";
        rodada(i);

        int final = 0;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (tabuleiro[j][k] == 0) final++;
            }
        }

        if (final == 0) {
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    if (tabuleiro[j][k] == 1) vitoria_1++;
                    if (tabuleiro[j][k] == 2) vitoria_2++;
                }
            }
            if (vitoria_1 > vitoria_2) cout << "\n\n JOGADOR 1 VENCEU!!!";
            else if (vitoria_1 < vitoria_2) cout << "\n\n JOGADOR 2 VENCEU!!!";
            else cout << "\n\n EMPATE!!!";

            return 0;
        }
    }
    return 0;
}
