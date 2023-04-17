#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int map[21][21];
int mov_num = 1;

void disp_map(int map[][21])
{
	cout << '\n';
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int search_max(int map[][21])
{
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			max = std::max(map[i][j], max);
		}
	}
	return (max);
}

void copy_map(int dst_map[][21], int src_map[][21])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dst_map[i][j] = src_map[i][j];
		}
	}
}

void mov_map(int tmp_map[][21], int dir)
{
	if (dir == 1)
	{
		for (int i = 0; i < n; i++)
		{
			int can_mov = 0;
			for (int k = 0; k < n; k++)
			{
				for(int j = n - 1 - k; j >= 0; j--)
				{
					int cmp = tmp_map[i][j - 1];
					int l;
					for(l = j - 1; cmp == 0 && l >= 0; l--)
					{
						cmp = tmp_map[i][l];;
					}
					if (j != 0 && !can_mov && ((tmp_map[i][j] == cmp) || tmp_map[i][j] == 0))
					{
						can_mov = 1;
						tmp_map[i][j] += tmp_map[i][l];
						tmp_map[i][l] = 0;
					}
					else if (j == 0 && can_mov)
						tmp_map[i][j] = 0;
					else if (j != 0 && can_mov)
						tmp_map[i][j] = cmp;
				}
			}
		}
	}
	else if (dir == 3)
	{
		for (int i = 0; i < n; i++)
		{
			int can_mov = 0;
			for (int k = 0; k < n; k++)
			{
				for(int j = k; j < n; j++)
				{
					int cmp = tmp_map[i][j + 1];
					int l;
					for(l = j + 1; cmp == 0 && l < n; l++)
					{
						cmp = tmp_map[i][l];;
					}
					if ((j != (n - 1)) && !can_mov && ((tmp_map[i][j] == cmp) || tmp_map[i][j] == 0))
					{
						can_mov = 1;
						tmp_map[i][j] += tmp_map[i][l];
						tmp_map[i][l] = 0;
					}
					else if (j == (n - 1) && can_mov)
						tmp_map[i][j] = 0;
					else if ((j != (n - 1)) && can_mov)
						tmp_map[i][j] = cmp;
				}
			}
		}
	}
	else if (dir == 2)
	{
		for (int i = 0; i < n; i++)
		{
			int can_mov = 0;
			for (int k = 0; k < n; k++)
			{
				for(int j = n - 1 - k; j >= 0; j--)
				{
					int cmp = tmp_map[j][i - 1];
					int l;
					for(l = j - 1; cmp == 0 && l >= 0; l--)
					{
						cmp = tmp_map[j][l];;
					}
					if (j != 0 && !can_mov && ((tmp_map[j][i] == cmp) || tmp_map[j][i] == 0))
					{
						can_mov = 1;
						tmp_map[j][i] += tmp_map[j][l];
						tmp_map[j][l] = 0;
					}
					else if (j == 0 && can_mov)
						tmp_map[j][i] = 0;
					else if (j != 0 && can_mov)
						tmp_map[j][i] = cmp;
				}
			}
		}
	}
	else if (dir == 0)
	{
		for (int i = 0; i < n; i++)
		{
			int can_mov = 0;
			for (int k = 0; k < n; k++)
			{
				for(int j = k; j < n; j++)
				{
					int cmp = tmp_map[j][i + 1];
					int l;
					for(l = j + 1; cmp == 0 && l < n; l++)
					{
						cmp = tmp_map[j][l];;
					}
					if ((j != (n - 1)) && !can_mov && ((tmp_map[j][i] == cmp) || tmp_map[j][i] == 0))
					{
						can_mov = 1;
						tmp_map[j][j] += tmp_map[j][l];
						tmp_map[j][l] = 0;
					}
					else if (j == (n - 1) && can_mov)
						tmp_map[j][i] = 0;
					else if ((j != (n - 1)) && can_mov)
						tmp_map[j][i] = cmp;
				}
			}
		}
	}
}

int brute_force(int depth, int *max, int tmp_map[][21])
{
	if(depth == mov_num)
		return (0);
	for(int dir = 0; dir < 4; dir++)
	{
		int backup_map[21][21];
		copy_map(backup_map, tmp_map);
		mov_map(tmp_map, dir);
		disp_map(tmp_map);
		int max_el = search_max(tmp_map);
		*max = std::max(max_el, *max);
		brute_force(depth + 1, max, tmp_map);
		copy_map(tmp_map, backup_map);
	}
	return (*max);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	// 최대 5번 민다.
	// map을 u,d,r,l방향으로 밀면서 각 경우에 element의 max값을 저장한다. 
	// u 후 l 와 l 후 u은 동일한 결과를 갖지 않으므로, bfs가 아닌 완전탐색을 한다. 
	// max를 출력한다.
	int max = 0;
	int tmp_map[21][21];
	copy_map(tmp_map, map);
	cout << brute_force(0, &max, tmp_map);
}

// 3
// 2 2 2
// 4 4 4
// 8 8 8
