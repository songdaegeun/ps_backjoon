#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
int map[51][51];
int dist[51][51];
int back_up_map[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int, int>> virus_space;

int bfs() {
	memset(dist, -1, sizeof(dist));
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 3) {
				dist[i][j] = 0;
				q.push({i,j});
			}
		}
	}
	int min_time = 0;
	while(!q.empty()) {
		int x, y;
		x = q.front().first;
		y = q.front().second; q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(map[nx][ny] == 1) continue;   // map이 벽이거나
			if(dist[nx][ny] != -1) continue; // 방문했던곳
			map[nx][ny] = 3;
			dist[nx][ny] = dist[x][y] + 1;
			min_time = dist[nx][ny];
			q.push({nx,ny});
		}
	}
	return (min_time);
}

int chk_virus_full()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != 1 && map[i][j] != 3)
				return (0);
		}
	}
	return (1);
}

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 2) {
				virus_space.push_back({i,j});
			}
		}
	}
	// virus_space C m
	int size_v = virus_space.size();
	vector<int> mask(size_v, 0);

	for (int i = size_v - 1; i > size_v - 1 - m; i--)
	{
		mask[i] = 1;
	}
	int defusion_time;
	int min_time = 987654321;
	do
	{
		// 0 or 2인 공간에 퍼질수있는 맵을 만든다.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				back_up_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < size_v; i++)
		{
			if(mask[i] == 1) {
				map[virus_space[i].first][virus_space[i].second] = 3;
			}
		}
		// disp_map();
		defusion_time = bfs();
		// disp_map();
		if (chk_virus_full() && min_time > defusion_time) {
			min_time = defusion_time;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = back_up_map[i][j];
			}
		}
	} while (next_permutation(mask.begin(), mask.end()));
	if(min_time == 987654321)
		cout << -1 << '\n';
	else
		cout << min_time << '\n';
}

// 예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자. 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸이다.

// 7 3
// 2 0 0 0 1 1 0
// 0 0 1 0 1 2 0
// 0 1 1 0 1 0 0
// 0 1 0 0 0 0 0
// 0 0 0 2 0 1 1
// 0 1 0 0 0 0 0
// 2 1 0 0 0 0 2