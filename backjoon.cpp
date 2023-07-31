#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[51][51];
int back_up_map[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int, int>> virus_space;

void bfs() {
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 3) {
				q.push({i,j});
			}
		}
	}
	while(!q.empty()) {
		int x, y;
		x = q.front().first;
		y = q.front().second; q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i];
			int ny = dy[i];
			
			if(oob()) continue;
			if(map[nx][ny] == 0 || map[nx][ny] == 2) {

			}
		}
		
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
	vector<int> mask(size_v);

	for (int i = size_v - 1; i >= 0; i--)
	{
		mask[i] = 1;
	}

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
		bfs();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = back_up_map[i][j];
			}
		}
	} while (next_permutation(mask.begin(), mask.end()));
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