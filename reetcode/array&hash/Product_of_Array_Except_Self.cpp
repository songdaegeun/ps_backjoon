#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		// dp[i] : 자신을 포함한 nums[i] 이전 요소들의 곱
		vector<int> ret(nums.size());
		
		vector<int> dp1(nums.size());
		vector<int> dp2(nums.size());
		
		dp1[0] = nums[0];
		for(int i=1; i<nums.size(); i++) {
			dp1[i] = nums[i] *dp1[i-1];
		}
		dp2[nums.size()-1] = nums[nums.size()-1];
		for(int i=nums.size()-2; i>=0; i--) {
			dp2[i] = nums[i]*dp2[i+1];
		}
		for(int i=0; i<nums.size(); i++) {
			if(i==0)
				ret[i] = dp2[i+1];
			else if(i == nums.size()-1)
				ret[i] = dp1[i-1];
			else
				ret[i] = dp1[i-1]*dp2[i+1];
		}
		return (ret);
	}
};

int main() {
	Solution s;

}


// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]