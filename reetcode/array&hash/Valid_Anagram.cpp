// Valid Anagram
// hash_map

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		unordered_map<int,int> map;

		for(auto el:s) {
			map[el]++;
		}
		for(auto el:t) {
			map[el]--;
		}
		for(auto el:map) {
			if(el.second != 0) {
				return (false);
			}
		}
		return (true);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	Solution s;
	cout << s.isAnagram("anagram", "nagaram");
}



// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
