#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> numsMap;
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			numsMap[target - nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (numsMap.find(nums[i]) != numsMap.end()) {
				if (numsMap[nums[i]] != i) {
					ans = {numsMap[nums[i]], i};
					return ans;
				}
			}
		}
		return ans;
	}
};
