#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	unordered_map<string, bool> inDict;
	vector<bool> pOfI;
	string str;

	bool p(int x) {
		if (x == 0) return true;
		for (int i = 0; i < x; i++) {
			if (pOfI[i] && inDict[str.substr(i, x-i)])
				return true;
		}
		return false;
	}
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		str = s;
		for (string palavra : wordDict) inDict[palavra] = true;
		for (int i = 0; i <= s.size(); i++) {
			pOfI.push_back(p(i));
		}
		return pOfI[s.size()];
	}
};

int main() {
	Solution s;
	vector<string> dict = {"leet", "code"};
	cout <<s.wordBreak("leetcodea", dict) << endl;

	return 0;
}
