// Valid_Palindrome
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		int st = 0;
		int en = s.size()-1;
		while(st < en) {
			while(!isalnum(s[st]) && st < en)
				st++;
			while(!isalnum(s[en]) && st < en)
				en--;
			if(tolower(s[st])!=tolower(s[en]))
				return (false);
			st++;
			en--;
		}
		return (true);
	}
};
 
int main() {
	Solution s;

}

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.