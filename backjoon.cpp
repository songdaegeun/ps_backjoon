#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

int map[101][101];
int visited[101][101];
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
// bfs_map_chk()로 대륙마다 visited = 1, 2, 3... chk.
void bfs_map_chk()
{
	queue<pair<int,int>> q;
	int conti_num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(map[i][j] != 1 || visited[i][j] != 0) continue;
			conti_num++;
			visited[i][j] = conti_num;
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
					if(map[nx][ny] != 1 || visited[nx][ny] != 0) continue;
					visited[nx][ny] = conti_num;
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
	memset(dist, -1, sizeof(int) * 101 * 101);
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(visited[i][j] == 0) continue;
			dist[i][j] = 0;
			q.push({i, j});
			while(!q.empty())
			{
				pair<int,int> pos =  q.front(); q.pop();
				int x, y;
				tie(x, y) = pos;
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(dist[nx][ny] >= 0 || visited[nx][ny] == visited[i][j]) continue;
					if(visited[nx][ny] != 0 && visited[nx][ny] != visited[i][j])
					{
						while(!q.empty()) q.pop();  // clear q
						if(dist[x][y] == 0)
							cout << nx << ' ' << ny << '\n';
						min_val = min(dist[x][y], min_val);
						break;
					}
					dist[nx][ny] = dist[x][y] + 1;
					q.push({nx, ny});
				}
			}
			memset(dist, -1, sizeof(int) * 101 * 101);
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
	// 대륙의 개수 conti_num에 대해 vector<int> (conti_num, 0)으로 잡고, next_permutation으로 2개 선택(conti_1, conti_2).
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