#include <iostream>
#include <queue>
#include <tuple>
#define AFTERNOON 1
#define MORNING 0
using namespace std;

int n, m, k;
string map[1001];
int dist[1001][1001][11][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs() {
	queue<tuple<int,int,int,int>> q;

	dist[0][0][0][0] = 1;
	q.push({0,0,0,0});

	while(!q.empty()) {
		int x,y,pull_down,daytime,cnt;

		tie(x,y,pull_down,daytime) = q.front(); q.pop();
		cnt = dist[x][y][pull_down][daytime];
		if(x == n - 1 && y == m - 1) {
			return (cnt);
		}
			
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if(map[nx][ny] == '0') {
				int n_daytime = 1 - daytime;
				if(dist[nx][ny][pull_down][n_daytime] != 0) continue;
				dist[nx][ny][pull_down][n_daytime] = cnt + 1;
				q.push({nx,ny,pull_down,n_daytime});
			}
			else if(map[nx][ny] == '1') {
				if(pull_down == k) continue;
				if(daytime == MORNING) { 
					int n_pull_down = pull_down + 1;
					int n_daytime = 1 - daytime;
					if(dist[nx][ny][n_pull_down][n_daytime] != 0) continue;
					dist[nx][ny][n_pull_down][n_daytime] = cnt + 1;
					q.push({nx,ny,n_pull_down, n_daytime});
				}
				else if (daytime == AFTERNOON) { // 밤에 벽을 만난경우.
					int n_daytime = 1 - daytime;
					if(dist[nx][ny][pull_down][n_daytime] != 0) continue;
					dist[x][y][pull_down][n_daytime]  = cnt + 1;
					q.push({x,y,pull_down,n_daytime});
					// 한번 대기
				}
			}
		}
	}
	return (-1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m >> k;
	cin.ignore();
	for (int i = 0; i < n; i++)
		cin >> map[i];

	int ans = bfs();
	cout << ans << '\n';
}
