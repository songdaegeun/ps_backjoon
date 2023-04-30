#include <iostream>
using namespace std;

int map[129][129];
int n;
int cnt[2];

void disp_map()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int integrity_map(int n, int x, int y)
{
	for(int i = x; i < x + n; i++)
	{
		for(int j = y; j < y + n; j++)
		{
			if(map[x][y] != map[i][j])
				return (0);
		}
	}
	return (1);
}

void search_map(int n, int x, int y)
{
	if(integrity_map(n, x, y))
	{
		cnt[map[x][y]]++;
		return ;
	}
	int size = n / 2;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			search_map(size, x + i * size, y + j * size);
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
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	search_map(n, 0, 0);
	cout << cnt[0] << '\n';
	cout << cnt[1] << '\n';
	
}

// 8
// 1 1 0 0 0 0 1 1
// 1 1 0 0 0 0 1 1
// 0 0 0 0 1 1 0 0
// 0 0 0 0 1 1 0 0
// 1 0 0 0 1 1 1 1
// 0 1 0 0 1 1 1 1
// 0 0 1 1 1 1 1 1
// 0 0 1 1 1 1 1 1