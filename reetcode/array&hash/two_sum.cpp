#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // nums을 순회하면서 이미 target-현재요소 가 탐색 map에 존재하는지 확인
		// 현재 요소 idx와 map에 저장된 idx를 임시객체로 반환.
		unordered_map<int,int> map;
		vector<int> ret;

		for(int i=0; i<nums.size(); i++) {
			if(map.find(target - nums[i]) != map.end()) {
				ret.push_back(map[target - nums[i]]);
				ret.push_back(i);
				return (ret);
			}
			map[nums[i]] = i;
		}
		return (ret);
    }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v({2,7,11,15});
	Solution s;
	cout << s.twoSum(v ,9)[0] << " " << s.twoSum(v ,9)[1];
}

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
