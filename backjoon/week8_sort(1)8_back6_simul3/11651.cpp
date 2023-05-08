#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<pair<int,int>> v;
	cin >> n;
	while(n--)
	{
		pair<int,int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), [&](pair<int,int> a, pair<int,int> b){
		if(a.second != b.second) return (a.second < b.second);
		else
			return (a.first < b.first);
	});
	for(auto el:v)
	{
		cout << el.first << ' ' << el.second << '\n';
	}
}

// 5
// 3 4
// 1 1
// 1 -1
// 2 2
// 3 3