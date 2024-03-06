#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // strs을 순회하며 각 요소의 anagram set을 map에 저장한다{anagram set, vector of str요소}. 
	// map을 순회하며 second요소들을 vector로 만들어 반환한다.
		unordered_map<string, vector<string>> ret;
		for(auto str:strs) {
			vector<int> anagram_cnt(26,0);	
			for(auto el:str) {
				anagram_cnt[el-'a']++;
			}
			string key = "";
			for(int i=0; i<26; i++)
				key += to_string(anagram_cnt[i])+",";
			ret[key].push_back(str);
		}
		vector<vector<string>> real_ret;
		for(auto el:ret) {
			real_ret.push_back(el.second);
		}
		return (real_ret);
    }
};
 
int main() {
	Solution s;
	vector<string> vec({"eat","tea","tan","ate","nat","bat"});
	vector<vector<string>> ans = s.groupAnagrams(vec);
	for(auto el:ans) {
		cout << "[";
		for(auto e:el) {
			cout << e << ',';
		}
		cout << "]";
	}
}


// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]