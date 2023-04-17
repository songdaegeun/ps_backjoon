#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int n, m;
int map[1002][1002];
int dist[1002][1002][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map();

void bfs()
{
	queue<tuple<int, int, int>> q;
	dist[0][0][0] = 1;
	q.push({0,0,0});
	while(!q.empty())
	{
		tuple<int,int, int> pos = q.front(); q.pop();
		int x, y, pull_down;
		tie(x,y,pull_down) = pos;
		if (x == n - 1 && y == m - 1)
		{
			cout <<  dist[x][y][pull_down];
			return ;
		}
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			// pull_down = get<2>(pos);
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(dist[nx][ny][pull_down] != 0) continue;

			if(map[nx][ny] == 0)
			{
				dist[nx][ny][pull_down] = dist[x][y][pull_down] + 1;
				q.push({nx, ny, pull_down});
				// cout << nx << ' ' << ny << ": " << pull_down << '\n';
			}

			if (pull_down == 0 && map[nx][ny] == 1)
			{
				dist[nx][ny][1] = dist[x][y][pull_down] + 1;
				q.push({nx, ny, 1});
				// cout << nx << ' ' << ny << ": " << pull_down << '\n';
			}
		}
	}
	cout << -1;
}

// 2 2
// 01
// 10
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	// map을 input stream에서 받는다.
	// bfs search in d, r, u, l order
	// push condition is (map's element == 0 or map's element == 1 && pull_down == 0 )(in this condition, set pull_down to 1)) && visited arr's element is 0 
	string str;
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		for (int j = 0; j < m; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}
	bfs();
	// if(dist[n - 1][m - 1][0] == 0)
	// 	cout << -1;
	// else
	// 	cout <<  dist[n - 1][m - 1][0];
}

// 6 4
// 0100
// 1110
// 1000
// 0000
// 0111
// 0000

void disp_map()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}