#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";

		string ans = strs[0];
		for (string word : strs) {
			while (word.find(ans) != 0) {
				ans.pop_back();
				if (ans.empty()) return "";
			}
		}
		return ans;
	}
};
