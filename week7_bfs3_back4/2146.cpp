#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

int map[101][101];
int chked_map[101][101];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int min_val;

void disp_map()
{
	for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << ' ';
		}
	}
}

void bfs_map_chk()
{
	queue<pair<int,int>> q;
	int conti_num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(map[i][j] != 1 || chked_map[i][j] != 0) continue;
			conti_num++;
			chked_map[i][j] = conti_num;
			q.push({i, j});
			while(!q.empty())
			{
				pair<int,int> pos = q.front(); q.pop();
				int x, y;
				tie(x,y) = pos;
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(map[nx][ny] != 1 || chked_map[nx][ny] != 0) continue;
					chked_map[nx][ny] = conti_num;
					q.push({nx, ny});
				}
			}
		}
	}
}

// 모든 육지에 대한 bfs
void bfs_dist()
{
	int dist[101][101];
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
            memset(dist, -1, sizeof(int) * 101 * 101);
			if(chked_map[i][j] == 0) continue;
			dist[i][j] = 0;
			q.push({i, j});
			while(!q.empty())
			{
				pair<int,int> pos =  q.front(); q.pop();
				int x, y;
				tie(x, y) = pos;
				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(dist[nx][ny] >= 0 || chked_map[nx][ny] == chked_map[i][j]) continue;
					if(chked_map[nx][ny] != 0 && chked_map[nx][ny] != chked_map[i][j])
					{
						while(!q.empty()) q.pop();  // clear q
						min_val = min(dist[x][y], min_val);
						break;
					}
					dist[nx][ny] = dist[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	min_val = 2 * n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	bfs_map_chk();
	bfs_dist();
	// 최소값 출력
	cout << min_val;
}

// 10
// 1 1 1 0 0 0 0 1 1 1
// 1 1 1 1 0 0 0 0 1 1
// 1 0 1 1 0 0 0 0 1 1
// 0 0 1 1 1 0 0 0 0 1
// 0 0 0 1 0 0 0 0 0 1
// 0 0 0 0 0 0 0 0 0 1
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 1 1 0 0 0 0
// 0 0 0 0 1 1 1 0 0 0
// 0 0 0 0 0 0 0 0 0 0