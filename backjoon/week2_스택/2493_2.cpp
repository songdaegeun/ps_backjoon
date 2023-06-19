#include <iostream>
#include <stack>
using namespace std;

stack<pair<int,int>> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int height;
		int idx;
		cin >> height;
		while(!st.empty() && st.top().first < height) {
			st.pop();
		}
		if(st.empty()) {
			idx = 0;
		}
		else {
			idx = st.top().second;
		}
		st.push({height, i});
		cout << idx;
		if(i != n)
			cout << ' ';
	}
}

// 5
// 6 9 5 7 4