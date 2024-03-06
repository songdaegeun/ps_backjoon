// 3Sum
#include <iostream>
// #include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		// unordered_set<vector<int>> set_ret;
		set<vector<int>> set_ret;
		sort(nums.begin(), nums.end());

		for(int i=0; i<nums.size()-2; i++) {
			int st = i+1;
			int en = nums.size()-1;
			while(st<en) {
				if(nums[st]+nums[en]+nums[i] == 0) {
					vector<int> vec;
					vec.push_back(nums[st]);
					vec.push_back(nums[i]);
					vec.push_back(nums[en]);
					set_ret.insert(vec);
					st++;
					en--;
				}
				if(st<en && nums[st]+nums[en]+nums[i] < 0)
					st++;
				else if(st<en && nums[st]+nums[en]+nums[i] > 0)
					en--;
			}
		}
		vector<vector<int>> ret(set_ret.begin(), set_ret.end());
		return (ret);
	}
};

int main() {
	Solution s;

}


// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.