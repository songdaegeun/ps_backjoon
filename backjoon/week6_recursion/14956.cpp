#include <iostream>
#include <cstring>
using namespace std;

// int map[32769][32769];
// int tmp_map[32769][32769];
// int map[1024][1024];

pair<int,int> pillo(int n, int step)
{
	if(n == 2)
	{
		switch (step)
		{
			case 1:
				return {1, 1};
			case 2:
				return {1, 2};
			case 3:
				return {2, 2};
			case 4:
				return {2, 1};
		}
	}
	int half = n / 2;
	if(step <= half * half)
	{
		pair<int,int> res = pillo(half, step);
		return {res.second, res.first};
	}
	else if (step <= 2 * half * half)
	{
		pair<int,int> res = pillo(half, step - half * half);
		return {res.first, res.second + half};
	}
	else if (step <= 3 * half * half)
	{
		pair<int,int> res = pillo(half, step - 2 * half * half);
		return {res.first + half, res.second + half};
	}
	else
	{
		pair<int,int> res = pillo(half, step - 3 * half * half);
		return {2 * half - res.second + 1, half - (res.first - 1)};
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	pair<int,int> pos = pillo(n, m);
	cout << pos.first << ' ' << pos.second;
}
