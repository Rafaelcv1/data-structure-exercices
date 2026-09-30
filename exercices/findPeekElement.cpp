#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while (left + 1 != right) {
			int m = (left+right)/2;
				if (nums[m] < nums[right]) {
					right = m;
				} else {
					left = m;
			}
		}
		return right;
    }
};
int main() {
	vector<int> n = {1,2,3,1};
	n = {1,2,1,3,5,6,4};
	Solution s;
	s.findPeakElement(n);
}
