#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n_cases;
	cin >> n_cases;
	for (int i = 0; i < n_cases; i++) {
		int fav_lenght;
		cin >> fav_lenght;
		vector<int> vector;
		for (int i = 0; i < fav_lenght; i++) {
			int x;
			cin >> x;
			vector.push_back(x);
		}
		int left = 0;
		int right = fav_lenght - 1;
		for (int i = 0; i < fav_lenght; i++) {
			if (i % 2 == 0 ) {
				cout << vector[left];
				left++;
			} else {
				cout << vector[right];
				right--;
			}
			if (i != fav_lenght- 1) cout << " ";
		}
		cout << endl;
	}
}
