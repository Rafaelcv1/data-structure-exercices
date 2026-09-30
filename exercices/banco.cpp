#include <bits/stdc++.h>

using namespace std;

int main() {
	int numOfTellers, numOfClients;
	cin >> numOfTellers >> numOfClients;
	int time;
	queue<pair<int, int>> clientQueue;
	int clientWaitingTooMuch{};

	int Tellers[numOfTellers];
	fill(Tellers, Tellers + numOfTellers, 0);

	for (int i = 0; i < numOfClients; i++) {
		pair<int, int> client;
		cin >> client.first >> client.second;
		clientQueue.push(client);
	}
	while (!clientQueue.empty()) {
		int nextTellerToServe{};
		for (int i = 1; i < numOfTellers; i++) {
			if (Tellers[nextTellerToServe] > Tellers[i]) {
				nextTellerToServe = i;
			}
		}
		if (Tellers[nextTellerToServe] - clientQueue.front().first > 20) {
			clientWaitingTooMuch++;
		}
		Tellers[nextTellerToServe] = max(Tellers[nextTellerToServe], clientQueue.front().first) + clientQueue.front().second;
		clientQueue.pop();
	}

	cout << clientWaitingTooMuch << endl;
	return 0;
}
