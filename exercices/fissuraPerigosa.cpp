#include <bits/stdc++.h>
#include <vector>
using namespace std;


vector<string> mapa;

void bfs(int v) {
    queue<pair<int, int>> q;
    q.push(pair<int,int>(0,0));
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};

    if (mapa[0][0] - '0' > v)
        return;
    while (!q.empty()) {
        auto [x,y] = q.front();q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < mapa.size() && ny >= 0 && ny < mapa.size()) {
                if (mapa[nx][ny] != '*' && mapa[nx][ny] - '0' <= v) {
                    q.push(pair<int, int>(nx,ny));
                    mapa[nx][ny]='*';
                }
            }
        }
    }
}

int main() {
    int n, f;
    cin >> n >> f;

    for (int i = 0; i < n; i++) {
        string aux;
        cin >> aux;
        mapa.push_back(aux);
    }

    bfs(f);
    for (int i = 0; i < n; i++) {
                cout << mapa[i] << endl;
    }
}
