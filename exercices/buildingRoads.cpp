#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
  visited[v] = true;
  for (auto i : adj[v]) {
    if (!visited[i]) dfs(i);
  }
}
int main() {
  int Ncities;
  int Nroads;
  cin >> Ncities >> Nroads;
  adj = vector<vector<int>>(Ncities);
  visited = vector<bool>(Ncities);
  for (int i = 0; i < Nroads; i++) {
    int a1, a2;
    cin >> a1 >> a2;
    adj[a1 - 1].push_back(a2 - 1);
    adj[a2 - 1].push_back(a1 - 1);
  }
  int conComp{};
  string ans{};
  dfs(0);
  for (int i = 1; i < Ncities; i++) {
    if (!visited[i]) {
      conComp++;
      ans += to_string(i) + " " + to_string(i + 1) + "\n";
      dfs(i);
    }
  }
  cout << conComp << endl;
  cout << ans;
}
