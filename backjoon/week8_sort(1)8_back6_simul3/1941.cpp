#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

char map[5][5];
char princess_mark[5][5];
char visited[5][5];

int mask[25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

void disp_map(int tmp_map[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << tmp_map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs_7_adjacent(queue<pair<int, int>>& q)
{
	int adj = 0;
	int dasom = 0;
	while(!q.empty())
	{
		pair<int,int> pos = q.front(); q.pop();
		adj++;
		int x, y;
		tie(x, y) = pos;
		if(map[x][y] == 'S')
			dasom++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || !princess_mark[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
	if(adj == 7 && dasom >= 4)
		ans++;
}

void combi(int m)
{
	for (int i = 0; i < 25; i++) (i < m)? mask[i] = 0 : mask[i] = 1; 
	do
	{
		memset(visited, 0, 25);
		memset(princess_mark, 0, 25);

		queue<pair<int, int>> q;
		for (int i = 0; i < 25; i++)
		{
			if(!mask[i])
			{
				int x = i / 5;
				int y = i % 5;
				princess_mark[x][y] = 1;
				if(q.empty())
				{
					visited[x][y] = 1;
					q.push({x, y});
				}
			}
		}
		bfs_7_adjacent(q);
	} while (next_permutation(mask, mask + 25));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	for (int i = 0; i < 5; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = str[j];
		}
	}
	// 7개의 인접영역에서 s가 4개 이상인 경우 cnt.
	// 5x5 map에서 7개의 인접영역인 모든 경우를 찾음.
	// 각 경우마다 s가 4개 이상인지 확인

	// 25C7
	combi(7);
	cout << ans;
}

// YYYYY
// SYSYS
// YYYYY
// YSYYS
// YYYYY