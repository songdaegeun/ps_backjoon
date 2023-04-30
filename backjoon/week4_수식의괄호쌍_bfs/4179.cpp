#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
char map[1000][1000];
int j_dist[1000][1000];
int f_dist[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int oob(int x, int y)
{
    return (x < 0 || x >= n|| y < 0 || y >= m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	string str;
	queue<pair<int,int>> f_q;
	queue<pair<int,int>> j_q;
	
	cin >> n >> m;
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		getline(cin, str);
		for(int j = 0; j < m; j++)
		{
			map[i][j] = str[j];
		}
	}
	memset(j_dist, -1, sizeof(int) * 1000 * 1000);
	memset(f_dist, -1, sizeof(int) * 1000 * 1000);
	// 'F'의 위치를 먼저 넣고, 'J'의 위치를 queue에 넣는다.
	// bfs로 둘의 dist계산
	// j_dist가 f_dist보다 같거나 크면 거기는 지나갈 수 없다.
	// 가장 자리 중 j_dist의 최소값을 출력. min이 n*m이라면, IMPOSSIBLE 을 출력
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(map[i][j] == 'F')
			{
				f_q.push({i, j});
				f_dist[i][j] = 0;
			}
			else if(map[i][j] == 'J')
			{
				j_q.push({i, j});
				j_dist[i][j] = 0;
			}	
		}
	}

	while(!f_q.empty()){
		pair<int, int> f_cur = f_q.front();

		f_q.pop();
		int x = f_cur.first;
		int y = f_cur.second;
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(oob(nx, ny)) continue;
			if(map[nx][ny] == '#') continue;
			if(f_dist[nx][ny] >= 0) continue;			
			f_dist[nx][ny] = f_dist[x][y] + 1;
			f_q.push({nx, ny});
		}
	}
	while(!j_q.empty()){
		pair<int, int> j_cur = j_q.front();

		j_q.pop();
		int x = j_cur.first;
		int y = j_cur.second;
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(oob(nx, ny))
			{
				cout << j_dist[x][y] + 1;
				return (0);
			}
			if(map[nx][ny] == '#' || j_dist[nx][ny] >= 0) continue;
			if(f_dist[nx][ny] != -1 && j_dist[x][y] + 1 >= f_dist[nx][ny]) continue;			
			j_dist[nx][ny] = j_dist[x][y] + 1;
			j_q.push({nx, ny});
		}
	}
	// int min = m * n;
	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < m; j++)
	// 	{
	// 		if(!(i == 0 || i == n - 1) && !(j == 0 || j == m - 1))
	// 			continue;
	// 		if(map[i][j] == '.' && j_dist[i][j] != 0 && j_dist[i][j] < min)
	// 			min = j_dist[i][j];
	// 	}
	// }
	cout << "IMPOSSIBLE" << '\n';

}

// 4 4
// ####
// #JF#
// #..#
// #..#