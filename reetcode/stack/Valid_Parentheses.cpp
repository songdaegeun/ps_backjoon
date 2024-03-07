// Valid_Parentheses

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<int> st;

		for(auto el:s) {
			if(el == '(' || el == '{' || el == '[')
				st.push(el);
			else {
				if(!st.empty()) {
					if(st.top() == '(' && el == ')' || (st.top() == '{' && el == '}') || (st.top() == '[' && el == ']')) {
						st.pop();
						continue;
					}
				}
				return (false);
			}
		}
		if(st.empty())
			return (true);
		else 
			return (false);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

}
// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true