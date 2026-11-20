#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> canva;

int ff(int x, int y) {
    int output{};
    queue<pair<int,int>> q;
    int xDesl[] = {0,0,1,-1,1,1,-1,-1};
    int yDesl[] = {1,-1,0,0,1,-1,1,-1};
    q.push(pair(x,y));
    canva[x][y]=1;
    output++;
    while (!q.empty()) {
        pair<int,int> curr = q.front();q.pop();
        for (int i = 0; i < 8; i++) {
            if (curr.first + xDesl[i] >= 0 && curr.second + yDesl[i] >= 0 && curr.first + xDesl[i] < canva.size() && curr.second + yDesl[i] < canva[0].size() && canva[curr.first + xDesl[i]][curr.second + yDesl[i]] == 0) {
                q.push(pair<int,int>(curr.first + xDesl[i], curr.second + yDesl[i]));
                canva[curr.first + xDesl[i]][curr.second + yDesl[i]]=1;
                output++;
            }
        }
    }
    return output;
}

int main() {
    int rows, cols, x, y, k;
    cin >> rows >> cols >> x >> y >> k;
    canva = vector<vector<int>> (rows, std::vector<int>(cols, 0));

    for (int i = 0; i < k; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        canva[a1-1][a2-1] = 1;
    }
    cout << ff(x-1,y-1);
}
