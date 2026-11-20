#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

unordered_map<char, vector<char>> adj;
unordered_map<char, int> deg;
list<char> s = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void dep(char a, char b) {
  adj[a].push_back(b);
  deg[a];
  deg[b]++;
  s.remove(a);
  s.remove(b);
}
int main() {
  int n;
  cin >> n;

  vector<string> words;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    words.push_back(tmp);
  }
  for (int i = 1; i < words.size(); i++) {
    bool notChanged = true;
    for (size_t c = 0; c < min(words[i - 1].size(), words[i].size()); c++) {
      if (words[i][c] != words[i - 1][c]) {
        dep(words[i - 1][c], words[i][c]);
        notChanged = false;
        break;
      }
    }
    if (notChanged && words[i - 1].size() > words[i].size()) {
      cout << "Impossible";
      return 0;
    }
  }

  queue<char> q;
  for (auto w : deg)
    if (w.second == 0) q.push(w.first);

  while (!q.empty()) {
    char cur = q.front();
    q.pop();
    s.push_back(cur);
    for (char next : adj[cur]) {
      deg[next]--;
      if (deg[next] == 0) q.push(next);
    }
  }
  if (s.size() == 26) {
    for (char c : s) {
      cout << c;
    }
  } else {
    cout << "Impossible";
  }
  cout << endl;
  return 0;
}
