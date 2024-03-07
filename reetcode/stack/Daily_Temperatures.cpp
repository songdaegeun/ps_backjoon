// Daily_Temperatures
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<pair<int,int>> st;
		vector<int> ret(temperatures.size());
		for(int i=0; i<temperatures.size(); i++) {
			while(!st.empty() && st.top().first < temperatures[i]) {
				ret[st.top().second] = i-st.top().second;
				st.pop();
			}
			st.push({temperatures[i],i});
		}
		return (ret);
	}
};

int main() {

}
// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]