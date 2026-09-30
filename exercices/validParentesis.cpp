#include <stack>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
  public:
	bool isValid(string s) {
		stack<char> stack;
		unordered_map<char, char> checkCloseMap;
		checkCloseMap['}'] = '{';
		checkCloseMap[')'] = '(';
		checkCloseMap[']'] = '[';

		for (char c : s) {
			if (checkCloseMap.find(c) == checkCloseMap.end()) {
				stack.push(c);
			} else if (stack.size() != 0) {
				if (stack.top() == checkCloseMap[c]) {
					stack.pop();
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
		if (stack.size() == 0) {
			return true;
		} else {
			return false;
		}
	}
};
