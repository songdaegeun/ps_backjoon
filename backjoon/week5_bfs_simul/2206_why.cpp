#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int n, m;
int pull_down = 1;
int map[1002][1002][2];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map();

void bfs()
{
	queue<pair<int, int>> q;
	dist[0][0] = 1;
	q.push({0,0});
	while(!q.empty())
	{
		pair<int,int> pos = q.front(); q.pop();
		int x = pos.first;
		int y = pos.second;
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(dist[nx][ny] != 0) continue;	
			// 이렇게 하면 벽을 부쉈던 경로로 탐색하는 과정에서 방문했던 곳은 방문하지 않게 되는데, 무조건적으로 상하좌우로 depth가 증가하면서 queue에 넣는 구조에서는 방문했던 곳에 다시 방문해봤자 manhattan distance가 더 작아질 수 없기 때문에 최단거리가 필요한 문제에 적용할 수 있었지만, 
			// 이 문제의 경우 벽을 부쉈던 경로보다 벽을 부수지 않았던 경로의 manhattan distance가 더 작을 수 있기 때문에 벽을 부쉈던 경로를 다시 방문할 필요가 있다.
			map[nx][ny][pull_down] = map[x][y][pull_down];		
			if(map[nx][ny][0] == 0 || (map[nx][ny][0] == 1 && map[nx][ny][pull_down] == 0))
			{
				if(map[nx][ny][0] == 1 && map[nx][ny][pull_down] == 0)
					map[nx][ny][pull_down] = 1;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

// 2 2
// 01
// 10
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	//map을 input stream에서 받는다.
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
			map[i][j][0] = str[j] - '0';
		}
	}
	bfs();
	if(dist[n - 1][m - 1] == 0)
		cout << -1;
	else
		cout <<  dist[n - 1][m - 1];
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
			cout << map[i][j][0] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}