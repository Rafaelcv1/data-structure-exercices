#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	pair<int, int> minor_time_player = {1e9, 0};
	for (int i = 0; i < n; i++) {
		int player_sum = 0;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			player_sum += x;
		}
		if (player_sum < minor_time_player.first) {
			minor_time_player= {player_sum, i+1};
		}
	}
	cout << minor_time_player.second;
}
