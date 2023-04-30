#include <iostream>
#include <cstring>
using namespace std;

int map[32769][32769];
int n;

void copy_map(int tmp_map[32769][32769])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp_map[i][j] = map[i][j];
		}
	}
}

void rotate(int dir)
{
	int tmp_map[32769][32769];

	copy_map(tmp_map);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// if(dir == 1)
			// 	map[i][j] = tmp_map[j][n - 1 - i];
			// else if(dir == -1)
			map[i][j] = tmp_map[n - 1 - j][i];
		}
	}
}

void col_reverse(int x, int y, int size)
{
	// int tmp_map[32769][32769];
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		tmp_map[i][j] = map[i][j];
	// 	}
	// }
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			map[i][j] = map[i][n - 1 - j];
		}
	}
}
void chk_path(int x, int y, int n, int *step)
{
	if(n == 2)
	{
		map[x + 0][y + 0] = (*step)++;
		map[x + 0][y + 1] = (*step)++;
		map[x + 1][y + 1] = (*step)++;
		map[x + 1][y + 0] = (*step)++;
		// base condition
		return ;
	}
	int size = n / 2;
	// -90 degree map rotate
	rotate(-1);
	chk_path(x, y, n / 2, step);
	// 90 degree map rotate
	for (int i = 0; i < 3; i++)
		rotate(-1);
	// rotate(1);
	col_reverse(x, y, n / 2);

	chk_path(x, y + size, n / 2, step);
	chk_path(x + size, y + size, n / 2, step);
	
	// 90 degree map rotate
	for (int i = 0; i < 3; i++)
		rotate(-1);
	// rotate(1);
	chk_path(x + size, y, n / 2, step);
	// -90 degree map rotate
	rotate(-1);
	col_reverse(x + size, y + size, n / 2);
}

pair<int,int> find_pos(int n, int m)
{
	pair<int,int> pos;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(m == map[i][j])
			{
				pos.first = i + 1;
				pos.first = j + 1;
				return (pos);
			}
		}
	}
	return (pos);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int m;
	cin >> n >> m;
	int step = 1;
	chk_path(0, 0, n, &step);
	pair<int,int> pos = find_pos(n, m);
	cout << pos.first << ' ' << pos.second;
}
