#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int st = 0;
		int en = nums.size()-1;
		while(st <= en) {
			int med_idx = (st+en)/2;
			if(nums[med_idx] == target)
				return (med_idx);
			else if(nums[med_idx] < target)
				st = med_idx+1;
			else if(nums[med_idx] > target)
				en = med_idx-1;
		}
		return (-1);
	}
};

int main() {
	Solution s;
	vector<int> v({-1,0,3,5,9,12});
	cout << s.search(v, 9);
}


// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4