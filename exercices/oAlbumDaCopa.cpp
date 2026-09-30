#include <bits/stdc++.h>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<int> has_number{};
	for (int  i = 0; i < m; i++) {
		int x;
		cin >> x;
		has_number.insert(x);
	}
	cout << n - has_number.size() << endl;
}
