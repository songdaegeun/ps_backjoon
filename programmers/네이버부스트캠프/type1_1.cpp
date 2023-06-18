#include <iostream>
#include <vector>
using namespace std;

int cnt[10];

// 8
// 1 2 3 3 3 3 4 4

// 9
// 3 2 4 4 2 5 2 5 5

// 5
// 3 5 7 9 1

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int data;
		// data는 0~9
		cin >> data;
		cnt[data]++;
	}
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		if (cnt[i] > 1)
		{
			v.push_back(cnt[i]);
		}
	}
	if(!v.empty()) {
		for(auto el:v)
		{
			cout << el << ' ';
		}
	}
	else
		cout << -1;
	cout << '\n';
}