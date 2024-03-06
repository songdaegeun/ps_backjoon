#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> set;
		for(auto el:nums) {
			if(set.find(el) != set.end())
				return (true);
			set.insert(el);
		}
		return (false);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	Solution s;
	vector<int> v({1,2,3,4});
	cout << s.containsDuplicate(v);

}

// Input: nums = [1,2,3,1]
// Output: true
