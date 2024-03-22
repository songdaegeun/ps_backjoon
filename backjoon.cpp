// Valid Anagram
// hash_map

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string,int> map;
	map["st"] = 2;
	cout << map["st"];
}

