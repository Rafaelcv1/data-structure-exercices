#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> team;

int bfs(int s) {
    queue<int> q;
    team[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int parent = q.front();q.pop();
        for (int child : adj[parent]) {
            if (!team[child]) {
                team[child] = 3 - team[parent];
                q.push(child);
            } else if (team[parent] == team[child]) return 1;
        }
    }
    return 0;
}

int main() {
    int nPupils, nFriendShips;
    cin >> nPupils >> nFriendShips;
    adj = vector<vector<int>> (nPupils);
    team = vector<int> (nPupils, 0);

    for (int i = 0; i < nFriendShips; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        adj[a1-1].push_back(a2-1);
        adj[a2-1].push_back(a1-1);
    }

    for (int i = 0; i < nPupils; i++) {
        if (team[i] != 0) continue;
        if (bfs(i)) {cout << "IMPOSSIBLE"; return 0; }
    }
    for (auto c: team) {
        cout << c << " ";
    }
}
