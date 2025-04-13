#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxTemp = 201;
const int maxNM = 101;
const int offset = 100;

bool dp[maxNM][maxNM][maxTemp]; 
bool visit[maxNM][maxNM][maxTemp];
int n, m,cantCasos;
vector<vector<int>> grafoMatriz;

bool aulas(int i, int j, int temperatura) {
    //cb 1 -> si se pasan los indices
    if (i >= n || j >= m) return false;

    temperatura += grafoMatriz[i][j];

    //optimizacion / poda
    int pasosRestantes = (n - 1 - i) + (m - 1 - j);
    if (temperatura < 0) {
    if (-temperatura > pasosRestantes) return false;
        } else {
    if (temperatura > pasosRestantes) return false;
        }

    // cb 2 -> si llega al final y temperatura == 0 ret true
    if (i == n - 1 && j == m - 1) return temperatura == 0;

    if (visit[i][j][temperatura + offset]) return dp[i][j][temperatura + offset]; //devuelvo si ya tengo

    //si no lo marco como visitado y lo guardo en dp
    visit[i][j][temperatura + offset] = true;

    dp[i][j][temperatura + offset] = aulas(i + 1, j, temperatura) ||  aulas(i, j + 1, temperatura);

    return  dp[i][j][temperatura + offset];
}

int main() {
    cin >> cantCasos;

    while (cantCasos--) {
        cin >> n >> m;

        grafoMatriz = vector<vector<int>>(n, vector<int>(m));

        for (int i = 0; i < n; ++i)

            for (int j = 0; j < m; ++j)

                cin >> grafoMatriz[i][j];


        memset(dp, 0, sizeof(dp));
        memset(visit, 0, sizeof(visit));

        if (aulas(0, 0, 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
