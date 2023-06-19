#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st;
	vector<char> v;
	int arr[100001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		st.push(i);
		v.push_back('+');
		while(!st.empty() && st.top() == arr[idx]) {
			st.pop();
			v.push_back('-');
			idx++;
		}
	}

	if(!st.empty()) {
		cout << "NO\n";
	}
	else {
		for(auto el:v) {
			cout << el << '\n';
		}
	}
	

}