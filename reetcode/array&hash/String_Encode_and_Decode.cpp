// String Encode and Decode
#include <iostream>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string en_data;
		for(auto el:strs) {
			en_data += to_string(el.size())+":"+el;
		}
        return (en_data);
    }

    vector<string> decode(string s) {
        vector<string> de_data;
		string prev ="";
		int i=0;
		while(i<s.size()) {
			int len;
			int j = i;
			while(s[j]!=':') {
				j++;
			}
			len = stoi(s.substr(i,j-i));
			de_data.push_back(s.substr(j+1,len));
			i=j+len+1;
		}
		return (de_data);
    }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	Solution s;

}