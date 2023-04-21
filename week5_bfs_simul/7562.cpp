#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int n,m;
int map[301][301];
int dist[301][301];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int oob(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= n);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int num;

	cin >> num;
	while(num--){
		cin >> n;
		queue<pair<int,int>> q;
		pair<int,int> start;
		cin >> start.first >> start.second;
		pair<int,int> end;
		cin >> end.first >> end.second;
		memset(dist, -1, sizeof(int) * 301 * 301);
		dist[start.first][start.second] = 0;
		q.push(start);
		while (dist[end.first][end.second] == -1)
		{
			pair<int,int> pos = q.front();
			q.pop();
			int x = pos.first;
			int y = pos.second;
			for(int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(oob(nx,ny)) continue;
				if(dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny}); 
			}
		}
		cout << dist[end.first][end.second] << '\n';
	}
}

// 3
// 8
// 0 0
// 7 0
// 100
// 0 0
// 30 50
// 10
// 1 1
// 1 1