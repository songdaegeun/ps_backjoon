#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v1,v2;
	v1={1,2,3};
	v2 = v1;
	for(auto el:v2) {
		cout << el << ' ';
	}
	cout << '\n';

	return (0);
}