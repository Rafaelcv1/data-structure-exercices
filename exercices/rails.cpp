#include <bits/stdc++.h>

using namespace std;

int main() {
	int caseLen{};
	while (cin >> caseLen && caseLen != 0) {
		for (int i = 0; i < caseLen; ++i) {
			vector<int> sequenceAfterStation;
			int valor;
            while (cin >> valor && valor != 0) {
				sequenceAfterStation.push_back(valor-1);
            }
			int pointerAfterStation = 0;
			int pointerBeforeStation = 0;
			stack<int> stack;
			while (pointerAfterStation < caseLen) {
				while (pointerBeforeStation != sequenceAfterStation[pointerAfterStation] && pointerBeforeStation < caseLen) {
					stack.push(pointerBeforeStation);
					pointerBeforeStation++;
				}
			}
        }
    }
	return 0;
}
