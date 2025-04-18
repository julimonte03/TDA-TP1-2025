#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <unordered_map>

using namespace std;

const int offset = 100;

vector<vector<unordered_map<int, optional<bool>>>> dp; //CLAVE TEMP, VALOR PUEDE SER NULL (SI NO FUE VISITADO) O TRUE OR FALSE

int n, m, cantCasos;
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

    if ((pasosRestantes - abs(temperatura)) % 2 != 0) return false;

    // cb 2 -> si llega al final y temperatura == 0 ret true
    if (i == n - 1 && j == m - 1) return temperatura == 0;

    if (dp[i][j].count(temperatura) && dp[i][j][temperatura].has_value()) return dp[i][j][temperatura].value();

    bool res = aulas(i + 1, j, temperatura) || aulas(i, j + 1, temperatura);

    dp[i][j][temperatura] = res;
    return res;
}

int main() {
    cin >> cantCasos;

    while (cantCasos--) {
        cin >> n >> m;

        grafoMatriz = vector<vector<int>>(n, vector<int>(m));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> grafoMatriz[i][j];

        dp = vector<vector<unordered_map<int, optional<bool>>>>(n, vector<unordered_map<int, optional<bool>>>(m));

        if (aulas(0, 0, 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
