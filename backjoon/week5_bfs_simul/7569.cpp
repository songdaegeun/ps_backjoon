#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n,m,h;
int map[101][101][101];
int dist[101][101][101];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int oob(int x, int y, int z){
    return (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	queue<tuple<int,int,int>> q;
	cin >> m >> n >> h;
	for(int k = 0; k < h; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> map[i][j][k];
				if(map[i][j][k] == 1)
				{
					dist[i][j][k] = 0;
					q.push(make_tuple(i, j, k));
				}
				else if(map[i][j][k] == 0)
					dist[i][j][k] = -1;
			}
		}
	}
	while(!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for(int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if(oob(nx, ny, nz)) continue;
			if(dist[nx][ny][nz] != -1 || map[nx][ny][nz] == -1) continue;
			dist[nx][ny][nz] = dist[x][y][z] + 1;
			q.push(make_tuple(nx, ny, nz));
		}
	}
	int max = -1;
	for(int k = 0; k < h; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(dist[i][j][k] == -1)
				{
					cout << -1;
					return (0);
				}
				if (max < dist[i][j][k])
					max = dist[i][j][k];	
			}
		}
	}
	cout << max;
}
// 5 3 1
// 0 -1 0 0 0
// -1 -1 0 1 1
// 0 0 0 1 1