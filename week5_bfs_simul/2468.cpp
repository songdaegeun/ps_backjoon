#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[102][102];
int visited[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void map_copy(int tmp_map[][102]);
void disp_map(int tmp_map[][102]);

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
	int min, max;
	min = 100;
	max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(min > map[i][j])
				min = map[i][j];
			if(max < map[i][j])
				max = map[i][j];
		}
	}
	int max_cnt = 0;
	for(int height = min - 1; height <= max; height++)
	{
		int tmp_map[102][102];
		map_copy(tmp_map);
		memset(visited, 0, sizeof(int) * 102 * 102);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tmp_map[i][j] <= height)
					tmp_map[i][j] = 0;
			}
		}
		// disp_map(tmp_map);
		queue<pair<int, int>> q;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(visited[i][j] || tmp_map[i][j] == 0) continue;
				cnt++;
				visited[i][j] = 1;
				q.push({i,j});
				while(!q.empty())
				{
					pair<int,int> pos = q.front();
					q.pop();
					int x = pos.first;
					int y = pos.second;
					for(int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(visited[nx][ny] || tmp_map[nx][ny] == 0) continue;
						visited[nx][ny] = 1;
						q.push({nx,ny});
					}
				}
			}
		}
		// cout << cnt << '\n';
		if (max_cnt < cnt)
			max_cnt = cnt;
	}
	cout << max_cnt;
}

void map_copy(int tmp_map[][102])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp_map[i][j] = map[i][j];
		}
	}
}

void disp_map(int tmp_map[][102])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << tmp_map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
// 5
// 6 8 2 6 2
// 3 2 3 4 6
// 6 7 3 3 2
// 7 2 5 3 6
// 8 9 5 2 7