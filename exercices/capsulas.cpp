#include <bits/stdc++.h>

using namespace std;

long long calcCaps(int x, const vector<int> &capsulesFreq) {
	long long total{};
	for (int c : capsulesFreq) {
		total += x / c;
	}
	return total;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long f;
	cin >> n >> f;
	vector<int> freqCapsule(n);
	for (int i = 0; i < n; i++) {
		cin >> freqCapsule[i];
	}

	int left = 1;
	int right = 1e9;

	while (left < right - 1) {
		int m = left + (right - left) / 2;
		long long sum = calcCaps(m, freqCapsule);
		if (sum >= f) {
			right = m;
		} else {
			left = m;
		}
	}
	cout << right << endl;
}
