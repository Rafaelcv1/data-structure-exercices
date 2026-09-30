#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		unordered_set<string> ans;
		unordered_map<string, int> hashmap;

		if (s.size() < 10) { return {};}

		for (int i = 0;  i < s.size()-9; i++) {
			string temp = s.substr(i,10);
			hashmap[temp]++;
			if (hashmap[temp] > 1) ans.insert(temp);
		}
    	vector<string> my_vector(ans.begin(), ans.end());
		return my_vector;
    }
};
