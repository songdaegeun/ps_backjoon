#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st = 0;
        int en = 0;
        unordered_set<int> set;
        int max_len = 0;
        
        while(en < s.size()) {
            if(set.find(s[en]) == set.end()) {
                set.insert(s[en]);
                if(max_len < (int)set.size()) {
                    max_len = (int)set.size();
                }
                en++;
            }
            else {
                set.insert(s[en]);
                while(s[st] != s[en]) {
                    set.erase(s[st]);
                    st++;
                }
                set.erase(s[st]);
                st++;
            }
        }
        return (max_len);
    }
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);


}