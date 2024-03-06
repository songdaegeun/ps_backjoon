// Longest Consecutive Sequence
// O(n)
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		// nums을 순회하면서 가장 긴 연속 요소 시퀀스의 길이를 알아내야한다.
		// nums을 set에 저장한다.
		// set을 순회하면서 요소-1이 존재하지 않으면 시작값이므로, 그때부터 연속되는 요소가 존재하지 않을때까지 cnt해서 len을 알아낸다.
		// len의 최대값을 출력한다.
		unordered_set hash_set(nums.begin(), nums.end());
		int ret = -1;
		for(auto el:hash_set) {
			if(hash_set.find(el-1) == hash_set.end()) {
				int len = 1;
				while(hash_set.find(el+len) != hash_set.end()) {
					len++;
				}
				ret = max(ret,len);
			}
		}
		return (ret);
	}
};


// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
