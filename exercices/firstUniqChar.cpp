#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
	int firstUniqChar(string s) {
		unordered_map<char, int> charCount;
		for (char c : s) {
			if (charCount.find(c) != charCount.end()) {
				charCount[c]++;
			} else {
				charCount[c] = 1;
			}
		}
		for (int i = 0; i < s.length(); i++) {
			if (charCount[s[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};
