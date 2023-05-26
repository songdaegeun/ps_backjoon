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
		if(cnt == 5)
			cout << x << ' ' << y << '\n';
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
					if(dist[x][y][pull_down][n_daytime] != 0) continue;
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



// 이번 문제에서는 낮과 밤이 번갈아가면서 등장한다.
// 가장 처음에 이동할 때는 낮이고, 한 번 이동할 때마다 낮과 밤이 바뀌게 된다. 이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.
// 만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다. 단, 벽은 낮에만 부술 수 있다.

// 상태변수: x, y, pull_down
// 상태: cnt, daytime <- pair<int,int>

// 3 3 3
// 011
// 111
// 110

// if(cnt == 5)
// 	cout << x << ' ' << y << '\n';
