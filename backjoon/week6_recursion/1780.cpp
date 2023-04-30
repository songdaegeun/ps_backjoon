#include <iostream>
using namespace std;

int map[2188][2188];
int n;
int cnt[3];

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

int chk_integrity(int s_x, int s_y, int e_x, int e_y)
{
	int tmp = map[s_x][s_y];

	for (int i = s_x; i < e_x; i++)
	{
		for (int j = s_y; j < e_y; j++)
		{
			if(tmp != map[i][j])
				return (-2);
		}
	}
	return (tmp);
}

void chk_map(int n, int s_x, int s_y, int e_x, int e_y)
{		
	int chk = chk_integrity(s_x, s_y, e_x, e_y);
	if(chk == -2)
	{
		int size = n / 3;
		chk_map(n/3, s_x, s_y, s_x + size, s_y + size);
		chk_map(n/3, s_x, s_y + size, s_x + size, s_y + 2 * size);
		chk_map(n/3, s_x, s_y + 2 * size, s_x + size, s_y + 3 * size);
		chk_map(n/3, s_x + size, s_y, s_x + 2 * size, s_y + size);
		chk_map(n/3, s_x + size, s_y + size, s_x + 2 * size, s_y + 2 * size);
		chk_map(n/3, s_x + size, s_y + 2 * size, s_x + 2 * size, s_y + 3 * size);
		chk_map(n/3, s_x + 2 * size, s_y, s_x + 3 * size, s_y + size);
		chk_map(n/3, s_x + 2 * size, s_y + size, s_x + 3 * size, s_y + 2 * size);
		chk_map(n/3, s_x + 2 * size, s_y + 2 * size, s_x + 3 * size, s_y + 3 * size);
	}
	else
	{
		if(chk == -1)
			cnt[0]++;
		else if(chk == 0)
			cnt[1]++;
		else if(chk == 1)
			cnt[2]++;
	}	
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	chk_map(n, 0, 0, n, n);
	for(auto c:cnt)
		cout << c << '\n';
}

// -1 0 1

// 9
// 0 0 0 1 1 1 -1 -1 -1
// 0 0 0 1 1 1 -1 -1 -1
// 0 0 0 1 1 1 -1 -1 -1
// 1 1 1 0 0 0 0 0 0
// 1 1 1 0 0 0 0 0 0
// 1 1 1 0 0 0 0 0 0
// 0 1 -1 0 1 -1 0 1 -1
// 0 -1 1 0 1 -1 0 1 -1
// 0 1 -1 1 0 -1 0 1 -1