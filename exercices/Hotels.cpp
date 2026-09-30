#include <bits/stdc++.h>

using namespace std;

int main() {
    long long array_size;
    cin >> array_size;
    long long budget;
    cin >> budget;
    vector<long long> vector(array_size);
    long long highest_in_budget = 0;
    
    for (long long i = 0; i < array_size; i++) {
        cin >> vector[i];
    }

    long long left = 0;
    long long sum = 0;
    for (long long right = 0; right < array_size; right++) {
        sum+= vector[right];
        while (sum > budget || left > right) {
            sum-=vector[left];
            left++;
        }
        if (sum > highest_in_budget) highest_in_budget = sum;
    }
    cout << highest_in_budget << '\n';
    return 0;
}
