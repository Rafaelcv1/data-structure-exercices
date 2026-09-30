#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int dice_array_lenght;
	int dice_number;
	cin >> dice_array_lenght >> dice_number;
	vector<double> expected_value;
	double max_expected_value_sum = 0;
	for (int i = 0; i < dice_array_lenght; i++) {
		int x;
		cin >> x;
		expected_value.push_back((x+1)/2.0);
	}

	double expected_value_sum = 0;
	for (int i = 0 ; i < dice_array_lenght; i++) {
		if (i < dice_number) {
			expected_value_sum += expected_value[i];
		} else {
			expected_value_sum += expected_value[i] - expected_value[i - dice_number];
		}
		if (expected_value_sum > max_expected_value_sum) max_expected_value_sum = expected_value_sum;
	}
	cout << fixed << setprecision(10) << max_expected_value_sum << endl; }
