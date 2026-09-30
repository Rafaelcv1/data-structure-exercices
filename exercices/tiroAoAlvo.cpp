#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long circles_number, tiros;
	cin >> circles_number >> tiros;
	vector<long long> circles(circles_number);

	for (int i = 0; i < circles_number; i++) {
		long long x;
		cin >> x;
		circles[i] = x * x;
	}

	long long points{};
	for (int i = 0; i < tiros; i++) {
		long long x, y;
		cin >> x >> y;
		long long inside_circles = lower_bound(circles.begin(), circles.end(), x*x + y*y) - circles.begin();
		points += circles_number - inside_circles;
	}
	cout << points << endl;
}
