/*Problema: Coloração de Cenério de Jogos - 1907
  Nome: Gabriela Emanuele de Araujo Amorim
*/

#include <iostream>
#include <queue>

using namespace std;

#define MAX 1030

char mapa[MAX][MAX];
int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inGrid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && mapa[i][j] == '.');
}

void floodFill(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    mapa[i][j] = 'o';

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int x = 0; x < 4; x++) {
            int ni = current.first + dx[x];
            int nj = current.second + dy[x];
            if (inGrid(ni, nj)) {
                mapa[ni][nj] = 'o';
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> mapa[i];
    }
        
    int resposta = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == '.') {
                resposta++;
                floodFill(i, j);
            }
        }
    }
    
    cout << resposta << endl;
    
    return 0;
}
