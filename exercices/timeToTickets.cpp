#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
		int ans = tickets[k];
		for (int i = 0; i < k; i++) {
			ans+=min(tickets[i], tickets[k]);
		}
		for (int i = k+1; i < tickets.size(); i++) {
			ans+=min(tickets[k]-1, tickets[i]);
		}
		return ans;
    }
};

int main() {
	Solution s;
	vector<int> tickets = {5,1,1,1};
	cout << s.timeRequiredToBuy(tickets, 0) << endl;
}
