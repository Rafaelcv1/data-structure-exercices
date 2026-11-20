#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

vector<vector<int>> cave;
vector<vector<int>> dist;
int min_dist {INT_MAX};

void bfs(int x_ini, int y_ini) {
    queue<pair<int,int>> q;
    q.push(pair<int,int>(x_ini,y_ini));
    int dx[] = {0,0,1,-1};
    int dy[] = {-1,1,0,0};
    while (!q.empty()) {
        pair<int, int> curr = q.front();q.pop();
        for (int i = 0; i < 4; i++) {
            if (curr.first+dx[i] >= 0 && curr.second+dy[i] >= 0 && curr.first+dx[i] < cave.size() && curr.second+dy[i] < cave[0].size()) {
                if (cave[curr.first+dx[i]][curr.second+dy[i]] != 2) {
                    q.push(pair<int,int>(curr.first+dx[i], curr.second+dy[i]));
                }
                dist[curr.first+dx[i]][curr.second+dy[i]]=min(dist[curr.first+dx[i]][curr.second+dy[i]], dist[curr.first][curr.second]+1);
                if (cave[curr.first+dx[i]][curr.second+dy[i]] == 0) {
                    min_dist = min(min_dist, dist[curr.first+dx[i]][curr.second+dy[i]]);
                    return;
                }
                cave[curr.first+dx[i]][curr.second+dy[i]] = 2;
            }

        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int x0, y0;
    cave = vector<vector<int>>(n, vector<int>(m, 0));
    dist = vector<vector<int>>(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 3){
                x0 = i;
                y0 = j;
            }
            cave[i][j] = tmp;
        }
    }
    dist[x0][y0]=0;
    cave[x0][y0]=2;
    bfs(x0,y0);
    cout << min_dist;
}
