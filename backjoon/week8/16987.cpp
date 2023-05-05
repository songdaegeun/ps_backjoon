#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> v;
int n, ans;

void egg_crash(int depth)
{
	if(depth == n)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if(v[i].first <= 0)
				cnt++;
		}
		if(ans < cnt) ans = cnt;
		return ;
	}
	int crash_flag = 0;
	for (int i = 0; i < n; i++)
	{
		if(i == depth) continue;
		if(v[i].first > 0) crash_flag = 1;
	}
	// 꺼낸 계란이 깨졌거나 깨지지 않은 다른 계란이 없는 경우
	if(v[depth].first <= 0 || crash_flag == 0)
		egg_crash(depth + 1);
	else
	{
		for (int i = 0; i < n; i++)
		{
			if(v[i].first > 0 && i != depth)
			{
				v[depth].first -= v[i].second;
				v[i].first -= v[depth].second;
				egg_crash(depth + 1);
				v[depth].first += v[i].second;
				v[i].first += v[depth].second;
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int durability;
		int weight;
		cin >> durability >> weight;
		v.push_back({durability, weight});
	}
	egg_crash(0);
	cout << ans;
}

// 3
// 8 5
// 1 100
// 3 5