#include <bits/stdc++.h>

using namespace std;

int main() {
	int array_size;
	int target_sum;
	cin >> array_size >> target_sum;

	map<long long, int> frequency_of_prefix_sum;
	frequency_of_prefix_sum[0] = 1;

	long long subarrays_sum = 0;
	long long prefix_sum = 0;

	for (int i = 0; i < array_size; i++) {
		int x;
		cin >> x;
		prefix_sum += x;
		subarrays_sum += frequency_of_prefix_sum[prefix_sum - target_sum];
		frequency_of_prefix_sum[prefix_sum]++;
	}

	cout << subarrays_sum << endl;
	return 0;
}
