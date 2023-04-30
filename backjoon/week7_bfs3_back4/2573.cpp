#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int map[302][302];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map()
{
	for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] << ' ';
		}
	}
}

int bfs_separate()
{
	int visited[302][302];
	memset(visited, 0, sizeof(int) * 302 * 302);
	queue<pair<int,int>> q;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(map[i][j] == 0 || visited[i][j] != 0) continue;
			visited[i][j] = 1;
			q.push({i,j});
			cnt++;
			while(!q.empty())
			{
				pair<int,int> pos = q.front(); q.pop();
				int x, y;
				tie(x, y) = pos;
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(map[nx][ny] == 0 || visited[nx][ny] != 0) continue;
					visited[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
		}
	}
	if(cnt >= 2)
		return (1);
	else
		return (0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	int res = 0;
	int year = 0;
	while(1)
	{
		// 빙산이 1년에 한번씩 녹는다.
		year++;
		int visited[302][302];
		memset(visited, 0, sizeof(int) * 302 * 302);
		int chk = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(map[i][j] != 0)
				{
					visited[i][j] = 1;
					chk = 1;
					int x = i;
					int y = j;
					int cont_cnt = 0;
					for (int i = 0; i < 4; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];
						if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if(map[nx][ny] == 0 && visited[nx][ny] != 1)
							cont_cnt++;
					}
					map[i][j] -= cont_cnt;
					if(map[i][j] < 0)
						map[i][j] = 0;
				}
			}
		}
		if(chk == 0)				// 빙하가 다 녹으면 종료.
		{
			res = 0;
			break;
		}
		else if (bfs_separate())	// 매년 덩어리를 bfs로 구분해본다.
		{
			res = year;				// 두 덩어리로 나눠지는 순간 res = cnt;
			break;
		}	
	}

	cout << res;
	
}

// 5 7
// 0 0 0 0 0 0 0
// 0 2 4 5 3 0 0
// 0 3 0 2 5 2 0
// 0 7 6 2 4 0 0
// 0 0 0 0 0 0 0