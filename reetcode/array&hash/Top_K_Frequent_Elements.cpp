// Top K Frequent Elements
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		// nums을 순회하며 map에 {nums의 요소,등장횟수}로 cnt.
		// map의 등장횟수기준으로 sort해야함. -> bucket sort. idx가 등장횟수를 의미하는 배열에 value를 담는다!
		// 동일한 등장 횟수는 bucket에 push_back.
		vector<vector<int>> bucket(nums.size()+1);
		unordered_map<int,int> hash_map;
		for(auto el:nums) {
			hash_map[el]++;
		}
		for(unordered_map<int,int>::iterator it=hash_map.begin(); it != hash_map.end(); it++) {
			bucket[it->second].push_back(it->first);
		}
		vector<int> ret;
		for(int i=nums.size(); i >= 1; i--) {
			for(auto el:bucket[i]) {
				ret.push_back(el);
				if(ret.size() == k)
					break;
			}
		}
		return (ret);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	Solution s;
	vector<int> input_v({1,2});
	vector<int> v;
	v = s.topKFrequent(input_v, 2);
	for(auto el:v)
		cout << el << ' ';
}

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]


// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

