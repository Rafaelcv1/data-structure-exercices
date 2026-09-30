#include "longestCommonPrefix.cpp"

int main() {
	vector<string> s = {"ab", "a"};
	Solution sol;
	sol.longestCommonPrefix(s);
	s = {"flower","flow","flight"};
	sol.longestCommonPrefix(s);
	s = {"dog","racecar","car"};
	sol.longestCommonPrefix(s);
	return 0;
}
